#include <iostream>
#include <queue>

using namespace std;

// Print elements of priority queue
void print(queue<int> pq)
{
	while (!pq.empty()) {
		cout << pq.front() << " ";
		pq.pop();
	}
	cout << endl;
}

int main() {
    // Declaration of queue
    queue<int> q1;
    queue<int> q2;

    // Pushing elements into the queue
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    q2.push(60);
    q2.push(70);
    q2.push(80);

    // Size of the queue
    cout << "Size of first queue: " << q1.size() << endl;

    // Front element of the queue
    cout << "Front element of first queue: " << q1.front() << endl;

    // Back element of the queue
    cout << "Back element of first queue: " << q1.back() << endl;

    // Popping the front elements from the queue
    cout << "Popping the front elements from the first queue: ";
    if (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

   cout << "\nBefore swapping:" << endl;
	cout << "Priority first Queue = ";
	print(q1);
	cout << "Priority second Queue = ";
	print(q2);

	// Swap
	q1.swap(q2);

	cout << endl << "After swapping:" << endl;
	cout << "Priority first Queue = ";
	print(q1);
	cout << "Priority second Queue = ";
	print(q2);

    // Checking if queue is empty
    if (q1.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
