#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja"

#include "../macro/macros.hpp"
#include "../tree/lca.cpp"

int main() {
    int N;
    cin >> N;
    LCA<long long> G(N);
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        while(k--){
            int a;
            cin >> a;
            G.add_edge(i, a);
        }
    }
    G.dfs();
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << G.lca(a, b) << endl;
    }
}