#include <AppManager.hpp>
AppManager* AppManager::instantiate_ = nullptr;
AppManager::AppManager()
{
	// Initialize window and settings

	InitWindow(0, 0, "Human muscles");
	ToggleFullscreen();
	SetTargetFPS(60);

	dir = MENU;
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
		ClearBackground(LIGHTGRAY);
		manage();
		EndDrawing();
	}
}
void AppManager::manage()
{
	switch (dir)
	{
		case MENU:
		{

			std::shared_ptr<Menu> menu = Menu::getInstantiation();
			menu->loop();
			break;
		}
		case APP:
		{
			std::shared_ptr<App> app = App::getInstantiation();
			app->loop();
			break;
		}
		case OPTIONS:
		{
			std::shared_ptr<Options> opt = Options::getInstantiation();
			opt->loop();
			break;
		}
		case QUIT:
			delete this;
			break;
	}
}