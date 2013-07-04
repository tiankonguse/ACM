#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int nSticks[68];
bool bUsed[68];

int nTotalSticks;

bool concatenate(int nUnusedSticks, int nLeft, int nLen)
//nUnusedSticks-未被用过的木棍数;nLeft-正在拼的木棒的剩余长度;nLen-正在尝试的原始长度
{
    //所有木棍均已拼凑到长为nLen的原始木棒中, 且剩余长度为0
    //则表示nLen为合理的原始长度
    if (nUnusedSticks == 0 && nLeft == 0) 
        return true;

    //如果当前木棒剩余0,则开始拼凑下一根木棒
    if (nLeft == 0 ) 
        nLeft = nLen;

    for (int i = 1; i <= nTotalSticks; ++i) {
        //已用过或其长度大于nLeft
        if (bUsed[i] == true || nSticks[i] > nLeft)
            continue;

        //尝试拼入正被拼凑的木棒
        bUsed[i] = true; 
        if (concatenate(nUnusedSticks-1, nLeft-nSticks[i], nLen) == true) 
            return true;

        //退出上次尝试的木棍,准备尝试下一根木棍
        bUsed[i] = false;
        //如果当前尝试的是某个原始木棍中的第一个位置或最后一个位置,
        //并且导致最终失败,则不必再在这个位置上尝试余下的木棍
        if (nSticks[i] == nLeft || nLeft == nLen)
            break;
    }//for

    return false;
}//concatenate()

int main()
{
    int nTotalLen, nLen, i;
    
    while (cin>>nTotalSticks && nTotalSticks != 0) {    
        memset(nSticks, 0    , 68*sizeof(int));
        memset(bUsed, false, 68*sizeof(bool));
        
        nTotalLen = 0;
        for (i = 1; i <= nTotalSticks; ++i) {
            scanf("%d", &nSticks[i]);
            nTotalLen += nSticks[i];
        }

        sort(nSticks+1, nSticks+1+nTotalSticks, greater<int>());
    
        for (nLen = nSticks[1]; nLen <= nTotalLen; ++nLen) {
            if (nTotalLen%nLen == 0 && concatenate(nTotalSticks, 0, nLen)) {
                    printf("%d\n", nLen);
                    break;
            }
        }//for
    }//while
    return 0;
}
