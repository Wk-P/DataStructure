#pragma once

/*
	多项式运算
	暂时只有加减
*/
#include <iostream>

typedef struct ListNode{
	int coe;			// 系数 coefficient
	int exp;			// 指数	exponent
	struct ListNode* next;
} ListNode;

// 多项式类
class Poly {
private:
	ListNode* coelist; // 系数表		coefficient list
	int size; // 元素个数	list size
public:
	Poly();							// 构造函数 constructor
	void InitPoly();				// 初始化   initialization
	Poly& operator+(Poly&);			// 相加	   '+' operator override
	Poly& operator-(Poly&);			// 相加	   '-' operator override
	void PrintPoly();				// 打印	   print out polynomial
};