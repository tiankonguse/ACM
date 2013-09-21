#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<algorithm>
#include<vector>
#include<functional>

#define PI acos(-1.0);
#define inf 0x3ffffffff;
using namespace std;
const int N = 100005;
bool pro_first[N];
bool pro_second[N];
int isprime[N],a[N]= {0};
map<string,int>Map;


struct T
{
    char name[40];
    char _name[40];
    char team[40];
    char sex[5];
    int pro_num;
    int contest_num;
    double contest_str[1010];
    double score;

} info[555];
int cmp(T a,T b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else return strcmp(a._name,b._name)<0;
}
int getscore(int x)
{
    if(x==1)return 36;
    if(x==2)return 27;
    if(x==3)return 18;
    return 0;

}
int main()
{

    int n,m,nm,r,s,tmp,q,i,j;
    char _string_tmp[40];
    int cas,ans;
    scanf("%d",&cas);
    memset(a,0,sizeof(a));
    for(i=2; i<=10000; i++)
    {
        if(a[i]==0)
        {
            isprime[i]=1;
            for(j=i+i; j<=10000; j+=i)
                a[j]=1;
        }
    }
    while(cas--)
    {
        memset(pro_first,false,sizeof(pro_first));
        memset(pro_second,false,sizeof(pro_second));
        scanf("%d%d",&n,&m);
        scanf("%d",&r);

        while(r--)
        {
            scanf("%d",&tmp);
            pro_first[tmp] = true;
        }
        scanf("%d",&s);

        while(s--)
        {
            scanf("%d",&tmp);
            pro_second[tmp] = true;
        }
        Map.clear();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s%d",_string_tmp,&tmp);
            Map[_string_tmp] = tmp;
        }
        for(i=0; i<n; i++)
        {
            info[i].score=0;
            scanf("%s%s%s",info[i].name,info[i].team,info[i].sex);
            for(j=0;info[i].name[j];j++){
                if(info[i].name[j] >='A' && info[i].name[j]<='Z'){
                    info[i]._name[j] = info[i].name[j] - 'A' + 'a';
                }else{
                    info[i]._name[j] = info[i].name[j];
                }
            }

            if(info[i].sex[0]=='F')info[i].score+=33;

            tmp =Map[info[i].team] ;
            info[i].score+=getscore(tmp);

            scanf("%d",&info[i].pro_num);
            scanf("%d",&info[i].contest_num);
            //cout<< info[i].score <<" #$#### "<<endl;
            while(info[i].pro_num--)
            {
                scanf("%d",&tmp);
                double scores=0;
                bool ok = false;
                if(pro_first[tmp])
                {
                    info[i].score+=2.5,scores = 2.5;
                    ok = true;
                }

                else if(pro_second[tmp])
                {
                    info[i].score+=1.5,scores = 1.5;
                     ok = true;
                }

                else if(isprime[tmp])
                {
                    info[i].score+=1.0,scores = 1.0;
                     ok = true;
                }

                else if(!ok){
                    info[i].score+=0.3,scores = 0.3;
                }
            }
            for(j=0; j<info[i].contest_num; j++)
            {
                scanf("%lf",&info[i].contest_str[j]);
            }
            // cout<<i<< " $$$$$$$$$$$ "<<info[i].score<<endl;
            if(info[i].contest_num>=3)
            {
                sort(info[i].contest_str,info[i].contest_str+info[i].contest_num);
                double dtmp = info[i].contest_str[info[i].contest_num-3];

                if((dtmp - 1200) >0)info[i].score +=  (dtmp - 1200)*1.0 / 100* 1.5;

            }
            //cout<<i<< " ****** "<<info[i].score<<endl;

        }
        sort(info,info+n,cmp);

        for(i=0; i<m; i++)
        {
            printf("%s %.3f\n",info[i].name,info[i].score);
        }



    }

    return 0;
}
