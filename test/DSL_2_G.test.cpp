#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include "../macro/macros.hpp"
#include "../data_structure/lazy-segment-tree-raq.cpp"


int main(){
    int N, Q;
    cin >> N >> Q;
    vector<long long> v(N,0);
    LazySegTree<long long> Seg(v);
    while(Q--){
        int ord;
        cin >> ord;
        if(ord == 0){
            int s, t;
            long long x;
            cin >> s >> t >> x;
            s--;t--;
            Seg.add(s, t+1, x);
        }
        if(ord == 1){
            int s, t;
            cin >> s >> t;
            s--;t--;
            cout << Seg.query(s, t+1) << endl;
        }
    }
}