#include <iostream>
#define MAX 100
using namespace std;
 struct point {
	float x, y;
};
void enter(point p) {
	cin >> p.x;
	cin >> p.y;
}
void pintf(point p){
    cout<<"p ("<<p.x<<p.y<<")"<<endl;
}
void enter_n(point p[], int n) {
	for (int i = 0; i < n; i++) {
		enter(p);
	}
}
void sort(int c, point p[], int n) {
    for(int i=0;i<n;i++){
        if(sprt(pow(p[i].x-0),2)+pow(p[i.y,2))>sprt(pow(p[i+1].x-0),2)+pow(p[i+1].y,2)){
            swap (p[i], p[i+1]);
        }
    }

}
void 
int main()
{
	;
