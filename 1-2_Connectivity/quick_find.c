#include <stdio.h>

#define N 10000

int main(int argc, char **argv) {
    int i;
    int p;
    int q;
    int t;
    int id[N];

    // all elements begin in their own set
    for (i = 0; i < N; ++i) {
        id[i] = i;
    }

    while (scanf("%d-%d\n", &p, &q) == 2) {
        // QuickFind:
        // if equal then they are in the same set
        if (id[p] == id[q]) {
            continue;
        }


        // Slow Union:
        t = id[p]; // name of set that `p' is in
        for (i = 0; i < N; ++i) {
            // if `i' was in set t, put it in the same
            // set as `q'
            if (id[i] == t) {
                id[i] = id[q];
            }
        }

        printf("%d-%d\n", p, q);
    }
    return 0;
}
