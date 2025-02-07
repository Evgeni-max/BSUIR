#include <iostream>

class IntArray
{
public:
    IntArray(unsigned size) : data{ new int[size] } {}  // выделяем память
    ~IntArray()
    {
        if (data)
        {
            std::cout << "Freeing memory..." << std::endl;
            delete[] data;      // освобождаем память
        }
    }
    // Удаляем конструктор копирования и оператор присваивания
    IntArray(const IntArray&) = delete;
    IntArray& operator=(const IntArray&) = delete;

    // оператор индексирования для доступа к элементам
    int& operator[](unsigned index) { return data[index]; }

    // возвращаем инкапсулированный ресурс
    int* get() const { return data; }
    // передаем ресурс другогому объекту
    int* release()
    {
        int* result = data;
        data = nullptr;
        return result;
    }
private:
    int* data;
};

int main()
{
    const unsigned count{ 5 };   // количество элементов
    IntArray array{ count };     // создаем объект, который управляет ресурсом

    // изменяем элементы динамического массива
    for (unsigned i{}; i < count; ++i)
    {
        array[i] = i;
    }

    for (unsigned i{}; i < count; ++i)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
    // получаем указатель
    int* data = array.release(); // теперь функция main обязана освободить память

    for (unsigned i{}; i < count; ++i)
    {
        std::cout << data[i] << "\t";
    }
    std::cout << std::endl;

    //освобожадем память
    delete[] data;
}