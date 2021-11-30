#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int get_teams(int a, int b) {
	if (a == 0 || b == 0) return 0;
	if (a + b < 4) return 0;
	if (a + b == 4) return 1;
	if (a == b) return a / 2;
	if (min(a, b) * 3 <= max(a, b)) return min(a, b);

	int x = ( max(a, b) - min(a, b) ) / 2;
	return x + ( min(a, b) - x ) / 2;
}

int main() {

	int n;
	cin >> n;

	vector<int> v;
	v.reserve(n);

	for (unsigned int i = 0; i < n; i++) {
		int a, b;
		cin >> a;
		cin >> b;
		v.push_back(get_teams(a, b));
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
	
	return 0;
}










