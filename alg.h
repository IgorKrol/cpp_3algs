#pragma once
#include <algorithm>
#include <iostream>
using namespace std;

/*	this function returns median over each n elements
	changes origin, returns end of new iteraor */
template<class T>
T Median(T begin, T end, int n) {
	if ((end - begin) % n == 0 && n > 1) {
		T it = begin;
		if (n % 2 == 1) {
			while (it != end) {
				sort(it, it + n);
				*begin = *(it + (n / 2));
				it = it + n;
				begin++;
			}
		}
		else {
			while (it != end) {
				sort(it, it + n);
				*begin = (*(it + (n / 2)) + *(it + (n / 2) - 1))/2;
				it = it + n;
				begin++;
			}
		}
		*begin = *end;
		return begin;
	}
	return end;
}

/*	this function swaps every two elements ([1,2,3,4] - > [2,1,4,3])
	return end */
template<class T>
T Transpose(T begin, T end) {
	while (begin != end && begin != (end - 1)) {
		iter_swap(begin, begin+1);
		begin += 2;
	}
	if (begin == end) {
		return end;
	}
	else {
		return end - 1;
	}
}

/*	this function computes with given function 'fun' each 2 elements, changes origin
	return end of new iterator	*/
template<class T, class Y>
T Transformations(T begin, T end, Y fun) {
	if ((end - begin) % 2 == 1 || end - begin == 0) {
		return end;
	}
	else {
		auto it = begin;
		while (it != end) {
			auto res = fun(*it, *(it + 1));
			*begin = res;
			begin++;
			it += 2;
		}
		*begin = *end;
		return begin;
	}
}