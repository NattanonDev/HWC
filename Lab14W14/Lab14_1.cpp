#include <stdio.h>

/* prototype */
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int best = 0;          // ค่ามากสุดที่เจอ
int y[100];            // เก็บทางเลือกชั่วคราว
int ans[100];          // เก็บคำตอบที่ดีที่สุด

/* main */
int main() {

    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};

    int *x, vx;

    x = new int[n];

    // init
    for(int i=0;i<n;i++){
        x[i] = 0;
        y[i] = 0;
        ans[i] = 0;
    }
    best = 0;

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);
    for(int i = 0; i < n; i++)
        printf("%d ", x[i]);

    delete [] x;
    return 0;
}

/* function */
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {

    // ถ้าพิจารณาครบทุกชิ้นแล้ว -> สรุปค่าของเส้นทางนี้
    if(i == n) {

        int sumV = 0;
        for(int k=0;k<n;k++){
            if(y[k] == 1) sumV += v[k];
        }

        // update ค่าดีที่สุด
        if(sumV > best){
            best = sumV;
            for(int k=0;k<n;k++)
                ans[k] = y[k];
        }
        return best;
    }

    // ทางเลือกที่ 1 : ไม่เลือกชิ้น i
    y[i] = 0;
    KnapsackBT(w, v, n, wx, i+1, x);

    // ทางเลือกที่ 2 : เลือกชิ้น i (ถ้าใส่ได้)
    if(w[i] <= wx){
        y[i] = 1;
        KnapsackBT(w, v, n, wx - w[i], i+1, x);
    }

    // ตอนจบให้คัดลอกคำตอบดีที่สุดออกไปที่ x
    if(i == 0){
        for(int k=0;k<n;k++)
            x[k] = ans[k];
    }

    return best;
}