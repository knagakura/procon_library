#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_K"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"

/*
@title 玉区別しない、箱区別しない、1個以内(0 or 1)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    cout << ((n <= k) ? 1: 0) << endl;
}