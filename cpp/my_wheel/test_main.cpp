#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "type_translate.h"

using namespace std;


int main(int argc, char** argv) {
    char a[10] = "5.16\0";
    float res = TypeTranslate::pchar_2_float(a);
    cout << res << endl;
}



