#include <iostream>
using namespace std;
const int mod=23 * 28 * 33;
int main()
{
    int p, e, i, d, ans;
    int icase = 1;
    while(cin >> p >> e >> i >> d,p+1){
      	ans = (5544 * p + 14421 * e + 1288 * i ) % mod - d;
		if (ans <= 0)ans += 21252;
		cout << "Case " << icase++ << ": the next triple peak occurs in " << ans << " days." << endl;		
    }
    return 0;
}
