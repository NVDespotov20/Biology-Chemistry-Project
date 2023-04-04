#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
#include "Inventory.hpp"
#include "SplitElements.hpp"
#include "Navigator.hpp"
#include "Items.hpp"
#include "Money.hpp"
#include "CheckValency.hpp"

class ChasingRoom
{
    float WIDTH;
    float HEIGHT;

    Rectangle menuButton;

    std::vector<Rectangle>verticalLimits;
    std::vector<Rectangle>horizontalLimits;

    std::shared_ptr<Teacher> teacher;
    std::shared_ptr<InventorySystem> inventory;
    std::shared_ptr<Items> items;
    std::shared_ptr<Money> money;

    std::shared_ptr<SplitElements>splitElements;
    std::string stringDirHolder;
    std::shared_ptr<Player>player;
    std::shared_ptr<Navigator>dir;
    std::shared_ptr<CheckValency> checkValency;

    std::vector<std::string> stringsBackgroundName;
    std::vector<Texture2D> texturesBackgrounds;
    int doors;

    Texture2D leftDoor;
    Texture2D rightDoor;
    Texture2D upDoor;
    Texture2D downDoor;

    Vector2 doorsPositons[4];

    bool loadCheckValencyMiniGame;
    bool loadSplitElementsMiniGame;
    bool miniGameSplitElementsPlayed;
    bool miniGameCheckValencyPlayed;
    Vector2 positionOfMiniGamePlace;

    unsigned seed;

    //random engine from random library
    std::mt19937 gen;

    Texture2D spawnPointBackground;
    Texture2D table; 
    Texture2D tableBackground;
    Texture2D rightArrow;

    std::vector<Vector2> points;

public:
    ChasingRoom();
    ChasingRoom(int doors);
    ~ChasingRoom();
    void drawChasingRoom();
    void drawSplitElementsMiniGame();
    void drawCheckValencyMiniGame();
    void unload();
    void load();
    void checkDoors();
};