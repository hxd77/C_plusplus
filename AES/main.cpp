#include"AES.h"
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    AES aes;
    
    // 设置密钥
    aes::byte key[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
    aes.setCipherKey(key);
    
    // 设置明文
    aes::byte plaintext[16]={0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
    aes.setPlainText(plaintext);
    
    // 输出轮密钥
    /*
    cout << "Round Key:" << endl;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << "0x" << hex << setw(2) << setfill('0') 
                 << static_cast<int>(aes.wordKeys[i].wordKey[j]) << " ";
        }
        cout << endl;
    }
    */
    
    // 输出明文矩阵
    cout << "\nPlaintext Matrix:" << endl;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << "0x" << hex << setw(2) << setfill('0') 
                 << static_cast<int>(plaintext[i*4 + j]) << " ";
        }
        cout << endl;
    }
    
    // 执行加密
    aes.processEncryption();
    
    // 获取并输出密文
    aes::byte ciphertext[16];
    aes.getCipherText(ciphertext);
    
    cout << "\nCiphertext Matrix:" << endl;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << "0x" << hex << setw(2) << setfill('0') 
                 << static_cast<int>(ciphertext[i*4 + j]) << " ";
        }
        cout << endl;
    }
    
    return 0;
}