#include "stdio.h"

int main(){
    int arr[100000];
    int n,c;
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++){
        scanf("%d", &c);
        arr[c] = 1;
    }
    int sum = 0;
    for(int i = 1 ; i <= n; i++){
        sum += arr[i];
    }
    int  res = n - sum;
    printf("%d\n", res);
}