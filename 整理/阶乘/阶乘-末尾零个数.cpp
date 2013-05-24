#include <iostream>
using namespace std;


int Factorial_CountZeros(int n) {
    int cnt = 0;
    while (n) {
        n /= 5;
        cnt += n;
    }
    return cnt; 
} 

int main()
{
	cout<<Factorial_CountZeros(200000)<<endl;
	return 0;
}