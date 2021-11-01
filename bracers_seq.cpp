
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

unsigned int count(unsigned int n) {
	return 0;
}

vector<string> generate(vector<string> input) {

	vector<string> output;
	for (unsigned int i = 0; i < input.size(); i++) {
		string v1 = '(' + input[i] + ')';
		string v2 = "()" + input[i];
		string v3 = input[i] + "()";

		output.push_back(v1);
		if (v2.compare(v1) != 0) output.push_back(v2);
		if (v3.compare(v1) != 0 && v3.compare(v2) != 0) output.push_back(v3);
	}

	return output;
}

vector<string> _generate(vector<string> input) {

	vector<string> output;
	for (unsigned int i = 0; i < input.size(); i++) {
		string v1 = '(' + input[i] + ')';
		string v2 = "()" + input[i];
		string v3 = input[i] + "()";

		bool is_duplicate_v1 = false;
		bool is_duplicate_v2 = v2.compare(v1) == 0;
		bool is_duplicate_v3 = v3.compare(v1) == 0 || v3.compare(v2) == 0;

		for (unsigned int j = 0; j < output.size(); j++) {
			if (!is_duplicate_v1) {
				if (output[j].compare(v1) == 0) is_duplicate_v1 = true;	
			}
			if (!is_duplicate_v2) {
				if (output[j].compare(v2) == 0) is_duplicate_v2 = true;
			}
			if (!is_duplicate_v3) {
				if (output[j].compare(v3) == 0) is_duplicate_v3 = true;
			}
		}

		if (!is_duplicate_v1) output.push_back(v1);
		if (!is_duplicate_v2) output.push_back(v2);
		if (!is_duplicate_v3) output.push_back(v3);
	}

	return output;
}


int main() {
	
	unsigned int n = 5;

	vector<string> result = {"()"};
	for (unsigned int i = 2; i <= n; i++) {
		result = generate(result);
	}

	for (unsigned int i = 0; i < result.size(); i++) {
		cout << i + 1 << " : " << result[i] << endl;
	}
	
	return 0;
}