//
// Created by 派星星 on 2019/11/11.
//

#include "sort.h"
#include "record.h"
#include "retrieval.h"

bool smaller_by_name(class Record *a, class Record *b, bool reversed) {
    return !reversed == a->getname() < b->getname();
}

bool smaller_by_chalu(class Record *a, class Record *b, bool reversed) {
    return !reversed == a->getchalu() < b->getchalu();
}

bool smaller_by_fanhao(class Record *a, class Record *b, bool reversed) {
    return !reversed == a->getfanhao() < b->getfanhao();
}

bool smaller_by_linkid(class Record *a, class Record *b, bool reversed) {
    return !reversed == a->getid() < b->getid();
}

void bubble_sort(class Record **ptr, int cnt,
        bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                bool reversed) {

    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = 0; j < cnt - i - 1; ++j) {
            if (is_smaller(ptr[j], ptr[j + 1], reversed)){
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }

}

void sort_my_record_by_name(class Record **ptr, int cnt, bool reversed) {
    bubble_sort(ptr, cnt, smaller_by_name, reversed);
    print_rows(ptr);
}

void sort_my_record_by_chalu(class Record **ptr, int cnt, bool reversed) {
    bubble_sort(ptr, cnt, smaller_by_chalu, reversed);
    print_rows(ptr);
}

void sort_my_record_by_fanhao(class Record **ptr, int cnt, bool reversed) {
    bubble_sort(ptr, cnt, smaller_by_fanhao, reversed);
    print_rows(ptr);
}

void sort_my_record_by_linkid(class Record **ptr, int cnt, bool reversed) {
    bubble_sort(ptr, cnt, smaller_by_linkid, reversed);
    print_rows(ptr);
}