// manage_tokens.h
#ifndef MANAGE_TOKENS_H
#define MANAGE_TOKENS_H

#include <vector>
#include <memory>
#include <string>
#include <random>

class NfToken {
public:
    std::string assetName;
    std::string hashValue;

    NfToken(const std::string& name);
    static std::string generateHash(const std::string& input);
};

class ManageTokens {
public:
    std::vector<std::unique_ptr<NfToken>> wallet1;
    std::vector<std::unique_ptr<NfToken>> wallet2;

    void mintToken(const std::string& name, std::vector<std::unique_ptr<NfToken>>& wallet);
    void transferToken(size_t index, std::vector<std::unique_ptr<NfToken>>& from, std::vector<std::unique_ptr<NfToken>>& to);
};

void benchmark();  // Forward declaration

#endif
