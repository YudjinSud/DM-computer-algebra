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
	bool n = false;
	for (int i = a.m; i >= 0; i--) // удаление лишних нулей с конца
	{
		if (a.C[i] == nul)
		{
			n = true;
		}
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
	return a.m;
}