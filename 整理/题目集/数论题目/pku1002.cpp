/*
最初思路:
    将转换为数字存入数组后，排序，然后遍历输出重复出现的号码和次数。
这样,即使是用快排，时间代价也是O(N*log2N+N),根据题目中的数据量，一定
会超时的,所以必须找到一种线性时间能完成的方法.
    也正是用了以上方法,修改了很多次都TLE,很是烦人.
改进:
    采用折半插入的方法存储转换后的数据,这样就能保证数据是有序存储的,输入结束后,
直接遍历输出重复的元素即可.

另辟蹊径:    
    为了实现起来简便,用了STL标准库中的map容器,因为其内部是由二叉树来实现的,所以插入
时的代价很小log2N,将其当作关联数组使用,省去了不少代码.
*/
#pragma  warning(disable: 4786)//在vc6.0下编译需加上此行
#include <iostream>
#include <map>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////
//             A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
int valus[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
typedef map<long, int, less<long> > LongIntMap;
//////////////////////////////////////////////////////////////////////////

int main()
{
    bool flag = false;
    long n, i,  tmp ; 
    LongIntMap mymap;
    LongIntMap::const_iterator itr;    
    
    cin>>n;    
    
    string str;    
    for (long k = 0; k < n; ++k) {
        cin>>str;
        tmp = 0;
        int len = str.size();
        
        for (i = 0; i < len; ++i) {
            if ( isdigit(str[i]) )
                tmp = tmp*10 + (str[i] -'0');
            else if ( isalpha(str[i]) ) 
                tmp = tmp*10 + valus[str[i] -'A'];    
        }
        mymap[tmp]  += 1;
    }
    
    for (itr = mymap.begin(); itr != mymap.end(); ++itr) {
        if (itr->second > 1) {
            printf("%03d-%04d %d\n", itr->first/10000, itr->first%10000, itr->second);
            flag = true;
        }
    }

    if (flag == false) {
        cout<<"No duplicates."<<endl;
    }
    return 0;
}
