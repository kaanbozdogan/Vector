#include"vec.h"
#include<vector>


int main() 
{
	Vec<int> v1, v2;

	std::cout << "-> v1 = Vec();" << std::endl;
	v1 = Vec<int>();
	std::cout << v1;

	std::cout << std::endl << "-> v1 = Vec(12, 3);" << std::endl;
	v1 = Vec(12, 3);
	std::cout << v1;

	std::cout << std::endl << "-> v2 = Vec(v1);" << std::endl;
	v2 = Vec(v1);
	std::cout << v2;

	std::cout << std::endl << "-> v1 = Vec({11,22,33,44});" << std::endl;
	v1 = Vec({11,22,33,44});
	std::cout << v1;

	std::cout << std::endl << "-> v2 = Vec(std::move(v1));" << std::endl;
	v2 = Vec(std::move(v1));
	std::cout << v2;

	std::cout << std::endl << "-> int arr[4] = {1,2,3,4,5,6,7};" << std::endl << "-> v1 = Vec(&arr[0], &arr[7]);" << std::endl;
	int arr[7] = {1,2,3,4,5,6,7};
	v1 = Vec(&arr[0], &arr[7]);
	std::cout << v1;
	
	std::cout << std::endl << "-> v2 = v1;" << std::endl;
	v2 = v1;
	std::cout << v2;

	std::cout << std::endl << "-> v1.push_back(101);" << std::endl;
	v1.push_back(101);
	std::cout << v1;

	std::cout << std::endl << "-> v2 = std::move(v1);" << std::endl;
	v2 = std::move(v1);
	std::cout << v2;

	std::cout << std::endl << "-> v2.pop_back();" << std::endl;
	v2.pop_back();
	std::cout << v2;

	std::cout << std::endl << "-> v2.reserve(8);" << std::endl;
	v2.reserve(8);
	std::cout << v2;

	std::cout << std::endl << "-> v2.reserve(12);" << std::endl;
	v2.reserve(12);
	std::cout << v2;

	std::cout << std::endl << "-> v2.shrink_to_fit();" << std::endl;
	v2.shrink_to_fit();
	std::cout << v2;

	std::cout << std::endl << "-> v2.assign(5, 99);" << std::endl;
	v2.assign(5, 99);
	std::cout << v2;
		
	std::cout << std::endl << "-> v2.clear();" << std::endl;
	v2.clear();
	std::cout << v2;

	std::cout << std::endl << "-> v2.assign({5,4,3,2,1,0,-1});" << std::endl;
	v2.assign({5,4,3,2,1,0,-1});
	std::cout << v2;

	std::cout << std::endl << "-> v1.assign(&arr[0], &arr[7]);" << std::endl;
	v1.assign(&arr[0], &arr[7]);
	std::cout << v1;
	
	std::cout << std::endl << "-> v2[3]: " << v2[3] << std::endl;

	std::cout << std::endl << "-> v1.swap(v2);" << std::endl;
	v1.swap(v2);
	std::cout << "v1: " << v1;
	std::cout << "v2: " << v2;

	std::cout << std::endl << "-> v1.resize(3);" << std::endl;
	v1.resize(3);
	std::cout << v1;

	std::cout << std::endl << "-> v1.resize(7, 99);" << std::endl;
	v1.resize(7, 99);
	std::cout << v1;

	std::cout << std::endl << "-> iterating v2 using iterators" << std::endl;
	auto it1 = v2.begin();
	auto it2 = v2.end();
	
	while (it1 != it2)
		std::cout << *(it1++) << ", ";
	std::cout << std::endl;

	std::cout << std::endl << "-> v2.insert(++++(v2.begin()), -99);" << std::endl;
	v2.insert(++++(v2.begin()), -99);
	std::cout << v2;

	std::cout << std::endl << "-> v2.insert(++++(v2.begin()), v1.begin(), ----(v1.end()));" << std::endl;
	v2.insert(++++(v2.begin()), v1.begin(), ----(v1.end()));
	std::cout << v2;
	
	std::cout << std::endl << "-> v2.erase(++++++(v2.begin()));" << std::endl;
	v2.erase(++++++(v2.begin()));
	std::cout << v2;

	std::cout << std::endl << "-> v2.erase(++++++v2.begin(), ------v2.end());" << std::endl;
	v2.erase(++++++v2.begin(), ------v2.end());
	std::cout << v2;

	std::cout << std::endl << "-> v1 = {2,4,6,8,12,3,4,4,5,6,6,7};" << std::endl;
	v1 = {2,4,6,8,12,3,4,4,5,6,6,7};
	std::cout << v1;

	std::cout << std::endl << "-> v1 = Vec<int>(++v2.cbegin(), --v2.cend());" << std::endl;
	v1 = Vec<int>(++v2.cbegin(), --v2.cend());
	std::cout << v1;

	v2 = {0,1,2,3,4,5,6,7,8};
	auto v1_beg = v1.begin();
	auto v1_end = v1.end();
	auto v2_beg = v2.begin();
	auto v2_end = v2.end();

	std::cout << std::endl << "v2: " << v2;
	
	std::cout << std::endl << "v1_beg = v1.begin();"
		<< std::endl << "v1_end = v1.end();"
		<< std::endl << "v2_beg = v2.begin();"
		<< std::endl << "v2_end = v2.end();"<< std::endl;
	
	std::cout << std::endl << "-> v2_beg[4]: " << v2_beg[4] << std::endl;
	std::cout << "-> v2_end - v2_beg: " << v2_end - v2_beg << std::endl;
	std::cout << "-> *(v2_beg + 2): " << *(v2_beg + 2) << std::endl;
	std::cout << "-> *(v2_end - 2): " << *(v2_end - 2) << std::endl << std::endl;
	
	std::cout << "v2_beg < v2_end: ";
	if (v2_beg < v2_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "v2_beg > v2_end: ";
	if (v2_beg > v2_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "v2_beg < v1_end: ";
	if (v2_beg < v1_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << std::endl;

	std::cout << "v2_beg <= v2_end: ";
	if (v2_beg <= v2_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "v2_beg >= v2_end: ";
	if (v2_beg >= v2_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "v2_beg <= v1_end: ";
	if (v2_beg <= v1_end)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "v2_beg >= v2.begin(): ";
	if (v2_beg >= v2.begin())
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << std::endl << "*(v2_beg += 6): " << *(v2_beg += 6) << std::endl;
	std::cout << "*(v2_beg -= 3): " << *(v2_beg -= 3) << std::endl;




	return 0;
}
