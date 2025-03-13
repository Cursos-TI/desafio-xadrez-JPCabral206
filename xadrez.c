#include <stdio.h>
#include <string.h>

//Funcao para movimentar a torre.
void movimento_torre(){
    char lado[10]; //Variavel para amarzenar a direcao do movimento.
    int vezes; //Variavel para amarmezanar a quantidade de vezes.

    //Pergunta qual lado a torre vai se movimentar para o jogador.
    printf("Qual lado vai ser o movimento da torre? (Direita, Esquerda, baixo e cima)\n");
    scanf("%s", lado);

    printf("Quantas vezes esse movimento vai ser feito? (Max 5)\n");
    scanf("%d", &vezes);

    if (vezes >5){
    printf("Numero de Movimento invalido (Max 5)\n");
    return;
    }

      for (int i =0; i < vezes; i++){
        printf("%d Torre para %s\n", i + 1, lado);
    }
}
//Funcao para movimentar a Bispo.
void movimento_bispo(){

    char lado[15]; //Variavel para amarzenar a direcao do movimento.
    int vezes; //Variavel para amarmezanar a quantidade de vezes.

    //Pergunta qual lado o bispo vai se movimentar para o jogador.
    printf("Qual lado vai ser o movimento do Bispo? (DireitaCima, EsquerdaCima, Direitabaixo e Esquerdacima)\n");
    scanf("%s", lado);

    printf("Quantas vezes esse movimento vai ser feito? (Max 5)\n");
    scanf("%d", &vezes);

    if (vezes >5){
    printf("Numero de Movimento invalido (Max 5)\n");
    return;     
    }

    for (int i = 0; i < vezes; i++){
        printf("%d Bispo para Diagonal %s\n", i + 1, lado);
    }
}

//Funcao para movimentar a Rainha
void movimento_rainha(){
    char lado[15];
    char movimento[15];
    int vezes;

    printf("Movimento para Qual lado Horizontal, Vertical ou Diagonal ?\n");
    scanf("%s", movimento);

        // Verifica o tipo de movimento escolhido.
        if (strcmp(movimento, "Diagonal") == 0) {
            // Se for diagonal, pergunta qual diagonal.
            printf("Movimentar Rainha para qual Diagonal? (DiretaCima, EsquerdaCima, DiretaBaixo, EsquerdaBaixo) \n");
            scanf("%s", lado);
        } else if (strcmp(movimento, "vertical") == 0 || strcmp(movimento, "horizontal") == 0) {
            // Se for vertical ou horizontal, pergunta o lado.
            printf("Movimentar Rainha para qual lado? (Direta, Esquerda, Cima, Baixo) \n");
            scanf("%s", lado);
        } else {
            // Se o movimento for inválido, exibe mensagem e retorna.
            printf("Movimento inválido!!\n");
            return;
        }
    
        // Pergunta quantas vezes a rainha deve se mover.
        printf("movimentar Rainha quantas vezes? (maximo 8 casas) \n");
        scanf("%d", &vezes);
    
        // Verifica se o número de movimentos ultrapassa o limite permitido.
        if (vezes > 8) {
            printf("Numero de vezes excede o máximo permitido (8).\n");
            return;
        }
    
        // Loop para exibir o movimento da rainha.
        for (int i = 0; i < vezes; i++) {
            printf("(%d) rainha para %s %s\n", i + 1, movimento, lado);
        }

}
void movimentar_cavalo() {
    char movimento1[15];  // Movimento principal (duas casas)
    char movimento2[15];  // Movimento secundário (uma casa)
    int opcao;

    printf("Escolha o tipo de movimento do cavalo:\n");
    printf("1 - Duas casas para cima ou para baixo e uma para a esquerda ou direita\n");
    printf("2 - Duas casas para a esquerda ou direita e uma para cima ou para baixo\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Movimentar cavalo para cima ou para baixo?\n");
        scanf("%s", movimento1);

        printf("Movimentar cavalo para direita ou esquerda?\n");
        scanf("%s", movimento2);
    } else if (opcao == 2) {
        printf("Movimentar cavalo para direita ou esquerda?\n");
        scanf("%s", movimento1);

        printf("Movimentar cavalo para cima ou para baixo?\n");
        scanf("%s", movimento2);
    } else {
        printf("Opção inválida! Tente novamente.\n");
        return;
    }

    // Movimento principal (duas casas)
    for (int i = 0; i < 2; i++) {
        printf("Cavalo se movimentou para %s\n", movimento1);
    }

    // Movimento secundário (uma casa)
    printf("Cavalo se movimentou para %s\n", movimento2);
}

int main() { // Função principal do programa.
    int escolha; // Variável para armazenar a escolha do jogador.

//Dando Boas Vindas ao jogador. 
printf("Bem vindo ao Xadrex - Mate Check\n\n");

    // Loop principal que exibe o menu e processa as escolhas do jogador.
    do {
        // Exibe o menu com as opções.
        printf("\n(1) Movimentar  torre\n");
        printf("(2) Movimentar bispo\n");
        printf("(3) Movimentar rainha\n");
        printf("(4) Movimentar Cavalo\n");
        printf("(5) sair do jogo\n");
        scanf("%d", &escolha);

        // Executa a opção escolhida usando switch.
        switch (escolha) {
            case 1:
                movimento_torre(); // Chama a função para movimentar a torre.
                break;
            case 2:
                movimento_bispo(); // Chama a função para movimentar o bispo.
                break;
            case 3:
                movimento_rainha(); // Chama a função para movimentar a rainha.
                break;
            case 4:
            movimentar_cavalo();
                break;
            case 5:
                printf("Adeus. \n"); // Mensagem de saída.
                break;
            default:
                printf("Opção inválida\n"); // Mensagem para opções inválida.
                break;
        }
    } while (escolha != 5); // Repete o menu até que a opção 5 (sair) seja selecionada.

    return 0; // Finaliza o programa.
}