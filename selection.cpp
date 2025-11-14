#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<int> a = { 5, 1, 4, 2, 8 };
    int n = a.size();

    cout << "Gia su ta co mang:\n\na = ";
    printArray(a);
    cout << "\n\n";

    for (int i = 0; i < n - 1; i++) {

        cout << "Buoc " << i + 1 << ": i = " << i << "\n\n";

        int minPos = i;

        // tìm nhỏ nhất trong đoạn
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minPos]) {
                minPos = j;
            }
        }

        cout << "Tim phan tu nho nhat trong ["
            << i << ".." << n - 1 << "] → nho nhat la "
            << a[minPos] << " (vi tri " << minPos << ")\n\n";

        if (minPos != i) {
            cout << "Doi a[" << i << "] ↔ a[" << minPos << "]\n";
            swap(a[i], a[minPos]);
            cout << "→ Mang: ";
            printArray(a);
            cout << "\n\n";
        }
        else {
            cout << "→ khong doi.\n\n";
        }
    }

    return 0;
}
