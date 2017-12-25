#include "stdio.h"
#include "stdlib.h"
#include "math.h"

/*======================================================
// ��������r_sband
// �����������ø�˹��ȥ������ͷ�����
// ���������a ��ϵ������b ��������x���صĽ�����
//           n δ֪��������h �����
//           eps ����Ҫ��С��eps��ֵ����Ϊ��0��
// ����ֵ�����͡����гɹ��򷵻�1,ʧ���򷵻�0
=========================================================*/
int r_gsband(a, b, x, n, h, eps)

double *a, *b, *x, eps;
int n;
{
int i, j, k, l, v, p;
double tmp;
if((a==NULL)||(b==NULL)||(x==NULL))             /* ��������ָ���Ƿ�Ϊ��*/
{
printf("The pointer is NULL\n");
return(0);
}
for(
k = 0;
k<n;
k++)
{
l = k * n + k;
p = (k + h) < (n - 1) ? (k + h) : (n - 1);                   /* p=min(k+h, n-1)*/
if(
fabs(a[l])
< eps)                           /* �ж���Ԫ�Ƿ��С*/
{
printf("failed.\n");
return(0);                                   /* ����Ԫ��С���˳�����*/
}
a[l] = 1.0/a[l];                              /* ȡ����������ת��Ϊ�˷�*/
for(
j = k + 1;
j<=
p;
j++)                         /* ��һ������*/
{
v = k * n + j;
a[v] = a[l]*a[v];
}
b[k] = b[k]*a[l];                             /* ���������Ĺ�һ������*/

for(
i = k + 1;
i<=
p;
i++)                          /* ��Ԫ����*/
{
for(
j = k + 1;
j<=
p;
j++)
a[
i *n
+j] -= a[
i *n
+k]*a[
k *n
+j];
b[i] -= a[
i *n
+k]*b[k];                     /* ��������ҲҪ������Ԫ����*/
}
}
x[n-1] = b[n-1];                               /* ��һ�����ֱ�Ӷ���*/
for(
i = n - 2;
i>=0; i--)                          /* �������лش������������*/
{
p = (i + h) < (n - 1) ? (i + h) : (n - 1);                /* p=min(i+h, n-1)*/
tmp = 0.0;
for(
j = i + 1;
j<=
p;
j++)
tmp = tmp + a[i * n + j] * x[j];
x[i] = b[i] -
tmp;
}
return(1);                                   /* ���ɹ�������1*/
}
