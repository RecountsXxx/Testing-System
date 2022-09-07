#pragma once
#include "Application.h"
#include <Windows.h>
class Test {
	string voprosQ[100];
	int abcd[100][4];
	string abcdAnswers[100][4];
public:  
	Test() {}
	~Test(){}
	void createCategory();
	void createTest();
	void swtichCater(string s) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		string text[4] = { "a", "b","c","d" };
		string path, temp, tempSlash, corOtvet;
		string nameRozdil, nameRozdilTest, pathTwo, str, strOne, strTwo, strThree, strFour, pathTemp;
		int kolTests;
		cout << "Раздел: " << s << endl;
		nameRozdil = s;
		if (fs::is_directory(nameRozdil)) {
			cout << "Введите название теста: ";
			cin >> nameRozdilTest;
			cin.ignore();
			cout << "Введите кол-во вопросов в тесте: ";
			cin >> kolTests;
			cin.ignore();

			strThree = nameRozdilTest;
			strFour = nameRozdil;
			strOne = nameRozdil;
			strTwo = nameRozdilTest;
			nameRozdil += "//";
			nameRozdil += "/Questions/";
			nameRozdilTest += ".txt";
			path = nameRozdil + nameRozdilTest;
			strOne += "//";
			strOne += "/Answers/";
			strTwo += ".txt";
			strThree += "-InfoTest.txt";
			strFour += "//";
			strFour += "/Answers/";
			pathTemp = strFour + strThree;
			pathTwo = strOne + strTwo;

			for (int i = 0; i < kolTests; i++) {  //сделать правильный запись
				cout << "Введите вопрос: ";
				getline(cin, voprosQ[i]);
				cout << "Введите варианты ответов. " << endl;
				for (int q = 0; q < 4; q++) {
					cout << text[q] << ". ";
					getline(cin, abcdAnswers[i][q]);
				}
				label1:
				cout << "Введите правильный ответ(a,b,c,d)." << endl;
				cout << ">>> ";
				cin >> corOtvet;
				corOtvet += ".";
				if (corOtvet == "a.") {
					abcd[i][0] = 1;
					abcd[i][1] = 0;
					abcd[i][2] = 0;
					abcd[i][3] = 0;		
				}
				if (corOtvet == "b.") {
					abcd[i][0] = 0;
					abcd[i][1] = 1;
					abcd[i][2] = 0;
					abcd[i][3] = 0;
				}
				if (corOtvet == "c.") {

					abcd[i][0] = 0;
					abcd[i][1] = 0;
					abcd[i][2] = 1;
					abcd[i][3] = 0;
				}
				if (corOtvet == "d.") {
					abcd[i][0] = 0;
					abcd[i][1] = 0;
					abcd[i][2] = 0;
					abcd[i][3] = 1;
				}
				if (corOtvet != "d." && corOtvet != "c." && corOtvet != "b." && corOtvet != "a.") {
					cout << "Неверно такого ответа не существует. " << endl;
					goto label1;
				}
				cin.ignore();
			}
			ofstream save;
			ofstream saveAns;
			ofstream saveInfo;
			saveInfo.open(pathTemp);
			saveInfo << kolTests << endl;
			saveInfo.close();
			save.open(path);
			saveAns.open(pathTwo);
			for (int i = 0; i < kolTests; i++) {
				save << i + 1 << ". " << voprosQ[i] << endl;
				saveAns << i + 1 << "." << endl;
				for (int q = 0; q < 4; q++) {
					save << text[q] << ". " << abcdAnswers[i][q] << endl;
					saveAns << text[q] << ". " << abcd[i][q] << endl;
				}
			}
			saveAns << "END" << endl;
			save << "END" << endl;
			saveAns.close();
			save.close();

		}
		else {
			cout << "Такого раздела не существует. " << endl;
		}
	}
};
void Test::createTest()
{
	vector<string>listDirect;
		string str, strSA;
		ifstream loadDir;
		loadDir.open("ListDirectorits.txt");
		while (!loadDir.eof()) {
			getline(loadDir, strSA);
			listDirect.push_back(strSA);
		}
     	int a  = Menu::select_vertical({
		listDirect },
		HorizontalAlignment::Center, listDirect.size());
		string s = listDirect.at(a);
	swtichCater(s);
}
void Test::createCategory()
{
	fs::path s;
	fs::path q;
	string name, strq,str;
	char ch;
	cout << "Введите название раздела: ";
	cin >> name;
	ifstream fin;

	fin.open("ListDirectorits.txt",ios::app);
	while (!fin.eof()) {
		fin.get(ch);
		strq += ch;
	}
	fin.close();
	int pos = strq.find(name);
	if (pos == -1) {
		s = name;
		s += "/Questions";
		q = name;
		q += "/Answers";
		fs::create_directories(s);
		fs::create_directories(q);
		cout << "Отлично." << endl;
		ofstream fs;
		fs.open("ListDirectorits.txt", ios::app);
		fs << name << endl;   //для записи раздела что он есть
		fs.close();
	}
	else {
		cout << "Такой раздел уже существует. " << endl;
		return;
	}
	
}
void CategorySwitch(CTest test, string login,int a) {
	SetConsoleCP(1251);
	srand(time(0));
	SetConsoleOutputCP(1251);
	vector<string> listDirect;
	string strSA,musor,s,STRQ;
	ifstream loadDir;
	loadDir.open("ListDirectorits.txt");
	while (!loadDir.eof()) {
		getline(loadDir, strSA);
		listDirect.push_back(strSA);
	}
	s = listDirect.at(a);
	loadDir.close();
		string strq, strh, tempStrOne, tempStrTwo, tempStrThree, pathTempDirTwo, tempStr;
		string pathTempDir, nameProfitTest;
		cout << "Вы попали в раздел " << s << endl;
		tempStr = s;
		string q = ".txt";
		cout << endl;
		cout << "Доступные тесты: " << endl;
		tempStrOne = s;
		pathTempDirTwo = tempStrOne += "//";
		pathTempDirTwo += "Answers/";
		pathTempDir = s += "//";
		pathTempDir += "Questions/";

		vector<string> hVector;
		string h;
		fs::path p(pathTempDir);
		for (auto i = fs::directory_iterator(p); i != fs::directory_iterator(); i++)
		{
			if (!fs::is_directory(i->path())) //we eliminate directories
			{
				h = i->path().filename().string();
				h.erase(h.find(".txt"), 4);
				hVector.push_back(h);
			}
			else
				continue;
		}
		int g = Menu::select_vertical({
		hVector },
		HorizontalAlignment::Center, hVector.size());
		string j = hVector.at(g);
		nameProfitTest = j;
		tempStrOne.clear();
		tempStrOne = pathTempDir;
		tempStrTwo = pathTempDirTwo;
		tempStrOne += nameProfitTest + ".txt";
		tempStrTwo += nameProfitTest + ".txt";
		system("cls");
		if (test.Open(tempStrOne, tempStrTwo)) {
			fs::create_directory("AcademicPerformance");
			test.RunTest(login, s, nameProfitTest, pathTempDir, tempStrOne,false);

		}
		else
			_getch();//запуск теста
		s = tempStr;
		tempStr.clear();
	}

