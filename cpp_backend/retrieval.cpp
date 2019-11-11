//
// Created by 派星星 on 2019/11/11.
//
#include "retrieval.h"
#include "record.h"

void print_rows(class Record *rows, int cnt) {
    class Record *t;

    json j;
    j["cnt"] = cnt;

    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    cout << j.dump();
}

void print_rows(class Record **rows, int cnt) {
    class Record *t;

    json j;
    j["cnt"] = cnt;

    for (int i = 0; i < cnt; ++i) {
        t = rows[i];
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    cout << j.dump();
}

void retrieve_by_name(class Record *rows, int cnt, char *name) {
    class Record *t;

    json j;

    int _cnt = 0;
    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        if (t->getname()->compare(name) != 0)
            continue;

        _cnt ++;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    j["cnt"] = _cnt;
    cout << j.dump();
}

void retrieve_by_chalu(class Record *rows, int cnt, char *chalu) {
    int _chalu;
    sscanf(chalu, "%d" , &_chalu);

    class Record *t;

    json j;

    int _cnt = 0;
    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        if (t->getchalu() != (uint8_t)_chalu)
            continue;
        _cnt ++;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    j["cnt"] = _cnt;
    cout << j.dump();
}

void retrieve_by_fanhao(class Record *rows, int cnt, char *fanhao) {
    int _fanhao;
    sscanf(fanhao, "%d" , &_fanhao);
    class Record *t;

    json j;

    int _cnt = 0;
    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        if (t->getfanhao() != (uint8_t)_fanhao)
            continue;

        _cnt ++;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    j["cnt"] = _cnt;
    cout << j.dump();
}

void retrieve_by_linkid(class Record *rows, int cnt, char *linkid) {
    int _id;
    sscanf(linkid, "%d" , &_id);


    class Record *t;

    json j;

    int _cnt = 0;
    for (int i = 0; i < cnt; ++i) {
        t = rows + i;
        if (t->getid() != (uint32_t)_id)
            continue;

        _cnt ++;
        j["result"].push_back({{"linkid", t->getid()},
                               {"name",   *t->getname()},
                               {"flag",   t->getflag()},
                               {"chalu",  t->getchalu()},
                               {"fanhao", t->getfanhao()}});
    }

    j["cnt"] = _cnt;
    cout << j.dump();
}