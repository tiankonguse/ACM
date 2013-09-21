
//pku-1067-取石子游戏(博弈论->威佐夫博奕)
#include <iostream>
#include <cmath>
using namespace std;

const double q = (1+sqrt(5.0))/2.0; //黄金分割数
unsigned long a, b;

bool WythoffGame_win()
{
    /*
    对于第k种奇异局势(ak,bk),应该有ak = k*q;
    首先,假设(a,b)为第k种奇异局势(k=0,1,2,...),那么将有k=(b-a),
    然后,再判断a与(int)(k*q),若相等,则为奇异局势,必败;否则必胜.
    */
    if (a > b)
        std::swap(a, b);
    int k = b-a;
    if (a == (unsigned long)(k*q)) {
        return false;
    }
    return true;    
}

int main()
{
    while(cin>>a>>b) {
        cout<<WythoffGame_win()<<endl;
    }
    return 0;
}
