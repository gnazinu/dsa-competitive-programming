#include "stdio.h"
const long long MOD = 1000000007;
int main(){
    int t;
    int n;
    
    int pares,impares,combPares,combImpares;
    long long sum;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        sum = 0;

        pares = (n - (n % 2)) / 2;
        impares = n - pares;
        
        combImpares = (impares) * (impares-1) / 2;
        sum = ((long long)pares * combImpares ) % MOD ;

        printf("%d\n", sum);
    }
}