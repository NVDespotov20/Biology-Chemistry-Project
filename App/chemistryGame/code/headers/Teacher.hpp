#pragma once
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
    bool isSeen;
    Rectangle itemRec;
public:
    int speed;
    Teacher();
    void LoadSprites();
    void Update(Vector2 posHero, Rectangle heroRec);
    void Draw(bool check);
};