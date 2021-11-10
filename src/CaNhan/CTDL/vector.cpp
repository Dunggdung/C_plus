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
        bool check(vector<student> &b);
        friend vector operator +(vector &a,vector &b);
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
bool vector<student>::check(vector<student> &b){
    return n==b.n;
}
// template<class student>
vector operator +(vector &a,vector &b){
    vector c = a;
    for (int i=0; i<a.n; i++)
        c.v[i]=a.v[i]+b.v[i];
    return c;
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
    vector a(n);
    a.add();
    a.display();
    cout<<"Enter number of elements in vector B: "; cin>>n;
    vector b(n);
    b.add();
    b.display();
    cout<<"Summation of A and B: ";
    if(a.check(b)){
        (a+b).display();
    }else   cout<<"Can not calculate"<<endl;
}