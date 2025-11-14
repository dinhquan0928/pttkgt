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

void mergeSteps(vector<int>& a, int left, int mid, int right) {
    vector<int> L(a.begin() + left, a.begin() + mid + 1);
    vector<int> R(a.begin() + mid + 1, a.begin() + right + 1);

    cout << "\nBuoc 3: Merge hai nua da sap xep\n";
    cout << "Left: ";
    printArray(L);
    cout << "\nRight: ";
    printArray(R);
    cout << "\n";

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < L.size()) a[k++] = L[i++];
    while (j < R.size()) a[k++] = R[j++];

    printArray(a);
    cout << "\n";
}

void mergeSortSteps(vector<int>& a, int left, int right, int depth = 1) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    cout << "\nBuoc 1: Chia mang thanh 2 nua\n";
    cout << "Left: ";
    printArray(vector<int>(a.begin() + left, a.begin() + mid + 1));
    cout << "\nRight: ";
    printArray(vector<int>(a.begin() + mid + 1, a.begin() + right + 1));
    cout << "\n";

    cout << "\nBuoc 2: de quy sap xep tung naa\n";

    // Đệ quy trái
    cout << "• Left → ";
    vector<int> leftPart(a.begin() + left, a.begin() + mid + 1);
    mergeSortSteps(leftPart, 0, leftPart.size() - 1);
    printArray(leftPart);
    cout << "\n";

    // Đệ quy phải
    cout << "• Right → ";
    vector<int> rightPart(a.begin() + mid + 1, a.begin() + right + 1);
    mergeSortSteps(rightPart, 0, rightPart.size() - 1);
    printArray(rightPart);
    cout << "\n";

    // Gộp vào mảng chính
    int i = 0;
    for (int k = left; k <= mid; k++) a[k] = leftPart[i++];
    i = 0;
    for (int k = mid + 1; k <= right; k++) a[k] = rightPart[i++];

    mergeSteps(a, left, mid, right);
}

int main() {
    vector<int> A = { 5, 1, 8, 3, 2, 7 };

    cout << "Mang ban dau:\nA = ";
    printArray(A);
    cout << "\n";

    mergeSortSteps(A, 0, A.size() - 1);

    return 0;
}
