#include "alg.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v = {1,2,3,10,8,6};
	auto p = [](const int x, const int y){return x + y;};
	auto vit = Transformations(v.begin(), v.end(), p);
	auto itB = v.begin();
	while (vit != itB) {
		cout << *itB << ", ";
		itB++;
	}
	cout << endl;
	return 0;
}