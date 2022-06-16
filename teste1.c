#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


//função que retorna a quantidade de Posições do número digitado pelo usuário
int verificaNum(char num){
    for(int i=48;i<58;i++){
        if(num==i){
            return 1;
        }
    }
    return 0;
}

int quantPos(int num){
    int acum=0;
    while(num!=0){
        acum++;
        num/=10;
    }
    return acum;
}

int convertaInt(char num){
    if(verificaNum(num)){
        for(int i=48;i<58;i++){
            if(num==i){
                return i-48;
            }
        }
    }
    else{
        char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i=0;i<6;i++){
            if(num==a[i]){
                return 10+i;
            }
        }
    }
    return 0;
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
    double numConv=0,numConvDez=0;
    char num[50];
    
    //pergunta do usuário o valor, a base de origem e base final;
    printf("Digite a valor a ser convetido: ");
    scanf("%s", num);
    printf("Digite a base de origem: ");
    scanf("%d", &baseInicial);
    printf("Digite a base de destino: ");
    scanf("%d", &baseFinal);
    printf("\n");
    /* como as bases são iguais não haverá mudança no valor do número, 
    logo o número convertido é o mesmo que o informado pelo usuário*/
    //numConv = num; 
    if(baseInicial>10){
        double acum=0;
    
        for(int i=0;i<strlen(num);i++){
            acum+=((convertaInt(num[i])) * pow(baseInicial,strlen(num)-1-i));
        }

        numConvDez=acum;

    }
    else{
        double numConvString=0;
        for(int i=0;i<strlen(num);i++){
            numConvString+=((convertaInt(num[i])) * pow(10,strlen(num)-1-i));
        }
        double i = numConvString;
        float acum=0;
        int tamNum = quantPos(i);
        //tranforma o valor recebido pelo usuário em um vetor de acordo com suas posições
        //início desse programa
        int numVet[tamNum];
        
        for(int j=tamNum-1;j>=0;j--){
            numVet[j] = i/pow(10,j);
            i-=(numVet[j] * pow(10,j));
        }
        numVet[0] = numConvString - transformaNum(numVet, tamNum);
        //fim do programa

        
        //tranforma o valor recebido na base de origem para a base 10
        //início desse programa
        for(int i = 0;i < tamNum;i++){
            acum=acum+(pow(baseInicial, i) * numVet[i]);
        } 
        numConvDez = acum;
        //fim desse programa
    }

    double x=0;
    int cont=numConvDez;
    int i=0;
    
    while(1){
        x+=((cont % baseFinal) * pow(10,i));
        }
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
