#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

const char *opl = "UDLR";
const int pos_x[] = { -1, 1, 0, 0};
const int pos_y[] = { 0, 0, -1, 1};

int main() {
	for(int cs = 0; cs < 100; cs++) {
		int cur_x, cur_y, next_x, next_y;
		char status[10] = "12345678#";
		random_shuffle(status, status + 9);
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(status[i*3+j] == '#') {
					cur_x = i;
					cur_y = j;
				}
				putchar(status[i*3+j]);
			}
			puts("");
		}
		int opc = rand() % 90 + 10;
		char op[1000];
		for(int i = 0; i < opc; i++) {
			int j;
			while(true) {
				j = rand() % 4;
				next_x = cur_x + pos_x[j];
				next_y = cur_y + pos_y[j];
				if(next_x < 0 || next_x > 2 || next_y < 0 || next_y > 2)
					continue;
				else
					break;
			}
			cur_x = next_x;
			cur_y = next_y;
			op[i] = opl[j];
		}
		op[opc] = '\0';
		if(cs % 5 == 0)
			swap(op[rand()%opc], op[rand()%opc]);
		puts(op);

	}
	return 0;
}
