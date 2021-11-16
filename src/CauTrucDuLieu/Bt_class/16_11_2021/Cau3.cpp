//Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
#include <iostream>
using namespace std;

typedef int Item;
struct Node {
    Item data;
    Node *left;
    Node *right;
};
class BST {
public:	
	BST(); // khởi tạo mặt định
	BST(Item v); // khởi tạo 
	Node* createNode(Item v); // tạo 1 node mới
    bool isEmpty();	// xem có phải phần tử rõng không
    void insert(Node* &root, Item v); // thêm node có giá trị v vào cây
    Item leftMostValue(Node* root); // nút bên trái nhất
    Node* remove(Node* &root, int v); // xóa phần tử
    void preOrder(Node* root); // duyệt theo kiểu pre
    Node* root;	// nút góc
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
Node* BST::createNode(Item v) {	
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
void BST::insert(Node* &root, Item v) {
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
Item BST::leftMostValue(Node* root){
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
Node* BST::remove(Node* &root, int v){
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
void BST::preOrder(Node* root) {
	if (root != NULL) {
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main (){
    BST bst;
    bst.root = NULL;
    Item v[5];
    cout << " Nhap gia tri vao cay: "<<endl;
    for(int i=0; i<5; i++){
        cin >> v[i];
        bst.insert(bst.root,v[i]);
    }
    // for(int i=0; i<5; i++){
        bst.preOrder(bst.root);
    // }
}