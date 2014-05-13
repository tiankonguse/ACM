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
using namespace std;
typedef long long LL;

map<string,int>mhead,mtail;
map<string, int>::iterator ithead, ittail;
queue<string>qhead, qtail;
map<string,string>prehead,pretail;
string shead, stail;
int str[2][10];
int n;
int ans;
bool ansFind;

void init(){
	mhead.clear();
	mtail.clear();
	prehead.clear();
	pretail.clear();
	while(!qhead.empty())qhead.pop();
	while(!qtail.empty())qtail.pop();
	shead = "";
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			shead += (str[j][i] + '0');
		}
	}
	mhead[shead] = 0;
	qhead.push(shead);
	prehead[shead] = "begin";

	stail = "";
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			stail += (i+'0');
		}
	}
	mtail[stail] = 0;
	qtail.push(stail);
	pretail[stail] = "end";

	ans  = 0;
	if(stail == shead){
		ansFind = true;
	}else{
		ansFind = false;
	}
}

void toArray(string& s){
	for(int i=1,j=0;i<=n;i++){
		for(int k=0;k<2;k++){
			str[k][i] = s[j++];
		}
	}
}

void toString(string& s){
	s = "";
	for(int i=1;i<=n;i++){
		if(str[0][i] > str[1][i]){
			s += str[1][i];
			s += str[0][i];
		}else{
			s += str[0][i];
			s += str[1][i];
		}
	}
}

void outputhead(int step, string&s){
	map<string, string>::iterator  it = prehead.find(s);
	if(it == prehead.end()){
		printf("%d:%s\n",step, s.c_str());
	}else{
		outputhead(step-1, it->second);
		printf("%d:%s\n",step, s.c_str());
	}
}
void outputtail(int step, string&s){
	printf("%d:%s\n",step, s.c_str());
	map<string, string>::iterator  it = pretail.find(s);
	if(it != pretail.end()){
		outputtail(step+1, it->second);
	}
}

void bfshead(){
	string s = qhead.front();qhead.pop();
	shead = s;
	int step = mhead[s];
	toArray(s);
	int i,j,k;
	for(i=1;i<n;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				if(str[j][i] == str[k][i+1])continue;
				if(j == 1 && str[1][i] == str[0][i])continue;
				if(k == 1 && str[1][i+1] == str[0][i+1])continue;
				if(str[j][i] <= i + '0' && str[k][i+1] >= i+'1')continue;
				if(str[j][i] < str[k][i+1] + 1)continue;
				//if(str[j][i] < i - 1 + '0')continue;
				//if(str[k][i+1] > i + 2+ '0')continue;

				swap(str[j][i],str[k][i+1]);
				toString(s);
				ithead = mhead.find(s);

				if(ithead == mhead.end()){



					ittail = mtail.find(s);
					if(ittail == mtail.end()){
						//head,tail all not find
						mhead[s] = step + 1;
						qhead.push(s);
						prehead[s] = shead;
					}else{
						// tail find
						ansFind = true;
						ans = step + ittail->second + 1;
						outputhead(step, shead);
						outputtail(step+1, s);
					}
				}
				if(ansFind){
					return ;
				}
				swap(str[j][i],str[k][i+1]);
			}
		}
	}
}



void bfstail(){
	string s = qtail.front();qtail.pop();
	stail = s;
	int step = mtail[s];
	toArray(s);
	int i,j,k;
	for(i=1;i<n;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				if(str[j][i] == str[k][i+1])continue;
				if(j == 1 && str[1][i] == str[0][i])continue;
				if(k == 1 && str[1][i+1] == str[0][i+1])continue;

				swap(str[j][i],str[k][i+1]);
				toString(s);
				ittail = mtail.find(s);

				if(ittail == mtail.end()){
					ithead = mhead.find(s);
					if(ithead == mhead.end()){
						//head,tail all not find
						mtail[s] = step + 1;
						qtail.push(s);
						pretail[s] = stail;
					}else{
						// head find
						ansFind = true;
						ans = step + ithead->second + 1;
						printf("tail\n");
						outputhead(ithead->second, s);
						printf("--\n");
						outputtail(ithead->second+1, stail);
					}
				}

				if(ansFind){
					return ;
				}
				swap(str[j][i],str[k][i+1]);
			}
		}
	}
}

void bfs(){

	//printf("head : %d\n",qhead.size());
	//printf("tail : %d\n",qtail.size());
	while(!ansFind){
		if(!ansFind){
			printf("head : %d\n",qhead.size());
			bfshead();
		}
		if(!ansFind){
			//bfstail();
		}
	}

}

int main(int argc, char* argv[]) {
    while(~scanf("%d",&n)) {
        for(int i=1; i<=n; i++) {
            scanf("%d%d",&str[0][i],&str[1][i]);
            if(str[0][i]>str[1][i])swap(str[0][i],str[1][i]);
        }
        init();
        if(!ansFind){
			bfs();
        }
        printf("%d\n",ans);
        break;
    }

    return 0;
}

/*
8
8 8
7 7
6 6
5 5
4 4
3 3
2 2
1 1

7
7 7
6 6
5 5
4 4
3 3
2 2
1 1

6
6 6
5 5
4 4
3 3
2 2
1 1

5
5 5
4 4
3 3
2 2
1 1

4
4 4
3 3
2 2
1 1

5
1 5
3 4
2 5
2 3
1 4

8
8 3
4 2
6 4
3 5
5 8
7 1
2 6
1 7


0:1534252314
1:1523452314
2:1523243514
3:1523241345
4:1523123445
5:1512233445
6:1125233445
7:1122353445
8:1122334545
9:1122334455

0:1534252314
1:1524352314
2:1245352314
3:1245233514
4:1245231345
5:1224351345
6:1224133545
7:1224133455
8:1212343455
9:1212334455
10:1122334455


*/
