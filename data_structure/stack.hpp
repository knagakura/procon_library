#ifndef INCLUDED_STACK_HPP
#define INCLUDED_STACK_HPP
#include "../macro/macros.hpp"
/*
@title stack
*/
template< typename T >
class Stack{
  public:
    int N;
    int top = 0;
    T data[20000];
    Stack(int sz):N(sz), top(0){}
    void push(int x){
        if(isFull()){
            cerr << "これ以上入りません" << endl;
            return;
        }
        data[top] = x;
        top++;
    }
    int pop(){
        if(isEmpty()){
            cerr << "中身は空です" << endl;
            return -1;
        }
        top--;
        return data[top];
    }
    bool isFull(){
        return top >= N;
    }
    bool isEmpty(){
        return top == 0;
    }
    void show(){
        dump(top);
        for(int i = 0; i < top;i++){
            cerr << data[i] << " ";
        }
        cerr << endl;
    }
};
#endif