#include<stdio.h>
#include<math.h>

int main(){
    int menu1, linha1, coluna1,linha2,coluna2;
    int escolhal1,escolhac1,pontos1=0;
    int minas1[5][5],minas2[5][5],campo[5][5];
    int derrota=0;
    do {
        printf("Qual o modo de jogo?\n");
        printf("1.Humano x Humano\n2.Humano x Computador\n3.Computador x Computador\n4.Sair\n");
        scanf("%d", &menu1);

        switch(menu1){
            case 1:
                printf("VOCE ESCOLHEU HUMANO X HUMANO\n");
                //JOGADOR 1 ESCOLHENDO AS MINAS
                for(int i = 0; i < 5; i++) {
                    printf("\nJogador 1:Escolha onde voce quer por as sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha1, &coluna1);
                    linha1-=1;
                    coluna1-=1;
                    minas1[linha1][coluna1]++;
                    for(int j=0; j < 5; j++) {
                        for(int k=0;k<5;k++){
                        if(minas1[j][k] == minas1[linha1][coluna1]) {
                            minas1[j][k] = 1;
                        } else {
                            minas1[j][k] = 0;
                        }
                        }
                    }
                }
                //IMPRIMINDO A MATRIZ MINAS 1
                printf("\nMatriz minas 1:\n");
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        printf("%d ", minas1[i][j]);
                    }
                    printf("\n");
                }
                //JOGADOR 2 ESCOLHENDO AS MINAS
                for(int i = 0; i < 5; i++) {
                    printf(" Jogador 2:Escolha onde voce quer por as sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha2, &coluna2);
                    linha2-=1;
                    coluna2-=1;
                    minas2[linha2][coluna2]++;
                    for(int j=0; j < 5; j++) {
                        for(int k=0;k<5;k++){
                        if(minas2[j][k] == minas2[linha2][coluna2]) {
                            minas2[j][k] = 1;
                        } else {
                            minas2[j][k] = 0;
                        }
                        }
                    }
                }
                //IMPRIMINDO A MATRIZ MINAS 2
                printf("\nMatriz minas 2:\n");
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        printf("%d ", minas2[i][j]);
                    }
                    printf("\n");
                }

                //COMEÇANDO O JOGO
                for(int i=0;i<5;i++){
                printf("\nJogador 1: Escolha onde voce quer pisar (Linha/Coluna)\n");
                scanf("%d %d",&escolhal1,&escolhac1);
                escolhal1-=1;
                escolhac1-=1;
                campo[escolhal1][escolhac1]=0;
                for(int j=0;j<5;j++){
                    for(int k=0;k<5;k++){
                    if(minas2[j][k]!=campo[escolhal1][escolhac1]){
                        derrota++;
                            }
                        else{
                            pontos1+=5;
                        }
                        }
                    }
                    if(derrota>0){
                    printf("\nVoce encontrou uma mina!\n");
                    break;
                    }
                    else{
                    printf("Voce acertou!\n(+ 5 pontos)");
                    }
                }
                break;
            case 2:
                printf("VOCE ESCOLHEU HUMANO X COMPUTADOR\n");
                break;
            case 3:
                printf("VOCE ESCOLHEU COMPUTADOR X COMPUTADOR\n");
                break;
            case 4:
                printf("SAINDO...");
                break;
            default:
                printf("OPCAO INVALIDA!\n");
        }
    } while(menu1 < 4 || menu1>4);

    return 0;
}