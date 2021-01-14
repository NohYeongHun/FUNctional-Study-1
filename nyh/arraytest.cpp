#include <string.h>
#include <iostream>
using namespace std;
// void arrayTest(){
//     char data[5];
//     for(int index=0; index<6; index++){
//         data[index] = index;
//     }
// }

// void Stest(struct Dstruct Dt){
//     if(Dt.st > (a+b)){
//         Dt.st = a;
//     }else {
//         Dt.ru = b;
//     }
// }


union UBox{
    bool a;
    int x,y;
};


void UnionFunc(UBox* up){
    up->x = 10;
}

// void atx(UB.dollar, UB.aka){
//     if(UB.dollar > UB.aka){
//         cout <<UB.dollar <<endl;
//     }else{
//         cout <<UB.aka;
//     }
// }
// void abc(int a, int b){
//     int *k;
//     cout << *k << endl;
// }

// 클래스 심볼  parameter 클래스
int main(){
    UBox u1;
    UnionFunc(&u1);
    cout << u1.x <<endl;


    // altx(5,5.5);
    // abc();
    // int *p;
    // abc(&p);
    return 0;
}
