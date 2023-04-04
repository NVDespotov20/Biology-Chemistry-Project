#pragma once
class LastRoom
{
	float WIDTH, HEIGHT;
	public:
	LastRoom(int door);
	LastRoom();
	~LastRoom();
	void drawLastRoom();
	void unload();
	Texture2D backgroundLastRoom;
	Texture2D doorDown;
	Texture2D doorUp;
	Texture2D fire;

	Rectangle imageSourceRec;
	Vector2 imageDestRec;

	Vector2 doorsPositons[2];
};

