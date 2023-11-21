#include "Header.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TextEditor Note("TextEditor");
	vector<string> Files = Note.getFilesName();
	for (int i = 0; i < Files.size(); i++) {
		cout << Files[i] << endl;
	}
	/*Note.openFileToRead(Files[3]);
	fstream& temp = Note.getFilePointer();
	if (temp.is_open()) {
		cout << "Файл открыт!" << endl;
	}
	else {
		cout << "Файл закрыт!" << endl;
	}
	Note.closeFile();
	if (temp.is_open()) {
		cout << "Файл открыт!" << endl;
	}
	else {
		cout << "Файл закрыт!" << endl;
	}*/

	HistoryOfFiles his(Note);
	cout << Note.getTextEditorName() << endl;
	Note.addFile("Новый текстовый документ.txt", Files, his);
	Note.addFile("TestFile.txt", Files, his);
	cout << Note.getCountOfFiles() << endl;
	Note.openFile(Files[3]);
	Note.openFile(Files[1]);
	Note.closeFile();
	Note.setTextEditorName("Блокнот");
	cout << Note.getTextEditorName() << endl;
	File *temp = new File();
	Note.openFile(Files[3]);
	cout << Note.getCurrPath() << endl;
	cout << temp->getData() << endl;
	temp->setData(Note);
	cout << temp->getData() << endl << endl;
	FileManager Mng;
	Mng.addDataToBuff("lalalala");
	cout << Mng.getBuff() << endl;
	Mng.addDataToBuff("We are the champions!");
	cout << Mng.getBuff() << endl;
	Mng.showFileData(Note);
	Mng.appendDataToFile(Note, his);
	Mng.addDataToBuff("We are the champions!");
	Mng.appendDataToFile(Note, his);
	Mng.addDataToBuff("We are the champions!");
	Mng.appendDataToFile(Note, his);
	Mng.addDataToBuff("We are the champions!");
	Mng.appendDataToFile(Note, his);
	cout << Mng.getBuff() << endl << endl;
	Mng.showFileData(Note);
	Mng.addDataToBuff("kfdaslfkdl");
	cout << Mng.getBuff() << endl << endl;
	Mng.setBuffEqualsToZero();
	cout << Mng.getBuff() << endl << endl;
	Transaction<FileManager> firstAccount;
	firstAccount->addDataToBuff("first try to add a data...");
	firstAccount.showState(State::begin);
	cout << "НАЧАЛЬНАЯ ИНИЦИАЛИЗАЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << "--------------------------------------------------"
		<< endl;
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ НАЧАТА СО ЗНАЧЕНИЕМ 10" << endl;
	if (firstAccount.beginTransactions("second try to add a data...")) {
		firstAccount.showState(State::middle);
	}
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ ПРОШЛА УСПЕШНО" << endl;
	cout << endl;
	cout << "--------------------------------------------------"
		<< endl;
	firstAccount.deleteTransactions();
	firstAccount.showState(State::middle);
	cout << "ПЕРВАЯ ТРАНЗАКЦИЯ БЫЛА ОТМЕНЕНА" << endl;
	firstAccount.commit();
	firstAccount.showState(State::middle);
	cout << "--------------------------------------------------"
		<< endl;
	cout << "ВТОРАЯ ТРАНЗАКЦИЯ НАЧАТА CO ЗНАЧЕНИЕМ 2" << endl;
	if (firstAccount.beginTransactions("Third try to add a data...")) {
		firstAccount.showState(State::begin);
		firstAccount.commit();
	}
	cout << "ВТОРАЯ ТРАНЗАКЦИЯ ПРОШЛА УСПЕШНО" << endl;
	firstAccount.showState(State::middle);
	his.printHistoryOfFiles();
	SmartPtr<File> pointer(temp);
	pointer.ShowCounter();
	File *secondFile = temp;
	pointer.ShowCounter();
	SmartPtr<File> secondPointer = pointer;
	secondPointer.ShowCounter();
	pointer.ShowCounter();
	pointer = NULL;
	secondPointer.ShowCounter();
	cout << temp->getData() << endl;
	secondPointer = NULL;
	/*cout << temp->getData() << endl;*/
	pointer.ShowCounter();
}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
//
//template <typename T>
//class MySmartPtr {
//public:
//    MySmartPtr() : ptr(nullptr), refCount(nullptr) {}
//
//    MySmartPtr(T* p) : ptr(p), refCount(new size_t(1)) {}
//
//    MySmartPtr(const MySmartPtr<T>& other) : ptr(other.ptr), refCount(other.refCount) {
//        if (refCount) {
//            (*refCount)++;
//        }
//    }
//
//    ~MySmartPtr() {
//        Release();
//    }
//
//    MySmartPtr& operator=(const MySmartPtr<T>& other) {
//        if (this != &other) {
//            Release();
//            ptr = other.ptr;
//            refCount = other.refCount;
//            if (refCount) {
//                (*refCount)++;
//            }
//        }
//        return *this;
//    }
//
//    T* Get() const {
//        return ptr;
//    }
//
//    size_t UseCount() const {
//        return (refCount ? *refCount : 0);
//    }
//
//    operator bool() const {
//        return ptr != nullptr;
//    }
//
//    T& operator*() const {
//        if (ptr) {
//            return *ptr;
//        }
//    }
//
//    T* operator->() const {
//        if (ptr) {
//            return ptr;
//        }
//    }
//
//private:
//    void Release() {
//        if (refCount) {
//            (*refCount)--;
//            if (*refCount == 0) {
//                delete ptr;
//                delete refCount;
//            }
//        }
//    }
//
//    T* ptr;
//    size_t* refCount;
//};
//
//class Transaction {
//public:
//    Transaction() : committed(false) {}
//
//    void Begin() {
//        committed = false;
//    }
//
//    void Commit() {
//        committed = true;
//    }
//
//    bool Committed() const {
//        return committed;
//    }
//
//    void Rollback() {
//        committed = false;
//    }
//
//private:
//    bool committed;
//};
//
//class Ticket {
//public:
//    Ticket() : price(0.0), quantity(0) {}
//
//    Ticket(const string& movie, double price, int quantity)
//        : movie(movie), price(price), quantity(quantity) {}
//
//    string GetMovie() const {
//        return movie;
//    }
//
//    void SetPrice(double price) {
//        this->price = price;
//    }
//
//    double GetPrice() const {
//        return price;
//    }
//
//    void SetQuantity(int quantity) {
//        this->quantity = quantity;
//    }
//
//    int GetQuantity() const {
//        return quantity;
//    }
//
//private:
//    string movie;
//    double price;
//    int quantity;
//};
//
//class CinemaHall {
//public:
//    CinemaHall() {}
//
//    void AddTicket(const MySmartPtr<Ticket>& ticket) {
//        ticketList.push_back(ticket);
//    }
//
//    void DisplayInfo() const {
//        cout << "Список билетов:\n";
//        cout << setw(20) << "Фильм" << setw(10) << "Цена" << setw(15) << "Количество" << endl;
//        for (const auto& ticket : ticketList) {
//            cout << setw(20) << ticket->GetMovie() << setw(10) << ticket->GetPrice() << setw(15) << ticket->GetQuantity() << endl;
//        }
//    }
//
//    void ShowSalesSummary() const {
//        double totalRevenue = 0.0;
//
//        cout << "\nОтчет о продажах:\n";
//        cout << setw(20) << "Фильм" << setw(10) << "Цена" << setw(15) << "Количество" << setw(15) << "Выручка" << endl;
//        for (const auto& ticket : ticketList) {
//            double revenue = ticket->GetPrice() * ticket->GetQuantity();
//            totalRevenue += revenue;
//            cout << setw(20) << ticket->GetMovie() << setw(10) << ticket->GetPrice() << setw(15) << ticket->GetQuantity() << setw(15) << revenue << endl;
//        }
//
//        cout << "\nИтоговая выручка: " << totalRevenue << endl;
//    }
//
//private:
//    vector<MySmartPtr<Ticket>> ticketList;
//};
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    CinemaHall cinemaHall;
//
//    while (true) {
//        cout << "Меню:\n";
//        cout << "1. Добавить билет\n";
//        cout << "2. Показать список билетов\n";
//        cout << "3. Показать отчет о продажах\n";
//        cout << "4. Выйти\n";
//        cout << "Выберите действие: ";
//
//        int choice;
//        cin >> choice;
//
//        if (choice == 1) {
//            string movie;
//            double price;
//            int quantity;
//
//            cout << "Введите название фильма: ";
//            cin.ignore();
//            getline(cin, movie);
//
//            while (true) {
//                cout << "Введите цену билета: ";
//                if (cin >> price) {
//                    break; // Ввод корректен, выходим из цикла
//                }
//                else {
//                    cout << "Ошибка: Неверный формат цены. Транзакция не выполнена. Данные не добавлены." << endl;
//                    cin.clear();
//                    cin.ignore(-1, '\n'); // Очищаем входной буфер
//                    return false;
//
//                }
//            }
//
//            while (true) {
//                cout << "Введите количество билетов: ";
//                if (cin >> quantity) {
//                    break;
//                }
//                else {
//                    cout << "Ошибка: Неверный формат количества. Транзакция не выполнена. Данные не добавлены." << endl;
//                    cin.clear();
//                    cin.ignore(-1, '\n'); // Очищаем входной буфер
//                    return false;
//                }
//            }
//
//            Transaction transaction;
//            transaction.Begin();
//
//            MySmartPtr<Ticket> ticket(new Ticket(movie, price, quantity));
//            cinemaHall.AddTicket(ticket);
//
//            transaction.Commit();
//
//            if (transaction.Committed()) {
//                cout << "Данные о билетах добавлены в кинозал.\n";
//            }
//            else {
//                cout << "Транзакция не выполнена. Данные не добавлены.\n";
//            }
//        }
//        else if (choice == 2) {
//            cout << "\nИнформация о кинозале:\n";
//            cinemaHall.DisplayInfo();
//        }
//        else if (choice == 3) {
//            cinemaHall.ShowSalesSummary();
//        }
//        else if (choice == 4) {
//            break;
//        }
//        else {
//            cout << "Неверный выбор. Попробуйте снова.\n";
//        }
//    }
//
//    return 0;
//}