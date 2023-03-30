#pragma once
class Money
{
	Money();
	~Money();
	void addMoney();

	int money;
	int allMoney, allMoneyCopy, moneySpent;
	std::string printMoney;
public:
	void drawMoney();
	bool insertMoney;

};

