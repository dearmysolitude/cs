#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2)
{
	vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		if (*iter1 < *iter2)
		{
			merged.emplace_back(*iter1);
			iter1++;
		}
		else
		{
			merged.emplace_back(*iter2);
			iter2++;
		}
	}
	if (iter1 != arr1.end())
	{
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else
	{
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}
	return merged;
}

template<typename T>
vector<T> merge_sort(vector<T> arr)
{
	if (arr.size() > 1)
	{
		auto mid = size_t(arr.size() / 2);
		auto left_half = merge_sort<T>(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = merge_sort<T>(vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}
	return arr;
}

template<typename T>
void print_vector(vector<T> arr)
{
	for (auto i : arr) //
		cout << i << " ";
	cout << endl;
}

void run_merge_sort_test()
{
	vector<int> S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };

	cout << "정렬되지 않은 입력 벡터" << endl;
	print_vector<int>(S1);
	cout << endl;

	auto sorted_S1 = merge_sort<int>(S1);

	cout << "병합 정렬에 의해 정렬된 벡터: " << endl;
	print_vector<int>(sorted_S1);
}

int main() 
{
	run_merge_sort_test();
	return 0;
}