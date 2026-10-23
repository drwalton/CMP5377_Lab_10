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

void NetworkManager::sendInput(float input)
{
   // YOUR CODE HERE
}

void NetworkManager::checkForNewState()
{
   // YOUR CODE HERE
}

float NetworkManager::ballX() const
{
	return ballX_;
}

float NetworkManager::ballY() const
{
	return ballY_;
}

float NetworkManager::paddle1X() const
{
	return paddle1X_;
}

float NetworkManager::paddle2X() const
{
	return paddle2X_;
}

int NetworkManager::p1Score() const
{
	return p1Score_;
}

int NetworkManager::p2Score() const
{
	return p2Score_;
}

