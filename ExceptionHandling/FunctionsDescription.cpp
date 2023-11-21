#include "Header.h"

double InputOfDouble() {
	double num;
	cin >> num;
	while (!cin || (getchar() != '\n') || num < 0) {
		cout << "����� ������ ������������ ����� ������ ����! ��������� ����:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> num;
	}
	return num;
}

double InputOfNumber() {
	double num;
	cin >> num;
	try {
		if (!cin || (getchar() != '\n')) throw "������ ���������!";
	}
	catch (const char* message) {
		cout << message << "(������ ����������)" << endl;
		throw;
	}
}

int InputOfPercent() {
	int percent;
	cin >> percent;
	while (!cin || (getchar() != '\n') || percent < 0 || percent > 100) {
		cout << "������������ ���� ������! ��������� ����:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> percent;
	}
	return percent;
}

int InputOfPositiveNum() {
	int num;
	cin >> num;
	while (!cin || (getchar() != '\n') || num < 0) {
		cout << "����� ������ ����� ��������������� �����! ��������� ����:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> num;
	}
	return num;
}

void terminateFunction() {
	cout << "�� ������ �� ���� ���������� catch! ���������� ���������..." << endl;
	exit(-1);
}

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}