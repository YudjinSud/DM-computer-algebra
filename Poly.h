#pragma once
#ifndef DM_COMPUTER_ALGEBRA_POLY_H
#define DM_COMPUTER_ALGEBRA_POLY_H


#include <vector>
#include <iosfwd>
#include <algorithm>
#include "Frac.h"
#include "Integ.h"
#include "Natural.h"
using namespace std;

struct Poly { // P/Q
	int m; // max ������� � ��������
	vector<Frac>C; // ������ �������������


	Poly() // C[0] - �������, �[1] - ����, �[2] - ���� � ��������...
	{
		Frac bla;
		this->C.push_back(bla);
		this->m = 1;
	}
	bool operator==(const Poly& other)
	{
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			if (this->C[i] == other.C[i])
				k++;
		}
		return ((this->m == other.m) && (k == m));
	}
	~Poly()
	{
		C.clear();
	}
};


Poly ADD_PP_P(Poly a, Poly b); // P-1 �������� �����������

Poly SUB_PP_P(Poly a, Poly b); // P-2 ��������� �����������

Poly MUL_PQ_P(Poly a, Frac r); // P-3 ��������� ���������� �� ������������ �����

Poly MUL_Pxk_P(Poly a, int k); // P-4 ��������� ���������� �� x^k

Frac LED_P_Q(Poly a); // P-5 ���������� ������� ����������� ����������

int DEG_P_N(Poly a); // P-6 ���������� ������� ����������

Poly FAC_P_Q(Poly a); // P-7 ��������� �� ���������� ��� ������������ ������������� � ��� ����������

Poly MUL_PP_P(Poly a, Poly b); // P-8 ������������ �����������

Poly DIV_PP_P(Poly a, Poly b); // P-9 ������� �� ������� ���������� �� ��������� ��� ������� � ��������

Poly MOD_PP_P(Poly a, Poly b); // P-10 ������� �� ������� ���������� �� ��������� ��� ������� � ��������

Poly GCF_PP_P(Poly a, Poly b); // P-11 ��� �����������

Poly DER_P_P(Poly a); // P-12 ����������� ����������

Poly NMR_P_P(Poly a); // P-13 �������������� ���������� � ������� ����� � �������

#endif //DM_COMPUTER_ALGEBRA_POLY_H