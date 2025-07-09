#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

int main() {
	SetConsoleOutputCP(CP_UTF8); // Define saída para UTF-8
    SetConsoleCP(CP_UTF8);       // Define entrada para UTF-8
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    
    system("cls"); 
    printf(" $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$\\   $$$$$$\\          \n");
    printf("$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  __$$\\ $$  __$$\\         \n");
    printf("$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ /  $$ |        \n");
    printf("$$ |      $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$$$  |$$ |  $$ |        \n");
    printf("$$ |      $$  __$$ |$$ \\$$$  $$ |$$  ____/ $$ |  $$ |        \n");
    printf("$$ |  $$\\ $$ |  $$ |$$ |\\$  /$$ |$$ |      $$ |  $$ |        \n");
    printf("\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$ |       $$$$$$  |        \n");
    printf(" \\______/ \\__|  \\__|\\__|     \\__|\\__|       \\______/         \n");
    printf("                                                             \n");
    printf("                                                             \n");
    printf("                                                             \n");
    printf("$$\\      $$\\ $$$$$$\\ $$\\   $$\\  $$$$$$\\  $$$$$$$\\   $$$$$$\\  \n");
    printf("$$$\\    $$$ |\\_$$  _|$$$\\  $$ |$$  __$$\\ $$  __$$\\ $$  __$$\\ \n");
    printf("$$$$\\  $$$$ |  $$ |  $$$$\\ $$ |$$ /  $$ |$$ |  $$ |$$ /  $$ |\n");
    printf("$$\\$$\\$$ $$ |  $$ |  $$ $$\\$$ |$$$$$$$$ |$$ |  $$ |$$ |  $$ |\n");
    printf("$$ \\$$$  $$ |  $$ |  $$ \\$$$$ |$$  __$$ |$$ |  $$ |$$ |  $$ |\n");
    printf("$$ |\\$  /$$ |  $$ |  $$ |\\$$$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n");
    printf("$$ | \\_/ $$ |$$$$$$\\ $$ | \\$$ |$$ |  $$ |$$$$$$$  | $$$$$$  |\n");
    printf("\\__|     \\__|\\______|\\__|  \\__|\\__|  \\__|\\_______/  \\______/ \n");
    printf("                                                             \n");
    printf("                                                             \n");

    system("pause");
    
    srand(time(NULL)); 
    int menu;
    int i, j;
    int linha1, coluna1, linha2, coluna2;
    int escolhal1, escolhac1, escolhal2, escolhac2;
    int repetido, repetido1, repetido2;
    int jogadas, pontos1, pontos2;
    int minas1[5][5], minas2[5][5];
    char campo1[5][5], campo2[5][5];
    int vetl1[50], vetc1[50], vetl2[50], vetc2[50];

    do {
        system("cls");
        printf("\nQual modo deseja escolher?\n");
        printf("\n");
        printf("1. Humano x Humano\n");
        printf("2. Humano x Computador\n");
        printf("3. Computador x Computador\n");
        printf("4. Sair\n");
        printf("\n");
        printf("Escolha: ");
        scanf("%d", &menu);

        // Inicializa estruturas
        pontos1 = pontos2 = jogadas = 0;
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                campo1[i][j] = '#';
                campo2[i][j] = '#';
                minas1[i][j] = 0;
                minas2[i][j] = 0;
            }
        }

        if (menu == 1 || menu == 2) {
            // Colocação de minas
            printf("\nJogador 1 - Escolha as 5 minas:\n");
            for (i = 0; i < 5; i++) {
                do {
                    printf("Mina %d (linha coluna): ", i + 1);
                    scanf("%d %d", &linha1, &coluna1);
                    linha1--; coluna1--;
                    repetido = 0;

                    if (linha1 < 0 || linha1 > 4 || coluna1 < 0 || coluna1 > 4) {
                        printf("Coordenada fora do tabuleiro. Tente novamente.\n");
                        repetido = 1;
                        continue;
                    }
                    for (j = 0; j < i; j++) {
                        if (vetl1[j] == linha1 && vetc1[j] == coluna1) {
                            printf("Coordenada já usada. Tente novamente.\n");
                            repetido = 1;
                            break;
                        }
                    }
                } while (repetido);
                minas1[linha1][coluna1] = 1;
                vetl1[i] = linha1;
                vetc1[i] = coluna1;
            }

            if (menu == 1) {
                printf("\nJogador 2 - Escolha as 5 minas:\n");
                for (i = 0; i < 5; i++) {
                    do {
                        printf("Mina %d (linha coluna): ", i + 1);
                        scanf("%d %d", &linha2, &coluna2);
                        linha2--; coluna2--;
                        repetido = 0;

                        if (linha2 < 0 || linha2 > 4 || coluna2 < 0 || coluna2 > 4) {
                            printf("Coordenada fora do tabuleiro. Tente novamente.\n");
                            repetido = 1;
                            continue;
                        }
                        for (j = 0; j < i; j++) {
                            if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                                printf("Coordenada já usada. Tente novamente.\n");
                                repetido = 1;
                                break;
                            }
                        }
                    } while (repetido);
                    minas2[linha2][coluna2] = 1;
                    vetl2[i] = linha2;
                    vetc2[i] = coluna2;
                }
            } else {
                // Colocação automática
                printf("Computador está escolhendo as minas...\n");
                for (i = 0; i < 5; i++) {
                    do {
                        linha2 = rand() % 5;
                        coluna2 = rand() % 5;
                        repetido = 0;
                        for (j = 0; j < i; j++) {
                            if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                                repetido = 1;
                                break;
                            }
                        }
                    } while (repetido);
                    minas2[linha2][coluna2] = 1;
                    vetl2[i] = linha2;
                    vetc2[i] = coluna2;
                }
            }

            // Resetar jogadas
            for (i = 0; i < 50; i++) {
                vetl1[i] = vetc1[i] = vetl2[i] = vetc2[i] = -1;
            }

            jogadas = 0;

            while (jogadas < 20) {
                // Jogador humano
                do {
                    system("cls");
                    printf("\nJogador 1, sua vez\n");
                    printf("Campo do inimigo:\n");
                    for (i = 0; i < 5; i++) {
                        for (j = 0; j < 5; j++) printf("%2c", campo2[i][j]);
                        printf("\n");
                    }
                    printf("Digite linha e coluna para pisar: ");
                    scanf("%d %d", &escolhal1, &escolhac1);
                    escolhal1--; escolhac1--;
                    repetido1 = 0;
                    if (escolhal1 < 0 || escolhal1 > 4 || escolhac1 < 0 || escolhac1 > 4) {
                        printf("Coordenada inválida!\n");
                        system("pause");
                        continue;
                    }
                    for (i = 0; i < jogadas; i++) {
                        if (vetl1[i] == escolhal1 && vetc1[i] == escolhac1) {
                            printf("Você já jogou aí!\n");
                            repetido1 = 1;
                            system("pause");
                            break;
                        }
                    }
                } while (repetido1);

                vetl1[jogadas] = escolhal1;
                vetc1[jogadas] = escolhac1;

                if (minas2[escolhal1][escolhac1]) {
                    campo2[escolhal1][escolhac1] = '*';
                    system("cls");
                    printf("Pisou numa mina!\n");
                    for (i = 0; i < 5; i++) {
                        for (j = 0; j < 5; j++) printf("%2c", campo2[i][j]);
                        printf("\n");
                    }
                } else {
                    campo2[escolhal1][escolhac1] = '.';
                    pontos1++;
                    system("cls");
                    printf("Acertou! +1 ponto.\n");
                    for (i = 0; i < 5; i++) {
                        for (j = 0; j < 5; j++) printf("%2c", campo2[i][j]);
                        printf("\n");
                    }
                }
                system("pause");

                jogadas++;
                if (jogadas >= 20) break;

                // Jogador 2 ou Computador
                if (menu == 1) {
                    do {
                        system("cls");
                        printf("\nJogador 2, sua vez\n");
                        printf("Campo do inimigo:\n");
                        for (i = 0; i < 5; i++) {
                            for (j = 0; j < 5; j++) printf("%2c", campo1[i][j]);
                            printf("\n");
                        }
                        printf("Digite linha e coluna para pisar: ");
                        scanf("%d %d", &escolhal2, &escolhac2);
                        escolhal2--; escolhac2--;
                        repetido2 = 0;
                        if (escolhal2 < 0 || escolhal2 > 4 || escolhac2 < 0 || escolhac2 > 4) {
                            printf("Coordenada inválida!\n");
                            system("pause");
                            continue;
                        }
                        for (i = 0; i < jogadas; i++) {
                            if (vetl2[i] == escolhal2 && vetc2[i] == escolhac2) {
                                printf("Jogada repetida!\n");
                                repetido2 = 1;
                                system("pause");
                                break;
                            }
                        }
                    } while (repetido2);
                } else {
                    do {
                        escolhal2 = rand() % 5;
                        escolhac2 = rand() % 5;
                        repetido2 = 0;
                        for (i = 0; i < jogadas; i++) {
                            if (vetl2[i] == escolhal2 && vetc2[i] == escolhac2) {
                                repetido2 = 1;
                                break;
                            }
                        }
                    } while (repetido2);
                    printf("Computador jogou em [%d, %d]\n", escolhal2 + 1, escolhac2 + 1);
                }

                vetl2[jogadas] = escolhal2;
                vetc2[jogadas] = escolhac2;

                if (minas1[escolhal2][escolhac2]) {
                    campo1[escolhal2][escolhac2] = '*';
                    system("cls");
                    printf("Mina! Jogador 2/Computador errou.\n");
                    for (i = 0; i < 5; i++) {
                        for (j = 0; j < 5; j++) printf("%2c", campo2[i][j]);
                        printf("\n");
                    }
                    
                } else {
                    campo1[escolhal2][escolhac2] = '.';
                    pontos2++;
                    system("cls");
                    printf("Jogador 2/Computador acertou! +1 ponto.\n");
                    for (i = 0; i < 5; i++) {
                        for (j = 0; j < 5; j++) printf("%2c", campo2[i][j]);
                        printf("\n");
                    }
                }
                system("pause");
                jogadas++;
            }

            system("cls");
            printf("Fim do jogo!\nPontuação:\n");
            printf("Jogador 1: %d\n", pontos1);
            printf("Jogador 2/Computador: %d\n", pontos2);
            if (pontos1 > pontos2) printf("Jogador 1 venceu!\n");
            else if (pontos2 > pontos1) printf("Jogador 2/Computador venceu!\n");
            else printf("Empate!\n");
            system("pause");

        } else if (menu == 3) {
            printf("Modo Computador x Computador.\n");
    // Colocar minas aleatórias para os dois
    for (i = 0; i < 5; i++) {
        do {
            linha1 = rand() % 5;
            coluna1 = rand() % 5;
            repetido = 0;
            for (j = 0; j < i; j++) {
                if (vetl1[j] == linha1 && vetc1[j] == coluna1) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);
        minas1[linha1][coluna1] = 1;
        vetl1[i] = linha1;
        vetc1[i] = coluna1;
    }

    for (i = 0; i < 5; i++) {
        do {
            linha2 = rand() % 5;
            coluna2 = rand() % 5;
            repetido = 0;
            for (j = 0; j < i; j++) {
                if (vetl2[j] == linha2 && vetc2[j] == coluna2) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);
        minas2[linha2][coluna2] = 1;
        vetl2[i] = linha2;
        vetc2[i] = coluna2;
    }

    // Reset jogadas
    for (i = 0; i < 50; i++) {
        vetl1[i] = vetc1[i] = vetl2[i] = vetc2[i] = -1;
    }

    jogadas = 0;
    pontos1 = 0;
    pontos2 = 0;

    while (jogadas < 20) {
        // Computador 1 joga
        do {
            escolhal1 = rand() % 5;
            escolhac1 = rand() % 5;
            repetido1 = 0;
            for (i = 0; i < jogadas; i++) {
                if (vetl1[i] == escolhal1 && vetc1[i] == escolhac1) {
                    repetido1 = 1;
                    break;
                }
            }
        } while (repetido1);

        vetl1[jogadas] = escolhal1;
        vetc1[jogadas] = escolhac1;

        printf("Computador 1 jogou em [%d, %d] -> ", escolhal1 + 1, escolhac1 + 1);
        if (minas2[escolhal1][escolhac1] == 1) {
            printf("ERROU (mina)!\n");
            campo2[escolhal1][escolhac1] = '*';
        } else {
            printf("ACERTOU! +1 ponto\n");
            campo2[escolhal1][escolhac1] = '.';
            pontos1++;
        }
        jogadas++;
        if (jogadas >= 20) break;

        // Computador 2 joga
        do {
            escolhal2 = rand() % 5;
            escolhac2 = rand() % 5;
            repetido2 = 0;
            for (i = 0; i < jogadas; i++) {
                if (vetl2[i] == escolhal2 && vetc2[i] == escolhac2) {
                    repetido2 = 1;
                    break;
                }
            }
        } while (repetido2);

        vetl2[jogadas] = escolhal2;
        vetc2[jogadas] = escolhac2;

        printf("Computador 2 jogou em [%d, %d] -> ", escolhal2 + 1, escolhac2 + 1);
        if (minas1[escolhal2][escolhac2] == 1) {
            printf("ERROU (mina)!\n");
            campo1[escolhal2][escolhac2] = '*';
        } else {
            printf("ACERTOU! +1 ponto\n");
            campo1[escolhal2][escolhac2] = '.';
            pontos2++;
        }

        jogadas++;
        system("pause");
    }

    system("cls");
    printf("Fim do jogo (Computador x Computador)\n");
    printf("Computador 1: %d pontos\n", pontos1);
    printf("Computador 2: %d pontos\n", pontos2);

    if (pontos1 > pontos2)
        printf("Computador 1 venceu!\n");
    else if (pontos2 > pontos1)
        printf("Computador 2 venceu!\n");
    else
        printf("Empate!\n");

    system("pause");

        } else if (menu == 4) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida.\n");
            system("pause");
        }

    } while (menu != 4);

    return 0;
}
