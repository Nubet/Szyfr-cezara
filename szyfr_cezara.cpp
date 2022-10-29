#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int na_jakiej_pozycji(char litera, char alfabet[]){
    	int pozycja = 0;
		for(int i = 0; i < 26; i++){
    		if(alfabet[i] == litera)
    			return pozycja;
			else 
				pozycja++;
		}
}
char szyfruj_litere(char litera, int klucz){
	char alfabet_podstawowy[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
	char znak_zaszyfrowany;
	int pozycja_podanej_litery_w_alfabecie = na_jakiej_pozycji(litera, alfabet_podstawowy);
	
    if(pozycja_podanej_litery_w_alfabecie+klucz <= 25)
        znak_zaszyfrowany = alfabet_podstawowy[pozycja_podanej_litery_w_alfabecie+klucz];
    else
        znak_zaszyfrowany = alfabet_podstawowy[klucz-(26-pozycja_podanej_litery_w_alfabecie)];
            
    return znak_zaszyfrowany;  
}
char odszyfruj_litere(char litera, int klucz){
	char alfabet_podstawowy[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char alfabet_szyfrowany[26];
    
    //Tworzenie alfabetu przesunietego o klucz
     for(int i = 0; i <= 25; i++){//alfabet lacinski ma 26 znakow
        if(i+klucz <= 25)
            alfabet_szyfrowany[i] = alfabet_podstawowy[i+klucz];
        else
            alfabet_szyfrowany[i] = alfabet_podstawowy[klucz-(26-i)]; // jesli np uzytkownik podal klucz 3 a jestesmy na literze 'X' tym samym i = 23 a dla 'Z' odpowiada 25 to 23+3 wyjdzie poza zakres wiec musimy "zaczac od  nowa" czyli tyle ile miesci sie odejmujemy od i a tyle ile sie nie mieci dodajemy ale od 0 elementu czyli literki 'A' (25 - i -> 25 - 23 = 2 czyli tyle przesuniec jeszcze zmiesci sie nie wychodzac poza alfabet czyli jesli od klucza odejmniemy ten wynik to otrzymamy wlasciwy element tablicy)
    }
   

	char znak_odszyfrowany;
	
	int pozycja_podanej_litery_w_alfabecie = na_jakiej_pozycji(litera, alfabet_szyfrowany);
	//cout<< "Pozycja w alfabecie przesunietym litery: " << litera << " to " <<  pozycja_podanej_litery_w_alfabecie << endl;
    if(pozycja_podanej_litery_w_alfabecie-klucz >= 0)
        znak_odszyfrowany = alfabet_szyfrowany[pozycja_podanej_litery_w_alfabecie-klucz];
    else
        znak_odszyfrowany = alfabet_szyfrowany[26-klucz+pozycja_podanej_litery_w_alfabecie]; // tyle ile wynosi klucz tyle ostatnich liter bedzie mialo juz przesuniecie na metodzie liczenia od poczatku wiec jesli od 26 odejmniemy klucz czyli np: 3 otrzymamy poprawna pozycje dla litery A. Wiec jak uzyskac dla np b? trzeba zastanowic ile razy w lewo jestesmy w stanie przejsc w przypadku B tylko raz matemtycznie opiszemy to dodajac pozycje litery -> A jest na pozycji zerowej wiec wynik sie nie zmieni
	
    return znak_odszyfrowany;  
}

int main() {
	string napis;
    int klucz;
	char wybor;
	
	while(true)
	{
		cout<< "============================================ " << endl;
		cout << "Wprowadz 'S' jesli chcesz zaszyfrowac zdanie " << endl;
		cout << "Wprowadz 'O' jesli chcesz odszyfrowac zdanie " << endl;
		cout << "Wybor: ";
		cin>>wybor;
		wybor = toupper(wybor);
		
		switch(wybor)
			{
				case 'S':
					 system("cls");
					 cin.ignore();
					 cout << "Wprowadz zdanie/slowo do zaszyfrowania: " << endl;
					 getline(cin, napis);
					 cout << "Podaj klucz (przesuniecie): ";
					 cin>>klucz;
					 if(klucz <= 0 || klucz >= 26){
					 	cout << "Klucz(przesuniecie) musi byc liczba wieksza od zera " << endl ;
					 	break;
					 }	
		
					 cout << "Zaszyfrowane zdanie: ";
					 for(int i=0; i<=napis.length()-1; i++)
					 {	
					   	if(!isspace(napis[i])){ // Sprawdzanie czy i element tablicy nie jest przypadkiem spacja no bo jak zaszyfrowac spacje?
						        char litera = toupper(napis[i]);
								cout << szyfruj_litere(litera,klucz);
						}
						else 
							cout << " ";	
					}
					cout << endl;
					break;
					
				case 'O':	
					system("cls");
				    cin.ignore();
					cout << "Wprowadz zdanie/slowo do odszyfrowania: " << endl;
				    getline(cin, napis);
				    cout << "Podaj klucz (przesuniecie): ";
				    cin>>klucz;
				    if(klucz <= 0 )	{
					 	cout << "Klucz(przesuniecie) musi byc liczba wieksza od zera " << endl ;
					 	break;
					 }	
				    cout << "Odszyfrowane zdanie: ";
				    for(int i=0; i<=napis.length()-1; i++)
					{	
				    	if(!isspace(napis[i])){ 
					    	char litera = toupper(napis[i]);
							cout << odszyfruj_litere(litera,klucz);
						}
						else 
							cout << " ";	
					}
					cout << endl;
					break;
					
				default:
					cout << "Podales bledny znak! " << endl;
					break;
		
			}
   }
    
}