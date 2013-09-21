#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
struct T{
	char name[72];
	int val;
}str[211];
bool cmp(T a,T b){
	return a.val > b.val;
}
int main(){
	int k=0;
	while(cin>>str[k].name>>str[k].val)k++;
	stable_sort(str,str+k,cmp);
	for(int i=0;i<k;i++){
		printf("%-20s %3d\n",str[i].name,str[i].val);
	}
	return 0;
}


