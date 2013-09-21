#include <iostream>
#include <queue>
using namespace std;
////////////////////////////////////////////////
class info {
public:
    int pos, depth;
    info():pos(-1), depth(0){};
    info(int nPos, int nDepth)
        :pos(nPos),depth(nDepth){};
}; 
////////////////////////////////////////////////
int main()
{
    int n , k, i;
    cin>>n>>k;
    if (n > k){
     //  std::swap(n, k);
        cout<<n-k<<endl; //注意-1
        return 0;
    }
    
    if (n == k) {
        cout<<0<<endl; 
        return 0;
    }

    bool *visited = new bool[2*k+2];
    memset(visited, 0, (2*k+2) );

    queue<info>  open;
    info temp, childs[3];

    open.push(info(n, 0));
    while (!open.empty()) {
        temp = open.front(); 
        visited[temp.pos] = true;
        open.pop(); 

        childs[0] = info(temp.pos<<1, temp.depth + 1);// n*2   
        childs[1] = info(temp.pos-1 , temp.depth + 1);// n-1 
        childs[2] = info(temp.pos+1 , temp.depth + 1);// n+1  
        for (i = 0; i < 3 ; ++i) { 
            if (childs[i].pos < 0 || childs[i].pos > 2*k) { //注意-2
                continue;
            }
            //当前新节点即为所求终点
            if (childs[i].pos == k) { 
                cout<<childs[i].depth<<endl;
                delete [] visited;
                return 0;
            }    
            //是否存在与closed表中
            if (visited[childs[i].pos] == false) {
                open.push(childs[i]);
                visited[childs[i].pos] = true;
                continue;
            } 
              
        }
    }
    delete [] visited;
    return 0;
}
