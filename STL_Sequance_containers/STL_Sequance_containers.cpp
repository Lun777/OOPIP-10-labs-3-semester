#include "ClassDefinitions.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ExamTicket ticket;
	ticket.fillTasks();
	Student student;
	list<Student> studs;
	for (int i = 0; student.fillStudents(i); i++) {
		studs.push_back(student);
	}
	while (true) {
		int choice;
		cout << "Выберите пункт меню:" << endl;
		cout << "1. Регистрация" << endl;
		cout << "2. Авторизация" << endl;
		cout << "3. Выход" << endl << endl;
		cout << "Ваш выбор: ";
		choice = InputOfPositiveNum();
		switch (choice) {
		case 1:
			system("cls");
		{
			string name;
			int group;
			cout << "Введите полное имя, под которым хотите зарегистрироваться" << endl;
			getline(cin, name);
			cout << "Введите номер группы" << endl;
			group = InputOfPositiveNum();
			student.setStudentData(name, group, 0);
			studs.push_back(student);
			cout << "Вы успешно зарегистрировались!" << endl;
			DeleteConsole();
		}
		break;
		case 2:
			system("cls");
		{
			string name;
			bool isLoggedIn = false;
			cout << "Введите ваше полное имя" << endl;
			getline(cin, name);
			for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
				if (name == it->getStudentName()) {
					student = *it;
					isLoggedIn = true;
					break;
				}
			}
			if (!isLoggedIn) {
				cout << "Вы не зарегистрированы в системе!" << endl;
			}
			else {
				cout << "Вы успешно авторизировались!" << endl;
				DeleteConsole();
				bool isReturn = false;
				while (true) {
					if (isReturn) {
						break;
					}
					int choice;
					cout << "Выберите пункт меню:" << endl;
					cout << "1. Пройти тест" << endl;
					cout << "2. Вывести таблицу результатов пользователей" << endl;
					cout << "3. Поменять имя" << endl;
					cout << "4. Удалить пользователя" << endl;
					cout << "0. Вернуться назад" << endl << endl;
					cout << "Ваш выбор: ";
					choice = InputOfPositiveNum();
					switch (choice) {
					case 1:
						system("cls");
					{
						int currTestResult = 0;
						for (int i = 0; i < 10; i++) {
							ticket.printTask(i);
							cout << endl;
							cout << "Ваш ответ: ";
							int answer;
							answer = InputOfPositiveNum();
							if (answer == ticket.getCorrAns(i)) {
								cout << "Вы ответили верно!" << endl << endl;
								currTestResult += 1;
							}
							else {
								cout << "Вы ответили неверно! Правильный ответ: " << ticket.getCorrAns(i) << endl << endl;
							}
						}
						cout << "Ваш результат: " << currTestResult << endl;
						for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
							if (student.getStudentName() == it->getStudentName()) {
								it->setStudentData(student.getStudentName(), student.getStudentGroup(), currTestResult);
								student = *it;
							}
						}
					}
					DeleteConsole();
						break;
					case 2:
						system("cls");
						cout << setw(75) << "Таблица с данными пользователей" << endl << endl;
						cout << setw(20) << "ФИО" << setw(30) << "Группа" << setw(30) << "Результат теста" << endl;
						for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
							cout << setw(30) << it->getStudentName() << setw(21) << it->getStudentGroup() << setw(23) << it->getStudentResult() << endl;
						}
						DeleteConsole();
						break;
					case 3:
					{
						system("cls");
						cout << "Для подтверждения изменения необходимо ввести \"Да\", в ином случае действие не подтвердится" << endl;
						cout << "Ввод: " << endl;
						string temp;
						getline(cin, temp);
						if (temp == "Да") {
							cout << "Введите изменённое имя: ";
							getline(cin, temp);
							for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
								if (student.getStudentName() == it->getStudentName()) {
									it->setStudentData(temp, student.getStudentGroup(), student.getStudentResult());
									student = *it;
									cout << "Ваше имя успешно изменено!" << endl;
								}
							}
						}
					}
					DeleteConsole();
						break;
					case 4:
					{
						system("cls");
						cout << "Для подтверждения удаления необходимо ввести \"Да\", в ином случае действие не подтвердится" << endl;
						cout << "Ввод: " << endl;
						string temp;
						getline(cin, temp);
						if (temp == "Да") {
							for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
								if (student.getStudentName() == it->getStudentName()) {
									studs.erase(it);
									isReturn = true;
									break;
								}
							}
						}
					}
					DeleteConsole();
						break;
					case 0:
						system("cls");
						isReturn = true;
						cout << "Вы вернулись назад..." << endl;
						DeleteConsole();
						break;
					default:
						cout << "Такого варианта нет в списке!" << endl;
						DeleteConsole();
						break;
					}
				}
			}
		}
			break;
		case 3:
		{
			system("cls");
			cout << "Досвидания" << endl;
			student.deleteFile();
			int i = 0;
			for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
				it->writeStudents(i);
				i++;
			}
			return 0;
		}
			break;
		default:
			cout << "Такого варианта нет в списке!" << endl;
			DeleteConsole();
			break;
		}
	}
}