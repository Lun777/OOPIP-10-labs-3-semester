#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <limits>

using namespace std;


double InputOfDouble();

double InputOfNumber();

int InputOfPercent();

int InputOfPositiveNum();

void terminateFunction();

void DeleteConsole();

class NegativeCountOfGoodsException : public exception {															// ����� ����������
public:
	NegativeCountOfGoodsException() : exception("������! ���������� ������� �� ����� ���� �������������!") {}
};

class Customer {
	string fullName;
	double cash;
	string phoneNumber;
public:
	Customer() {
		fullName = "������ ���� ��������";
		cash = 10000;
		phoneNumber = "375291111111";
	}
	Customer(string fullName, double cash, string phoneNumber) {
		this->fullName = fullName;
		this->cash = cash;
		this->phoneNumber = phoneNumber;
	}
	void setFullName(string fullName) {
		this->fullName = fullName;
	}
	void setCash(double cash) {
		this->cash = cash;
	}
	void setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	string getFullName() {
		return fullName;
	}
	double getCash() {
		return cash;
	}
	string getPhoneNumber() {
		return phoneNumber;
	}
	void topUpCash(double amountOfMoney) {
		cash += amountOfMoney;
	}
};

class Good {
	string name;
	int price;
public:
	Good() {
		cout << "�������� ����������� ������ Good..." << endl;										// ��������� ���������� � ������������
		cout << "������� �������� ��������" << endl;
		getline(cin, name);
		cout << "������� ���� �� " << name << endl;
		price = InputOfNumber();
		/*name = "���";
		price = 10;*/
	}
	Good(string name, double price) {
		this->name = name;
		this->price = price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(double price) {																		// ��������� ������ �� ������� ���������
		try {
			if (price > INT_MAX) {
				throw range_error("������! ����� �� ������� ��������� int!");
				return;
			}
			this->price = price;
		}
		catch (range_error range) {
			cout << range.what() << endl;
		}
	}
	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
	~Good() {
		/*cout << "�������� ���������� ������ Good..." << endl;*/
	}
};

class Order {
	Good* basket;
	int count = 0;
	int basketPrice;
public:
	Order() {
		count = 0;
		basketPrice = 0;
	}
	Order(Good* basket, int count, double basketPrice) {
		this->basket = basket;
		this->count = count;
		this->basketPrice = basketPrice;
	}
	void addGoodToBasket() {																// ��������� ���������� � ���������� new
		Good* temp = basket;
		try {
			basket = new Good[(count + 1) * 1000000000000];
		}
		catch (bad_alloc) {
			cout << "������ �����������!" << endl;
			throw;
		}
		for (int i = 0; i < count; i++) {
			basket[i] = temp[i];
		}
		basketPrice += basket[count].getPrice();
		count++;
		delete[] temp;
	}
	void setBasketGoods(Good* basket, int count) {
		delete this->basket;
		this->basket = basket;
		this->count = count;
	}
	void setBasketGoodsPrice() {
		if (!basket) {
			cout << "������� �����!" << endl;
			return;
		}
		basketPrice = 0;
		for (int i = 0; i < count; i++) {
			basketPrice += basket[i].getPrice();
		}
	}
	void setCount(int count) {																	// ����������� ��� ���������� (������������� ����� �������)
		try {
			if (count < 0) {
				throw NegativeCountOfGoodsException();
				return;
			}
			this->count = count;
		}
		catch (NegativeCountOfGoodsException& error) {
			cout << error.what();
		}
	}
	double getAvgPriceOfGoods() {														// ��������� ���������� (������� �� ����)								
		if (!basket) {
			return NULL;
		}
		try {
			if (!count) {
				throw 0;
			}
			return basketPrice / count;
		}
		catch (int) {
			cout << "�������� ����������! ���������� ������� ����� 0" << endl;
			return -1;
		}
	}									
	Good* getBasket() {
		if (basket) {
			return basket;
		}
		return NULL;
	}
	int getCount() {
		if (basket) {
			return count;
		}
		return 0;
	}
	double getPrice() {
		if (basket) {
			return basketPrice;
		}
		return 0;
	}
	void deleteBasket() {
		delete basket;
		basket = NULL;
	}
};

class Drink : public Good {
	int sugarContent;																	//���������� ������ � �������
	int alcPerc;																			//������� ���������� ��������
public:
	Drink() {
		sugarContent = 0;
		alcPerc = 0;
	}
	Drink(int sugar, int alc) {
		sugarContent = sugar;
		alcPerc = alc;
	}
	void setSugarContent(int sugar) {
		sugarContent = sugar;
	}
	void setAlcPerc(int alc) {
		alcPerc = alc;
	}
	int getSugarContent() {
		return sugarContent;
	}
	int getAlcPerc() {
		return alcPerc;
	}
};

class FreshFruits : public Good {
	int daysUntilOverdue;																	//���� �� ��������� ����� ��������
	double weight;																			//� �������
public:
	FreshFruits() {
		daysUntilOverdue = 30;
		weight = 1000;
	}
	FreshFruits(int days, int weight) {
		daysUntilOverdue = days;
		this->weight = weight;
	}
	void setDaysUntiOverdue(int days) {
		daysUntilOverdue = days;
	}
	void setWeight(int weight) {
		this->weight = weight;
	}
	int getDaysUntilOverdue() {
		return daysUntilOverdue;
	}
	double getWeight() {
		return weight;
	}
};