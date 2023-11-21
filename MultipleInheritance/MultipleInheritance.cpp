#include "ClassDefinitions.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	City* arr[5];
	arr[0] = new Bank();
	arr[1] = new Store("Минск", 1000000, 352.3, "Пушкинская", 5, 0);
	arr[2] = new TradeDeal("Гомель", 600000, 184.2, "Ленина", 5, "None", 0, 0, 0);
	arr[3] = new Salesman();
	arr[4] = new Customer("Брест", 350000, 135.1, "Советская", 2, "None", 0, 0, 0, "Иванов Иван Иванович", 10000);
	/*for (int i = 0; i < 5; i++) {
		arr[i]->printInfo();
		cout << "\n\n";
	}*/
	int choice = 1;
	while (choice != 3) {
		cout << "Выберите пункт меню:" << endl << endl
			<< "1. Изменить данные." << endl
			<< "2. Вывести данные." << endl
			<< "3. Завершить работу программы." << endl << endl
			<< "Что желаете выбрать? (1, 2, 3)" << endl << endl;
		choice = inputOfNaturalNum();
		system("cls");
		int choice1 = 1;
		int choice2 = 1;
		switch (choice) {
		case 1:
			while (choice1 != 6) {
				cout << "Выберите для какого объекта изменить данные:" << endl << endl
					<< "1. Изменить данные для объекта \"Bank\"." << endl
					<< "2. Изменить данные для объекта \"Store\"." << endl
					<< "3. Изменить данные для объекта \"TradeDeal\"." << endl
					<< "4. Изменить данные для объекта \"Salesman\"." << endl
					<< "5. Изменить данные для объекта \"Customer\"." << endl
					<< "6. Вернуться назад." << endl << endl
					<< "Что желаете выбрать? (1, 2, 3, 4, 5, 6)" << endl << endl;
				choice1 = inputOfNaturalNum();
				system("cls");
				switch (choice1) {
				case 1:
					cout << "Изменение данных для объекта \"Bank\": " << endl << endl;
					arr[0]->changeData();
					cout << endl << endl << "Вы успешно изменили данные!" << endl << endl;
					DeleteConsole();
					break;
				case 2:
					cout << "Изменение данных для объекта \"Store\": " << endl << endl;
					arr[1]->changeData();
					cout << endl << endl << "Вы успешно изменили данные!" << endl << endl;
					DeleteConsole();
					break;
				case 3:
					cout << "Изменение данных для объекта \"TradeDeal\": " << endl << endl;
					arr[2]->changeData();
					cout << endl << endl << "Вы успешно изменили данные!" << endl << endl;
					DeleteConsole();
					break;
				case 4:
					cout << "Изменение данных для объекта \"Salesman\": " << endl << endl;
					arr[3]->changeData();
					cout << endl << endl << "Вы успешно изменили данные!" << endl << endl;
					DeleteConsole();
					break;
				case 5:
					cout << "Изменение данных для объекта \"Customer\": " << endl << endl;
					arr[4]->changeData();
					cout << endl << endl << "Вы успешно изменили данные!" << endl << endl;
					DeleteConsole();
					break;
				case 6:
					system("cls");
					break;
				default:
					cout << "Такого варианта не существует! Повторите ввод" << endl << endl;
					DeleteConsole();
					break;
				}
			}
			break;
		case 2:
			while (choice2 != 7) {
				cout << "Выберите какие данные хотите вывести:" << endl << endl
					<< "1. Вывести данные об объекте \"Bank\"." << endl
					<< "2. Вывести данные об объекте \"Store\"." << endl
					<< "3. Вывести данные об объекте \"TradeDeal\"." << endl
					<< "4. Вывести данные об объекте \"Salesman\"." << endl
					<< "5. Вывести данные об объекте \"Customer\"." << endl
					<< "6. Вывести данные о всех объектах" << endl
					<< "7. Вернуться назад." << endl << endl
					<< "Что желаете выбрать? (1, 2, 3, 4, 5, 6, 7)" << endl << endl;
				choice2 = inputOfNaturalNum();
				system("cls");
				switch (choice2) {
				case 1:
					cout << "Вывод данных об объекте \"Bank\": " << endl << endl;
					arr[0]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 2:
					cout << "Вывод данных об объекте \"Store\": " << endl << endl;
					arr[1]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 3:
					cout << "Вывод данных об объекте \"TradeDeal\": " << endl << endl;
					arr[2]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 4:
					cout << "Вывод данных об объекте \"Salesman\": " << endl << endl;
					arr[3]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 5:
					cout << "Вывод данных об объекте \"Customer\": " << endl << endl;
					arr[4]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 6:
					cout << "Вывод данных об объекте \"Bank\": " << endl << endl;
					arr[0]->printInfo();
					cout << endl << endl << endl << endl;
					cout << "Вывод данных об объекте \"Store\": " << endl << endl;
					arr[1]->printInfo();
					cout << endl << endl << endl << endl;
					cout << "Вывод данных об объекте \"TradeDeal\": " << endl << endl;
					arr[2]->printInfo();
					cout << endl << endl << endl << endl;
					cout << "Вывод данных об объекте \"Salesman\": " << endl << endl;
					arr[3]->printInfo();
					cout << endl << endl << endl << endl;
					cout << "Вывод данных об объекте \"Customer\": " << endl << endl;
					arr[4]->printInfo();
					cout << endl << endl;
					DeleteConsole();
					break;
				case 7:
					system("cls");
					break;
				default:
					cout << "Такого варианта не существует! Повторите ввод" << endl << endl;
					DeleteConsole();
					break;
				}
			}
			break;
		case 3:
			cout << "Досвидания!" << endl << endl;
			break;
		default:
			cout << "Такого варианта не существует! Повторите ввод" << endl << endl;
			DeleteConsole();
			break;
		}
	}
}