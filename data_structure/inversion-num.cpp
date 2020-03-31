#ifndef INVERSION_NUM_CPP
#define INVERSION_NUM_CPP
#include "../macro/macros.hpp"
#include "../data_structure/bit.cpp"
/*
@title 転倒数(The Number of Inversion)
@category データ構造
@docs ../docs/data_structure/inversion-num.md
*/
template<typename T> 
T Inversion_num(vector<T>& v){
    int N = v.size();
    BIT<T> Tree(N);
    vector<int> B(N);
    vector<pair<T, int>> ap;
    for(int i = 0; i < N; i++){
        ap.push_back(make_pair(v[i],i));
    }
    sort(all(ap));
    for(int i = 0; i < N; i++){
        B[ap[i].second] =  i;
    }
    T res = 0;
    for(int i = 0; i < N; i++){
        res += i - Tree.sum0(B[i]);
        Tree.add0(B[i], 1);
    }
    return res;
}
#endif