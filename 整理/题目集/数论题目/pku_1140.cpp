#include<iostream>
#include<string>
#include<vector>
using namespace std;

inline void print_str(string str)
{
    while(str.length() > 50) 
    {
        cout<<str.substr(0,50)<<endl;
        str = str.substr(50);
    }
    cout<<str<<endl;
}

int main()
{
    string chars = "0123456789";
    long a, b;
    string str;
    vector<long> pos;
    while(cin>>a>>b && a+b) 
    {
        pos.assign(b, -1);
        str = ".";
        int i = 0;
        pos[a] = 0;//因为a<b,所以个位一定为0
        while(1)
        {
            ++i;//计算小数的第i位, 从1开始
            a *= 10;
            str += chars[a/b]; 
            a %= b;
            if(a == 0)//余数为零,除法结束
            {
                print_str(str);
                puts("This expansion terminates.");
                break;
            }
            else if(pos[a] != -1)//余数a之前已经出现过,产生循环
            {
                print_str(str);
                printf("The last %d digits repeat forever.\n", i-pos[a]);
                break;
            }
            else 
                pos[a] = i;//计算结果小数中的第1位是,余数为a         
        }
    }
    return 0;
}
