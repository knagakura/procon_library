#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"
#include "../macro/macros.hpp"
#include "../tree/template.cpp"
#include "../tree/tree-diameter.cpp"


int main(){
    int N;
    cin >> N;
    Diameter<long long> G(N);
    G.input(N-1, 0, true, false);
    G.build(N/2);
    cout << G.get_diameter() << endl;
}