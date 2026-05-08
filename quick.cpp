#include <iostream>
using namespace std;

int hoarePartition(int A[], int l, int r)
{
    int p = A[l];
    int i = l;
    int j = r + 1;

    while (true)
    {
        do {
            i = i + 1;
        } while (A[i] < p);

        do {
            j = j - 1;
        } while (A[j] > p);

        if (i >= j)
            break;

        swap(A[i], A[j]);
    }

    swap(A[l], A[j]);
    return j;
}

void quickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int s = hoarePartition(A, l, r);
        quickSort(A, l, s - 1);
        quickSort(A, s + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[100];   // simple fixed-size array (beginner friendly)

    cout << "Enter the elements:\n";

    for (int i = 0; i < n; i++)
        cin >> A[i];

    quickSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

