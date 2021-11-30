#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {

	int t;
	cin >> t;

	vector<pair<int, vector<int>>> answers;
	answers.reserve(t);

	for (unsigned int i = 0; i < t; i++) {
		int n;
		map<int, vector<int>> m;

		cin >> n;
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			m[v].push_back(j + 1);
		}
		
		vector<int> cs;
		cs.resize(n + 1);
		cs[0] = 0;

		int coordinate = 1;
		int dist = 0;
		auto it = m.rbegin();
		while (it != m.rend()) {
			vector<int> v = it->second;
			for (int i1 = 0; i1 < v.size(); i1++) {
				cs[v[i1]] = coordinate;
				dist += abs(coordinate) * 2 * it->first;
				if (coordinate > 0) {
					coordinate = -1 * coordinate;
				} else {
					coordinate = -1 * coordinate + 1;
				}
			}
			it++;
		}
		answers.push_back(pair<int, vector<int>>(dist, cs));
	}

	for (int i = 0; i < t; i++) {
		cout << answers[i].first << endl;
		vector<int> v = answers[i].second;
		for (int j = 0; j < v.size(); j++) {
			cout << v[j] << (j != (v.size() - 1) ? " " : "");
		}
		cout << endl;
	}
	
	return 0;
}




