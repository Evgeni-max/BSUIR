#include <iostream>

template<typename T>
class List {
private:
    struct baseElement;
    struct element;
    class iterator {
    private:
        element* p;
    public:
        explicit iterator(element* value) {
            p = value;
        }
        ~iterator() {
            p->~element();
        }
        void operator ++() {
            p = static_cast<element*>(p->_next);
        }
        void operator --() {
            p = p->_last;
        }
        element& operator* () {
            return *p;
        }
        element* operator ->() {
            return p;
        }
        bool operator ==(iterator second_iter) {
            if (p == &(*second_iter)) return true;
            else return false;
        }
        bool operator !=(iterator second_iter) {
            if (p == &(*second_iter)) return false;
            else return true;
        }
    };

    struct baseElement {
        baseElement* _next;
        baseElement* _last;
        explicit baseElement(baseElement* next, baseElement* last) {
            _next = next;
            _last = last;
        }
        explicit baseElement() {
            _next = nullptr;
            _last = nullptr;
        }
    };

    struct element : baseElement {
        T _value;
        explicit element(baseElement* next, baseElement* last, T&& value) : baseElement(next, last) {
            _value = std::forward<T>(value);
        }
        explicit element(element* element1) {
            _value = std::forward<T>(element1->_value);
            this->_next = element1->_next;
            this->_last = element1->_last;
        }
        ~element() {
            _value.~T();
        }
        operator baseElement() const { return baseElement(this->_next, this->_last); }
    };

    baseElement head;
    size_t size;
public:
    explicit List(T&& value) {
        head = baseElement(nullptr, nullptr);
        element* el1 = element(&head, &head, std::forward<T>(value));
        head._next = el1;
        head._last = el1;
        size = 1;
    }
    explicit List() {
        head = baseElement(nullptr, nullptr);
        size = 0;
    }
    ~List() = default;

    iterator push_back(T&& value) {
        if (head._next == nullptr) {
            element* el1 = new element(&head, &head, std::forward<T>(value));
            head._next = el1;
            head._last = el1;
            ++size;
            return iterator(el1);
        }
        else {
            element* newel = new element(&head, head._last, std::forward<T>(value));
            head._last->_next = newel;
            head._last = newel;
            ++size;
            return iterator(newel);
        }
    }

    iterator pop_back() {
        head->_last->~element();
        head->_last = head->_last->_last;
        head->_last->_next = head;
        --size;
    }

    iterator insert(iterator pos, T&& value) {
        element* newel = new element(&(*pos), pos->_last, std::forward<T>(value));
        pos->_last->_next = newel;
        pos->_last = newel;
        return iterator(newel);
    }

    iterator begin() {
        return iterator(static_cast<element*>(head._next));
    }

    iterator end() {
        return iterator(static_cast<element*>(&head));
    }

    size_t getSize() {
        return size;
    }

    iterator erase(iterator pos) {
        ++pos;
        pos->_last = pos->_last->_last;
        pos->_last->_next->~baseElement();
        pos->_last->_next = &(*pos);
        return pos;
    }

};
int main() {
    List<int> arr;
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(23);
    auto a = arr.begin();
    ++a;
    //++a;
    a = arr.erase(a);
    arr.insert(a, 89);

    for (auto i = arr.begin(); i != arr.end(); ++i) {
        std::cout << i->_value << ' ';
    }
}