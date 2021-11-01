
#include <iostream>
#include <vector>

// "XY" -> 1
// "YX" -> 1
// "OOOXOOYOXO" -> 2 // 3; 2
// "OOOXXOY" -> 2 // 3; 2

using namespace std;

int get_length(std::vector<char> array) {
    if (array.size() == 0 || array.size() == 1) return 0;

    char type = 'O';
    int index = -1;
    int dist = 0;

    for (unsigned int i = 0; i < array.size(); i++) {
        if (array[i] == 'X' || array[i] == 'Y') {
            if (index == -1) {
                index = i;
                type = array[i];
            } else {
                if (array[i] == type) {
                    index = i;
                } else {
                    if (dist == 0) {
                        dist = i - index;
                    } else {
                    	int diff = i - index;
                        dist = std::min(dist, diff);
                    }
                    index = i;
                    type = array[i];
                }
            }
        }
    }
    return dist;
}

int main() {

	unsigned int i = -1;cout << i << endl; // 4294967295

	cout << get_length({}) << endl;
	cout << get_length({'X'}) << endl;

	return 0;
}