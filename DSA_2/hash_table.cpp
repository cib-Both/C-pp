#include <iostream>
#include <vector>
#include <string>
using namespace std;
class HashTable {
private:
    vector<string> table;
    int size;

    int hashFunction(const string &word) {
        // Using ASCII values and multiply powers
        // multiplied by a prime number (31) 
        return (static_cast<int>(word[0]) * 31 + static_cast<int>(word[1])) % size;
    }

public:
    HashTable(int size) : size(size) {
        table.resize(size, "");
    }

    void insert(const string &word) {
        int index = hashFunction(word);
        int originalIndex = index;

        // Linear probing to handle collisions
        while (!table[index].empty()) { //when the calculated index is already have
            index = (index + 1) % size; 
            if (index == originalIndex) {
                throw runtime_error("Hash table is full");
            }
        }
        // insert word in emply slot
        table[index] = word;
    }

    int search(const string &word) {
        int index = hashFunction(word);
        int originalIndex = index;
        while (!table[index].empty()) { // loop until found
            if (table[index] == word) { // check if slot match search word
                return index;
            }
            index = (index + 1) % size; 
            if (index == originalIndex) { 
                return -1;  // Word not found
            }
        }
        return -1;  // Word not found
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            if (!table[i].empty()) {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable(200);

    vector<string> words = {
        "book", "ask", "ball", "pen", "ice", "phone", "why", "gf", "idk", "a"
    };

    for (const auto &word : words) {
        hashTable.insert(word);
    }

    // Display the hash table
    hashTable.display();

    // Search for words
    string searchWord = "pen";
    int index = hashTable.search(searchWord);
    if (index != -1) {
        cout << "Index of '" << searchWord << "': " << index << endl;
    } else {
        cout << "'" << searchWord << "' not found in the hash table." << endl;
    }

    searchWord = "car";
    index = hashTable.search(searchWord);
    if (index != -1) {
        cout << "Index of '" << searchWord << "': " << index << endl;
    } else {
        cout << "'" << searchWord << "' not found in the hash table." << endl;
    }

    return 0;
}
