#pragma once
class Money
{
    //singleton

    static std::shared_ptr<Money> instantiate_;

public:
    Money();
    ~Money();

    static std::shared_ptr<Money> getInstantiation();

    void addMoney();
    void drawMoney();

private:
    int money;
    float WIDTH, HEIGHT;
};