#include <iostream>
#include <queue>
using namespace std;

// Print elements of priority queue
void print(priority_queue<int> pq)
{
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

int main()
{
	priority_queue<int> pq1;
	priority_queue<int> pq2;

	// pushing elements into the 1st priority queue
	pq1.push(6);
	pq1.push(4);
	pq1.push(12);
	pq1.push(33);

	// pushing elements into the 2nd priority queue
	pq2.push(2);
	pq2.push(5);
	pq2.push(25);
	pq2.push(10);

  // Size of the queue
    cout << "Size of first queue: " << pq1.size() << endl;

    // Front element of the queue
    cout << "Top element of first queue: " << pq1.top() << endl;

    // Popping the top elements from the queue
    cout << "Popping the top elements from the first queue: ";
    if (!pq1.empty()) {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

	cout << "\nBefore swapping:" << endl;
	cout << "Priority first Queue = ";
	print(pq1);
	cout << "Priority second Queue = ";
	print(pq2);

	// Swap
	pq1.swap(pq2);

	cout << endl << "After swapping:" << endl;
	cout << "Priority first Queue = ";
	print(pq1);
	cout << "Priority second Queue = ";
	print(pq2);

  // Checking if queue is empty
    if (pq1.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

	return 0;
}
