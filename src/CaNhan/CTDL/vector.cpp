#include<iostream>
using namespace std;
template<class student>
class vector{
    private:
        int n;
        student *v;
    public:
        vector(int size);
        vector(vector<student> &a);
        ~vector();
        void add();
        void display();
        void operator =(vector<student> &a);
};
template<class student>
vector<student>::vector(int size){
    n = size;
    v = new student [n];
}
template<class student>
vector<student>::vector(vector<student> &a){
    n = a.n;
    v = new student [n];
    for (int i=0; i<n; i++)   
        v[i]=a.v[i];
}
template<class student>
vector<student>::~vector(){
    delete v;
}
template<class student>
void vector<student>::add(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}
template<class student>
void vector<student>:: operator =(vector<student> &a){
    n = a.n;
    v = new student [n];
    for (int i=0; i<n; i++)
        v[i]=a.v[i];
}
template<class student>
void vector<student>::display(){
    for(int i=0; i<n; i++)    
        cout<<v[i]<<" ";
        cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements in vector A: "; cin>>n;
    vector<int> a(n);
    a.add();
    a.display();
    cout<<"Enter number of elements in vector B: "; cin>>n;
    vector <int> b(n);
    b.add();
    b.display();
}