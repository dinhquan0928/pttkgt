#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& a) {
    cout << "[";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i + 1 < a.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    vector<int> a = { 1, 2, 4, 5, 8 }; // mảng ví dụ (bạn có thể thay đổi)
    int n = (int)a.size();

    cout << "Mang ban dau: ";
    printArray(a);
    cout << "\n\n";

    // Insertion sort với in bước chi tiết (i in 1..n-1). Hiển thị i theo 1-based để giống hình
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;
        bool shifted = false;

        cout << "Buoc " << i << ": i = " << i << "\n";
        cout << "  key = a[" << i << "] = " << key << "\n";

        // So sánh và dịch từng phần tử nếu cần
        while (j >= 0 && a[j] > key) {
            cout << "  So sanh key(" << key << ") < a[" << j << "](" << a[j] << ") -> dung -> dich a[" << j << "] sang vi tri " << (j + 1) << "\n";
            a[j + 1] = a[j]; // shift
            ++shifted;
            printArray(a);
            cout << "\n";
            j = j - 1;
        }

        if (!shifted) {
            // Không cần dịch
            if (j >= 0) {
                cout << "  So sanh " << key << " < " << a[j] << " -> sai -> khong can dich.\n";
            }
            else {
                cout << "  Khong co phan tu trai hon de so sanh -> khong can dich.\n";
            }
        }

        // đặt key vào vị trí đúng
        a[j + 1] = key;
        cout << "  Mang sau khi chen key: ";
        printArray(a);
        cout << "\n\n";
    }

    cout << "ket qua: ";
    printArray(a);
    cout << "\n";

    return 0;
}
