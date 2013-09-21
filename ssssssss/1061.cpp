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
int mymin,mymax;
bool cmp(T a,T b){
	return a.val > b.val;
}
void print(int k){
	if(mymin == str[k-1].val)print(k-1);
	else {printf(" %s",str[k].name); return ;}
	printf(",%s",str[k].name);
}
int main(){
	int k=0;
	while(cin>>str[k].name>>str[k].val){if(str[k].val==-1)break;k++;}
	stable_sort(str,str+k,cmp);
	mymax=str[0].val;
	mymin=str[k-1].val;
	printf("Max is %d,name have",mymax);
	printf(" %s",str[0].name);
	for(int i=1;str[i].val==mymax;i++){
		printf(",%s",str[i].name);
	}
	printf("\n");
	printf("Min is %d,name have",mymin);
	print(k-1);
	printf("\n");

	return 0;
}


