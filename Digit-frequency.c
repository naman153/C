#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char num[1000];
    scanf("%s",num);
    int s=strlen(num);
    char result[10];
    for(int i=0;i<10;i++){
        result[i]=0;
    }
    for(int i=0;i<s;i++){
        int x= num[i]-'0';
        if(x>=0 && x<=9){
            result[x]++;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ", result[i]);
    }    
    return 0;
}
