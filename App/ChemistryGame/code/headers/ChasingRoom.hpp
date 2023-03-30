#pragma once
#include "Player.hpp"
#include "Teacher.hpp"
#include "Inventory.hpp"
#include "SplitElements.hpp"
#include "Navigator.hpp"
#include "Items.hpp"
#include "Money.hpp"
class ChasingRoom
{
    int WIDTH;
    int HEIGHT;
    std::shared_ptr<Teacher> teacher;
    std::shared_ptr<InventorySystem> inventory;
    std::shared_ptr<Items> items;
    std::shared_ptr<Money> money;

    std::shared_ptr<SplitElements>splitElements;
    std::string stringDirHolder;
    std::shared_ptr<Player>player;
    std::shared_ptr<Navigator>dir;

    std::vector<const char*> stringsBackgroundName;
    int doors;
    bool loadMiniGame;
    bool miniGamePlayed;
    Vector2 positionOfMiniGamePlace;
public:
    ChasingRoom();
    ChasingRoom(int doors);
    ~ChasingRoom();
    void drawChasingRoom();
    void drawMiniGame();

    void checkDoors();
};