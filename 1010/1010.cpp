/**
 * 这一题分成两个数组，然后导数的系数就是两个对应位子相乘，指数-1
 */

#include<iostream>
//#include<stdio.h>
#include<cstdlib>

using namespace std;

int coe[2001] = {};			//存放系数
int index[2001]={};		//存放指数

int getin();
void putout(int n);

int main(){

	int num = getin();
	for(int i=0;i<num;i++){
		if(index[i]==0){
			index[i]=0;
			coe[i] = 0;
			break;
		}
		coe[i] *= index[i];
		index[i]--;
	}
	putout(num);
}

/**
 * 接收输入并返回输入个数的一半，也就是多项式有几项
 */
int getin(){
	int i = 0;
	do{
		cin >> coe[i] >> index[i];
		i++;
	}while(cin.get()!='\n');	//当换行时跳出循环,新发现的一个输入技巧，利用了缓冲区接收\r并进入缓冲去后变成\n
	return i;		//返回有几项
}

//格式化输出结果
void putout(int n){
	if(index[0]==0&&coe[0]==0){
		cout << "0 0";
	}
	for(int i=0;i<n;i++){
		if(coe[i]==0) continue;
		cout << coe[i] <<" "<<index[i];
		if(!(index[i+1]==0&&coe[i+1]==0)){
			cout << " ";
		}
	}
}


