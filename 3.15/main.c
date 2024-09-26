#include <stdio.h>
#include <math.h>

void main(void)
{
    int I = 1, B = 0, C;
    double RES;
    RES = 4.0 / I;
    C = 1;
    while ((fabs (3.1415 - RES)) > 0.0005)
        {
            I += 2 ;
            if (B)
                {
                    RES += (double) (4.0 / I);
                    /*double es parecido a float pero con mayor cantidad de digitos, es decir, mayor precision*/
                    B = 0;
    }
    else
    {
            RES -= (double) (4.0 / I);
            B = 1;
    }
    C++;
    }
    printf("\nNumero de términos:%d", C);
}
