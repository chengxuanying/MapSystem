#include "global.h"

#include "utils.h"
#include "record.h"
#include "retrieval.h"


int main(int argc, char **argv) {

    class Record rows[MAX], *t;
    int cnt = readDat(rows);

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

        } else {
            goto help;
        }

    } else {
        help:
        cout << "cpp_backend的用法:(GTBL.dat在同一目录下)" << endl;
        cout << "./cpp_backend sample 输出十个给你测试用" << endl;
        cout << "./cpp_backend list 输出所有地图信息" << endl;

        cout << "./cpp_backend retrieve name xxx  根据名字检索(顺序查找)" << endl;
        cout << "./cpp_backend retrieve chalu xxx  根据岔路数量检索(顺序查找)" << endl;
        cout << "./cpp_backend retrieve fanhao xxx  根据番号检索(顺序查找)" << endl;
        cout << "./cpp_backend retrieve linkid xxx  根据linkid检索(顺序查找)" << endl;
    }


    return 0;
}