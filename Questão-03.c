#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[10], dia_semana[20];
    const char *dias_semana[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    // Leitura da placa e do dia da semana
    scanf("%s", placa);
    scanf("%s", dia_semana);

    // Verificação do formato do dia da semana
    int dia_valido = 0;
    for (int i = 0; i < 7; i++) {
        if (strcmp(dia_semana, dias_semana[i]) == 0) {
            dia_valido = 1;
            break;
        }
    }

    // Verificação do formato da placa
    int placa_valida = 0;
    int tamanho_placa = strlen(placa);

    if ((tamanho_placa == 7 || tamanho_placa == 8) &&
        isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
        placa[3] == '-' &&
        isdigit(placa[4]) && isdigit(placa[5]) && isdigit(placa[6]) && isdigit(placa[7])) {
        placa_valida = 1;
    }

    // Verificação e saída
    if (!placa_valida) {
        printf("Placa invalida\n");
        return 1;
    } else if (!dias_semana) {
        printf("Dia da semana invalido\n");
        exit(0);
    }


    int ultimo_digito = placa[tamanho_placa - 1] - '0';
    int proibido = 0;

    if (strstr("SEGUNDA-TERCA-QUARTA-QUINTA-SEXTA", dia_semana)) {
        if (ultimo_digito >= 0 && ultimo_digito <= 1) proibido = 1;
    } else if (strcmp(dia_semana, "SABADO") == 0 || strcmp(dia_semana, "DOMINGO") == 0) {
        printf("%s nao pode circular %s\n", placa, dia_semana);
        return 0;
    } else {
        if (ultimo_digito >= 6 && ultimo_digito <= 9) proibido = 1;
    }
    
    if (proibido) {
        printf("%s nao pode circular %s\n", placa, dia_semana);
    } else {
        printf("%s pode circular %s\n", placa, dia_semana);
    }

    return 0;
}
