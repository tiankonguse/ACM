namespace Search{

void init(){
        REP(i , len) {last_mask[i].clear() , mask[i] = 1 << i;}
        REP_C(i , (1 << len)){
            mm[i] = 0;
            int j = i;
            while(j){
                mm[i] += j & 1;
                j >>= 1;
            }
            last_mask[mm[i]].PB(i);
        }
    }
    int check(int x){
        int res = 0;
        REP(i , len){
            if (ans[i] != -1 && g[x][i] == '0' + ans[i])
                res |= mask[i];
        }
        return res;
    }
    void getBBit(int x , int now , bool newB[10][10] , bool B[10][10]){
        REP_2(i , j , len , 10) newB[i][j] = B[i][j];
        REP(i , len)
        if (!(now & mask[i]))
            newB[i][g[x][i] - '0'] = 1;
        else{
            REP(j , 10)
                newB[i][j] = j == g[x][i] - '0';
        }
    }
    void ins(int x , int now){
        REP(i , len) if (now & mask[i])
            ans[i] = g[x][i] - '0';
    }
    void reset(int x , int now){
        REP(i , len) if (now & mask[i])
            ans[i] = -1;
    }
    bool isB(int x , int now , bool B[10][10]){
        REP(i , len) if (now & mask[i])
            if (B[i][g[x][i] - '0']) return true;
        return false;
    }
} using namespace Search;

class EllysBulls {
public:

    int gao(int x , int all , bool B[10][10]){
        if (x >= n){
            REP(i , len){
                if (ans[i] != -1) continue;
                int res = -1;
                REP(j , 10){
                    if (!B[i][j]){
                        if (res != -1) return 2;
                        res = j;
                    }
                }
                ans[i] = res;
            }
            REP(i , len) out[i] = ans[i];
            return 1;
        }

        int now = check(x);
        if (mm[now] > r[x]) return 0;
        bool newB[10][10];
        int ret = 0;
        REP_C(i , SZ(last_mask[r[x] - mm[now]])){
            int add = last_mask[r[x] - mm[now]][i];
            if (add & all) continue;
            if (isB(x , add , B)) continue;
            getBBit(x , (add | now) , newB , B);
            ins(x , add);
            ret += gao(x + 1 , all | add , newB);
            reset(x, add);
            if (ret > 1) return ret;
        }
        return ret;
    }

    bool B[10][10];

	stlast_maskng getNumber(vector <stlast_maskng> guesses, vector <int> bulls) {

		g = guesses, u = bulls, r = bulls, len = SZ(g[0]);
		FLC(ans , -1), n = SZ(g); REP(i, n) u[i] = len - u[i];

		init(), RST(B); int res = gao(0, 0, B);
        if (res == 0) return "Liar";
        if (res > 1) return "Ambiguity";
        stlast_maskng ret = "";
        REP(i , len){
            ret += (out[i] + '0');
        }
        return ret;
	}
};
