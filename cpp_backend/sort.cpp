//
// Created by 派星星 on 2019/11/11.
//

#include "sort.h"
#include "record.h"
#include "retrieval.h"

inline bool smaller_by_name(class Record *a, class Record *b, bool reversed) {
    if (reversed) {
        return *a->getname() > *b->getname();
    } else {
        return *a->getname() < *b->getname();
    }
}

inline bool smaller_by_chalu(class Record *a, class Record *b, bool reversed) {
    if (reversed) {
        return a->getchalu() > b->getchalu();
    } else {
        return a->getchalu() < b->getchalu();
    }
}

inline bool smaller_by_fanhao(class Record *a, class Record *b, bool reversed) {
    if (reversed) {
        return a->getfanhao() > b->getfanhao();
    } else {
        return a->getfanhao() < b->getfanhao();
    }
}

inline bool smaller_by_linkid(class Record *a, class Record *b, bool reversed) {
    if (reversed) {
        return a->getid() > b->getid();
    } else {
        return a->getid() < b->getid();
    }
}

int partition(class Record **vi, int low, int up,
              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
              bool reversed) {
    class Record *pivot = vi[up];
    int i = low - 1;
    for (int j = low; j < up; j++) {
        if (is_smaller(vi[j], pivot, reversed)) {
            i++;
            swap(vi[i], vi[j]);
        }
    }
    swap(vi[i + 1], vi[up]);
    return i + 1;
}

void quickSort(class Record **vi, int low, int up,
               bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
               bool reversed) {
    if (low < up) {
        int mid = partition(vi, low, up, is_smaller, reversed);
        //Watch out! The mid position is on the place, so we don't need to consider it again.
        //That's why below is mid-1, not mid! Otherwise it will occur overflow error!!!
        quickSort(vi, low, mid - 1, is_smaller, reversed);
        quickSort(vi, mid + 1, up, is_smaller, reversed);
    }
}

void qSort(class Record **ptr, int cnt,
           bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
           bool reversed) {
    quickSort(ptr, 0, cnt - 1, is_smaller, reversed);
}

void bubble_sort(class Record **ptr, int cnt,
                 bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                 bool reversed) {

    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = 0; j < cnt - i - 1; ++j) {
            if (is_smaller(ptr[j], ptr[j + 1], reversed)) {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }

}


void insertSort(class Record **ptr, int cnt,
                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                bool reversed) {

    class Record *temp;
    int j;

    for (int i = 1; i < cnt; i++) {
        if (is_smaller(ptr[i], ptr[i - 1], reversed)) {
            temp = ptr[i];
            for (j = i - 1; j >= 0 && is_smaller(temp, ptr[j], reversed); j--)
                ptr[j + 1] = ptr[j];
            ptr[j + 1] = temp;
        }

    }
}

void stdSort(class Record **ptr, int cnt,
             bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
             bool reversed) {
    sort(ptr, ptr + cnt, bind(is_smaller, _1, _2, reversed));
}

void HeapAdjust(class Record **ptr, int cnt, int k,
                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                bool reversed) {
    Record *tmp = ptr[k];
    int i = 2 * k + 1;
    while (i < cnt) {
        if (i + 1 < cnt && is_smaller(ptr[i + 1], ptr[i], reversed)) //选取最小的结点位置
            ++i;
        if (is_smaller(tmp, ptr[i], reversed)) //不用交换
            break;
        ptr[k] = ptr[i]; //交换值
        k = i; //继续查找
        i = 2 * k + 1;
    }
    ptr[k] = tmp;
}

void HeapSort(class Record **ptr, int cnt,
              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
              bool reversed) {

    if (ptr == NULL || cnt <= 0)
        return;

    for (int i = cnt / 2 - 1; i >= 0; --i) {
        HeapAdjust(ptr, cnt, i, is_smaller, reversed); //从第二层开始建堆
    }

    for (int i = cnt - 1; i >= 0; --i) {
        std::swap(ptr[0], ptr[i]);
        HeapAdjust(ptr, i, 0, is_smaller, reversed); //从顶点开始建堆, 忽略最后一个
    }
}

vector<class Record *> bucket[890000];

void BucketSort(class Record **ptr, int cnt,
              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
              bool reversed) {

    if (is_smaller == smaller_by_name){
        stdSort(ptr, cnt, smaller_by_name, reversed);
        return;
    }

    if (is_smaller == smaller_by_linkid){
        for (int i = 0; i < 890000; ++i) {
            bucket[i].clear();
        }

        for (int i = 0; i < cnt; ++i) {
            int id = ptr[i]->getid();
            bucket[id].push_back(ptr[i]);
        }

        int index = 0;
        for (int i = 0; i < 890000; ++i) {
            for(int j = 0; j < bucket[i].size(); ++j){
                ptr[index++] = bucket[i][j];
            }
        }

        return;
    }

    if (is_smaller == smaller_by_chalu){
        for (int i = 0; i < 20; ++i) {
            bucket[i].clear();
        }

        for (int i = 0; i < cnt; ++i) {
            int id = ptr[i]->getchalu();
            bucket[id].push_back(ptr[i]);
        }

        int index = 0;
        for (int i = 0; i < 20; ++i) {
            for(int j = 0; j < bucket[i].size(); ++j){
                ptr[index++] = bucket[i][j];
            }
        }

        return;
    }

    if (is_smaller == smaller_by_fanhao){
        for (int i = 0; i < 20; ++i) {
            bucket[i].clear();
        }

        for (int i = 0; i < cnt; ++i) {
            int id = ptr[i]->getfanhao();
            bucket[id].push_back(ptr[i]);
        }

        int index = 0;
        for (int i = 0; i < 20; ++i) {
            for(int j = 0; j < bucket[i].size(); ++j){
                ptr[index++] = bucket[i][j];
            }
        }

        return;
    }
}

/*
 *
 * 业务
 *
 */

void sort_my_record_by_name(class Record **ptr, int cnt, bool reversed,
                            void (*sort_func)(class Record **ptr, int cnt,
                                              bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                              bool reversed)) {
    sort_func(ptr, cnt, smaller_by_name, reversed);
}

void sort_my_record_by_chalu(class Record **ptr, int cnt, bool reversed,
                             void (*sort_func)(class Record **ptr, int cnt,
                                               bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                               bool reversed)) {
    sort_func(ptr, cnt, smaller_by_chalu, reversed);
}

void sort_my_record_by_fanhao(class Record **ptr, int cnt, bool reversed,
                              void (*sort_func)(class Record **ptr, int cnt,
                                                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                                bool reversed)) {
    sort_func(ptr, cnt, smaller_by_fanhao, reversed);
}

void sort_my_record_by_linkid(class Record **ptr, int cnt, bool reversed,
                              void (*sort_func)(class Record **ptr, int cnt,
                                                bool (*is_smaller)(class Record *a, class Record *b, bool reversed),
                                                bool reversed)) {
    sort_func(ptr, cnt, smaller_by_linkid, reversed);
}