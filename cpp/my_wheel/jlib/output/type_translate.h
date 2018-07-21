//各种类型之间的转换控制类

#include <string>

class TypeTranslate {
public:
    static float pchar_2_float(const char* pchar);

    static std::string float_2_string(float f);
	static std::string int_2_string(int i);

};


