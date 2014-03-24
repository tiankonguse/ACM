#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
int main()
{
	freopen ("hanoi.in","r",stdin);
	freopen ("hanoi.out","w",stdout);
	cin>>n;
	cout<<(int)pow(2,n)-1;
	return 0;
} 
