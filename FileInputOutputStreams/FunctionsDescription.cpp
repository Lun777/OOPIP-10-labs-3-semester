#include "Header.h"

double InputOfDouble() {
	double num;
	cin.unsetf(ios::skipws);
	cin >> num;
	while (!cin.good() || cin.peek() != '\n' || num < 0) {
		cout << "����� ������ ������������ ����� ������ ����! ��������� ����:" << endl;
		cin.clear();
		cin.ignore(10, '\n');
		cin >> num;
	}
	cin.setf(ios::skipws);
	cin.get();
	return num;
}

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}

int InputOfPositiveNum() {
	int num;
	cin.unsetf(ios::skipws);
	cin >> num;
	while (cin.bad() || cin.peek() != '\n' || num < 0) {
		cout << "����� ������ ����� ��������������� �����! ��������� ����:" << endl;
		cin.clear();
		cin.ignore(10, '\n');
		cin >> num;
	}
	cin.setf(ios::skipws);
	cin.get();
	return num;
}

void goodSearchByName(vector<Good>& goods) {
	system("cls");
	string goodName;
	string lowerGoodName;
	bool isFind = false;
	cout << "������� �������� ������������� ������: ";
	char tempCh;
	while (true) {
		char ch = _getch();
		tempCh = ch;
		if ((int)ch == 13) {  // Enter key
			break;
		}
		if ((int)ch == 8) {  // Backspace key
			if (!lowerGoodName.empty()) {
				lowerGoodName.pop_back();
				goodName.pop_back();
				system("cls");
			}
		}
		if ((int)ch != 8) {
			lowerGoodName += tolower(ch);
			goodName += ch;
		}
		system("cls");
		isFind = false;
		cout << "������� �������� ������������� ������: " << goodName;
		for (int index = 0; index < goods.size(); index++) {
			string goodName = goods[index].getName();
			for (char& c : goodName) {
				c = tolower(c);
			}
			if (goodName.find(lowerGoodName) == 0) {
				if (!isFind) {
					cout << setw(4) << endl << "-" << "------------------------------------------------------------------------------------" << endl;
					cout << setw(4) << "|" << setw(30) << "�������� ������" << setw(16) << "|" << setw(19) << "���������� ������" << setw(3) << "|" << setw(13) << "���� ������"
						<< "  |" << endl;
					cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl;
					isFind = true;
				}
				cout << setw(4) << "|" << setw(26) << goods[index].getName() << setw(20) << "|" << setw(12) << goods[index].getCount() << setw(10) << "|" << setw(10)
					<< goods[index].getPrice() << setw(6) << "|" << endl;
				cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl;
			}
		}
		if (!isFind) {
			cout << endl << "����� � ����� ������ �� ������." << endl;
		}
	}
	if (lowerGoodName.empty() && (int)tempCh != 13) {

	}
	if (!isFind && !lowerGoodName.empty()) {
		cout << "����� � ����� ������ �� ������." << endl;
	}
}

void goodSearchByCount(vector<Good>& goods) {
	system("cls");
	int count;
	bool isFind = false;
	int index = 0;
	cout << "������� ���������� �������: ";
	count = InputOfPositiveNum();
	for (index = 0; index < goods.size(); index++) {
		if (count == goods[index].getCount()) {
			isFind = true;
			break;
		}
	}
	if (isFind) {
		cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl;
		cout << setw(4) << "|" << setw(30) << "�������� ������" << setw(16) << "|" << setw(19) << "���������� ������" << setw(3) << "|" << setw(13) << "���� ������"
			<< "  |" << endl;
		for (int i = 0; i < goods.size(); i++) {
			if (count == goods[i].getCount()) {
				cout << setw(4) << "|" << "---------------------------------------------|---------------------|---------------|" << endl;
				cout << setw(4) << "|" << setw(26) << goods[i].getName() << setw(20) << "|" << setw(12) << goods[i].getCount() << setw(10) << "|" << setw(10)
					<< goods[i].getPrice() << setw(6) << "|" << endl;
			}
		}
		cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl << endl;
	}
	else {
		cout << "\n������� � ����� ���������� � ������ ���!" << endl << endl;
	}
}

void goodSearchByPrice(vector<Good>& goods) {
	system("cls");
	double price;
	bool isFind = false;
	int index = 0;
	cout << "������� ����: ";
	price = InputOfDouble();
	for (index = 0; index < goods.size(); index++) {
		if (price == goods[index].getPrice()) {
			isFind = true;
			break;
		}
	}
	if (isFind) {
		cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl;
		cout << setw(4) << "|" << setw(30) << "�������� ������" << setw(16) << "|" << setw(19) << "���������� ������" << setw(3) << "|" << setw(13) << "���� ������"
			<< "  |" << endl;
		for (int i = 0; i < goods.size(); i++) {
			if (price == goods[i].getPrice()) {
				cout << setw(4) << "|" << "---------------------------------------------|---------------------|---------------|" << endl;
				cout << setw(4) << "|" << setw(26) << goods[i].getName() << setw(20) << "|" << setw(12) << goods[i].getCount() << setw(10) << "|" << setw(10)
					<< goods[i].getPrice() << setw(6) << "|" << endl;
			}
		}
		cout << setw(4) << "-" << "------------------------------------------------------------------------------------" << endl << endl;
	}
	else {
		cout << "\n������� �� ����� ���� � ������ ���!" << endl << endl;
	}
}