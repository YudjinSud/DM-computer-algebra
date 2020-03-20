#include "Natural.h"
#include "Integ.h"
#include "Poly.h"
#include "Frac.h"

Poly ADD_PP_P(Poly a, Poly b) // P-1 сложение многочленов
{
	if (a.m < b.m)
		swap(a, b);
	int delta = a.m - b.m;
	Frac nul;
	for (int i = 0; i <= delta; i++)
		b.C.push_back(nul);
	for (int i = 0; i <= a.m; i++)
		a.C[i] = ADD_QQ_Q(a.C[i], b.C[i]);
	return a;
}

Poly SUB_PP_P(Poly a, Poly b) // P-2 вычитание многочленов
{
	if (a.m < b.m)
		swap(a, b);
	int delta = a.m - b.m;
	Frac nul;
	for (int i = 0; i <= delta; i++)
		b.C.push_back(nul);
	for (int i = 0; i <= a.m; i++)
		a.C[i] = SUB_QQ_Q(a.C[i], b.C[i]);
	for (int i = a.m; i >= 0; i--) // удаление лишних нулей с конца
	{
		if (a.C[i] == nul)
		{
			a.C.pop_back();
			a.m--;
		}
		else
		    break;
	}
	return a;
}

Poly MUL_PQ_P(Poly a, Frac r) // P-3 умножение многочлена на рациональное число
{
	Frac bla;
	Poly nul;
	if (r == bla)
		return nul;
	for (int i = 0; i <= a.m; i++)
		a.C[i] = MUL_QQ_Q(a.C[i], r);
	return a;
}

Poly MUL_Pxk_P(Poly a, int k) // P-4 умножение многочлена на x^k
{
	Frac nul;
	reverse(a.C.begin(), a.C.end());
	for (int i = 0; i < k; i++)
		a.C.push_back(nul);
	a.m += k;
	reverse(a.C.begin(), a.C.end());
	return a;
}

Frac LED_P_Q(Poly a) // P-5 возвращает старший коэффициент многочлена
{
	return a.C[a.m];
}

int DEG_P_N(Poly a) // P-6 возвращает степень многочлена
{
	int i = a.m;
	Frac nul;
	while ((a.C[i] == nul)&&(i>0))
    {
	    i--;
    }
	return i;
}

Poly FAC_P_Q(Poly a) // P-7 Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
{
    Natural NOD, NOK;
    if (a.m > 0) // если <= 0, то 1 или 0 чисел в многочлене и нечего выносить
    {
        NOD = GCF_NN_N(TRANS_Z_N(a.C[0].p),TRANS_Z_N(a.C[1].p));
        NOK = LCM_NN_N(a.C[0].q, a.C[1].q);
    }
    for (int i = 2; i <= a.m; i++)
    {
        NOD = GCF_NN_N(NOD, TRANS_Z_N(a.C[i].p));
        NOK = LCM_NN_N(NOK, a.C[i].q);
    }
    for (int i = 0; i <= a.m; i++)
    {
        a.C[i].p = TRANS_N_Z(DIV_NN_N(TRANS_Z_N(a.C[i].p), NOD));
        a.C[i].q = DIV_NN_N(a.C[i].q, NOK);
    }
    return a;
}

Poly MUL_PP_P(Poly a, Poly b) // P-8 перемножение многочленов
{
    if (a.m < b.m)
        swap(a, b);
    Poly c = MUL_PQ_P(a, TRANS_Z_Q(b.C[0].p));
    for (int i = 1; i <= b.m; i++)
        c = ADD_PP_P(c, ADD_PP_P(MUL_PQ_P(a, TRANS_Z_Q(b.C[i].p)),  MUL_Pxk_P(a, i)));
    return c;
}

