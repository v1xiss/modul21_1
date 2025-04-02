#include <iostream>
using namespace std;

template <typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;

public:
    base(T1 v1, T2 v2) : value1(v1), value2(v2) {
        cout << "base constructor called" << endl;
    }

    ~base() {
        cout << "base destructor called" << endl;
    }

    void displayBase() const { 
        cout << "base: value1 = " << value1 << ", value2 = " << value2 << endl;
    }
};
template <typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    child(T1 v1, T2 v2, T3 v3, T4 v4) : base(v1, v2), value3(v3), value4(v4) {
        cout << "child constructor called" << endl;
    }
    ~child() {
        cout << "child destructor called" << endl;
   }

    void displayChild() const { 
        displayBase();
        cout << "child: value3 = " << value3 << ", value4 = " << value4 << endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
public:
    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : child(v1, v2, v3, v4), value5(v5), value6(v6) {
        cout << "child2 constructor called" << endl;
    }
    ~child2() {
        cout << "child2 destructor called" << endl;
    }

    void displayChild2() const { // «м≥нено на public
        displayChild();
        cout << "child2: value5 = " << value5 << ", value6 = " << value6 << endl;
    }
};



int main() {
    base<int, double> b(10, 3.14);
    b.displayBase();
    child<int, double, string, char> c(20, 2.71, "hello", 'A');
    c.displayChild();
    child2<int, double, string, char, bool, int> c2(30, 1.61, "world", 'B', true, 42);
    c2.displayChild2();
    return 0;
}