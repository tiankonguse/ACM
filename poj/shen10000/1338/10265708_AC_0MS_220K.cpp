#include<string>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
vector<__int64>vec;
priority_queue<__int64, vector<__int64>, greater<__int64> >q;
int main()
{
__int64 n,m,tmp;
q.push(1);
for(int i=0;i<1510;i++){
	m=q.top();
	q.pop();
//	cout<<i<<"  "<<m<<endl;
	vec.push_back(m);
	if(m%5==0){
		q.push(m*5);
	}else if(m%3==0){
		q.push(m*3);
		q.push(m*5);
	}else{
		q.push(m*2);
		q.push(m*3);
		q.push(m*5);
	}
}
int k;
while(scanf("%d",&k),k){
	printf("%d\n",vec[k-1]);
}
return 0;
}
