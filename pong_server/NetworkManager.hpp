#pragma once
#include <SDL3_net/SDL_net.h>
#include <string>

class NetworkManager final {
public:
	NetworkManager(const std::string& hostname, int sendPort, int recvPort);
	~NetworkManager();

	void sendState(
		float ballX, float ballY,
		float paddle1X, float paddle2X,
		int p1Score, int p2Score);

	void checkForRemoteInput();

	float getCurrInput();


private:
	NET_Address* address_;
	NET_DatagramSocket* socket_;
	Uint16 sendPort_, recvPort_;
	float currInput_;
};
