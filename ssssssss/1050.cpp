#include<iostream>
#include <iomanip>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
int main(){
	double f;

	while(cin>>f)printf("celsius=%.6f,fahr=%.3f\n",f,(9.0*f/5+32));

	return 0;
}
//9*c/5+32
