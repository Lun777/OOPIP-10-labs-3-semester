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
	void WriteGoodToFile() {
		ofstream file;
		file.open("BasketHistory.txt", ios::app | ios::binary);
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		else {
			file.write((char*)this, sizeof(*this));
			if (file.bad()) {
				cout << "Не удалось записать информацию в файл" << endl;
				exit(0);
			}
		}
		file.close();
	}
	void ReadGoodFromFile(int goodNumber) {
		ifstream file;
		file.open("BasketHistory.txt", ios::binary);
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		else {
			file.seekg(goodNumber * sizeof(Good));
			file.read((char*)this, sizeof(*this));
			if (file.bad()) {
				cout << "Не удалось считать информацию из файла" << endl;
				exit(0);
			}
		}
		file.close();
	}
	/*friend istream& operator>>(istream& s, Good& good) {
		string temp;
		getline(s, good.name);
		getline(s, temp);
		good.count = stoi(temp);
		getline(s, temp);
		good.price = stod(temp);
		return s;
	}
	friend ostream& operator<<(ostream& s, Good& good) {
		s << '\n' << good.name << '\n' << good.count << '\n' << good.price;
	}*/
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
	vector<Good>& deleteBasket() {
		for (int i = 0; i < count; i++) {
			basket.pop_back();
		}
		return basket;
	}
	void addGoodToBasket(Good& product) {
		basket.push_back(product);
		product.WriteGoodToFile();
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
	vector<Good>& deleteGoodFromBasket(int index) {
		basket.erase(basket.begin() + index);
		this->WriteGoodsToFile();
		count--;
		return basket;
	}
	vector<Good>& editGood(int index) {
		if (index >= basket.size() || index < 0) {
			cout << "Товара с таким индексом не существует!" << endl;
		}
		else {
			cout << "Хотите изменить название товара? (Да – 1, Нет – 0)" << endl;
			while (true) {
				int choice = InputOfPositiveNum();
				if (choice == 1) {
					string tempName;
					getline(cin, tempName);
					basket[index].setName(tempName);
				}
				else if (choice == 0) {
					break;
				}
				else {
					cout << "Необходимо ввести 1 – если хотите изменить количество товара или 0 – если не хотите" << endl;
				}
			}
			cout << "Хотите изменить количество товара(" << basket[index].getName() << ") ? (Да – 1, Нет – 0)" << endl;
			while (true) {
				int choice = InputOfPositiveNum();
				if (choice == 1) {
					int tempCount = InputOfPositiveNum();
					basket[index].setCount(tempCount);
				}
				else if (choice == 0) {
					break;
				}
				else {
					cout << "Необходимо ввести 1 – если хотите изменить количество товара или 0 – если не хотите" << endl;
				}
			}
			cout << "Хотите изменить цену товара(" << basket[index].getName() << ") ? (Да – 1, Нет – 0)" << endl;
			while (true) {
				int choice = InputOfPositiveNum();
				if (choice == 1) {
					double tempPrice = InputOfDouble();
					basket[index].setPrice(tempPrice);
				}
				else if (choice == 0) {
					break;
				}
				else {
					cout << "Необходимо ввести 1 – если хотите изменить цену товара или 0 – если не хотите" << endl;
				}
			}
			vector<Good>::iterator it = basket.begin();
			for (it; it != basket.end(); it++) {
				if (it->getName() == basket[index].getName()) {
					basket.insert(it + 1, basket[index]);
					count++;
					break;
				}
			}
			basket = deleteGoodFromBasket(index);
		}
		return basket;
	}
	int getPersonCount() {
		ifstream file;
		file.open("BasketHistory.txt", ios::binary);
		if (!file) {
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		file.seekg(0, ios::end);
		int endpos = file.tellg();
		file.close();
		return endpos / sizeof(Good);
	}
	void FillGoodsVect(Good& good) {
		ifstream file;
		file.open("BasketHistory.txt", ios::binary);
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		file.read((char*)(&good), sizeof(Good));
		while (!file.eof()) {
			basket.push_back(good);
			file.read((char*)(&good), sizeof(Good));
			if (!file.good()) {
				file.clear();
				break;
			}
		}
		file.close();
		count = this->getPersonCount();
	}
	void WriteGoodsToFile() {
		ofstream file;
		file.open("BasketHistory.txt", ios::trunc | ios::binary);
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < basket.size(); i++) {
				file.write((char*)(&basket[i]), sizeof(basket[i]));
				if (file.bad()) {
					cout << "Не удалось записать информацию в файл" << endl;
					exit(0);
				}
			}
		}
		file.close();
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

void goodSearchByName(vector<Good>& goods);

void goodSearchByCount(vector<Good>& goods);

void goodSearchByPrice(vector<Good>& goods);