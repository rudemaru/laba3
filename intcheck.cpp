#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ten_int(int a, int n){
    for(int i = 0; i < n - 1; i++){
        a *= 10;
    }
    return a;
}

int intcheck(){
    setlocale(LC_ALL, "RUS");
    int Cel = 0, SUMint;
    int minus = 0, index_int = 0;
    char input_int[100];
    //printf("Input: ");
    fgets(input_int, 100, stdin);

    if(input_int[0] == '\0' || input_int[0] == '\n'){
        printf("Input error!\n");
        return intcheck();
    }

    if(input_int[0] == '.' || input_int[0] == ','){
        printf("Input error!\n");
        return intcheck();
    }

    for(int j = 0; j < 2; j++){
        if(input_int[0]=='-'){
        minus++;
        for(int i = 1; i < 100; i++){
            input_int[i-1] = input_int[i];
        }
    }
    }

    if(minus>0){
        printf("Input error!\n");
        return(intcheck());
    }   

    index_int = 0;

    while(input_int[index_int]!='\n' && input_int[index_int]!='\0'){
        if(input_int[index_int] > '9' || input_int[index_int] < '0'){
            printf("Input error!\n");
            return intcheck();
        }
        index_int++;
    }

    int porCelint = index_int;
    if(porCelint > 10){
        printf("Input error!\n");
        rewind(stdin);
        return intcheck();
    }

    for(int i = 0; i < porCelint; i++){
        Cel += ten_int(input_int[i] - '0', porCelint - i);
    }

    SUMint = Cel;
    if(minus == 1){
        SUMint *= -1;
    }
    
    return SUMint;
}