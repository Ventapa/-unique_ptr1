#include <iostream>
#include "manage_tokens.h"

int main() {
    ManageTokens manager;

    std::cout << "Minting tokens into wallet1...\n";
    manager.mintToken("FeteerNFT", manager.wallet1);
    manager.mintToken("CerealNFT", manager.wallet1);

    std::cout << "\nTokens in wallet1:\n";
    for (const auto& token : manager.wallet1) {
        std::cout << "Asset: " << token->assetName << ", Hash: " << token->hashValue << "\n";
    }

    std::cout << "\nTransferring first token to wallet2...\n";
    manager.transferToken(0, manager.wallet1, manager.wallet2);

    std::cout << "\nTokens in wallet1:\n";
    for (const auto& token : manager.wallet1) {
        std::cout << "Asset: " << token->assetName << ", Hash: " << token->hashValue << "\n";
    }

    std::cout << "\nTokens in wallet2:\n";
    for (const auto& token : manager.wallet2) {
        std::cout << "Asset: " << token->assetName << ", Hash: " << token->hashValue << "\n";
    }

    std::cout << "\nBenchmarking int vs long int vs bigint:\n";
    benchmark();

    return 0;
}
