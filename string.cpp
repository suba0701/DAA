#include <iostream>

using namespace std;

int main() {
    char text[500], pattern[100];

    cout << "Enter the Text: ";
    cin.getline(text, 500);
    cout << "Enter the Pattern: ";
    cin.getline(pattern, 100);

    int n = 0; while (text[n] != '\0') n++;
    int m = 0; while (pattern[m] != '\0') m++;

    // 1. LOOKUP TABLE
    cout << "\n SHIFT TABLE " << endl;
    cout << "Char | Shift" << endl;
    for (int j = 0; j < m; j++)
    {
        bool already = false;
        for (int p = 0; p < j; p++) if (pattern[p] == pattern[j]) already = true;
        if (!already)
        {
            int s = m;
            for (int k = 0; k <= m - 2; k++)
            {
                if (pattern[k] == pattern[j]) s = m - 1 - k;
            }
            cout << "  " << pattern[j] << "  |   " << s << endl;
        }
    }
    cout << "Other|   " << m << endl;


    cout << "\n SEARCHING" << endl;
    cout << text << endl;

    int i = m - 1;
    while (i < n)
    {

        for (int s = 0; s < (i - m + 1); s++) cout << " ";

        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
        {
            k++;
        }

        if (k == m)
        {
            cout << pattern << " <- MATCH!" << endl;
            cout << "\nPattern found at index: " << (i - m + 1) << endl;
            return 0;
        }
        else
        {
            int sVal = m;

            for (int j = m - 2; j >= 0; j--)
            {
                if (pattern[j] == text[i])
                {
                    sVal = m - 1 - j;
                    break;
                }
            }
            cout << pattern << " (Shift: " << sVal << ")" << endl;
            i = i + sVal;
        }
    }
    cout << "\nPattern not found." << endl;
    return 0;
}

