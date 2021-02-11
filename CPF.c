#include <stdio.h>

int main()
{
    char cpf[11];
    for (int i = 1; i <= 11; i++){
        scanf("%c", (cpf + i));
    }

    return 0;
}
int numsiguais(int a[11]){
    int cont = 1;
    for(int i = 1; i <=11; i++){
        if(a[i] == a[i+1]){
            cont++;
        }
    }
    return cont >=11;
}
int verificar(char cpf[11]){
    int j;
    int k;
    int nums[11];
    int x;
    int resto;
    for (int i = 1; i <=11; i++){
        if(cpf[i] < '0'|| cpf[i] > '9'){
            printf("Numero invalido");
        return 0;
        }
    nums[i] = cpf[i] - '0';
    }
    if(numsiguais(nums)){
        printf("Nao eh valido");
        return 0;
    }
    for(int i = 1; i<=9; i++){
        x = nums[i] * (10 - i) + x;
    }
        resto = x % 11;
    if (resto == 0 || resto == 1){
        j = 0;
    }else{
        j = 11 - resto;
    }
    if(j!= nums[9]){
        printf("Nao eh valido");
        return 0;
    }
    x = 0;
    for(int i = 1; i<=10; i++){
        x = nums[i] * (11 - i) + x;
    }
    resto = x % 11;
    if (resto == 0 || resto == 1){
        k = 0;
    }else{
        k = 11 - resto;
    }
    if(k!= nums[10]){
        printf("Nao eh valido");
        return 0;
    }
    printf("Eh valido");
}
