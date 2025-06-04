#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Declaration of stack
    stack<int> s;

    // Pushing elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Size of the stack
    cout << "Size of stack: " << s.size() << endl;

    // Top element of the stack
    cout << "Top element of stack: " << s.top() << endl;

    // Popping the top element from the stack
    if (!s.empty()) {
        cout << "Pop element: " << s.top() << endl;
        s.pop();
    }

    // Top element after popping 
    cout << "Top element after pop: " << s.top() << endl; 

    // Checking if stack is empty
    if (s.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
