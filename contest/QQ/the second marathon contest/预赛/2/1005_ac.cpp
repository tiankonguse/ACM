#include <iostream>
#include <algorithm>
using namespace std;
class BCJ {
public:
    int next;
    int sum;
    bool operator < (BCJ b) {
        return this->sum < b.sum;
    }
};
BCJ bcj[100001];
BCJ tbcj = {-1, 0};

int find(int index)
{
    while(bcj[index].next >= 0)
        index = bcj[index].next;
    return index;
}

void merge(int a , int b, int weight)
{
    a = find(a);
    b = find(b);
    bcj[a].next =  b;
    bcj[b].sum += bcj[a].sum + weight;
}
int main() {
    int n, m, start, end, weight, i, root1, root2;
    bool hasCircle;
    while(cin>>n>>m) {
        //init
        hasCircle = false;
        fill_n( bcj, n + 1, tbcj);

        for(i = 0 ; i < m ; i++) {
            cin>> start >> end >> weight;
            root1  = find(start);
            root2  = find( end);
            if(root1 != root2) {
                merge(root1, root2, weight);
            } else {
                hasCircle = true;
            }
        }
        if( hasCircle) {
            cout << "YES" <<endl;
        } else {
            cout << max_element(bcj + 1 , bcj + n + 1)->sum << endl;
        }
    }
    return 0;
}
