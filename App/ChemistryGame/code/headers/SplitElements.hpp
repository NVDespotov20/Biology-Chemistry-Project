#pragma once // This is a preprocessor directive that ensures the header file is only included once in the compilation process.
#include "pchGame.hpp"
class SplitElements
{

public:
	~SplitElements(); // Destructor of the SplitElements class.

		//int arrays for holders
	int positionOfMetalsHolder[4]; // Integer array to hold the position of metal elements.
	int positionOfNonMetalsHolder[4]; // Integer array to hold the position of non-metal elements.

	//rectangles initialization
	Rectangle elementsInTheBoxRec[4]; // Array of rectangles for the elements in the box.
	Rectangle elementsInTheBoxRec2[4]; // Array of rectangles for the elements in the box.
	Rectangle elementsInTheHolders[4]; // Array of rectangles for the elements in the holders.
	Rectangle elementsInTheHolders2[4]; // Array of rectangles for the elements in the holders.
	Rectangle choice[2]; // Array of rectangles for the choice buttons.
	Rectangle backButton; // Rectangle for the back button.

	//texture initialization
	Texture2D backgroundOfTable; // Texture for the background of the table.

	//normal vars initialization
	int saverForIndexOfElement; // Index of the selected element.

	bool chooseMetalOrNonmetal; // Boolean to choose between metal or non-metal elements.

	//vectors initialization
	std::vector<std::string> elementsTexturesStrings; // Vector of strings for the element textures.
	std::vector<std::string> checkerForMetals; // Vector of strings to check for metal elements.
	std::vector<Texture2D> elementsTextures; // Vector of textures for the elements.
	std::vector<std::string> elementsStrings; // Vector of strings for the elements.
	std::vector<std::string> metalElementsStrings; // Vector of strings for the metal elements.
	std::vector<std::string> nonmetalElementsStrings; // Vector of strings for the non-metal elements.
	std::vector<Texture2D> metalsHolders; // Vector of textures for the metal holders.
	std::vector<Texture2D> nonmetalsHolders; // Vector of textures for the non-metal holders.

	Texture2D choiceOfMetalOtNonmetal[2]; // Array of textures for the choice buttons.
	Texture2D backbuttonTexture; // Texture for the back button.
	Texture2D label; // Texture for the label.
	int counter; // Counter for the number of elements.

	//seed that we make different every time
	unsigned seed; // Unsigned integer to hold the seed for the random engine.

	//random engine from random library
	std::mt19937 gen; // Object of the mt19937 class from the random library.

	//function initialization
	void drawAndMoveElementsAndHolders(bool& loadMiniGame); // Member function to draw and move the elements and holders.
	void unload(); // Member function to unload the elements and holders.
	static std::shared_ptr<SplitElements> getInstantiation(); // Static member function to get an instance of the SplitElements class.

	bool checkElements(); // Member function to check the selected elements.
private:
	SplitElements(); // Constructor of the SplitElements class.
	static std::shared_ptr<SplitElements> instantiate_; // Static shared pointer to an instance of the SplitElements class.

		//not accessable from other places vars
	float WIDTH; // Width of the elements and holders.
	float HEIGHT; // Height of the elements and holders.

	Vector2 mousepoint; // Vector to hold the mouse position.
};