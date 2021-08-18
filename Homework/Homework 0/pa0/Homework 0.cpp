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
	Vector3d p(2, 1, 1);	//��Ҫ����ĵ�P(2,1)��������������ʾ
	Matrix3d M;		//�任���󣬰��������Ա任��ƽ��
	//M��ֵ
	M << cos(PI / 4), -sin(PI / 4), 1,
		 sin(PI / 4), cos(PI / 4),  2,
		 0,           0,            1;
	cout << M * p;

	return 0;
}