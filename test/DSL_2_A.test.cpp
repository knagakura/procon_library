#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../macro/macros.hpp"
#include "../data_structure/segment-tree.cpp"

int main(){
    
    int N, Q;
    cin >> N >> Q;
    long long inf = (1LL << 31) - 1;
    auto f = [&](int a, int b){
        return min(a, b);
    };
    auto g = [&](int a, int b){
        return b;
    };
    SegTree<long long> Tree(N,inf,f,g);
    while(Q--){
        long long ord, x, y;
        cin >> ord >> x >> y;
        if(ord == 0){
            Tree.change(x, y);
        }
        if(ord == 1){
            cout << Tree.query(x, y+1) << endl;
        }
    }
}