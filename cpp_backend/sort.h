//
// Created by 派星星 on 2019/11/11.
//

#ifndef CPP_BACKEND_SORT_H
#define CPP_BACKEND_SORT_H

#endif //CPP_BACKEND_SORT_H

#include "global.h"


bool smaller_by_name(class Record *a, class Record *b, bool reversed = false);

bool smaller_by_chalu(class Record *a, class Record *b, bool reversed = false);

bool smaller_by_fanhao(class Record *a, class Record *b, bool reversed = false);

bool smaller_by_linkid(class Record *a, class Record *b, bool reversed = false);

void qSort(class Record **ptr, int cnt,
           bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
           bool reversed);

void bubble_sort(class Record **ptr, int cnt,
                 bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                 bool reversed);

void insertSort(class Record **ptr, int cnt,
                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                bool reversed);

void stdSort(class Record **ptr, int cnt,
             bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
             bool reversed);

void HeapAdjust(class Record **ptr, int cnt, int k,
                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                bool reversed);

void HeapSort(class Record **ptr, int cnt,
              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
              bool reversed);

void sort_my_record_by_name(class Record **ptr, int cnt, bool reversed = false,
                            void (*sort_func)(class Record **ptr, int cnt,
                                              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                              bool reversed) = stdSort);

void sort_my_record_by_chalu(class Record **ptr, int cnt, bool reversed = false,
                             void (*sort_func)(class Record **ptr, int cnt,
                                               bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                               bool reversed) = stdSort);

void sort_my_record_by_fanhao(class Record **ptr, int cnt, bool reversed = false,
                              void (*sort_func)(class Record **ptr, int cnt,
                                                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                                bool reversed) = stdSort);

void sort_my_record_by_linkid(class Record **ptr, int cnt, bool reversed = false,
                              void (*sort_func)(class Record **ptr, int cnt,
                                                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                                bool reversed) = stdSort);
