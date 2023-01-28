//end() always returns a special, past - the - end iterator.
//That iterator is not dereferenceable(it doesn't point to any element), it just serves as an indicator of the container's end.

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

	for_each(names.begin(), names.end(), [](string& v) {static string n = "-"; v = n; });
	for_each(names.begin(), names.end(), [](string v) {cout << v << " "; });
	return 0;
}