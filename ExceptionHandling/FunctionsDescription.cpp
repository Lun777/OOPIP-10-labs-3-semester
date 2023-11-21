#include "Header.h"

double InputOfDouble() {
	double num;
	cin >> num;
	while (!cin || (getchar() != '\n') || num < 0) {
		cout << "Нужно ввести вещественное число больше нуля! Повторите ввод:" << endl;
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
		if (!cin || (getchar() != '\n')) throw "Ошибка типизации!";
	}
	catch (const char* message) {
		cout << message << "(первый обработчик)" << endl;
		throw;
	}
}

int InputOfPercent() {
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

int InputOfPositiveNum() {
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

void terminateFunction() {
	cout << "Не найден ни один обработчик catch! Завершение программы..." << endl;
	exit(-1);
}

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}