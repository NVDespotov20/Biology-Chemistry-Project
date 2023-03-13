#include <AppManager.hpp>
AppManager* AppManager::instantiate_ = nullptr;
AppManager::AppManager()
{
	// Initialize window and settings

	InitWindow(0, 0, "Human muscles");
	ToggleFullscreen();
	SetTargetFPS(60);

	dir = APP;
}
AppManager::~AppManager()
{
	CloseWindow();
}
AppManager* AppManager::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = new AppManager();
	}
	return instantiate_;
}
void AppManager::loop()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		manage();
		EndDrawing();
	}
}
void AppManager::manage()
{
	switch (dir)
	{
		case MENU:
			Menu* menu;
			menu = Menu::getInstantiation();
			menu->loop();
			break;
		case APP:
			App* app;
			app = App::getInstantiation();
			app->loop();
			break;
		case OPTIONS:
			Options* opt;
			opt = Options::getInstantiation();
			opt->loop();
			break;
		case QUIT:
			delete this;
			break;
		default:
			break;
	}
}