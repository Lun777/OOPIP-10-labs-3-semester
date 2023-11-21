#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <direct.h>
#include <locale>
#include <map>


using namespace std;
using namespace filesystem;

template <class T>
class Transaction;

class HistoryOfFiles;

void getFilesFromDirectory(vector<string>& files) {
	string extension = ".txt";
	directory_iterator iterator(current_path());
 	for (; iterator != end(iterator); iterator++)
	{
		if (iterator->path().extension() == extension)
		{
			files.push_back(iterator->path().filename().string());
		}
	}
}

template<class T>
struct Status {
	T* ptr;
	int counter;
};

class TextEditor {
	string name;
	fstream file;
	int count;
	vector<string> files;
	string currPath;
public:
	TextEditor(string name) {
		this->name = name;
		getFilesFromDirectory(files);
		count = files.size();
		currPath = "";
	}
	TextEditor() {
		name = "Блокнот";
		getFilesFromDirectory(files);
		count = files.size();
		currPath = "";
	}
	void openFile(string path) {
		if (file.is_open()) {
			cout << "Ошибка доступа! Уже открыт другой файл" << endl;
			return;
		}
		for (int i = 0; i < count; i++) {
			if (files[i] == path) {
				file.open(path, ios::in | ios::app);
				cout << "Файл \"" << path << "\"" << " успешно открыт!" << endl;
				currPath = path;
			}
		}
		if (!file) {
			cout << "Файл \"" << path << "\" не найден" << endl;
		}
	}
	void closeFile() {
		if (file) {
			file.close();
			cout << "Файл успешно закрыт!" << endl;
			currPath = "";
		}
		else {
			cout << "Ошибка закрытия файла" << endl;
		}
	};
	void setTextEditorName(string name) {
		this->name = name;
	}
	void addFile(string fileName, vector<string>& arr, HistoryOfFiles& his);
	string getTextEditorName() {
		return name;
	}
	vector<string> getFilesName() {
		return files;
	}
	string getCurrPath() {
		return currPath;
	}
	int getCountOfFiles() {
		return count;
	}
	fstream& getFilePointer() {
		return file;
	}
	~TextEditor() {
		if (file.is_open()) {
			file.close();
		}
		files.clear();
		files.shrink_to_fit();
	}
};

class File {
	string data;
	string name;
public:
	File() {
		data = "";
		name = "Unknown";
	}
	File(string data, string name) {
		this->data = data;
		this->name = name;
	}
	void setData(TextEditor &note) {
		fstream &temp = note.getFilePointer();
		temp.seekg(0, ios::beg);
		if (!temp.is_open()) {
			cout << "Файл не открыт! Данные не могут быть считаны" << endl;
		}
		else {
			data = "";
			string temp_str;
			while (!temp.eof()) {
				getline(temp, temp_str);
				data += temp_str;
				if (!temp.eof()) {
					data += '\n';
				}
			}
		}
	}
	void setFileName(TextEditor &note) {
		fstream& temp = note.getFilePointer();
		if (!temp.is_open()) {
			cout << "Файл не открыт!" << endl;
		}
		else {
			name = note.getCurrPath();
		}
	}
	string getData() {
		if (data == "") {
			cout << "Файл пуст или не открыт!" << endl;
		}
		return data;
	}
	string getName() {
		return name;
	}
};

class HistoryOfFiles {
	map<string, int> filesAndCount;
	fstream file;
public:
	HistoryOfFiles() {
		file.open("FilesHistory.txt", ios::in);
		string temp1;
		string temp2;
		while (!file.eof()) {
			getline(file, temp1);
			getline(file, temp2);
			filesAndCount[temp1] = stoi(temp2);
		}
	}
	HistoryOfFiles(TextEditor& note) {
		vector<string> temp = note.getFilesName();
		for (int i = 0; i < note.getCountOfFiles(); i++) {
			filesAndCount[temp[i]] = 0;
		}
		file.open("FilesHistory.txt", ios::in);
		string temp1;
		string temp2;
		if (file.eof()) {
			
		}
		while (!file.eof()) {
			if (!getline(file, temp1)) {
				break;
			}
			getline(file, temp2);
			filesAndCount[temp1] = stoi(temp2);
		}
	}
	void printHistoryOfFiles() {
		map<string, int>::iterator it;
		for (it = filesAndCount.begin(); it != filesAndCount.end(); ++it)
			cout << it->first << " " << it->second << '\n';
	}
	map<string, int> getFilesAndCount() {
		return filesAndCount;
	}
	void increaseCounter(string FileName) {
		filesAndCount[FileName]++;
	}
	void addFileInHistory(string fileName) {
		filesAndCount[fileName] = 0;
	}
	~HistoryOfFiles() {
		file.close();
		file.open("FilesHistory.txt", ios::out);
		for (auto it = filesAndCount.begin(); it != filesAndCount.end(); ++it) {
			if (!(it == filesAndCount.begin())) {
				file << endl;
			}
			file << it->first << endl << it->second;
		}
	}
};

