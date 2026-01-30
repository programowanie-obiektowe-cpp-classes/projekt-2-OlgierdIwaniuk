#include <iostream>
#include <fstream>
#include <string>
#include <print>
using namespace std;

int main() {

    ifstream file("dane.txt");
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku dane.txt\n";
        return 1;
    }

    string line;
    long long  suma=0;
    
    while (getline(file, line)) {
        auto element=line.begin();
        long long num = 0;
        int c=11;
        for(int k=0; k<c+1; k++)
        {
          auto f = max_element(element,line.end()+k-c);
          element=f+1;
          num*=10;
          num+=(*f-'0');
        }
      
        suma+=num;
    }
        
    println("wynik {}",suma);
    return 0;
}
