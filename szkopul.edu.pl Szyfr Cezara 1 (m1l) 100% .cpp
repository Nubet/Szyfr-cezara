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


int main() {
    int klucz, ile;

    cin>>ile;
    cin>>klucz;
    if(klucz > 26)
        klucz = klucz % 26;

    string slowa[ile];
    for(int i = 0; i <= ile-1; i++)
       cin>>slowa[i];

    //cin>>napis;

    for(int i = 0; i <= ile-1; i++){
        string slowo = slowa[i];
        for(int i=0; i<=slowo.length()-1; i++){
                char litera = toupper(slowo[i]);
                cout << szyfruj_litere(litera,klucz);
        }
        cout << endl;
    }


}
