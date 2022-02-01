#include<string>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
vector<__int64>vec;
priority_queue<__int64, vector<__int64>, greater<__int64> >q;
map<__int64,int>mymap;
int main()
{
__int64 n,m,tmp;
q.push(1);
mymap[1]=1;
for(int i=0;i<1510;i++){
	m=q.top();
	q.pop();
//	cout<<i<<"  "<<m<<endl;
	vec.push_back(m);
	tmp=m*2;
	if(mymap.find(tmp)==mymap.end()){
		mymap[tmp]=1;
		q.push(tmp);
	}
	tmp=m*3;
	if(mymap.find(tmp)==mymap.end()){
		mymap[tmp]=1;
		q.push(tmp);
	}
	tmp=m*5;
	if(mymap.find(tmp)==mymap.end()){
		mymap[tmp]=1;
		q.push(tmp);
	}


}
int k;
while(scanf("%d",&k),k){
	printf("%d\n",vec[k-1]);
}
return 0;
}
