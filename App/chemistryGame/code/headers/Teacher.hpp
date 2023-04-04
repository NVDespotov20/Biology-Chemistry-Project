#pragma once
#include "pchGame.hpp"
class Teacher {


private:
    static std::shared_ptr<Teacher> instantiate_;
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
    bool isSeen;
    Teacher();

public:
     int WIDTH; 
     int HEIGHT;
    static std::shared_ptr<Teacher> getInstantiation();
    ~Teacher();
    void LoadSprites();
    void update(Vector2 posHero, Rectangle heroRec);
    void draw();
    void changePosition(Vector2 newPos);
    void setActive(bool state);
};