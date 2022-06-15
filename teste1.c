#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//função que retorna a quantidade de Posições do número digitado pelo usuário
int quantPos(int num){
    int acum=0;
    while(num!=0){
        acum++;
        num/=10;
    }
    return acum;
}

int transformaNum(int vet[], int tamnum){
    float acum = 0;
    for(int i = 1;i<tamnum;i++){
        acum+=(pow(10,i) * vet[i]);
    }
    return acum;
}

int main()
{

    int baseInicial, baseFinal;
    double num,numConv=0,numConvDez=0;
    
    //pergunta do usuário o valor, a base de origem e base final;
    printf("Digite a valor a ser convetido: ");
    scanf("%lf", &num);
    printf("Digite a base de origem: ");
    scanf("%d", &baseInicial);
    printf("Digite a base de destino: ");
    scanf("%d", &baseFinal);
    printf("\n");
    /* como as bases são iguais não haverá mudança no valor do número, 
    logo o número convertido é o mesmo que o informado pelo usuário*/
    //numConv = num; 

    double i = num;
    float acum=0;
    int tamNum = quantPos(i);
    
    //tranforma o valor recebido pelo usuário em um vetor de acordo com suas posições
    //início desse programa
    int numVet[tamNum];
    
    for(int j=tamNum-1;j>=0;j--){
        numVet[j] = i/(int)pow(10,j);
        i-=(numVet[j] * pow(10,j));
    }
    numVet[0] = num - transformaNum(numVet, tamNum); 
    //fim do programa

    
    //tranforma o valor recebido na base de origem para a base 10
    //início desse programa
    for(int i = 0;i < tamNum;i++){
        acum=acum+(pow(baseInicial, i) * numVet[i]);
    } 
    numConvDez = acum;
    //fim desse programa


    double x=0;
    int cont=numConvDez;
    i=0;
    
    while(1){
        x+=((cont % baseFinal) * pow(10,i));
        if(cont/baseFinal<baseFinal){
            x += ((cont/baseFinal)*pow(10,i+1));
            break;
        }
        cont/=baseFinal;
        i++;
    }

    numConv = x;

    printf("O valor na base destino e %0.lf\n", numConv);
    printf("Este valor na base 10 e %0.lf", numConvDez);
    return 0;
}