void TextEditor::addFile(string fileName, vector<string>& arr, HistoryOfFiles& his) {
	if (path(fileName).extension() == ".txt") {
		for (int i = 0; i < count; i++) {
			if (files[i] == fileName) {
				cout << "Файл с таким именем уже существует!" << endl;
				return;
			}
		}
		fstream temp;
		temp.open(fileName, 'w');
		temp.close();
		files.push_back(fileName);
		arr.push_back(fileName);
		his.addFileInHistory(fileName);
		count++;
		cout << "Файл \"" << fileName << "\"" << "успешно добавлен!" << endl;
	}
	else {
		cout << "Не удалось создать файл..." << endl;
	}
}

class FileManager {
	string buff;
	string data;
public:
	FileManager(string data) {
		data += '\n';
		buff = data;
	}
	FileManager() {
		data = "";
		buff = "";
	}
	void addDataToBuff(string data) {
		buff += data;
	}
	string getBuff() {
		return buff;
	}
	void setBuffEqualsToZero() {
		buff = "";
	}
	void appendDataToFile(TextEditor& note, HistoryOfFiles& his) {
		fstream& temp = note.getFilePointer();
		temp.clear();
		temp.seekg(0, ios::end);
		/*temp.close();
		temp.open(note.getCurrPath(), ios::in | ios::app);*/
		if (!temp.is_open()) {
			cout << "Файл закрыт!" << endl;
			return;
		}
		else {
			temp << buff;
			buff = "";
			/*temp.close();*/
			his.increaseCounter(note.getCurrPath());
		}
	}
	void showFileData(TextEditor& note) {
		fstream& temp = note.getFilePointer();
		temp.clear();
		temp.seekg(0, ios::beg);
		string temp_str = "";
		while (!temp.eof()) {
			getline(temp, temp_str);
			cout << temp_str << endl;
		}
		cout << "Конец файла!" << endl;
	}
};

class AutoSaveManager {
	string time;
public:
	AutoSaveManager() {
		time = 3;
	}
	AutoSaveManager(string time) {
		this->time = time;
	}
	void setTime(string time) {
		this->time = time;
	}
	string getTime() {
		return time;
	}
};

enum State {begin, middle};

template <class T>
class Transaction {
	T* currState;
	T* prevState;
public:
	Transaction() : prevState(NULL), currState(new T) {}
	Transaction(const Transaction& obj) : currState(new T(*(obj.currState))), prevState(new T(*(obj.prevState))) {}
	~Transaction() {
		delete prevState;
		delete currState;
	}
	Transaction& operator=(const Transaction& obj) {
		if (this != &obj) {
			delete currState;
			delete prevState;
			currState = new T(*(obj.currState));
			prevState = new T(*(obj.prevState));
		}
		return *this;
	}
	void showState(State state) {
		cout << "Состояние объекта ";
		if (!state) cout << "до начала транзакции" << endl;
		else cout << "после начала транзакции" << endl;
		if (prevState) cout << "prevState = " << prevState->getBuff() << endl;
		else cout << "prevState = NULL" << endl;
		cout << "currState = " << currState->getBuff() << endl;
	}
	int beginTransactions(string data) {
		delete prevState;
		prevState = currState;
		currState = new T(*prevState);
		if (!currState) return 0;
		currState->addDataToBuff(data);
		return 1;
	}
	void commit() {
		delete prevState;
		prevState = NULL;
	}
	void deleteTransactions() {
		if (prevState) {
			T* temp = currState;
			currState = prevState;
			prevState = temp;
			temp = NULL;
		}
	}
	T* operator->() { 
		return currState;
	}
};

template<class T>
class SmartPtr {
	Status<T>* smartPtr;
public:
	SmartPtr(T* ptr) {
		if (!ptr) {
			smartPtr = NULL;
		}
		else {
			smartPtr = new Status<T>();
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;
		}
	}
	SmartPtr(const SmartPtr& obj) : smartPtr(obj.smartPtr) {
		if (smartPtr) {
			smartPtr->counter++;
		}
	}
	~SmartPtr() {
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter == 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPtr& operator=(const SmartPtr& obj) {
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter == 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
		smartPtr = obj.smartPtr;
		if (smartPtr) smartPtr->counter++;
		return *this;
	}
	T* operator->() const {
		if (smartPtr) return smartPtr->ptr;
		else return NULL;
	}
	void ShowCounter() {
		cout << "Значение счетчика для объекта " << smartPtr << " равно: " << smartPtr->counter << endl;
	}
};

