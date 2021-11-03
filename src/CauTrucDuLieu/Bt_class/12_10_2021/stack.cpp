#include <iostream>
using namespace std;

typedef int Item;

struct Node{
    Item data;
    Node *next;
};

struct stack{
    Node *top;
    long size;
    
    stack();
    void traverse() const;    
    Node* CreateNode(Item v);        
    void push(Item v);
    Item pop();
    Item peek();    
};
stack::stack() {
    top = NULL;
    size = 0;
}
Node* stack::CreateNode(Item v)
{
    Node* p = new Node;
    p->data = v;
    p->next = NULL;    
    return p; 
}
void stack::push(Item v){
    Node* p = CreateNode(v);
    p->next = top;
    top = p;
    size++;
}
Item stack::pop() {
    Node *t = top;
    Item data = top->data;
    top = top->next;
    delete t;
    size--;
    return data;
}
Item stack::peek(){
    return top->data;
}
void stack::traverse() const {
    Node *p = top;
    while (p != NULL) {
        cout << p->data << "\t";
        p = p->next;
    }
    delete p;
}