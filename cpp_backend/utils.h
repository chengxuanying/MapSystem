//
// Created by 派星星 on 2019/11/11.
//

#ifndef CPP_BACKEND_UTILS_H
#define CPP_BACKEND_UTILS_H

#endif //CPP_BACKEND_UTILS_H

#include <stdint.h>

uint16_t swap_uint16(uint16_t val);

int16_t swap_int16(int16_t val);

uint32_t swap_uint32(uint32_t val);

int32_t swap_int32(int32_t val);

int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);

std::string any2utf8(std::string in, std::string fromEncode, std::string toEncode);

std::string gbk2utf8(const char *in);

