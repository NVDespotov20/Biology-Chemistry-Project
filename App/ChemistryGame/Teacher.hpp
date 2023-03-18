#pragma once
#include"pch.hpp"

class Teacher {
private:
    Texture2D r;
    Texture2D l;
    Texture2D u;
    Texture2D d;
    Texture2D SpasNPC;
    Rectangle SpasNPCView;
    Texture2D itemForShowingTheMinigame;
    int counterFlip;
    int counterFrame;
    Vector2 position;
    Rectangle positionRec;
    int speed;
    bool isSeen;
    Rectangle itemRec;
public:
    Teacher();
    void LoadSprites();
    void Draw(int xBg, int yBg);
    void Update(Vector2 posHero, int xBg, int yBg);
    void Draw(int xBg, int yBg, bool check);
    void CheckMiniGame(bool& check, Rectangle heroRec);
    void Update(Vector2 posHero, int xBg, int yBg, Rectangle heroRec);
};