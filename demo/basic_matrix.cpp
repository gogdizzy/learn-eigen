#include <iostream>
#include <Eigen/Dense>

using std::cout;
using std::endl;
using namespace Eigen;

void testMethod() {
	MatrixXcf a = MatrixXcf::Random(2,2);
	cout << "Here is the matrix a\n" << a << endl;
	cout << "Here is the matrix a^T\n" << a.transpose() << endl;
	cout << "Here is the conjugate of a\n" << a.conjugate() << endl;
	cout << "Here is the matrix a^*\n" << a.adjoint() << endl;

	MatrixXd b = MatrixXd::Zero(3, 3);
	cout << "before b\n" << b << endl;
	auto bk1 = b.block(1, 1, 2, 2);
	bk1(1, 1) = 3;
    cout << "after b\n" << b << endl;

    VectorXd c = VectorXd::Zero(3);
    cout << "before c\n" << c << endl;
    auto sg1 = c.segment(1, 2);
    sg1(1) = 3;
    cout << "after c\n" << c << endl;

    VectorXd d(4);
    d << 1, 2, 3, 4;
    cout << "init d\n" << d << endl;

    MatrixXd e = MatrixXd::Zero(3, 3);
    VectorXd f(3);
    f << 1, 2, 3;
    e.col(1) = f;
    cout << "after e\n" << e << endl;

    Matrix<double, Dynamic, Dynamic, RowMajor> g(3, 4);
    cout << "begin g\n" << g << endl;
    g.block(0, 0, 3, 3) = e;
    cout << "after g\n" << g << endl;
    for(auto i = 0; i < g.rows() * g.cols(); ++i) cout << g.data()[i] << endl;
    cout << ( g.row(1) - g.row(0) ) << endl;
    cout << ( g.row(1) - g.row(0) ).norm() << endl;


}


int main() {
	testMethod();
	return 0;
}
