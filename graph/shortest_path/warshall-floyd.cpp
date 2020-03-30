#ifndef WARSHALL_FLOYD_CPP
#define WARSHALL_FLOYD_CPP
/*
*/
#include "../../macro/macros.hpp"
#include "../template.hpp"

template<typename T>
class WarshallFloyd : public Graph<T>{
  public:
    using Graph<T>::N;
    using Graph<T>::G;
    T inf;
    vvec<T> d;
    WarshallFloyd(int _N, T _inf):Graph<T>::Graph(_N), inf(_inf), d(_N,vec<T>(_N,_inf)){}
    void solve(){
        //initialize the distance matrix
        d.assign(N, vec<T>(N,inf));
        for(int i = 0; i < N;i++) d[i][i] = 0;
        rep(i,N){
            for(auto e: G[i]){
                d[i][e.to] = e.cost;
            }
        }
        //WarshallFloyd
        for(int k = 0; k < N; k++)for(int i = 0; i < N; i++)for(int j = 0; j < N; j++){
            if(d[i][k] == inf || d[k][j] == inf)continue;
            chmin(d[i][j],d[i][k] + d[k][j]);
        }
    }
    bool negative_cycle(){
        for(int i = 0; i < N; i++)
            if(d[i][i] < 0)
                return true;
        return false;
    }
    void debug(){
        for(int i = 0; i < N; ++i){
            cerr<<i+1<<": ";
            for(auto e: G[i]){
                cerr<<"{"<<e.to+1<<", "<<e.cost<<"}, ";
            }
            cerr<<endl<<endl;
        }

        cerr<<"distance_matrix"<<endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(d[i][j] == inf){
                    cerr<<-1<<" ";
                }else cerr<<d[i][j]<<" ";
            }
            cerr<<endl;
        }
    }
};
#endif