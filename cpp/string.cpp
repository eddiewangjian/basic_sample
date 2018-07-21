#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


using namespace std;

// 初始化
void test1() {
    string a = "abcdefg";
    string b = "b";
    string c = "c";

    string d = a + b + c;
    cout << d << endl;

	string e("n" + a);
    cout << e << endl;

	string f(a, 2, 30);
    cout << f << endl;

	string g;
    cout << g << endl;

    return;
}

// 长度判断
void test2() {
	string a(3, 'a');
	cout << a << endl;
	cout << a.capacity() << endl;
	a.clear();
	cout << a << endl;
	cout << a.capacity() << endl;
	
	cout << a.empty() << endl;
	cout << a.size() << endl;

	a.resize(10);
	cout << a << endl;
	cout << a.size() << endl;
	a.resize(15, 'b');
	cout << a << endl;
	cout << a.size() << endl;
	a.resize(10);
	cout << a << endl;
	cout << a.size() << endl;

	cout << a.length() << endl;
	cout << a.capacity() << endl;
	a.reserve(20);
	cout << a.capacity() << endl;
	cout << a.max_size() << endl;
}

// 字符串处理
void test3() {
	string a = "a";
	a.append("b");
	a += a;
	cout << a << endl;
	a += "wk";
	cout << a << endl;
	a.push_back('k');
	cout << a << endl;
	cout << a[3] << endl;
	a.insert(2, "ii");
	cout << a << endl;
	a.insert(2, a, 4, 3);
	cout << a << endl;
	a.erase(3, 2);
	cout << a.npos << endl;
	string sub = "ii";
	a.replace(a.find(sub), sub.size(), "jj");
	cout << a << endl;

	string aa = "aa";
	string bb = "bb";
	cout << aa << bb << endl;
	aa.swap(bb);
	cout << aa << bb << endl;

	string c = "aaccaa";
	size_t idx = c.rfind("aa", 3);
	cout << idx << endl;

	cout << string::npos << endl;

	string a1 = "aaa";
	string b1 = "a";
	cout << a1.compare(b1) << endl;
	cout << b1.compare(a1) << endl;
	cout << a1.compare(a1) << endl;
	cout << a1.compare(1, 1, b1) << endl;

}

// 切分
void test4() {
    string _task_result_desp = "alignment_pointcloud version=3e9819309b15b0a269e3ad0599d528ba  /home/map/hadmap/alignment-pointcloud/alignment_pointcloud|err_code:2001010";
    std::string::size_type pos = _task_result_desp.rfind(":");
    int _task_result;
    if (pos != string::npos) {
        cout << _task_result_desp.substr(pos + 1) << endl;
        _task_result = atoi(_task_result_desp.substr(pos + 1).c_str());
        cout << _task_result << endl;
    } else {
        _task_result = atoi(_task_result_desp.c_str());
    }
    cout << _task_result << endl;
}



int main(int argc, char** argv) {
    test4(); 
}







