#ifndef STIRING_NUMBER_SECOND_DP_CPP
#define STIRING_NUMBER_SECOND_DP_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"
#include "comb.hpp"

/*
@title 第二種スターリング数(DP($O(N^2)))
@category 写像12相
@docs ../docs/math/stiring-number-second-dp.md
*/
template<typename T = mint>
struct Stiring_dp{
    int N;
    vector<vector<mint>> S;
    Stiring_dp(int _N):N(_N), S(N+1, vector<mint>(N+1, 0)){
        build();
    }
    void build(){
        S[0][0] = 1;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                S[i][j] = S[i-1][j-1] + mint(j)*S[i-1][j];
            }
        }
    }
    mint get(int n, int k){
        if(n < 0 || k < 0 || n < k)return 0;
        return S[n][k];
    }
};

#endif