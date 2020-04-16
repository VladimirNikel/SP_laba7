#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg){
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[]){
	int sockfd, n;
	unsigned int length;
	struct sockaddr_in server, from;
	struct hostent *hp;
	char buffer[256];
	sockfd= socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd<0) error("Ошибка: не удалось открыть сокет\n");
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if (hp==0) error("Ошибка: нет такого хоста\n");
	bcopy((char *)hp->h_addr, (char *)&server.sin_addr,hp->h_length);
	server.sin_port = htons(atoi(argv[2]));
	length=sizeof(struct sockaddr_in);
	printf("Введите Ваше сообщение: ");
	bzero(buffer,256);
	fgets(buffer,255,stdin);
	n=sendto(sockfd,buffer,strlen(buffer),0,(const struct sockaddr *)&server,length);
	if(n<0) error("Ошибка: не удалось отправить сообщение\n");
	n = recvfrom(sockfd,buffer,256,0,(struct sockaddr *)&from, &length);
	if(n<0) error("Ошибка: не удалось прочитать данные из сокета\n");
	write(1,"Ответ: ",12);
	write(1,buffer,n);
	close(sockfd);
	return 0;
}