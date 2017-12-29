/*
 * 1011.cpp
 *
 *  Created on: 2017年12月29日
 *      Author: Administrator
 */
#include<iostream>
#include<cstdlib>

/**
 * 小心超出int边界的测试用例
 */

using namespace std;

void getin(int n,long num[10][3]);
void putout(int n,long num[10][3]);

int main(){
	long num[10][3]={0};
	int n=0;
	cin >> n;
	getin(n,num);
	putout(n,num);
	return 0;
}


//接收入二维数组
void getin(int n,long num[10][3]){
	for(int i=0;i<n;i++){
		int k=0;
		while(k<3){
			cin >> num[i][k++];
		}
	}
}

void putout(int n,long num[10][3]){
	for(int i=0;i<n;i++){
		if(num[i][0]+num[i][1]<=num[i][2]){
			cout << "Case #" << i+1 << ": false" << endl;
		}else{
			cout << "Case #" << i+1 << ": true" <<endl;
		}
	}
}


