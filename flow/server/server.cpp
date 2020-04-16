#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

void dostuff(int);
void error(const char *msg){
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[]){
	int sockfd, new_sockfd, port_number, pid;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	if(argc<2){
		fprintf (stderr, "Ошибка: порт не подоставлен\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd<0) error("Ошибка: не удалось открыть сокет\n");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	port_number = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port_number);
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0) 
		error("Ошибка: не удалось установить соединение\n");
	listen(sockfd,5);
	clilen=sizeof(cli_addr);
	while(1){
		new_sockfd=accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if(new_sockfd<0) error("Ошибка: не готов принять запрос\n");
		pid = fork();
		if(pid<0) error("Ошибка создания потока\n");
		if(pid==0){
			close(sockfd);
			dostuff(new_sockfd);
			exit(0);
		}
		else close(new_sockfd);
	}
	close(sockfd);
	return 0;
}

void dostuff(int sock){
	int n;
	char buffer[256];
	bzero(buffer,256);
	n=read(sock,buffer,255);
	if(n<0) error("Ошибка: Чтение из сокета невозможно\n");
	printf("Прислали сообщение: %s\n",buffer);
	n=write(sock,"Я отправил сообщение",20);
	if(n<0) error ("Ошибка: Запись в сокет невозможна\n");
}