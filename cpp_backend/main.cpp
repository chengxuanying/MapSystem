#include "global.h"

#include "utils.h"
#include "record.h"

#include "json.hpp"
using json = nlohmann::json;

int main() {
//    json j;
//    j["startrow"] = { 1 };
//    j["endrow"] = { 100 };
//    j["result"] = { json::array({1,2,3}) };
//    auto cpp_string = j.dump();
//    cout << cpp_string;
    ;

    readDat();
    return 0;
}