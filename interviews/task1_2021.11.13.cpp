// Даны свёрнутые массивы. (значение, количество элементов). Найти скалярное произведение этих массивов
// Например:
// [(1, 3), (2, 4)] -> [1, 1, 1, 2, 2, 2, 2]
// [(-1, 7)] -> [-1, -1, -1, -1, -1, -1, -1]
// 
// [(1, 1000000000)], [(1, 1000000000)]

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
#include <sstream>

using namespace std;

int get_mult(const vector<pair<int, int>>& v1, const vector<pair<int, int>>& v2) {
    
    int sum = 0;
    
    int counter1 = 0;
    int counter2 = 0;
    int pos1 = 0;
    int pos2 = 0;
    while (pos1 < v1.size() && pos2 < v2.size()) {
        if (counter1 == 0) counter1 = v1[pos1].second;
        if (counter2 == 0) counter2 = v2[pos2].second;
        sum += v1[pos1].first * v2[pos2].first * min(counter1, counter2);
        if (counter1 == counter2) {
            pos1++;
            pos2++;
            counter1 = 0;
            counter2 = 0;
        } else {
            if (counter1 < counter2) {
                pos1++;
                counter1 = 0;
                counter2 = counter2 - counter1;
            } else {
                pos2++;
                counter2 = 0;
                counter1 = counter1 - counter2;
            }
        }
    }
    
    return sum;
}

int main() {

    return 0;
}
