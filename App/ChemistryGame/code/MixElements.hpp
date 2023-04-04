#pragma once
class mixElements
{
public:
	mixElements();
	~mixElements();
	void Draw(bool& loadMiniGame);

	std::vector<Vector2> elementPos;
	std::vector<std::string> elementsTexturesStrings;
	std::vector<std::string> threeChosen;
	std::vector<Texture2D> elementsTextures;
	Texture2D backbuttonTexture;
	Texture2D water;

private:


	int WIDTH = GetScreenWidth();
	int HEIGHT = GetScreenHeight();
};