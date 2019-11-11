#include "global.h"

#include "utils.h"
#include "record.h"
#include "retrieval.h"


int main(int argc, char **argv) {

    class Record rows[MAX], *t;
    int cnt = readDat(rows);

    if (argc > 1) {
        if (strcmp("sample", argv[1]) == 0) {
            print_rows(rows);
        } else if (strcmp("list", argv[1]) == 0) {
            print_rows(rows, cnt);
        } else {
            goto help;
        }

    } else {
        help:
        cout << "cpp_backend的用法:(GTBL.dat在同一目录下)" << endl;
        cout << "./cpp_backend sample 输出十个给你测试用" << endl;
        cout << "./cpp_backend list 输出所有地图信息" << endl;
    }


    return 0;
}