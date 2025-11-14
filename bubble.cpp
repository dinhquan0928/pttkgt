#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& a) {
    cout << "[";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i < a.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    vector<int> a = { 5, 1, 4, 2, 8 };
    int n = a.size();

    cout << "A = [5, 1, 4, 2, 8]\n\n";

    for (int i = 0; i < n - 1; i++) {

        cout << "i = " << i << "\n";

        for (int j = 0; j < n - 1 - i; j++) {

            cout << "(" << a[j] << ">" << a[j + 1] << ")? ";

            if (a[j] > a[j + 1]) {
                cout << "doi → ";
                swap(a[j], a[j + 1]);
                printArray(a);
                cout << "; ";
            }
            else {
                cout << "khong; ";
            }
        }

        cout << "\nKet qua sau luot i: ";
        printArray(a);
        cout << "\n\n";
    }

    cout << "Ket qua: A = ";
    printArray(a);
    cout << "\n";

    return 0;
}
