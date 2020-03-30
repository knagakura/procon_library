#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"
#include "../macro/macros.hpp"
#include "../tree/template.cpp"
#include "../tree/tree-diameter-height.cpp"


int main(){
    int N;
    cin >> N;
    Tree_DH<long long> G(N);
    G.input(N-1, 0, true, false);
    G.build();
    auto ans = G.get_height();
    for(auto x: ans){
        cout << x << endl;
    }
}