#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a vector of integers
    vector<int> vec;

    // Add some elements to the vector
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(5);

    // Iterator functions
    cout << "Using begin and end: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Using rbegin and rend: " ;
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Capacity functions
    cout << "size: " << vec.size() << endl;
    cout << "max_size: " << vec.max_size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "empty: " << (vec.empty() ? "true" : "false") << endl;

    // Resize 
    vec.resize(8);
    cout << "After resize(8): ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    vec.resize(2);
    cout << "After resize(2): ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
