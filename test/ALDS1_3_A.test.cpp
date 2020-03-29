#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp"
#include "../macro/macros.hpp"
#include "../data_structure/stack.hpp"

int main(){
    Stack<int> S(1000);
    string c;
    while(cin >> c){
        if(c == "+"){
            int a = S.pop();
            int b = S.pop();
            S.push(b + a);
        }
        else if(c == "-"){
            int a = S.pop();
            int b = S.pop();
            S.push(b - a);
        }
        else if(c == "*"){
            int a = S.pop();
            int b = S.pop();
            S.push(b * a);
        }
        else{
            int x = stoi(c);
            S.push(x);
        }
    }
    cout << S.pop() << endl;
}
