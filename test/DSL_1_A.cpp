#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp"
#include "../datastructure/unionfind.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;
    UnionFind Tree(N);
    while(Q--){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            Tree.unite(x, y);
        }
        if(com == 1){
            cout << Tree.same(x, y) << endl;
        }
    }
}