//
// Created by 派星星 on 2019/11/11.
//


#ifndef CPP_BACKEND_RETRIEVAL_H
#define CPP_BACKEND_RETRIEVAL_H

#endif //CPP_BACKEND_RETRIEVAL_H

#include "global.h"

void print_rows(class Record *rows, int cnt = 20);

void print_rows(class Record **rows, int cnt = 20);

void retrieve_by_name(class Record *rows, int cnt, char *name);

void retrieve_by_chalu(class Record *rows, int cnt, char *chalu);

void retrieve_by_fanhao(class Record *rows, int cnt, char *fanhao);

void retrieve_by_linkid(class Record *rows, int cnt, char *linkid);