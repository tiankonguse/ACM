#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Root{
	deque<int>que1,que2,que3;
	int _add;
	bool head;

	void init(int k1,int k2,int n){
		_add=0;
		head=true;
		while(!que1.empty())que1.pop_back();
		while(!que2.empty())que2.pop_back();
		while(!que3.empty())que3.pop_back();
		int tmp;
		for(int i=0;i<k1;i++){
			scanf("%d",&tmp);
			que1.push_back(tmp);
		}
		for(int i=k1;i<k2;i++){
			scanf("%d",&tmp);
			que2.push_back(tmp);
		}
		for(int i=k2;i<n;i++){
			scanf("%d",&tmp);
			que3.push_front(tmp);
		}

	}

	void insert(int x){
		int tmp;
		if(head){

			tmp=que1.front();que1.pop_front();
			que1.push_front(x-_add);
			que1.push_front(tmp);

			que2.push_front(que1.back());que1.pop_back();

			que3.push_back(que2.back()+_add);que2.pop_back();
		}else{
			tmp=que1.back();que1.pop_back();
			que1.push_back(x-_add);
			que1.push_back(tmp);

			que2.push_front(que1.front());que1.pop_front();

			que3.push_back(que2.back()+_add);que2.pop_back();
		}
	}

	void _delete(){
		int tmp;
		if(head){

			que1.pop_front();
			que1.push_back(que2.front());

			que2.pop_front();
			que2.push_back(que3.back()-_add);

			que3.pop_back();
		}else{
			que1.pop_back();
			que1.push_front(que2.front());

			que2.pop_front();
			que2.push_back(que3.back()-_add);

			que3.pop_back();
		}
	}

	void reverse(){
		head=!head;
	}
	void add(int x){
		_add+=x;
	}
	void move(int x){
		if(x==1){
			if(head){
				que1.push_front(que3.front()-_add);que3.pop_front();
				que2.push_front(que1.back());que1.pop_back();
				que3.push_back(que2.back()+_add);que2.pop_back();
			}else{
				que1.push_back(que3.front()-_add);que3.pop_front();
				que2.push_front(que1.front());que1.pop_front();
				que3.push_back(que2.back()+_add);que2.pop_back();
			}
		}else{
			if(head){
				que3.push_front(que1.front()+_add);que1.pop_front();
				que1.push_back(que2.front());que2.pop_front();
				que2.push_back(que3.back()-_add);que3.pop_back();
			}else{
				que3.push_front(que1.back()+_add);que1.pop_back();
				que1.push_front(que2.front());que2.pop_front();
				que2.push_back(que3.back()-_add);que3.pop_back();
			}
		}
	}
	int query(){
		if(head){
			return que1.front()+_add;
		}else{
			return que1.back()+_add;
		}
	}

}root;



int main(){
	int m,tmp,n,k1,k2;
	char op[10];
	int ca=1;
	while(scanf("%d%d%d%d",&n,&m,&k1,&k2),n){
		root.init(k1,k2,n);
		printf("Case #%d:\n",ca++);
		while(m--){
			scanf("%s",op);
			switch(op[0]){
				case 'a':scanf("%d",&tmp);root.add(tmp);break;
				case 'r':root.reverse();break;
				case 'i':scanf("%d",&tmp);root.insert(tmp);break;
				case 'd':root._delete();break;
				case 'm':scanf("%d",&tmp);root.move(tmp);break;
				case 'q':printf("%d\n",root.query());break;
			}
		}
	}
	return 0;
}
