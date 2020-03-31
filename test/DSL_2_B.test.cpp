#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../macro/macros.hpp"
#include "../data_structure/bit.cpp"

int main(){
    int n, q;
    cin >> n >> q;
    BIT<long long> Bit(n);
    while(q--){
        int ord, x, y;
        cin >> ord >> x >> y;
        if(ord == 0){
            Bit.add(x, y);
        }
        if(ord == 1){
            cout << Bit.sum(x, y) << endl;
        }
    }
}