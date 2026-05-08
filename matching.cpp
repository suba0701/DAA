#include <iostream>
using namespace std;

int main()
{

    string t, p;

    cout << "Enter the text: ";
    getline(cin,t);

    cout << "Enter the pattern: ";
    getline(cin,p);

    int n = 0, m = 0;

    while (t[n] != '\0')
        n++;

    while (p[m] != '\0')
        m++;

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;

        while (j < m && t[i + j] == p[j])
            j++;

        if (j == m)
        {
            cout << "\nText    : " << t << endl;
            cout << "Pattern : ";

            // spaces for alignment
            for (int k = 0; k < i; k++)
                cout << " ";

            cout << p << endl;

            cout << "\nPattern found from index "
                 << i << " to " << (i + m - 1) << endl;

            return 0;
        }
    }

    cout << "Pattern not found" << endl;
    return 0;
}
