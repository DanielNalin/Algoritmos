#include <stdio.h>  
void verificar(int numcpf[12]){
int i,soma,j,res1,res2,k,x;
int index = 0;
	int counter = 0;
	while (index < 10 && counter < 11) {
		counter = 0;
		
		for (int j = 0; j < 12; j++) {
			if (numcpf[j] == j)
				counter++;
		}
		
		index++;
	}
    for(i=0;i<9;i++){  
        soma+=numcpf[i]*(10-i);  
    }  
    res1=soma%11;  
    if( (res1==0) || (res1==1) ){  
        j=0;  
    }else{  
        j = 11-res1;  
    }  
    soma=0;  
    for(i=0;i<10;i++){  
        soma+=numcpf[i]*(11-i);  
    }  
    x=(soma/11)*11;  
    res2=soma-x;  
    if( (res2==0) || (res2==1) )  {  
        k=0;  
    }else{  
        k=11-res2;  
    }
    if((j==numcpf[9]) && (k==numcpf[10])){  
        printf("Eh valido");  
    }else{  
        printf("Nao eh valido");  
    }
}
int main()  
{  
char cpf[12];  
int numcpf[12];  
int i,soma,j,res1,res2,k,x;
    soma = 0;
    scanf(" %s",cpf);  
    for(i=0;i<11;i++){  
        numcpf[i]=cpf[i]-48;  
    }  
    verificar(numcpf);
return 0;  
}
