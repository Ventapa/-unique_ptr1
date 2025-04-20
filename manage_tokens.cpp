#include "manage_tokens.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <random>
#include <gmpxx.h>

NfToken::NfToken(const std::string& name) : assetName(name) {
    hashValue = generateHash(name + std::to_string(std::chrono::system_clock::now().time_since_epoch().count()));
}

// Fake hash generator – generates a 64-character hexadecimal string
std::string NfToken::generateHash(const std::string& input) {
    std::mt19937 rng(std::hash<std::string>{}(input));
    std::stringstream ss;
    for (int i = 0; i < 64; ++i) {
        ss << std::hex << ((rng() % 16));
    }
    return ss.str();
}

void ManageTokens::mintToken(const std::string& name, std::vector<std::unique_ptr<NfToken>>& wallet) {
    wallet.push_back(std::unique_ptr<NfToken>(new NfToken(name)));
}

void ManageTokens::transferToken(size_t index, std::vector<std::unique_ptr<NfToken>>& from, std::vector<std::unique_ptr<NfToken>>& to) {
    if (index < from.size()) {
        to.push_back(std::move(from[index]));
        from.erase(from.begin() + index);
    }
}

void benchmark() {
    const int iterations = 100000;

    auto start = std::chrono::high_resolution_clock::now();
    int a = 0;
    for (int i = 0; i < iterations; ++i) a += i;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "int: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";

    start = std::chrono::high_resolution_clock::now();
    long int b = 0;
    for (int i = 0; i < iterations; ++i) b += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "long int: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";

    start = std::chrono::high_resolution_clock::now();
    mpz_class c = 0;
    for (int i = 0; i < iterations; ++i) c += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "bigint: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";
}
