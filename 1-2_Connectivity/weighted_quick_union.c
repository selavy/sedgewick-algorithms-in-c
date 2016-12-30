#include <stdio.h>

#define N 10000

int main(int argc, char **argv) {
    int i;
    int j;
    int p;
    int q;
    int t;
    int id[N];
    int sz[N]; // size of each set

    // all elements begin in their own set
    for (i = 0; i < N; ++i) {
        id[i] = i;
        sz[i] = 1;
    }

    while (scanf("%d-%d\n", &p, &q) == 2) {
        // Slow Find
        // follows pointers until it gets to the "root" element
        // which is still in its original set.  If both elements
        // end at the same "root" element then they are connected
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;

        // Weighted Quick Union: O(1)
        // connect the smaller set to the larger set to put
        // upper bound on Slow Find algorithm
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("%d-%d\n", p, q);
    }
    return 0;
}
