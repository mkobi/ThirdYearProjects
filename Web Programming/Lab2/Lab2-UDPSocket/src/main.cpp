//============================================================================
// Name        : Lab1UDPSocket
// Author      : Eliav Menachi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "UDPSocket.h"
using namespace std;

int main() {
	cout << "UDP Socket test" << endl;
	//create client UDP socket named cSocket
	UDPSocket* cSocket = new UDPSocket();
	//create server UDP socket named sSocket
	UDPSocket* sSocket = new UDPSocket(3346);

	// this part test the sendTo and recv methods
	string message = "Test 1234567890";
	cSocket->sendTo(message,"127.0.0.1", 3346);
	char buffer[100];
	memset((void*)buffer,0,100);
	int rc = sSocket->recv(buffer, 100);
	cout<<"send msg:"<<message<<endl;
	cout<<"recv msg:"<<buffer<<endl;
	if (rc != (int)message.length()){
		perror("FAIL1: receive different message length");
	}
	if (message != buffer){
		perror("FAIL2: receive different message");
	}


	string messageToReply = "Reply 1234567890";
	sSocket->reply(messageToReply);
	char buffer2[100];
	memset((void*)buffer2,0,100);
	int rc2 = cSocket->recv(buffer2, 100);
	cout<<"reply msg:"<<messageToReply<<endl;
	cout<<"recv msg:"<<buffer2<<endl;
	if (rc2 != (int)messageToReply.length()){
		perror("FAIL1: receive different message length from reply");
	}
	if (messageToReply != buffer2){
		perror("FAIL2: receive different message from reply");
	}

	cout<<"from address = "<<sSocket->fromAddr()<<endl;
	cout<<"from address = "<<cSocket->fromAddr()<<endl;
	cout<<"TEST COMPLETE"<<endl;

	sSocket->cclose();
	cSocket->cclose();

	delete sSocket;
	delete cSocket;

	return 0;
}
