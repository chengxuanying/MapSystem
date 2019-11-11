//
// Created by 派星星 on 2019/11/11.
//
#include "record.h"
#include "utils.h"

void endianChange(struct _struct_record &t) {
    // change the endian mode
    t._struct_size = swap_uint16(t._struct_size);
    t._id = swap_uint32(t._id);
    t._name_size = swap_uint16(t._name_size);
    t._info = swap_uint32(t._info);
}

int readDat() {
    // create tmp struct
    struct _struct_record _tmp_struct_record;

    int _string_size = 0;

    FILE *fptr = fopen("../GTBL.dat", "rb");

    // if not have file than raise error
    if (fptr == NULL) {
        printf("Cannot find GTBL.dat!");
        exit(1);
    }

    cout << "struct_size:" << sizeof(_struct_record) << endl;
    int cnt = 0;
    while (fread(&_tmp_struct_record, sizeof(_struct_record), 1, fptr) == 1) {

        endianChange(_tmp_struct_record);
        _string_size = _tmp_struct_record._struct_size - 12; // 12 = 2 + 4 + 2 + 4

        char _tmp_string[100];
        fread(_tmp_string, _string_size * sizeof(char), 1, fptr);
        _tmp_string[_string_size + 1] = 0;


        cout << _tmp_string << ';' << endl;
        std::string str2 ( _tmp_string);
        cout << str2 << endl;
//        char *a = "123是23";
//        cout << a << endl;
        cout << ++cnt << ":" << _tmp_struct_record._name_size << endl;
    }


    fclose(fptr);
}