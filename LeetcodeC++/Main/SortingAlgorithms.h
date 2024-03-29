#pragma once
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>


// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class SortingAlgorithms 
{
public:
	static void merge(int arr[], int l, int mid, int r) {
		int n1 = mid - l + 1;
		int n2 = r - mid;

		int left[10], right[10];

		for (int i = 0; i < n1; i++)
			left[i] = arr[l + i];
		for (int j = 0; j < n2; j++)
			right[j] = arr[mid + j + 1];

		int i, j, k;
		i = 0;
		j = 0;
		k = l;

		while (i < n1 && j < n2)
		{
			if (left[i] <= right[j])
				arr[k++] = left[i++];
			else
				arr[k++] = right[j++];
		}

		while (i < n1)
			arr[k++] = left[i++];
		while (j < n2)
			arr[k++] = right[j++];
	}

	static void mergeSort(int arr[], int l, int r) {
		if (l >= r)
			return;

		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);

		merge(arr, l, mid, r);
	}

	static void bubbleSort(vector<int>& nums) {
		int n = nums.size();
		bool isSwapped;

		for (int i = 0; i < n; i++) {
			isSwapped = false;
			for (int j = 1; j < n - i; j++) {
				int a = nums[j - 1];
				int b = nums[j];
				if (nums[j - 1] > nums[j]) {
					swap(nums[j - 1], nums[j]);
					isSwapped = true;
				}
			}
			if (!isSwapped)
				break;
		}
	}

	static void selectionSort(vector<int>& nums) {
		int minIndex;
		int len = nums.size();

		for (int i = 0; i < len; i++)
		{
			minIndex = i;
			for (int j = i; j < len; j++)
			{
				if (nums[j] < nums[minIndex])
					minIndex = j;
			}

			swap(nums[minIndex], nums[i]);
		}
	}

	static void insertionSort(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i, temp = nums[i];

			while (j > 0 && nums[j - 1] > temp)
				nums[j] = nums[--j];

			nums[j] = temp;
		}
	}
};
