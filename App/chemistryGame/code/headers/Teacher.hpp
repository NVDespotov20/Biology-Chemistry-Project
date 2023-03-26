#pragma once
class Teacher {
private:
    Texture2D right;
    Texture2D left;
    Texture2D up;
    Texture2D down;
    Texture2D SpasNPC;

    Rectangle SpasNPCView;
    Rectangle itemRec;

    int counterFlip;
    int counterFrame;

    Vector2 position;

    bool isSeen;
public:
    int speed;
    Teacher();
    ~Teacher();
    void LoadSprites();
    void update(Vector2 posHero, Rectangle heroRec);
    void draw();
};