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

    bool counted[n] = {false};

    cout << "Element frequencies:" << endl;
    for (int i = 0; i < n; i++) {
        if (counted[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                counted[j] = true;
            }
        }
        cout << arr[i] << " -> " << count << endl;
    }

    return 0;
}
