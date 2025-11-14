#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

// Hàm phân hoạch có in từng bước
int partition(vector<int>& a, int left, int right, int level) {
    int pivot = a[right];

    cout << string(level * 4, ' ')
        << "Chon pivot = " << pivot << " tai vi tri " << right << endl;

    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);

    cout << string(level * 4, ' ')
        << "Sau khi phan hoach: ";
    printArray(a);

    cout << string(level * 4, ' ')
        << "Pivot dat tai vi tri: " << i + 1 << endl << endl;

    return i + 1;
}

// Quick Sort có in từng bước
void quickSort(vector<int>& a, int left, int right, int level = 0) {
    if (left < right) {
        cout << string(level * 4, ' ')
            << "Sap xep doan [" << left << ", " << right << "]" << endl;

        int pi = partition(a, left, right, level);

        quickSort(a, left, pi - 1, level + 1);
        quickSort(a, pi + 1, right, level + 1);
    }
}

int main() {
    vector<int> a = { 5, 1, 8, 3, 2, 7 };

    cout << "Mang ban dau: ";
    printArray(a);

    quickSort(a, 0, a.size() - 1);

    cout << "Mang da sap xep: ";
    printArray(a);

    return 0;
}
