/*
	多项式（polynomial）运算
*/

#include "polynomial.h"

Poly::Poly() {
	coelist = NULL;
	size = 0;
}							
void Poly::InitPoly() {
	std::cout << "多项式项数:" << std::flush;
	std::cin >> size;
	coelist = new ListNode;
	coelist->coe = -1;
	coelist->exp = -1;
	coelist->next = NULL;
	ListNode* tail = coelist;
	for (int i = 0; i < size; i++) {
		ListNode* temp = new ListNode;
		if (!temp) exit(1);
		std::cout << "输入第 " << i+1 << " 项系数(coe)和指数(exp):" << std::flush;
		std::cin >> temp->coe >> temp->exp;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}
}

Poly& Poly::operator+(Poly& f) {
	// f -> formula 式子
	ListNode* p1 = coelist->next, *p2 = f.coelist->next;
	Poly nf = Poly();
	nf.coelist = new ListNode;
	nf.coelist->exp = -1;
	nf.coelist->coe = -1;
	nf.coelist->next = NULL;
	ListNode* newlp = new ListNode;
	nf.coelist->next = newlp;
	if (!newlp) {
		std::cout << "Wrong\n";
	}
	while (p1 || p2) {
		if (p1 && p2) {
			if (p1->exp == p2->exp) {
				newlp->coe = p1->coe + p2->coe;
				newlp->exp = p1->exp;
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->exp > p2->exp) {
				newlp->exp = p2->exp;
				p2 = p2->next;
			}
			else if (p1->exp < p2->exp) {
				newlp->exp = p1->exp;
				p1 = p1->next;
			}
		}
		else if (!p1 && p2) {
			newlp->exp = p2->exp;
			newlp->coe = p2->coe;
			p2 = p2->next;
		}
		else if (!p2 && p1) {
			newlp->exp = p1->exp;
			newlp->coe = p1->coe;
			p1 = p1->next;
		}
		nf.size++;
		newlp->next = new ListNode;
		if (p1 || p2) newlp = newlp->next;
		else newlp->next = NULL;
	}
	return nf;
}

Poly& Poly::operator-(Poly& f) {
	// f -> formula 式子
	// this substract f "this" '-' "f" 
	ListNode* p1 = coelist->next, * p2 = f.coelist->next;
	Poly nf = Poly();
	nf.coelist = new ListNode;
	nf.coelist->exp = -1;
	nf.coelist->coe = -1;
	nf.coelist->next = NULL;
	ListNode* newlp = new ListNode;
	nf.coelist->next = newlp;
	if (!newlp) {
		std::cout << "Wrong\n";
	}
	while (p1 || p2) {
		if (p1 && p2) {
			if (p1->exp == p2->exp) {
				newlp->coe = p1->coe - p2->coe;
				newlp->exp = p1->exp;
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1->exp > p2->exp) {
				newlp->exp = -p2->exp;
				p2 = p2->next;
			}
			else if (p1->exp < p2->exp) {
				newlp->exp = p1->exp;
				p1 = p1->next;
			}
		}
		else if (!p1 && p2) {
			newlp->exp = p2->exp;
			newlp->coe = -p2->coe;
			p2 = p2->next;
		}
		else if (!p2 && p1) {
			newlp->exp = p1->exp;
			newlp->coe = p1->coe;
			p1 = p1->next;
		}
		nf.size++;
		newlp->next = new ListNode;
		if (p1 || p2) newlp = newlp->next;
		else newlp->next = NULL;
	}
	return nf;
}

void Poly::PrintPoly() {
	if (!coelist->next) {
		std::cout << "Empty!" << std::endl;
		return;
	}
	ListNode* tran = coelist->next;
	while (tran) {
		std::cout << "[ coe : " << tran->coe << " , exp : " << tran->exp << " ]" << std::endl;
		tran = tran->next;
	}
}