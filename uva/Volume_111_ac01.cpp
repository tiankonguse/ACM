#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int map[ 25 ];
int len[ 25 ];
int dat[ 25 ];

int main()
{
	int n,temp;cin >> n;
	for ( int i = 1 ; i <= n ; ++ i )
		cin >> map[i];

	while ( cin >> temp ) {
		dat[temp] = 1;
		for ( int i = 2 ; i <= n ; ++ i ) {
			cin >> temp;
			dat[temp] = i;
		}

		int max = 0;
		for ( int i = 1 ; i <= n ; ++ i ) {
			len[i] = 1;
			for ( int j = 1 ; j < i ; ++ j )
				if ( map[dat[j]] < map[dat[i]] && len[i] <= len[j] )
					len[i] = len[j]+1;
			if ( max < len[i] )
				max = len[i];
		}

		cout << max << endl;
	}
	return 0;
}
