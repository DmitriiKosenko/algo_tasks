/*
Дан массив из нулей и единиц.
Нужно определить, какой максимальный по длине подинтервал единиц можно получить, удалив ровно один элемент массива.
size_t maxOnes(const std::vector<int>& v);

assert(maxOnes({0, 0}) == 0);
assert(maxOnes({1, 0}) == 1);
assert(maxOnes({0, 1}) == 1);
assert(maxOnes({1, 0, 1, 1, 0}) == 3);
assert(maxOnes({1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1}) == 5);
assert(maxOnes({1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}) == 6);

assert(maxOnes({1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1}) == 6);
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t maxOnes(const std::vector<int>& v) {
    if (v.size() == 0) return 0;
    if (v.size() == 1) return (v[0] == 1 ? 1 : 0);
    
    int index1 = -1;
    int index2 = -1;
    bool del = false;
    int result = 0;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            if (index1 == -1) {
                index1 = i;
            } else if (del) {
                index2 = i;
                del = false;
            }
        } else {
            if (index1 != -1) {
                if (index2 == -1) {
                    if (! del) {
                        del = true;
                    } else {
                        result = max(result, i - 1 - index1);
                        index1 = -1;
                        del = false;
                    }
                } else {
                    result = max(result, i - index1 - 1);
                    index1 = index2;
                    del = true;
                    index2 = -1;
                }
            }
        }
    }

    if (index1 != -1) {
        if (del) {
            result = max(result, (int)(v.size() - 1 - index1));
        } else {
            if (index2 != -1) {
                result = max(result, (int)(v.size() - index1 - 1));
            } else {
                result = max(result, (int)(v.size() - index1));
            }
        }
    }
    
    return (size_t)result;
}

int main() {

    vector<int> v0 = {0, 0};
    vector<int> v1 = {1, 0};
    vector<int> v2 = {0, 1};
    vector<int> v3 = {1, 0, 0, 1, 1, 0};
    vector<int> v4 = {1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1};
    vector<int> v5 = {1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1};
    
    cout << maxOnes(v0) << " : 0" << endl;
    cout << maxOnes(v1) << " : 1" << endl;
    cout << maxOnes(v2) << " : 1" << endl;
    cout << maxOnes(v3) << " : 2" << endl;
    cout << maxOnes(v4) << " : 5" << endl;
    cout << maxOnes(v5) << " : 6" << endl;

    return 0;
}


