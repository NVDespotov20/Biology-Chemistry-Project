#include<pch.hpp>
#include <Menu.hpp>
std::shared_ptr<Menu> Menu::instantiate_ = nullptr;

Menu::Menu()
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	mousePoint = { 0,0 };
	buttonsRecs = {
		{WIDTH / 2.25f,HEIGHT / 6.25f,WIDTH / 6,HEIGHT / 10},
		{WIDTH / 2.25f,HEIGHT / 2,WIDTH / 6,HEIGHT / 10},
		{WIDTH / 2.25f,HEIGHT / 1.50f,WIDTH / 6,HEIGHT / 10},
		{WIDTH / 2.25f,HEIGHT - HEIGHT/1.5f,WIDTH / 6,HEIGHT / 10},
	};
	load();
}

Menu::~Menu()
{
	unload();
}


std::shared_ptr<Menu> Menu::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ =
			std::shared_ptr<Menu>(new Menu);
	}
	return instantiate_;
}

inline void Menu::load()
{

}

inline void Menu::unload()
{
	
}

inline bool Menu::isClicked(const Vector2& mPos, const Rectangle& rec)
{
	if (CheckCollisionPointRec(mPos, rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		return true;
	}
	else {
		return false;
	}
}

void Menu::loop()
{
		
		mousePoint = GetMousePosition();

		// Fix unable to alt-tab
		if (!IsWindowFocused())
			MinimizeWindow();
		
		
		for (auto button : buttonsRecs)
		{
			if(isClicked(mousePoint, button)) {

				auto manager = pch::getInstantiation();
				manager->dir = pch::Direction::APP;
			}
			DrawRectangleRounded(button, 0.5f, 15, RED);
			DrawText("MAIN MENU", button.x + button.width / 2, button.y + button.height / 2, WIDTH / 400, BLACK);
		}
}