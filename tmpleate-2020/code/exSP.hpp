// 爆栈问题处理(切换栈指针) By 猛犸也钻地 @ 2012.03.23

/* 使用方法：对于会爆栈的函数，在被调用之前及之后位置加上exSP() //
   在x86环境下运行正常，其他硬件环境下没有测试过
   在x64环境下，可能要把下面定义中的long改成long long，或是改成size_t
   (在64位的操作系统中，只有Windows的long是32位，其他都是64位的)
   此模板中定义的变量必须放在其他变量之前，且不能变动定义的顺序 
// 由于比赛环境差异很大，所以不保证此模板能处处有效 */

const int MEMS = 1<<24;
long data[MEMS],* mysp = data+MEMS-1,* bksp;
register long* sp asm("esp"); // 16位环境下是sp，32位是esp，64位是rsp
#define exSP() do bksp=sp,sp=mysp,mysp=bksp; while(0)
