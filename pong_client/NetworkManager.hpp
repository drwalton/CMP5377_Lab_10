#pragma once
#include <SDL3_net/SDL_net.h>
#include <string>

class NetworkManager final {
public:
	NetworkManager(const std::string& hostname, int sendPort, int recvPort);
	~NetworkManager();

	void sendInput(float input);
	void checkForNewState();

	float ballX() const;
	float ballY() const;
	float paddle1X() const;
	float paddle2X() const;

	int p1Score() const;
	int p2Score() const;

private:
	NET_Address* address_;
	NET_DatagramSocket* socket_;
	Uint16 sendPort_, recvPort_;

	float ballX_, ballY_, paddle1X_, paddle2X_, p1Score_, p2Score_;
};
