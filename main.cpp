#include <iostream>
#include <string>

#include <gestalt/aes.h>

int main()
{
    const std::string key = "10a58869d74be5a374cf867cfb473859";
    std::string pt = "Hello, World!";

    std::cout << "Plaintext: " << pt << std::endl;
    std::string ct = aesEncryptECB(pt, key);
    std::cout << "Ciphertext: " << ct << std::endl;
    std::cout << "Decrypted text: " << aesDecryptECB(ct, key) << std::endl;
 
    return 0;
}