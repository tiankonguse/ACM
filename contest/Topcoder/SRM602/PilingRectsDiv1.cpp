#line 5 "PilingRectsDiv1.cpp"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#define N 200005
pair<int , int> a[N];
int d[N] , D , c[N];

void add(int x , int w)
{
    for (int i = x ; i <= D ; i += i & -i)
        c[i] += w;
}
int getKth(int k)
{
    int x = 0 , i;
    for (i = 17 ; i >= 0 ; -- i)
        if (x + (1 << i) <= D && c[x + (1 << i)] < k)
        {
            x += 1 << i;
            k -= c[x];
        }
    return x + 1;
}

class PilingRectsDiv1
{
        public:
        long long getmax(int n, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC)
        {
            int i , j;

            j = XS.size() , D = 0;
            for (i = 0 ; i < j ; ++ i)
                a[i] = make_pair(XS[i] , YS[i]);
            for (i = j ; i < n + n; ++ i)
                a[i].first  = ((LL)a[i - 1].first  * XA + XB) % XC + 1 ,
                a[i].second = ((LL)a[i - 1].second * YA + YB) % YC + 1 ;
            for (i = 0 ; i < n + n ; ++ i)
                if (a[i].first > a[i].second)
                    swap(a[i].first , a[i].second);
            sort(a , a + n + n);
            //for (i = 0 ; i < n + n; ++ i)
            //    cout << a[i].first << ' ' << a[i].second << endl;
            for (i = 0 ; i < n + n; ++ i)
                d[D ++] = a[i].second;
            sort(d , d + D) , D = unique(d , d + D) - d;
            for (i = 0 ; i < n + n; ++ i)
                a[i].second = lower_bound(d , d + D , a[i].second) - d + 1;
            LL ans = 0;
            //for (i = 0 ; i < n + n; ++ i)
            //    cout << a[i].first << ' ' << a[i].second << endl;
            memset(c , 0 , sizeof(c));
            for (i = 1 ; i < n + n ; ++ i)
                add(a[i].second , 1);
            int mY = a[0].second;
            for (i = 1 ; i <= n ; ++ i) // the biggest in the second set
            {
                // the 1st set has (i - 1) elemcnt , request n - i + 1
                add(a[i].second , -1);

                int my = getKth(1);
                //cout << "My -> " << mY << endl;
                //cout << "my -> " << my << endl;
                // miny puts into 1st set
                //cout << size - n + 2 << " ** " << getKth(size - n + 2) << endl;
                LL area = (LL) a[0].first * d[min(mY , my) - 1] + (LL) a[i].first * d[min(a[i].second , getKth(n - i + 1)) - 1];
                ans = max(ans , area);
                // miny puts into 2rd set
                //cout << size - n + i << " ** " << getKth(size - n + i) << endl;
                area = (LL) a[0].first * d[min(mY , getKth(n)) - 1] + (LL) a[i].first * d[min(a[i].second , my) - 1];
                ans = max(ans , area);
                mY = min(mY , a[i].second);
            }
            return ans;
        }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {3,2,4,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 7LL; verify_case(0, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {7,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; int Arg4 = 0; int Arg5 = 10; int Arg6 = 2; int Arg7 = 7; int Arg8 = 9; long long Arg9 = 56LL; verify_case(1, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {5,6,9,10,4,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9,5,8,6,8,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 1; int Arg6 = 0; int Arg7 = 0; int Arg8 = 1; long long Arg9 = 69LL; verify_case(2, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_3() { int Arg0 = 10000; int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 93827162; int Arg4 = 91238127; int Arg5 = 98231267; int Arg6 = 92138287; int Arg7 = 98563732; int Arg8 = 99381279; long long Arg9 = 1240119561532788LL; verify_case(3, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {375,571,973,896,460,930,583,530,657,590}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {284,37,994,699,941,745,166,884,270,708}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 428; int Arg4 = 1000; int Arg5 = 788; int Arg6 = 851; int Arg7 = 125; int Arg8 = 894; long long Arg9 = 420515LL; verify_case(4, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }
	void test_case_5() { int Arg0 = 34734; int Arr1[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 569; int Arg4 = 185; int Arg5 = 285; int Arg6 = 741; int Arg7 = 304; int Arg8 = 296; long long Arg9 = 10050LL; verify_case(5, Arg9, getmax(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8)); }

// END CUT HERE
//{2, {3, 2, 4, 2}, {1, 2, 2, 2}, 1, 1, 1, 1, 1, 1}
};

// BEGIN CUT HERE
int main()
{
        PilingRectsDiv1 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
