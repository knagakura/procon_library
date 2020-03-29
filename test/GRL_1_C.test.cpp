#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"
#include "../macro/macros.hpp"
#include "../graph/template.hpp"
#include "../graph/shortest_path/warshall-floyd.cpp"

//#define IGNORE
int main(){
    ll V, E;
    cin >> V >> E;
    WarshallFloyd<ll> G(V,INFLL);
    G.input(E, 0, true, true);
    G.solve();
    if(G.negative_cycle()){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for(int i = 0; i < V; i++)for(int j = 0; j < V; j++){
        if(G.d[i][j] == G.inf){
            cout << "INF";
        }
        else{
            cout << G.d[i][j];
        }
        if(j == V-1)cout << endl;
        else cout << " ";
    }
}