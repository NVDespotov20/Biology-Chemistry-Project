#include "pchGame.hpp"
#include "LastRoom.hpp"

LastRoom::LastRoom(int door)
{
	backgroundLastRoom = LoadTexture("../assets/images/chemistry/Rooms/RoomTwo.png");
	backgroundLastRoom.width = GetScreenWidth();
	backgroundLastRoom.height = GetScreenHeight();

	doorDown = LoadTexture("../assets/images/chemistry/Objects/DoorDown.png");
	doorDown.width = 200;
	doorDown.height = 200;

	doorUp = LoadTexture("../assets/images/chemistry/Objects/DoorUp.png");
	doorUp.width = 200;
	doorUp.height = 200;

	fire = LoadTexture("../assets/images/chemistry/Objects/Fire.png");

	doorsPositons[0].x = 850;
	doorsPositons[0].y = 30;

	doorsPositons[1].x = 850;
	doorsPositons[1].y = 855;

	fire.width = 900;
	fire.height = 300;

	imageSourceRec = { 0, 0, 32, 32 };

	imageDestRec = {32, 32 };
}

LastRoom::LastRoom()
{
	
}

LastRoom::~LastRoom()
{
}

void LastRoom::drawLastRoom()
{
	DrawTexture(backgroundLastRoom,0,0, WHITE);
	DrawTexture(doorUp, doorsPositons[0].x, doorsPositons[0].y, WHITE);
	DrawTexture(doorDown, doorsPositons[1].x, doorsPositons[1].y, WHITE);
	DrawTextureRec(fire, imageSourceRec, imageDestRec, WHITE);
}

void LastRoom::unload()
{
	UnloadTexture(backgroundLastRoom);
	UnloadTexture(doorDown);
	UnloadTexture(fire);
	UnloadTexture(doorUp);

}