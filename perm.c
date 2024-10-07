// Calculate total permutation based on given words
// https://creativecommons.org/publicdomain/zero/1.0/
#include <stdio.h>
#include <string.h>
#include <time.h>

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char *a, int x, int y) {
    int i;
    if (x == y) {
        printf("%s ", a);
    } else {
        for (i = x; i <= y; i++) {
            swap((a + x), (a + i));
            permute(a, x + 1, y);

            swap((a + x), (a + i));
        }
    }
}

int main(int argc, char *argv[]) {
    
    // Get user's input
    if (argc != 2) {
        printf("Improper input. Exit \n");
        return 1;
    }
    
    char *p = argv[1];
    int n = strlen(p);

    if (n > 10) {
        printf("Please input less than 10 character(s)\n");
        return 1;
    }

    clock_t start_time = clock();
    permute(p, 0, n-1);
    clock_t end_time = clock();
    double time_taken = ((double) end_time - start_time) / CLOCKS_PER_SEC;
    
    unsigned int t = 1;
    for (int i = 1; i <= n; i++) {
        t *= i;
    }
    
    printf("\nTotal permutation of '%s': %u\n", p, t);
    printf("Calculation time(including display): %f seconds\n", time_taken);
    return 0;
}
