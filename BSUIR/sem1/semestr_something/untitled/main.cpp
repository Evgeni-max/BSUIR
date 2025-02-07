/*
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
            p = static_cast<element*>(p->_last);
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
        explicit element(baseElement* next, baseElement* last, T&& value) : baseElement(next, last){
            _value = std::forward<T>(value);
        }
        explicit element(element* element1){
            _value = std::forward<T>(element1->_value);
            this->_next = element1->_next;
            this->_last = element1->_last;
        }
        ~element() {
            _value.~T();
        }
        operator baseElement() const {return baseElement(this->_next, this->_last);}
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

    iterator insert(iterator& pos, T&& value) {
        element* newel = new element(&(*pos), pos->_last, std::forward<T>(value));
        pos->_last->_next = newel;
        pos->_last = newel;
        --pos;
        return iterator(pos);
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

    iterator erase(iterator& pos) {
        ++pos;
        pos->_last = pos->_last->_last;
        pos->_last->_next->~baseElement();
        pos->_last->_next = &(*pos);
        return pos;
    }

    static void splice(iterator& from_beg, iterator& from_end, iterator& to_beg) {
        --from_end;
        from_beg->_last->_next = &(*from_end);
        from_end->_last =  from_beg->_last;

        from_beg->_last = to_beg->_last;
        to_beg->_last->_next = &(*from_beg);
        from_end->_next = &(*to_beg);
        to_beg->_last = &(*from_end);
    }
};
int main() {
    List<int> arr;
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(23);
    auto a1 = arr.push_back(17);
    arr.push_back(110);
    arr.push_back(231);
    arr.push_back(743);
    arr.push_back(1340);
    arr.push_back(2353);
    arr.push_back(712);
    arr.push_back(101);
    arr.push_back(2378);

    List<int> li;
    li.push_back(9);
    li.push_back(19);
    li.push_back(29);
    auto a2 = li.push_back(67);
    li.push_back(146);
    li.push_back(287);
    li.push_back(746);
    li.push_back(146);
    li.push_back(235);
    li.push_back(58);
    auto a3 = li.push_back(11024);
    li.push_back(24571);

    List<int>::splice(a2, a3, a1);

    for (auto i = arr.begin(); i != arr.end(); ++i) {
        std::cout << i->_value << ' ';
    }
}
*/

#include <fstream>
#include "iostream"
#include "chrono"
#include "tree.h"
#include "newtree.h"
#include "algorithm"
class RBTree {
private:
    struct element {
        element* parent;
        element* leftChild;
        element* rigthChild;

        bool isRed;
    };
public:

};

template<typename T>
class BinTree {
private:
    struct element;
    class iterator {
    private:
        element* p;
    public:
        explicit iterator(element* value) {
            p = value;
        }
        ~iterator() = default;
        void left() {
            p = p->leftChild;
        }
        void right() {
            p = p->rigthChild;
        }
        void operator --() {
            p = p->parent;
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
        iterator& operator =(iterator second_iter) {
            this->p = &(*second_iter);
            return *this;
        }

        bool is_null() {
            return p == nullptr;
        }
    };

    struct element {
        element* parent;
        element* leftChild;
        element* rigthChild;

        size_t heigth;
        T value;

        ~element() {
            value.~T();
        }
        element() {

        }
        explicit element(T&& value, element* parent) {
            this->leftChild = nullptr;
            this->rigthChild = nullptr;
            this->value = std::forward<T>(value);
            this->parent = parent;
        }
    };
    element head;

    void insert(T&& value, element* pos) {
        if (pos->value > value) {
            if (pos->leftChild != nullptr) insert(std::forward<T>(value), pos->leftChild);
            else { pos->leftChild = new element(std::forward<T>(value), pos); ++sz; }
        }
        else if(pos->value < value) {
            if (pos->rigthChild != nullptr) insert(std::forward<T>(value), pos->rigthChild);
            else { pos->rigthChild = new element(std::forward<T>(value), pos); ++sz; }
        }
        else return;
    }

    void insert(T& value, element* pos) {
        if (pos->value > value) {
            if (pos->leftChild != nullptr) insert(std::forward<T>(value), pos->leftChild);
            else { pos->leftChild = new element(std::forward<T>(value), pos); ++sz; }
        }
        else if(pos->value < value) {
            if (pos->rigthChild != nullptr) insert(std::forward<T>(value), pos->rigthChild);
            else { pos->rigthChild = new element(std::forward<T>(value), pos); ++sz; }
        }
        else return;
    }

    size_t sz;
public:

    BinTree() {
        head = nullptr;
        sz = 0;
    }
    explicit BinTree(T&& value) {
        head = element(std::forward<T>(value), nullptr);
        sz = 1;
    }

    iterator begin() {
        iterator pos(&head);
        while(pos->leftChild != nullptr) {
            pos.left();
        }
        return pos;
    }
    iterator end() {
        iterator pos(&head);
        while(pos->rigthChild != nullptr) {
            pos.right();
        }
        return pos;
    }

    void _each(element* a) {
        if (a != nullptr) {
            _each(a->leftChild);
            std::cout << a->value << ' ';
            _each(a->rigthChild);
        }
    }

