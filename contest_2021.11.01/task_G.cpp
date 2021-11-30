/*

Не секрет, что некоторые программисты очень любят путешествовать. Хорошо всем известный программист Петя тоже очень любит путешествовать, посещать музеи и осматривать достопримечательности других городов.
Для перемещений между из города в город он предпочитает использовать машину. При этом он заправляется только на станциях в городах, но не на станциях по пути. Поэтому он очень аккуратно выбирает маршруты, чтобы машина не заглохла в дороге. А ещё Петя очень важный член команды, поэтому он не может себе позволить путешествовать слишком долго. Он решил написать программу, которая поможет ему с выбором очередного путешествия. Но так как сейчас у него слишком много других задач, он попросил вас помочь ему.
Расстояние между двумя городами считается как сумма модулей разности по каждой из координат. Дороги есть между всеми парами городов.

Формат ввода
В первой строке входных данных записано количество городов n (2≤n≤1000). В следующих n строках даны два целых числа: координаты каждого города, не превосходящие по модулю миллиарда. Все города пронумерованы числами от 1 до n в порядке записи во входных данных.
В следующей строке записано целое положительное число k, не превосходящее двух миллиардов, — максимальное расстояние между городами, которое Петя может преодолеть без дозаправки машины.
В последней строке записаны два различных числа — номер города, откуда едет Петя, и номер города, куда он едет.

Формат вывода
Если существуют пути, удовлетворяющие описанным выше условиям, то выведите минимальное количество дорог, которое нужно проехать, чтобы попасть из начальной точки маршрута в конечную. Если пути не существует, выведите -1. 

*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

unsigned int n;
vector<pair<int, int>> cities;
unsigned int k;
unsigned int a, b;

unsigned int get_dist(pair<int, int> p1, pair<int, int> p2) {
	unsigned int d1 = abs(p1.first - p2.first);
	unsigned int d2 = abs(p1.second - p2.second);
	return d1 + d2;
}

bool in_rect(pair<int, int> p1, pair<int, int> p2, pair<int, int> x) {
	return x.first <= max(p1.first, p2.first) && 
		x.first >= min(p1.first, p2.first) &&
		x.second <= max(p1.second, p2.second) &&
		x.second >= min(p1.second, p2.second);
}

void read_input() {
	//
	cin >> n;

	for (int i = 0; i < n; i++) {
		int ti1, ti2;
		cin >> ti1;
		cin >> ti2;
		cities.push_back(pair<int, int>(ti1, ti2));
	}

	cin >> k;
	cin >> a;
	cin >> b;
	//
}

pair<int, int> split_str(string s) {
	pair<int, int> result;

	bool flag = false;
	int pos = 0;
	while(! flag && pos < s.size()) {
		if (s[pos] == ' ') {
			flag = true;
			pos--;
		}
		pos++;
	}
	result.first = atoi(s.substr(0, pos).c_str());
	result.second = atoi(s.substr(pos + 1).c_str());

	return result;
}

void read_from_file() {
	string line;
	ifstream myfile ("resources/test.txt");
	if (myfile.is_open()) {
		getline (myfile, line);
		n = atoi(line.c_str());

		for (int i = 0; i < n; i++) {
			getline (myfile, line);
			cities.push_back(split_str(line));
		}

		getline (myfile, line);
		k = atoi(line.c_str());

		getline (myfile, line);
		pair<int, int> p = split_str(line);
		a = p.first;
		b = p.second;

		myfile.close();
	}

	// cout << n << endl;
	// cout << k << endl;
	// cout << a << endl;
	// cout << b << endl;

	// for (int i = 0; i < n; i++) {
	// 	cout << cities[i].first << " = " << cities[i].second << endl;
	// }
}

int main() {

	// read_input();
	read_from_file();

	if (a > n || b > n) {
		cout << -1;
		return 0;
	}
	if (a == b) {
		cout << 0;
		return 0;
	}
	if (get_dist(cities[a - 1], cities[b - 1]) <= k) {
		cout << 1;
		return 0;
	}

	unsigned int i1 = a - 1;
	unsigned int i2 = b - 1;
	vector<int> v;
	v.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (i != i1 && i != i2) {
			if (in_rect(cities[i1], cities[i2], cities[i])) {
				v.push_back(i);
			}
		}
	}

	unsigned int counter = 0;

	bool flag = true;
	while(flag) {
		if (get_dist(cities[i1], cities[i2]) <= k) {
			cout << counter + 1;
			return 0;
		}
		if (v.size() == 0) {
			cout << -1;
			return 0;
		}

		int l_max = 0;
		int ix = -1;
		vector<int> v2;
		v2.reserve(v.size());
		for (int i = 0; i < v.size(); i++) {
			unsigned int d = get_dist(cities[i1], cities[v[i]]);
			if (d <= k) {
				if (d > l_max) {
					l_max = d;
					ix = v[i];
				}
			} else {
				v2.push_back(v[i]);
			}
		}

		if (ix != -1) {
			i1 = ix;
			counter++;
			v = v2;
		} else {
			flag = false;
		}
	}

	cout << -1;
	return 0;
}


















