#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int temp[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int k = 0; k < j; k++) {
            if (arr[i] == temp[k]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[j] = arr[i];
            j++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < j; i++)
        cout << temp[i] << " ";
    cout << endl;

    return 0;
}
