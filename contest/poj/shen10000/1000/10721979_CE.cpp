const int Max=5010;
struct Mapped_TYPE{
	int len;
	int Coord[Max];
	
	/* 用于初始化该映射 */
	Mapped_TYPE(){len=0;}
	
	/*用于插入一个分割坐标，此时坐标之间是无序的*/
	void Insert(int x){Coord[++len]=x;}
	
	void sort(){};
};