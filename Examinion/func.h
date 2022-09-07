#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include "Application.h"
#include <sstream>
#include <ctime>
using namespace std;
bool is_empt(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}
void  renameLoginAdmin(string login) {
	string logins, passwords;
	char login_l[80], password_l[80];
	ifstream load;
	load.open("LogsAdmin.txt");
	load.getline(login_l, 80, '\n');
	load.getline(password_l, 80, '\n');
	logins = login_l;
	passwords = password_l;
	while (!load.eof()) {
		load.getline(login_l, 80, '\n');
		load.getline(password_l, 80, '\n');
		logins = login_l;
		passwords = password_l;
	}
	load.close();
	string correctAdm;
	char w;
	ofstream admCheck;
	admCheck.open("LogsAdmin.txt");
	while (!admCheck.eof()) {
		admCheck << logins << endl;
		admCheck << passwords << endl;
	}
	admCheck.close();

}
bool chechAdmin(string pass, string login) {
	string correctAdm;
	char w;
	ifstream admCheck;
	admCheck.open("LogsAdmin.txt");
	while (!admCheck.eof()) {
		admCheck.get(w);
		correctAdm.push_back(w);
	}
	int adm1 = correctAdm.find(pass);
	int adm2 = correctAdm.find(login);

	//
	if (adm1 == -1 || adm2 == -1) {
		return false;
		system("pause");
	}
	else {
		return true;
		system("pause");
		system("cls");
	}
}
enum HorizontalAlignment
{
	Center, Left, Right
};

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
class Menu
{
public:
	static int select_vertical(vector <string> menu, HorizontalAlignment ha, int y = 8)
	{
		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO start_attribute;
		HWND s = GetConsoleWindow();
		ShowScrollBar(s, SB_BOTH, FALSE);
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
		GetConsoleScreenBufferInfo(hStdOut, &start_attribute);
		int backColor = start_attribute.wAttributes & 15;
		int textColor = (start_attribute.wAttributes >>= 4) & 15;
		int maxLen = 0;
		for (size_t i = 0; i < menu.size(); i++)
		{
			menu[i] = " " + menu[i] + " ";
			if (menu[i].length() > maxLen)
				maxLen = menu[i].length();
		}
		int x = 0;
		switch (ha)
		{
		case Center: x = 55 - maxLen / 2; break;
		case Left:   x = 40 - maxLen / 2;	              break;
		case Right:  x = 110 - maxLen;     break;
		}
		char c;
		int pos = 0;
		do
		{
			for (int i = 0; i < menu.size(); i++)
			{
				if (i == pos)
				{
					SetColor(textColor, backColor);
					gotoxy(x, y + i);
					cout << setw(maxLen) << left;
					gotoxy(x, y + i);
					cout << menu[i] << endl;
					SetColor(backColor, textColor);
				}
				else
				{
					SetColor(backColor, textColor);
					gotoxy(x, y + i);
					cout << setw(maxLen) << left;
					gotoxy(x, y + i);
					cout << menu[i] << endl;
					SetColor(textColor, backColor);
				}
			}
			c = _getch();
			switch (c)
			{
			case 72: if (pos > 0)               pos--; break; // up
			case 80: if (pos < menu.size() - 1) pos++; break; // down
			case 13: break;
			}

		} while (c != 13);
		for (size_t i = 0; i < 2; i++)
		{
			SetColor(backColor, textColor);
			gotoxy(x, y + pos);
			cout << setw(maxLen) << left;
			gotoxy(x, y + pos);
			cout << menu[pos] << endl;
			Sleep(200);
			SetColor(textColor, backColor);
			gotoxy(x, y + pos);
			cout << setw(maxLen) << left;
			gotoxy(x, y + pos);
			cout << menu[pos] << endl;
			SetColor(backColor, textColor);
			Sleep(200);
		}
		SetColor(backColor, textColor);
		system("cls");
		return pos;
	}
	int select_gorizontal(vector<string> menu)
	{
		int max_len = 0;
		for (int i = 0; i < menu.size(); i++)
			max_len += menu[i].length();
		if (max_len > 80 - menu.size() - 1)
			int a = 1;/////////
	}
};
bool IsEmpty(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return false;
	}
	return true;
}

string Trim(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (!i)
				return s;
			else
			{
				return s.substr(i);
			}
		}
	}
	return s;
}

string GetCharBeforeDot(string s)
{
	string str;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			return Trim(s.substr(0, i));
		}
	}
	return "";
}

