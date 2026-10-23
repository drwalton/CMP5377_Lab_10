#pragma once
#include <SDL3_net/SDL_net.h>
#include <string>

class NetHighScoreManager final {
public:
	NetHighScoreManager(const std::string& hostname);
	~NetHighScoreManager();

	void sendHighScore(const std::string& name, int score);
	std::string getHighScores();
private:
	NET_StreamSocket* socket_;
};
