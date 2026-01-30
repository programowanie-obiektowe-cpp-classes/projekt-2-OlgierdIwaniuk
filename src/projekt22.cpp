
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <print>
using namespace std;

vector<char> wspolne_litery(const string& a, const string& b) {

    set<char> s;
    vector<char> wynik;

    
    for (char c : a)
        s.insert(c);

    
    for (char c : b) {
        if (s.count(c)) {
            wynik.push_back(c);
            s.erase(c); 
        }
    }

    return wynik;
}
int punkty(char c) {

    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;

    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
}
int main() {

    ifstream plik("dane.txt");
    int wynik1=0;
    if (!plik.is_open()) {
        println( "Nie mozna otworzyc pliku\n");
        return 1;
    }

    vector<pair<string, string>> dane;

    string linia;

    while (getline(plik, linia)) {

        int polowa = linia.length() / 2;

        string lewa  = linia.substr(0, polowa);
        string prawa = linia.substr(polowa);

        dane.push_back({lewa, prawa});
    }

    
    for (auto& p : dane) {

    auto wspolne = wspolne_litery(p.first, p.second);
    for (char c : wspolne)
        {
        int wynik = punkty(c);
        wynik1 = wynik+wynik1;
        }
    
    
}
    println("suma punktów {}",wynik1);

    return 0;
}