string GetCharAfterDot(string s)
{
	string str;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
		{
			return Trim(s.substr(i + 1));
		}
	}
	return "";
}




struct CAnswerStruct
{
	char c;
	int bonus;
};

typedef vector<string> CQuestStrings;
typedef vector<CQuestStrings*> CQuest;
typedef vector<CAnswerStruct*> CAnswer;
typedef vector<CAnswer*> CAnswers;

class CTest
{
	string UserName;
	CQuest Questions;
	CAnswers Answers;
	int Bonus;
	bool EndTest = false;
	void WriteQuest(int n, string pathTwo, string pathOne, string nameTest, string nameRozdil, string login)
	{
		string strhq, strq,tempStrOne, pathTempDirTwo, tempStr, pathTemDirOne, pathThree, kolTests,input;
		int pop = 0, numerate = 0,stroki = 0, num = 0;
		ofstream saving;
		ofstream save;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		for (size_t j = 0; j < Questions[n]->size(); j++)
		{
			numerate++;
			ifstream fin;
			fin.open(pathOne);
			string s;
			while (fin.peek() != EOF) {
				getline(fin, s);
				stroki++;
			}
			fin.close();
			if (GetAsyncKeyState(VK_CONTROL)) {
				tempStrOne = nameRozdil;
				pathTempDirTwo = tempStrOne;
				pathTempDirTwo += "Answers/";
				tempStr = nameTest;
				pathTemDirOne = tempStr += "-InfoTest.txt";
				pathThree = pathTempDirTwo + pathTemDirOne;
				kolTests = readFile(pathThree);
				system("cls");
				cout << "Вы завершили тест. Вы сможете потом его допройти." << endl;
				saving.open(pathTwo);
				saving << n<< endl;
				saving << Bonus << endl;
				saving << nameTest << endl;
				nameRozdil.erase(nameRozdil.find("//"), 2);
				saving << nameRozdil << endl;
				saving.close();
				input = readFile(pathOne);
				pop = n + 1;
				string temp = " ";
				string start = to_string(pop), finish = "END";
				ifstream fin(pathOne);
				while (!fin.eof() && temp != "") {
					getline(fin, temp);
					input += temp;
				}
				input.erase(0, input.find(start) + start.length() - 1);
				input.erase(input.find(finish) - 1, input.length());
				fin.close();

				string str1, str2, pathFour, str3, str4, pathFive;
				str1 = login;
				str1 += "-" + nameTest + "-Questions.txt";
				str2 = "NoEndTests//";
				pathFour = str2 + str1;
				str3 = login;
				str3 += "-" + nameTest + "-Answers.txt";
				str4 = "NoEndTests//";
				pathFive = str4 + str3;
				int nuq = stoi(kolTests);
				nuq += 1;

				ofstream savingq;
				savingq.open(pathFour);
				savingq << input << endl;
				savingq << "END" << endl;
				savingq.close();
				ifstream tmp;
				ifstream tmp2;

				string SSS = nameRozdil + "//";
				SSS += "Answers/";
				SSS += nameTest + "-InfoTest.txt";
				string endRes;

				tmp2.open(pathTwo);
				string ostatok;
				tmp2 >> ostatok;
				tmp2.close();

				tmp2.open(SSS);
				string strrr;
				tmp2 >> strrr;
				tmp2.close();


				tmp.open(pathFour);
				string fffff;
				int qwerty = 1;
				for (size_t i = 0; i < stoi(strrr) - stoi(ostatok); i++)
				{
					getline(tmp, fffff);

					if (fffff == "END")
					{
						break;
					}
					int k = 0;
					while (fffff[k] != '.')
					{
						++k;
					}

					endRes += to_string(qwerty);

					for (size_t i = 0; i < fffff.length(); ++i, ++k)
					{
						endRes += fffff[k];
					}
					endRes += "\n";
					++qwerty;
					for (size_t i = 0; i < 4; i++)
					{
						getline(tmp, fffff);
						endRes += fffff + "\n";
					}
				}


				tmp.close();
				endRes += "\nEND";
				savingq.open(pathFour);
				savingq << endRes << endl;
				savingq.close();
				string pathSix;
				pathSix = nameRozdil + "//Answers/";
				pathSix += nameTest + ".txt";
				string inputTwo = readFile(pathSix);
				int popq = n + 1;
				string tempTwo = " ";
				system("pause");
				string startTwo = to_string(popq), finishTwo = "END";
				ifstream finw(pathSix);


				while (!finw.eof() && tempTwo != "") {
					getline(finw, tempTwo);
					inputTwo += tempTwo;
				}
				inputTwo.erase(0, inputTwo.find(startTwo) + startTwo.length() - 1);
				inputTwo.erase(inputTwo.find(finishTwo) - 1, inputTwo.length());
				finw.close();


				ofstream savingqw;
				savingqw.open(pathFive);
				savingqw << inputTwo << endl;
				savingqw << "END" << endl;
				savingqw.close();
				ifstream tmp3;
				ifstream tmp4;
				string endResQ;
				tmp3.open(pathFive);
				string fffffQ;
				int qwertyQ = 1;
				for (size_t i = 0; i < stoi(strrr) - stoi(ostatok); i++)
				{
					getline(tmp3, fffffQ);

					if (fffffQ == "END")
					{
						break;
					}
					endResQ += to_string(qwertyQ) + ".\n";
					++qwertyQ;

					for (size_t i = 0; i < 4; i++)
					{
						getline(tmp3, fffffQ);
						endResQ += fffffQ + "\n";
					}
				}
				tmp3.close();
				endResQ += "\nEND";
				ofstream savinQ;
				savinQ.open(pathFive);
				savinQ << endResQ << endl;
				savinQ.close();



				string S1, S2, S3;
				S1 = "NoEndTests//";
				S1 += login + "-" + "Info.txt";

				S2 = nameRozdil + "//";
				S2 += "Answers/";
				S2 += nameTest + "-InfoTest.txt";
				ifstream loadinqwe;
				loadinqwe.open(S2);



				while (!loadinqwe.eof()) {
					loadinqwe >> S3;
				}
				loadinqwe.close();
				ofstream savingwe;
				numerate += numerate;
				int resultat = stoi(S3);
				savingwe.open(S1);
				savingwe << resultat << endl; 
				savingwe.close();
				exit(0);
			}
		}
	}
	string readFile(const std::string& fileName) {
		fstream f(fileName);
		stringstream ssq;
		ssq << f.rdbuf();
		return ssq.str();
	}




