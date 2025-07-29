//Programa que faz um jogo de adivinhação com o usuário

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
int main(){
    int cont=0,x;
    bool vitoria=false;
    srand(time(NULL));
    int n=rand() % 101;
      
      printf("Qual numero voce acha que e?\n");
      scanf("%d",&x);
      
      do{
      if(x==n){
      printf("Voce acertou! O numero era:%d\n",n);
      vitoria=true;
      break;
      }
      else if(n > x){
           printf("Errou!\nTentativas restantes:%d Tente um numero maior...\n",5-cont);
           scanf("%d",&x);
           }
      else{
           printf("Errou!\nTentativas restantes:%d Tente um numero menor...\n",5-cont);
           scanf("%d",&x);
           }
      cont++;
       if(cont==5){
      printf("Fim das tentativas! O numero era: %d\n",n);
      }
      }while(cont<5 || vitoria);
    system("Pause");
}
