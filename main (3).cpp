#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int mode;
    int cipherType;
    string vigenereTable[26][26];
    string word;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> v;
    string key;
    bool running = true;
    int shift;
    while (running) {
        cout << "Select mode:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
        cin >> mode;
        if (mode == 3) {
            running = false;
            break;
        }
        cout << "Select cipher:\n1. Caesar\n2. Vigenere\n3. Atbash\n4. XOR\n";
        cin >> cipherType;
        cin.ignore();
        switch (mode) {
            case 1: // Encryption
                switch (cipherType) {// Caesar
                    case 1: { 
                        cout << "Enter shift:\n";
                        cin >> shift;
                        cin.ignore();
                        cout << "Enter text (uppercase letters only):\n";
                        getline(cin, word);
                        for (int i = 0; i < word.length(); i++) {
                            for (int j = 0; j < 26; j++) {
                                if (word[i] == alphabet[j]) {
                                    word[i] = alphabet[(j + shift) % 26];
                                    break;
                                }
                            }
                        }
                        cout << "Encrypted text: " << word << endl;
                        break;
                    }
                    case 2: { // Vigenere
                        for (int i = 0; i < 26; i++) {
                            for (int j = 0; j < 26; j++) {
                                vigenereTable[i][j] = alphabet[(j + i) % 26];
                            }
                        }
                        cout << "Enter text (uppercase letters only):\n";
                        getline(cin, word);
                        cout << "Enter key:\n";
                        cin >> key;
                        int keyPos = 0;
                        for (int i = 0; i < word.length(); i++) {
                            if (word[i] == ' ') continue;
                            int textIndex = word[i] - 'A';
                            char keyChar = key[keyPos % key.length()];
                            int keyIndex = keyChar - 'A';
                            word[i] = vigenereTable[keyIndex][textIndex][0];
                            keyPos++;
                        }
                        cout << "Encrypted text: " << word << endl;
                        break;
                    }
                    case 3: { // Atbash
                        cout << "Enter text (uppercase letters only):\n";
                        getline(cin, word);
                        for (int i = 0; i < word.length(); i++) {
                            for (int j = 0; j < 26; j++) {
                                if (word[i] == alphabet[j]) {
                                    word[i] = alphabet[25 - j];
                                    break;
                                }
                            }
                        }
                        cout << "Encrypted text: " << word << endl;
                        break;
                    }
                    case 4: { // XOR
                        cout << "Enter key:\n";
                        cin >> key;
                        cin.ignore();
                        cout << "Enter text (uppercase letters only):\n";
                        getline(cin, word);
                        for (int i = 0; i < word.length(); i++) {
                            word[i] = word[i] ^ key[i % key.length()];
                        }
                        cout << "Encrypted text (in hex): ";
                        for (char c : word) {
                            cout << hex << setw(2) << setfill('0') << (int)(unsigned char)c << " ";
                        }
                        cout << endl;
                        break;
                    }
                    default:
                        cout << "Invalid cipher selection.\n";
                        break;
                }
                break;
            case 2: // Decryption
                switch (cipherType) {
                    case 1: { // Caesar
                        cout << "Enter shift:\n";
                        cin >> shift;
                        cin.ignore();
                        cout << "Enter encrypted text (uppercase letters only):\n";
                        getline(cin, word);
                        for (int i = 0; i < word.length(); i++) {
                            for (int j = 0; j < 26; j++) {
                                if (word[i] == alphabet[j]) {
                                    word[i] = alphabet[(j - shift + 26) % 26];
                                    break;
                                }
                            }
                        }
                        cout << "Decrypted text: " << word << endl;
                        break;
                    }
                    case 2: { // Vigenere
                        for (int i = 0; i < 26; i++) {
                            for (int j = 0; j < 26; j++) {
                                vigenereTable[i][j] = alphabet[(j + i) % 26];
                            }
                        }
                        cout << "Enter encrypted text (uppercase letters only):\n";
                        getline(cin, word);
                        cout << "Enter key:\n";
                        cin >> key;
                        int keyPos = 0;
                        for (int i = 0; i < word.length(); i++) {
                            if (word[i] == ' ') continue;
                            char keyChar = key[keyPos % key.length()];
                            int keyIndex = keyChar - 'A';
                            for (int j = 0; j < 26; j++) {
                                if (word[i] == vigenereTable[keyIndex][j][0]) {
                                    word[i] = alphabet[j];
                                    keyPos++;
                                    break;
                                }
                            }
                        }
                        cout << "Decrypted text: " << word << endl;
                        break;
                    }
                    case 3: { // Atbash
                        cout << "Enter encrypted text (uppercase letters only):\n";
                        getline(cin, word);

                        for (int i = 0; i < word.length(); i++) {
                            for (int j = 0; j < 26; j++) {
                                if (word[i] == alphabet[j]) {
                                    word[i] = alphabet[25 - j];
                                    break;
                                }
                            }
                        }
                        cout << "Decrypted text: " << word << endl;
                        break;
                    }
                    case 4: { // XOR
                        cout << "Enter key:\n";
                        cin >> key;
                        cin.ignore();
                        cout << "Enter encrypted text:\n";
                        getline(cin, word);
                        for (int i = 0; i < word.length(); i++) {
                            word[i] = word[i] ^ key[i % key.length()];
                        }
                        cout << "Decrypted text: " << word << endl;
                        break;
                    }
                    default:
                        cout << "Invalid cipher selection.\n";
                        break;
                }
                break;
            default:
                cout << "Invalid mode selection.\n";
                break;
        }
    }
    return 0;
}
