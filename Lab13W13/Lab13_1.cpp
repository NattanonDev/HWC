#include <stdio.h>

/* prototype */
int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {

    int n = 5, wx = 11;
    int w[5] = {1,2,5,6,7};
    int v[5] = {1,6,18,22,28};
    int *x;

    x = KnapsackDP(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    delete [] x;
    return 0;
}

/* function */
int *KnapsackDP(int *w, int *v, int n, int wx) {

    int i, j;

    int **DP = new int*[n+1];
    for(i=0;i<=n;i++)
        DP[i] = new int[wx+1];

    for(i=0;i<=n;i++)
        for(j=0;j<=wx;j++)
            DP[i][j] = 0;

    for(i=1;i<=n;i++){
        for(j=0;j<=wx;j++){

            if(w[i-1] <= j){

                int a = v[i-1] + DP[i-1][j - w[i-1]];
                int b = DP[i-1][j];

                if(a > b)
                    DP[i][j] = a;
                else
                    DP[i][j] = b;
            }
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    int *x = new int[n];
    for(i=0;i<n;i++) x[i]=0;

    j = wx;

    for(i=n;i>0;i--){
        if(DP[i][j] != DP[i-1][j]){
            x[i-1] = 1;
            j = j - w[i-1];
        }
    }

    for(i=0;i<=n;i++)
        delete [] DP[i];
    delete [] DP;

    return x;
}