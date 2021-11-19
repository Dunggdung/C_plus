//Phạm Nguyễn Thùy Dung 6151071003
#include <iostream>
using namespace std;

class Media{
    protected:
        string Ten;
        float Gia;
    public: 
        Media();
        Media(string Ten,float Gia);
        virtual void Enter() = 0;
        virtual void Print();
};
Media::Media (){
    Ten = "";
    Gia = 0;
}
Media::Media(string Ten,float Gia){
    this->Ten = Ten;
    this->Gia = Gia;
}
class Book : public Media{
    protected:
        int Trang;
        string TacGia;
    public:
        Book ();
        void Enter();
        void Print();
};
Book::Book(){
    this->Trang = 0;
    this->TacGia ="";
    this->Ten ="";
    this->Gia = 0;
}
class Video : public Media{
    protected:
        int Time;
        float Gia;
    public: 
        void Enter();
        void Print();
};

void Media::Enter(){
    fflush(stdin);
    cout << "Nhap Ten: ";
    getline (cin,Ten);
    cout << "Gia: ";
    cin >> Gia;
}

void Media::Print(){
    cout <<"Ten: "<<Ten<<endl;
    cout <<"Gia: "<<Gia<<endl;
}

void Book::Enter(){
    Media::Enter();
    fflush(stdin);
    cout << "Nhap Tac Gia: ";
    getline (cin,TacGia);
    cout << "Nhap Trang: ";
    cin >> Trang;
}

void Book::Print(){
    Media::Print();
    cout <<"Tac Gia: "<<TacGia<<endl;
    cout <<"Trang: "<<Trang<<endl;
}

void Video::Enter(){
    Media::Enter();
    fflush(stdin);
    cout << "Nhap Time: ";
    cin >> Time;
    cout << "Nhap Gia: ";
    cin >> Gia;
}

void Video::Print(){
    Media::Print();
    cout <<"Time: "<<Time<<endl;
    cout <<"Gia: "<<Gia<<endl;
}

int main(){
    Video *v = new Video [2];
    Book *b = new Book [2];
    for(int i = 0; i < 2; i++){
        (v+i)->Enter();
    }
    for(int i = 0; i < 2; i++){
        (v+i)->Print();
    }
    for(int i = 0; i < 2; i++){
        (b+i)->Enter();
    }
    for(int i = 0; i < 2; i++){
        (b+i)->Print();
    }
    return 0;
}