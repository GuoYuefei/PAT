/*
 * Guess.cpp
 *
 *  Created on: 2017年4月28日
 *      Author: Administrator
 */
#include<iostream>
#include<cstdlib>
using namespace std;

class Process{
private:
	int* n;
	int num;
	//将x从指定成员数组n中删除
	int removeSame(int x,int where){
		for(int i=0;i<num;i++){
			if(x==n[i]){		//如果查找到x了 那么就将其删除 num--
				for(int j=i;j<num-1;j++){
					n[j] = n[j+1];
				}
				num--;
				if(i<where){	//如果删除的数在已搜索位子的前面，那么返回1标记
					return 1;
				}
			}
		}
		return 0;
	}

	//奇偶判断函数，奇数就返回1，偶数返回0  输入那个数字
	bool odevity(int n){
		if(n%2==0){
			return false;
		}else{
			return true;
		}
	}

public:
	//输入
	void input(){
		cin >> num;
		n = new int[num];
		for(int i=0;i<num;i++){
			cin >> n[i];
		}
	}
	void sort(){
		//冒泡排序 我去竟然差点连冒泡都不会了，这个泡在for 0:n的过程中只能冒向后面
		for(int i=0;i<num-1;i++){
			for(int j=0;j<num-1-i;j++){
				if(n[j]<n[j+1]){
					int temp = n[j+1];
					n[j+1] = n[j];
					n[j] = temp;
				}
			}
		}
	}
	//输出
	void output(){
		for(int i=0;i<num-1;i++){
//			System.out.print(n[i]+" ");
			cout << n[i] << " ";
		}
//		System.out.print(n[num-1]);		//这个独立仅为了满足输出要求
		cout << n[num-1] << endl;
	}
	//构造
	Process(){
		input();
	}

//	Process(int num,int* n){
//		this.num = num;
//		this.n = n;			//这是引用赋值 注意
//	}

	//具体执行函数
	void process(){
		int i=0;
		int temp;

		for(i=0;i<num;i++){		//num在removeSame中改变
			temp = n[i];
			while(temp != 1){
				if(odevity(temp)){		//如果是奇数就执行下面语句
					temp = 3*temp+1;
					i-=removeSame(temp,i);		//如果需要验证的数组中有这个数就删除，如果删除的数在搜索的前面就让搜索序号-1重新定位到当前元素
				}
				//如果是奇数的话，经过上述的if后一定是偶数，所以都可以除2
				temp = temp/2;
				i-=removeSame(temp,i); 			//同上
			}
		}
	}
};


	int main( ){

//		Process pro = new Process();
		Process* pro = new Process();
//		int[] n =new int[100];
//		for(int i=0;i<99;i++){
//			n[i] = i+2;
//		}
//		Process pro = new Process(99, n);
		pro->process();
		pro->sort();
		pro->output();
		return 0;

	}








