#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HashTable {
private:
    vector<int> table;
    int size;
    int prime; 

    // Primary hash function
    int hashFunction1(int key) {
        return key % size;
    }

    // Secondary hash function
    int hashFunction2(int key) {
        return prime - (key % prime);
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1); // table with -1 to indicate empty slots
        prime = findPrimeSmallerThan(size);
    }

    // Function to find a prime number smaller than the size of the hash table
    int findPrimeSmallerThan(int n) {
        for (int i = n - 1; i >= 2; i--) {
            if (isPrime(i)) {
                return i;
            }
        }
        return 2;
    }

    // Helper function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void insert(int key) {
        int hash1 = hashFunction1(key);
        int hash2 = hashFunction2(key);
        int i = 0;
        // Use double hashing to find an empty slot
        while (table[(hash1 + i * hash2) % size] != -1) {
            i++;
            if (i == size) {
                cout << "Hash table is full\n";
                return;
            }
        }
        // Insert key at the found slot
        table[(hash1 + i * hash2) % size] = key;
    }

    bool search(int key) {
        int hash1 = hashFunction1(key);
        int hash2 = hashFunction2(key);
        int i = 0;
        while (table[(hash1 + i * hash2) % size] != key) {
            if (table[(hash1 + i * hash2) % size] == -1 || i == size) {
                return false; // Key not found
            }
            i++;
        }
        return true; // Key found
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
    HashTable ht(7); // Create a hash table of size 7

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
