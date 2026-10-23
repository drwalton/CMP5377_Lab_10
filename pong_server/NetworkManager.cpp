#include "NetworkManager.hpp"
#include <stdexcept>
#include <iostream>

struct StatePacket {
	// Define your State packet
};

struct InputPacket {
	// Define your input packet
};

NetworkManager::NetworkManager(const std::string& hostname, int sendPort, int recvPort)
	:sendPort_(sendPort), recvPort_(recvPort)
{
	// YOUR CODE HERE
}

NetworkManager::~NetworkManager()
{
	// YOUR CODE HERE
}

void NetworkManager::sendState(float ballX, float ballY, float paddle1X, float paddle2X, int p1Score, int p2Score)
{
	// YOUR CODE HERE
}

void NetworkManager::checkForRemoteInput()
{
   // YOUR CODE HERE
}

float NetworkManager::getCurrInput()
{
	return currInput_;
}
