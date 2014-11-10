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



typedef class ErasingCharacters {
    char output[100];
    int len;
    public:
    string simulate(string s) {
        const char *p=s.c_str();
        len = 0;
		while(*p){
			if(len && *p == output[len-1]){
				len--;
			}else{
				output[len++] = *p;
			}
			p++;
		}
		output[len] = '\0';
        return output;
    }
}Class_One1;
typedef class ErasingCharacters1 {
    char output[100];
    int len;
    public:
    string simulate(string s) {
        while(true){
			bool find = false;

			for(int i=0;i<s.size();++i){
				if(s[i] == s[i+1]){
					find = true;
					if(i +1 == s.size()){
						cout<<"test "<<s[s.size()+1]<<endl;
					}
					s = s.substr(0,i) + s.substr(i+2);

				}
			}


			if(!find)break;
        }
        return s;
    }
}Class_One;



int main() {
	Class_One test;
	cout<<test.simulate("aaaaaabanananabb")<<endl;
	cout<<test.simulate("a")<<endl;
	cout<<test.simulate("abcdefghijklmnopqrstuvwxyyxwvutsrqponmlkjihgfedcba")<<endl;
	cout<<test.simulate("bacaabaccbaaccabbcabbacabcbba")<<endl;
	cout<<test.simulate("eel")<<endl;


    return 0;
}
