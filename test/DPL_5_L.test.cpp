#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/partition-number.cpp"
/*
@title 玉区別しない、箱区別しない、1個以上(分割数$P(n-k,k)$)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    Partition<mint> Par(n, k);
    cout << Par.get(n-k, k) << endl;
}