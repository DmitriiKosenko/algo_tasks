/*

Даны две строки, состоящие из строчных латинских букв. Требуется определить, являются ли эти строки анаграммами, т. е. отличаются ли они только порядком следования символов.
Формат ввода

Входной файл содержит две строки строчных латинских символов, каждая не длиннее 100 000 символов. Строки разделяются символом перевода строки.
Формат вывода

Выходной файл должен содержать единицу, если строки являются анаграммами, и ноль в противном случае.

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

	string s1;
	string s2;
	cin >> s1;
	cin >> s2;

	if (s1.size() == 0 || s2.size() == 0) {
		cout << 0;
		return 0;
	}
	if (s1.size() != s2.size()) {
		cout << 0;
		return 0;
	}

	unordered_map<char, pair<int, int>> m;
	bool flag = true;
	for (int i = 0; i < s1.size(); i++) {
		m[s1[i]].first++;
		m[s2[i]].second++;
		if (flag) {
			if (s1[i] != s2[i]) flag = false;
		}
	}

	if (flag) {
		cout << 1;
		return 0;
	}

	for (auto v : m) {
		if (v.second.first != v.second.second) {
			cout << 0;
			return 0;
		}
	}

	cout << 1;
	return 0;
}