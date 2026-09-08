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

    bool isPalindrome = true;
    int start = 0, end = n - 1;

    while (start < end) {
        if (arr[start] != arr[end]) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome)
        cout << "The array is a palindrome." << endl;
    else
        cout << "The array is not a palindrome." << endl;

    return 0;
}
