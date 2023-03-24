#include <iostream>
#include <Eigen/Dense>

using std::cout;
using std::endl;
using Eigen::MatrixXcf;
using Eigen::Matrix3f;
using Eigen::Vector3f;

void testMethod() {
   Matrix3f A;
   Vector3f b;
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3f x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
}


int main() {
	testMethod();
	return 0;
}
