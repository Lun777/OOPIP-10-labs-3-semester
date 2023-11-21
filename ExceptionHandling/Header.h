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

class NegativeCountOfGoodsException : public exception {															// Класс исключения
public:
	NegativeCountOfGoodsException() : exception("Ошибка! Количество товаров не может быть отрицательным!") {}
};

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
	int price;
public:
	Good() {
		cout << "Вызвался конструктор класса Good..." << endl;										// генерация исключения в конструкторе
		cout << "Введите название продукта" << endl;
		getline(cin, name);
		cout << "Введите цену на " << name << endl;
		price = InputOfNumber();
		/*name = "Сок";
		price = 10;*/
	}
	Good(string name, double price) {
		this->name = name;
		this->price = price;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPrice(double price) {																		// генерация выхода за пределы диапазона
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
	double getPrice() {
		return price;
	}
	~Good() {
		/*cout << "Вызвался деструктор класса Good..." << endl;*/
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
	void addGoodToBasket() {																// генерация исключения с оператором new
		Good* temp = basket;
		try {
			basket = new Good[(count + 1) * 1000000000000];
		}
		catch (bad_alloc) {
			cout << "Память закончилась!" << endl;
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
			cout << "Корзина пуста!" << endl;
			return;
		}
		basketPrice = 0;
		for (int i = 0; i < count; i++) {
			basketPrice += basket[i].getPrice();
		}
	}
	void setCount(int count) {																	// собственный тип исключения (отрицательное число товаров)
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
	double getAvgPriceOfGoods() {														// Генерация исключения (деление на ноль)								
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
			cout << "Операция невозможна! Количество товаров равно 0" << endl;
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