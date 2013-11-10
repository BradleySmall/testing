#include <iostream>
#include <vector>
#include <map>

using namespace std;

class A {
public:
    // constructor
    A(int i) 
    { 
        // it always begins with this constructor
        // set the reference count to 1
        ptr = new int(i);
        ref[ptr] = 1;

        cout << "CTOR    NEW " << *ptr << " - Ref Count = " << ref[ptr] << endl;
    }

    // copy constructor
    A(const A & other ) : ptr(other.ptr) 
    {   
        // in the copy constructor
        // no memory is allocated 
        // so just increment the reference count
        ++ref[ptr];  

        cout << "CTOR   COPY " << *ptr << " - Ref Count = " << ref[ptr] << endl;
    }
   
    // Destructor 
    ~A()                             
    { 
        // it always ends with this destructor
        // decrement the reference count
        --ref[ptr];
        cout << "DTOR        " <<  *ptr  << " - Ref Count = " << ref[ptr] ;

        // when the reference count is 0 then 
        // delete the memory
        if(!ref[ptr]) 
        { 
            cout << " DELETE ";
            delete ptr ; 
        } 

        cout << endl;
    }

private:
    static map<int *, int> ref;
    int *ptr;
};
map<int *, int> A::ref;

int main ( void ) 
{
    A a(9);
    vector<A>vec;
    vec.push_back(a);
    vec.push_back(A(1));
    vec.push_back(A(2));
    vec.push_back(A(3));
    vec.push_back(A(4));
    vec.push_back(A(5));
    vec.push_back(A(6));
    vec.push_back(A(7));
    return 0;
}
