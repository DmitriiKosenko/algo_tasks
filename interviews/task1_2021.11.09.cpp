// Нужно реализовать функцию OneEditApart , 
// проверяющую, можно ли одну строку получить из другой не более, 
// чем за одно исправление (удаление, добавление, изменение символа):

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool one_edit_apart(const string& s1, const string& s2) {
    if (s1.length() == 0 && s2.length() == 0) return true;
    if (abs((int)s1.length() - (int)s2.length()) > 1) return false;
    if (s1 == s2) return true;

    bool flag = false;
    for (int i = 0; i < min(s1.length(), s2.length()); i++) {
        if (s1[i] != s2[i]) {
            if (flag) return false;

            if (s1.length() == s2.length()) {
                flag = true;
            } else {
                int j = i;
                while (1) { // not the best way to organize this cycle, but it's for fun :)
                    if (s1.length() > s2.length()) {
                        if (s1[j + 1] != s2[j]) return false;
                    } else {
                        if (s2[j + 1] != s1[j]) return false;
                    }
                    if (j == min(s1.length(), s2.length()) - 1) return true;
                    j++;
                }
            }
        }
    }
    
    return true;

}

int main() {

    cout << ( one_edit_apart("", "") ? "passed" : "failed" ) << endl;
    cout << ( one_edit_apart("a", "a") ? "passed" : "failed" ) << endl;
    cout << ( one_edit_apart("ab", "a") ? "passed" : "failed" ) << endl;
    cout << ( one_edit_apart("ba", "a") ? "passed" : "failed" ) << endl;
    cout << ( one_edit_apart("abc", "adc") ? "passed" : "failed" ) << endl;
    cout << ( one_edit_apart("abc", "abe") ? "passed" : "failed" ) << endl;

    cout << ( !one_edit_apart("abc", "add") ? "passed" : "failed" ) << endl;
    cout << ( !one_edit_apart("abc", "addas") ? "passed" : "failed" ) << endl;
    cout << ( !one_edit_apart("abc", "abee") ? "passed" : "failed" ) << endl;

    return 0;
}
