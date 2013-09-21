/*************************************************************************
    > File Name: E - Ever Dream.cpp
    > Author: tiankonguse
    > Mail: shen10000shen@gmail.com
    > Created Time: 2013/5/10 19:33:51
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
using namespace std;

struct T{
    char _str[111];
    int num,len;
    void insert(char *word){
        strcpy(_str, word);
        num = 1;
        len = strlen(_str);
    }

    bool operator < (const T& tmp)const{
        if(num > tmp.num)return true;
        if(num < tmp.num)return false;

        if(len > tmp.len)return true;
        if(len < tmp.len)return false;

        return strcmp(_str,tmp._str)>0;

    }


}str[5100];
int word_num;

bool is_alpha(char c){
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void change_to_low(char* line){
    while(*line){
        if(is_alpha(*line) && *line >= 'A' && *line <= 'Z'){
            *line = *line - 'A' + 'a';
        }
        line++;
    }
}

void insert(char* word){
    int i=0;
    for(i = 0; i< word_num; i++){
        if(strcmp(word,str[i]._str)==0){
            str[i].num++;
            return ;
        }
    }

    str[word_num++].insert(word);
}

void read_word(char*& line){
    char word[111];
    int i=0;
    while(is_alpha(*line)){
        word[i++] = *line++;
    }
    word[i] = '\0';

    insert(word);

}


void add_line(char* line){
    change_to_low(line);
    while(*line){
        if(is_alpha(*line)){
            read_word(line);
        }else{
            line++;
        }
    }
}

int main() {
    char _tmp[111];
    int n,cas,i, j;
    scanf("%d",&cas);

    while(cas--){
        scanf("%d",&n);
        word_num = 0;
        getchar();
        for(i=0;i<n;i++){
            gets(_tmp);
            add_line(_tmp);
        }

        sort(str,str+word_num);
        str[word_num].num = -1;
        bool first = false;
        for(i=0;i<word_num;){
            if(str[i].num ==1)break;
            if(first){
                putchar(' ');
            }
            first = true;
            if(str[i].num != str[i+1].num || str[i].len != str[i+1].len){
                printf("%s",str[i]._str);
            }else{
                printf("%s",str[i+1]._str);
            }
            j = i;
            while(str[i].num == str[j].num)i++;
        }
        puts("");

    }


    return 0;
}
