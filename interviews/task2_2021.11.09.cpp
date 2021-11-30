// Дан текст T и строка S. 
// Требуется найти подстроку S' в T такую, что она совпадает с S с точностью до перестановки букв.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string get_sub_str(const string& t, const string& s) {
	if (s.length() == 0) return "";
	if (t.length() == 0) return "";
	if (s.length() > t.length()) return "";

	unordered_map<char, int> m;
	for (int i = 0; i < s.length(); i++) {
		int c;
		c = m[s[i]];
		if (c == 0) {
			m[s[i]] = 1;
		} else {
			if (c - 1 == 0) {
				m.erase(s[i]);
			} else {
				m[s[i]] = c - 1;
			}
		}
		
		c = m[t[i]];
		if (c == 0) {
			m[t[i]] = 1;
		} else {
			if (c - 1 == 0) {
				m.erase(t[i]);
			} else {
				m[t[i]] = c - 1;
			}
		}
	}
	if (m.size() == 0) return t.substr(0, s.size());

	for (int i = 1; i < t.size() - s.size() + 1; i++) {
		char ch1 = t[i - 1];
		char ch2 = t[i + s.size() - 1];

		int c;
		c = m[ch1];
		if (c - 1 == 0) {
			m.erase(ch1);
		} else {
			m[ch1] = c - 1;
		}
		
		c = m[ch2];
		if (c == 0) {
			m[ch2] = 1;
		} else {
			if (c - 1 == 0) {
				m.erase(ch2);
			} else {
				m[ch2] = c - 1;
			}
		}

		if (m.size() == 0) return t.substr(i, s.size());
	}

	return "";
}

int main() {

	cout << ( get_sub_str("", "") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("", "a") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("a", "") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abc", "abcd") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abc", "d") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abcdef", "bde") == "" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abc", "abc") == "abc" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abc", "cb") == "bc" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abcdef", "edc") == "cde" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abcdef", "fed") == "def" ? "passed" : "failed" ) << endl;
	cout << ( get_sub_str("abcdef", "abd") == "" ? "passed" : "failed" ) << endl;

	return 0;
}