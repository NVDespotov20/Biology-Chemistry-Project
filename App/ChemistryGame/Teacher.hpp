#pragma once
#include"pch.hpp"

class Teacher {
private:
    Texture2D right;
    Texture2D left;
    Texture2D up;
    Texture2D down;
    Texture2D SpasNPC;
    Rectangle SpasNPCView;
    int counterFlip;
    int counterFrame;
    Vector2 position;
    int speed;
    bool isSeen;
    Rectangle itemRec;
public:
    Teacher();
    void LoadSprites();
    void Update(Vector2 posHero, Rectangle heroRec);
    void Draw(bool check);
};