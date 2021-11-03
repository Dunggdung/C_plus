typedef int Item;
struct Node {
    Item data;
    Node *left;
    Node *right;
};
class BST
Item BinaryTree::deleteRight(Node* p){
    if(p == NULL){
        cout<<"Error"<<endl;
        return -1;
    }
    else if(p->right == NULL){
        cout<<"Error"<<endl;
        return -1;
    }
    else{
        Node* q = p->right;
        if(q->left != NULL || q->right != NULL){
            cout<<"Error"<<endl;
            return -1;
        }
        else{
            Item value = q->data;
            p->right = NULL;
            delete q;
            return value;
        }
    }
}
Item BinaryTree::deleteLeft(Node* p){
    if(p == NULL){
        cout<<"Error"<<endl;
        return -1;
    }
    else if(p->left == NULL){
        cout<<"Error"<<endl;
        return -1;
    }
    else{
        Node* q = p->left;
        if(q->left != NULL || q->right != NULL){
            cout<<"Error"<<endl;
            return -1;
        }
        else{
            Item value = q->data;
            p->left = NULL;
            delete q;
            return value;
        }
    }
}
void BinaryTree ::deleteTree(Node* &root){
    if (root != NULL){
        deleteTree (root->left);
        deleteTree (root->right);
        delete root;
        root = NULL;
    }
}
void BinaryTree ::preOrder (Node* root){
    if (root != NULL){
        // tham nút cha
        cout << root->data ;
            preOrder(root->left);
            preOrder(root->right);
    }
}
void BinaryTree ::inOrder (Node* root){
    if (root != NULL){
        inOrder (root->left);
        cout << root->data ;
        inOrder(root->right);
    }
}
void BinaryTree ::posOrder (Node* root){
    if (root != NULL){
    posOrder (root->left);
    posOrder (root->right);
    cout << root->data ;
    }
}
void BinaryTree ::posOrder (Node* root){
    if (root != NULL){
    posOrder (root->right);
    posOrder (root->left);
    cout << root->data ;
    }
}
Node* BinaryTree::search (Node* p,Item v){
    if (p == NULL)
        return NULL;
    if (p->data == v)
        return p;
        Node *q = search (p->left,v);
    
    if (q==NULL)
        q =  search (p->right,v);
}