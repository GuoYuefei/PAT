/**
*	��һ����vsд���о����������͸�ˣ�����Ҫ���ԣ�û�취
*
**/
#include<iostream>
//���ڲ���
#define B 3
#define S 2
#define G 1
void toArray(int n,short* arr);
void change(short x,int oper);
using namespace std;
int main(){
	int n;short arr[3];
	cin >> n;
	toArray(n,arr);
	change(arr[0],B);
	change(arr[1],S);
	change(arr[2],G);
	system("pause");

}
//��һ����λ���ڵ����ַֽ��3�����ֱַ����һ��3��С�����飬��ʮ���ֱ����0��1��2
void toArray(int n,short* arr){
	arr[0] = n/100;
	arr[1] = n/10%10;
	arr[2] = n%10;
}

void change(short x,int oper){
	switch (oper){
		case B:
			while(x--){
				cout << "B";
			}break;
		case S:
			while (x--){
				cout << "S";
			}break;
		case G:
			for (int i=1;i<x+1;i++){
				cout << i;
			}break;
	}

}