#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int verificaNum(char num){
    for(int i=48;i<58;i++){
        if(num==i){
            return 1;
        }
    }
    return 0;
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

int main(){

    char num[50];
    int baseInicial = 16;
    double acum=0;
    
    scanf("%s", num);

    for(int i=0;i<strlen(num);i++){
        acum+=((convertaInt(num[i])) * pow(baseInicial,strlen(num)-1-i));

    }

    printf("%0.lf", acum);
   

    

}