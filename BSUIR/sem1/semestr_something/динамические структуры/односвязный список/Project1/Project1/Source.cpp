#include <iostream>

template<typename T>
class List {
public:
    List();
    ~List();
    void push_back(T data);
    int size() { return size; };
    T& operator[](const int index);
private:
    template<typename T>
    class cell {
    public:
        cell* next_cell;
        T data;

        cell(cell* next_cell, T data) {
            this->data = data;
            this->next_cell = next_cell;
        }
    };
    int Size;
    cell<T> * head;
};

template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {

}

template<typename T>
void List<T>::push_back(T data) {
    cell* current = head;

    if(current)
}

template<typename T>
T& List<T>::operator[](const int index) {
    int counter = 0;
    cell<T>* current = head;
    while (current->next_cell != nullptr) {
        if (counter == index) {
            return current->data;
        }

        current = current->next_cell;
        ++counter;
    }
}

int main() {
    List<int> l;
    l.push_back((int)20);
}