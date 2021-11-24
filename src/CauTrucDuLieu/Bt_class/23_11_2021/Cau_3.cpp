#include<iostream>
using namespace std;
 
struct Node{
	int data;
	Node *pNext;
};
struct singleList{
	Node *pHead;
};
void Initialize(singleList &list){
	list.pHead = NULL;
}
// tao node
Node *CreateNode( int d){
	Node *pNode = new Node;
	if(pNode != NULL){
		pNode->data=d;
		pNode->pNext=NULL;
	}
	else{
		cout<<"Cap phat bo nho that bai";
	}
	return pNode;	
}
// in ra danh sach lien ket
void PrintList(singleList list){
	Node *pTmp=list.pHead;
	if(pTmp==NULL){
		cout<<"The list is empty!";
		return;
	}
	while(pTmp!= NULL){
		cout<<pTmp->data<<" ";
		pTmp=pTmp->pNext;
	}
}
// dem so phan tu trong danh sach lien ket
int SizeOfList(singleList list){
	Node *pTmp=list.pHead;
	int nSize=0;
	while(pTmp!=NULL){
		pTmp=pTmp->pNext;
		nSize++;
	}
	return nSize;
}
// chen node vao dau danh sach lien ket
void InsertFirst(singleList &list, int d){
	Node *pNode=CreateNode(d);
	if(list.pHead == NULL){
		list.pHead=pNode;
	}
	else {
		pNode->pNext=list.pHead;
		list.pHead=pNode;
	}
}
// chen node vao cuoi danh sach lien ket
void InsertLast(singleList &list, int d){
	Node *pNode=CreateNode(d);
	if(list.pHead == NULL){
		list.pHead= pNode;
	}
	else {
		Node *pTmp=list.pHead;
		while (pTmp->pNext != NULL){
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
	}
}
// chen node vao cuoi danh sach lien ket
void InsertMid(singleList &list,int pos, int d){
    if(pos<0 || pos >= SizeOfList(list)){
		cout << "Not valid position do insert";
		return ;
	} 
	if (pos == 0) InsertFirst(list,d);
	else if (pos == SizeOfList(list)-1)
	    InsertLast(list,d);
	else{
		Node *pNode=CreateNode(d);
		Node *pIns=list.pHead;
		Node *pPre=NULL;
		int i=0;
		while(pIns!=NULL){
			if(i==pos) break;
			pPre=pIns;
			pIns=pIns->pNext;
			i++;
		}
		pPre->pNext=pNode;
		pNode->pNext=pIns;
	}
}
// xoa node khoi danh sach lien ket
void RemoveNode(singleList &list, int d){
	Node *pDel=list.pHead;
	if(pDel == NULL){
		cout <<" The list is empty!";
	}
	else{
		Node *pPre = NULL;
		while (pDel!= NULL){
			if(pDel->data == d) break;
			pPre = pDel;
			pDel=pDel->pNext;
		}
		if(pDel == NULL){
			cout << " Could not found number! ";
		}
		else {
			// xoa dau
			if (pDel == list.pHead){
				list.pHead = list.pHead->pNext;
				pDel->pNext = NULL;
				delete pDel; 
				pDel = NULL;
			}
			// xoa giua
			else {
				pPre->pNext=pDel->pNext;
				pDel->pNext= NULL;
                delete pDel;
				pDel=NULL;
			}
		}
	}
}
// tim kiem node trong danh sach lien ket 
Node *SearchNode(singleList list, int d){
	Node *pTmp = list.pHead;
	while (pTmp != NULL){
		if(pTmp->data== d) break;
		pTmp= pTmp->pNext;
	}
	return pTmp;
}
// sap xep trong danh sach lien ket
void SortList(singleList &list){
	for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
			if(pTmp->data > pTmp2->data){
				int tmp=pTmp->data;
				pTmp->data= pTmp2->data;
				pTmp2->data= tmp;
			}
		}
	}
}
// huy danh sach lien ket
void FreeMemory(singleList &list){
	while (list.pHead != NULL){
		Node *pTmp=list.pHead;
		list.pHead=pTmp->pNext;
		pTmp->pNext=NULL;
		cout << pTmp->data << "is deleted \n";
		delete pTmp;
		pTmp = NULL;
	}
}
int main(){
	singleList list;
	Initialize(list);
	InsertFirst(list,10);
	InsertFirst(list,3);
	InsertFirst(list,5);
	InsertFirst(list,7);
	InsertLast(list,8);
	InsertMid(list,2,4);
	RemoveNode(list,5);
	PrintList(list);
	int d;
	cout << "\nNhap gia tri muon tim: ";
	cin >> d; 
	Node *pSearch=SearchNode(list,d);
	if(pSearch!=NULL){
		cout << "Found";
	}
	else{
		cout <<" Not found"<< d;
	}
	cout <<"\n Mang da sap xep: ";
	SortList(list);
	PrintList(list);
    return 0; 
}