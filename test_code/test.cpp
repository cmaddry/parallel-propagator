#include <iostream>
#include <omp.h>

int main() {
    const int N = 100000000;
    long long sum = 0;

    double start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += i % 10;
    }

    double end = omp_get_wtime();

    std::cout << "Sum = " << sum << "\n";
    std::cout << "Time = " << (end - start) << " seconds\n";
    std::cout << "Threads used = " << omp_get_max_threads() << "\n";

    return 0;
}