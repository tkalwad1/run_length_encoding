#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace run_length_encoding {
    string encode(string phrase);
    string decode(string code);
}  // namespace run_length_encoding