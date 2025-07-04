#include<stdio.h> //Biblioteca principal
#include<stdlib.h> //Biblioteca para
#include<stdbool.h> //Biblioteca para vaiável booleana
#include<time.h> //Bibliteca para usar aleatoriedade melhor

int main() {

    //Variáveis de entrada de dados
    int menu, linha1, coluna1, linha2, coluna2, escolhal1, escolhac1, escolhal2, escolhac2;

    //Variáveis de controle
    int pontos1 = 0, pontos2 = 0, vetl1[20] = {0}, vetc1[20] = {0}, vetl2[20] = {0}, vetc2[20] = {0};

    //Matrizes
    int minas1[5][5] = {0}, minas2[5][5] = {0}; //Matrizes que vao gurdadar coordenadas das minas
    char campo1[5][5], campo2[5][5]; //Matrizes que vao mostrar o campo para os jogadores

    //Inicializando os campos com '?'
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            campo1[i][j] = '?';
            campo2[i][j] = '?';
        }
    }

    //Iniciando menu iterativo
    do{
    printf("Qual modo voce deseja escolher?\n");
    printf("1.Humano x Humano\n");
    printf("2.Humano x Computador (Aleatorio)\n");
    printf("3.Computador x Computador (Automatico)\n");
    printf("4.Sair\n");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            //Modo humano x humano
            printf("Voce escolheu o modo humano x humano\n");

            //Jogador 1 escolhendo onde vai colocar as minas
            for (int i = 0; i < 5; i++) {
                int repetido; //Verificaçao de escolha repetida
                do {
                    printf("\nJogador 1: Escolha onde quer por a sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha1, &coluna1);
                    linha1 -= 1;
                    coluna1 -= 1;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl1[j] == linha1 && vetc1[j] == coluna1) {
                            repetido = 1;
                            break;
                        }
                    }
                    //Informando se houve algum erro de digitação para o usuário
                    if (repetido) {
                        printf("Voce ja escolheu isso antes\nTente novamente\n");
                    } else if (linha1 < 0 || linha1 > 4 || coluna1 < 0 || coluna1 > 4) {
                        printf("Coordenadas fora do tabuleiro! Tente novamente.\n");
                    } else {
                        minas1[linha1][coluna1]++; //Coloca valor 1 para o local da mina
                    }

                } while (repetido || linha1 < 0 || linha1 > 4 || coluna1 < 0 || coluna1 > 4);

                //Da esse valores para verificar na próxima
                vetl1[i] = linha1;
                vetc1[i] = coluna1;
            }
            //Imprimindo a matriz com as coordenadas das minas
            printf("\nMatriz minas 1:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("%2d ", minas1[i][j]);
                }
                printf("\n");
            }

            //Jogador 2 escolhendo onde vai colocar as minas
            for (int i = 0; i < 5; i++) {
                int repetido; //Verificaçao de escolha repetida
                do {
                    printf("\nJogador 2: Escolha onde quer por a sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha2, &coluna2);
                    linha2 -= 1;
                    coluna2 -= 1;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                            repetido = 1;
                            break;
                        }
                    }
                    //Informando se houve algum erro de digitação para o usuário
                    if (repetido) {
                        printf("Voce ja escolheu isso antes\nTente novamente\n");
                    } else if (linha2 < 0 || linha2 > 4 || coluna2 < 0 || coluna2 > 4) {
                        printf("Coordenadas fora do tabuleiro! Tente novamente.\n");
                    } else {
                        minas2[linha2][coluna2]++; //Coloca valor 1 para o local da mina
                    }

                } while (repetido || linha2 < 0 || linha2 > 4 || coluna2 < 0 || coluna2 > 4);

                //Da esse valores para verificar na próxima
                vetl2[i] = linha2;
                vetc2[i] = coluna2;
            }

            //ZERANDO TODOS OS VETORES
            for (int i = 0; i < 5; i++) {
                vetc1[i] = 0;
                vetc2[i] = 0;
                vetl1[i] = 0;
                vetl2[i] = 0;
            }

            // Começando o jogo
            printf("COMECANDO JOGO\n");
            for (int i = 0; i < 20; i++) {
                int repetido1 = 0, repetido2 = 0;

                do {
                    // Jogador 1 escolhendo onde vai pisar
                    printf("\nJogador 1: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    //Mostrando o campo 2 ao jogador 1
                    printf("Campo atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo2[l][m]);
                        }
                        printf("\n");
                    }

                    scanf("%d %d", &escolhal1, &escolhac1);
                    escolhal1 -= 1;
                    escolhac1 -= 1;
                    for (int j = 0; j < i; j++) {
                        if (vetl1[j] == escolhal1 || vetc1[j] == escolhac1) {
                            printf("Voce ja escolheu isso antes! Tente novamente");
                            repetido1 = 1;
                        }
                    }

                    if (minas2[escolhal1][escolhac1] == 1) {
                        printf("Voce encontrou uma mina\nPerdeu a jogada");
                        campo2[escolhal1][escolhac1] = '*';
                    } else {
                        if (vetl1[i - 1] == escolhal1 && vetc1[i - 1] == escolhac1) {
                            printf("\nVoce ja escolheu isso antes!\n Tente novamente\n");
                        } else if (escolhal1 > 4 || escolhal1 < 0 || escolhac1 > 4 || escolhac1 < 0) {
                            printf("Coordenada fora do tabuleiro! Tente novamente");
                        } else {
                            printf("Voce acertou!\n (+5 pontos)\n");
                            pontos1 += 1;
                            vetl1[i] = escolhal1;
                            vetc1[i] = escolhac1;
                            campo2[escolhal1][escolhac1] = '.';
                        }
                    }
                } while (repetido1 || escolhal1 > 4 || escolhal1 < 0 || escolhac1 > 4 || escolhac1 < 0);

                do {
                    // Jogador 2 escolhendo onde vai pisar
                    printf("\nJogador 2: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    //Mostrando o campo 1 ao jogador 2
                    printf("Campo Atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo1[l][m]);
                        }
                        printf("\n");
                    }
                    scanf("%d %d", &escolhal2, &escolhac2);
                    escolhal2 -= 1;
                    escolhac2 -= 1;

                    for (int k = 0; k < i; k++) {
                        if (vetl2[k] == escolhal1 || vetc2[k] == escolhac1) {
                            printf("Voce ja escolheu isso antes! Tente novamente");
                            repetido2 = 1;
                        }
                    }

                    if (minas1[escolhal2][escolhac2] == 1) {
                        printf("\nVoce encontrou uma mina\nPerdeu a jogada\n");
                        campo1[escolhal2][escolhac2] = '*';
                    } else {
                        if (vetl2[i - 1] == escolhal2 && vetc2[i - 1] == escolhac2) {
                            printf("\nVoce ja escolheu isso antes!\n Tente novamente\n");
                        } else if (escolhal2 > 4 || escolhal2 < 0 || escolhac2 > 4 || escolhac2 < 0) {
                            printf("Coordenada fora do tabuleiro! Tente novamente");
                        } else {
                            printf("\nVoce acertou!\n(+1 ponto)\n");
                            pontos2 += 1;
                            vetl2[i] = escolhal2;
                            vetc2[i] = escolhac2;
                            campo1[escolhal2][escolhac2] = '.';
                        }
                    }
                } while (repetido2 || escolhal2 > 4 || escolhal2 < 0 || escolhac2 > 4 || escolhac2 < 0);
            }

            //VENDO SE ALGUEM GANHOU OU DEU EMPATE
            if (pontos1 > pontos2) {
                printf("\nJogador 1 venceu!\n");
            } else if (pontos2 > pontos1) {
                printf("\nJogador 2 venceu!\n");
            } else {
                printf("Empate!");
            }
            printf("PONTUACAO FINAL:\nJogador 1: %d pontos\nJogador 2: %d pontos\n", pontos1, pontos2);
            return 0;
            break;
                case 2:
            // MODO: Jogador x Computador
            printf("Voce escolheu modo humano x computador");

            //Jogador 1 escolhendo onde vai colocar as minas
            for (int i = 0; i < 5; i++) {
                int repetido; //Verificaçao de escolha repetida
                do {
                    printf("\nJogador 1: Escolha onde quer por a sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha1, &coluna1);
                    linha1 -= 1;
                    coluna1 -= 1;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl1[j] == linha1 && vetc1[j] == coluna1) {
                            repetido = 1;
                            break;
                        }
                    }
                    //Informando se houve algum erro de digitação para o usuário
                    if (repetido) {
                        printf("Voce ja escolheu isso antes\nTente novamente\n");
                    } else if (linha1 < 0 || linha1 > 4 || coluna1 < 0 || coluna1 > 4) {
                        printf("Coordenadas fora do tabuleiro! Tente novamente.\n");
                    } else {
                        minas1[linha1][coluna1]++; //Coloca valor 1 para o local da mina
                    }

                } while (repetido || linha1 < 0 || linha1 > 4 || coluna1 < 0 || coluna1 > 4);

                vetl1[i] = linha1;
                vetc1[i] = coluna1;
            }

            printf("\nMatriz minas 1:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("%2d ", minas1[i][j]);
                }
                printf("\n");
            }

            //Computador escolhendo coordenadas das minas
            printf("Computador está escolhendo coordenadas das minas...\n");
            for (int i = 0; i < 5; i++) {
                int repetido = 0;
                do {
                    int linha2 = rand() % 5;
                    int coluna2 = rand() % 5;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                            repetido = 1;
                            break;
                        }
                    }
                    if (!repetido) {
                        minas2[linha2][coluna2]++;
                        vetl2[i] = linha2;
                        vetc2[i] = coluna2;
                    }
                } while (repetido);
            }

            printf("\nMatriz CPU:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("%2d ", minas2[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < 5; i++) {
                vetl1[i] = vetc1[i] = vetl2[i] = vetc2[i] = 0;
            }

            for (int i = 0; i < 20; i++) {
                int repetido1 = 0, repetido2 = 0;
                //Começando o jogo (humano x computador)
                do {
                    printf("\nJogador 1: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    printf("Campo atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo2[l][m]);
                        }
                        printf("\n");
                    }
                    scanf("%d %d", &escolhal1, &escolhac1);
                    escolhal1 -= 1;
                    escolhac1 -= 1;
                    
                    for (int j = 0; j < i; j++) {
                        if (vetl1[j] == escolhal1 && vetc1[j] == escolhac1) {
                            printf("Voce ja escolheu isso antes! Tente novamente");
                            repetido1 = 1;
                        }
                    }

                    if (minas2[escolhal1][escolhac1] == 1) {
                        printf("Voce encontrou uma mina\nPerdeu a jogada");
                        campo2[escolhal1][escolhac1] = '*';
                    } else {
                        if (escolhal1 > 4 || escolhal1 < 0 || escolhac1 > 4 || escolhac1 < 0) {
                            printf("Coordenada fora do tabuleiro! Tente novamente");
                        } else {
                            printf("Voce acertou!\n (+5 pontos)\n");
                            pontos1 += 1;
                            vetl1[i] = escolhal1;
                            vetc1[i] = escolhac1;
                            campo2[escolhal1][escolhac1] = '.';
                        }
                    }
                } while (repetido1 || escolhal1 > 4 || escolhal1 < 0 || escolhac1 > 4 || escolhac1 < 0);

                do {
                    printf("\nComputador 2 escolhendo onde vai pisar...\n");
                    printf("Campo Atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo1[l][m]);
                        }
                        printf("\n");
                    }

                    escolhal2 = rand() % 5;
                    escolhac2 = rand() % 5;

                    if (minas1[escolhal2][escolhac2] == 1) {
                        printf("\nComputador 2 encontrou uma mina!\nPerdeu o turno\n");
                        campo1[escolhal2][escolhac2] = '*';
                    } else {
                        for (int j = 0; j < i; j++) {
                            if (vetl2[j] == escolhal2 && vetc2[j] == escolhac2) {
                                repetido2 = 1;
                                break;
                            }
                        }
                        if (!repetido2) {
                            printf("\nComputador 2 acertou!\n(+1 ponto)\n");
                            pontos2 += 1;
                            vetl2[i] = escolhal2;
                            vetc2[i] = escolhac2;
                            campo1[escolhal2][escolhac2] = '.';
                        }
                    }
                } while (repetido2 || escolhal2 < 0 || escolhal2 > 4 || escolhac2 < 0 || escolhac2 > 4);
            }

            if (pontos1 > pontos2) {
                printf("\nJogador 1 venceu!\n");
            } else if (pontos2 > pontos1) {
                printf("\nJogador 2 venceu!\n");
            } else {
                printf("Empate!");
            }
            printf("PONTUACAO FINAL:\nJogador 1: %d pontos\nJogador 2: %d pontos\n", pontos1, pontos2);
            return 0;
            break;
        case 3:
            //MODO: Computador x Computador (Automático)
            printf("Voce escolheu modo automatico");

            printf("Computador está escolhendo coordenadas das minas...\n");
            for (int i = 0; i < 5; i++) {
                int repetido = 0;
                do {
                    int linha1 = rand() % 5;
                    int coluna1 = rand() % 5;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl1[j] == linha1 && vetc1[j] == coluna1) {
                            repetido = 1;
                            break;
                        }
                    }
                    if (!repetido) {
                        minas1[linha1][coluna1]++;
                        vetl1[i] = linha1;
                        vetc1[i] = coluna1;
                    }
                } while (repetido);
            }

            printf("\nMatriz CPU 1:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("%2d ", minas1[i][j]);
                }
                printf("\n");
            }

            printf("Computador está escolhendo coordenadas das minas...\n");
            for (int i = 0; i < 5; i++) {
                int repetido = 0;
                do {
                    int linha2 = rand() % 5;
                    int coluna2 = rand() % 5;
                    repetido = 0;
                    for (int j = 0; j < i; j++) {
                        if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                            repetido = 1;
                            break;
                        }
                    }
                    if (!repetido) {
                        minas2[linha2][coluna2]++;
                        vetl2[i] = linha2;
                        vetc2[i] = coluna2;
                    }
                } while (repetido);
            }

            printf("\nMatriz CPU 2:\n");
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    printf("%2d ", minas2[i][j]);
                }
                printf("\n");
            }

            for (int i = 0; i < 20; i++) {
                int repetido1 = 0, repetido2 = 0;

                do {
                    printf("\nComputador 1 escolhendo onde vai pisar...\n");
                    printf("Campo Atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo2[l][m]);
                        }
                        printf("\n");
                    }

                    escolhal1 = rand() % 5;
                    escolhac1 = rand() % 5;

                    if (minas2[escolhal1][escolhac1] == 1) {
                        printf("\nComputador 1 encontrou uma mina!\nPerdeu o turno\n");
                        campo2[escolhal1][escolhac1] = '*';
                    } else {
                        for (int j = 0; j < i; j++) {
                            if (vetl1[j] == escolhal1 && vetc1[j] == escolhac1) {
                                repetido1 = 1;
                                break;
                            }
                        }
                        if (!repetido1) {
                            printf("\nComputador 1 acertou!\n(+1 ponto)\n");
                            pontos1 += 1;
                            vetl1[i] = escolhal1;
                            vetc1[i] = escolhac1;
                            campo2[escolhal1][escolhac1] = '.';
                        }
                    }
                } while (repetido1);

                do {
                    printf("\nComputador 2 escolhendo onde vai pisar...\n");
                    printf("Campo Atual:\n");
                    for (int l = 0; l < 5; l++) {
                        for (int m = 0; m < 5; m++) {
                            printf("%2c", campo1[l][m]);
                        }
                        printf("\n");
                    }

                    escolhal2 = rand() % 5;
                    escolhac2 = rand() % 5;

                    if (minas1[escolhal2][escolhac2] == 1) {
                        printf("\nComputador 2 encontrou uma mina!\nPerdeu o turno\n");
                        campo1[escolhal2][escolhac2] = '*';
                    } else {
                        for (int j = 0; j < i; j++) {
                            if (vetl2[j] == escolhal2 && vetc2[j] == escolhac2) {
                                repetido2 = 1;
                                break;
                            }
                        }
                        if (!repetido2) {
                            printf("\nComputador 2 acertou!\n(+1 ponto)\n");
                            pontos2 += 1;
                            vetl2[i] = escolhal2;
                            vetc2[i] = escolhac2;
                            campo1[escolhal2][escolhac2] = '.';
                        }
                    }
                } while (repetido2);
            }

            if (pontos1 > pontos2) {
                printf("\nCPU 1 venceu!\n");
            } else if (pontos2 > pontos1) {
                printf("\nCPU 2 venceu!\n");
            } else {
                printf("Empate!");
            }
            printf("PONTUACAO FINAL:\nCPU 1: %d pontos\nCPU 2: %d pontos\n", pontos1, pontos2);
            return 0;
            break;
        case 4:
            printf("SAINDO...");
        default:
            printf("Opcao Invalida!");
        }
    }while(menu < 4 || menu > 4);
}
