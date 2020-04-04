//最近点对问题，二维数组指针作为函数参数或返回值

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

typedef int (*aa)[2];   //定义二维数组指针类型 

// 要生成和返回随机数的函数
aa getRandom() {
	static int array[20][2];   //静态局部变量 
	//设置种子 
	srand((unsigned)time(NULL));
	cout << "随机20个坐标点：" << endl; 
	for(int i = 0; i < 20; i++){
		for(int j = 0;j < 2;j++) {
			array[i][j] = rand() % 100;    //x,y 范围（1，99） 
		}
		cout << "(" << array[i][0] << "," << array[i][1] << ")";   //x = array[i][0], y = array[i][1]
		cout << endl;
	} 
	return array;  //返回二维数组指针
}


int main(void) {
	
	int (*p)[2] = getRandom();//一个指向二维数组的指针 
	int distMin = 10000; //最短距离
	int Xmin1, Ymin1, Xmin2, Ymin2;  // 最短点对 
	//cout << p[0][1] << endl;
	//最近点对
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
	cout << "最近点对为：" << "(" << Xmin1 << "," << Ymin1 << ")" << ", (" << Xmin2 << "," << Ymin2 << ")" << endl;
	cout << "最近距离为：" << sqrt(distMin) << endl; 
} 
