#include <iostream>
using namespace std;

typedef int Item;

struct Node{
    Item data;
    Node *next;
};

struct SList{
    Node *head;
    Node *tail;
    long size;
    
    SList();
    
    Node* CreateNode(Item v);
    void addFirst(const Item v);
    void insertAfter(Node *p, Item v);
    void insertBefore(Node *p, Item v);
    void addLast(Item v);
    void removeFirst();
    void removeLast();
    void remove(Node *p);        
    void traverse() const;
    Node* previous(Node *p);
};

SList::SList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

Node* SList::CreateNode(Item v)
{
    Node* p = new Node;
    p->data = v;    
    p->next = NULL;    
    return p; 
}

void SList::addFirst(const Item v){
    Node* p = CreateNode(v);
    p->next = head;
    head = p;
    if (size == 0)
        tail = p;
    size++;
}

void SList::insertAfter(Node *p, Item v) {
    if (p == tail)
        addLast(v);
    else {
        Node *q = CreateNode(v);
        q->next = p->next;
        p->next = q;      
    }
    size++;
}

Node* SList::previous(Node *p) {
    Node *t = head;
    while (t->next != p)
        t = t->next;
    return t;
}

void SList::insertBefore(Node *p, Item v) {
    if (p == head)
        addFirst(v);
    else {        
        Node *pre = previous(p);
        insertAfter(pre, v);
    }    
}

void SList::addLast(Item v) {
    Node *p = CreateNode(v);
    if (size == 0) {
        head = p;
        tail = p;
    }
    else {
        tail->next = p;
        tail = p;      
    }
    size = size + 1;
}

void SList::removeFirst() {
    if (size == 0)
        return;
    Node *t = head;
    head = head->next;
    delete t;
    size--;
}

void SList::removeLast() {
    if (size == 0)
        return;
    if (size == 1) {
        delete head;
        size--;
        return;
    }
    Node *p = previous(tail);
    Node *t = tail;    
    p->next = NULL;
    tail = p;
    delete t;
    size--;
}

void SList::remove(Node *p) {
    if (p == head) {
        removeFirst();
        return;
    }
    if (p == tail) {
        removeLast();
        return;
    }
    Node *pre = previous(p);
    pre->next = p->next;
    delete p;
    size--;
}

void SList::traverse() const {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
    delete p;
}