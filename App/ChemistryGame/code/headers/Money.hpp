#pragma once
class Money
{
	Money();
	~Money();

public:
	bool insertMoney;
	int money;
	int allMoney, allMoneyCopy, moneySpent;
	std::string printMoney;
	void addMoney();
	void drawMoney();

};

