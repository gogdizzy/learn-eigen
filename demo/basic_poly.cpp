#include <iostream>
#include <Eigen/Dense>

using std::cout;
using std::endl;
using Eigen::MatrixXd;
using Eigen::Vector3d;

void testMethod() {
	Vector3d p0, pf, v0, vf;
	p0 << 0, 0, 0;
	pf << 100, 200, 300;
	v0 << 10, 0, 0;
	vf << 0, 10, 0;

	double coe[5];
	coe[0] = -36 * p0.dot(p0) + 72 * p0.dot(pf) - 36 * pf.dot(pf);
	coe[1] = -24 * p0.dot(v0) + 24 * pf.dot(v0) - 24 * p0.dot(vf) + 24 * pf.dot(vf);
	coe[2] = -4 * v0.dot(v0) - 4 * v0.dot(vf) - 4 * vf.dot(vf);
	coe[3] = 0;
	coe[4] = 1;

	MatrixXd compan = MatrixXd::Constant(4, 4, 0.0);
	compan(0, 1) = 1;
	compan(1, 2) = 1;
	compan(2, 3) = 1;
	compan(3, 0) = -coe[0] / coe[4];
	compan(3, 1) = -coe[1] / coe[4];
	compan(3, 2) = -coe[2] / coe[4];
	compan(3, 3) = -coe[3] / coe[4];
	cout << compan << endl;
	cout << compan.eigenvalues() << endl;
	auto evs = compan.eigenvalues();
	for(int i = 0; i < evs.rows(); ++i) {
		if( evs(i).imag() == 0 )
			cout << evs(i) << endl;
	}
}


int main() {
	testMethod();
	return 0;
}
