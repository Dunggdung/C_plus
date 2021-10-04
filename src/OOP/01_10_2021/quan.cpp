#include <iostream>
using namespace std;
class Student{
    private:
        string name,cl,id,birth;
        float grade;
        
    public:
        friend istream& operator >> (istream &is, Student &s); 
        friend ostream& operator << (ostream &os, Student s); 

istream& operator >> (istream &is, Student &s){
    fflush(stdin);
    cout << "Name: ";
    getline (is,s.name);
    cout << "ID: ";
    getline (is,s.id);
    cout >> "Birth: ";
    getline (is,s.birth);
    cout >> "Total Grade: ";
    is >> s.grade; 
}

ostream& operator << (ostream &os, Student s){
    os << "--Name: " << s.name << endl;
    os << "--ID: " << s.id << endl;
    os << "--Birth: " << s.birth << endl;
    os << "--Total Grade: " << s.grade << endl;
}

int main(){
    Student s;
    int n;
    cout << "Enter Total Student: ";
    cin >> n;
    for (int i= 0; i < n; i++)
        {
            cin >> s[i];
        }
    for (int i= 0; i < n; i++)
        {
            cout << s[i];
        }
}