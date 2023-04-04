#pragma once
class mixElements
{
public:
	mixElements();
	~mixElements();
	void Draw(bool& loadMiniGame);
	void unload(); 

	std::vector<std::string> elementsTexturesStrings;
	std::vector<std::string> fiveChosen;
	std::vector<Texture2D> elementsTextures;
	Texture2D backbuttonTexture;
	Texture2D water;
	
	unsigned seed;

	//random engine from random library
	std::mt19937 gen;

private:
	int WIDTH = GetScreenWidth(); 
	int HEIGHT =GetScreenHeight(); 
};