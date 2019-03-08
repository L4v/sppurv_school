#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

// помоћне функције
static bool loadStudents(string fileName);
static void printStudentNames();
static void printStudentIndexNums();
static void printStudentNamesAndIndexNums();
static void addStudent();
static void makeIndexToNameMap();
static void printIndexToNameMap();
static void printDesiredIndex(int x);
static void makeNameToIndexMap();
static void printDesiredName(string name);
static void printSpecial();
static void replace();

// глобалне променљиве
static list<string> studentNames;
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

	printStudentNames();
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

	string name;
	string surname;
	name = argv[2]; surname = argv[3];

	string fullName = name + " " + surname;

	printDesiredName(fullName);

	// Додатни
	printSpecial();

	replace();

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

		studentNames.push_back(ime + " " + prezime);
		studentIndexNums.push_back(brojIndeksa);

	} while (inputFile.eof() == false);

	inputFile.close();

	return true;
}


void printStudentNames()
{
	for(auto i : studentNames)
	    cout << i << endl;
}


void printStudentIndexNums()
{
	// штампа на екран студентске индексе али у обрнутом редоследу
	vector<int>::reverse_iterator it;
	for(it = studentIndexNums.rbegin(); it != studentIndexNums.rend(); it ++)
        cout << *it << endl;
}


void printStudentNamesAndIndexNums()
{
	// штампа на екран име студента праћено бројем индекса

	// користити информације у studentNames и studentIndexNums
	for(auto i : studentNames)
	    cout << "Student: " << i << " Indeks: " << studentNameToIndexMap[i] << endl;
}


void addStudent() {
    string studentsName = "Marko Kraljevic";
    int studentsIndexNum = 54321;

    // TODO: додати студента Краљевића Марка тачно иза Малог Радојице (12345)
    list<string>::iterator itl;
    vector<int>::iterator itv;
    for (itl = studentNames.begin(); itl != studentNames.end(); itl++)
        if (*itl == "Mali Radojica") {
            studentNames.insert(--itl, studentsName);
            break;
        }

    for (itv = studentIndexNums.begin(); itv != studentIndexNums.end(); itv++)
        if (*itv == 12345) {
            studentIndexNums.insert(--itv, studentsIndexNum);
            break;
        }
}

void makeIndexToNameMap()
{
	vector<int>::iterator itv;
	list<string>::iterator itl;
	for(itv = studentIndexNums.begin(), itl = studentNames.begin(); itv != studentIndexNums.end(); itv ++, itl ++)
	    studentIndexToNameMap.insert({*itv, *itl});

}


void printIndexToNameMap()
{
	map<int, string>::iterator it;
	for(it = studentIndexToNameMap.begin(); it != studentIndexToNameMap.end(); it ++)
		cout << "Indeks " << it->first << " Ime " << it->second << endl;
}


void printDesiredIndex(int x)
{
	// претпоставити да је број индекса увек валидан
	cout << "Student s indeksom " << x << " je " << studentIndexToNameMap[x];
}


void makeNameToIndexMap()
{
	vector<int>::iterator itv;
	list<string>::iterator itl;
	for(itl = studentNames.begin(), itv = studentIndexNums.begin(); itl != studentNames.end(); itl ++, itv ++)
		studentNameToIndexMap.insert({*itl, *itv});
}


void printDesiredName(string name)
{
	// TODO: наћи индекс студента на основу имена, и одшампати индекс на екран
	// претпоставити да је могућ унос невалидног имена
	cout << "Indeks studenta " << (studentNameToIndexMap.find(name) != studentNameToIndexMap.end() ? studentNameToIndexMap.find(name) : "sa tim imenom ne postoji") << endl;
}


void printSpecial()
{
	// TODO: коришћењем итератора проћи кроз целу мапу studentIndexToNameMap
	// и исписати на екран парове индекс и име_презиме студената, за све студенте
	// осим последњег. За последњег студента исписати само име и презиме.
	map<string, int>::const_iterator kraj = studentNameToIndexMap.end()--;
	map<string, int>::iterator it;
	for(it = studentNameToIndexMap.begin(); it != studentNameToIndexMap.end(); it++)

}


void replace()
{
	// TODO: коришћењем метода знаковног низа у задатој реченици заменити зарезе размацима
	string str = "Sve,zareze,izmedju,reci,zameniti,razmacima";

	cout << endl << "Recenica koju treba prepraviti je:";
	cout << endl << str << endl;

	// TODO: имплементирати замену

	cout << endl << "Ispravljena recenica:";
	cout << endl << str << endl;
}
