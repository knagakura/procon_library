#ifndef WARSHALL_FLOYD_CPP
#define WARSHALL_FLOYD_CPP
/*
*/
#include "../../macro/macros.hpp"
#include "../template.hpp"

template<typename T>
class WarshallFloyd : public Graph<T>{
  public:
    using Graph<T>::Graph;
    int N;
    vvec<T> d;
    T inf;
    WarshallFloyd(int _N, T _inf):N(_N), Graph<T>::Graph(_N), inf(_inf), d(_N,vec<T>(_N,_inf)){}
    void solve(){
        //initialize the distance matrix
        d.assign(N, vec<T>(N,inf));
        for(int i = 0; i < N;i++) d[i][i] = 0;
        auto edges = Graph<T>::G;
        rep(i,N){
            for(auto e: edges[i]){
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
        auto edges = Graph<T>::G;
        for(int i = 0; i < N; ++i){
            cerr<<i+1<<": ";
            for(auto e:edges[i]){
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