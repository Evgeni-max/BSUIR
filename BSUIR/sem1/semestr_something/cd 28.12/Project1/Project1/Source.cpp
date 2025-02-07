#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void foo() {
        std::cout << "Derived::foo()" << std::endl;
    }
};

int main() {
    Base* p = new Base();
    Derived* q = dynamic_cast<Derived*>(p); // ������� �������������� ��������� �� ������� ����� � ��������� �� ����������� �����
    if (q != nullptr) {
        q->foo(); // ����� ������� foo() �� ������ Derived
    }
    else {
        std::cout << "Invalid cast" << std::endl; // ����� ��������� �� ������ ��������������
    }
}
