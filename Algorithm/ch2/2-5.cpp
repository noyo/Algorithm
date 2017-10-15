#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c,i=0;
    while (scanf("%d%d%d",&a,&b,&c)==3 && a && b && b<=pow(10.0,6.0) && c && c<=100) {

        printf("Case %d: %.*f\n",++i,c,(double)a/b);
    }
    return 0;
}
