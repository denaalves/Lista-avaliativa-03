#include <stdio.h>
#include <string.h>


int romanoParaDecimal(char *romano) {
    int valores[26];
    valores['I' - 'A'] = 1;
    valores['V' - 'A'] = 5;
    valores['X' - 'A'] = 10;
    valores['L' - 'A'] = 50;
    valores['C' - 'A'] = 100;
    valores['D' - 'A'] = 500;
    valores['M' - 'A'] = 1000;

    int resultado = 0;
    int comprimento = strlen(romano);

    for (int i = 0; i < comprimento; i++) {
        if (i < comprimento - 1 && valores[romano[i + 1] - 'A'] > valores[romano[i] - 'A']) {
            resultado += valores[romano[i + 1] - 'A'] - valores[romano[i] - 'A'];
            i++; 
        } else {
            resultado += valores[romano[i] - 'A'];
        }
    }

    return resultado;
}


void decimalParaBinario(int normal, char *romano) {
    if (normal == 0) {
        printf("%s na base 2: 0\n", romano);
        return;
    }

    int binario[20];
    int i = 0;

   
    while (normal > 0) {
        binario[i] = normal % 2;
        normal = normal / 2;
        i++;
    }

    printf("%s na base 2: ", romano);
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

int main() {
    char romano[13];

    scanf("%s", romano);

    int decimal = romanoParaDecimal(romano);

    decimalParaBinario(decimal, romano);

    printf("%s na base 10: %d\n", romano, decimal);

    printf("%s na base 16: %x\n", romano, decimal);

    return 0;
}
//SELO-ADENILSON-DE-PRODUCAO