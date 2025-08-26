#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da cidade
typedef struct {
    char nome[50];
    char estado[3];  // Sigla do estado (ex: "SP", "RJ")
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Cidade;

// Função para imprimir inteiros com separador de milhar (pontos)
void imprimeComPontos(int valor) {
    char buffer[50];
    char formatado[60];
    int i, j, len, count = 0;

    sprintf(buffer, "%d", valor);   // converte o número para string
    len = strlen(buffer);
    j = 0;

    for (i = 0; i < len; i++) {
        formatado[j++] = buffer[i];
        if ((len - i - 1) % 3 == 0 && i != len - 1) {
            formatado[j++] = '.';
        }
    }
    formatado[j] = '\0';
    printf("%s", formatado);
}

int main() {
    // --- Definição das cartas ---
    Cidade carta1, carta2;

    // Carta 1 - São Paulo
    strcpy(carta1.nome, "São Paulo");
    strcpy(carta1.estado, "SP");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699280000000.0;
    carta1.pontosTuristicos = 50;
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Carta 2 - Rio de Janeiro
    strcpy(carta2.nome, "Rio de Janeiro");
    strcpy(carta2.estado, "RJ");
    carta2.populacao = 6000000;
    carta2.area = 1182.30;
    carta2.pib = 407000000000.0;
    carta2.pontosTuristicos = 40;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // --- Atributo escolhido: População ---
    char atributoComparado[20] = "Populacao";

    printf("Comparacao de cartas (Atributo: %s):\n\n", atributoComparado);

    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    imprimeComPontos(carta1.populacao);
    printf("\n");

    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);
    imprimeComPontos(carta2.populacao);
    printf("\n\n");

    // --- Comparação ---
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}