	void WriteAnswers()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		for (size_t i = 0; i < Answers.size(); i++)
			cout << Answers[i] << endl;
	}

	void ReadTest(string test)
	{

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		string s;
		int nQ = -1;

		ifstream in;
		in.open(test.c_str());
		if (!in)
		{
			cout << "Ошибка при чтении файла " << endl;
			throw 0;
		}
		while (!in.eof())
		{
			getline(in, s);

			if (!IsEmpty(s))
			{
				int n = atoi(GetCharBeforeDot(s).c_str());
				if (n)
				{
					CQuestStrings* strs = new CQuestStrings();
					Questions.push_back(strs);
					strs->push_back(s);
					nQ = n - 1;
				}
				else if (nQ != -1)
				{
					Questions[nQ]->push_back(s);
				}
			}
		}
		in.close();

	}

	void ReadAnswers(string answers)
	{
		string s;
		int nA = -1;

		ifstream in;
		in.open(answers.c_str());
		if (!in)
		{
			cout << "Ошибка при чтении файла " << endl;
			throw 0;
		}
		while (!in.eof())
		{
			getline(in, s);

			if (!IsEmpty(s))
			{
				int n = atoi(GetCharBeforeDot(s).c_str());
				if (n)
				{
					CAnswer* answer = new CAnswer();
					Answers.push_back(answer);
					nA = n - 1;
				}
				else if (nA != -1)
				{
					CAnswerStruct* as = new CAnswerStruct();
					Answers[nA]->push_back(as);
					as->c = GetCharBeforeDot(s)[0];
					int m = atoi(GetCharAfterDot(s).c_str());
					as->bonus = m;
				}
			}
		}
		in.close();
	}


	void RunQuest(int n, string pathTwo, string pathOne, string nameTest, string nameRozdil, string login)
	{
		WriteQuest(n, pathTwo, pathOne, nameTest, nameRozdil, login);
		cout << "Если вы хотите выйти, то нажмите Ctrl и потом Enter. " << endl;
		label1:
		char f= Menu::select_vertical({
			(*Questions[n])},
			HorizontalAlignment::Center, Questions[n]->size());
		char c;

		if (f == 1) {
			c = 'a';
		}
		if (f == 2) {
			c = 'b';
		}
		if (f == 3) {
			c = 'c';
		}
		if (f == 4) {
			c = 'd';
		}
		if (f == 5) {
			cout << "Выберите ответ: " << endl;
			goto label1;
		}
		for (size_t i = 0; i < Answers[n]->size(); i++)
		{
			if (f == 0) {
				cout << "Выбран неверный вариант. " << endl;
				goto label1;
			}
			if (c == Answers[n]->at(i)->c)
				Bonus += Answers[n]->at(i)->bonus;
		}

	}

