/*=============================================================
// �� �� ����errf
// �������������������ֵ
// ���������x �Ա���x��ֵ��
// �� �� ֵ��������ֵ
//==============================================================*/
#include "stdio.h"
#include "math.h"
#include "gamm2.c"

#define EPS 1.0e-6                    /* ʹ�ò���ȫ٤������Ҫ������*/
#define DMIN 1.0e-30
double errf(x)
double x;
{
double t;
t = gamm2(0.5, x * x, EPS, DMIN);
if(x<0)                             /* ��x<0����ȡ��*/
t = -t;
return(t);
}
