/*
pku-2181 Jumping Cows
http://acm.pku.edu.cn/JudgeOnline/problem?id=2181

把给定的一系列值在坐标系中表示出来,连接起来就是一条波形曲线,
由于奇数次跳是增加,偶数次跳是减少.所以奇数次跳要加上处于"波峰"处的值,
偶数次跳要减去处于"波谷"出的值,并且保证整个过程中的跳跃次数是奇数次,就
可以求得最后的正确结果.
*/


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    
    int p;
    cin>>p;
    vector<double> v(p,0);
    vector<double> res;
    
    int i, j;
    for (i = 0; i < p ; ++i) {
        cin>>v[i];
    }
    double pre = INT_MIN;
    int c = 0;
    for (i = 0; i < p; ++i) {
        j = i;
        if (c == 0) {
            while (j+1 < p && v[j+1] > v[j]) {
                pre = v[j++];
            }
            res.push_back(v[j]);
            //cout<<"正数"<<v[j]<<endl;
        }
        if (c == 1) {
            while (j+1 < p  && v[j+1] < v[j]) {
                pre = v[j++];
            } 
            res.push_back(-v[j]);
           // cout<<"负数: "<<-v[j]<<endl;
        }
        i = j;
        c = (c+1)%2;  
    }

    if (res[res.size()-1] < 0) { //如果最后一步的值为负,则取消,相当于退回一步
        res[res.size()-1] = 0;
    }
    printf("%.lf\n",accumulate(res.begin(), res.end(), 0.0) );
    
    return 0;
}


