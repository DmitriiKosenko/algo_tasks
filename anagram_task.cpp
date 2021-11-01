/*

 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef struct Pair Pair;
struct Pair {
	unsigned int val1;
	unsigned int val2;
};

bool is_anagram(string s1, string s2) {

	if (s1.empty() || s2.empty()) return false;
	if (s1.length() != s2.length()) return false;

	unordered_map<char, Pair> u;
	bool flag = true; // string are equals

	for (unsigned int i = 0; i < s1.length(); i++) {
		char p1 = s1[i];
		char p2 = s2[i];
		if (p1 == p2) {
			Pair v = u[p1];
			v.val1++;
			v.val2++;
			u[p1] = v;
		} else {
			Pair v1 = u[p1];
			Pair v2 = u[p2];
			v1.val1++;
			v2.val2++;
			u[p1] = v1;
			u[p2] = v2;
		}
		
		if (flag) {
			flag = p1 == p2;
		}
	}

	if (flag) return false;

	for (const auto& n : u) {
		if (n.second.val1 != n.second.val2) return false;
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