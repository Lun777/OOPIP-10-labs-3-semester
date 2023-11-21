#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);
	/*cout << true << endl;*/
	cout.setf(ios::showpos);
	cout.setf(ios::internal);
	cout.setf(ios::right);
	/*cout << true << endl;
	for (int i = 0; i < 10; i++) {
		cout.width(70);
		cout << "Скажи-ка дядя, ведь недаром" << endl;
	}*/
	/*cout << - 123 << endl;
	int num = InputOfDouble();*/
	vector<Good> goods;
	Good good;
	Order order;
	/*order.addGoodToBasket(good);
	order.deleteBasket();*/
	order.FillGoodsVect(good);
	goods = order.getBasket();
	for (int i = 0; i < order.getCountOfGoods(); i++) {
		cout << goods[i].getName() << endl;
	}
	order.printTableGoods();
	while (true) {
		cout << "Какое действие хотите выбрать?" << endl;
		cout << "1. Просмотр корзины товаров." << endl;
		cout << "2. Добавление товара в корзину." << endl;
		cout << "3. Удаление товара из корзины." << endl;
		cout << "4. Изменение параметров товара" << endl;
		cout << "0. Выход из программы." << endl << endl;
		cout << "Ваш выбор: ";
		int choice = InputOfPositiveNum();
		switch (choice) {
		case 1:
			system("cls");
			{
				int choice;
				do {
					order.printTableGoods();
					cout << "\n\n";
					cout << "Выберите действие" << endl;
					cout << "1. Сортировка по параметру." << endl;
					cout << "2. Поиск по параметру." << endl;
					cout << "0. Вернуться назад." << endl << endl;
					cout << "Ваш выбор: ";
					choice = InputOfPositiveNum();
					switch (choice) {
					case 1:
						{
							int choice;
							do {
								system("cls");
								cout << "Выберите параметр сортировки" << endl;
								cout << "1. По названию" << endl;
								cout << "2. По количеству" << endl;
								cout << "3. По цене" << endl;
								cout << "0. Вернуться назад." << endl << endl;
								cout << "Ваш выбор: ";
								choice = InputOfPositiveNum();
								switch (choice) {
								case 1:
									for (int i = 0; i < goods.size(); i++) {
										for (int j = 0; j < goods.size() - 1 - i; j++) {
											if (goods[j].getName() > goods[j + 1].getName()) {
												swap(goods[j], goods[j + 1]);
											}
										}
									}
									order.setBasketGoods(goods, goods.size());
									break;
								case 2:
									for (int i = 0; i < goods.size(); i++) {
										for (int j = 0; j < goods.size() - 1 - i; j++) {
											if (goods[j].getCount() < goods[j + 1].getCount()) {
												swap(goods[j], goods[j + 1]);
											}
										}
									}
									order.setBasketGoods(goods, goods.size());
									break;
								case 3:
									for (int i = 0; i < goods.size(); i++) {
										for (int j = 0; j < goods.size() - 1 - i; j++) {
											if (goods[j].getPrice() < goods[j + 1].getPrice()) {
												swap(goods[j], goods[j + 1]);
											}
										}
									}
									order.setBasketGoods(goods, goods.size());
									break;
								case 0:
									cout << "Вы вернулись назад..." << endl;
									DeleteConsole();
									break;
								default:
									cout << "Вы ввели некорректного значения! Пожалуйста повторите ввод...";
									DeleteConsole();
									break;
								}
							} while (choice != 0);
						}
						break;
					case 2:
						{
							int choice;
							do {
								cout << "Выберите параметр поиска" << endl;
								cout << "1. По названию" << endl;
								cout << "2. По количеству" << endl;
								cout << "3. По цене" << endl;
								cout << "0. Вернуться назад." << endl << endl;
								cout << "Ваш выбор: ";
								choice = InputOfPositiveNum();
								switch (choice) {
								case 1:
									goodSearchByName(goods);
									DeleteConsole();
									break;
								case 2:
									goodSearchByCount(goods);
									DeleteConsole();
									break;
								case 3:
									goodSearchByPrice(goods);
									DeleteConsole();
									break;
								case 0:
									cout << "Вы вернулись назад..." << endl;
									DeleteConsole();
									break;
								default:
									cout << "Вы ввели некорректного значения! Пожалуйста повторите ввод...";
									DeleteConsole();
									break;
								}
							} while (choice != 0);
						}
						break;
					case 0:
						cout << "Вы вернулись назад..." << endl;
						DeleteConsole();
						break;
					default:
						cout << "Вы ввели некорректного значения! Пожалуйста повторите ввод...";
						DeleteConsole();
						break;
					}
				} while (choice != 0);
			}
			break;
		case 2:
		{
			system("cls");
			Good temp;
			string name;
			int count;
			double price;
			cout << "Введите название товара" << endl;
			getline(cin, name);
			cout << "Введите количество данного товара" << endl;
			count = InputOfPositiveNum();
			cout << "Введите цену данного товара" << endl;
			price = InputOfDouble();
			DeleteConsole();
			temp.setName(name);
			temp.setCount(count);
			temp.setPrice(price);
			order.addGoodToBasket(temp);
			goods.push_back(temp);
		}
		break;
		case 3:
		{
			system("cls");
			string name;
			cout << "Введите название товара, который хотите удалить" << endl;
			getline(cin, name);
			for (int i = 0; i < order.getCountOfGoods(); i++) {
				if (name == goods[i].getName()) {
					goods.erase(goods.begin() + i);
					order.deleteGoodFromBasket(i);
					i--;
				}
			}
			DeleteConsole();
		}
		break;
		case 4:
		{
			system("cls");
			cout << "Введите индекс товара, который хотите изменить: ";
			int index = InputOfPositiveNum();
			goods = order.editGood(index);
		}
			break;
		case 0:
			cout << endl << "Досвидания!" << endl;
			order.WriteGoodsToFile();
			return 0;
			break;
		default:
			cout << "Вы ввели некорректного значения! Пожалуйста повторите ввод...";
			DeleteConsole();
			break;
		}
	}
}

//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Good good;
//	int ch = 1;
//	string name;
//	int count;
//	double price;
//	ofstream file;
//	//file.open("BasketHistory.txt", ios::out);
//	//file.close();
//	file.open("BasketHistory.txt", ios::trunc | ios::binary);
//	while (ch == 1) {
//		cout << "Enter data:" << endl;
//		cout << "Good name: ";
//		getline(cin, name);
//		cout << "Good count: ";
//		count = InputOfPositiveNum();
//		cout << "Good price: ";
//		price = InputOfPositiveNum();
//		/*good.setYourData(name, count, price);*/
//		good.setName(name);
//		good.setCount(count);
//		good.setPrice(price);
//		file.write((char*)&good, sizeof(good));
//		ch = InputOfPositiveNum();
//	}
//	file.close();
//	ifstream file1;
//	file1.open("BasketHistory.txt", ios::in | ios::binary);
//	if (!file1.is_open()) {
//		cout << "Ошибка открытия файла!" << endl;
//		return 1; // или какой-то другой код ошибки
//	}
//	file1.seekg(0, ios::end);
//	cout << sizeof(Good) << endl;
//	int endpos = file1.tellg();
//	if (endpos == -1) {
//		cout << "Ошибка получения позиции в конце файла!" << endl;
//		return 1; // или какой-то другой код ошибки
//	}
//	cout << endpos << endl;
//	int n = endpos / sizeof(Good);
//	cout << n << endl;
//	Order order;
//	order.FillGoodsVect(good);
//	order.printTableGoods();
//}