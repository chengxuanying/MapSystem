//
// Created by 派星星 on 2019/11/11.
//

#include "global.h"
#include "utils.h"
#include "record.h"

//! Byte swap unsigned short
uint16_t swap_uint16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

//! Byte swap short
int16_t swap_int16(int16_t val) {
    return (val << 8) | ((val >> 8) & 0xFF);
}

//! Byte swap unsigned int
uint32_t swap_uint32(uint32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

//! Byte swap int
int32_t swap_int32(int32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | ((val >> 16) & 0xFFFF);
}


int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen) {
    iconv_t cd;
    int rc;
    char **pin = &inbuf;
    char **pout = &outbuf;
    cd = iconv_open(to_charset, from_charset);
    if (cd == 0)
        return -1;
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
        return -1;
    iconv_close(cd);
    return 0;
}

std::string any2utf8(std::string in, std::string fromEncode, std::string toEncode) {
    char *inbuf = (char *) in.c_str();
    int inlen = strlen(inbuf);
    int outlen = inlen * 3 + 5;//in case unicode 3 times than ascii + 5 to remove "" zero string
    char outbuf[outlen];// = {0};
    for (int i = 0; i < outlen; ++i) {
        outbuf[i] = '\0';
    }

    int rst = code_convert((char *) fromEncode.c_str(), (char *) toEncode.c_str(), inbuf, inlen, outbuf, outlen);
    if (rst == 0) {
        return std::string(outbuf);
    } else {
        return in;
    }
}

std::string gbk2utf8(const char *in) {
    return any2utf8(std::string(in), std::string("gbk"), std::string("utf-8"));
}

std::string utf82gbk(const char *in) {
    return any2utf8(std::string(in), std::string("utf-8"), std::string("gbk"));
}

std::string utf82gbk(string in) {
    return any2utf8(in, std::string("utf-8"), std::string("gbk"));
}

void init_ptr(class Record **ptr, class Record *rows, int cnt) {
    for (int i = 0; i < cnt; ++i) {
        ptr[i] = rows + i;
    }
}