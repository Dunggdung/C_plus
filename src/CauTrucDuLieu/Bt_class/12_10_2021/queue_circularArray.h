#include <iostream>
using namespace std;

template <typename Item>
class CArrayQueue {
public:
	CArrayQueue(int size);	
	bool isEmpty();
	bool isFull();
	int getRead();
	int getWrite();
	int getLength();
	void enqueue(Item v);
	Item dequeue();
	void show();
private:
	Item *buf;	// circular buffer
	int read;	// read pointer
	int write;	// write pointer
	int length;	// buffer length
};
template <typename Item>
bool CArrayQueue<Item>::isEmpty(){
    return (read == write);
}
template <typename Item>
bool CArrayQueue<Item>::isFull(){
    return (read == ((write+1) % length));
}
template <typename Item>
CArrayQueue<Item>::CArrayQueue(int size) {
	buf = new Item[size];
	read = 0;
	write = 0;
	length = size;
}
template <typename Item>
void CArrayQueue<Item>::enqueue(Item v) {
	// write your code here
    if (isFull())
    cout <<"Full queue";
    else {
        buf[write] = v;
        write = (write + 1) % length;
    }
}
template <typename Item>
Item CArrayQueue<Item>::dequeue() {
	// write your code here
    if (isEmpty()){ 
        cout << "Empty queue";
        return -1;
    }
    else {
        Item r = buf[read];
        read = (read + 1) % length;
        return r;
    }
}
template <typename Item>
void CArrayQueue<Item>::show() {
	if (read == write) {
		cout << "empty queue" << endl;
		return;
	}
	for (int i = read; i < write; i++)
		cout << buf[i] << "\t";
	cout << endl;
}