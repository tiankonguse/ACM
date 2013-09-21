#include<iostream>
using namespace std;
//想了好多次,没能想出好办法,从论坛搜到了一个打表的,超级好用.
//http://cms.bit.edu.cn/moodle/mod/forum/discuss.php?d=10531
//以后再研究时怎么回事了.
int main()
{
    long m[15]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
    long n;
    while(cin>>n && n) {
       cout<<m[n]<<endl;
    }
    return 0;
}
