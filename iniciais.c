#include <stdio.h>
int main(){
char name[100];
int j;
char initials[20];
int previousSpace;
    fgets(name, 100, stdin);
    previousSpace = 1;
    for (int i = 0; i < 100; i++){
    if (name[i] == '\0'){
        break;
    }
    if (name[i] == ' '){
        previousSpace = 1;
    }
    else
    {
        if (previousSpace == 1){
            initials[j] = name[i];
            j++;
            previousSpace = 0;
        }
    }
}
    initials[j] = '\0';
    printf("%s", initials);
}
