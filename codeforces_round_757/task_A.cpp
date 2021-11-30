#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

	int t;
	cin >> t;

	vector<int> answers;
	answers.reserve(t);

	for (unsigned int i = 0; i < t; i++) {
		int n, l, r, k;
		multiset<int> m;

		cin >> n;
		cin >> l;
		cin >> r;
		cin >> k;
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			if (v >= l && v <= r) {
				m.insert(v);
			}
		}
		
		int counter = 0;
		auto it = m.begin();
		while (it != m.end() && k > 0) {
			if (*it <= k) {
				counter++;
				k = k - (*it);
				it++;
			} else {
				k = -1;
			}
		}
		answers.push_back(counter);
	}

	for (int i = 0; i < t; i++) {
		cout << answers[i] << endl;
	}
	
	return 0;
}










