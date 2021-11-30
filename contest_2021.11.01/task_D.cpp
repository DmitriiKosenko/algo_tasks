/*

Дано целое число n. Требуется вывести все правильные скобочные последовательности длины 2 ⋅ n, упорядоченные лексикографически (см. https://ru.wikipedia.org/wiki/Лексикографический_порядок).
В задаче используются только круглые скобки.

Желательно получить решение, которое работает за время, пропорциональное общему количеству правильных скобочных последовательностей в ответе, и при этом использует объём памяти, пропорциональный n.

Формат ввода
Единственная строка входного файла содержит целое число n, 0 ≤ n ≤ 11

Формат вывода
Выходной файл содержит сгенерированные правильные скобочные последовательности, упорядоченные лексикографически.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

bool is_right_seq(vector<int>& v) {
	int counter = 0;
	for (int i = 0; i < v.size(); i++) {
		int pos = v.size() - 1 - i;
		if (v[pos] == 1) {
			counter++;
		} else {
			counter--;
		}
		if (counter < 0) return false;
	}
	return counter == 0;
}

string get_seq(vector<int>& v) {
	stringstream ss;
	for (int i = 0; i < v.size(); i++) {
		int pos = v.size() - 1 - i;
		ss << (v[pos] == 1 ? "(" : ")");
	}
	return ss.str();
}

int main() {

	int n;
	cin >> n;

	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
		cout << "()";
		return 0;
	}

	int length = 2 * n;
	int steps = 0;
	vector<int> v;
	v.reserve(length);

	for (int i = 0; i < length; i++) {
		if (i < length / 2) {

			if (i % 2 == 1) {
				steps = steps - pow(2, i);
			}
		} else {
			

			if (i % 2 == 0) {
				steps = steps + pow(2, i);
			}
		}

		v.push_back(i % 2 == 0 ? 0 : 1);
	}

	vector<string> s;
	s.push_back(get_seq(v));
	for (int i = 0; i < steps; i++) {
		bool flag = false;
		int pos = 0;
		while (! flag) {
			if (v[pos] == 0) {
				v[pos] = 1;
				flag = true;
			} else {
				v[pos] = 0;
				pos++;
			}
		}

		if (is_right_seq(v)) {
			s.push_back(get_seq(v));
		}
	}


	for (int i = 0; i < s.size(); i++) {
		int pos = s.size() - 1 - i;
		cout << s[pos] << endl;
	}
	
	return 0;
}