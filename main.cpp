#include"vec.cpp"
#include<vector>

using namespace std;

int main() 
{

    Vec<int> v1, v2;

    for(int i = 0; i < 12; i++)
        v1.push_back(i+1);
    for(int i = 0; i < 12; i++)
        v2.push_back(i+1);

    v1.print();
    v2.print();
    cout << endl;

    auto it1 = v1.begin();
    auto it2 = v1.begin();
    it2++;

    if (it1 < it2)
        cout << "true" << endl;
    else
        cout << "false" << endl;


/*
//init
    int size = 5;

    struct vec
    {
        shared_ptr<int[]> data;
        
        vec(int n) { data = shared_ptr<int[]>(new int[n]); }
    };
    

    //represents vector data
    vec p1(size); 
    //represents iterator data
    shared_ptr<shared_ptr<int[]>> p2(&(p1.data), [](shared_ptr<int[]>* ptr)
    {
        //no delete calls because ptr is allocated in stack
    });
 
    //init vector data
    for (size_t i = 0; i < size; i++)
        p1.data[i] = i;
    
    //check if iterator works
    for (size_t i = 0; i < size; i++)
        cout << (*p2)[i] << ", ";
    cout << endl;

//realloc    
    p1.data = shared_ptr<int[]>(new int [size]);

//check
    //change values in vector
    for (size_t i = 0; i < size; i++)
        p1.data[i] = i*2;

    //check if iterator still points to vector
    for (size_t i = 0; i < size; i++)
        cout << (*p2)[i] << ", ";
    cout << endl;
*/

/*
    vector<int> v1, v2;

    for(int i = 0; i < 12; i++)
        v1.push_back(i+1);
    for(int i = 0; i < 12; i++)
        v2.push_back(i+1);


    auto it1 = v1.begin();
    auto it2 = v2.begin();
    it1--;
    it1--;


    cout << *it1 << endl;
*/
    
    


    return 0;
}