#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char placa[10], dia_semana[20];
    const char *dias_semana[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};

    scanf("%s", placa);
    scanf("%s", dia_semana);

    int dia_valido = 0;
    for (int i = 0; i < 7; i++) {
        if (strcmp(dia_semana, dias_semana[i]) == 0) {
            dia_valido = 1;
            break;
        }
    }

    int placa_valida = 0;
    int tamanho_placa = strlen(placa);

    if ((tamanho_placa == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) && isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]))|| (tamanho_placa == 8 && isdigit(placa[6]) && placa[3] == '-') ) {
        placa_valida = 1;
    }

    if (!placa_valida && dia_valido ) {
        printf("Placa invalida\n");
        return 1;
    } else if (placa_valida && !dia_valido) {
        printf("Dia da semana invalido\n");
        return 1;
    }else if (!placa_valida && !dia_valido) {
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");
        return 1;
    }

    int ultimo_digito = placa[tamanho_placa - 1] - '0';
    int proibido = 0;
    int tamanho_dia = strlen(dia_semana);

    for(int i = 0; i < tamanho_dia; i++){
        dia_semana[i] = tolower(dia_semana[i]);
    }


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
