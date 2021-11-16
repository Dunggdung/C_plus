#include <iostream>
using namespace std;

typedef int Item;
struct Node {
    Item data;
    Node *left;
    Node *right;
};
class BST{
    public:
    BST();
    BST(Item v);
    Node *createNode(Item v);
    bool isEmpty();
    void preOrder(Node *root);
    void postOrder(Node *root);
    void inOrder(Node *root);
    void deleteTree(Node* &root);
    Node* search(Node* p,Item v);
    void insert(Item v);
    Item remove(Node* p);
    Node* minValueNode(Node* p)
    Node* root;
};
void BST::insert(Node* &root,Item v){
    if (root == NULL){
        root = createNode(v);
    }
    else {
        Node root = new Node;
        if (v < root->data)
            insert(root->left,v);
        else if (v > root->data)
            insert(root->right,v);
    }
}
BST createFromArray(Item a[],int length){
    BST bst;
    for (int i = 0; i < length; i++){
        bst.insert(bst.root,a[i]);
    }
    return bst;
}
Node* BST::minValueNode(Node* p){
    Node* current = p;
    while (current&&current->left != NULL)
    current = current->left;
    return current;
}
Node* BST::remove(Node* &root,int v){
    if (root == NULL)
        return root;
    if (v < root->data)
        
    else if (v > root->data)

    else{
        if(root->left == NULL&&root->right == NULL)

        else {
            if()

            else if()

            else if()

            else{

            }
        }

    }
    return root;
}