public:
	CTest(string userName)
	{
		UserName = userName;
		Bonus = 0;
	}
	CTest() {}
	bool Open(string test, string answers)
	{

		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		try
		{
			ReadTest(test);
			ReadAnswers(answers);
			return true;
		}
		catch (...)
		{
			return false;
		}

	}
	void RunTest(string login, string nameRozdil, string nameTest, string pathTempDir, string tempStrOne, bool end)
	{
		string strTempOne = nameTest;
		double start = clock();
		int kols = 0;
		int kolsNew = 0;
		string str1, str2, str3, str4, path, kolTestsInfo, str5, str6, pathTwo;
		char kolTestsInfoChar[80];
		string login_temp, str, temp;
		str6 = "NoEndTests";
		str5 += "-" + login;
		str5 += ".txt";
		str6 += "//";
		pathTwo = str6 + str5;
		for (size_t i = 0; i < Answers.size(); i++) {
			RunQuest(i, pathTwo, tempStrOne, nameTest, nameRozdil, login);
		}
		pathTempDir += nameTest + ".txt";
		str1 = nameTest;
		str2 = nameRozdil;
		str1 += "-InfoTest.txt";
		str += "//";
		str2 += "Answers/";
		path = str2 + str1;
		login_temp = login;
		login_temp += ".txt";
		str = "AcademicPerformance//";
		str += login_temp;
		ofstream save;
		string S1, S2, S3, PT;
		S1 = "NoEndTests//";
		S1 += login + "-Info.txt";


		if (end == false) {
			system("cls");
			double endq = clock();
			double timeq = (endq - start) / CLOCKS_PER_SEC;
			time_t now = time(0);
			char* dt = ctime(&now);

			cout << "Времени потрачено на тест: " << timeq << ", дата: "<< dt << endl;
			cout << "Вы набрали " << Bonus << " бал(а,ов)" << endl;
			ifstream load;
			load.open(path);
			while (!load.eof()) {
				load >> kols;
			}
			load.close();
			save.open(str, ios::app);
			nameRozdil.erase(nameRozdil.find('//'), 2);
			save << "Раздел: " << nameRozdil << endl;
			save << "Тест: " << nameTest << ", оценка за него: " << Bonus << endl;
			save << "Времени потрачено на тест: " << timeq << ", дата: " << dt;
			float num = Bonus, result;
			float prot = kols;
			result = prot - Bonus;
			float resultAll = kols - result;
			float proc;
			proc = (resultAll / kols) * 100.0f;
			save << "Всего вопросов: " << kols << ", правильных ответов: " << resultAll << ", неправильных ответов: " << result << ", процент правильных ответов: " << proc << "%" << "." << endl;
			cout << "Всего вопросов: " << kols << ", правильных ответов: " << resultAll << ", неправильных ответов: " << result << ", процент правильных ответов: " << proc << "%" << "." << endl;
			save << endl;
			save.close();
			_getch();
		}
		else { //сделать тут красиво
			double endq = clock();
			double timeq = (endq - start) / CLOCKS_PER_SEC;
			time_t now = time(0);
			char* dt = ctime(&now);

			system("cls");
			ifstream load;
			string ST1, ST2, ST3, ST4, ST5;
			ST5 += nameTest;
			ST1 = nameTest;
			ST2 = nameRozdil;
			ST1 += "-InfoTest.txt";
			ST2 += "//";
			ST2 += "Answers/";
			ST3 = ST2 + ST1;
			ST4 = "NoEndTests//";
			ST4 += login + "-Info.txt";
			string temp_login = login, S7;

			temp_login += ".txt";
			S7 = "AcademicPerformance//";
			S7 += temp_login;
			string S5, S10, S11, S12, S13;
			S5 = "NoEndTests//";
			S5 += "-" + login + ".txt";
			ifstream loadiq;
			loadiq.open(S5);
			getline(loadiq, S10);
			getline(loadiq, S11);
			loadiq.close();
			S12 = "NoEndTests//";
			S12 += login + "-" + "Info.txt";
			ifstream qweqw;
			qweqw.open(S12);
			getline(qweqw, S13);
			qweqw.close();



			int newBonus = stoi(S11), newKols = stoi(S13);
			newBonus += Bonus;
			cout << "Законченный тест.Вы набрали " << newBonus << " бал(а,ов)" << endl;
			ofstream Saviw;
			Saviw.open(S7, ios::app);
			cout << "Тест: " << nameTest << ", оценка за него: " << newBonus << endl;
			cout << "Времени потрачено на тест: " << timeq << ", дата: " << dt;
			Saviw << "Это полностью пройденный тест. Раздел: " << nameRozdil << endl;
			Saviw << "Времени потрачено на тест: " << timeq << ", дата: " << dt;
			Saviw << "Тест: " << nameTest << ", оценка за него: " << newBonus << endl;
			float num = newBonus, result;
			float prot = newKols;
			result = prot - newBonus;
			float resultAll = newKols - result;
			float proc;
			proc = (resultAll / newKols) * 100.0f;
			Saviw << "Всего вопросов: " << newKols << ", правильных ответов: " << resultAll << ", неправильных ответов: " << result << ", процент правильных ответов: " << proc << "%" << "." << endl;
			cout << "Всего вопросов: " << newKols << ", правильных ответов: " << resultAll << ", неправильных ответов: " << result << ", процент правильных ответов: " << proc << "%" << "." << endl;
			cout << endl;
			Saviw << endl;
			Saviw.close();
			remove(S5.c_str());
			remove(ST4.c_str());
			return;
		}

	}

	void checkEndTest(string login, CTest testing) {
		string strq, strh, tempStrOne, tempStrTwo, tempStrThree, pathTempDirTwo, tempStr;
		string pathTempDir, nameProfitTest;
		int variant;
		string test, test2, str1, str2, path, str3, str4, str5, str6;
		str2 = "NoEndTests//";
		str1 += "-";
		str1 += login;
		str1 += ".txt";
		path = str2 + str1;
		ifstream checkEndTestFile;
		checkEndTestFile.open(path);
		if (is_empt(checkEndTestFile)) {
			cout << "Вы молодец!" << endl;
			cout << "У вас нету незаконченых тестов." << endl;
			return;
		}
		int n = 3, q = 4;
		for (int i = 0; i < n - 1; ++i)
		{
			string strTemp;
			getline(checkEndTestFile, strTemp);
		}
		string strTemp;
		getline(checkEndTestFile, strTemp);
		checkEndTestFile.close();
		ifstream checkEndTestFileTwo;
		checkEndTestFileTwo.open(path);
		for (int a = 0; a < q - 1; ++a)
		{
			string strTempOne;
			getline(checkEndTestFileTwo, strTempOne);
		}

		string strTempOne;
		getline(checkEndTestFileTwo, strTempOne);
		checkEndTestFileTwo.close();
		nameProfitTest = strTemp;
		cout << "Вы не прошли тест: " << strTemp << ", в разделе: " << strTempOne << endl;
		cout << "Вам стоит ещё потрудиться." << endl;
		cout << "У вас есть незакоченные тесты. " << endl;
		if (true) {
			bool end = false;
			string strq, strh, tempStrOne, tempStrTwo, tempStrThree, pathTempDirTwo, tempStr;
			string pathTempDir, nameProfitTest;
			test2 = strTempOne;
			tempStr = test2;
			cout << endl;
			tempStrOne = test2;
			pathTempDirTwo = strTempOne;
			pathTempDirTwo += "//Answers/";
			pathTempDir = strTempOne;
			pathTempDir += "//Questions/";
			tempStrOne.clear();
			tempStrOne = pathTempDir;
			tempStrTwo = pathTempDirTwo;
			tempStrOne += strTemp + ".txt";
			tempStrTwo += strTemp + ".txt";
			string pathAns, pathQuest, S1, S2, S3, S4;
			S1 = "NoEndTests//";
			S2 += login + "-" + strTemp + "-" + "Questions.txt";
			S3 = "NoEndTests//";
			S4 += login + "-" + strTemp + "-" + "Answers.txt";
			pathQuest = S1 + S2;
			pathAns = S3 + S4;
			end = true;
			if (testing.Open(pathQuest, pathAns)) {
				testing.RunTest(login, strTempOne, nameProfitTest, pathTempDir, tempStrOne, end);

			}
			remove(pathQuest.c_str());
			remove(pathAns.c_str());

		}
	}
};