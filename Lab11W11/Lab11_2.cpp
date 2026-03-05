#include <stdio.h>

/* prototype */
void mergesort(int t[], int k);
void merge(int *u, int m, int *v, int n, int *t);

/* function merge sort */
void mergesort(int t[], int k) {

    int i;
    int u[50], v[50];
    int m, n;

    if(k > 1) {

        m = k/2;
        n = k - m;

        for(i=0;i<m;i++)
            u[i] = t[i];

        for(i=0;i<n;i++)
            v[i] = t[i+m];

        mergesort(u, m);
        mergesort(v, n);

        merge(u, m, v, n, t);
    }
}

/* function merge */
void merge(int *u, int m, int *v, int n, int *t) {

    int i=0, j=0, k=0;

    while(i<m && j<n) {

        if(u[i] < v[j])
            t[k++] = u[i++];
        else
            t[k++] = v[j++];
    }

    while(i<m)
        t[k++] = u[i++];

    while(j<n)
        t[k++] = v[j++];
}

/* main */
int main() {

    int data[7] = {4,6,1,2,5,1,8};
    int n = 7;

    mergesort(data, n);

    for(int i=0;i<n;i++)
        printf("%d ", data[i]);

    return 0;
}