#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	set_terminate(terminateFunction);
	while (true) {
		cout << "Какой тип исключительной ситуации хотите обработать?" << endl << endl;
		cout << "1. Ошибка деления на 0." << endl;
		cout << "2. Ошибка создания объекта в конструкторе." << endl;
		cout << "3. Ошибка выделения памяти оператором new." << endl;
		cout << "4. Работа изменённой terimante() функции." << endl;
		cout << "5. Собственный тип исключения (отрицательное количество товаров)." << endl;
		cout << "6. Ошибка выхода за пределы диапазона int." << endl;
		cout << "0. Завершение работы программы." << endl << endl;
		cout << "Ваш выбор: ";
		int choice = InputOfPositiveNum();
		switch (choice) {
		case 1:
		{
			Good* tempArr = new Good[0];															// ошибка деления на 0
			Order obj(tempArr, 0, 0);
			obj.getAvgPriceOfGoods();
			delete[] tempArr;
			cout << endl;
			DeleteConsole();
		}
			break;
		case 2:
		{	
			try {																					// переадресация вызова и ошибка создания объекта в конструкторе
				Good ob;
			}
			catch (const char* message) {
				cout << message << "(второй обработчик)" << endl;
			}
			cin.get();
			cout << endl;
			DeleteConsole();
		}
			break;
		case 3:
		{
			Order obj;
			while (1) {																			// ошибка выделения памяти оператором new
				try {
					obj.addGoodToBasket();
				}
				catch (bad_alloc) {
					cout << "Удаляем выделенную память!" << endl;
					obj.deleteBasket();
					break;
				}
			}
			cout << endl;
			DeleteConsole();
		}
			break;
		case 4:
		{
			int count = 0;																	//set_terminate функция
			try {
				if (count == 0) throw "Деление на ноль!";
				cout << 1 / count << endl;
			}
			catch (int) {
				cout << "Произошло деление на ноль" << endl;
			}
			cout << endl;
			DeleteConsole();
		}
			break;
		case 5:
		{
			Order obj;
			obj.setCount(-1);																// собственный тип исключения (отрицательное число товаров)
			cout << endl;
			DeleteConsole();
		}
			break;
		case 6:
		{
			Good temp;																		// ошибка выхода за пределы диапазона значений int
			temp.setPrice(18239218392321321);
			cout << endl;
			DeleteConsole();
		}
			break;
		case 0:
			return 1;
			break;
		default:
			cout << "Вы ввели недопустимое значение! Повторите ввод!" << endl;
			cout << endl;
			DeleteConsole();
			break;
		}
	}
	//Good* tempArr = new Good[0];															// ошибка деления на 0
	//Order obj(tempArr, 0, 0);
	//obj.getAvgPriceOfGoods();
	//try {																					// переадресация вызова и ошибка создания объекта в конструкторе
	//	Good ob;
	//}
	//catch (const char* message) {
	//	cout << message << "(второй обработчик)" << endl;
	//}
	//Order obj;
	//while (1) {																			// ошибка выделения памяти оператором new
	//	try {
	//		obj.addGoodToBasket();
	//	}
	//	catch (bad_alloc) {
	//		cout << "Удаляем выделенную память!" << endl;
	//		obj.deleteBasket();
	//		break;
	//	}
	//}
	//int count = 0;																	//set_terminate функция
	//try {
	//	if (count == 0) throw "Деление на ноль!";
	//	cout << 1 / count << endl;
	//}
	//catch (int) {
	//	cout << "Произошло деление на ноль" << endl;
	//}
	//obj.setCount(-1);																// собственный тип исключения (отрицательное число товаров)
	//Good temp;																		// ошибка выхода за пределы диапазона значений int
	//temp.setPrice(18239218392321321);
}