#include <stdio.h>
#include <math.h>

int main() {
    int t;
    double a, i, v;

    scanf("%d", &t);
    getchar();

    scanf("%lf", &a);
    getchar();

    scanf("%lf", &i);
    getchar();

    for (int i2 = 1; i2 <= t; i2++) {
        v = a * (1 + i) * ((pow(1 + i, i2) - 1) / i);
        printf("Montante ao fim do mes %d: R$ %.2lf\n", i2, v);
    }

    return 0;
}
//SELO-ADENILSON-DE-PRODUÇÃO
