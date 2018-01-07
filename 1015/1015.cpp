/*
 * 1015.cpp
 *
 *  Created on: 2018��1��1��
 *      Author: ASUS
 *
 *
 *      本题应注意时间效率，cout一定要用printf代替，不然很容易超时
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;
/**
 * 学生
 */
class stu{
public:
	int id,de,cai;
	static vector<stu> a[4];
	stu():id(0),de(0),cai(0){}
	stu(int i,int d,int c):id(i),de(d),cai(c){
	}
	~stu(){
	}
	/**
	 * 考生分类
	 */
	inline bool clas(int pass,int good){
		if(de<pass||cai<pass){
			return false;				//没过线
		}else if(de>=good&&cai>=good){
			a[0].push_back(*this);					//才得全尽
		}else if(de>=good&&cai<good){
			a[1].push_back(*this);					//得大于才
		}else if(de<good&&cai<good&&de>=cai){
			a[2].push_back(*this);					//才得皆亡，但得尚大于才者
		}else{
			a[3].push_back(*this);					//其他考生
		}
		return true;
	}
};

int num=4,pass=60,good=80;		//记录输入人数，及格分，优秀分
vector<stu> stu::a[4];		//类中的static只是声明，故而在此定义
int input(){
	cin >> num >> pass >> good;
	int total = num;
	stu temp;
	for(int i=0;i<num;i++){
		cin >> temp.id >> temp.de >> temp.cai;
		if(!temp.clas(pass,good)){
			total--;
		}
	}
	return total;
}

bool compare(stu s1,stu s2){
	if(s1.cai+s1.de != s2.cai+s2.de){
		return (s1.cai+s1.de) > (s2.cai+s2.de);
	}else if(s1.de != s2.de){
		return s1.de > s2.de;
	}else{
		return s1.id < s2.id;
	}
}
/**
 * 对一个vector排序并输出
 */
void my_sort(vector<stu> array[]){
	//若使用最初的方法sort可能会打乱顺序，快排是一种不稳定排序，不过可以使用stable_sort代替
	for(int i=0;i<4;i++){
		sort(array[i].begin(),array[i].end(),compare);
		for(unsigned int j=0;j<array[i].size();j++){
			printf("%d %d %d\n",array[i][j].id,array[i][j].de,array[i][j].cai);
		}
	}
}

int main(){
	cout << input() <<endl;
	my_sort(stu::a);
	return 0;
}

