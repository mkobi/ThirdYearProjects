/*
 * UDPSocket.cpp
 *
 *  Created on: Feb 8, 2013
 *      Author: Eliav Menachi
 */

#include "UDPSocket.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

UDPSocket::UDPSocket(int port){
	_socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	bzero((char*)&s_in, sizeof(s_in));
	s_in.sin_family=(short)AF_INET;
	s_in.sin_addr.s_addr=htonl(INADDR_ANY);
	s_in.sin_port=htons(port);

	client_last_ip = "0.0.0.0";
	client_last_port = 0;

	if(bind(_socket_fd,(struct sockaddr*)&s_in,sizeof(s_in))<0)
		perror("Error naming channel");
}

int UDPSocket::recv(char* buffer, int length){
	sockaddr_in cl_addr;
	socklen_t addres_size = sizeof(cl_addr);
	bzero(&cl_addr, sizeof(cl_addr));
	int n = recvfrom(_socket_fd,buffer,length,0,(sockaddr*)&cl_addr,&addres_size);

	string str(inet_ntoa(cl_addr.sin_addr));
	client_last_ip = str;
	client_last_port = (int)ntohs(cl_addr.sin_port);

	return n;
}

int UDPSocket::sendTo(string msg, string ip, int port){
	struct sockaddr_in d_out;

	bzero(&d_out, sizeof(d_out));
	d_out.sin_family=(short)AF_INET;
	d_out.sin_addr.s_addr=inet_addr(ip.c_str());
	d_out.sin_port=htons(port);

	return sendto(_socket_fd,msg.data(),msg.length(),0,(struct sockaddr*)&d_out,sizeof(d_out));
}

int UDPSocket::reply(string msg){
	return this->sendTo(msg, this->fromAddr(), client_last_port);
}

void UDPSocket::cclose(){
	shutdown(_socket_fd,SHUT_RDWR);
	close(_socket_fd);
}

string UDPSocket::fromAddr(){
	return client_last_ip;
}



