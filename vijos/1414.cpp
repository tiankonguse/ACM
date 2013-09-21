#include<iostream>
#include<string>
#include<queue>
#include<cstdio>
#include<map>
#include<cmath>
#include<stack>
#include<algorithm>
#include<functional>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

char str[300];
int n,s;
deque<char>deq;
queue<char>que;
int main()
{
	int i;
	while(!deq.empty())deq.pop_back();
	while(!que.empty())que.pop();
	
	while(~scanf("%s%d",str,&s)){
		n=strlen(str);
		if(s<n){

			for(int i=0;str[i];i++)que.push(str[i]);
			
			while(s--){
				if(deq.empty() && que.empty())break;
				if(deq.empty()){
					deq.push_back(que.front());que.pop();
				}
				while(1){
					if(que.empty()){
						deq.pop_back();break;
					}else{
						if(deq.back() >que.front()){
							deq.pop_back();break;
						}else{
							deq.push_back(que.front());que.pop();
						}
					}
				}
			}
			while(!que.empty()){
				deq.push_back(que.front());que.pop();
			}
			while(!deq.empty() && deq.front()=='0')deq.pop_front();
			if(deq.empty())deq.push_back('0');			
		}
		
		while(!deq.empty()){
			putchar(deq.front());
			deq.pop_front();
		}
		puts("");
	}	
	
	return 0;
}
