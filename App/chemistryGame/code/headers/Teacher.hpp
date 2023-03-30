#pragma once
class Teacher {
private:
    Texture2D right;
    Texture2D left;
    Texture2D idle;
    Texture2D teacherTextureChasing;
    Texture2D teacherTextureIdle;

    Rectangle SpasNPCViewChasing;
    Rectangle SpasNPCViewIdle;
    Rectangle itemRec;

    int counterFrameIdle;
    int counterFrameChasing;
    Vector2 position;

    int speed;
public:
    bool isSeen;
    Teacher();
    ~Teacher();
    void LoadSprites();
    void update(Vector2 posHero, Rectangle heroRec);
    void draw();
};