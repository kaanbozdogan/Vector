#include"vec.cpp"
#include"iter.cpp"
#include<vector>
#include<typeinfo>

using namespace std;



int main() 
{
	Vec<int> v1, v2;

	cout << "-> v1 = Vec();" << endl;
	v1 = Vec<int>();
	cout << v1;

	cout << endl << "-> v1 = Vec(12, 3);" << endl;
	v1 = Vec(12, 3);
	cout << v1;
/*
	cout << endl << "-> " << endl;
	v2 = Vec(v1.begin(), v1.end());
	cout << v2;
*/
	cout << endl << "-> v2 = Vec(v1);" << endl;
	v2 = Vec(v1);
	cout << v2;

	cout << endl << "-> v1 = Vec({11,22,33,44});" << endl;
	v1 = Vec({11,22,33,44});
	cout << v1;

	cout << endl << "-> v2 = Vec(move(v1));" << endl;
	v2 = Vec(move(v1));
	cout << v2;

	cout << endl << "-> int arr[4] = {1,2,3,4,5,6,7};" << endl << "-> v1 = Vec(&arr[0], &arr[7]);" << endl;
	int arr[7] = {1,2,3,4,5,6,7};
	v1 = Vec(&arr[0], &arr[7]);
	cout << v1;
	
	cout << endl << "-> v2 = v1;" << endl;
	v2 = v1;
	cout << v2;

	cout << endl << "-> v1.push_back(101);" << endl;
	v1.push_back(101);
	cout << v1;

	cout << endl << "-> v2 = move(v1);" << endl;
	v2 = move(v1);
	cout << v2;

	cout << endl << "-> v2.pop_back();" << endl;
	v2.pop_back();
	cout << v2;

	cout << endl << "-> v2.reserve(8);" << endl;
	v2.reserve(8);
	cout << v2;

	cout << endl << "-> v2.reserve(12);" << endl;
	v2.reserve(12);
	cout << v2;

	cout << endl << "-> v2.shrink_to_fit();" << endl;
	v2.shrink_to_fit();
	cout << v2;

	cout << endl << "-> v2.assign(5, 99);" << endl;
	v2.assign(5, 99);
	cout << v2;
		
	cout << endl << "-> v2.clear();" << endl;
	v2.clear();
	cout << v2;

	cout << endl << "-> v2.assign({5,4,3,2,1,0,-1});" << endl;
	v2.assign({5,4,3,2,1,0,-1});
	cout << v2;

	cout << endl << "-> v1.assign(&arr[0], &arr[7]);" << endl;
	v1.assign(&arr[0], &arr[7]);
	cout << v1;
	
	cout << endl << "-> v2[3]: " << v2[3] << endl;

	cout << endl << "-> v1.swap(v2);" << endl;
	v1.swap(v2);
	cout << "v1: " << v1;
	cout << "v2: " << v2;

	cout << endl << "-> v1.resize(3);" << endl;
	v1.resize(3);
	cout << v1;

	cout << endl << "-> v1.resize(7, 99);" << endl;
	v1.resize(7, 99);
	cout << v1;

	cout << endl << "-> iterating v2 using iterators" << endl;
	auto it1 = v2.begin();
	auto it2 = v2.end();
	
	while (it1 != it2)
		cout << *(it1++) << ", ";
	cout << endl;

	cout << endl << "-> v2.insert(++++(v2.begin()), -99);" << endl;
	v2.insert(++++(v2.begin()), -99);
	cout << v2;

	cout << endl << "-> v2.insert(++++(v2.begin()), v1.begin(), ----(v1.end()));" << endl;
	v2.insert(++++(v2.begin()), v1.begin(), ----(v1.end()));
	cout << v2;
	
	cout << endl << "-> v2.erase(++++++(v2.begin()));" << endl;
	v2.erase(++++++(v2.begin()));
	cout << v2;

	cout << endl << "-> v2.erase(++++++v2.begin(), ------v2.end());" << endl;
	v2.erase(++++++v2.begin(), ------v2.end());
	cout << v2;

	cout << endl << "-> v1 = {2,4,6,8,12,3,4,4,5,6,6,7};" << endl;
	v1 = {2,4,6,8,12,3,4,4,5,6,6,7};
	cout << v1;

	v2 = {0,1,2,3,4,5,6,7,8};
	auto v1_beg = v1.begin();
	auto v1_end = v1.end();
	auto v2_beg = v2.begin();
	auto v2_end = v2.end();

	cout << endl << "v2: " << v2;
	
	cout << endl << "v1_beg = v1.begin();"
		<< endl << "v1_end = v1.end();"
		<< endl << "v2_beg = v2.begin();"
		<< endl << "v2_end = v2.end();"<< endl;
	
	cout << endl << "-> v2_beg[4]: " << v2_beg[4] << endl;
	cout << "-> v2_end - v2_beg: " << v2_end - v2_beg << endl;
	cout << "-> *(v2_beg + 2): " << *(v2_beg + 2) << endl;
	cout << "-> *(v2_end - 2): " << *(v2_end - 2) << endl << endl;
	
	cout << "v2_beg < v2_end: ";
	if (v2_beg < v2_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "v2_beg > v2_end: ";
	if (v2_beg > v2_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "v2_beg < v1_end: ";
	if (v2_beg < v1_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << endl;

	cout << "v2_beg <= v2_end: ";
	if (v2_beg <= v2_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "v2_beg >= v2_end: ";
	if (v2_beg >= v2_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "v2_beg <= v1_end: ";
	if (v2_beg <= v1_end)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	cout << "v2_beg >= v2.begin(): ";
	if (v2_beg >= v2.begin())
		cout << "true" << endl;
	else
		cout << "false" << endl;

	




	return 0;
}

/*
	cout << ": ";
	if ()
		cout << "true";
	else
		cout << "false";

	cout << endl << "-> : " <<  << endl;

	cout << endl << "-> " << endl;
	cout << v2;


	cout << endl << "-> " << endl;
	v1 = Vec(v2.begin(), v2.end());
	cout << v1;
*/