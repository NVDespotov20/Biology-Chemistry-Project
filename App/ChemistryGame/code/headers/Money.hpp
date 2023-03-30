#pragma once
class Money
{
	//singleton

	static std::shared_ptr<Money> instantiate_;
	public:
	Money();
	~Money();

public:
	static std::shared_ptr<Money> getInstantiation();
	bool insertMoney;
	int money;
	int allMoney, allMoneyCopy, moneySpent;
	std::string printMoney;
	void addMoney();
	void drawMoney();

};

