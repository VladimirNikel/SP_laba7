#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int socket(
	int domain,		//создание сокета
	int type,		//домен и семейство адресов AF_UNIX и AF_INET
	int protocol	//протокол
);

int bind(			//связывание сокета сервера с адресом
	int sockfd,				//дескриптор сокера
	struct sockaddr *addr,	//указатель на структуру с адресом
	int addrlen				//длина структуры адреса
);

int listen(			//перевод сокета сервера в режим ожидания запросов со стороны клиентов
	int sockfd,			//дескриптор сокета
	int backlog			//размер очереди дискрипторов
);

int accept(
	int sockfd,		//дескриптор слушающего сокета
	void *addr,		//арес сокера клиента
	int *addrlen	//длина
);

int send(
	int sockfd,		//дескриптор сокета, через который отправляются данные
	const void *msg,//указатель на буфер с данными
	int len,		//длина буфера данных
	int flags		//набор битовым флагов
);

int recv(
	int sockfd,		//дескриптор сокета, через который считываются данные
	void *buf,		//указатель на буфер
	int len,		//длина буфера данных
	int flags		//набор битовым флагов
);

int shutdown(
	int sockfd,		//дескриптор сокета
	int how			//0 - запрет чтенияб 1 - запрет записи, 2 - чтения и записи
);

int close(
	int fd			//дескриптор сокета
);


int main(int argc, char *argv[]){
	//инструкция:
	//socket();
	//bind();
	//listen();
	//accept();
	//send();
	//recv();
	//shutdown();
	//close();

	return 0;
}






