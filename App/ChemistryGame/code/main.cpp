#include "pchGame.hpp"
#include "GameManager.hpp"
int main()
{
	std::shared_ptr<GameManager> navigate = std::make_shared<GameManager>();
	navigate->start();
}