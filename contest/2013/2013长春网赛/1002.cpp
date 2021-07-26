#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
//#include <cmath>
//#include <stack>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define E exp(double(1))
#define maxn 110000
using namespace std;
//typedef long long  LL;
//typedef unsigned int uint;

struct Subnet {
    int a,b,c,d;
//    char b_sub[33];
    int i_sub;
    int _sub;
    void read(int num=0) {
        if(num == 0) {
            scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&num);
            get_sub(num);
        } else {
            scanf("%d.%d.%d.%d",&a,&b,&c,&d);
            get_sub(num);

        }
    }
    void get_sub(int num) {
        this->num = num;
        i_sub = 0;
        _sub = 0;

        int j = 0;
        for(int i=7; i >= 0; i--) {
            i_sub = i_sub <<1;
            _sub = _sub << 1;
            if(8 - i <= num) {
                i_sub |=  ((a >> i) & 1);
                _sub |= 1;
            }
        }
        for(int i=7; i >= 0; i--) {
            i_sub = i_sub <<1;
            _sub = _sub << 1;
            if(8 - i + 8 <= num) {
                i_sub |=  ((b >> i) & 1);
                _sub |= 1;
            }
        }
        for(int i=7; i >= 0; i--) {
            i_sub = i_sub <<1;
            _sub = _sub << 1;
            if(8 - i + 16 <= num) {
                i_sub |=  ((c >> i) & 1);
                _sub |= 1;
            }
        }
//        b_sub[j] = '\0';
    }
    int num;
} tmp,from,to;
struct Net {
    bool have;
    int num;
    vector<Subnet>subnet;
    Net():have(false),num(0) {}

    void add(Subnet& tmp) {
        if(have == false) {
            have = true;
            subnet.clear();
            subnet.push_back(tmp);
            num++;
        } else {
            subnet.push_back(tmp);
            num++;
        }

    }
    void del() {
        have = false;
        num = 0;
    }
    bool connect(int debug = 0) {
        bool from_ok = false, to_ok = false;
        for(int i=0; i<num; i++) {
            if(!from_ok) {
                if((from.i_sub & subnet[i]._sub) == subnet[i].i_sub)  {
                    from_ok = true;
                }
            }
            if(!to_ok) {
                if((to.i_sub & subnet[i]._sub) == subnet[i].i_sub) {
                    to_ok = true;
                }
            }
            if(from_ok && to_ok) {
                return true;
            }
        }
        return false;
    }
} net[1034];




bool getAns() {
    for(int i=1; i<=1024; i++) {
        if(net[i].have && net[i].connect()) {
            return true;
        }
    }
    return false;
}


int main() {

    char op[2];
    int id,n,i;
    while(~scanf("%s",op)) {
        if(op[0] == 'E') {
            scanf("%d%d",&id,&n);
            for(i=0; i<n; i++) {
                tmp.read();
                net[id].add(tmp);
            }
        } else if(op[0] == 'F') {
            from.read(24);
            to.read(24);
            printf("%s\n",getAns()?"F":"D");
        } else if(op[0] == 'D') {
            scanf("%d",&id);
            net[id].del();
        }
    }

    return 0;
}
