#include"vec.cpp"
#include<vector>

using namespace std;


int main() 
{
/*
    Vec<int> v1;

    for(int i = 0; i < 12; i++)
        v1.push_back(i+1);

    v1.print();

    auto vit = v1.begin();

    //cout << *vit << endl << *(++vit) << endl;
*/

//init

    struct vec
    {
        std::shared_vec<int[]> data;
    };
    

    vec p1;
    p1.data = std::shared_vec<int[]>(new int[5]);
    vec* p2 = &p1;

   
    for (size_t i = 0; i < 5; i++)
    {
        p1.data[i] = i;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << (*p2).data[i] << ", ";
    }
    cout << endl;

//realloc
/*
    int* p = p1.get();
    delete[] p;
    p = new int[10];
    p1.reset(p);
*/

    p1.data = std::shared_vec<int[]>(new int [5]);

//check
    for (size_t i = 0; i < 5; i++)
        p1.data[i] = i*2;

    for (size_t i = 0; i < 5; i++)
        cout << (*p2).data[i] << ", ";
    cout << endl;


/*
    std::vector<int> v1, v2;
    int count = 5;
    for (size_t i = 0; i < count; i++)
        v1.push_back(i);

    auto it = v1.begin();

    for (size_t i = 0; i < count; i++)
        v1.pop_back();

    cout << v1.size() << endl;

    for (size_t i = 0; i < 100; i++)
        cout << *(it++) << ", ";
    cout << endl;
    
    v1.clear();
    for (size_t i = count; i > 0; i--)
        cout << *(--it) << "(" << i << "), ";
    cout << endl;
*/    


    return 0;
}