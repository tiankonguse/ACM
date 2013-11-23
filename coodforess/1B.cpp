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

void read_char(char * tmp, int& pos, char* output ) {
    for(int i=0; tmp[pos] && tmp[pos] >= 'A' && tmp[pos] <= 'Z';) {
        output[i++] = tmp[pos++];
        output[i] = '\0';
    }
}
void read_num(char * tmp, int& pos, char* output ) {
    for(int i=0; tmp[pos] && tmp[pos] >= '0' && tmp[pos] <= '9';) {
        output[i++] = tmp[pos++];
        output[i] = '\0';
    }
}

int getNumByChar(char *p) {
    int base = 1;
    int len = strlen(p);
    int ans = 0;
    for(int i=len-1; i>=0; i--) {
        ans += base * (p[i] - 'A' + 1);
        base *= 26;
    }
    return ans;
}
int getNumByNum(char *p) {
    int base = 1;
    int len = strlen(p);
    int ans = 0;
    for(int i=len-1; i>=0; i--) {
        ans += base * (p[i] - '0');
        base *= 10;
    }
    return ans;
}

char* getChar(int num, char* output){
//    printf("%d\n",num);
    int i=0;
    int tmp;
    while(num){
        tmp = num%26;
        if(tmp == 0){
            output[i++] = 'Z';
            num -= 26;
        }else{
            output[i++] = tmp - 1 + 'A';
        }
        num /= 26;
        output[i] = '\0';
    }
    i--;
    for(int j=0;j<i;j++,i--){
        swap(output[j],output[i]);
    }
    return output;
}

int main() {
    int n;
    scanf("%d",&n);
    char tmp[100];
    char letter1[100];
    char letter2[100];
    char number1[100];
    char number2[100];
    int len,i;
    while(n--) {
        scanf("%s",tmp);
        len = strlen(tmp);
        i = 0;
        read_char(tmp,i,letter1);
        read_num(tmp,i,number1);
        if(i == len) {
            printf("R%sC%d\n",number1,getNumByChar(letter1));
        }else{
            read_char(tmp,i,letter2);
            read_num(tmp,i,number2);
            printf("%s%s\n",getChar(getNumByNum(number2), letter2),number1);
        }

    }
    return 0;
}