    int heigth_difference(element* pos) {
        bool has_left_child = pos->leftChild != nullptr;
        bool has_rigth_child = pos->rigthChild != nullptr;

        if (has_left_child && has_rigth_child) return pos->leftChild->heigth - pos->rigthChild->heigth;
        else if (has_left_child) return  pos->leftChild->heigth;
        else if (has_rigth_child) return - pos->rigthChild->heigth;
        else return 0;
    }

    bool is_rigth_child(element* pos) {
        if (pos->parent != nullptr) {
            if (pos->parent->value > pos->value) {
                return false;
            }
            else {
                return true;
            }
        }
    }

    void simple_left_rotation(element* pos) {
        pos->rigthChild->parent = pos->parent;
        bool rigth_is_child = is_rigth_child(pos);
        if (rigth_is_child) {
            pos->parent->rigthChild = pos->rigthChild;
        }
        else {
            pos->parent->leftChild = pos->rigthChild;
        }

        pos->rigthChild = pos->rigthChild->leftChild;
        pos->rigthChild->parent;
        pos->rigthChild->parent = pos;

        if (rigth_is_child) pos->parent = pos->parent->rigthChild;
        else pos->parent = pos->parent->leftChild;

        pos->parent->leftChild = pos;
    }

    void hard_left_rotation(element* pos) {
        element* copy_b = pos->rigthChild;
        element* copy_c = pos->rigthChild->leftChild;

        pos->rigthChild->leftChild = pos->rigthChild->leftChild->rigthChild;
        copy_c->rigthChild->parent = pos->rigthChild;
        pos->rigthChild = copy_c->leftChild;
        copy_c->leftChild->parent = pos;
        copy_c->parent = pos->parent;

        if (is_rigth_child(pos)) pos->parent->rigthChild = copy_c;
        else pos->parent->leftChild = copy_c;

        copy_c->leftChild = pos;
        pos->parent = copy_c;
        copy_c->rigthChild = copy_b;
        copy_b->parent = copy_c;
    }

    void for_() {
        _each(&head);
        std::cout << std::endl;
    }

    iterator find(T&& value) {
        iterator pos(&head);
        while (true) {
            if (pos->value > value) {
                if (pos->leftChild != nullptr) pos.left();
                else {
                    return static_cast<iterator>(nullptr);
                }
            }
            else if(pos->value < value) {
                if (pos->rigthChild != nullptr) pos.right();
                else return static_cast<iterator>(nullptr);
            }
            else return pos;
        }
    }
    void insert(T&& value) {
        if (sz == 0) head = element(std::forward<T>(value), nullptr);
        else insert(std::forward<T>(value), &head);
    }
    void insert(T& value) {
        if (sz == 0) head = element(std::forward<T>(value), nullptr);
        else insert(std::forward<T>(value), &head);
    }

    void erase(T&& value) {
        auto pos = find(value);

        if (pos != static_cast<iterator>(nullptr)) {
            bool has_left_child = pos->leftChild != nullptr;
            bool has_rigth_child = pos->rigthChild != nullptr;

            if (has_left_child && has_rigth_child) {
                auto copy_pos = pos;
                pos.right();
                while (pos->leftChild != nullptr) {
                    pos.left();
                }

                copy_pos->value = pos->value;
            }
            else {
                if (has_left_child) {
                    if (pos->parent->value > pos->value) {
                        pos->parent->leftChild = pos->leftChild;
                        pos->leftChild->parent = pos->parent;
                    }
                    else {
                        pos->parent->rigthChild = pos->leftChild;
                        pos->leftChild->parent = pos->parent;
                    }
                }
                else if (has_rigth_child) {
                    if (pos->parent->value > pos->value) {
                        pos->parent->leftChild = pos->rigthChild;
                        pos->rigthChild->parent = pos->parent;
                    }
                    else {
                        pos->parent->rigthChild = pos->rigthChild;
                        pos->rigthChild->parent = pos->parent;
                    }
                }
            }

            pos->~element();
            &(*pos) = nullptr;
        }
    }
};
int main() {
    nTree tr;

    int *a=new int [1000000];
    std::fstream fs;
    fs.open("numbers1.txt");
    if (fs.is_open()) {
        std::string buf;
        for (int i = 0; i < 1000000; ++i) {
            fs >> buf;
            int buffer = 0;
            for (int j = 0; j < buf.length(); ++j) {
                buffer *= 10;
                buffer += buf[i] - '0';
            }
            a[i] = buffer;
            buffer = 0;
        }
    }

    auto point1 = std::chrono::system_clock::now();
    for (int i = 0; i < 30; ++i) {
        tr.ins(a[i]);
        //tr.ins(i);
    }
    auto point2 = std::chrono::system_clock::now();
    std::cout << "N_tree:\n" << std::chrono::duration_cast<std::chrono::nanoseconds>(point2 - point1).count() << '\n';

    Tree tree1;
    auto point3 = std::chrono::system_clock::now();
    for (int i = 0; i < 30; ++i) {
        tree1.ins(a[i]);
        //tree1.ins(i);
    }
    auto point4 = std::chrono::system_clock::now();
    std::cout << "AVL_tree:\n" << std::chrono::duration_cast<std::chrono::nanoseconds>(point4 - point3).count();

}
