#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
int main(){
    //VARIÁVEIS PARA ENTRADA DE DADOS
    int menu1, linha1, coluna1,linha2,coluna2,escolhal1,escolhac1,escolhal2,escolhac2;
    //VARIÁVEIS DE CONTROLE
    int pontos1=0,pontos2=5,vetl1[20],vetc1[20],vetl2[20],vetc2[20];
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
                    do{
                    printf("\nJogador 1:Escolha onde voce quer por as sua mina %d (Linha/Coluna)\n", i + 1);
                    scanf("%d %d", &linha1, &coluna1);
                    linha1-=1;
                    coluna1-=1;
                    minas1[linha1][coluna1]++;
                    for(int j=0; j < 5; j++) {
                        for(int k=0;k<5;k++){
                        if(minas1[j][k] == minas1[linha1][coluna1]) {
                            minas1[j][k] = 1;
                            vetl1[i]=escolhal1;
                            vetc1[i]=escolhac1;
                        } else {
                            minas1[j][k] = 0;
                        }
                        }
                    }
                    if(vetl1[i-1]==escolhal1&&vetc1[i-1]==escolhac1){
                        printf("\nVoce ja escolheu isso antes!\nTente Novamente\n");
                    }
                    }while(vetl1[i-1]==escolhal1&&vetc1[i-1]==escolhac1);
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
                    for(int i=0;i<20;i++){
                        do{
                            //JOGADOR 1 ESCOLHENDO ONDE VAI PISAR
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
                        if(derrota==true){
                            break;
                        }
                    do{
                        //JOGADOR 2 ESCOLHENDO ONDE VAI PISAR
                    printf("\nJogador 2: Escolha onde voce quer pisar (Linha/Coluna)\n");
                    scanf("%d %d",&escolhal2,&escolhac2);
                    escolhal2-=1;
                    escolhac2-=1;
                            if(minas1[escolhal2][escolhac2]==1){
                            printf("\nVoce encontrou uma mina\n");
                            derrota=true;
                            break;
                            }
                            else{
                                if(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2){
                                    printf("\nVoce ja escolheu isso antes!\n Tente novamente\n");
                                }
                                else{
                                    printf("\nVoce acertou!\n(+5 pontos)\n");
                                    pontos2+=5;
                                    vetl2[i]=escolhal2;
                                    vetc2[i]=escolhac2;
                                }
                            }
                    }while(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2);
                    if(derrota==true){
                            break;
                        }
                    }
                //VENDO SE ALGUEM GANHOU OU DEU EMPATE
                if(pontos1>pontos2){
                    printf("\nJogador 1 venceu!\n");
                }
                else if(pontos2>pontos1){
                    printf("\nJogador 2 venceu!\n");
                }
                else{
                    printf("Empate!");
                }
                printf("\nJogador 1: %d pontos\nJogador 2: %d pontos\n",pontos1,pontos2);
                system("Pause");
                return 0;
                        
            case 2:
                printf("\nVOCE ESCOLHEU HUMANO X COMPUTADOR\n");
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
                 //COMPUTADOR ESCOLHENDO AS MINAS
                 srand(time(NULL));
                 printf(" Computador está escolhendo coordenadas das minas...\n");
                for(int i = 0; i < 5; i++) {
                    int linha2=rand() % 5;
                    int coluna2=rand() % 5;
                    printf("%d\n",linha2);
                    printf("%d\n",coluna2);
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
                //IMPRIMINDO A MATRIZ MINAS CPU
                printf("\nMatriz CPU:\n");
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        printf("%d ", minas2[i][j]);
                    }
                    printf("\n");
                }
                for(int i=0;i<20;i++){
                        do{
                            //JOGADOR 1 ESCOLHENDO ONDE VAI PISAR
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
                        if(derrota==true){
                            break;
                        }
                        //COMPUTADOR ESCOLHENDO ONDE VAI PISAR
                    do{
                    printf("\nComputador escolhendo onde vai pisar...\n");
                    escolhal2= rand() % 5;
                    escolhac2=rand() % 5;
                            if(minas1[escolhal2][escolhac2]==1){
                            printf("\nComputador encontrou uma mina!\nFIM DE JOGO\n");
                            derrota=true;
                            break;
                            }
                            else{
                                printf("\nComputador acertou!\n(+5 pontos)\n");
                                pontos2+=5;
                                vetl2[i]=escolhal2;
                                vetc2[i]=escolhac2;
                                }
                    }while(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2);
                    if(derrota==true){
                            break;
                        }
                    }
                    //DECIDINDO QUEM GANHOU E QUEM PERDEU
                    if(pontos1>pontos2){
                    printf("\nJogador 1 venceu!\n");
                }
                else if(pontos2>pontos1){
                    printf("\nComputador venceu!\n");
                }
                else{
                    printf("Empate!");
                }
                printf("\nPONTUACAO FINAL:\nJogador 1: %d pontos\nComputador: %d pontos\n",pontos1,pontos2);
                system("Pause");
                return 0;
                break;
            case 3:
                printf("VOCE ESCOLHEU COMPUTADOR X COMPUTADOR\n");
                //COMPUTADOR 1 ESCOLHENDO AS MINAS
                 srand(time(NULL));
                 printf(" Computador 1 está escolhendo coordenadas das minas...\n");
                for(int i = 0; i < 5; i++) {
                    int linha1=rand() % 5;
                    int coluna1=rand() % 5;
                    printf("%d\n",linha1);
                    printf("%d\n",coluna1);
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
                //IMPRIMINDO A MATRIZ MINAS CPU 1
                printf("\nMatriz CPU 2:\n");
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        printf("%d ", minas1[i][j]);
                    }
                    printf("\n");
                }
                //COMPUTADOR 2 ESCOLHENDO AS MINAS
                 printf(" Computador está escolhendo coordenadas das minas...\n");
                for(int i = 0; i < 5; i++) {
                    int linha2=rand() % 5;
                    int coluna2=rand() % 5;
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
                //IMPRIMINDO A MATRIZ MINAS CPU 2
                printf("\nMatriz CPU 2:\n");
                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        printf("%d ", minas2[i][j]);
                    }
                    printf("\n");
                }
                for(int i=0;i<20;i++){
                        do{
                        //COMPUTADOR 1 ESCOLHENDO ONDE VAI PISAR
                    printf("\nComputador 1 escolhendo onde vai pisar...\n");
                    escolhal1= rand() % 5;
                    escolhac1=rand() % 5;
                            if(minas2[escolhal1][escolhac1]==1){
                            printf("\nComputador 1 encontrou uma mina!\nFIM DE JOGO\n");
                            derrota=true;
                            break;
                            }
                            else{
                                printf("\nComputador 1 acertou!\n(+5 pontos)\n");
                                pontos1+=5;
                                vetl1[i]=escolhal1;
                                vetc1[i]=escolhac1;
                                }
                    }while(vetl1[i-1]==escolhal1&&vetc1[i-1]==escolhac1);
                    if(derrota==true){
                            break;
                        }
                        //COMPUTADOR 2 ESCOLHENDO ONDE VAI PISAR
                    do{
                    printf("\nComputador 2 escolhendo onde vai pisar...\n");
                    escolhal2= rand() % 5;
                    escolhac2=rand() % 5;
                            if(minas1[escolhal2][escolhac2]==1){
                            printf("\nComputador 2 encontrou uma mina!\nFIM DE JOGO\n");
                            derrota=true;
                            break;
                            }
                            else{
                                printf("\nComputador 2 acertou!\n(+5 pontos)\n");
                                pontos2+=5;
                                vetl2[i]=escolhal2;
                                vetc2[i]=escolhac2;
                                }
                    }while(vetl2[i-1]==escolhal2&&vetc2[i-1]==escolhac2);
                    if(derrota==true){
                            break;
                        }
                    }
                    //DECIDINDO QUEM GANHOU E QUEM PERDEU
                    if(pontos1>pontos2){
                    printf("\nComputador 1 venceu!\n");
                }
                else if(pontos2>pontos1){
                    printf("\nComputador 2 venceu!\n");
                }
                else{
                    printf("Empate!");
                }
                printf("\nPONTUACAO FINAL:\nComputador 1: %d pontos\nComputador 2: %d pontos\n",pontos1,pontos2);
                system("Pause");
                return 0;
                break;
            case 4:
                printf("SAINDO...");
                system("Pause");
                break;
            default:
                printf("OPCAO INVALIDA!\n");
        }
    } while(menu1 < 4 || menu1>4);
    system("Pause");
    return 0;
}
