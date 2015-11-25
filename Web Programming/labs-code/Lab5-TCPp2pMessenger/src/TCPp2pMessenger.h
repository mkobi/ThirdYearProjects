//============================================================================
// Name        : UDPMessenger.h
// Author      : Eliav Menachi
// Version     :
// Copyright   : Your copyright notice
// Description : TCP p2p Messenger application
//============================================================================

#include <pthread.h>
#include "TCPSocket.h"
#include "MThread.h"

using namespace std;

//TODO: create two new classes to manage the server side and the client side of the messenger

class TCPp2pMessenger{
	//TODO: add class properties

public:
	/**
	 * Construct the P2P messenger - this action include:
	 * 								 opening a TCP server socket
	 * 								 opening a thread that accept all incoming connection and reads incoming messages
	 */
	TCPp2pMessenger();

	/**
	 * Open a connection to the given IP address and once the connection is established it will open a thread
	 * to read incoming messages from the socket
	 */
	bool open(string peerIp);

	/**
	 * Close an open session
	 */
	bool closeSession();

	/**
	 * send a message on the client open connection
	 * The message is sent in the form: [message length - 4 bytes][message data]
	 */
	void send(string msg);

	/**
	 * send a message on the server socket incoming connection
	 * The message is sent in the form: [message length - 4 bytes][message data]
	 */
	void reply(string msg);

	/**
	 * close all resources / sockets
	 */
	void close();

	/**
	 * return  true if the client socket is connected
	 */
	bool isActiveClientSession();

	/**
	 * return true if there is an open incoming connection
	 */
	bool isActivePeerSession();
};

