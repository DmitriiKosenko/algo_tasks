
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_anagram(string s1, string s2) {

	if (s1.empty() || s2.empty()) return false;
	if (s1.length() != s2.length()) return false;

	unordered_map<char, pair<int, int>> u;
	bool flag = true; // string are equals

	for (unsigned int i = 0; i < s1.length(); i++) {
		char p1 = s1[i];
		char p2 = s2[i];
		if (p1 == p2) {
			pair<int, int> v = u[p1];
			v.first++;
			v.second++;
			u[p1] = v;
		} else {
			pair<int, int> v1 = u[p1];
			pair<int, int> v2 = u[p2];
			v1.first++;
			v2.second++;
			u[p1] = v1;
			u[p2] = v2;
		}
		
		if (flag) {
			flag = p1 == p2;
		}
	}

	if (flag) return false;

	for (const auto& n : u) {
		if (n.second.first != n.second.second) return false;
	}

	return true;
}

int main() {

	cout << "0: " << (is_anagram("", "") ? "true" : "false") << endl;
	cout << "1: " << (is_anagram("a", "") ? "true" : "false")  << endl;
	cout << "2: " << (is_anagram("abc", "a") ? "true" : "false")  << endl;
	cout << "3: " << (is_anagram("abc", "abc") ? "true" : "false")  << endl;
	cout << "4: " << (is_anagram("cba", "abc") ? "true" : "false")  << endl;
	cout << "5: " << (is_anagram("cbd", "abc") ? "true" : "false")  << endl;

	cout << "a1: " << (is_anagram("cbadef", "abcfed") ? "true" : "false")  << endl;
	cout << "a2: " << (is_anagram("cbadef", "abrfed") ? "true" : "false")  << endl;
	
	return 0;
}