#include <stdio.h>
#include <time.h>

int main(void) {
    double x = 0.5;
    unsigned long long Ns[] = {
        1000000000,
        2000000000,
        5000000000,
        10000000000,
        20000000000
    };
    int nN = sizeof(Ns) / sizeof(Ns[0]);

    for (int j = 0; j < nN; ++j) {
        unsigned long long N = Ns[j];
        struct timespec start, end;
        double s = 0.0, t = x;

        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        for (size_t i = 1; i <= N; ++i) {
            s += t / (double)i;
            t *= -x;
        }
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        double tm = (end.tv_sec - start.tv_sec) + 1e-9 * (end.tv_nsec - start.tv_nsec);

        printf("N = %llu   time = %.15f\n", N, tm);
    }

    return 0;
}
