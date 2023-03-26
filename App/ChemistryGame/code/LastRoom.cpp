#include "pchGame.hpp"
#include "LastRoom.hpp"

LastRoom::LastRoom(int door)
{
}

LastRoom::LastRoom()
{
}

LastRoom::~LastRoom()
{
}

void LastRoom::drawLastRoom()
{
	DrawText("IMPLEMENT GAMEOVER SCREEN ", 500, 500, 50, Fade(RED, 0.8f));
}