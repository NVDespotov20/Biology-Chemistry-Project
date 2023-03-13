#include <Options.hpp>
Options* Options::instantiate_ = nullptr;
Options::Options()
{
	load();
}
Options::~Options()
{
	unload();
}
Options* Options::getInstantiation()
{
	if (instantiate_ == nullptr) {
		instantiate_ = new Options();
	}
	return instantiate_;
}
void Options::loop()
{

	ClearBackground(LIGHTGRAY);

	// Fix unable to alt-tab
	if (!IsWindowFocused())
		MinimizeWindow();

	DrawText("Options", GetScreenWidth() / 2, GetScreenHeight() / 2, 40, BLACK);
}
inline void Options::load()
{

}
inline void Options::unload()
{

}