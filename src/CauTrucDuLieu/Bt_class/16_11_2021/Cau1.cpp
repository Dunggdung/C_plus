// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
#include <iostream>
#include <math.h>
using namespace std;

typedef int Item;
struct Node {
    Item data;
    Node *left;
    Node *right;
};
class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(Item v);
        Node* createNode(Item v);
        bool isEmpty();
        void deleteTree(Node* &root);
        void preOrder(Node* root);
        void inOrder(Node* root);
        void posOrder(Node* root);
        void insertLeft(Node* p, Item v);
        void insertRight(Node* p, Item v);
        int height(Node* root);
        int countNode(Node* root);
        int countLeaf(Node* root);
        void findBigger(Node* root, Item v);
        Item findMax(Node* root);
        Item findMin(Node* root);
        bool perfectBinaryTree(Node *root);
        Node* search(Node* root,Item v);
        Node* root;
        int size;
};
// khởi tạo mặt định
BinaryTree::BinaryTree(){
    root = NULL;
    size = 0;
}
// khởi tạo có tham chiếu
BinaryTree::BinaryTree(Item v){
    root = createNode(v);
    size = 1;
}
// tạo nút mới
Node* BinaryTree::createNode(Item v){
    Node* p = new Node;
    p->data = v;
    p->left = p->right = NULL;
    return p;
}
// kiểm tra cây có rỗng không?
bool BinaryTree::isEmpty(){
    return root == NULL;
}
// xóa nguyên cây
void BinaryTree ::deleteTree(Node* &root){
    if (root != NULL){
        deleteTree (root->left);
        deleteTree (root->right);
        delete root;
        root = NULL;
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
//	Duyệt cây theo thứ tự trước, thứ tự giữa, và thứ tự sau.
void BinaryTree ::preOrder (Node* root){
    if (root != NULL){
        cout << root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void BinaryTree ::inOrder (Node* root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}
void BinaryTree::posOrder (Node* root){
    if (root != NULL){
        posOrder (root->left);
        posOrder (root->right);
        cout << root->data<<" ";
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// thêm phải
void BinaryTree::insertRight(Node* p,Item v){
    if (p == NULL) {
        cout << "error";
        // return;
    }
    else if (p->right != NULL) {
        cout << "Da co con phai";
        // return;
    }
    else{
        p->right = createNode(v);
        size++;
    }
}
// thêm trái
void BinaryTree::insertLeft(Node* p, Item v){
    if (p == NULL) {
        cout << "error";
        // return;
    }
    else if (p->left != NULL) {
        cout << "Da co con trai";
        // return;
    }
    else {
        p->left = createNode(v);
        size++;
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// chiều cao của cây
int BinaryTree::height(Node* root){
    if(root == NULL)    return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    if(h1>h2)   return h1+1;
    else return h2+1;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// đếm số nút có trong cây
int count1 = 0;
int BinaryTree ::countNode (Node* root){
    if (root != NULL){
        count1 ++;
        countNode(root->left);
        countNode(root->right);
    }
    return count1;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// đếm số nút lá trên cây
int BinaryTree::countLeaf(Node* root){
    if(root== NULL) return 0;
    else{
        if(root->left == NULL && root->right == NULL) return 1;
        else return countLeaf(root->left) +countLeaf(root->right);
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// đếm nút lớn hơn x
int count = 0;
void BinaryTree::findBigger(Node *root, Item v){
    if (root != NULL){
        if(root->data > v)  count++;
        findBigger(root->left, v);
        findBigger(root->right, v);
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// tìm nút lớn nhất
Item BinaryTree::findMax(Node* root){
    if (root == NULL)
        return 0;
    int res = root->data;
    int leftres = findMax(root->left);
    int rightres = findMax(root->right);
    if (leftres > res)
        res = leftres;
    if (rightres > res)
        res = rightres;
    return res;
}

Item BinaryTree::findMin(Node* root){
    if (root == NULL)
        return 0;
    int res = root->data;
    int leftres = findMin(root->left);
    int rightres = findMin(root->right);
    if (leftres < res)
        res = leftres;
    if (rightres < res)
        res = rightres;
    return res;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
bool BinaryTree::perfectBinaryTree(Node *root){
    return pow(2,height(root))-1 == size;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// tìm nút
Node* BinaryTree::search (Node* root,Item v){
    if (root == NULL)
        return NULL;
    if (root->data == v)
        return root;
        Node *q = search(root->left,v);
    if (q==NULL)
        q = search (root->right,v);
    return q;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
int main(){
    BinaryTree tree(7);
    tree.insertLeft(tree.root, 3);
    tree.insertRight(tree.root, 10);
    tree.insertLeft(tree.search(tree.root,3), 2);
    tree.insertRight(tree.search(tree.root,3), 5);
    tree.insertLeft(tree.search(tree.root,10), 6);
    tree.insertRight(tree.search(tree.root,10), 9);
    tree.preOrder(tree.root);
    cout<<endl<<"Chieu cao cua cay: "<<tree.height(tree.root)<<endl;
    cout<<"So nut cua cay: "<<tree.countNode(tree.root)<<endl;
    cout<<"So nut la: "<<tree.countLeaf(tree.root)<<endl;
    tree.findBigger(tree.root,4);
    cout<<"so nut lon hon x: "<<count<<endl;
    
    cout<<"Gia tri lon nhat: "<<tree.findMax(tree.root)<<endl;
    // cout<<"Gia tri nho nhat: "<<tree.findMin(tree.root)<<endl;
    if (tree.perfectBinaryTree(tree.root)){
        cout<<endl<<"La cay hoan hao";
    }else {
        cout<<"Khong Phai cay hoan hao";
    }
    tree.deleteTree(tree.root);
}

