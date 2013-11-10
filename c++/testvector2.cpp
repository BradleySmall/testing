#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    // constructor
    A(int i) 
    { 
        // it always begins with this constructor
        // set the reference count to 1
        ptr = new int(i);
        ref = new int(1);

        cout << "CTOR    NEW " << *ptr << " - Ref Count = " << *ref << endl;
    }

    // copy constructor
    A(const A & other ) : ref(other.ref), ptr(other.ptr) 
    {   
        // in the copy constructor
        // no memory is allocated 
        // so just increment the reference count
        ++*ref;  

        cout << "CTOR   COPY " << *ptr << " - Ref Count = " << *ref << endl;
    }
   
    // Destructor 
    ~A()                             
    { 
        // it always ends with this destructor
        // decrement the reference count
        --*ref;
        cout << "DTOR        " <<  *ptr  << " - Ref Count = " << *ref;

        // when the reference count is 0 then 
        // delete the memory
        if(!*ref) 
        { 
            cout << " DELETE ";
            delete ptr ; 
            delete ref ; 
        } 

        cout << endl;
    }

private:
    int *ref;
    int *ptr;
};

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
