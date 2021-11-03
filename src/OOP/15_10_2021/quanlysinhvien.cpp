// Phạm Nguyễn Thùy Dung 6151071003
// quản lý sinh viên 
// class person:
// +name age address (private)
//input output (public)
// class student:public person
// +id,score (private)
//rank(public) input1, output1;
//class teacher:public person
//void teach(); (public)
#include <iostream>
using namespace std;
class Person {
    private:
        string name,address;
        int age;
    public:
        void input();
        void output();
        string getName(){
            return name;
        }
};
class Student : public Person {
    private:
        string id;
        float score;
    public:
        void input1();
        void output1();
        void rank();
};
class Teacher : public Person {
    public:
        void teach();
};
void Person::input(){
    fflush(stdin);
    cout <<"Enter name: " ;
    getline(cin,name);
    cout <<"Enter address: ";
    getline(cin,address);
    cout <<"Enter age: ";
    cin >> age;
}
void Person::output(){
    cout <<"Name: " << name <<" ||Address: " << address <<" ||Age: " << age <<endl;
}

void Teacher::teach(){
    if(getName()=="Dung")
        cout <<"Teaching K62."<<endl;
    else if(getName()=="Mien")
        cout <<"Teaching K61."<<endl;
    else if(getName()=="Minh")
        cout <<"Teaching K60."<<endl;
    else
        cout <<"Teching K59."<<endl;
}

void Student::input1(){
    fflush(stdin);
    input();
    fflush(stdin);
    cout <<"Enter id: " ;
    getline(cin,id);
    // cout <<"Enter name: " ;
    // getline(cin,name);
    // cout <<"Enter address: ";
    // getline(cin,address);
    // cout <<"Enter age: ";
    // cin >> age;
    do { 
        cout << "Enter score: ";
        cin >> score;
        if (score < 0.0 ||score > 10.0){
            cout << "Enter score: ";
            cin >> score;
        }
    }while (score < 0.0 ||score > 10.0);
}
void Student::output1(){
    output();
    cout <<"Id: " <<id <<" ||Score: " << score << endl;
}
// void Student::input(){
//     fflush(stdin);
//     cout <<"Enter id: " ;
//     getline(cin,id);
//     cout <<"Enter name: " ;
//     getline(cin,name);
//     cout <<"Enter address: ";
//     getline(cin,address);
//     cout <<"Enter age: ";
//     cin >> age;
//     do { 
//         cout << "Enter score: ";
//         cin >> score;
//         if (score < 0.0 ||score > 10.0){
//             cout << "Enter score: ";
//             cin >> score;
//         }
//     }while (score < 0.0 ||score > 10.0);
// }
// void Student::output(){
//     cout <<"Id: " <<id<<" ||Name: " << name <<" ||Address: " << address <<" ||Age: " << age <<" ||Score: " << score << endl;
// }
void Student::rank (){
    // Xếp loại theo tiêu chí:
    //     - Giỏi (>= 8.0)
    //     - Khá (>= 7.0)
    //     - Trung bình (>= 5.0)
    //     - Yếu (< 5)
    if (score >= 8.0){
        cout <<"Gioi" << endl;
    }
    else if (score >=7.0 && score < 8.0){
        cout <<"Kha"<< endl;
    }
    else if (score >= 5.0 && score < 7.0){
        cout <<"Trung Binh"<< endl;
    }
    else {
        cout <<"Yeu"<< endl;
    }
}
int main (){
    Student a;
    Teacher b;
    b.input();
    b.output();
    b.teach();
    a.input1();
    a.output1();
    return 0;
}
