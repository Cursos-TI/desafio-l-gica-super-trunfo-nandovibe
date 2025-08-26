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

// Função para exibir menu de atributos
void exibirMenu(int excluido) {
    printf("\n=== SUPER TRUNFO - MENU DE ATRIBUTOS ===\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Número de Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    printf("0 - Sair do Jogo\n");
    printf("Escolha o atributo: ");
}

// Função para pegar valor do atributo
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0;
    }
}

// Função para imprimir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função principal de comparação
void comparar(Carta c1, Carta c2, int attr1, int attr2) {
    float valor1_c1 = obterValor(c1, attr1);
    float valor1_c2 = obterValor(c2, attr1);

    float valor2_c1 = obterValor(c1, attr2);
    float valor2_c2 = obterValor(c2, attr2);

    // Regras especiais (densidade vence quem tem menor)
    int vencedorAttr1 = (attr1 == 5) ? 
                        (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0)) :
                        (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    int vencedorAttr2 = (attr2 == 5) ? 
                        (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0)) :
                        (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n=== RESULTADO DA RODADA ===\n");
    printf("%s (Carta 1) x %s (Carta 2)\n\n", c1.nomeCidade, c2.nomeCidade);

    // Mostrar valores do primeiro atributo
    printf("%s:\n", nomeAtributo(attr1));
    printf("  %s: %.2f\n  %s: %.2f\n",
           c1.nomeCidade, valor1_c1, c2.nomeCidade, valor1_c2);
    printf("Vencedor no atributo: %s\n\n", vencedorAttr1 == 1 ? c1.nomeCidade :
                                               vencedorAttr1 == 2 ? c2.nomeCidade : "Empate");

    // Mostrar valores do segundo atributo
    printf("%s:\n", nomeAtributo(attr2));
    printf("  %s: %.2f\n  %s: %.2f\n",
           c1.nomeCidade, valor2_c1, c2.nomeCidade, valor2_c2);
    printf("Vencedor no atributo: %s\n\n", vencedorAttr2 == 1 ? c1.nomeCidade :
                                               vencedorAttr2 == 2 ? c2.nomeCidade : "Empate");

    // Mostrar soma
    printf("SOMA DOS ATRIBUTOS:\n");
    printf("  %s: %.2f\n  %s: %.2f\n", c1.nomeCidade, soma1, c2.nomeCidade, soma2);

    // Resultado final
    printf("\n>>> RESULTADO FINAL: ");
    if (soma1 > soma2) printf("%s venceu a rodada!\n", c1.nomeCidade);
    else if (soma1 < soma2) printf("%s venceu a rodada!\n", c2.nomeCidade);
    else printf("Empate!\n");
}

int main() {
    // Carta 1
    Carta carta1 = {'A', "A01", "São Paulo", 12325000, 1521.11, 699.28, 50, 8102.47, 56724.32};

    // Carta 2
    Carta carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30, 5622.24, 44532.91};

    int escolha1, escolha2;

    while (1) {
        exibirMenu(0);
        scanf("%d", &escolha1);

        if (escolha1 == 0) {
            printf("\nVocê escolheu sair. Obrigado por jogar!\n");
            break;
        }

        // Menu dinâmico (não mostra o escolhido antes)
        exibirMenu(escolha1);
        scanf("%d", &escolha2);

        if (escolha2 == 0) {
            printf("\nVocê escolheu sair. Obrigado por jogar!\n");
            break;
        }

        if (escolha1 == escolha2) {
            printf("\nVocê não pode escolher o mesmo atributo duas vezes!\n");
            continue;
        }

        comparar(carta1, carta2, escolha1, escolha2);

        printf("\n---------------------------------------\n");
        printf("A rodada terminou. Vamos de novo!\n");
    }

    return 0;
}