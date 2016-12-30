#include <stdio.h>

#define N 10000

int main(int argc, char **argv) {
    int i;
    int j;
    int p;
    int q;
    int t;
    int id[N];

    // all elements begin in their own set
    for (i = 0; i < N; ++i) {
        id[i] = i;
    }

    while (scanf("%d-%d\n", &p, &q) == 2) {
        // Slow Find
        // follows pointers until it gets to the "root" element
        // which is still in its original set.  If both elements
        // end at the same "root" element then they are connected
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;

        // Quick Union: O(1)
        id[i] = j;
        printf("%d-%d\n", p, q);
    }
    return 0;
}
