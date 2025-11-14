#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> A = { 5, 1, 8, 3, 2, 7 };
    int n = A.size();

    cout << "Mang ban dau: ";
    printArray(A);
    cout << endl;

    // Dãy gap đơn giản: n/2 → 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        cout << "gap = " << gap << endl;

        // Duyệt từng nhóm theo gap
        for (int start = 0; start < gap; start++) {
            cout << "  Nhom " << (start + 1) << ": ";

            // In phần tử nhóm trước khi sắp xếp
            vector<int> group;
            for (int i = start; i < n; i += gap)
                group.push_back(A[i]);

            for (int x : group) cout << x << " ";
            cout << " -> ";

            // Sắp xếp nhóm bằng insertion sort
            for (int i = start + gap; i < n; i += gap) {
                int key = A[i];
                int j = i - gap;
                while (j >= 0 && A[j] > key) {
                    A[j + gap] = A[j];
                    j -= gap;
                }
                A[j + gap] = key;
            }

            // In nhóm sau khi sắp xếp
            group.clear();
            for (int i = start; i < n; i += gap)
                group.push_back(A[i]);
            for (int x : group) cout << x << " ";
            cout << endl;
        }

        cout << "Mang sau buoc gap=" << gap << ": ";
        printArray(A);
        cout << endl;
    }

    cout << "Mang duoc sap xep hoan chinh: ";
    printArray(A);
    return 0;
}