//���������⣬��ά����ָ����Ϊ���������򷵻�ֵ

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

typedef int (*aa)[2];   //�����ά����ָ������ 

// Ҫ���ɺͷ���������ĺ���
aa getRandom() {
	static int array[20][2];   //��̬�ֲ����� 
	//�������� 
	srand((unsigned)time(NULL));
	cout << "���20������㣺" << endl; 
	for(int i = 0; i < 20; i++){
		for(int j = 0;j < 2;j++) {
			array[i][j] = rand() % 100;    //x,y ��Χ��1��99�� 
		}
		cout << "(" << array[i][0] << "," << array[i][1] << ")";   //x = array[i][0], y = array[i][1]
		cout << endl;
	} 
	return array;  //���ض�ά����ָ��
}


int main(void) {
	
	int (*p)[2] = getRandom();//һ��ָ���ά�����ָ�� 
	int distMin = 10000; //��̾���
	int Xmin1, Ymin1, Xmin2, Ymin2;  // ��̵�� 
	//cout << p[0][1] << endl;
	//������
	for(int i = 0; i < 20; i++) {
		for(int j = i + 1; j < 20; j++){
			int dist = (p[j][0] - p[i][0]) * (p[j][0] - p[i][0]) +  (p[j][1] - p[i][1]) * (p[j][1] - p[i][1]);
			if(dist < distMin) {
				distMin = dist;
				Xmin1 = p[i][0];
				Xmin2 = p[j][0];
				Ymin1 = p[i][1];
				Ymin2 = p[j][1];
			}
		}
	}
	cout << "������Ϊ��" << "(" << Xmin1 << "," << Ymin1 << ")" << ", (" << Xmin2 << "," << Ymin2 << ")" << endl;
	cout << "�������Ϊ��" << sqrt(distMin) << endl; 
} 
