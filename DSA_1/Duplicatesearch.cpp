#include <iostream>
using namespace std;

int main() {
    int A[] = {10, 20, 33, 40, 33, 60, 70, 33, 90, 15};
    int Count = 0;
    int input;
    cout << "Enter a number to search for: ";
    cin >> input;

    for (int i = 0; i < 10; ++i) {
        if (A[i] == input) { // Check if the element of the array matches the input
            Count++;  // count if match is founnd 
        }
    }

    if (Count > 0) { // count greater then zero 
        // print output
        cout << "Found: " << input << " for " << Count << " time" << endl;
        // if not 
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}
