// Sử dụng ngôn ngữ lập trình C++:
// 1. Xây dựng LỚP SinhVien (Sinh viên) gồm các thuộc tính: MSV (Mã sinh viên),
// Hoten (Họ tên), NS (Năm sinh), Lop (Lớp) và DTB (Điểm trung bình).
// Xây dựng các hàm toán tử nhập, xuất, so sánh, …đối tượng sinh viên. Từ đó:
// 2. Nhập một danh sách n sinh viên, xuất danh sách sinh viên trên ra màn hình theo
// dạng: dòng đầu là số thứ tự sinh viên, trên mỗi 5 dòng tiếp theo là các thông tin
// (MSV, Hoten, NS, Lop và DTB) của một sinh viên.
// 3. Sắp xếp các sinh viên theo thứ tự ĐTB giảm dần và in danh sách đã được sắp xếp
// ra màn hình.
// 4. Sắp xếp các sinh viên theo thứ tự Năm sinh tăng dần và xuất danh sách ra màn
// hình.
// 5. Thống kê số lượng sinh viên thuộc diện cảnh báo học tập, biết rằng nếu điểm trung
// bình < 1.0 thì sinh viên thuộc diện cảnh báo học tập.
// 6. Viết hàm main sử dụng các hàm đã viết ở trên và hoàn thiện chương trình.
//Phạm Nguyễn Thùy Dung
//MSSV:6151071003
#include <iostream>
using namespace std;
class SinhVien {
    private: 
        string ten;
        string mssv;
        string lop;
        int nam;
        float diem;
    public:
        friend istream& operator >>(istream& is, SinhVien& sv);
        friend ostream& operator <<(ostream& os, const SinhVien& sv);
        bool operator < (SinhVien sv);
        bool operator > (SinhVien sv);
        float getdiem(){
            return diem;
        }
        int getnam (){
            return nam;
        }
};
istream& operator >>(istream& is, SinhVien& sv){
    fflush (stdin);
    cout << "Nhap Ma So Sinh Vien: ";
    getline(is, sv.mssv);
    cout << "Nhap Ho Va Ten: ";
    getline(is, sv.ten);
    cout << "Nhap lop: ";
    getline(cin, sv.lop);
    cout << "Nhap Ngay Sinh: ";
    is >> sv.nam;
    cout << "Nhap Diem Trung Binh: ";
    is >> sv.diem;
    return is;
}
void nhap (SinhVien sv[], int n){
    for(int i=0; i<n; i++){
        cout<<"***Nhap Sinh Vien "<< i+1 <<endl;
        cin>>sv[i];
    }
}
void xuat(SinhVien sv[], int n){
    for(int i=0; i<n; i++){
        cout<<"STT "<<i+1;
        cout<<sv[i]<<endl;
    }
}
ostream& operator <<(ostream& os, const SinhVien& sv) {
    os << " MSSV: " <<sv.mssv<<" |Ho Ten: " << sv.ten <<" |Nam Sinh: "<< sv.nam <<" |Lop: "<<sv.lop<<" |Diem Trung Binh: " << sv.diem <<endl;
    return os;
}
bool SinhVien::operator<(SinhVien s){
    return diem < s.diem;
}
bool SinhVien::operator>(SinhVien s){
    return nam > s.nam;
}
void sapxeptb(SinhVien sv[], int n){
    SinhVien temp;
    for(int i = 0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
             if(sv[i] < sv[j]){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void sapxepnam(SinhVien sv[], int n){
    SinhVien temp;
    for(int i = 0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
             if(sv[i] > sv[j]){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
int canhbao(SinhVien sv[], int n){
    int count = 0;
    for(int i=0; i<n;i++){
        if(sv[i].getdiem()<1.0){
            count++;
        }
    }
    return count;
}
int main (){
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien sv[n];
    nhap (sv,n);
    xuat (sv,n);
    sapxeptb(sv,n);
    cout<<"Sap xep theo diem trung binh :"<<endl;
    xuat (sv,n);
    sapxepnam (sv,n);
    cout<<"Sap xep theo nam sinh :"<<endl;
    xuat (sv,n);
    cout <<"Co "<<canhbao(sv,n)<<" ban bi canh bao hoc tap!";
}