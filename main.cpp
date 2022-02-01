#include"vec.cpp"
#include<vector>

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
	v1.print();



	delete[] arr;
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
//


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