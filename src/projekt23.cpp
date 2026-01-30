#include <print>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

int main() {

    ifstream file("dane.txt");
    if (!file.is_open()) {
        println("Nie mozna otworzyc pliku dane.txt");
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    int rows = lines.size();
    int cols = 0;

    for (auto &s : lines)
        cols = max(cols, (int)s.size());

    for (auto &s : lines)
        if ((int)s.size() < cols)
            s += string(cols - s.size(), ' ');

    long long Total = 0;

    int c = 0;
    while (c < cols) {

        bool empty = true;
        for (int r = 0; r < rows; r++)
            if (lines[r][c] != ' ')
                empty = false;

        if (empty) {
            c++;
            continue;
        }

        vector<long long> nums;
        char op = '?';

        int start = c;

        while (c < cols) {
            bool colEmpty = true;
            for (int r = 0; r < rows; r++)
                if (lines[r][c] != ' ')
                    colEmpty = false;

            if (colEmpty)
                break;
            c++;
        }

        int end = c;

        for (int r = 0; r < rows; r++) {
            string num = "";

            for (int x = start; x < end; x++) {
                char ch = lines[r][x];

                if (isdigit(ch))
                    num += ch;
                else if (ch == '+' || ch == '*')
                    op = ch;
            }

            if (!num.empty())
                nums.push_back(stoll(num));
        }

        long long val;

        if (op == '*')
        val = 1;
        else
        val = 0;

        for (long long x : nums) {
            if (op == '*') val *= x;
            else val += x;
        }

        Total += val;
    }

    println("Wynik: {}", Total);
    return 0;
}
