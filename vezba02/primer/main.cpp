//08-03-2019
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

// помоћне функције
static bool loadStudents(string fileName);
static void printStudentLastNames();
static void printStudentIndexNums();
static void printStudentNamesAndIndexNums();
static void addStudent();
static void makeIndexToNameMap();
static void printIndexToNameMap();
static void printDesiredIndex(int x);
static void makeNameToIndexMap();
static void updateDesiredName(string name, int x);
static void printSpecial();
static void replace();
static void palindrom(string str);

// глобалне променљиве
static list<string> studentFirstNames;
static list<string> studentLastNames;
static vector<int> studentIndexNums;
static map<int, string> studentIndexToNameMap;
static map<string, int> studentNameToIndexMap;


int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Niste uneli potrebne argumente za pokretanje programa!" << endl;
		cout << "Argumenti komandne linije treba da budu:" << endl;
		cout << "1. apsolutna ili relativna putanja do datoteke: \"baza_studenata.txt\"" << endl;
		cout << "2. ime studenta" << endl;
		cout << "3. prezime studenta" << endl;
		exit(-1);
	}

	bool retVal;

	retVal = loadStudents(argv[1]);

	if (retVal == false)
	{
		cout << "Greska prilikom ucitavanja ulazne datoteke!\n" << endl;
		exit(-1);
	}

	printStudentLastNames();
	printStudentIndexNums();

	printStudentNamesAndIndexNums();

	addStudent();

	printStudentNamesAndIndexNums();

	makeIndexToNameMap();
	printIndexToNameMap();

	int x;
	cout << "Unesite broj indeksa: ";
	cin >> x;

	printDesiredIndex(x);

	makeNameToIndexMap();

	string name = argv[2];
	string surname = argv[3];
	// TODO: име и презиме студента преузети из прослеђених аргумената командне линије!

	string fullName = name + " " + surname;
	// TODO: формирај од имена и презимена један знаковни низ!

	updateDesiredName(fullName, 999);

	// Додатни
	printSpecial();

	replace();
	
	palindrom("Ova recenica nije palindrom");
	
	palindrom("Ana voli milovana");

	cout << endl << endl;

	return 0;
}


bool loadStudents(string fileName)
{
	// учитава датотеку "baza_studenata.txt"

	ifstream inputFile(fileName);

	if (inputFile.is_open() == false)
	{
		cout << endl << "GRESKA! Pogresno ime datoteke" << endl << endl;
		return false;
	}

	string ime;
	string prezime;
	int brojIndeksa;

	do
	{
		inputFile >> ime;
		inputFile >> prezime;
		inputFile >> brojIndeksa;

		// место за код
		// TODO: попуните studentFirstNames са именима
		studentFirstNames.push_back(ime);
		// TODO: попуните studentLastNames са презименима
		studentLastNames.push_back(prezime);
		// TODO: studentIndexNums са бројевима индекса
		studentIndexNums.push_back(brojIndeksa);
		
	} while (inputFile.eof() == false);

	inputFile.close();

	return true;
}


void printStudentLastNames()
{
	// TODO: имплементирати испис презимена студената
	for (auto i : studentLastNames)
		cout << i << endl;
}


void printStudentIndexNums()
{
	// штампа на екран студентске индексе али тако да исписује само сваки трећи индекс
	// TODO: имплементирати
	vector<int>::iterator it;
	for (it = studentIndexNums.begin(); it != studentIndexNums.end(); it += 3)
		cout << *it << endl;
}


void printStudentNamesAndIndexNums()
{
	// штампа на екран име студента праћено презименом, па бројем индекса

	// користити информације у studentFirstNames, studentLastNames и studentIndexNums
	// TODO: имплементирати
	list<string>::iterator itn, itl;
	vector<int>::iterator iti;
	for (itn = studentFirstNames.begin(), itl = studentLastNames.begin(), iti = studentIndexNums.begin(); itn != studentFirstNames.end(); itn++, itl++, iti++)
		cout << "Ime " << *itn << " Prezime " << *itl << " Indeks " << *iti << endl;

}


void addStudent()
{
	string studentsName = "Marko Kraljevic";
	string ime = "Marko", prezime = "Kraljevic";
	int studentsIndexNum = 54321;
	list<string>::iterator itn, itl;
	vector<int>::iterator iti;
	// TODO: додати студента Краљевића Марка два места пре Малог Радојице (12345)
	for(itn = studentFirstNames.begin(), itl = studentLastNames.begin(), iti = studentIndexNums.begin(); itn != studentFirstNames.end(); itn ++, itl++, iti++)
		if (*itn == "Mali") {
			--itn; --itn;
			--itl; --itl;
			--iti; --iti;
			studentFirstNames.insert(itn, ime);
			studentLastNames.insert(itl, prezime);
			studentIndexNums.insert(iti, studentsIndexNum);
			break;
		}

}


