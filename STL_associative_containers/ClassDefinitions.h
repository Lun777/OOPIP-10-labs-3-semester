#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <array>
#include <list>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>

using namespace std;

void DeleteConsole() {
	cout << "Введите любой символ чтобы продолжить..." << endl;
	cin.get();
	system("cls");
}

int InputOfPositiveNum() {
	int num;
	cin.unsetf(ios::skipws);
	cin >> num;
	while (cin.bad() || cin.peek() != '\n' || num < 0) {
		cout << "Нужно ввести целое неотрицательное число! Повторите ввод:" << endl;
		cin.clear();
		cin.ignore(10, '\n');
		cin >> num;
	}
	cin.setf(ios::skipws);
	cin.get();
	return num;
}

class Student {
	string fullName;
	int group;
	int testResult;
public:
	Student() {
		fullName = "None";
		group = 0;
		testResult = 0;
	}
	Student(string name, int group, int result) {
		fullName = name;
		this->group = group;
		testResult = result;
	}
	void setStudentData(string name, int group, int result) {
		fullName = name;
		this->group = group;
		testResult = result;
	}
	string getStudentName() {
		return fullName;
	}
	unsigned int getStudentGroup() {
		return group;
	}
	int getStudentResult() {
		return testResult;
	}
	bool fillStudents(int num) {
		ifstream file;
		string temp;
		file.open("Students.txt");
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(1);
		}
		for (int i = 0; i < num; i++) {
			getline(file, temp);
		}
		if (file.eof()) {
			return false;
		}
		getline(file, temp, ',');
		fullName = temp;
		file.seekg(ios::cur, 1);
		getline(file, temp, ',');
		group = stoi(temp);
		file.seekg(ios::cur, 1);
		getline(file, temp, '.');
		testResult = stoi(temp);
		file.close();
		return true;
	}
	void deleteFile() {
		ofstream file;
		file.open("Students.txt");
		file.close();
	}
	void writeStudents(int num) {
		ofstream file;
		file.open("Students.txt", ios::app);
		if (!file.is_open()) {
			cout << "Не удалось открыть файл" << endl;
			exit(1);
		}
		if (num != 0) {
			file << '\n';
		}
		file << fullName << ", " << group << ", " << testResult << ".";
		file.close();
	}
	bool UserAuthorization(string name) {
		if (fullName == name) {
			return true;
		}
	}
	friend bool operator<(const Student& stud1, const Student& stud2) {
		return stud1.testResult < stud2.testResult;
	}
	friend bool operator>(const Student& stud1, const Student& stud2) {
		return stud1.testResult > stud2.testResult;
	}
	friend bool operator==(const Student& stud1, const Student& stud2) {
		return stud1.testResult == stud2.testResult;
	}
	friend bool operator!=(const Student& stud1, const Student& stud2) {
		return stud1.testResult != stud2.testResult;
	}
	Student& operator=(const Student& stud) {
		if (this == &stud) {
			return *this;
		}
		fullName = stud.fullName;
		group = stud.group;
		testResult = stud.testResult;
		return *this;
	}
};

class Task {
	string question;
	array<string, 4> answers;
	int correctAnswer;
public:
	Task() {
		question = "None";
		correctAnswer = -1;
	}
	Task(string question, array<string, 4>& answers, int correctAnswer) {
		this->question = question;
		this->answers = answers;
		this->correctAnswer = correctAnswer;
	}
	void setTaskData(string question, array<string, 4>& answers, int correctAnswer) {
		this->question = question;
		this->answers = answers;
		this->correctAnswer = correctAnswer;
	}
	string getQuestion() {
		return question;
	}
	array<string, 4> getAnswers() {
		return answers;
	}
	int getCorrectAnswer() {
		return correctAnswer;
	}
	void printQuestion() {
		cout << question << endl;
	}
	void printAnswers() {
		for (int i = 0; i < 4; i++) {
			cout << answers[i] << endl;
		}
	}
	void printCorrAnswer() {
		cout << correctAnswer << endl;
	}
	void printData() {
		cout << question << endl;
		for (int i = 0; i < 4; i++) {
			cout << answers[i] << endl;
		}
		cout << correctAnswer << endl;
	}
};

class ExamTicket {
	string name;
	vector<Task> tasks;
public:
	ExamTicket() {
		name = "Билет по программированию";
	}
	ExamTicket(vector<Task>& tasks) {
		name = "Билет по программированию";
		this->tasks = tasks;
	}
	void setData(string name, vector<Task>& tasks) {
		this->name = name;
		this->tasks = tasks;
	}
	string getExamTicketName() {
		return name;
	}
	vector<Task> getTasks() {
		return tasks;
	}
	void fillTasks() {
		ifstream file;
		Task temp;
		file.open("Test.txt");
		if (!file.is_open()) {
			cout << "Ошибка открытия файла" << endl;
			exit(1);
		}
		while (!file.eof()) {
			string temp1;
			array<string, 4> temp2;
			string temp3;
			getline(file, temp1);
			for (int i = 0; i < 4; i++) {
				getline(file, temp2[i]);
			}
			getline(file, temp3);
			temp.setTaskData(temp1, temp2, stoi(temp3));
			tasks.push_back(temp);
		}
		file.close();
	}
	void printTask(int num) {
		if (num < 1 && num > 10) {
			cout << "Задания с таким номером не существует" << endl;
		}
		else {
			tasks[num].printQuestion();
			tasks[num].printAnswers();
		}
	}
	int getCorrAns(int num) {
		if (num < 1 && num > 10) {
			cout << "Задания с таким номером не существует" << endl;
		}
		else {
			return tasks[num].getCorrectAnswer();
		}
	}
	void printTicket() {
		for (int i = 0, n = tasks.size(); i < n; i++) {
			tasks[i].printData();
			cout << endl;
		}
	}
};