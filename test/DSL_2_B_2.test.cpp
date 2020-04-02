#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../macro/macros.hpp"
#include "../data_structure/segment-tree.cpp"

int main(){
    
    int N, Q;
    cin >> N >> Q;

    auto f = [&](long long a, long long b){
        return a + b;
    };
    auto g = [&](long long a, long long b){
        return a + b;
    };
    SegTree<long long> Tree(N,0LL,f,g);
    while(Q--){
        long long ord, x, y;
        cin >> ord >> x >> y;
        x--;
        if(ord == 0){
            Tree.change(x, y);
        }
        if(ord == 1){
            y--;
            cout << Tree.query(x, y+1) << endl;
        }
    }
}