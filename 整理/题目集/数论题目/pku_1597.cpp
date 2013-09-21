#include <iostream>
using namespace std;

int main()
{
    long step, mod, seed, i;
    while (cin>>step>>mod) {
        seed = 0;
        bool bGood = true;
        for (i = 1; i < mod; ++i) {
            seed = (seed+step)%mod;
            if (seed == 0) { 
                //不断取模,余数最终会形成一个循环,因为开始为0,
                //所以,如果在求出第mod个余数之前又出现了余数0,则为bad
                bGood = false;
                break;
            }
        }
        if (bGood == true)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);
    }
    return 0;
}


/*
AC
#include <iostream>
using namespace std;

int main()
{
    bool bFlags[100001];
    long step, mod, seed, i;
    while (cin>>step>>mod) {
        memset(bFlags, false, 100001);
        seed = 0;
        bFlags[0] = true;
        bool bGood = true;
        for (i = 1; i < mod; ++i) {
            seed = (seed+step)%mod;
            if (seed == 0) { //不断取模,余数最终会形成一个循环,因为开始为0,
                //所以,如果在求出第mod个余数之前又出现了余数0,则为bad
            //if (bFlags[seed] == true) {//这个余数已经出现过了
                bGood = false;
                break;
            }
            else 
                bFlags[seed] = true;
        }
        if (bGood == true)
            printf("%10d%10d    Good Choice\n\n", step, mod);
        else
            printf("%10d%10d    Bad Choice\n\n", step, mod);
    }
    return 0;
}
*/