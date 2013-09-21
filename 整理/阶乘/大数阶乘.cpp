/*
http://www.wangchao.net.cn/bbsdetail_38136.html　
用数组的方法解决大数、巨数的阶乘结果越界的问题。
具体算法中有最朴实的乘法运算思想，请各位细细体味。
 */
#include <stdio.h>
#include <memory.h>

//计算n的阶乘, int a[]保存结果, 返回阶乘位数digits
//调用: int digits = bignumber_factorial(n, a);
int bignumber_factorial(int n, int *a)
{
	memset(a, 0, sizeof(a)), a[0] = 1;
    int nCarry, nDigits = 1; //进位, 位数
         //将结果先初始化为1
    int temp;      //阶乘的任一元素与临时结果的某位的乘积结果

    for(int i = 2; i <= n; ++i)    { //开始阶乘，阶乘元素从2开始依次“登场”
        //按最基本的乘法运算思想来考虑，将临时结果的每位与阶乘元素相乘
        for(int j = 1, nCarry = 0; j <= nDigits; ++j) {
            temp = a[j-1] * i + nCarry; //相应阶乘中的一项与当前所得临时结果的某位相乘（加上进位）
            a[j-1] = temp % 10; //更新临时结果的位上信息
            nCarry = temp / 10; //看是否有进位
        }
        while(nCarry) { //如果最高位有进位
            a[++nDigits-1] = nCarry % 10; //新加一位，添加信息。位数增1
            nCarry /= 10; //看还能不能继续进位
        }
    }
	return nDigits;
}

int main()
{
	int a[10000];   //确保保存最终运算结果的数组足够大

    int n;         //阶乘大小
    printf("请输入n的大小(小于2000):");
   // scanf("%d",&n);//从键盘接收阶乘大小
    n = 20;
	int digits = bignumber_factorial(n, a);

    printf("结果是:\n%d ! = ", n); //显示结果
    for(int j = digits; j >=1; --j) {
        printf("%d",a[j-1]);
    }
	putchar('\n');

    return 0;
}
