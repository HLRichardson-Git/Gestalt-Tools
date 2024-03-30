#include <benchmark/benchmark.h>

// Define the function to be benchmarked
int Add(int a, int b) {
    return a + b;
}

// Define the benchmark function
static void BM_Add(benchmark::State& state) {
    // Perform setup here
    int x = 1;
    int y = 2;
    for (auto _ : state) {
        // This code gets timed
        int result = Add(x, y);
        // Prevent the result from being optimized away
        benchmark::DoNotOptimize(result);
    }
}

// Register the benchmark
BENCHMARK(BM_Add);

// Run the benchmark
BENCHMARK_MAIN();
