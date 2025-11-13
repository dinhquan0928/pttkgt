#include <iostream>
using namespace std;

// Hàm in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm vun đống (heapify)
void heapify(int arr[], int n, int i) {
    int largest = i;       // gốc
    int left = 2 * i + 1;  // con trái
    int right = 2 * i + 2; // con phải

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu gốc không phải lớn nhất thì đổi chỗ
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // đệ quy để đảm bảo cây con vẫn là heap
    }
}

// Hàm Heap Sort chính
void heapSort(int arr[], int n) {
    // Bước 1: Xây dựng Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    cout << "Sau khi tao Max Heap: ";
    printArray(arr, n);

    // Bước 2: Trích phần tử lớn nhất và đưa về cuối
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // đổi chỗ gốc với phần tử cuối
        cout << "Hoan doi " << arr[i] << " len cuoi: ";
        printArray(arr, n);

        heapify(arr, i, 0); // heapify lại phần còn lại
        cout << "Sau khi heapify lai: ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = { 54, 23, 28, 17, 37, 39, 42, 70, 61 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "\nMang sau khi sap xep tang dan: ";
    printArray(arr, n);

    return 0;
}
