#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 100
using namespace std;
char str[maxn], res[maxn];
bool mark[256], vowel[256];
int main(){
  vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] = vowel['U'] = true;
	int n, len, l, r;
	while(gets(str)) {
		n = strlen(str);
		len = 0;
		memset(mark, false, sizeof(mark));
		for(int i=0;i<n;i++) {
			if(str[i] >= 'A' && str[i] <= 'Z') {
				if(!vowel[ str[i] ] && !mark[ str[i] ]){
					mark[ str[i] ] = true;
					res[len++] = str[i];
				}
			}
			else{
			    if(len > 0 && res[len - 1] == ' ') res[len - 1] = str[i];
			    else res[len++] = str[i];
			}
		}
		l = 0, r = len - 1;
		while(res[l] == ' ') l++;
		while(res[r] == ' ') r--;
		for(int i=l;i<=r;i++) putchar(res[i]);
		putchar(10);
	}
    return 0;
}
