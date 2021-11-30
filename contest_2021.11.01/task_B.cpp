/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int n;
	cin >> n;

	if (n <= 0) {
		cout << 0;
		return 0;
	}

	int result = 0;
	int pos = -1;

	for (unsigned int i = 0; i < n; i++) {
		int t;
		cin >> t;
		
		if (t == 0) {
			if (pos != -1) {
				result = max(result, (int) (i - pos));
				pos = -1;
			}
		} else {
			if (pos == -1) pos = i;
		}
	}
	if (pos != -1) {
		result = max(result, (int) (n - pos));
	}

	cout << result;
	
	return 0;
}