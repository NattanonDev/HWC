#include <stdio.h>

/* prototype */
int *KnapsackGreedy(int *w, int *v, int n, int wx);

int main() {

    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x = KnapsackGreedy(w, v, n, wx);

    for(int i = 0; i < n; i++)
        printf("%d", x[i]);

    delete [] x;
    return 0;
}

/* function */
int *KnapsackGreedy(int *w, int *v, int n, int wx) {

    int i, j;
    int *x = new int[n];
    int *idx = new int[n];     // เก็บ index เดิม
    float *ratio = new float[n];

    for(i = 0; i < n; i++) {
        x[i] = 0;
        idx[i] = i;
        ratio[i] = (float)v[i] / (float)w[i];
    }

    /* sort idx ตาม ratio มาก -> น้อย (bubble ง่ายๆ แบบเด็กทำ) */
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(ratio[idx[j]] < ratio[idx[j+1]]) {
                int tmp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = tmp;
            }
        }
    }

    /* เลือกของตามลำดับ greedy */
    for(i = 0; i < n; i++) {
        int k = idx[i];      // item จริง

        if(w[k] <= wx) {
            x[k] = 1;
            wx = wx - w[k];
        }
    }

    delete [] idx;
    delete [] ratio;

    return x;
}