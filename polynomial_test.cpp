#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {
	// 生成多项式
	Poly A = Poly();
	Poly B = Poly();

	// 多项式初始化
	A.InitPoly();
	B.InitPoly();

	// 多项式运算
	(A + B).PrintPoly();
	(A - B).PrintPoly();

	return 0;
}