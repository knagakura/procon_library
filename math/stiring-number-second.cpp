#ifndef STIRING_NUMBER_SECOND_CPP
#define STIRING_NUMBER_SECOND_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"

/*
@title 第二種スターリング数
*/
mint stirling_number_second(int n, int k){
    combination C(k+1);
    mint res = 0;
    for(int i = 0; i <= k;i++){
        mint x = C.Comb(k, i) * mint(k-i).modpow(n);
        res += (i & 1) ? -x:x;
    }
    res *= C.ifact[k];
    return res;
}

#endif