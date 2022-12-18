#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Cours { I = 1, II, III, IV, V };
string KursStr[] = { "I", "II", "III", "IV", "V" };
struct Student
{
	string prizv;
	string cpecialnist;
	Cours kurs;
	union
	{
		int math;
		int physics;
		int inform;
	};
};
void Create(Student* p, char* fname, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);

int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Enter N: "; cin >> N;
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;


	Student* p = new Student[N];
	Create(p, fname, N);
	Print(p, N);
	double proc = LineSearch(p, N);
	cout << proc << "%" << endl;
	return 0;
}
void Create(Student* p, char* fname, const int N)
{
	int kurs;
	for (int i = 0; i < N; i++)
	{
		ofstream fout(fname, ios::binary);
		string s;
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Prizv: "; cin >> p[i].prizv; //getline(cin, s);
		cout << " Cpecialnist : "; cin >> p[i].cpecialnist; //getline(cin, s);
		cout << " Cours (0 - I, 1 - II, 2 - III, 3 - IV, 4 - V): "; getline(cin, s);
		cin >> kurs; getline(cin, s);
		p[i].kurs = (Cours)kurs;
		switch (p[i].kurs)
		{
		case I:
		case II:
		case III:
		case IV:
		case V:
			cout << " Math : "; cin >> p[i].math;
			//break;
			cout << " Physics : "; cin >> p[i].physics;
			//break;
			cout << " Inform : "; cin >> p[i].inform;
			break;
		}
		for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
			fout.write((char*)&s[i], sizeof(s[i]));//записуємо рядок у файл
		cout << endl;
		
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| # | Prizv | Cpecialnist | Cours | Math | Phisics | Inform |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(6) << left << p[i].prizv
			<< "| " << setw(11) << right << p[i].cpecialnist << " "
			<< "| " << setw(6) << left << KursStr[p[i].kurs];
		switch (p[i].kurs)
		{
		case I:
		case II:
		case III:
		case IV:
		case V:
			cout << "| " << setw(4) << setprecision(2) << fixed << right
				<< p[i].math << " |" << setw(2) << right

				<< setw(8) << setprecision(2) << fixed << right
				<< p[i].physics << " |" << setw(13) << right <<
				setw(7) << setprecision(2) << fixed << right
				<< p[i].inform << " |" << setw(0) << right << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	int m = 0, ph = 0, in = 0, k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math >= 3)
		{
			m++;
			cout << m
				<< " " << "math" << endl;
		}
		else cout << m
			<< " " << "math" << endl;

		if (p[i].physics >= 3)
		{
			ph++;
			cout << ph
				<< " " << "physics" << endl;
		}
		else cout << ph
			<< " " << "physics" << endl;
		if (p[i].inform >= 3)
		{
			in++;
			cout << in
				<< " " << "inform" << endl;
		}
		else cout << in
			<< " " << "inform" << endl;
		if (p[i].math >= 5 && p[i].physics >= 5)
		{
			k++;
		}
	}
	if (k != 0)
	{
		return 100.0 * k / N;
	}
	else
		return 0;
}

