#include <benchmark/benchmark.h>
#include <gestalt/ecdsa.h> // Include your ECDSA implementation header

static void BM_ECDSA_Signature(benchmark::State& state) {
    ECDSA ecdsa(StandardCurve::secp256k1);

    KeyPair keyPair = {{"5844747745739988917638281854633664105197999881451444700670129218777985873582",
                        "108534668176366933332951134464297919708693135604831156472843095507119755132861"},
                        "36911659202040455512047859400253132650624032136469391266733306307680092206180"};

    const InfInt k = "67228059374187986264907871817984995299114694677537144137068659840319595636958";
    std::string message = "4c24c2225c70900f85f97d6ff7936f1dca59e8283f1a1a8872c981b98a0ee53a";

    for (auto _ : state) {
        Signature signature = ecdsa.signMessage(message, keyPair, k);
        benchmark::DoNotOptimize(signature);
    }
}

static void BM_ECDSA_VerifySignature(benchmark::State& state) {
    ECDSA ecdsa(StandardCurve::secp256k1);

    KeyPair keyPair = {{"5844747745739988917638281854633664105197999881451444700670129218777985873582",
                        "108534668176366933332951134464297919708693135604831156472843095507119755132861"},
                        "36911659202040455512047859400253132650624032136469391266733306307680092206180"};

    const InfInt k = "67228059374187986264907871817984995299114694677537144137068659840319595636958";
    std::string message = "4c24c2225c70900f85f97d6ff7936f1dca59e8283f1a1a8872c981b98a0ee53a";

    Signature signature = ecdsa.signMessage(message, keyPair, k);

    for (auto _ : state) {
        bool verify = ecdsa.verifySignature(message, signature, keyPair.publicKey);
        benchmark::DoNotOptimize(verify);
    }
}

static void BM_ECDSA_GenerateKey(benchmark::State& state) {
    ECDSA ecdsa(StandardCurve::secp256k1);

    for (auto _ : state) {
        KeyPair keyPair = ecdsa.generateKeyPair();
        benchmark::DoNotOptimize(keyPair);
    }
}

// Register the benchmarks
BENCHMARK(BM_ECDSA_Signature)->Iterations(20);
BENCHMARK(BM_ECDSA_VerifySignature)->Iterations(20);
BENCHMARK(BM_ECDSA_GenerateKey)->Iterations(20);

// Run the benchmark
BENCHMARK_MAIN();
