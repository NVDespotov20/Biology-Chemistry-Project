
#include "pchGame.hpp"
#include "GameManager.hpp"

int main()
{
	std::shared_ptr<GameManager> navigate = std::make_shared<GameManager>();
	navigate->start();
}


//#include "../../HumanMuscles/code/headers/AppManager.hpp"
//#include "../code/headers/pchGame.hpp"
//
//int main()
//{
//    AppManager* manager = AppManager::getInstantiation();
//    manager->drawMainLoop();
//    delete manager;
//}