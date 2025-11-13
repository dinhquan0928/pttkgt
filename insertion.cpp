#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    cout << "Mang ban dau: ";
    printArray(arr);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Buoc " << i << ": ";
        printArray(arr);
    }

    cout << "Mang sau khi sap xep: ";
    printArray(arr);
}

int main() {
    vector<int> arr = { 7, 6, 2, 1, 4 };
    insertionSort(arr);
    return 0;
}