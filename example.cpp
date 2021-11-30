#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef struct ListNode ListNode;


int main() {

	int i = pow(2, 31) - 1;
	int j = -1 * pow(2, 31);
	cout << i << endl;
	cout << ( (i + 1) > 2147483647 ) << endl;
	cout << j << endl;
	cout << j - 1 << endl;

	int i1 = -2147483647;
	int i2 = -214748364;
	cout << i1 / 1000000000 << endl;
	cout << i2 / 1000000000 << endl;

	cout << i1 / 10 << endl;
	cout << i1 % 10 << endl;
	//-2147483648
	// 2147483647
	// 0123456789
	return 0;
}










