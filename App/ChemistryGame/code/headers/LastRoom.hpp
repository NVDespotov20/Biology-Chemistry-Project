#pragma once
class LastRoom
{
	public:
	LastRoom(int door);
	LastRoom();
	~LastRoom();
	void drawLastRoom();

	Texture2D backgroundLastRoom;
	Texture2D doorDown;
	Texture2D doorUp;
	Texture2D fire;

	Rectangle imageSourceRec;
	Vector2 imageDestRec;

	Vector2 doorsPositons[2];
};

