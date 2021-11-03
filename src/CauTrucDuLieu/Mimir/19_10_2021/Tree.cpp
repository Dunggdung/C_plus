#include <iostream>
using namespace std;

typedef int Item;
struct Node {
	Item data;
	Node* left;
	Node* right;	
};
class BST {
public:	
	// methods
	BST();
	BST(Item v);
	Node* createNode(Item v);
	bool isEmpty();	
	void preOrder(Node* root);
	void inOrder(Node* root);
	void posOrder(Node* root);	
	void deleteTree(Node* &root);
	Node* search(Node* p, Item v);
	void insert(Node* &root, Item v);
	Node* minValueNode(Node* p);
	Item leftMostValue(Node* root);
	Node* remove(Node* &root, int v);
	// variable
	Node* root;	
};
BST::BST() {
	root = NULL;
}
BST::BST(Item v) {
	root = createNode(v);
}
bool BST::isEmpty() {
	return (root == NULL);
}
// traversal in NLR (Node Left Right) order
void BST::preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}
// create a new node with data v
Node* BST::createNode(Item v) {	
	// WRITE YOUR CODE HERE
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}

// insert a new node
void BST::insert(Node* &root, Item v) {
	// WRITE YOUR CODE HERE
    if (root == NULL){
        root = createNode(v);
    }
    else {
        if (v < root->data)
            insert(root->left,v);
        else if (v > root->data)
            insert(root->right,v);
    }
}
/* Given a non-empty binary search tree, return the node with minimum 
key value found in that tree*/
Node* BST::minValueNode(Node* p) 
{ 
	// WRITE YOUR CODE HERE
    if(p->left == NULL){
        return p;
    }
    return minValueNode(p->left);
} 
/* Given a binary search tree and a key, this function deletes the key 
and returns the new root */
Item BST::leftMostValue(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
Node* BST::remove(Node* &root, int v)
{
	// WRITE YOUR CODE HERE
    if (root == NULL)
        return root;
    if (v < root->data)
        root->left = remove(root->left, v);
    else if (v > root->data)
        root->right = remove(root->right, v);
    else{
        if(root->left == NULL){
            Node* newRoot=root->right;
            delete root;
            return newRoot;
        }
        if(root->right == NULL){
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
        root->data = leftMostValue(root->right);
        root->right = remove(root->right, root->data);
    }
    return root;
}
// create a BST with keys from an array
BST createFromArray(Item a[], int length) {
	// WRITE YOUR CODE HERE
    BST b;
    for(int i = 0; i<length; i++){
        b.insert(b.root, a[i]);
    }
    return b;
}