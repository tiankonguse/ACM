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
#include<stdarg.h>
using namespace std;
#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

struct T {
    string key;
    string val;
    int type;// 0 : Integer; 1 : String
    int isConst; // 0 : var; 1 : const
    T() {}
    T(char*key, char*val,int type, int isConst):key(key),val(val),type(type),isConst(isConst) {
    }
};
const char* TYPE[] = {"integer","string"};
map<string, T> mymap;
map<string, T>::iterator it;
int Error,Panic;
void init() {
    Error = 1;
    Panic = 0;
    mymap.clear();
}
inline bool isTerminate(char* line) {
    return strcmp("Panic", line) == 0;
}
inline bool isWhiteSpaces(char c) {
    return (c==9 || c == 32);
}
void trim(char* line) {
    int l = strlen(line);
    // 删除右边的空格
    for(int i=l-1; i>=0; i--) {
        if(isWhiteSpaces(line[i])) {
            l--;
            line[i] = '\0';
        } else {
            break;
        }
    }

    // 找到左边起第一个有效的位置
    int b = 0;
    for(int i=0; i<l; i++) {
        if(isWhiteSpaces(line[i])) {
            b++;
        } else {
            break;
        }
    }
    //整体左移
    for(int i=0; b<=l; i++,b++) {
        line[i] = line[b];
    }
}
bool isErrorReporting(char* line) {
    const char * e = "Errmsg";
    int l = strlen(e);
    if(strncmp(e, line, l) == 0) {
        if(isWhiteSpaces(line[l])) {
            trim(line + l + 1);
            if(line[l+1] == 'O' && line[l+2] == 'N' && line[l+3] == '\0') {
                Error = 1;
            } else if(line[l+1] == 'O' && line[l+2] == 'F' && line[l+3] == 'F' && line[l+4] == '\0') {
                Error = 0;
            }
            return true;
        }
    }
    return false;
}
bool isOutput(char* line) {
    const char * e = "Print";
    int l = strlen(e);
    if(strncmp(e, line, l) == 0) {
        if(isWhiteSpaces(line[l])) {
            trim(line + l + 1);
            string s = line + l + 1;
            it = mymap.find(s);
            if(it != mymap.end()) {
                printf("%s\n",it->second.val.c_str());
            } else {
                if(line[l+1] == '$') {
                    printf("NULL\n");
                    if(Error == 1) {
                        printf("NOTICE: Undefined Variable %s.\n",line + l + 1);
                    }
                } else {
                    printf("%s\n",line + l + 1);
                    if(Error == 1) {
                        printf("NOTICE: Undefined Constant %s.\n",line + l + 1);
                    }
                }
            }
            return true;
        }
    }
    return false;
}
bool isDump(char* line) {
    const char * e = "Dump";
    int l = strlen(e);
    if(strncmp(e, line, l) == 0) {
        if(isWhiteSpaces(line[l])) {
            trim(line + l + 1);
            string s = line + l + 1;
            it = mymap.find(s);
            if(it != mymap.end()) {
                if(it->second.type == 0) {
                    printf("%s: %s\n",TYPE[it->second.type], it->second.val.c_str());
                } else {
                    printf("%s: \"%s\"\n",TYPE[it->second.type], it->second.val.c_str());
                }
            } else {
                if(line[l+1] == '$') {
                    printf("NULL\n");
                    if(Error == 1) {
                        printf("NOTICE: Undefined Variable %s.\n",line + l + 1);
                    }
                } else {
                    printf("%s: \"%s\"\n",TYPE[1], line + l + 1);
                    if(Error == 1) {
                        printf("NOTICE: Undefined Constant %s.\n",line + l + 1);
                    }
                }
            }
            return true;
        }
    }
    return false;
}
int haseq(char* line) {
    for(int i=0; line[i]; i++) {
        if(line[i] == '=') {
            return i;
        }
    }
    return 0;
}
bool isAssignment(char* line) {
    int pos;
    if(pos=haseq(line)) {
        line[pos]= '\0';
        char* key=line;
        char* val = line+pos+1;
        int type = 0;
        int isConst = 0;
        trim(key);
        trim(val);
        if(key[0] != '$') {
            isConst = 1;
        }
        if(val[0] == '\"') {
            val[0] = ' ';
            val[strlen(val)-1] = ' ';
            trim(val);
            type = 1;
        }
        it = mymap.find(key);
        if(it != mymap.end()) {
            if(isConst == 0) {
                mymap[key] = T(key,val, type, isConst);
            } else {
                if(Error == 1) {
                    printf("WARNING: Constant %s Already Defined!\n", key);
                }
            }
        } else {
            mymap[key] = T(key,val, type, isConst);
        }
        return true;
    }

    return false;
}
void Analysis(char* line) {
    trim(line);
    if(isAssignment(line)) {
        return ;
    }
    if(isTerminate(line)) {
        Panic = 1;
        printf("Script was KILLED.\n");
        return ;
    }
    if(isErrorReporting(line)) {
        return ;
    }
    if(isOutput(line)) {
        return ;
    }
    if(isDump(line)) {
        return ;
    }
}
int main() {
    int t,n;
    scanf("%d",&t);
    char line[1000];
    for(int i=1; i<=t; i++) {
        if(i>1) {
            puts("");
        }
        scanf("%d",&n);
        getchar();
        init();
        while(n--) {
            gets(line);
            if(Panic == 0) {
                Analysis(line);
            }
        }
    }


    return 0;
}
