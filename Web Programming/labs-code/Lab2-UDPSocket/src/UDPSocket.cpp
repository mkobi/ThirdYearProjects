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
	//TODO: create a UDP socket

	//TODO: Create an address for the socket

	//TODO: bind the socket on the specified address
}

int UDPSocket::recv(char* buffer, int length){
	//TODO: call receive from on the socket and save the address of the sender for the reply method
	return -1;
}

int UDPSocket::sendTo(string msg, string ip, int port){
	//TODO: create an address struct for the destination

	//TODO: call send to and sent the message to the destination address
	return -1;
}

int UDPSocket::reply(string msg){
	//TODO: send the message to the address of the last received message
	return -1;
}

void UDPSocket::cclose(){
	//TODO: shutdown and close the socket
}

string UDPSocket::fromAddr(){
	//TODO: return the IP address of the last received message as a string
	return "";
}



