#include "global.h"

#include "utils.h"
#include "record.h"
#include "retrieval.h"
#include "sort.h"


int main(int argc, char **argv) {

    class Record rows[MAX], *ptr[MAX];
    int cnt = readDat(rows);
    init_ptr(ptr, rows);

//    writeDat(ptr, cnt);
//    return 0;
    if (argc == 2) {
        if (strcmp("sample", argv[1]) == 0) {
            print_rows(rows);
        } else if (strcmp("list", argv[1]) == 0) {
            print_rows(rows, cnt);
        } else {
            goto help;
        }

    } else if (argc == 3) {

    } else if (argc == 4) {
        if (strcmp("retrieve", argv[1]) == 0 &&
            strcmp("name", argv[2]) == 0) {
            retrieve_by_name(rows, cnt, argv[3]);

        } else if (strcmp("retrieve", argv[1]) == 0 &&
                   strcmp("chalu", argv[2]) == 0) {
            retrieve_by_chalu(rows, cnt, argv[3]);

        } else if (strcmp("retrieve", argv[1]) == 0 &&
                   strcmp("fanhao", argv[2]) == 0) {
            retrieve_by_fanhao(rows, cnt, argv[3]);

        } else if (strcmp("retrieve", argv[1]) == 0 &&
                   strcmp("linkid", argv[2]) == 0) {
            retrieve_by_linkid(rows, cnt, argv[3]);

        } else if (strcmp("sort", argv[1]) == 0) {
            bool reversed = false;

            // up or down
            if (strcmp("up", argv[3]) == 0) {
                reversed = false;
            } else if (strcmp("down", argv[3]) == 0) {
                reversed = true;
            } else {
                goto help;
            }

            // 4 xuan 1
            if (strcmp("name", argv[2]) == 0) {
                sort_my_record_by_name(ptr, cnt, reversed);
            } else if (strcmp("chalu", argv[2]) == 0) {
                sort_my_record_by_chalu(ptr, cnt, reversed);
            } else if (strcmp("fanhao", argv[2]) == 0) {
                sort_my_record_by_fanhao(ptr, cnt, reversed);
            } else if (strcmp("linkid", argv[2]) == 0) {
                sort_my_record_by_linkid(ptr, cnt, reversed);
            } else {
                goto help;
            }


        } else {
            goto help;
        }

    } else {
        help:
        cout << "cpp_backend的用法:(GTBL.dat在同一目录下，此程序不检查参数正确性)" << endl;
        cout << "./cpp_backend sample 输出十个给你测试用" << endl;
        cout << "./cpp_backend list 输出所有地图信息" << endl;

        cout << "./cpp_backend retrieve name \"xxx\"  根据名字检索(顺序查找)" << endl;
        cout << "./cpp_backend retrieve chalu xxx  根据岔路数量检索(顺序查找),0<=xxx<8" << endl;
        cout << "./cpp_backend retrieve fanhao xxx  根据番号检索(顺序查找),0<=xxx<16" << endl;
        cout << "./cpp_backend retrieve linkid xxx  根据linkid检索(顺序查找),0<=xxx<int_max" << endl;

        cout << "./cpp_backend sort name up/down  根据名字排序" << endl;
        cout << "./cpp_backend sort chalu up/down 根据岔路数量排序" << endl;
        cout << "./cpp_backend sort fanhao up/down 根据番号排序" << endl;
        cout << "./cpp_backend sort linkid up/down 根据linkid排序" << endl;

    }


    return 0;
}