#pragma once // This is a preprocessor directive that ensures the header file is only included once in the compilation process.

class CheckValency
{
public:
	CheckValency(); // Constructor of the CheckValency class.
	~CheckValency(); // Destructor of the CheckValency class.

	void drawAndCheckElementsAndHolders(bool& loadMiniGame); // Member function to draw and check the elements and holders.
	bool checkAccuracy(); // Member function to check the accuracy of the user's answers.
	void unload(); // Member function to unload the elements and holders.

	static std::shared_ptr<CheckValency> getInstantiation(); // Static member function to get an instance of the CheckValency class.

	int counterForAccuracy; // Counter for the accuracy of the user's answers.
	int saver; // Index of the selected element.
	int rightAnswersArray[3]; // Array to hold the right answers.

	std::vector<int> givenAnswers; // Vector to hold the user's answers.

	std::vector<std::string> theChosenThreeStrings; // Vector of strings for the chosen three elements.
	std::vector<std::string> valencyTwo; // Vector of strings for the elements with valency two.
	std::vector<std::string> valencyOne; // Vector of strings for the elements with valency one.

	std::vector<Texture2D> theChosenThree; // Vector of textures for the chosen three elements.

	Rectangle backbutton; // Rectangle for the back button.
	Rectangle answersRec1[3]; // Array of rectangles for the answers.
	Rectangle answersRec2[3]; // Array of rectangles for the answers.
	Rectangle answersRec3[3]; // Array of rectangles for the answers.
	Rectangle containersRec[3]; // Array of rectangles for the containers.

	Texture2D background; // Texture for the background.
	Texture2D label; // Texture for the label.
	Texture2D backbuttonTexture; // Texture for the back button.
	Texture2D buttonsTextures[3]; // Array of textures for the answer buttons.
	Texture2D metalOrNonmetalChoice[2]; // Array of textures for the metal or non-metal choice buttons.

	unsigned seed; // Unsigned integer to hold the seed for the random engine.

	//random engine from random library
	std::mt19937 gen; // Object of the mt19937 class from the random library.
private:
	Vector2 mousePoint; // Vector to hold the mouse position.
	static std::shared_ptr<CheckValency> instantiate_; // Static shared pointer to an instance of the CheckValency class.
	float WIDTH; // Width of the elements and holders.
	float HEIGHT; // Height of the elements and holders.
};