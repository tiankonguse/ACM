#include<iostream>
using namespace std;
#include<string>
int N;//字符长度
char s[5001],_s[5001];//原字符,和逆序字符
short int D[5001][5001];//用来保存I,J个字符的最大子串
int main()
{               
    memset(D,0,sizeof(D));
    cin>>N;    
    string tem;    
    cin>>tem;        
    for (int i=0;i<N;i++)
    {        
        s[i+1]=tem[i];
        _s[i+1]=tem[N-i-1];
    }//输入数据结束     
    for (int i=1;i<=N;i++)
    {
        for (int j=1;j<=N;j++)
        {
            if (s[i]==_s[j])
            {

                D[i][j]=D[i-1][j-1]+1;              
            }
            else
            {

                D[i][j]=max(D[i-1][j],D[i][j-1]);
            }
        }
    }  //从下往上递归,注意要满足无后效性才行.
    cout<<N-D[N][N]<<endl;    
    return 0;
}

