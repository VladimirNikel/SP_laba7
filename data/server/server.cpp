#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

void error(const char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]){
	int sock, length, n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char buf[1024];
	sock=socket(AF_INET, SOCK_DGRAM, 0);
	if(sock<0) error("Ошибка: не удалось открыть сокет\n");
	length = sizeof(server);
	bzero(&server,length);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(atoi(argv[1]));
	if(bind(sock,(struct sockaddr *)&server,length)<0) 
		error("Ошибка: не удалось установить соединение\n");
	fromlen = sizeof(struct sockaddr_in);
	while(1) {
		n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
		if(n<0) error("Ошибка: не удалось прочитать данные из сокета\n");
		write(1,"Полученые данные: ",33);
		write(1,buf,n);
		n = sendto(sock,"Получил!\n ",18,0,(struct sockaddr *)&from,fromlen);
		if(n<0) error("Ошибка: не удалось отправить сообщение\n");
	}
   	return 0;
}
