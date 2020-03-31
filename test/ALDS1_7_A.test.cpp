#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A"
#include "../macro/macros.hpp"
#include "../tree/rooted-tree.cpp"
/*
*/

int main(){
    int N;
    cin >> N;
    Rooted_Tree G(N);
    for(int i = 0; i < N;i++){
        int from, k, to;
        cin >> from >> k;
        for(int j = 0; j < k;j++){
            cin >> to;
            G.add_directed_edge(from, to);
        }
    }
    G.build();
    G.Cout();
}