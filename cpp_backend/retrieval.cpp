//
// Created by 派星星 on 2019/11/11.
//
#include "retrieval.h"
#include "record.h"
/**/
void print_rows(class Record *rows, int cnt){
    class Record *t;

    json j;
    j["cnt"] = cnt;

    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name", *t->getname()},
                               {"flag", t->getflag()},
                               {"chalu", t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    cout << j.dump();
}