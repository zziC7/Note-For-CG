#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<unordered_map>
#include <Eigen\Dense>

using namespace std;
using namespace Eigen;

const double PI = acos(-1);

int main()
{	
	Vector3d p(2, 1, 1);	//需要处理的点P(2,1)，并用齐次坐标表示
	Matrix3d M;		//变换矩阵，包括了线性变换和平移
	//M赋值
	M << cos(PI / 4), -sin(PI / 4), 1,
		 sin(PI / 4), cos(PI / 4),  2,
		 0,           0,            1;
	cout << M * p;

	return 0;
}