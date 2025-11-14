#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Hàm heapify để duy trì max-heap
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

// Heap Sort có in từng bước
void heapSort(vector<int>& a) {
    int n = a.size();

    cout << "Mang ban dau: ";
    printArray(a);
    cout << "- Xay dung max heap:\n";

    // 1. Xây dựng max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    cout << "+ Heap sau khi xay dung: ";
    printArray(a);
    cout << endl;

    // 2. Trích dần phần tử lớn nhất
    for (int i = n - 1; i > 0; i--) {
        cout << "- Buoc " << (n - i) << ": Doi " << a[0]
            << " (dinh) voi " << a[i] << " (cuoi), thu nho heap:\n";

        swap(a[0], a[i]);

        cout << "+ Mang: ";
        printArray(a);

        heapify(a, i, 0);

        cout << "+ Heapify lai: ";
        printArray(a);
        cout << endl;
    }
}

int main() {
    vector<int> a = { 5, 1, 8, 3, 2, 7 };

    heapSort(a);

    cout << "Mang da sap xep tang dan: ";
    printArray(a);

    return 0;
}
