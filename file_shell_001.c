#include <stdio.h>
#include <string.h>

void fun_shell(char *vet, int n){

    int gap, i,j;
    char temp;

    for(gap=n/2; gap>0;gap /=2){
        for(i=gap; i<n; i++){
            temp = vet[i];
            for(j=i; j>=gap && vet[j-gap]>temp; j-=gap){
                vet[j]=vet[j-gap];
            }
            vet[j] = temp;
        }
    }
}

int main(){

#define MAX 30

    char vet[MAX] = {"qwertyuiopasdfghjklzxcvbnm"};
    FILE *arquivo;

    arquivo = fopen("desordenado.txt", "w");
    fputs(vet, arquivo);
    fclose(arquivo);

    arquivo = fopen("desordenado.txt", "r");
    fgets(vet, MAX, arquivo);
    arquivo = fopen("ordenado.txt", "w");
    fun_shell(vet, strlen(vet));
    fputs(vet, arquivo);
    fclose(arquivo);


return 0;
}
