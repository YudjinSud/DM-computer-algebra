#include "Natural.h"
#include "Integ.h"
#include "Poly.h"
#include "Frac.h"

Poly ADD_PP_P(Poly a, Poly b) // P-1 сложение многочленов
{
	if (a.m < b.m)
		swap(a, b);
    for (int i = 0; i <= b.m; i++)
        a.C[i] = ADD_QQ_Q(a.C[i], b.C[i]);
	return a;
}

Poly SUB_PP_P(Poly a, Poly b) // P-2 вычитание многочленов
{
	if (a.m < b.m)
		swap(a, b);
	Frac nul;
	for (int i = 0; i <= b.m; i++)
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
    int i = a.m;
    Frac nul;
    while ((a.C[i] == nul)&&(i>0))
        i--;
	return a.C[i];
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
    if (a.m > 0) {
        NOD = GCF_NN_N(TRANS_Z_N(a.C[0].p), TRANS_Z_N(a.C[1].p));
        NOK = LCM_NN_N(a.C[0].q, a.C[1].q);
    }
    for (int i = 2; i <= a.m; i++) {
        NOD = GCF_NN_N(NOD, TRANS_Z_N(a.C[i].p));
        NOK = LCM_NN_N(NOK, a.C[i].q);
    }
    for (int i = 0; i <= a.m; i++) {
        a.C[i].p = MUL_ZZ_Z(TRANS_N_Z(DIV_NN_N(TRANS_Z_N(a.C[i].p), NOD)), TRANS_N_Z(DIV_NN_N(NOK,a.C[i].q)));
        a.C[i].q.n = 1;
        a.C[i].q.dig = {1};
    }
    return a;
}

Poly MUL_PP_P(Poly a, Poly b) // P-8 перемножение многочленов
{
    if (a.m < b.m)
        swap(a, b);
    Poly c = MUL_PQ_P(a, b.C[0]);
    for (int i = 1; i <= b.m; i++)
        c = ADD_PP_P(c, ADD_PP_P(MUL_PQ_P(a, b.C[i]),  MUL_Pxk_P(a, i)));
    c.m = DEG_P_N(c);
    c.C.resize(c.m+1);
    return c;
}



Poly DIV_PP_P(Poly a, Poly b) // P-9 Частное от деления многочлена на многочлен при делении с остатком
{
//    if (a.m < b.m)
//        swap(a, b);
//    else if ((a.m == b.m) && ()
//    Natural c;
//    c.n = 0;
//    int k = a.n - b.n;
//    // нашли k - степень 10
//    while (k >= 0) {
//        c.dig.push_back(DIV_NN_Dk(a, b)); // вписали первую цифру результата
//        c.n++;
//        if (COM_NN_D(a, MUL_Nk_N(b, k)) == 1)
//            k--;
//        a = SUB_NN_N(a, MUL_Nk_N(MUL_ND_N(b, DIV_NN_Dk(a, b)), k)); // a = a - первая цифра * b * 10^k
//        k--;
//        for (int i = 0; i < k; i++)  {
//            c.dig.push_back(0);
//            c.n++;
//            k--;
//        }
//        while (COM_NN_D(a, MUL_Nk_N(b, k+1)) == 2) {
//            k++;
//            c.dig.pop_back();
//            c.n--;
//        }
//    }
}


Poly DER_P_P(Poly a) { //P-12
    for (int i = 1; i <= a.m; i++) {
        int j = i;
        Integ h;
        h.b = 0;
        while (j > 0) {
            h.dig.push_back(j % 10);
            j /= 10;
        }
        h.n = int(h.dig.size());
        a.C[i - 1] = MUL_QQ_Q(a.C[i], TRANS_Z_Q(h));
    }
    a.C.pop_back();
    a.m--;
    return a;
}

