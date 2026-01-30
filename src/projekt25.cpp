
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <print>
using namespace std;

int main() 
    {

    ifstream file("dane.txt");
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc dane.txt\n";
        return 1;
    }

    string line;
    long long total = 0;

    while (getline(file, line)) {

        
        int pos = line.find(':');
        line = line.substr(pos + 1);

        
        int bar = line.find('|');
        string left = line.substr(0, bar);
        string right = line.substr(bar + 1);

        
        set<int> winning;

        stringstream ss(left);
        int x;
        while (ss >> x)
            winning.insert(x);
        int matches = 0;
        stringstream ss2(right);

        while (ss2 >> x) {
            if (winning.count(x))
                matches++;
        }

        
        if (matches > 0) {

    long long points = 1;

    for (int i = 0; i < matches - 1; i++) {
        points *= 2;
    }

    total += points;
}
    }

    println("wynik to :{}",total);
    return 0;
}

   
