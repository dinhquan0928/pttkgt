#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = { 5, 3, 8, 4, 2 };
    int n = a.size();

    cout << "Cho mang ban dau: a = [";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]\n\n";

    for (int i = 0; i < n - 1; i++) {
        cout << "Buoc " << i + 1 << ": i = " << i << endl;

        cout << "So sanh a[" << i << "]=" << a[i]
            << " voi cac phan tu sau:\n";

            for (int j = i + 1; j < n; j++) {
                cout << a[i] << " > " << a[j] << " --> ";

                if (a[i] > a[j]) {
                    cout << "doi --> ";
                    swap(a[i], a[j]);
                }
                else {
                    cout << "khong doi --> ";
                }

                // In mảng sau mỗi lần so sánh
                cout << "[";
                for (int k = 0; k < n; k++) {
                    cout << a[k];
                    if (k < n - 1) cout << ", ";
                }
                cout << "]\n";
            }
            cout << endl;
    }

    cout << "Mang sau khi sap xep: [";
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]";

    return 0;
}
