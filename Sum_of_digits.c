#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=0;i<5;i++){
        ans=ans+n%10;
        n=n/10;
    }
    printf("%d",ans);
    return 0;
}
