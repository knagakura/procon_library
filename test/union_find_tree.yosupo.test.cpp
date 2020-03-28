#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../macro/macros.hpp"
#include "../data_structure/unionfind.hpp"

using namespace std;

int main() {
    int n, q; cin >> n >> q;
    UnionFind uft(n);
    rep (i, q) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) {
            uft.unite(u, v);
        } else if (t == 1) {
            cout << uft.same(u, v) << endl;
        }
    }
    return 0;
}
