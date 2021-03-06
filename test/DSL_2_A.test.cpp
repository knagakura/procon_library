#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../macro/macros.hpp"
#include "../data_structure/segment-tree.cpp"

int main(){
    
    int N, Q;
    cin >> N >> Q;
    long long inf = (1LL << 31) - 1;
    auto f = [&](long long a, long long b){
        return min(a, b);
    };
    auto g = [&](long long a, long long b){
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