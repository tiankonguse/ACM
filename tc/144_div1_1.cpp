#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
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

typedef class BinaryCode{
	string m;
	string getAns(string now){
		char val;
		int pos = 1;
		bool ok = true;
		for(int i=0;i<m.size();i++){
			if(m[i] > '3' || m[i] < '0'){
				ok = false;
				break;
			}

			val = m[i] - (now[pos] - '0') - (now[pos-1] - '0');
			if(val >'1' || val < '0'){
				ok = false;
				break;
			}

			now += val;
			pos++;
		}
		if(ok){
			if(now[now.size()-1] == '1'){
				return "NONE";
			}
			return now.substr(1,now.size()-2);
		}else{
			return "NONE";
		}
	}

	public:
	vector <string> decode(string m){
		this->m = m;
		vector <string> ans;

		ans.push_back(getAns("00"));
		ans.push_back(getAns("01"));

		return ans;
	}
}One;


int main() {

	One one;
	char str[1000];
	while(~scanf("%s",str)){
		vector <string>  ans = one.decode(str);
		cout<<ans[0]<<endl;
		cout<<ans[1]<<endl;
	}


//123210122

    return 0;
}
