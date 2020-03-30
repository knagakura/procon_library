#ifndef BELL_NUMBER_2_CPP
#define BELL_NUMBER_2_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"
#include "stiring-number-second.cpp"
/*
@title ベル数($O(NK\log N)$)
@docs ../docs/math/bell-number-2.md
*/
mint bell_number_2(int n, int k){
    mint res = 0;
    for(int j = 0; j <= k;j++){
        res += stirling_number_second(n, j);
    }
    return res;
}

#endif