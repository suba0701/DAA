#include <iostream>
using namespace std;
int getLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}
void displayShiftTable(char pattern[], int m, int table[]) {
    cout << "\n--- Shift Table ---" << endl;
    cout << "Char  |  Shift" << endl;
    cout << "--------------" << endl;

    bool seen[256] = {false};
    for (int i = 0; i < m; i++) {
        unsigned char c = (unsigned char)pattern[i];
        if (!seen[c]) {
            cout << "  " << (char)c << "   |    " << table[c] << endl;
            seen[c] = true;
        }
    }
     cout << "Other |    " << m << endl;
    cout << "------------------\n" << endl;
}
void shiftTable(char pattern[], int m, int table[]) {
    for (int i = 0; i < 256; i++)
        table[i] = m;
    for (int i = 0; i < m - 1; i++)
        table[(unsigned char)pattern[i]] = m - 1 - i;
    displayShiftTable(pattern, m, table);
}
int horspool(char text[], char pattern[]) {
    int m = getLength(pattern);
    int n = getLength(text);
    int table[256];
    if (m > n) return -1;
    shiftTable(pattern, m, table);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if (k == m)
            return i - m + 1;
        i += table[(unsigned char)text[i]];
    }

    return -1;
}
int main() {
    char text[200], pattern[100];

    cout << "ENTER THE TEXT: ";
    cin.getline(text, 200);

    cout << "ENTER THE PATTERN: ";
    cin.getline(pattern, 100);

    int pos = horspool(text, pattern);

    if (pos >= 0)
        cout << "PATTERN FOUND AT POSITION: " << pos << endl;
    else
        cout << "PATTERN NOT FOUND" << endl;

    return 0;
}