
#include<AppManager.hpp>
int main()
{
    AppManager* manager = AppManager::getInstantiation();
    manager->loop();
    delete manager;
}