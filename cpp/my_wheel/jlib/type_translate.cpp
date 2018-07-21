#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "type_translate.h"


float TypeTranslate::pchar_2_float(const char* pchar) {
    return atof(pchar);
}


std::string TypeTranslate::float_2_string(float f) {
    return std::to_string(f); 
}

std::string TypeTranslate::int_2_string(int i) {
    return std::to_string(i); 
}

// test
//int main() {
//    char a[10] = "3.14\0";
//    float res = TypeTranslate::pchar_2_float(a);
//    std::cout << res << std::endl;
//
//}


