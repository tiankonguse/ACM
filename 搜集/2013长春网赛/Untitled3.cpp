#include <vector>
#include <cstdio>
using namespace std;

struct Subnet {
    int a,b,c;
    int i_sub;
    void read(int num=0) {
        if(num == 0) {
            scanf("%d.%d.%d.%*d/%d",&a,&b,&c,&num);
            get_sub(num);
        } else {
            scanf("%d.%d.%d.%*d",&a,&b,&c);
        }
    }
    void get_sub(int num) {
        this->num = num;
        i_sub = a;
        num -= 8;

        if(num == 0){
            i_sub = i_sub <<16;
        }else if(num <= 8){
            for(int i=7; i >= 0; i--) {
                i_sub = i_sub <<1;
                if(8 - i + 8 <= num) {
                    i_sub |=  ((b >> i) & 1);
                }
            }
            i_sub = i_sub <<8;
        }else{
            i_sub = i_sub <<8 + b;

        }


        for(int i=7; i >= 0; i--) {
            i_sub = i_sub <<1;
            if(8 - i + 8 <= num) {
                i_sub |=  ((b >> i) & 1);
            }
        }
        for(int i=7; i >= 0; i--) {
            i_sub = i_sub <<1;
            if(8 - i + 16 <= num) {
                i_sub |=  ((c >> i) & 1);
            }
        }
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
                from.get_sub(subnet[i].num);
                if((from.i_sub & subnet[i].i_sub) == subnet[i].i_sub) {
                    from_ok = true;
                }
            }
            if(!to_ok) {
                to.get_sub(subnet[i].num);
                if((to.i_sub & subnet[i].i_sub) == subnet[i].i_sub) {
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
            from.read(1);
            to.read(1);
            printf("%s\n",getAns()?"F":"D");
        } else if(op[0] == 'D') {
            scanf("%d",&id);
            net[id].del();
        }
    }

    return 0;
}
