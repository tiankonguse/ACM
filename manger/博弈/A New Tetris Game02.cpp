/*************************************************************************
    > File Name: A New Tetris Game02.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/15 22:35:58
 ************************************************************************/

#include <iostream>
#include <set>
#include <bitset>
#include <map>
//#include <algorithm>
using namespace std;

//better if find area that not linked and sg each
typedef bitset<32> int_set;
struct array2{
    bitset<64> bs;
    int r,c;
    bool operator<(const array2& a2)const{
        if(r!=a2.r)return r<a2.r;
        if(c!=a2.c)return c<a2.c;
        return *(long long*)&bs< *(long long*)&a2.bs;
    }
    bitset<64>::reference operator()(int ir,int ic){
        return bs[ir*c+ic];
    }
}g;
inline int mex(const int_set& is){
    if(is.none())return 0;
    for(int i=0;i!=32;++i){ //assum i will never exceed 32
        if(is.test(i)==0)
            return i;
    }
}
inline bool check_ok(int ir,int ic){
    return !g(ir,ic)&&!g(ir+1,ic)&&!g(ir,ic+1)&&!g(ir+1,ic+1);
}
map<array2,int> ma;
inline void set_it(int ir,int ic,int s){
    g(ir,ic)=s;
    g(ir+1,ic)=s;
    g(ir,ic+1)=s;
    g(ir+1,ic+1)=s;
}
inline int sg(int r,int c){
    map<array2,int>::iterator p=ma.find(g);//optimizing for the repeated
    if(p!=ma.end())return p->second;
    int_set sgs;
    for(int i=0;i<r-1;++i)
        for(int j=0;j<c-1;++j)
            if(check_ok(i,j)){
                set_it(i,j,1);
                sgs.set(sg(r,c));
                set_it(i,j,0);
            }
    return ma[g]=mex(sgs);
}
int main(){
    int n;
    while(cin>>n){
        int out=0;
        while(n--){
            int r,c;
            cin>>g.r >>g.c;
            for(int i=0;i!=g.r;++i)
                for(int j=0;j!=g.c;++j){
                    char c;
                    cin>>c;
                   g(i,j)=c-'0';
                }
                out^=sg(g.r,g.c);
         }
        cout<<(out?"Yes":"No")<<endl;
    }
    return 0;
}
