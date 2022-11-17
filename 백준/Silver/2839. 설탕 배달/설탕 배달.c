#include <stdio.h>

int main(void){
    int n;
    int fiv;
    int thr = 0;
    scanf("%d",&n);
    fiv = n/5;
    n = n % 5;
    while(fiv >=0){
        if(n % 3 == 0){
            thr = n / 3;
            n = n % 3;
            break;
        }
        fiv --;
        n += 5;
    }
    printf("%d",n==0?fiv+thr:-1);
}
