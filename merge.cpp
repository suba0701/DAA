#include<iostream>
using namespace std;
void Merge(int B[], int C[], int A[], int p, int q)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < p && j < q)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i = i + 1;
        }
        else
        {
            A[k] = C[j];
            j = j + 1;
        }
        k = k + 1;
    }

    if (i == p)
    {
        while (j < q)
        {
            A[k] = C[j];
            j = j + 1;
            k = k + 1;
        }
    }
    else
    {
        while (i < p)
        {
            A[k] = B[i];
            i = i + 1;
            k = k + 1;
        }
    }
}

/*
ALGORITHM MergeSort(A[0..n-1])
*/
void MergeSort(int A[], int n)
{
    if (n > 1)
    {
        int B[n / 2];
        int C[n - n / 2];

        // copy A[0..n/2-1] into B
        for (int i = 0; i < n / 2; i++)
            B[i] = A[i];

        // copy A[n/2..n-1] into C
        for (int i = n / 2; i < n; i++)
            C[i - n / 2] = A[i];

        MergeSort(B, n / 2);
        MergeSort(C, n - n / 2);
        Merge(B, C, A, n / 2, n - n / 2);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    MergeSort(A, n);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

