#include <string.h>
#include <iostream>
using namespace std;

class A{
    private:
    int a;
    int b;
    public:
    int x=10, y=10;
    A(int a, int b){
        this->a = a;
        this->b = b;
        //this->a 멤버 a는 매개 변수
    }
    void printing(){
        cout <<this ->a <<endl;
        cout <<this ->b <<endl;
        
    }
    protected:
        float z;
        float w;
};

template <unsigned N>
struct Fibonacci
{
    enum
    {
        value = Fibonacci<N-1>::vlaue + Fibonacci<N-2>::value}
    };
};


// T sum (T a, T b){
//     return a + b;
// }





void ClassFunc(A x){
    for(int i = 0; i<x.x; i++){
    for(int j = 0; j<x.y; j++){
        cout<<"*";
    }
        cout<<"\n";
    }
}


int main(){
    Stack<char> stack(10); stack.Push('A'); 
    stack.Push('B'); stack.Push('C'); 
    for(int i=0;i<3; i++) 
    { cout<<stack.Pop()<<endl; }
    Stack<int> stack2(10); 
    stack2.Push(10); 
    stack2.Push(20);
    stack2.Push(30); 
    for(int j=0; j<3; j++) 
    { 
        cout<<stack2.Pop()<<endl; 
    } 
    return 0; 

    // A as(2,3);
    // as.printing();
    // cout << "sum " << sum<double>(d1,d2) <<endl;
    return 0;
}