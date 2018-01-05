/*
 * 1013.cpp
 *
 *  Created on: 2017年12月30日
 *      Author: ASUS
 */

#include<cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

int pr=2,prnum=1;		//当前搜索到的素数和该素数是第几个

int nextPr(int pr);
int searchPr(int num);

int main(){
//	clock_t start,finish;
//	start=clock();
	int m,n,pr,i=0;
	cin >> m >>n;
	pr = searchPr(m);
	while(i+m<n){
		cout << pr;
		if(++i%10!=0){
			cout << " ";
		}else{
			cout << endl;
		}
		pr = nextPr(pr);
	};
	cout << pr;		//输出最后一个
//	finish = clock();
//	cout << endl;
//	cout << "run time:" << finish - start <<endl;
//	while(1);

}

/**
 * 输入素数，返回下一个素数
 */
int nextPr(int pr){
	bool flag = true;
	int i=3,j=pr+2;
	if(pr==2) j=3;		//除了2以外素数都是奇数
	while(true){
		flag = true;
		for(i=3;i<=sqrt(j);i+=2){
			if(j%i==0){
				flag = false;
				break;
			}
		}
		if(flag) break;
		j+=2;			//检查下一个奇数
	}
	return j;
}

/**
 * 找到第num个素数
 */
int searchPr(int num){
	int pr=2;
	for(int i=1;i<num;i++){
		pr = nextPr(pr);
	}
	return pr;
}



