#include "Header.h"

// просмотр (табличный), добавление, удаление, редактирование, сортировка, поиск

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);
	cout << true << endl;
	cout.setf(ios::showpos);
	cout.setf(ios::internal);
	cout.setf(ios::right);
	cout << true << endl;
	for (int i = 0; i < 10; i++) {
		cout.width(70);
		cout << "Скажи-ка дядя, ведь недаром" << endl;
	}
	/*cout << - 123 << endl;
	int num = InputOfDouble();*/
	vector<Good> goods;
	FillGoodsVect(goods);
	Order order;
	order.setBasketGoods(goods, goods.size());
	for (int i = 0; i < order.getCountOfGoods(); i++) {
		cout << goods[i].getName() << endl;
	}
	while (true) {
		cout << "Какое действие хотите выбрать?" << endl;
		cout << "1. Просмотр корзины товаров." << endl;
		cout << "2. Добавление товара в корзину." << endl;
		cout << "3. Удаление товара из корзины." << endl;
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
					system("cls");
				{
					int choice;
					do {
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
							DeleteConsole();
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
							DeleteConsole();
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
				case 2:
					system("cls");
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
		case 0:
			cout << endl << "Досвидания!" << endl;
			WriteGoodsToFile(order.getBasket());
			return 0;
			break;
		default:
			cout << "Вы ввели некорректного значения! Пожалуйста повторите ввод...";
			DeleteConsole();
			break;
		}
	}
}