#include"vec.cpp"
#include"iter.cpp"
#include<vector>
#include<typeinfo>

using namespace std;

void print(vector<int> v)
{
	auto s = v.begin();
	auto e = v.end();

	while(s != e)
	{
		cout << *(s++) << ", ";
	} cout << endl;
}

int main() 
{
	Vec<int> v1, v2;

	for(int i = 0; i < 12; i++)
		v1.push_back(i+1);
	for(int i = 0; i < 12; i++)
		v2.push_back(i+10);

	v1.print();
	v2.print();
	cout << endl;

	v1.swap(v2);

	auto it1 = v1.begin();
	auto end1 = v1.end();
	auto it2 = v2.begin();
	auto end2 = v2.end();

	int *arr = new int[5];
	for (size_t i = 0; i < 5; i++)
	{
		arr[i] = i * 10;
	}
	
	int *b, *e;
	b = arr;
	e = &arr[5];
	
	v1.assign(b,e);
	cout << v1;
	delete[] arr;

	v1.assign(initializer_list({11,22,33,44,55}));
	cout << v1 << endl;


	auto cit = v1.begin();

	cout << *cit;

	*cit = 1100010101;

	cout << v1;


	std::vector<int> nums {1, 2, 4, 8, 16};
	auto vcit = nums.cbegin();
	


/*
	vector<int> v1, v2;

	for(int i = 0; i < 4; i++)
		v1.push_back(i+1);
	for(int i = 0; i < 7; i++)
		v2.push_back(i+10);

	auto it1 = v1.begin();
	auto end1 = v1.end();
	auto it2 = v2.begin();
	auto end2 = v2.end();
		
	cout << "1:" << endl;
	while (it1 != end1) {
		cout << *(it1++) << ", ";
	}cout << endl;
	
	cout << "2:" << endl;
	while (it2 != end2) {
		cout << *(it2++) << ", ";
	} cout << endl;

	auto it = v2.begin();
	++++it;

	v1.insert(it, 100);
	print(v1);
	cout << endl;

	v1.assign(5, 100);
	print(v1);
*/


	return 0;
}