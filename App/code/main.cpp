#include"headers/App.hpp"
int main()
{
    App* app = App::getInstance();
    app->loop();
}