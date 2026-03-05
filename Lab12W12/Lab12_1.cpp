#include <stdio.h>
#include <limits.h>

/* prototype */
int *Dijkstra(int *L, int n);

int main() {

    int n = 5, i = 0, j = 0, *d, *g;

    g = new int[n * n];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100;   g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;    g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;    g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;    g[4 * n + 3] = 10;

    d = Dijkstra(g, n);

    for(i = 0; i < n - 1; i++)
        printf("%d ", d[i]);

    // กัน memory leak แบบนักศึกษา (พอมี)
    delete [] d;
    delete [] g;

    return 0;
}

/* function */
int *Dijkstra(int *L, int n) {

    int *D = new int[n - 1];
    int *dist = new int[n];
    int *used = new int[n];

    int i, w, v;

    // init
    for(i = 0; i < n; i++) {
        dist[i] = INT_MAX/4;   // กัน overflow ตอนบวก
        used[i] = 0;
    }

    dist[0] = 0;   // เริ่มที่ node 0 (เมือง 1 ในสไลด์)

    // ทำซ้ำ n ครั้ง
    for(i = 0; i < n; i++) {

        // หา v ที่ยังไม่ใช้และ dist น้อยที่สุด
        v = -1;
        for(w = 0; w < n; w++) {
            if(!used[w] && (v == -1 || dist[w] < dist[v])) {
                v = w;
            }
        }

        if(v == -1) break;
        used[v] = 1;

        // อัปเดตเพื่อนบ้านของ v
        for(w = 0; w < n; w++) {
            int cost = L[v * n + w];
            if(cost != -1) { // มีเส้นทาง
                if(dist[v] + cost < dist[w]) {
                    dist[w] = dist[v] + cost;
                }
            }
        }
    }

    // คืนค่า D ของ node 1..n-1 (ไม่รวม node 0)
    for(i = 1; i < n; i++)
        D[i - 1] = dist[i];

    delete [] dist;
    delete [] used;

    return D;
}