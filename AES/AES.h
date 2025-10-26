#ifndef AES_H
#define AES_H

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace aes {
    // 明确定义 aes::byte 类型，确保全局唯一
    typedef uint8_t byte;
}

struct word //一个字=4个字节
{
    aes::byte wordKey[4];//初始轮密钥
};

class AES
{
public:
    AES();
    void setCipherKey(aes::byte key[]);//设置初始密钥
    void setPlainText(aes::byte plain[]);//明文初始化，函数参数为字节型数组，输入为16字节的明文
    void keyExpansion(aes::byte key[],word w[]);//拓展密钥算法
    word rotWord(word w);   //使输入的4个字节循环左移1个字节
    word subWord(word w);   //利用S盒对输入的每个字节进行字节代换
    word wordXOR(word w1,word w2);
    void printState(word state[]); // 打印当前状态
    //用于处理加密和解密的各函数
    void encryption(word in[],word out[],word key[]);//加密函数
    void processEncryption();
    void addRoundKey(word in[],int round);//轮密钥加
    // 获取密文数据
    void getCipherText(aes::byte out[16]);
    void subbyte(word in[]);//S盒替换
    void shiftRows(word in[]);//行移位
    void mixColumn(word in[]);//列混淆
    aes::byte GFMultiplybyte(aes::byte L,aes::byte R);
    //用于处理解密的各函数
    void decryption(word in[],word out[],word key[]);//解密函数
    void processDecryption();
    void invSubbyte(word in[]);//逆S盒替换
    void invShiftRows(word in[]);//逆行移位
    void invMixColumn(word in[]);//逆列混淆
    void initRcon();
    word wordKeys[44];//以字形式表示的拓展后的密钥，供各轮加密过程使用
private:
    aes::byte cipherKey[16];//原始加密密钥,16字节的数组，每个字节8位，共128位
    word plainText[4];//输入的明文。4字组成的数组，每字4个字节，共128位
    word cipherText[4];//对输入的明文进行加密后得到的密文，4字组成的数组，每字4个字节，共128位
    word deCipherText[4];//对密文解密后的数据，4字组成的数组，每字4个字节，共128位
    int Nb,Nk,Nr;//Nb表示数据分组长度/32，Nk表示密钥分组长度/32，Nr表示轮数。在本示例中，Nb为4，Nk为4，Nr为10
    word Rcon[11];//用于密钥拓展的常量
    static const aes::byte SBox[16][16]; //静态常数据成员，S盒数据，数据类型为字节型，为16*16的二维数组
    static const aes::byte invSBox[16][16];//S盒的逆，数据类型为字节型，为16*16的二维数组
    static const aes::byte mixColumnMatrix[4][4];//列混淆常量矩阵，数据类型为字节型，为4*4的二维数组
    static const aes::byte invMixColumnMatrix[4][4];//逆列混淆常量矩阵，数据类型为字节型，为4*4的二维数组
};

#endif // AES_H

