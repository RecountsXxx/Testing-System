#pragma once
#include "Autorize.h"
#include "Testing.h"
#include <sstream>
#include <string>
namespace fs = std::experimental::filesystem;
using namespace std;
class MenuListAdmin{
public:
	void replaceLoginAdmin(string login);
	void replacePasswordAdmin(string password);
	void deleteUser(string findLogin, string findPassword);
	void renamePhone(string newPhone, string login);
	void renameAdress(string newAdress, string login);
	void renameFIO(string newFIO, string login);
	void renamePassword(string newPassword, string login, string password);
	void renameLogin(string newLogin, string login,string str);
	void addUser();
	int menu();
	string str;
};
int MenuListAdmin::menu()
{
	ifstream fin,two,three,four,five,six,seven,eight;
	char ch;
	int pos = 0;
	bool exitMenu = false;
	string  currentPassword, currentLogin, currentNew, loginFindStat,strOne,strTwo,strThree,strFour,str;
	char login_l[80], password_l[80];
	ifstream load;
	ifstream loadStat;
	load.open("LogsAdmin.txt");
	load.getline(login_l, 80, '\n');
	load.getline(password_l, 80, '\n');
	userAdmin adminsq(login_l, password_l);
	Test test;
	admins.push_back(adminsq);
	while (!load.eof()) {
		load.getline(login_l, 80, '\n');
		load.getline(password_l, 80, '\n');
		userAdmin adminsq(login_l, password_l);
		admins.push_back(adminsq);
	}
	load.close();
	adminsq.clear();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (!exitMenu) {
		system("cls");
		int c = Menu::select_vertical({
		"Сменить логин.",
		"Сменить пароль.",
		"Удалить пользователя. ",
		"Добавить пользователя. " ,
		"Сменить логин пользователю. ",
		"Сменить пароль пользователю. ",
		"Сменить ФИО пользователя. ",
		"Сменить адресс проживания пользователя. ",
		"Сменить номер телефона пользователя. ",
		"Добавить раздел. ",
		"Добавить тест. ",
		"Посмотреть статистику студентов.",
		"Выйти с личного кабинета." },
		HorizontalAlignment::Center, 12);
		switch (c) {
		case 0:
			system("cls");
			currentLogin.clear();
			cout << "Смена логина. " << endl;
			cout << "Введите новый логин: ";
			cin >> currentLogin;
			this->replaceLoginAdmin(currentLogin);
			system("pause");
			break;
		case 1:
			system("cls");
			currentNew.clear();
			cout << "Смена пароля. " << endl;
			cout << "Введите новый пароль: ";
			cin >> currentNew;
			this->replacePasswordAdmin(currentNew);
			system("pause");
			break;
		case 2:
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
				break;
			}
			else {
				cout << "Введите пароль пользователя: ";
				cin >> currentPassword;
				currentPassword = md5(currentPassword);
				this->deleteUser(currentLogin, currentPassword);
				system("pause");
			}
			break;
		case 3:
			system("cls");
			this->addUser();
			system("pause");
			break;
		case 4:
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentNew.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
			}
			else {
				system("cls");
				cout << "Введите новый логин пользователю: ";
				cin >> currentNew;
				this->renameLogin(currentNew, currentLogin,str);
				system("pause");
			}	
			break;
		case 5:
			str.clear();
			currentLogin.clear();
			currentNew.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
			}
			else {
				system("cls");
				cout << "Введите пароль пользователю: ";
				cin >> currentPassword;
				cout << "Введите новый пароль пользователю: ";
				cin >> currentNew;
				currentNew = md5(currentNew);
				currentPassword = md5(currentPassword);
				this->renamePassword(currentNew, currentLogin, currentPassword);
				system("pause");
			}
			break;
		case 6:
			system("cls");
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
				break;
			}
			else {
				system("cls");
				cout << "Введите новое ФИО пользователю: ";
				cin >> currentNew;
				this->renameFIO(currentNew, currentLogin);
				system("pause");

			}
			break;
		case 7:
			system("cls");
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
				break;
			}
			else {
				system("cls");
				cout << "Введите новый адресс пользователю: ";
				cin >> currentNew;
				this->renameAdress(currentNew, currentLogin);
				system("pause");
			}
			break;
		case 8:
			system("cls");
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
				break;
			}
			else {
				system("cls");
				cout << "Введите новый номер телефона пользователя: ";
				cin >> currentNew;
				this->renamePhone(currentNew, currentLogin);
				system("pause");
			}
			break;
		case 9:
			system("cls");
			test.createCategory();
			system("pause");
			break;
		case 10:
			system("cls");
			test.createTest();
			system("pause");
			break;
		case 11:
			system("cls");
			str.clear();
			pos = NULL;
			currentLogin.clear();
			currentPassword.clear();
			system("cls");
			cout << "Введите логин пользователя: ";
			cin >> currentLogin;
			fin.open("LogsUsers.txt");
			while (!fin.eof()) {
				fin.get(ch);
				str += ch;
			}
			fin.close();
			pos = str.find(currentLogin);
			if (pos == -1) {
				cout << "Такого логина нету в базе. " << endl;
				system("pause");
				break;
			}
			else {
				strOne = currentLogin;
				strOne += ".txt";
				strTwo = "AcademicPerformance//";
				strTwo += strOne;
				loadStat.open(strTwo);
				while (!loadStat.eof()) {
					getline(loadStat, strThree);
					strFour += strThree;
					if (!loadStat.eof()) {
						strFour += '\n';
					}
				}
				cout << strFour << endl;
				strFour.clear();
				loadStat.close();
				system("pause");
				break;
			}
			break;
		case 12:
			exitMenu = true;
			break;
		}
	}
	return 0;
}
string readFile(const std::string& fileName) {
	fstream f(fileName);
	stringstream ssq;
	ssq << f.rdbuf();
	return ssq.str();
}
void MenuListAdmin::renamePhone(string newPhone, string login)
{
	char ch;
	ifstream fiadsn, qin;
	string strFIO, strAdress, strPhone, strLogin, strAll, str;
	string login_temp = login;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;

	qin.open("LogsUsers.txt");
	while (!qin.eof()) {
		qin.get(ch);
		str += ch;
	}
	qin.close();

	fiadsn.open(path);
	getline(fiadsn, strLogin);
	getline(fiadsn, strFIO);
	getline(fiadsn, strAdress);
	getline(fiadsn, strPhone);
	fiadsn.close();
	strAll = strLogin + "\n" + strFIO + "\n" + strAdress + "\n" + strPhone + "\n";
	int pos = str.find(login);
	if (pos == -1) {
		cout << "Такого логина нету в базе. " << endl;
	}
	else {
		cout << "Отлично." << endl;
		strAll.replace(strAll.find(strPhone), strPhone.length(), newPhone);
		ofstream save;
		save.open(path);
		save << strAll << endl;
		save.close();
	}
}
void MenuListAdmin::renameAdress(string newAdress, string login)
{
	char ch;
	string strFIO, strAdress, strPhone, strLogin, strAll, str;
	ifstream qin, fiadsn;
	string login_temp = login;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;

	qin.open("LogsUsers.txt");
	while (!qin.eof()) {
		qin.get(ch);
		str += ch;
	}
	qin.close();
	fiadsn.open(path);
	getline(fiadsn, strLogin);
	getline(fiadsn, strFIO);
	getline(fiadsn, strAdress);
	getline(fiadsn, strPhone);
	fiadsn.close();
	strAll = strLogin + "\n" + strFIO + "\n" + strAdress + "\n" + strPhone + "\n";
	int pos = str.find(login);
	if (pos == -1) {
		cout << "Такого логина нету в базе. " << endl;
	}
	else {
		cout << "Отлично." << endl;
		strAll.replace(strAll.find(strAdress), strAdress.length(), newAdress);
		ofstream save;
		save.open(path);
		save << strAll << endl;
		save.close();
	}
}
void MenuListAdmin::renameFIO(string newFIO, string login)
{
	char ch;
	string str, strFIO, strAdress, strPhone, strLogin, strAll;
	ifstream qin, fiadsn;

	string login_temp = login;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;
	qin.open("LogsUsers.txt");
	while (!qin.eof()) {
		qin.get(ch);
		str += ch;
	}
	qin.close();
	fiadsn.open(path);
	getline(fiadsn, strLogin);
	getline(fiadsn, strFIO);
	getline(fiadsn, strAdress);
	getline(fiadsn, strPhone);
	fiadsn.close();
	strAll = strLogin + "\n" + strFIO + "\n" + strAdress + "\n" + strPhone + "\n";
	int pos = str.find(login);
	if (pos == -1) {
		cout << "Такого логина нету в базе. " << endl;
	}
	else {
		cout << strFIO << endl;
		cout << "Отлично." << endl;
		strAll.replace(strAll.find(strFIO), strFIO.length(), newFIO);
		ofstream save;
		save.open(path);
		save << strAll << endl;
		save.close();
	}
}
void MenuListAdmin::renamePassword(string newPassword, string login, string password) {
	char ch;
	string str;
	ifstream fin;
	fin.open("LogsUsers.txt");
	while (!fin.eof()) {
		fin.get(ch);
		str += ch;
	}
	fin.close();
	int pos = str.find(login);
	if (pos == -1) {
		cout << "Такого логина нету в базе. " << endl;
	}
	else {
		int pos1 = str.find(password);
		if (pos1 == -1) {
			cout << "Неверный пароль к логину. " << endl;
		}
		else {
			cout << "Отлично." << endl;
			str.replace(str.find(password), password.length(), newPassword);
			ofstream save;
			save.open("LogsUsers.txt");
			save << str << endl;
			save.close();
		}

	}
}
void MenuListAdmin::renameLogin(string newLogin, string login,string str) {
	ifstream fiadsn;
	string strFIO, strAdress, strPhone, strLogin, strAll;
	string login_temp = login;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;

	fiadsn.open(path);
	getline(fiadsn, strLogin);
	getline(fiadsn, strFIO);
	getline(fiadsn, strAdress);
	getline(fiadsn, strPhone);
	fiadsn.close();
	strAll = newLogin + "\n" + strFIO + "\n" + strAdress + "\n" + strPhone;
	remove(path.c_str());
	string login_new_temp = newLogin;
	string txt = ".txt";
	login_new_temp += temp;
	string pathTemp = "InfoUsers//";
	pathTemp += login_new_temp;
	ofstream finq;
	finq.open(pathTemp);
	finq << strAll << endl;
	finq.close();
		string str5, str6, pathTwo,str2,str3,pathThree,bonus,kols,str7,str8,pathFour,str9,str10,pathFive,nameTest,nameRozdil,str11,str12,str13,str14,pathSix;
		string AllStr;
		str6 = "NoEndTests";
		str5 += "-" + login;
		str5 += ".txt";
		str6 += "//";
		pathTwo = str6 + str5;	
		ifstream loginSave;
		loginSave.open(pathTwo);
		getline(loginSave, kols);
		getline(loginSave, bonus);
		getline(loginSave, nameTest);
		getline(loginSave, nameRozdil);
		AllStr = kols + "\n" + bonus + "\n" + nameTest + "\n" + nameRozdil;
		loginSave.close();
		remove(pathTwo.c_str());

		str7 = "NoEndTests//";
		str8 += login + "-" + nameTest + "-" + "Questions.txt";
		pathFive = str7 + str8;
		str9 = "NoEndTests//";
		str10 += login + "-" + nameTest + "-" + "Answers.txt";
		pathSix = str9 + str10;
		string infoQuest = readFile(pathFive);
		string infoAns = readFile(pathSix);
		remove(pathSix.c_str());
		remove(pathFive.c_str());

	

		ofstream newQuestSave;
		str12 = "NoEndTests//";
		str12 += newLogin + "-" + nameTest + "-" + "Questions.txt";
		str14 = "NoEndTests//";
		str14 += newLogin + "-" + nameTest + "-" + "Answers.txt";
		newQuestSave.open(str12);
		newQuestSave << infoQuest << endl;
		newQuestSave.close();
		ofstream newAnsSave;
		newAnsSave.open(str14);
		newAnsSave << infoAns << endl;
		newAnsSave.close();

		ofstream newLoginSave;
		str2 = "NoEndTests";
		str3 += "-" + newLogin;
		str3 += ".txt";
		str2 += "//";
		pathThree = str2 + str3;
		newLoginSave.open(pathThree);
		newLoginSave << AllStr << endl;
		newLoginSave.close();
		string PathOne;

		PathOne = "AcademicPerformance//";
		PathOne += login + ".txt";
		string sq;
		char chq;
		fstream acedem(PathOne, ios::in | ios::out | ios::app);
		while (!acedem.eof()) {
			acedem.get(chq);
			sq += chq;
		}
		acedem.close();
		remove(PathOne.c_str());


		string PathTwo;
		PathTwo = "AcademicPerformance//";
		PathTwo += newLogin + ".txt";
		ofstream acedemSave(PathTwo);
		acedemSave.open(PathTwo);
		acedemSave << sq;
		acedemSave.close();

		ifstream fin;
		char chw;
		string qwe;
		
		cout << "Отлично." << endl;
		str.replace(str.find(login), login.length(), newLogin);
		ofstream save;
		save.open("LogsUsers.txt");
		save << str << endl;
		save.close();
	
}
void MenuListAdmin::addUser() {
	Register();
}
void MenuListAdmin::deleteUser(string findLogin, string findPassword)
{
	string login_temp = findLogin;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;
	remove(path.c_str());
	ifstream fin;
	fin.open("LogsUsers.txt");
	char ch;
	string str;
	while (!fin.eof()) {
		fin.get(ch);
		str += ch;
	}
	fin.close();
	int pos = str.find(findLogin);
	int pos1 = str.find(findPassword);
	bool fa = str.find(str.empty());
	if (pos == -1 || pos1 == -1) {
		cout << "В базе данных нету таких данных." << endl;
	}
	else {
		size_t pos = str.find(findLogin);
		if (pos != string::npos) {
			str.replace(str.find(findLogin), findLogin.length(), "");
		}
		size_t pos1 = str.find(findPassword);
		if (pos1 != string::npos) {
			str.replace(str.find(findPassword), findPassword.length(), "");
		}
		ofstream save;
		save.open("LogsUsers.txt");
		if (!str.empty())
		{
			save << str << endl;
		}
		cout << "Удалено. " << endl;
		save.close();
	}
}
void MenuListAdmin::replacePasswordAdmin(string password)
{
	string logins, passwords;
	char login_l[80], password_l[80];
	ifstream load;
	load.open("LogsAdmin.txt");
	load.getline(login_l, 80, '\n');
	load.getline(password_l, 80, '\n');
	load.close();
	ofstream save;
	save.open("LogsAdmin.txt");
	save.clear();
	password = md5(password);
	save << login_l << endl;
	save << password << endl;
	save.close();
}
void MenuListAdmin::replaceLoginAdmin(string login)
{
	string logins, passwords;
	char login_l[80], password_l[80];
	ifstream load;
	load.open("LogsAdmin.txt");
	load.getline(login_l, 80, '\n');
	load.getline(password_l, 80, '\n');
	load.close();
	ofstream save;
	save.open("LogsAdmin.txt");
	save.clear();
	save << login << endl;
	save << password_l << endl;
	save.close();
}

