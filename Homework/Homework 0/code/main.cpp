#include<cmath>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include<iostream>

using namespace std;
using namespace Eigen;

const double PI = acos(-1);

int main()
{	
	Vector3d p(2, 1, 1);	
	Matrix3d M;		//M is transfrom matrix
	//Init M
	M << cos(PI / 4), -sin(PI / 4), 1,
		 sin(PI / 4), cos(PI / 4),  2,
		 0,           0,            1;
	cout << M * p;

	return 0;
}