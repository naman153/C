#include <stdio.h>
void swap_add(int a, int b){
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nElement after swapping by using (+,-) operators: A: %d , B: %d",a,b);
}
void swap_mul(int a, int b){
    a=a*b;
    b=a/b;
    a=a/b;
    printf("\nElement after swapping by using (*,/) operators: A: %d , B: %d",a,b);
}
void swap_xor(int a, int b){
    a=a^b;
    b=a^b;
    a=a^b;
    printf("\nElement after swapping by using (^) operators: A: %d , B: %d",a,b);
}

int main()
{
    int a , b;
    printf("Enter element A: ");
    scanf("%d",&a);
    printf("Enter element B: ");
    scanf("%d",&b);
    swap_add(a,b);
    swap_mul(a,b);
    swap_xor(a,b);

    return 0;
}
