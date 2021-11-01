/*
Дан массив из нулей и единиц.
Нужно определить, какой максимальный по длине подинтервал единиц можно получить, удалив ровно один элемент массива.
size_t maxOnes(const std::vector<int>& v);

assert(maxOnes({0, 0}) == 0);
assert(maxOnes({1, 0}) == 1);
assert(maxOnes({0, 1}) == 1);
assert(maxOnes({1, 0, 1}) == 2);
assert(maxOnes({1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1}) == 5);
assert(maxOnes({1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1}) == 6);

assert(maxOnes({1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1}) == 6);
*/

#include <iostream>
#include <vector>

using namespace std;

size_t maxOnes(const std::vector<int>& v) {
    if (v.size() == 0) return 0;
    if (v.size() == 1) return (v[0] == 1 ? 1 : 0);
    
    int index = -1;
    size_t result;
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 1) {
            if (index == -1) index = i;
        } else {
            if (index != -1) {
                result = i - index;
                index = -1;
            }
        }
    }
    
    return result;
}

int main() {
    
    return 0;
}


