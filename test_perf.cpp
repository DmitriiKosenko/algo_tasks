
#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <chrono>

using namespace std;

int main() {

	vector<int> foo;
	list<int> bar;

	for (int i = 0; i < 100000; i++) {
		foo.push_back(i + 1);
		bar.push_back(i + 2);
	}
	// for (int i = 0; i < 100000; i++) {
	// 	foo.push_back(i + 1);
	// 	bar.push_back(i + 2);
	// }
	// for (int i = 0; i < 100000; i++) {
	// 	foo.push_back(i + 1);
	// 	bar.push_back(i + 2);
	// }
	// for (int i = 0; i < 100000; i++) {
	// 	foo.push_back(i + 1);
	// 	bar.push_back(i + 2);
	// }
	// for (int i = 0; i < 100000; i++) {
	// 	foo.push_back(i + 1);
	// 	bar.push_back(i + 2);
	// }

	auto start1 = chrono::high_resolution_clock::now();
	stringstream stream1;
	for (int i = 0; i < 1000000; i++) {
		stream1 << "el " << i << " = " << foo[i] << endl;
	}
	auto stop1 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
  
	cout << "For vector: " << duration1.count() << endl;


	auto start2 = chrono::high_resolution_clock::now();
	stringstream stream2;
	auto it = bar.begin();
	for (int i = 0; i < 1000000; i++) {
		if (it != bar.end()) {
			stream2 << "el " << i << " = " << *it << endl;
		}
		it++;
	}
	auto stop2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);

	cout << "For list: " << duration2.count() << endl;

	
	return 0;
}