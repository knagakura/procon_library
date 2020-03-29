#ifndef COMB_HPP
#define COMB_HPP
#include "../macro/macros.hpp"
#include "mint.hpp"

/*
@title 組み合わせ(Combination)
*/
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint Comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
    mint H(int n, int m){
        return Comb(n + m - 1, m);
    }
    //nPk
    mint Perm(int n, int k){
        if (k < 0 || n < k) return 0;
        return fact[n]*ifact[n-k];
    }
};
#endif