#include "stdio.h"
#include "simplex.c"

main() {
    int i, j, n, m1, m2, m3, ixr[4], ixc[4];
    double eps = 1.0e-10;
    double a[6][5] = {{0.0,   1.0,  2.0,  3.0,  -4.0},
                      {100.0, -1.0, -2.0, -1.0, 0.0},
                      {10.0,  0.0,  -2.0, 3.0,  -1.0},
                      {0.0,   0.0,  -1.0, 1.0,  1.0},
                      {7.0,   -1.0, -1.0, -1.0, -1.0}};

    n = 4;
    m1 = 2;
    m2 = 1;
    m3 = 1;

    simplex(a, n, m1, m2, m3, ixr, ixc, eps);               /* ���ú���*/
    for (j = 1; j <= n; j++)                               /* ��ȡ��ֵΪ0��x���*/
    {
        if (ixr[j] < n)
            printf("x%d = 0.00\n", ixr[j]);
    }
    for (i = 1; i <= n; i++)                              /* ��ȡ��ֵ��Ϊ0��x���*/
    {
        if (ixc[i] < n)
            printf("x%d =%5.2f\n", ixc[i], a[i][0]);
    }
    printf("fopt = %5.2f\n", a[0][0]);                /* �����ļ�Сֵ*/
    printf("\nlast simplex:\n");                      /* ��ӡ���յĵ����α�*/
    printf("      b    ");
    for (j = 1; j < 5; j++) {
        if (ixr[j] < n + m1 + m2)                         /* ������������ı���z*/
            printf("x%d    ", ixr[j]);
    }
    printf("\n");
    printf("f  ");
    for (j = 0; j < 5; j++) {
        if (ixr[j] < n + m1 + m2)                         /* ������������ı���z*/
            printf("%5.2f ", a[0][j]);
    }
    printf("\n");
    for (i = 1; i < 5; i++) {
        printf("x%d ", ixc[i]);                      /* ���ж�Ӧ�ı������*/
        for (j = 0; j < 5; j++) {
            if (ixr[j] < n + m1 + m2)                     /* ������������ı���z*/
                printf("%5.2f ", a[i][j]);
        }
        printf("\n");
    }

}
