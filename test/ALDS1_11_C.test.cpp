#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
#include "../macro/macros.hpp"
#include "../graph/template.hpp"
#include "../graph/shortest_path/bfs.hpp"

int main(){
    int N;
    cin >> N;
    BFS<int> G(N);
    rep(i,N){
        int u, k;
        cin >> u >> k;
        u--;
        rep(j,k){
            int v;
            cin >> v;
            v--;
            G.add_Directed_edge(u, v);
        }
    }
    G.bfs();
    rep(i,N){
        cout << i + 1 << " " << G.d[i] << endl;
    }
}