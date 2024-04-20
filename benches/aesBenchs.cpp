#include <benchmark/benchmark.h>
#include <string>
#include <gestalt/aes.h> // Include the AES implementation header

// Define the benchmark function
static void BM_AESEncryptECB(benchmark::State& state) {
    // Perform setup here
    const std::string key = "10a58869d74be5a374cf867cfb473859";
    std::string pt;
    pt.resize(state.range(0), 'A');

    std::string ct;

    for (auto _ : state) {
        // This code gets timed
        ct = aesEncryptECB(pt, key);
        // Prevent the result from being optimized away
        benchmark::DoNotOptimize(ct);
    }
}

// Register the benchmark
BENCHMARK(BM_AESEncryptECB)->Range(128, 8192);

// Run the benchmark
//BENCHMARK_MAIN();
