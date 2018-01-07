/*
 * 1016.cpp
 *
 *  Created on: 2018年1月7日
 *      Author: Administrator
 */
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int pow10(int i){
	int n=1;
	while(i--){
		n*=10;
	}
	return n;
}


/**
 * 重组一个整数,输入里表明最高10位
 */
int redecompose(int a,int da){
	vector<int> ve;
	int temp;
	for(int i=0;i<10;i++){
		temp = a%10;
		a = a/10;
		if(temp==da){				//如果分解出来的数字和给定的数字相同，暂时放入容器
			ve.push_back(da);
		}
	}
	temp=0;
	for(int i=ve.size();i>0;i--){
		temp+=da*pow10(i-1);
	}
	return temp;
}

int main(){
	int a,b,da,db;
	cin >> a >> da >> b >> db;
	a = redecompose(a,da);
	b = redecompose(b,db);
	cout << a+b;


}




