#include <iostream>
using namespace std;

// Function to print the array (1-based indexing)
void displayArray(int H[], int n) {
    for(int i = 1; i <= n; i++)
        cout << H[i] << " ";
    cout << endl;
}

void heapSort(int H[], int n) {
    int i, k, j, v;
    bool heap;

    // --- PHASE 1: BUILD MAX HEAP ---
    for(i = n/2; i >= 1; i--) {
        k = i;
        v = H[k];
        heap = false;

        while(!heap && 2*k <= n) {
            j = 2*k;
            if(j < n && H[j] < H[j+1])
                j = j + 1;

            if(v >= H[j])
                heap = true;
            else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }

    // Display the Max Heap after building it
    cout << "Maximum Heap: ";
    displayArray(H, n);

    // --- PHASE 2: EXTRACT ELEMENTS (SORTING) ---
    for(i = n; i >= 2; i--) {
        swap(H[1], H[i]);
        k = 1;
        v = H[k];
        heap = false;

        while(!heap && 2*k <= i-1) {
            j = 2*k;
            if(j < i-1 && H[j] < H[j+1])
                j = j + 1;

            if(v >= H[j])
                heap = true;
            else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int H[n+1];
    cout << "Enter " << n << " elements:\n";
    for(int i = 1; i <= n; i++)
        cin >> H[i];

    heapSort(H, n);

    cout << "Sorted array: ";
    displayArray(H, n);

    return 0;
}
