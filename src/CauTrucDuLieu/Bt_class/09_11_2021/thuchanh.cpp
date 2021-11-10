// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
#include <iostream>
using namespace std;

// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
typedef int Item;
struct Node{
	Item data;
	Node *next;
};
// Dinh nghia cau truc SList
struct SList{
	Node *head;
	Node *tail;
	long size;
	
	SList();
	
	Node* CreateNode(Item v);	
    void addLast(Item v);	
    void addFirst(const Item v)
    void traverse() const ;
    int Count();
    float aver ();
    Item High();
    Node* previous(Node *p);
    void removeFirst();
    void removeLast();
    void remove(Node *x);
    void insertAfter(Node *p, Item v);
    void insertBefore(Node *p, Item v)
};
// Khoi tao danh sach rong
SList::SList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
//Tao 1 node moi
Node* SList::CreateNode(Item v){
	Node* p=new Node;
	p->data=v;
	p->next=NULL;
	return p;
}
// them node vao cuoi danh sach
void SList::addLast(Item v){
	Node *temp=CreateNode(v);
    if(size == 0){
        head = tail = temp;
        size++;
    }else{
        tail->next=temp;
        tail=temp;
        size++;
    }
}
void SList::addFirst(const Item v){
    Node* p = CreateNode(v);
    p->next = head;
    head = p;
    if (size == 0)
        tail = p;
    size++;
}
//Nhap danh sach so nguyen ngung khi nhap 0
void input(SList &s){
    Item v;
    int i = 0;
    do{
        cout <<"Nhap phan tu thu " << i+1<<": " ;
        cin >> v;
        if (v != 0){
            s.addLast(v);
            i++;
        }
    }while(v != 0);
}
// nhap so nguyen
void input(SList &s,int &n){
    Item v;
    cout <<"Nhap n phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout <<"Nhap phan tu thu " << i+1<<": " ;
        cin >> v;
        s.addLast(v);
    }
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// Xuat
void print (Item a){
    cout<<" "<<a<<" || ";
}
void SList::traverse() const {
	Node* p = head;
	while (p != NULL) {
		print(p->data);
		p = p->next;
	}
	cout << endl;
	delete p;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// Dem so luong phan tu
int SList::Count(){
	int count = 0;
	Node* p = head;
	while(p != NULL){
		count++;
		p = p->next;
	}
	return count;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// tinh trung binh
float SList:: aver (){
    Node* p = head;
    float tbc = 0;
    int sum = 0;
    int count = 0;
    while (p != NULL){
        sum += p->data;
        count++;
        p = p->next;
    }
    tbc = (float)sum/count;
    return tbc;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// phan tu lon nhat
Item SList::High(){
    Node* p = head;
    Node* cur = head->next;
    while(cur != NULL){
        if(cur->data> p->data){
            p = cur;
        }
        cur = cur->next;
    }
    return p->data;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// tim dia chi truoc con tro p
Node* SList::previous(Node *p) {
    Node *t = head;
    while (t->next != p)
        t = t->next;
    return t;
}
// xoa phan tu dau
void SList::removeFirst() {
    if (size == 0)
        return;
    Node *t = head;
    head = head->next;
    delete t;
    size--;
}
// xoa phan tu cuoi
void SList::removeLast() {
    if (size == 0)
        return;
    if (size == 1) {
        delete head;
        size--;
        return;
    }
    Node *x = previous(tail);
    Node *t = tail;    
    x->next = NULL;
    tail = x;
    delete t;
    size--;
}
// xoa phan tu x
void SList::remove(Node *x) {
    if (x == head) {
        removeFirst();
        return;
    }
    if (x == tail) {
        removeLast();
        return;
    }
    Node *pre = previous(x);
    pre->next = x->next;
    delete x;
    size--;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// them vao sau  node p
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
// them y vao sau x
void After (SList s,int x){
    int y;
    Node *p = s.head;
    while (p != NULL){
        if (p->data == x) 
        break;
        p = p->next;
    }
    cout <<"Nhap gia tri y: ";
    cin >>y;
    s.insertAfter(p,y);
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// them phan tu truoc p
void SList::insertBefore(Node *p, Item v) {
    if (p == head)
        addFirst(v);
    else {        
        Node *pre = previous(p);
        insertAfter(pre, v);
    }    
}
// them y truoc x
void Before (SList s,int x){
    int y;
    Node *p = s.head;
    while (p != NULL){
        if (p->data == x) 
        break;
        p = p->next;
    }
    cout <<"Nhap gia tri y: ";
    cin >>y;
    s.insertBefore(p,y);
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
// giá trị của nút thứ k  (k bắt đầu từ 0)
void searchK (SList s,int k){
    int cout = 0;
    Node *p = s.head;
    while (p != NULL){
        if (cout == k) 
        break;
        count++;
        p = p->next;
    }
    cout <<"Gia tri nut k: "<<p->data <<endl;
}
// Họ và tên: Phạm Nguyễn Thùy Dung
// MSSV: 6151071003
// Ngày sinh:08/06/2002
// Email:6151071003@st.utc2.edu.vn
int main (){
    Item *v;
    SList s;
    int n ;
    input (s,n);
    s.traverse();
    cout <<" Co "<<s.Count()<<" phan tu"<<endl;
    cout <<"Trung binh cong: "<<s.aver()<<endl;
    cout <<"So lon nhat:  "<<s.High()<<endl;
    After(s,x);
    Before (s,x);
    searchK (s,k);
    return 0;
}

