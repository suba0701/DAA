#include <iostream>
#include <cmath>
using namespace std;

int x[100];
int countSol = 0;

// Check safe position
bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

// Print board (ONLY Q and .)
void printBoard(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// N-Queens using backtracking
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {

        if (Place(k, i)) {
            x[k] = i;

            cout << "Placed Q at Row " << k << " Column " << i << endl;
            printBoard(n);

            if (k == n) {
                countSol++;
                cout << "===== SOLUTION " << countSol << " =====\n";
                printBoard(n);
            } else {
                NQueens(k + 1, n);
            }

            // Backtracking
            x[k] = 0;
        }
    }
}

// Main
int main() {
    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    NQueens(1, n);

    if (countSol == 0)
        cout << "No solution exists";

    return 0;
}
