#include "ClassDefinitions.h"

void DeleteConsole() {
	cout << "������� ����� ������ ����� ����������..." << endl;
	cin.get();
	system("cls");
}

int inputOfPositiveNum() {
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

float inputOfFloat() {
	float num;
	cin >> num;
	while (!cin || (getchar() != '\n') || num < 0) {
		cout << "����� ������ ������������ ����� ������ ����! ��������� ����:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> num;
	}
	return num;
}

int inputOfPercent() {
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