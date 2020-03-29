#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"
/*
@title 玉区別する、箱区別する、1個以上($\sum_{i=0}^{k} (-1)^{i} {}_k{\rm C}_{i} (k-i)^n$)
@category 写像12相
*/
combination C(200010);
int main(){
    int n, k;
    cin >> n >> k;
    mint ans = 0;
    for(int i = 0; i <= k;i++){
        mint x = C.Comb(k, i) * mint(k-i).modpow(n);
        ans += (i & 1) ? -x:x;
    }
    cout << ans << endl;
}
