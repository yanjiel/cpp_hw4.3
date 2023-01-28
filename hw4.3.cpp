#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct maxlenftn {
	maxlenftn() { /*maxlen = 0;*/}
	void operator()(string s) {
		maxlen = max(maxlen, s.size());
	}
	static string::size_type maxlen;
};

string::size_type maxlenftn::maxlen = 0;

int main() {
	vector<string> names{ "Smith", "Jones", "Johnson", "Grant" };
	maxlenftn maxf;
	for_each(names.begin(), names.end(), maxf);
	cout << maxf.maxlen << endl;
	return 0;
}