#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1); // table with -1 to indicate empty slots
    }

    void insert(int key) {
        int hash = hashFunction(key);
        int i = 0;
        while (table[(hash + i * i) % size] != -1) { // Use quadratic probing to find an empty slot
            i++;
            if (i == size) {
                cout << "Hash table is full\n";
                return;
            }
        }
        // Insert key at the found slot
        table[(hash + i * i) % size] = key;
    }

    bool search(int key) {
        int hash = hashFunction(key);
        int i = 0;
        while (table[(hash + i * i) % size] != key) {
            if (table[(hash + i * i) % size] == -1 || i == size) {
                return false; // not found
            }
            i++;
        }
        return true; // found
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << "\n";
            else
                cout << i << "\n";
        }
    }
};

int main() {
    HashTable ht(10); // Create a hash table of size 10
    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash table contents:\n";
    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found\n" : "Not found\n");
    cout << "Searching for 30: " << (ht.search(30) ? "Found\n" : "Not found\n");

    return 0;
}

