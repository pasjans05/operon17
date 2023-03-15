// operon17.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream plik("pesel.txt");

void MK()
{
	string PESEL;
	int m = 0;
	int k = 0;
	for (int i = 0; i < 200; i++)
	{
		plik >> PESEL;
		if (PESEL[9] == '1' || PESEL[9] == '3' || PESEL[9] == '5' || PESEL[9] == '7' || PESEL[9] == '9') m++;
		else if (PESEL[9] == '0' || PESEL[9] == '2' || PESEL[9] == '4' || PESEL[9] == '6' || PESEL[9] == '8') k++;
	}
	cout << m << " mezczyzn i " << k << " kobiet \n";
	plik.close();
	plik.open("pesel.txt");
}

bool kontrolna(long long int pesel)
{
	int kontr = pesel % 10;
	pesel /= 10;
	int sum = 0;
	int a;
	int b; //waga mnożenia cyfry z numeru PESEL
	for (int i = 0; i < 10; i++)
	{
		a = pesel % 10;
		switch (i % 4)
		{
			case 0:
				b = 3;
				break;
			case 1:
				b = 1;
				break;
			case 2:
				b = 9;
				break;
			case 3:
				b = 7;
				break;
		}
		sum += (a * b)%10;
		pesel /= 10;
	}
	if ((10 - (sum % 10)) == kontr) return true;
	else return false;
}

int wiek(string pesel)
{
	int wiek = 0;
	long long PESEL = stoll(pesel);
	int rocz = PESEL /= 1000000000;
	if (pesel[2] == '8' || pesel[2] == '9') wiek += 100;
	else if (pesel[2] == '2' || pesel[2] == '3') wiek = 22 - rocz;
	else wiek = 22 + 100 - rocz;
	return wiek;
}

int main()
{
	MK();
	string pesel;
	for (int i = 0; i < 200; i++)
	{
		plik >> pesel;
		if (!kontrolna(stoll(pesel))) cout << pesel << endl;
	}
	plik.close();
	plik.open("pesel.txt");
	int a = 0; //grupa wiekowa do 18 lat włącznie
	int b = 0; //grupa wiekowa od 19 do 50 lat
	int c = 0; //grupa wiekowa od 51 do 100 lat
	int d = 0; //grupa wiekowa powwyżej 100 lat
	for (int i = 0; i < 200; i++)
	{
		plik >> pesel;
		if (wiek(pesel) < 19) a++;
		else if (wiek(pesel) > 18 && wiek(pesel) < 51) b++;
		else if (wiek(pesel) > 50 && wiek(pesel) < 101) c++;
		else if (wiek(pesel) > 100) d++;
	}
	cout << "Do 18 lat wlacznie: " << a << endl << "Od 19 do 50 lat: " << b << endl << "Od 51 do 100 lat: " << c << endl << "Powyzej 100 lat: " << d << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
