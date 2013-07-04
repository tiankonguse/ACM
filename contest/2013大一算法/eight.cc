#include <cstdio>
#include <algorithm>
using namespace std;

const char *opl = "UDLR";
const int pos_x[] = { -1, 1, 0, 0};
const int pos_y[] = { 0, 0, -1, 1};
const int maxn = 5;
char status[maxn][maxn], op[1000];

int main() {
	while(~scanf("%s", status[0])) {
		scanf("%s", status[1]);
		scanf("%s", status[2]);
		int cur_x, cur_y;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(status[i][j] == '#') {
					cur_x = i;
					cur_y = j;
				}
			}
		}
		scanf("%s", op);
		bool on_err = false;
		for(int i = 0; op[i]; i++) {
			for(int j = 0; j < 4; j++)
				if(opl[j] == op[i]) {
					int next_x = cur_x + pos_x[j];
					int next_y = cur_y + pos_y[j];
					if(next_x < 0 || next_x > 2 || next_y < 0 || next_y > 2) {
						on_err = true;
						break;
					}
					swap(status[next_x][next_y], status[cur_x][cur_y]);
					cur_x = next_x;
					cur_y = next_y;
				}
			if(on_err)break;
		}
		if(on_err)
			puts("Error");
		else
			for(int i = 0; i < 3; i++)
				puts(status[i]);
		puts("");
	}
	return 0;
}

