/*
 * 1014.cpp
 *
 *  Created on: 2017��12��30��
 *      Author: ASUS
 */

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
char n[4][61];

void getin(){

	for(int i=0;i<4;i++){
		int j=0;
		do{
			n[i][j++]=cin.get();
		}while(n[i][j-1]!='\n');
	}
//	for(int i=0;i<4;i++){
//		int j=0;
//		do{
//			cout << n[i][j++];
//		}while(n[i][j-1]!='\n');
////			cout << endl;
//	}
}

/**
 * �ӵ�num���ַ���ʼ�Ƚϣ����ֵĵ�һ����ͬ�ַ���ŷ��أ���0������
 */
int search(char m[],char n[],int num){
	for(int i=num;m[i]!='\n'&&n[i]!='\n';i++){
		if(m[i]==n[i]){
			return i;
		}
	}
	return -1;				//��num֮��������ͬԪ�أ�����-1
}



string wk[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
	int num=-1,i=0;
	bool flag=true;			//flag=1��ʾҪ���wk���������Сʱ
	char temp[61];
	getin();
	do{
		num = search(n[1],n[0],num+1);
		if(num!=-1){
			temp[i++] = n[0][num];			//���i����temp�ж���Ԫ��
		}
	}while(num!=-1);
	for(int j=0;j<i;j++){
		if(temp[j]>='A'&&temp[j]<='G'&&flag){
			cout << wk[temp[j]-'A']<<" ";			//�ҵ���һ����д��ĸ��������ڼ�
			flag = false;continue;
		}
		if((temp[j]>='A'&&temp[j]<='N')&&!flag){
			cout << temp[j]-'A'+10<<":";break;
		}
		if((temp[j]>='0'&&temp[j]<='9')&&!flag){
			cout <<"0"<< temp[j] << ":";break;
		}
	}
	num=-1;
	char tmp;
	do{
		num = search(n[2],n[3],num+1);
		tmp = n[2][num];
	}while(!((tmp>='A'&&tmp<='Z')||(tmp>='a'&&tmp<='z')));
	if(num>9){
		cout << num;
	}else{
		cout << 0 << num;
	}
	return 0;
}



