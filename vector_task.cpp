
#include <iostream>
/*
Условие: 
	Дан бинарный вектор. 
	Необходимо определить максимальную длину последовательности из подряд идущих единиц в этом векторе.

Замечания:
1. Не обязательно использовать счётчик. "Посчитать" не стоит воспринимать буквально. 
	Можно найти индекс начала и конца последовательности и найти длину через их разность.
	Использование счётчика не обоснованно и может добавлять коэффициенты в оценке сложности.
2. "Мы можем увидеть дублирования кода". Увидеть, конечно, можем, но его там нет. 
	2 раза вызывается функция max(...) - всё ок. Мне кажется, Алексей сам смеётся, когда говорит об этом.
	При переносе max(...) в условие if (n > 0), вызов этой функции будет в холостую каждый раз, 
	когда будет встречаться 1 в векторе.
3. В предложенном алгоритме при оценке сложности может появиться коэффициент 3 в случае, 
	если в векторе единиц много больше, чем нулей.
3. Обработка граничных условий не обязывает завязываться на них в реализации основного алгоритма. 
	Поэтому тезис о том, что не стоит проверять граничные условия, на мой взгляд, не корректен.
4. Можно добавить ещё случай, когда в векторе есть две и более последовательности одинаковой длины,
	причём одна из этих последовательностей находится в конце вектора.
*/

using namespace std;

int imax(int v1, int v2) {
	return v1 > v2 ? v1 : v2;
}

int count_seq_length(bool* vec, int vec_length) {
	int size = 0;
	int first = -1;

	if (vec_length == 0) return 0;
	if (vec_length == 1) return vec[0] ? 1 : 0;

	for (int i = 0; i < vec_length; i++) {
		if (vec[i] == 1) {
			if (first == -1) first = i;
		} else {
			if (first != -1) {
				size = imax(size, i - first);
				first = -1;
			}
		}
	}
	if (first == -1) return size;
	return imax(size, vec_length - first);
}

int main() {
	bool vec0[] = {0};
	bool vec1[] = {1};
	bool vec2[] = {};
	bool vec3[] = {1,1,1,1,1,1,1,1};
	bool vec4[] = {0,0,0,0,0,0,0,0};
	bool vec5[] = {0,0,0,0,1,1,1,1};
	bool vec6[] = {1,1,1,1,1,0,0,0};
	bool vec7[] = {0,1,1,1,1,1,0,0,1,1,1,1,1};
	bool vec8[] = {0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1};

	
	cout << "test 0: expect 0 = " << count_seq_length(vec0, sizeof(vec0)) << endl;
	cout << "test 1: expect 1 = " << count_seq_length(vec1, sizeof(vec1)) << endl;
	cout << "test 2: expect 0 = " << count_seq_length(vec2, sizeof(vec2)) << endl;
	cout << "test 3: expect 8 = " << count_seq_length(vec3, sizeof(vec3)) << endl;
	cout << "test 4: expect 0 = " << count_seq_length(vec4, sizeof(vec4)) << endl;
	cout << "test 5: expect 4 = " << count_seq_length(vec5, sizeof(vec5)) << endl;
	cout << "test 6: expect 5 = " << count_seq_length(vec6, sizeof(vec6)) << endl;
	cout << "test 7: expect 5 = " << count_seq_length(vec7, sizeof(vec7)) << endl;
	cout << "test 8: expect 10 = " << count_seq_length(vec8, sizeof(vec8)) << endl;

	return 0;
}