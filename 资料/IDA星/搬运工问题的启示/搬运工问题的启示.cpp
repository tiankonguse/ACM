/*************************************************************************
    > File Name: 搬运工问题的启示.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/23 15:42:48
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T{
    int g;
};

stack<T>OpenStack;
int ResourceLimitsReached;
int H(T& State){
    return 0;
}

void Push(stack<T>&OpenStack, T& State){
    OpenStack.push(State);
}

T Pop(stack<T>&OpenStack){
    T top = OpenStack.top();OpenStack.pop();
    return top;
}
bool empty(stack<T>&OpenStack){
    return OpenStack.empty();
}

bool Solution(T& State){
    return true;
}


void IDA_STAR(T StartState){
    int PathLimit = H(StartState) - 1;
    bool Success =  false;
    T CurrentState;
    while(1){
        PathLimit++;
        StartState.g = 0;
        Push(OpenStack, StartState);
        while(1){
            CurrentState = Pop(OpenStack);
            if(Solution(CurrentState)){
                Success = true;
            }else if(PathLimit >= CurrentState.g + H(CurrentState)){
//　　　    Foreach Child(CurrentState) do
//　　　      Push(OpenStack, Child(CurrentState));
            }
             if(Success || empty(OpenStack))break;
        }
        if(Success || ResourceLimitsReached)break;
    }

}



int main() {

    return 0;
}
