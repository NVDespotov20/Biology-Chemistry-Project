#include "GameManager.hpp"

#include "../code/headers/pchGame.hpp"
int main()
{
	std::shared_ptr<GameManager> navigate = std::make_shared<GameManager>();
	navigate->start();
}
