#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja"

#include "../macro/macros.hpp"
#include "../tree/lca.cpp"

int main() {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k;j++){
            int a;
            cin >> a;
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    LCA G(N, g);
    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << G.lca(a, b) << endl;
    }
}