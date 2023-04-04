#include "pchGame.hpp"
#include "LastRoom.hpp"

LastRoom::LastRoom(int door)
{
	WIDTH = GetScreenWidth();
	HEIGHT = GetScreenHeight();
	backgroundLastRoom = LoadTexture("../assets/images/chemistry/Rooms/RoomTwo.png");
	backgroundLastRoom.width = WIDTH;
	backgroundLastRoom.height = HEIGHT;

	doorDown = LoadTexture("../assets/images/chemistry/Objects/DoorDown.png");
	doorDown.width = WIDTH / 9.6f;
	doorDown.height = HEIGHT / 5.4f;

	doorUp = LoadTexture("../assets/images/chemistry/Objects/DoorUp.png");
	doorUp.width = WIDTH / 9.6f;
	doorUp.height = HEIGHT / 5.4f;

	fire = LoadTexture("../assets/images/chemistry/Objects/Fire.png");

	doorsPositons[0].x = WIDTH / 2.259f;
	doorsPositons[0].y = HEIGHT / 36;

	doorsPositons[1].x = WIDTH / 2.259f;
	doorsPositons[1].y = HEIGHT / 1.263f;

	fire.width = WIDTH / 2.133f;
	fire.height = HEIGHT / 3.6f;

	imageSourceRec = { 0, 0, WIDTH / 60, HEIGHT / 33.75f };

	imageDestRec = { WIDTH / 60, HEIGHT / 33.75f };
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