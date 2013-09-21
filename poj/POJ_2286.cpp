/*
 *	POJ2286 The Rotation Game
 *	解题思路：使用迭代加深的深度搜索算法，这里非常要注意还是剪枝的问题
 *	只有较好的针对题目环境的剪枝，才能提高搜索效率
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

//使用数组表示游戏局面
int map[25],countArray[25];
//搜索深度 , 最终的局面中心数字
int DEPTH,res;

char outPath[100];

//判断是否到达了目标局面
bool isOk(const int* state){

	int tmp = state[7];
	if( tmp!= state[8] || tmp!=state[9] || tmp!= state[12]
		|| tmp!= state[13] || tmp!=state[16] || tmp!= state[17]
		|| tmp!= state[18] ){

			return false  ;
		}
	return true ;
}

//统计局面的中心区域含有相同数字的最大数量
int countMaxSameNumber(const int* state){

	memset(countArray , 0 ,sizeof(countArray) ) ;
	countArray[ state[7] ]++; countArray[state[8]] ++; countArray[state[9]]++;
	countArray[ state[12] ]++; countArray[ state[13] ]++ ; countArray[state[16]]++;
	countArray[state[17]] ++ ; countArray[state[18]]++;

	countArray[2] = (countArray[2]>countArray[1]) ? countArray[2]: countArray[1];
	return max(countArray[2],countArray[3]);
}

void changeState(int *state,int a1,int a2,int a3,int a4,int a5,int a6,int a7){

	int tmp = state[a1];
	state[a1]=state[a2],state[a2]=state[a3],state[a3]=state[a4],
	state[a4]=state[a5],state[a5]=state[a6],state[a6]=state[a7],state[a7]=tmp;

}

//迭代加深搜索
//state：当前局面 currDepth :当前所处的搜索深度 preDir：当前搜索选择的旋转的方向
bool dfsSearch( int* state ,int currDepth , int preDir) {

	//剪枝 1  : 本质上使用的就是IDA*估价函数进行剪枝
	if( DEPTH - currDepth < 8- countMaxSameNumber(state))
		return false ;

	//超过了当前的搜索深度
	if( DEPTH <= currDepth )
		return false ;

	int tmp[25];
	for(int i=1 ; i<=8 ; i++){

		//剪枝2 ：前后连续的相反方向的两次旋转是没有意义的
		if( (1 == i && 6 == preDir) || (6==i && 1== preDir) )	continue ;
		if( (2 == i && 5 == preDir) || (5==i && 2== preDir) )	continue ;
		if( (3 == i && 8 == preDir) || (8==i && 3== preDir) )	continue ;
		if( (4 == i && 7 == preDir) || (7==i && 4== preDir) )	continue ;

	//	memcpy( tmp , state , sizeof(state)) ;
		for(int k=1 ; k<=24 ; k++)
			tmp[k]=state[k];

		switch(i){
			//记录搜索路径
			case 1 : outPath[currDepth] = 'A' ; changeState(tmp,1,3,7,12,16,21,23); break;
			case 2 : outPath[currDepth] = 'B' ; changeState(tmp,2,4,9,13,18,22,24); break;
			case 3 : outPath[currDepth] = 'C' ; changeState(tmp,11,10,9,8,7,6,5); break;
			case 4 : outPath[currDepth] = 'D' ; changeState(tmp,20,19,18,17,16,15,14); break;
			case 5 : outPath[currDepth] = 'E' ; changeState(tmp,24,22,18,13,9,4,2); break;
			case 6 : outPath[currDepth] = 'F' ; changeState(tmp,23,21,16,12,7,3,1); break;
			case 7 : outPath[currDepth] = 'G' ; changeState(tmp,14,15,16,17,18,19,20); break;
			case 8 : outPath[currDepth] = 'H' ; changeState(tmp,5,6,7,8,9,10,11); break;
			default : cout<<"ERROR!"<<endl;
		}

		if( isOk(tmp) ){

			res = tmp[7];
		 	outPath[currDepth +1]='\0';
			return true ;
		}

		if( dfsSearch(tmp , currDepth+1 , i))
			return true ;
	}

	return false ;
}


int main(){

	//ifstream in("test.txt");

	while(1){

		cin>>map[1];
		if( 0 == map[1])break;

		for(int i=2 ; i<=24 ; i++)cin>>map[i];

		if( isOk(map)){
			cout<<"No moves needed"<<endl;
			cout<<map[7]<<endl;
		}

		else{
			DEPTH =1 ;
			while(1){
				if(dfsSearch(map , 0 , -1 ))
					break;
				DEPTH ++ ;
			}

			cout<<outPath<<endl;
			cout<<res<<endl;
		}

	}
}