void makeIndexToNameMap()
{
	// TODO: направити мапу пресликавања бројева индекса на имена и презимена
	// Име и презиме треба бити једна вредност типа string настала надовезивањем имена на презиме са размаком између
	list<string>::iterator itn, itl;
	vector<int>::iterator iti;
	for (itn = studentFirstNames.begin(), itl = studentLastNames.begin(), iti = studentIndexNums.begin(); itn != studentFirstNames.end(); itn++, itl++, iti++)
		studentIndexToNameMap.insert({ *iti, (*itn + " " + *itl) });
}


void printIndexToNameMap()
{
	// TODO: одшампати на екран садржај IndexToName мапе
	map<int, string>::iterator it;
	for (it = studentIndexToNameMap.begin(); it != studentIndexToNameMap.end(); it++) 
		cout << studentIndexToNameMap[it->first] << endl;
}


void printDesiredIndex(int x)
{
	// TODO: наћи име студента у мапи на основу броја индекса, и одшампати име на екран
	// претпоставити да је број индекса увек валидан
	cout << "Student " << studentIndexToNameMap[x] << endl;
}


void makeNameToIndexMap()
{
	// TODO: направити мапу пресликавања индекса на имена и презимена. 
	// Име и презиме треба бити једна вредност типа string настала надовезивањем имена на презиме са размаком између
	list<string>::iterator itn, itl;
	vector<int>::iterator iti;
	for (itn = studentFirstNames.begin(), itl = studentLastNames.begin(), iti = studentIndexNums.begin(); itn != studentFirstNames.end(); itn++, itl++, iti++)
		studentNameToIndexMap.insert({ (*itn + " " + *itl), *iti });
}


void updateDesiredName(string name, int x)
{
	// TODO: Уколико постоји студент са датим именом променити његову вредност индекса у мапи на прослеђену вредност
	// Након тога исписати име и нови број индекса
	if (studentNameToIndexMap.find(name) != studentNameToIndexMap.end()) {
		studentNameToIndexMap[name] = x;
		cout << "Novo " << name << " " << x << endl;
	}
}


void printSpecial()
{
	// TODO: коришћењем итератора проћи кроз целу мапу studentIndexToNameMap
	// и исписати на екран парове индекс и име_презиме студената, за све студенте
	// са парним бројем индекса, потом исписати и за сутденте са непарним бројем индекса
	// али у обрнутом редоследу. За првог и последњег студента из мапе исписати само име и презиме.
	map<int, string>::iterator it;
	map<int, string>::const_iterator last = studentIndexToNameMap.end()--;
	map<int, string>::reverse_iterator ti;
	for (it = studentIndexToNameMap.begin(); it != studentIndexToNameMap.end(); it++) {
		if (it == studentIndexToNameMap.begin()) {
			cout << "Ime " << studentIndexToNameMap[it->first] << " Prezime " << studentIndexToNameMap[it->first] << endl;
			continue;
		}
		if (it->first % 2 == 0)
			cout << "Indeks " << it->first << " Ime_Prezime " << it->second << endl;
	}


	for (ti = studentIndexToNameMap.rbegin(); ti != studentIndexToNameMap.rend(); ti++) {
		if (ti == studentIndexToNameMap.rbegin()) {
			cout << "Ime " << studentIndexToNameMap[ti->first] << " Prezime " << studentIndexToNameMap[ti->first] << endl;
			continue;
		}
		if (ti->first % 2 != 0)
			cout << "Indeks " << ti->first << " Ime_Prezime " << ti->second << endl;
	}
}


void replace()
{
	// TODO: коришћењем метода знаковног низа у задатој реченици заменити зарезе размацима
	string str = "Sve,zareze,izmedju,reci,zameniti,razmacima";

	cout << endl << "Recenica koju treba prepraviti je:";
	cout << endl << str << endl;

	// TODO: имплементирати замену
	char i = str.find_first_of(',');
	while (i != string::npos) {
		str[i] = ' ';
		i = str.find_first_of(',', i + 1);
	}

	cout << endl << "Ispravljena recenica:";
	cout << endl << str << endl;
}

void palindrom(string str)
{
	// TODO: коришћењем метода знаковног низа проверити да ли је прослеђена реченица палиндром
	// приликом провере занемарити размаке 
	string::iterator it;
	string tmpstr = str;
	
	for (it = tmpstr.begin(); it != tmpstr.end(); it++) {
		if (*it == ' ') {
			tmpstr.erase(it);
			continue;
		}
		if (*it < 97)
			*it += 32;
	}

	cout << endl << "Recenica:";
	cout << endl << str << endl;

	const char* i = tmpstr.c_str();
	const char* j = tmpstr.c_str() + tmpstr.size() - 1;
	while (i < j) {
		if (*i != *j) {
			cout << " Nije palindrom" << endl;
			return;
		}
		i++;
		j--;
	}
	cout << " Jeste palindrom";
}
