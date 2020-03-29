#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp"
#include "../macro/macros.hpp"
template< typename T >
class Stack{
  public:
    int N;
    int top = 0;
    T data[20000];
    Stack(int sz):N(sz), top(0){}
    void push(int x){
        if(isFull()){
            cerr << "これ以上入りません" << endl;
            return;
        }
        data[top] = x;
        top++;
    }
    int pop(){
        if(isEmpty()){
            cerr << "中身は空です" << endl;
            return -1;
        }
        top--;
        return data[top];
    }
    bool isFull(){
        return top >= N;
    }
    bool isEmpty(){
        return top == 0;
    }
    void show(){
        dump(top);
        for(int i = 0; i < top;i++){
            cerr << data[i] << " ";
        }
        cerr << endl;
    }
};
int main(){
    Stack<int> S(1000);
    string c;
    while(cin >> c){
        if(c == "+"){
            int a = S.pop();
            int b = S.pop();
            //cerr << a << " " << b << endl;
            S.push(b + a);
        }
        else if(c == "-"){
            int a = S.pop();
            int b = S.pop();
            //cerr << a << " " << b << endl;
            S.push(b - a);
        }
        else if(c == "*"){
            int a = S.pop();
            int b = S.pop();
            //cerr << a << " " << b << endl;
            S.push(b * a);
        }
        else{
            int x = stoi(c);
            S.push(x);
        }
        //S.show();
    }
    cout << S.pop() << endl;
}