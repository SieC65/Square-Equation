#include <stdio.h>
#include <math.h>
#include <assert.h>
int SqEq_Ev (double, double, double, double*, double*);
int SqEq_Pr (double, double, double, double*, double*, int);
int SqEq_Test (double*, double*);
int SqEq_Sc (double*, double*, double*);
const int INF = -1;

int main ()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    char ch = 't';
    while (ch == 't' or ch == 'i')
    {
        printf ("\nWhat do you want to do? ''t'' - test, ''i'' - input your params, any other key - quit. \n");
        scanf ("%1s",&ch);
        switch (ch)
        {
            case 't':
                SqEq_Test (&x1, &x2);
                break;
            case 'i':
                SqEq_Sc (&a, &b, &c);
                int N_Roots = SqEq_Ev (a, b, c, &x1, &x2);
                SqEq_Pr (a, b, c, &x1, &x2, N_Roots);
        }
    }
}

int SqEq_Test (double* x1, double* x2)
{
    const int Np = 7;
    double a[Np] = { 1,  0,   1,   0,  0,  -1,  0};
    double b[Np] = {-3,  0,  -2,   1,  1,   3,  0};
    double c[Np] = { 4,  1,   1,  -5,  0,   0,  0};
    printf ("\n--------TEST--------\n");
    for (int i = 0; i < Np; i++)
    {
        int N_Roots = SqEq_Ev (a[i], b[i], c[i], x1, x2);
        SqEq_Pr (a[i], b[i], c[i], x1, x2, N_Roots);
    }
    printf ("\n-----END OF TEST-----\n");
}

int SqEq_Sc (double* a, double* b, double* c)
{
    assert (a != b && b != c && a != c);
    printf ("\nInput a, b, c \n");
    printf (" a=");
    scanf ("%lg", a);
    printf (" b=");
    scanf ("%lg", b);
    printf (" c=");
    scanf ("%lg", c);
}

int SqEq_Ev (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != x2);
    double d = 0;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0) return INF;
            else return (0);
        }
        else
        {
            *x1 = (-c/b);
            *x2 = *x1;
            return (1);
        }
    }
    else
    {
        d = (b*b - 4*a*c);
        if (d < 0)
        {
            return (0);
        }
        else if (d == 0)
        {
            *x1 = (-b + sqrt(d)) / 2;
            *x2 = *x1;
            return (1);
        }
        else
        {
            *x1 = (-b + sqrt(d)) / 2;
            *x2 = (-b - sqrt(d)) / 2;
            return (2);
        }
    }
}

int SqEq_Pr (double a, double b, double c, double* x1, double* x2, int N_Roots)
{
    assert (x1 != x2);
    printf ("\nFor a = %.1f, b = %.1f, c = %.1f ", a, b, c);
    if (N_Roots == 0) printf ("\n there are no roots \n");
    else if (N_Roots == 1) printf ("\n there is one root: \n  x1 = %.1f \n", *x1);
    else if (N_Roots == 2) printf ("\n there are two roots: \n  x1 = %.1f \n  x2 = %.1f \n", *x1, *x2);
    else if (N_Roots == -1) printf ("\n there are infinitive amount of roots \n");
}
