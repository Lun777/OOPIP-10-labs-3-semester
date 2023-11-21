#include "ClassDefinitions.h"

template<typename T>
void printQueue(T& queue) {
	while (!queue.empty()) {
		cout << queue.top() << " ";
		queue.pop();
	}
	cout << '\n';
}

template<typename T>
void printReverseQueue(T& queue) {
	T temp;
	while (!queue.empty()) {
		temp.push(queue.top());
		queue.pop();
	}
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
}

class CompareResults {
public:
	bool operator()(Student& s1, Student& s2) {
		if (s1.getStudentResult() < s2.getStudentResult()) return true;
		return false;
	}
};

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
	set<string> names;
	for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
		names.insert(it->getStudentName());
	}
	while (true) {
		int choice;
		cout << "Выберите пункт меню:" << endl;
		cout << "1. Регистрация" << endl;
		cout << "2. Авторизация" << endl;
		cout << "3. Работа с адаптерами" << endl;
		cout << "0. Выход" << endl << endl;
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
				names.insert(student.getStudentName());
				if (studs.size() != names.size()) {
					cout << "Пользователь с таким именем уже существует!" << endl;
					studs.erase(--studs.end());
				}
				else {
					cout << "Вы успешно зарегистрировались!" << endl;
				}
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
						cout << "5. Посмотреть количество студентов сдавших на определённую оценку" << endl;
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
										for (set<string>::iterator it1 = names.begin(); it1 != names.end(); it++) {
											if (*it1 == student.getStudentName()) {
												names.erase(it1);
												names.insert(it1, temp);
												break;
											}
										}
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
										names.erase(student.getStudentName());
										studs.erase(it);
										isReturn = true;
										break;
									}
								}
							}
						}
						DeleteConsole();
						break;
						case 5:
						{
							bool isReturn = false;
							while (true) {
								if (isReturn) {
									break;
								}
								map<int, int> marks;
								for (int i = 0; i <= 10; i++) {
									marks[i] = 0;
								}
								for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
									marks[it->getStudentResult()]++;
								}
								cout << setw(30) << "Результат теста" << setw(60) << "Количество людей сдавших на данную отметку" << endl << endl;
								for (int i = 0; i <= 10; i++) {
									cout << setw(21) << i << setw(50) << marks[i] << endl;
								}
								cout << endl << endl << endl;
								int choice;
								cout << "Выберите пункт меню:" << endl;
								cout << "1. ФИО студентов сдавших на 0" << endl;
								cout << "2. ФИО студентов сдавших на 1" << endl;
								cout << "3. ФИО студентов сдавших на 2" << endl;
								cout << "4. ФИО студентов сдавших на 3" << endl;
								cout << "5. ФИО студентов сдавших на 4" << endl;
								cout << "6. ФИО студентов сдавших на 5" << endl;
								cout << "7. ФИО студентов сдавших на 6" << endl;
								cout << "8. ФИО студентов сдавших на 7" << endl;
								cout << "9. ФИО студентов сдавших на 8" << endl;
								cout << "10. ФИО студентов сдавших на 9" << endl;
								cout << "11. ФИО студентов сдавших на 10" << endl;
								cout << "0. Вернуться назад" << endl << endl;
								cout << "Ваш выбор: ";
								choice = InputOfPositiveNum();
								switch (choice) {
								case 1:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 0" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 0) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 2:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 1" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 1) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 3:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 2" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 2) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 4:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 3" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 3) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 5:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 4" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 4) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 6:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 5" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 5) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 7:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 6" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 6) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 8:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 7" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 7) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 9:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 8" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 8) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 10:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 9" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 9) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
									DeleteConsole();
									break;
								case 11:
									system("cls");
									cout << setw(70) << "Студенты получившие оценку 10" << endl << endl;
									for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
										if (it->getStudentResult() == 10) {
											cout << setw(65) << it->getStudentName() << endl;
										}
									}
									cout << endl;
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
			system("cls");
			{
				bool isReturn = false;
				while (true) {
					if (isReturn) {
						break;
					}
					int choice;
					cout << "Выберите пункт меню: " << endl;
					cout << "1. Работа со stack" << endl;
					cout << "2. Работа с queue и priority_queue" << endl;
					cout << "0. Вернуться назад" << endl << endl;
					cout << "Ваш выбор: ";
					choice = InputOfPositiveNum();
					switch (choice) {
					case 1:
						system("cls");
						{
							stack<Student, list<Student>> users(studs);
							cout << "Размер стека равен = " << users.size() << endl << endl;
							Student temp("Иванов Андрей Степанович", 273602, 0);
							cout << "Добавим студента – " << temp.getStudentName() << endl << endl;
							users.push(temp);
							cout << "Размер стека после добавления пользователя = " << users.size() << endl << endl;
							cout << "Вывод имён пользователей:" << endl << endl;
							while (!users.empty()) {
								cout << users.top().getStudentName() << endl;
								users.pop();
							}
							cout << endl;
						}
						DeleteConsole();
						break;
					case 2:
						system("cls");
						{
							queue<Student, list<Student>> users1(studs);
							priority_queue<Student, vector<Student>, CompareResults> users2;
							for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
								users2.push(*it);
							}
							cout << "Размер очереди = " << users1.size() << endl;
							cout << "Размер приоритетной очереди = " << users2.size() << endl << endl;
							cout << "Студент стоящий первый в очереди:" << endl;
							cout << users1.front().getStudentName() << "    " << users1.front().getStudentGroup() << "    " << users1.front().getStudentResult() << endl << endl;
							cout << "Студент стоящий в конце очереди:" << endl;
							cout << users1.back().getStudentName() << "    " << users1.back().getStudentGroup() << "    " << users1.back().getStudentResult() << endl << endl;
							Student temp = users2.top();
							cout << "Студент с первый в очереди по наилучшему результату:" << endl;
							cout << temp.getStudentName() << "    " << temp.getStudentGroup() << "    " << temp.getStudentResult() << endl << endl;
							cout << "Вывод информации о студентах в очереди:" << endl << endl;
							while (!users1.empty()) {
								cout << users1.front().getStudentName() << "    " << users1.front().getStudentGroup() << "    " << users1.front().getStudentResult() << endl;
								users1.pop();
							}
							cout << endl;
							cout << "Вывод информации о студентах в приоритетной очереди:" << endl << endl;
							while (!users2.empty()) {
								temp = users2.top();
								cout << temp.getStudentName() << "    " << temp.getStudentGroup() << "    " << temp.getStudentResult() << endl;
								users2.pop();
							}
							cout << endl;
						}
						DeleteConsole();
						break;
					case 3:
						system("cls");
						{
							cout << "Создадим два массива размером n = 10 типа int (неотрицательные) и заполним значениями.\nЗатем создадим множество." << endl;
							array<int, 10> arr1;
							array<int, 10> arr2;
							set<int> unicArr;
							cout << "Благодаря этому контейнеру найдём объединение двух массивов" << endl;
							bool isBack = false;
							cin.get();
							while (true) {
								system("cls");
								if (isBack) {
									break;
								}
								cout << "Заполните 1-ый массив" << endl;
								for (int i = 0; i < 10; i++) {
									arr1[i] = InputOfPositiveNum();
								}
								cout << "Заполните 2-ой массив" << endl;
								for (int i = 0; i < 10; i++) {
									arr2[i] = InputOfPositiveNum();
								}
								cout << "Значения массивов:" << endl;
								for (int i = 0; i < 10; i++) {
									cout << arr1[i];
									if (i != 9) {
										cout << " ";
									}
									else {
										cout << endl;
									}
								}
								for (int i = 0; i < 10; i++) {
									cout << arr2[i];
									if (i != 9) {
										cout << " ";
									}
									else {
										cout << endl << endl;
									}
								}
								for (int i = 0; i < 10; i++) {
									unicArr.insert(arr1[i]);
									unicArr.insert(arr2[i]);
								}
								cout << "Значения множества:" << endl;
								for (set<int>::iterator it = unicArr.begin(); it != unicArr.end(); it++) {
									cout << *it << " ";
								}
								cout << endl << endl;
								cout << "Желаете продолжить?" << endl;
								cout << "1. Да" << endl;
								cout << "0. Нет" << endl << endl;
								cout << "Ваш выбор: ";
								int choice;
								while (true) {
									choice = InputOfPositiveNum();
									if (choice == 1) {
										system("cls");
										unicArr.clear();
										break;
									}
									else if (choice == 0) {
										isBack = true;
										break;
									}
									else {
										cout << "Такого варианта не существует!" << endl;
									}
								}
							}
						}
						DeleteConsole();
						break;
					case 4:
						system("cls");
						{
							cout << "Создадим set и multiset и добавим в них целочисленные значения: 1, 2, 3, 4, 5, 1, 5, 5, 5, 5." << endl;
							cout << "set" << endl;
							set<int> s1;
							multiset<int> s2;
							s1.insert(1);
							s1.insert(2);
							s1.insert(3);
							s1.insert(4);
							s1.insert(5);
							s1.insert(1);
							s1.insert(5);
							s1.insert(5);
							s1.insert(5);
							s1.insert(5);
							for (set<int>::const_iterator pos = s1.begin(); pos != s1.end(); ++pos)
								cout << *pos << " ";
							cout << endl << endl;
							cout << "multiset" << endl;
							s2.insert(1);
							s2.insert(2);
							s2.insert(3);
							s2.insert(4);
							s2.insert(5);
							s2.insert(1);
							s2.insert(5);
							s2.insert(5);
							s2.insert(5);
							s2.insert(5);
							for (multiset<int>::const_iterator pos = s2.begin(); pos != s2.end(); ++pos)
								cout << *pos << " ";
							cout << endl << endl;
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
			break;
		case 0:
		{
			system("cls");
			cout << "Досвидания" << endl;
			student.deleteFile();
			int i = 0;
			for (list<Student>::iterator it = studs.begin(); it != studs.end(); it++) {
				it->writeStudents(i);
				i++;
			}
			studs.clear();
			names.clear();
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