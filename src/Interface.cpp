#include "Interface.h"

#include <sstream>
#include <string.h>
#include <iostream>




bool Interface::checkEmptyString(string s)
{
    // Odrzuca pusty string na wejściu
    int i = 0;
    do
    {
        if( s[i] == *"" || s.length() == 0 )
        {
            cout << "Malformed entry please, try again." << endl;
            return true; 
        }
        i++;

    } while(i < s.length());
    return false;
}

vector<string> Interface::divideString(string s)
{
    vector<string> v;
    string d = " ", word;
    size_t pos;

    // Dodawanie elementów stringa co spacja
    while((pos = s.find(d)) != string::npos)
    {
        // Tworzenie podstringa z jednym elementem bez spacji
        word = s.substr(0, pos);

        // Dodawanie podstringów gdy nie są spacjami
        if (word != " " && word != "")
        {
            v.push_back(word);
        }

        // Usuwanie dodanych elementów
        s.erase(0, pos + d.length());
    }
    // Dodawanie ostatniego elementu który nie ma po sobie spacji 
    if(s.length() != 0) v.push_back(s);

    return v;
}

vector<string> Interface::getInput()
{
    int i = 0;
    string s;
    do
    {
        cout << "Your input: ";
        getline(cin, s);
        i++;
    } while (i < 5 && this -> checkEmptyString(s));

    vector<string> v = this -> divideString(s);
    return v;
}

int Interface::interface()
{
    this -> getInput();
    return 0;
}

