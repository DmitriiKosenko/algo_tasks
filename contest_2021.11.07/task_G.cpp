/*


Водители Яндекс.Такси узнали о раздаче бонусов и выстроились перед офисом. У каждого водителя есть рейтинг. Необходимо раздать водителям бонусы, соблюдая следующие условия:
• Сумма бонуса кратна 500 рублям.
• Каждый водитель должен получить как минимум 500 рублей.
• Водитель с бóльшим рейтингом должен получить бóльшую сумму бонуса, чем его соседи слева или справа с меньшим рейтингом.

Какое минимальное количество денег потребуется на бонусы?
Формат ввода

На первой строчке записано число N (1 <= N <= 20000), далее следует N строчек с рейтингами водителей Rn (0 <= Rn < 4096)
Формат вывода

Ответ должен содержать минимально необходимое количество денег для выплаты вознаграждений 

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
#include <sstream>

using namespace std;

int main() {

	unsigned int n;
	vector<int> t;

	cin >> n;

	t.reserve(n);
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		t.push_back(temp);
	}

	sort(t.begin(), t.end());

	long sum = 500;
	int amount = 500;
	int prev = t[0];
	for (int i = 1; i < t.size(); i++) {
		if (t[i] == prev) {
			sum = sum + amount;
		} else {
			prev = t[i];
			amount = amount + 500;
			sum = sum + amount;
		}
	}
	
	cout << sum << endl;

	return 0;
}