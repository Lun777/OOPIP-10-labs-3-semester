#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <stdlib.h>

using namespace std;

int inputOfNaturalNum();

float inputOfFloat();

int inputOfPercent();

using namespace std;

void DeleteConsole();

class City {
	string name;
	int population;
	float area;
public:
	City() {
		name = "�����";
		population = 345000;
		area = 146.1;
	}
	City(string name, int population, float area) {
		this->name = name;
		this->population = population;
		this->area = area;
	}
	virtual void changeData() {
		cout << "������� �������� ������: ";
		getline(cin, name);
		cout << "������� ��������� ������: ";
		population = inputOfNaturalNum();
		cout << "������� ������� ������ (� ��^2): ";
		area = inputOfFloat();
	};
	virtual void printInfo() {
		cout << "�������� ������: " << name << endl;
		cout << "��������� ������ " << name << ": " << population << endl;
		cout << "������� ������ " << name << ": " << area << endl;
	};
};

class Street : public City {
	string address;
public:
	Street() {
		address = "���������";
	}
	Street(string name, int population, float area, string street) : City(name, population, area) {
		address = street;
	}
	void changeData() override {
		City::changeData();
		cout << "������� �������� �����: ";
		getline(cin, address);
	}
	void printInfo() override {
		City::printInfo();
		cout << "�������� �����: " << address << endl;
	}
};

class Building : public Street {
	int numOfFloors;
public:
	Building() {
		numOfFloors = 2;
	}
	Building(string name, int population, float area, string street, int numOfFloors) : Street(name, population, area, street) {
		this->numOfFloors = numOfFloors;
	}
	void changeData() override {
		Street::changeData();
		cout << "������� ���������� ������: ";
		numOfFloors = inputOfNaturalNum();
	}
	void printInfo() override {
		Street::printInfo();
		cout << "���������� ������: " << numOfFloors << endl;
	}
};

class Bank : virtual public Building {
	string credit;
	int percent;
public:
	Bank() {
		credit = "None";
		percent = 0;
	}
	Bank(string name, int population, float area, string street, int numOfFloors, string credit, int percent) : Building(name, population, area, street, numOfFloors) {
		this->credit = credit;
		this->percent = percent;
	}
	void setCreditName() {
		cout << "������� �������� �������: ";
		getline(cin, credit);
	}
	void setPercent() {
		cout << "��� ����� ������� ������ ������ ������: ";
		percent = inputOfPercent();
	}
	void printCreditName() {
		cout << "�������� �������: " << credit << endl;
	}
	void printPercent() {
		cout << "������� ��� ������� ������ ������ ������: " << percent << endl;
	}
	void changeData() override {
		Building::changeData();
		setCreditName();
		setPercent();
	}
	void printInfo() override {
		Building::printInfo();
		printCreditName();
		printPercent();
	}
};

class Store : virtual public Building {
	int numOfGoods;
public:
	Store() {
		numOfGoods = 0;
	}
	Store(string name, int population, float area, string street, int numOfFloors, int numOfGoods) : Building(name, population, area, street, numOfFloors) {
		this->numOfGoods = numOfGoods;
	}
	void setNumOfGoods() {
		cout << "������� ���������� ��������� �������: ";
		numOfGoods = inputOfNaturalNum();
	}
	int getNumOfGoods() {
		return numOfGoods;
	}
	void changeData() override {
		Building::changeData();
		setNumOfGoods();
	}
	void printInfo() override {
		Building::printInfo();
		cout << "���������� ��������� �������: " << numOfGoods << endl;
	}
};

class TradeDeal : public Bank, public Store {
	float sum;
public:
	TradeDeal() {
		sum = 0;
	}
	TradeDeal(string name, int population, float area, string street, int numOfFloors, string credit, int percent, int numOfGoods, float sum) : Bank(name, population, area,
		street, numOfFloors, credit, percent), Store(name, population, area, street, numOfFloors, numOfGoods) {
		this->sum = sum;
	}
	void calcSumOfDeal() {
		sum = 0;
		int size = getNumOfGoods();
		cout << "����� ����� �������: ";
		for (int i = 0; i < size; i++) {
			sum += rand() / 100;
		}
		cout << sum << endl;
	}
	void printSumOfDeal() {
		cout << "����� ����������� ������: " << sum << endl;
	}
	void changeData() override {
		Building::changeData();
		setNumOfGoods();
		setCreditName();
		setPercent();
		calcSumOfDeal();
	}
	void printInfo() override {
		Building::printInfo();
		cout << "���������� ��������� ���� �������: " << getNumOfGoods() << endl;
		printCreditName();
		printPercent();
		printSumOfDeal();
	}

};

class Customer : public TradeDeal {
	string FullName;
	float cash;
public:
	Customer() {
		FullName = "None";
		cash = 0;
	}
	Customer(string name, int population, float area, string street, int numOfFloors, string credit, int percent, int numOfGoods, float sum, string FullName, float cash) :
		TradeDeal(name, population, area, street, numOfFloors, credit, percent, numOfGoods, sum) {
		this->FullName = FullName;
		this->cash = cash;
	}
	void changeData() override {
		TradeDeal::changeData();
		cout << "������� ��� ����������: ";
		getline(cin, FullName);
		cout << "������� ����� ��� �����: ";
		cash = inputOfFloat();
	}
	void printInfo() override {
		TradeDeal::printInfo();
		cout << "��� ����������: " << FullName << endl;
		cout << "����� ��� �����: " << cash << endl;
	}
};

class Salesman : public TradeDeal {
	string FullName;
public:
	Salesman() {
		FullName = "None";
	}
	Salesman(string name, int population, float area, string street, int numOfFloors, string credit, int percent, int numOfGoods, float sum, string FullName) :
		TradeDeal(name, population, area, street, numOfFloors, credit, percent, numOfGoods, sum) {
		this->FullName = FullName;
	}
	void changeData() override {
		TradeDeal::changeData();
		cout << "������� ��� ��������: ";
		getline(cin, FullName);
	}
	void printInfo() override {
		TradeDeal::printInfo();
		cout << "��� ��������: " << FullName << endl;
	}
};