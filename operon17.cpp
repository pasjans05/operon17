// operon17.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
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
}

int main()
{
	MK();
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
