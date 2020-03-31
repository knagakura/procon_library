#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_B"
#include "../macro/macros.hpp"
#include "../tree/binary-tree.cpp"
/*
*/

int main(){
    int N;
    cin >> N;
    Binary_Tree G(N);
    for(int i = 0; i < N;i++){
        int from, l, r;
        cin >> from >> l >> r;
        if(l != -1)G.add_directed_edge(from, l);
        if(r != -1)G.add_directed_edge(from, r);
        if(l != -1 && r != -1){
            G.set_sibling(l, r);
        }
    }
    G.build();
    G.Cout();
}