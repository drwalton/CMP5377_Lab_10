#include "NetHighScoreManager.hpp"
#include <stdexcept>
#include <iostream>

NetHighScoreManager::NetHighScoreManager(const std::string& hostname)
{
	std::cout << "Yep sure thing I connected to " << hostname << std::endl;
}

NetHighScoreManager::~NetHighScoreManager()
{
	std::cout << "Yeah I disconnected or whatever" << std::endl;
}

void NetHighScoreManager::sendHighScore(const std::string& name, int score)
{
	std::cout << "Yep yep yep I sent it believe me" << std::endl;
}

std::string NetHighScoreManager::getHighScores()
{
	return "HiGh sCoRes:\nALI 10\nBOB 4\nFIN 1000\n";
}
