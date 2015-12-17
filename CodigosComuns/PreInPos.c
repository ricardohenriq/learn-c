#include<stdio.h>
char preOrdem[60],inOrdem[60],posOrdem[60];
int indice;
int cont = -1;
void fazPosOrdem(int auxiliar, int numeroNo){
    int auxiliar2;
    if(auxiliar > numeroNo){
        return;
    }
    for(auxiliar2 = auxiliar;auxiliar2 <= numeroNo; auxiliar2++){
        if(inOrdem[auxiliar2] == preOrdem[indice]){
            break;
        }
    }
    if(auxiliar2 != numeroNo+1){
            indice++;
            fazPosOrdem(auxiliar, auxiliar2-1);
            fazPosOrdem(auxiliar2+1,numeroNo);
            cont++;
            posOrdem[cont]=inOrdem[auxiliar2];
            //printf("%c",posOrdem[cont]);
    }
}

int main(){

    int caso,numeroNo;
    int i;
    scanf("%i",&caso);
    for(i = 0;i < caso; i++){
        scanf("%i %s %s",&numeroNo,preOrdem,inOrdem);
        indice = 0;
        fazPosOrdem(0,numeroNo-1);
        printf("%s",posOrdem);
    }
    return 0;
}
