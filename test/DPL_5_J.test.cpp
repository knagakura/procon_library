#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_J"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/partition-number.cpp"
/*
@title 玉区別しない、箱区別しない、制限なし(分割数$P(n,k)$)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    Partition<mint> Par(n, k);
    cout << Par.get(n, k) << endl;
}