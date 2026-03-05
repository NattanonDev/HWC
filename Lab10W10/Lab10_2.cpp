#include <stdio.h>

/* prototype */
void TowerHanoi(int m, int i, int j);

/* main */
int main() {

    TowerHanoi(3, 1, 3);

    return 0;
}

/* function */
void TowerHanoi(int m, int i, int j) {

    int k;

    if(m == 1) {
        printf("Disc %d from %d to %d\n", m, i, j);
    }
    else {
        k = 6 - i - j;        // หาเสาพัก

        TowerHanoi(m-1, i, k);

        printf("Disc %d from %d to %d\n", m, i, j);

        TowerHanoi(m-1, k, j);
    }

}