class MenuListStudent {
public:
	int menu(string loginq);
	void checkLoginStud(string login);
};
int MenuListStudent::menu(string loginq)
{
	vector<string> listDirect;

	setlocale(LC_ALL, "Russian");
	string loginInfo_temp = loginq;
	loginInfo_temp += ".txt";
	string STR = "AcademicPerformance//";
	STR += loginInfo_temp;
	ifstream load;
	ifstream testProfit;
	string FIO_F, phone_p, adress_a, login_l,tempOne,tempTwo;
	char FIO_C[80], phone_c[80], adress_c[80], login_c[80];
	string login_temp = loginq;
	string temp = ".txt";
	login_temp += temp;
	string path = "InfoUsers//";
	path += login_temp;
	load.open(path);
	load.getline(login_c, 80, '\n');
	load.getline(FIO_C, 80, '\n');
	load.getline(phone_c, 80, '\n');
	load.getline(adress_c, 80, '\n');
	userStudent usersq(login_c, FIO_C, adress_c, phone_c);
	people.push_back(usersq);
	while (!load.eof()) {
		load.getline(login_c, 80, '\n');
		load.getline(FIO_C, 80, '\n');
		load.getline(phone_c, 80, '\n');
		load.getline(adress_c, 80, '\n');
		load.close();
		userStudent usersq(login_c, FIO_C, adress_c, phone_c);
		people.push_back(usersq);
	}
	load.close();
	string str,strSA;
	ifstream loadDir;
	loadDir.open("ListDirectorits.txt");
	while (!loadDir.eof()) {
		getline(loadDir, strSA);
		listDirect.push_back(strSA);
	}
	while (true)
	{
		ifstream loadqs(STR);
		CTest test(loginq);
		int a = 0;
		system("cls");
		string str5, str6, pathTwo;
		str6 = "NoEndTests";
		str5 += "-" + loginq;
		str5 += ".txt";
		str6 += "//";
		pathTwo = str6 + str5;

		ifstream loadTwo;
		loadTwo.open(pathTwo);
		if (is_empt(loadTwo)) {
			
		}
		else {
			cout << "У вас есть незавершенные тесты. " << endl;
		}
		loadTwo.close();
		int c = Menu::select_vertical({
			"Пройти тест.",
			"Посмотреть свои результаты тестирования.",
			"Пройти непройденный тест.",
			"Показать инфо про себя.",
			"Выход c личного кабинета." },
			HorizontalAlignment::Center, 5);
		switch (c) {
		case 0:
				a = Menu::select_vertical({
				listDirect,},
				HorizontalAlignment::Center, listDirect.size());
				CategorySwitch(test, loginq, a);
			break;
		case 1:
			if (is_empt(loadqs)) {
				cout << "Вы ещё не прошли ни одного теста. " << endl;
				system("pause");
			}
			else {
				while (!loadqs.eof()) {
					getline(loadqs, tempOne);
					tempTwo += tempOne;
					if (!loadqs.eof()) {
						tempTwo += '\n';
					}
				}
				cout << tempTwo << endl;
				tempOne.clear();
				tempTwo.clear();
				system("pause");
			}
			break;
		case 2:
			test.checkEndTest(loginq, test);
			system("pause");
			break;
		case 3:
			checkLoginStud(loginq);
			
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
	}
}
void MenuListStudent::checkLoginStud(string login) {

	string str1, str2, path;
	str1 = login;
	str1 += ".txt";
	str2 = "InfoUsers//";
	path = str2 + str1;
	string str3;
	stringstream s;
	ifstream fin(path);
	if (fin)
	{
		s << fin.rdbuf();
		str3 = s.str();
	}
	cout << str3;
	system("pause");

}

class Application {
	MenuListAdmin mla;
	MenuListStudent mls;
public:
	int appMenu();
};
int Application::appMenu()
{
	setlocale(LC_ALL, "ukr");
	bool logOrNoLog = false;
	string loginCorrectTrue, newRenameLogin1;
	ifstream checkAdm;
	checkAdm.open("LogsAdmin.txt");
	if (is_empt(checkAdm)) {
		Register_Admin();
	}
	while (true)
	{
		system("cls");
		int c = Menu::select_vertical({
			"Вход.",
			"Регистрация.",
			"Выход" },
			HorizontalAlignment::Center, 3);
		switch (c) {
		case 0:
			system("cls");
			logOrNoLog = Logins();
			if (logOrNoLog == true) {
				if (getCheckAdmin == true) {
					cout << "Вы зашли как админ." << endl;
					system("pause");
					 mla.menu();
				}
				else {
					loginCorrectTrue = loginCorrect;
					cout << "Вы зашли как студент." << endl;
					system("pause");
					mls.menu(loginCorrectTrue);
				}
			}
			else {
				cout << "Вы не попали в меню." << endl;
			}
			system("pause");
			break;
		case 1:
			system("cls");
			Register(); 
			system("pause");
			break;
		case 2:
			return 0;
			break;
		default:
			break;
		}
	}
}