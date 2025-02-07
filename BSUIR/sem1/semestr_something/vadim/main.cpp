#include <iostream>
class A  {
public:
    virtual void foo() {
        std::cout << "a";
    }
};
class B : public A {
public:
     void foo() override {
        std::cout << "b";
    }
};
class C : public A {
public:
     void foo() override {
        std::cout << "c";
    }
};
class D : public C, virtual public B {
public:
    /*virtual void foo() {
        std::cout << "d";
    }*/



};


int main() {
    D d;
    d.foo();

    return 0;
}
