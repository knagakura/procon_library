#ifndef BELL_NUMBER_CPP
#define BELL_NUMBER_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"
#include "stiring-number-second.cpp"
/*
@title ベル数($O(\min(N,K) \log N)$)
@docs ../docs/math/bell-number.md
*/
template<typename T>
mint bell_number(T n, T k){
    combination C(max(n, k)+1);
    vector<mint> temp(k+1);
    temp[0] = 1;
    for(int j = 1; j <= k;j++){
        temp[j] = temp[j-1] + ((j & 1) ? -C.ifact[j]: C.ifact[j]);
    }
    mint res = 0;
    for(int i = 0; i <= k;i++){
        res += mint(i).modpow(n) * C.ifact[i] * temp[k-i];
    }
    return res;
}

#endif