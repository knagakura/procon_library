#ifndef LAZY_SEGMENT_TREE_RAQ_CPP
#define LAZY_SEGMENT_TREE_RAQ_CPP
#include "../macro/macros.hpp"

/*
@title 遅延評価セグメント木(Lazy Segment Tree) 区間加算
@category データ構造
*/
template<typename T>
class LazySegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    vector<T> lazy;//遅延評価
    void _add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else{
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }
    }
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return c1 + c2;
    }
    //コンストラクター
    LazySegTree(vector<T> v){
        int sz = v.size();
        N = 1;
        while(N < sz)N *= 2;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];
        for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];
    }
    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k] == 0)return;
        data[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x){
        _add(a, b, x, 0, 0, N);
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};

#endif