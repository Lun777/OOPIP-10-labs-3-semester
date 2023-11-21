#include "ClassDefinitions.h"

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}

int inputOfPositiveNum() {
	int num;
	cin >> num;
	while (!cin || (getchar() != '\n') || num < 0) {
		cout << "Нужно ввести целое неотрицательное число! Повторите ввод:" << endl;
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
		cout << "Нужно ввести вещественное число больше нуля! Повторите ввод:" << endl;
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
		cout << "Некорректный ввод данных! Повторите ввод:" << endl;
		cin.clear();
		rewind(stdin);
		cin >> percent;
	}
	return percent;
}