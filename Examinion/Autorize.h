#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<iostream>
#include<string>
#include <vector>
#include <conio.h>
#include <fstream>
#include "MD5.h"
#include "func.h"
#include "Application.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
class userStudent{
	string login;
	string password;
	string FIO;
	string phone;
	string adress;
public:
	userStudent(){}
	userStudent(const string& login, const string& FIO, const string& adress, const string& phone) : login(login), FIO(FIO), adress(adress), phone(phone){}
	userStudent(const string& login, const string& password, const string& FIO, const string& phone, const string& adress) : login(login),password(password),FIO(FIO),phone(phone),adress(adress){}
	~userStudent() {}
	string getLogin() { return login; }
	string getPassword() { return password; }
	string getFIO() { return FIO; }
	string getPhone() { return phone; }
	string getAdress() { return adress; }
	void setLogin() { cin >> login; }
	void setPassword() { cin >> password; }
	void setFIO() { cin >> FIO; }
	void setPhone() { cin >> phone; }
	void setAdress() { cin >> adress; }
	void setLogin(string login1) { login = login1; }
	void setPass(string pass) { password = pass; }
	void clear() {
		login.clear();
		password.clear();
		FIO.clear();
		phone.clear();
		adress.clear();
	}
	friend ostream& operator <<(ostream& out, userStudent& obj){
	out << endl;
	out << "Логин: " << obj.getLogin() << endl;
	out << "ФИО: " << obj.getFIO() << endl;
	out << "Адресс проживания: " << obj.getAdress() << endl;
	out << "Номер телефона: " << obj.getPhone() << endl;
	return out;
	}
	
};
class userAdmin {
	string login;
	string password;
public:
	userAdmin() {}
	userAdmin(string login, string password) : login(login), password(password) {}
	~userAdmin() {}
	string getLogin() { return login; }
	string getPassword() { return password; }
	void setLogin() { cin >> login; }
	void setPassword() { cin >> password; }
	void setPass(string pass) { password = pass; }
	void setLogin(string log) { login = log; }
	void clear() {
		login.clear();
		password.clear();
	}
};
//что бь доавить нового ректора или ещё кого то создаёться новый класс с ним и потом меню для него.
vector<userAdmin> admins;
vector<userStudent> people;
string loginCorrect;
bool getCheckAdmin = false;
bool Logins()
{
	vector<char>vecPassword;
	char pas, c;
	bool cont = false, checkAdm = false;
	while (!cont) {
		cout << "Введите ваш логин:";
		string login, correctInfo;
		cin >> login;
		cout << "Введите пароль: ";
		while ((pas = _getch()) != '\r')
		{
			if (pas == 8 || pas == '\n') {
				
			}
			else {
				vecPassword.push_back(pas);
				_putch('*');
			}
		
		}
		string password_in(vecPassword.begin(), vecPassword.end());
		password_in = md5(password_in);
		cout << endl;
		ifstream correct;
		correct.open("LogsUsers.txt");
		while (!correct.eof()) {
			correct.get(c);
			correctInfo.push_back(c);
		}
		correct.close();
		int pos = correctInfo.find(password_in);
		int pos2 = correctInfo.find(login);
		checkAdm = chechAdmin(password_in, login);
		if (checkAdm == true) {
			getCheckAdmin = true;
			cont = true;
			return true;
			system("pause");
		}
		else {
			getCheckAdmin = false;
		}
		if (pos == -1 || pos2 == -1) {
			cout << "Неверный пароль, введите еще раз. " << endl;
			cont = false;
			return false;
			system("pause");
			system("cls");
		}
		else {
			cout << endl;
			cout << "Успешный вход!" << endl;

			loginCorrect = login;
			cont = true;
			return true;
			system("pause");
			system("cls");
		}
	}
	cout << "Такого логина не существует, введите заново:" << endl;
}
void Register()
{
	int countVec = 0;
	int q = 0;
	userStudent person;
	vector<char> vecPassword;
	char pas, c;
	string correctInfo, correctLogin;
	bool cont = false, busy = false;
	while (!cont) {
		system("cls");
		cout << "Регистарция студента. " << endl;
		cout << "Введите свой логин:";
		person.setLogin();
		ifstream correct;
		correct.open("LogsUsers.txt");
		while (!correct.eof()) {
			correct.get(c);
			correctInfo.push_back(c);
		}
		correctLogin = person.getLogin();
		correct.close();
		int pos = correctInfo.find(correctLogin);
		if (pos == -1) {
			cout << "Введите пароль: ";
			while ((pas = _getch()) != '\r')
			{
				if (pas == 8 || pas == '\n') {

				}
				else {
				vecPassword.push_back(pas);
				_putch('*');
			}
			}
			string password_in(vecPassword.begin(), vecPassword.end());
			cout << endl;
			cout << "Введите ваше ФИО:";
			person.setFIO();
			cout << "Введите ваш номер телефона:";
			person.setPhone();
			cout << "Введите свой адресс проживания: ";
			person.setAdress();
			if (password_in.length() > 3) {
				ofstream save;
				save.open("LogsUsers.txt", ios::app);
				password_in = md5(password_in);
				person.setPass(password_in);
				save << person.getLogin() << endl;
				save << person.getPassword() << endl;
				save.close();
				ofstream saveInfoAll;
				fs::path s("InfoUsers");
				fs::create_directory(s);
				string login = person.getLogin();
				string temp = ".txt";
				login += temp;
				string path = "InfoUsers//";
				path += login;
				saveInfoAll.open(path, ios::app);
				saveInfoAll << person.getLogin() << endl;
				saveInfoAll << person.getFIO() << endl;
				saveInfoAll << person.getAdress() << endl;
				saveInfoAll << person.getPhone() << endl;
				saveInfoAll.close();
				cout << "Зарегистрировано успешно!" << endl;
				person.setPass(password_in);
				people.push_back(person);
				cont = true;
			}
			else {
				cout << "Пароль сликом маленький, попробуйте снова." << endl;
				system("pause");
				person.clear();
				cont = false;
			}
		}
		else {
			cout << "Такой логин занят.  " << endl;
			system("pause");
			cont = false;
		}
	}

}
void Register_Admin()
{
	userAdmin person;
	vector<char> vecPassword;
	char pas;
	string pw1, pw2;
	bool cont = false, busy = false;
	while (!cont) {
		system("cls");
		cout << "Регистарция админа. " << endl;
		cout << "Введите свой логин:";
		person.setLogin();
		if (busy == false) {
			cout << "Введите пароль: ";
			while ((pas = _getch()) != '\r')
			{
				if (pas == 8 || pas == '\n') {

				}
				else {
					vecPassword.push_back(pas);
					_putch('*');
				}
			}
			string password_in(vecPassword.begin(), vecPassword.end());
			cout << endl;
			if (password_in.length() > 3) {
				ofstream save;
				save.open("LogsAdmin.txt", ios::app);
				password_in = md5(password_in);
				person.setPass(password_in);
				save << person.getLogin() << endl;
				save << person.getPassword() << endl;
				save.close();
				cout << "Зарегистрировано успешно!" << endl;
				person.setPass(password_in);
				admins.push_back(person);
				cont = true;
				cin.clear();
			}
			else {
				cout << "Пароль сликом маленький, попробуйте снова." << endl;
				system("pause");
				person.clear();
				cont = false;
			}
		}
	}
}


