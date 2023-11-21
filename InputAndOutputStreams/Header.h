#pragma once

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;


double InputOfDouble();

void DeleteConsole();

int InputOfPositiveNum();


class Customer {
	string fullName;
	double cash;
	string phoneNumber;
public:
	Customer() {
		fullName = "Иванов Иван Иванович";
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
	int count;
	double price;
public:
	Good() {
		/*cout << "Введите название продукта" << endl;
		getline(cin, name);
		cout << "Введите количество имеющегося товара" << endl;
		count = InputOfPositiveNum();
		cout << "Введите цену на " << name << endl;
		price = InputOfDouble();*/
		name = "None";
		count = 0;
		price = 0;
	}
	Good(string name, int count, double price) {
		this->name = name;
		this->count = count;
		this->price = price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setCount(int count) {
		this->count = count;
	}
	void setPrice(double price) {
		try {
			if (price > INT_MAX) {
				throw range_error("Ошибка! Выход за пределы диапазона int!");
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
	int getCount() {
		return count;
	}
	double getPrice() {
		return price;
	}
};

class Order {
	vector<Good> basket;
	int count = 0;
	double basketPrice;
public:
	Order() {
		count = 0;
		basketPrice = 0;
	}
	Order(vector<Good>& basket, int count, double basketPrice) {
		this->basket = basket;
		this->count = count;
		this->basketPrice = basketPrice;
	}
	void setBasketGoods(vector<Good>& basket, int count) {
		this->basket = basket;
		this->count = count;
	}
	void setBasketGoodsPrice() {
		if (count == 0) {
			cout << "Корзина пуста!" << endl;
			return;
		}
		basketPrice = 0;
		for (int i = 0; i < count; i++) {
			basketPrice += basket[i].getPrice();
		}
	}
	double getAvgPriceOfGoods() {														// Генерация исключения (деление на ноль)								
		if (count == 0) {
			return 0;
		}
		return basketPrice / count;
	}
	vector<Good>& getBasket() {
		return basket;
	}
	int getCountOfGoods() {
		return count;
	}
	double getPrice() {
		return basketPrice;
	}
	void deleteBasket() {
		for (int i = 0; i < count; i++) {
			basket.pop_back();
		}
	}
	void addGoodToBasket(Good& product) {
		basket.push_back(product);
		count++;
	}
	void printTableGoods() {
		cout.fill(' ');
		cout << endl << setw(65) << "Таблица с данными о товарах\n" << endl;
		cout.fill('-');
		cout.setf(ios::right);
		cout.width(85);
		cout << "-" << endl;
		cout.fill(' ');
		cout << "|" << setw(30) << "Название товара" << setw(16) << "|" << setw(19) << "Количество товара" << setw(3) << "|" << setw(13) << "Цена товара"
			<< "  |" << endl;
		for (int i = 0; i < basket.size(); i++) {
			cout.fill('-');
			cout.width(85);
			cout << "-" << endl;
			cout.fill(' ');
			cout << "|" << setw(26) << basket[i].getName() << setw(20) << "|" << setw(12) << basket[i].getCount() << setw(10) << "|" << setw(10)
				<< basket[i].getPrice() << setw(6) << "|" << endl;
		}
		cout.fill('-');
		cout.width(85);
		cout << "-" << endl;
		cout.fill(' ');
		cout.unsetf(ios::right);
	}
	void deleteGoodFromBasket(int index) {
		basket.erase(basket.begin() + index);
		count--;
	}
};

class Drink : public Good {
	int sugarContent;																	//Содержание сахара в граммах
	int alcPerc;																			//Процент содержания алкоголя
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
	int daysUntilOverdue;																	//Дней до окончания срока годности
	double weight;																			//В граммах
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

void FillGoodsVect(vector<Good>& basket);

void WriteGoodsToFile(vector<Good>& basket);

void goodSearchByName(vector<Good>& goods);

void goodSearchByCount(vector<Good>& goods);

void goodSearchByPrice(vector<Good>& goods);