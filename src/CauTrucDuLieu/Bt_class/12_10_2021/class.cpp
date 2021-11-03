/*Phạm Nguyễn Thùy Dung
MSSV: 6151071003
*/
#include <iostream>
using namespace std;
 
class ArrayList {
public:
	static const int MAX_SIZE = 100; 
	ArrayList(); 			// initialize an empty list 
	bool isEmpty() const; 	// check if the list is empty
	int length() const; 	// get the number of elements in a list
	void insert(const int x, int i); 	// insert x at the position i
	void append(const int x); 	// insert x at the end of the list
	void remove(int i); 		// remove the ith element
	int retrieve(int i) const; // return the value to the ith element
	void print() const; 	// print all element values
	int getlast() const;  // print index value at the end of the list
 
private:
	int element[MAX_SIZE];	// array to store all list elements
	int last;	// index of the last item
};
// Definition of all ArrayList methods
ArrayList::ArrayList(){
	last = -1;
}
bool ArrayList::isEmpty() const {
	return (last == -1);
}	
int ArrayList :: length() const {
	return (last + 1);
}
void ArrayList::insert(const int x, int i){
	if(last == MAX_SIZE ){
		cout<<"Cannot insert into list";
		exit(0);
	}
	else {
		for(int j=last+1;j>i;j--){
			element[j]=element[j-1];
		}
		element[i]=x;
        ++last;
	}
}
void ArrayList :: append(const int x){
	if(last == MAX_SIZE){
		cout<<"Cannot insert into list";
		exit(0);
	}
	else{
		element[last+1]=x;
		++last;
	}
}
void ArrayList :: remove(int i){
	for(int j = i; j < last; j++)
	{
		element[j] = element[j+1];		
	}
		last--;
}
int ArrayList :: retrieve(int i) const{
	return element[i];
}
void ArrayList :: print() const{
	for( int i=0 ;i <= last; i++){
		cout<<element[i]<<" ";
	}
}
int ArrayList::getlast() const{
	return last;
} 
// Main function
int main() {
	ArrayList list;
	//kiểm tra hàm có rổng hay không
	if (list.isEmpty())
		cout << "Empty list"<<endl;
	else cout<< "Not empty list"<<endl;
	//thêm phần tử 3
	cout<<"Insert at the end of the list :"<<endl;
	list.append(3);
	list.print();
	cout << endl;
	//thêm phần tử 7
	list.append(7);
	list.print();
	cout << endl;
	//thêm phần tử 1
 	list.append(1);
	list.print();
	cout << endl;
	// thêm phần tử x = 8 vào vị trí i = 1
	cout<<"Insert x = 8 at the position i = 1:"<<endl;
	list.insert(8,1);
	list.print();
	cout<<endl;
	//vị trí cuối cùng trong dãy
	cout<<"Index last of the list:\t"<<list.getlast()<<endl;
	//xuất các biến của dãy
	cout<<"All value of the list :";
	list.print();
	cout<<endl;
	// độ dài
	cout<<"Length of the list :"<<list.length()<<endl;
	// xóa 1 phần từ
	list.remove(1);
	list.print();
	//phần tử ở vị trí thứ i
	cout << endl <<"The value to the ith element: "<<list.retrieve(1);
	//kết thúc
	cout << endl << "End.";
	return 0;
}