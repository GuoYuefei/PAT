/*
 * 1012.cpp
 *
 *  Created on: 2017年12月29日
 *      Author: Administrator
 */

#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int n[1000]={0};
int group[6][1001]={0};	//每行第一个数记录个数

int getin();
void quyu(int group[6][1001],int length);
void putout();

int main(){
	int length = getin();
	quyu(group,length);
	putout();
}


int getin(){
	int i = 0;
	cin >> n[i++];
	do{
		cin >> n[i++];
	}while(cin.get()!='\n');			//不换行就一直接收输入
	return i;
}


void quyu(int group[6][1001],int length){
	for(int i=1;i<length;i++){
		switch(n[i]%5){
		case 0:group[0][++group[0][0]] = n[i];break;
		case 1:group[1][++group[1][0]] = n[i];break;
		case 2:group[2][++group[2][0]] = n[i];break;
		case 3:group[3][++group[3][0]] = n[i];break;
		case 4:group[4][++group[4][0]] = n[i];break;
		}
	}
}

void putout(){
	for(int i=1;i<group[0][0]+1;i++){
		if(group[0][i]%2==0){
			group[5][0]+=group[0][i];
		}
	}
	for(int i=1;i<group[1][0]+1;i++){
		if(i%2!=0){					//从1开始的，所以！=时-
			group[5][1]+=group[1][i];
		}else{
			group[5][1]-=group[1][i];
		}
	}
	group[5][2] = group[2][0];
	for(int i=1;i<group[3][0]+1;i++){
		group[5][3]+=group[3][i];
	}
	float g53 = float(group[5][3])/group[3][0];
	for(int i=1;i<group[4][0]+1;i++){
		if(group[5][4]<group[4][i]){
			group[5][4] = group[4][i];
		}

	}
	//开始输出
	if(group[5][0]==0){			//为了满足题目的用例，但是个人觉得题目要求中是指%5==0的数字没有时才cout N的
		cout << "N"<<" ";		//但是题目用例中却不是，而是认为%10==0没有时就应该cout N
	}else{
		cout << group[5][0]<<" ";
	}
	for(int i=1;i<3;i++){
		if(group[i][0]==0){
			cout << "N"<<" ";
		}else{
			cout << group[5][i] <<" ";
		}
	}
	if(group[3][0]==0){
		cout << "N"<<" ";
	}else{
		printf("%.1f ",g53);
	}
	if(group[4][0]==0){
		cout << "N";
	}else{
		cout << group[5][4];
	}

//	for(int i=0;i<5;i++){
//		cout <<group[i][0]<<" ";
//	}


}


