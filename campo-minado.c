#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
    //VARIÁVEIS PARA ENTRADA DE DADOS
    int menu1, linha1, coluna1,linha2,coluna2,escolhal1,escolhac1,escolhal2,escolhac2;
    //VARIÁVEIS DE CONTROLE
    int pontos1=0,pontos2=0,cont=1,vetl1[20],vetc1[20],vetl2[20],vetc2[20],n1=20,n2=20;
    //MATRIZES
    int minas1[5][5],minas2[5][5];
    //VARIÁVEL BOOLEANA
    bool derrota=false;

    //ZERANDO TODAS AS MATRIZES E VETORES
        for(int i=0;i<5;i++){
            for(int j=0; j<5;j++){
            minas1[i][j]=0;
            minas2[i][j]=0;
            }
        }
        for(int i=0;i<20;i++){
            vetl1[i]=0;
            vetc1[i]=0;
            vetl2[i]=0;
            vetc2[i]=0;
        }
        
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
                    printf(" Jogador 2:Escolha onde voce quer por a sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d",&linha2,&coluna2);
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
                //EM DESENVOLVIMENTO
                    for(int i=0;i<20;i++){
                        do{
                    printf("\nJogador 1: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    scanf("%d %d",&escolhal1,&escolhac1);
                    escolhal1-=1;
                    escolhac1-=1;
                            if(minas2[escolhal1][escolhac1]==1){
                            printf("Voce encontrou uma mina\n");
                            derrota=true;
                            break;
                            }
                            else{
                                if(vetl1[i-1]==escolhal1&&vetc1[i-1]==escolhac1){
                                    printf("\nVoce ja escolheu isso antes!\n Tente novamente\n");
                                }
                                else{
                                    printf("Voce acertou!\n (+5 pontos)\n");
                                    pontos1+=5;
                                    vetl1[i]=escolhal1;
                                    vetc1[i]=escolhac1;
                                    }
                            }
                        }while(vetl1[i-1]==escolhal1&&vetc1[i-1]==escolhac1);
                    do{
                    printf("\nJogador 2: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    scanf("%d %d",&escolhal2,&escolhac2);
                    escolhal2-=1;
                    escolhac2-=1;
                            if(minas1[escolhal2][escolhac2]==1){
                            printf("Voce encontrou uma mina\n");
                            derrota=true;
                            break;
                            }
                            else{
                                if(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2){
                                    printf("\nVoce ja escolheu isso antes!\n Tente novamente\n");
                                }
                                else{
                                    printf("Voce acertou!\n (+5 pontos)\n");
                                    pontos2+=5;
                                    vetl2[i]=escolhal2;
                                    vetc2[i]=escolhac2;
                                }
                            }
                    }while(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2);
                    }
                        
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
    system("Pause");
    return 0;
}
