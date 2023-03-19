#include "pchGame.hpp"
#include "Game.hpp"
int main()
{
	std::shared_ptr<Game> game = std::make_shared<Game>();
	game->mainLoop();
}