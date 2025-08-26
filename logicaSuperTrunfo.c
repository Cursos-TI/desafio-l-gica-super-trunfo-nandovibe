#include <stdio.h>
#include <string.h>

// Estrutura para armazenar informações da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para exibir menu
void exibirMenu() {
    printf("\n=== SUPER TRUNFO - MENU DE ATRIBUTOS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("0 - Sair do Jogo\n");
    printf("Escolha o atributo para comparação: ");
}

// Função para comparar os atributos
void comparar(Carta c1, Carta c2, int opcao) {
    printf("\nComparando %s (Carta 1) x %s (Carta 2)\n", c1.nomeCidade, c2.nomeCidade);

    switch (opcao) {
        case 1: // População
            printf("População:\n%s: %d habitantes\n%s: %d habitantes\n",
                   c1.nomeCidade, c1.populacao, c2.nomeCidade, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c1.populacao < c2.populacao)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Área:\n%s: %.2f km²\n%s: %.2f km²\n",
                   c1.nomeCidade, c1.area, c2.nomeCidade, c2.area);
            if (c1.area > c2.area)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c1.area < c2.area)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("PIB:\n%s: %.2f bilhões\n%s: %.2f bilhões\n",
                   c1.nomeCidade, c1.pib, c2.nomeCidade, c2.pib);
            if (c1.pib > c2.pib)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c1.pib < c2.pib)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Número de Pontos Turísticos:\n%s: %d\n%s: %d\n",
                   c1.nomeCidade, c1.pontosTuristicos, c2.nomeCidade, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c1.nomeCidade);
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade Demográfica (regra invertida)
            printf("Densidade Demográfica:\n%s: %.2f hab/km²\n%s: %.2f hab/km²\n",
                   c1.nomeCidade, c1.densidadeDemografica, c2.nomeCidade, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Resultado: %s venceu! (menor densidade ganha)\n", c1.nomeCidade);
            else if (c1.densidadeDemografica > c2.densidadeDemografica)
                printf("Resultado: %s venceu! (menor densidade ganha)\n", c2.nomeCidade);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Escolha um número entre 0 e 5.\n");
            break;
    }
}

int main() {
    // Carta 1
    Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50, 8102.47, 56724.32};

    // Carta 2
    Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30, 5622.24, 44532.91};

    int escolha;

    while (1) {
        exibirMenu();
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("\nVocê escolheu sair. Obrigado por jogar!\n");
            break;
        }

        comparar(carta1, carta2, escolha);

        printf("\n---------------------------------------\n");
        printf("A comparação terminou. Vamos de novo!\n");
    }

    return 0;
}