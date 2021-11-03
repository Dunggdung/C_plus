#include "queue_circularArray.h"
void printQueueInfo(CArrayQueue<int> Q) {
	Q.show();
	cout << "length = " << Q.getLength() << endl;
	cout << "read pointer = " << Q.getRead() << endl;
	cout << "write pointer = " << Q.getWrite() << endl;
	cout << endl;
}
int main() {
	CArrayQueue<int> Q(10);
	cout << "Test initialization function\n";
	printQueueInfo(Q);
	
	cout << "\nTest enqueue function\n";
	Q.enqueue(5);
	printQueueInfo(Q);	
	Q.enqueue(2);
	printQueueInfo(Q);
	Q.enqueue(3);
	printQueueInfo(Q);
	
	cout << "\nTest dequeue function\n";
	int x = Q.dequeue();
	cout << "Return value = " << x << endl;
	printQueueInfo(Q);	
	x = Q.dequeue();
	cout << "Return value = " << x << endl;
	printQueueInfo(Q);
	x = Q.dequeue();
	cout << "Return value = " << x << endl;
	printQueueInfo(Q);
	
	return 0;
}
