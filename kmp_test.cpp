#include "kmp_algo.h"

using namespace std;

int main() {
	char str_m[] = "ILoveFishC";
	char str_p[] = "FishC";
	int size_m = sizeof(str_m) - 1, size_p = sizeof(str_p) - 1;
	int result = kmp_match(str_m, str_p, size_m, size_p);
	if (result != -1) {
		cout << "主串 : ";
		_print(str_m, result, result + size_p - 1, size_m);
		cout << "匹配的主串起始位置 : " << result << endl;
	}
	else {
		cout << "没有匹配结果!" << endl;
	}
}