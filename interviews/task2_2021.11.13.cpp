// Дан массив целых чисел.
// Нужно найти непустой подотрезок (непрерывную подпоследовательность) с заданной суммой X,
// либо сказать, что это невозможно.

// a=[1, -3, 10, -5]
// p=[1, -2, 8, 3]

// s - X
// a
// p
// (i, j) -> p[j + 1] - p[i]
// X=7
// X = -5
// [10, -3]

// [3, -3, 3, -3] X = 7

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

pair<int, int> get_sub_seq(const vector<int>& v, int x) {
	if (v.size() == 0) return pair<int, int>(-1, -1);
	if (v.size() == 1) {
		if (v[0] == x) {
			return pair<int, int>(0, 0);
		} else {
			return pair<int, int>(-1, -1);
		}
	}

	int sum = 0;
	unordered_map<int, int> m;

	for (int i = 0; i < v.size(); i++) {
		if (x == v[i]) return pair<int, int>(i, i);
		if (x == sum + v[i]) return pair<int, int>(0, i);

		sum += v[i];
		int d = sum - x;
		if (m.find(d) != m.end()) {
			return pair<int, int>(m.at(d) + 1, i);
		}
		m[sum] = i;
	}

	return pair<int, int>(-1, -1);
}

void pp(const pair<int, int> p1, const pair<int, int> p2) {
	if (p1.first == p2.first && p1.second == p2.second) {
		cout << p1.first << " : " << p1.second << " " << "passed" << endl;
	} else {
		cout << p1.first << " : " << p1.second << " " << "failed" << endl;
	}
	
}

int main() {

	pp(get_sub_seq({}, 5), pair<int, int>(-1, -1));
	pp(get_sub_seq({1, 2, 3}, 5), pair<int, int>(1, 2));
	pp(get_sub_seq({1, -3, 10, -5}, -5), pair<int, int>(3, 3));
	pp(get_sub_seq({0, -3, 10, -5}, 0), pair<int, int>(0, 0));
	pp(get_sub_seq({0, -3, 10, -5}, 7), pair<int, int>(0, 2));
	pp(get_sub_seq({0, -3, 10, -5}, 2), pair<int, int>(0, 3));
	pp(get_sub_seq({0}, 2), pair<int, int>(-1, -1));
	pp(get_sub_seq({-5, 5, -5, 5}, 10), pair<int, int>(-1, -1));
	pp(get_sub_seq({-5, 5, -5, 5}, -5), pair<int, int>(0, 0));

	return 0;
}