#include <iostream>
#include <vector>
#include <sstream>


using namespace std;


int get_steps(int n) {
	if (n / 10 == 0) return (n % 2 == 0) ? 0 : -1;

	int counter = 0;
	int pos = -1;
	while (n != 0) {
		counter++;
		if ((n % 10) % 2 == 0) pos = counter;
		if (counter == 1 && pos == 1) return 0;
		n = n / 10;
	}

	if (pos == -1) return -1;
	if (pos == counter) return 1;
	return 2;
}

int main() {

	int n;
	cin >> n;

	vector<int> v;
	v.reserve(n);

	for (unsigned int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(get_steps(t));
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
	
	return 0;
}










