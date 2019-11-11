//
// Created by 派星星 on 2019/11/11.
//
#include <codecvt>
#include <utility>
#include "record.h"
#include "utils.h"

void endianChange(struct _struct_record &t) {
    // change the endian mode
    t._struct_size = swap_uint16(t._struct_size);
    t._id = swap_uint32(t._id);
    t._name_size = swap_uint16(t._name_size);
    t._info = swap_uint32(t._info);
}


int readDat(Record *rows) {
    // create tmp struct
    struct _struct_record _tmp_record;
    int _string_size = 0;
    string _tmp_string;

    FILE *fptr = fopen("GTBL.dat", "rb");

    // if not have file than raise error
    if (fptr == NULL) {
        printf("Cannot find GTBL.dat!");
        exit(1);
    }

    int cnt = 0;
    while (fread(&_tmp_record, sizeof(_struct_record), 1, fptr) == 1) {
    // till eof


        endianChange(_tmp_record);
        _string_size = _tmp_record._struct_size - 12; // 12 = 2 + 4 + 2 + 4

        char _tmp_char[100];
        fread(_tmp_char, _string_size * sizeof(char), 1, fptr);
        _tmp_char[_string_size] = 0;

        _tmp_string = gbk2utf8(_tmp_char);
        rows[cnt++] = Record(_tmp_record._id,
                             _tmp_record._name_size,
                             _tmp_record._info,
                             _tmp_string);
    }


    fclose(fptr);
    return cnt;
}

Record::Record(uint32_t _id, uint16_t _name_size, uint32_t _info) {
    this->_id = _id;
    this->_name_size = _name_size;
    this->_info = _info;
}

Record::Record(uint32_t _id, uint16_t _name_size, uint32_t _info, string _name) {
    this->_id = _id;
    this->_name_size = _name_size;
    this->_info = _info;
    this->_name = string();

    // save memory
    this->_name = std::move(_name);
}

Record::Record() {

}

uint32_t Record::getid() {
    return this->_id;
}

string *Record::getname() {
    return &this->_name;
}

uint8_t Record::getchalu() {
    return (this->_info & 0x0070) >> 4;
}

uint8_t Record::getflag() {
    return (this->_info & 0x0080) >> 7;
}

uint8_t Record::getfanhao() {
    return (this->_info & 0x000F);
}
