#include <Menu.hpp>
Menu* Menu::instantiate_ = nullptr;
Menu::Menu()
{
	load();
}
Menu::~Menu()
{
	unload();
}
Menu* Menu::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = new Menu();
	}
	return instantiate_;
}
inline void Menu::load()
{

}
inline void Menu::unload()
{
	
}
void Menu::loop()
{
		
		ClearBackground(LIGHTGRAY);

		// Fix unable to alt-tab
		if (!IsWindowFocused())
			MinimizeWindow();

		DrawText("MAIN MENU", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, BLACK);

}