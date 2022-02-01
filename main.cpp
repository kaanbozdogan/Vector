#include"vec.cpp"
#include<vector>

using namespace std;


int main() 
{
/*
	Vec<int> v1, v2;

	for(int i = 0; i < 12; i++)
		v1.push_back(i+1);
	for(int i = 0; i < 12; i++)
		v2.push_back(i+1);

	v1.print();
	v2.print();
	cout << endl;

	auto it1 = v1.begin();
	auto it2 = v1.end();
	it2;

	while (it1 != it2)
	{
		cout << *it1 << ", ";
		it1++;
	}
	cout << endl;
	
	v1.resize(23, 1);

	v1.print();

	cout << v1[3] << endl; 

/*
//init
	int size = 5;	

	//represents vector data
	shared_ptr<int[]> p1(new int[size]); 
	//represents iterator data
	shared_ptr<int[]> p2 = p1;
 
	//init vector data
	for (size_t i = 0; i < size; i++)
		p1[i] = i;
	
	//check if iterator works
	for (size_t i = 0; i < size; i++)
		cout << p2[i] << ", ";
	cout << endl;

//realloc
	p1 = move(shared_ptr<int[]>(new int [size]));

//check
	//change values in vector
	for (size_t i = 0; i < size; i++)
		p1[i] = i*2;

	//check if iterator still points to vector
	for (size_t i = 0; i < size; i++)
		cout << p2[i] << ", ";
	cout << endl;
*/


	vector<int> v1, v2;

	for(int i = 0; i < 4; i++)
		v1.push_back(i+1);
	for(int i = 0; i < 7; i++)
		v2.push_back(i+10);

	
	v1.swap(v2);

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

	return 0;
}