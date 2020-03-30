#ifndef PARTITION_NUMBER_CPP
#define PARTITION_NUMBER_CPP
#include "../macro/macros.hpp"
#include "mint.hpp"

/*
@title 分割数(Partition Number)
@category 写像12相
@docs ../docs/math/partition-number.md
*/

template<typename T = mint>
struct Partition{
    int N,K;
    vector<vector<mint>> Par;
    Partition(int _N, int _K):N(_N),K(_K),Par(N+1, vector<mint>(K+1, 0)){
        build();
    }
    void build(){
        for(int k = 0; k <= K;k++)Par[0][k] = 1;
        for(int n = 1; n <= N; n++){
            for(int k = 1; k <= K; k++){
                if(k-1 >= 0)Par[n][k] += Par[n][k-1];
                if(n-k >= 0)Par[n][k] += Par[n-k][k];
            }
        }
    }
    mint get(int n, int k){
        if(n < 0 || k < 0)return 0;
        return Par[n][k];
    }
};

#endif