#include <iostream>
using namespace std;
int main() {
    int Arr[] = {10, 20, 33, 40, 50, 70 , 60 , 80 , 11 , 22 , 102 };
    int KeySearch ;
    int i;
    cout << "Enter nummber to search : ";
    cin >> KeySearch;
    for (i = 0; i < 10; ++i) {
        if (Arr[i] == KeySearch) { // check if the element match the Keysearch
            break;
        }
    }

    if (i < 11) { // if the loop reach the end of array Arr[10] it found
        cout << "Found : " << KeySearch << endl;
    } 
    else {
        cout << "No the Element" << endl;
    }

    return 0;
}
