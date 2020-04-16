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

int connect(
	int sockfd,		//сокет, использующийся для обмена данными с сервером
	struct sockaddr *serv adrr,	//указатель на структуру с адресов сервера
	int addrlen 	//длина этой структуры
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

int main(){
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



