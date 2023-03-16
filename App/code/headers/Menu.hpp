#pragma once
class Menu
{
public:
    float WIDTH;
    float HEIGHT;

    Menu();
    ~Menu();
    void drawMainMenu();
    static std::shared_ptr<Menu> getInstantiation();
private:
    static std::shared_ptr<Menu> instantiate_;

    void unload();
    void load();
    bool isClicked(const Vector2& mPos, const Rectangle& rec);

    Texture2D menuBackground;

    Rectangle menuBackgroundRec;

    Vector2 mousePoint;

    std::vector<Rectangle> buttonsRecs;
};