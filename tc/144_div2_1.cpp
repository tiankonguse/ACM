#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <iostream>     // std::istream, std::cout
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <locale>       // std::isspace, std::isdigit
#include<string>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

class Time{
	public:
	string whatTime(int s){
		int m,h;
		string ans = "";
		m = s / 60;
		s = s % 60;
		h = m / 60;
		m = m % 60;

		std::ostringstream out;
		out<<h << ":" << m << ":" << s;
		ans = out.str().c_str() ;

		return ans;
	}
};


int main() {

	Time t;
	int s;
	while(cin>>s){
		cout<<t.whatTime(s)<<endl;
	}

    return 0;
}
