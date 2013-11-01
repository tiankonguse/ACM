#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
typedef long long LL;
const int N = 110000;

struct T{
    int id,val;
    T(int id=0,int val=0):id(id),val(val){}
    bool operator<(const T a)const{
        return this->val <= a.val;
    }
};

stack<int>sta;
queue<int>que;
deque<int>deq;
priority_queue<T>heap;
bool have[N];
int str[N];

void init(){
    memset(have,false,sizeof(have));
    while(!sta.empty()){
        sta.pop();
    }
    while(!que.empty()){
        que.pop();
    }
    while(!deq.empty()){
        deq.pop_front();
    }
    while(!heap.empty()){
        heap.pop();
    }
}

int main() {
    int n,i,num,k;
    while(~scanf("%d",&n)){
        init();
        for(i=0;i<n;i++){
            scanf("%d",&str[i]);
            if(str[i] == 0){
                num = 3;
                while(num-- && !heap.empty()){
                    have[heap.top().id] = true;
                    heap.pop();
                }
                while(!heap.empty()){
                    heap.pop();
                }
            }else{
                heap.push(T(i,str[i]));
            }
        }

        for(i=0;i<n;i++){
            if(str[i] == 0){
                if(!sta.empty()){
                    k = 1;
                    sta.pop();

                    while(!que.empty()){
                        k++;
                        que.pop();
                    }

                    while(!deq.empty()){
                        k++;
                        deq.pop_front();
                    }

                    printf("%d",k);
                    if(k == 1){
                        printf(" popStack\n");
                    }else if(k == 2){
                        printf(" popStack popQueue\n");
                    }else{
                        printf(" popStack popQueue popFront\n");
                    }
                }else{
                    printf("0\n");
                }
            }else{
                if(have[i]){
                    if(sta.size() > que.size()){
                        que.push(1);
                        printf("pushQueue\n");
                    }else if(que.size() > deq.size()){
                        deq.push_front(1);
                        printf("pushFront\n");
                    }else{
                        sta.push(1);
                        printf("pushStack\n");
                    }
                }else{
                    printf("pushBack\n");
                }
            }
        }

    }
    return 0;
}






