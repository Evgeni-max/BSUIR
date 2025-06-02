import math
import functools

# Lab 3 - Function Definitions and Implementation
# Developer: Мартынкевич Е.Д.
# Date of Development: 2025-03-27
# Version: 1.0

str_for_task4 = "So she was considering in her own mind, as well as she could, for the hot day made her feel very sleepy and stupid, whether the pleasure of making a daisy-chain would be worth the trouble of getting up and picking the daisies, when suddenly a White Rabbit with pink eyes ran close by her."

def task1(x, eps):
    """
    Function to calculate the logarithm of (1 - x) using an iterative series.
    Args:
        x (float): The value for the series.
        eps (float): The precision for the calculation.
    """
    sum_pred = 1e+10
    iter = 0
    sum = 0
    pref = -1

    for i in range(1, 500):
        if abs(sum - sum_pred) < eps:
            iter = i
            break
        sum_pred = sum
        pref *= x
        sum += pref / i

    print(f"x : {x}")
    print(f"n : {iter}")
    print(f"F(x) : {sum}")
    print(f"Math(x) : {math.log(1 - x)}")
    print(f"eps : {eps}")

def task2():
    """
    Function to subtract user-input integers from an initial value of 10000
    and print the sum after each subtraction.
    """
    sum = 10000
    sums = []

    while sum >= 0:
        while True:
            try:
                var = int(input("Введите целое число: "))
                break
            except ValueError:
                print("Ошибка: неправильный ввод")

        sum -= var
        sums.append(sum)

    print(f"Сумма на каждой итерации: {sums}")

def count_decorator(func):
    """
    Decorator
    """
    @functools.wraps(func)

    def wrapper():
        result = func()
        inp_str = func.inp_str
        total = sum(1 for _ in inp_str)
        print(f"Общее количество символов: {total}")
        return result

    return wrapper


@count_decorator
def task3():
    """
    Function to count the number of commas and spaces in a string entered by the user.
    Uses generator for counting.
    """
    task3.inp_str = input("Введите строку, в которой хотите посчитать количество запятых и пробелов: ")

    comma_count = sum(1 for char in task3.inp_str if char == ',')
    space_count = sum(1 for char in task3.inp_str if char == ' ')

    print(f"Количество запятых: {comma_count}")
    print(f"Количество пробелов: {space_count}")


def task4(str_parametr=str_for_task4):
    """
    Function to analyze words in a string: count words less than 7 characters,
    find the shortest word ending with 'a', and sort the words by length.
    Args:
        str_parametr (str): The input string to analyze (defaults to a sample string).
    """
    words = str_parametr.replace(',', '').split()

    count_short_words = sum(1 for word in words if len(word) < 7)

    shortest_word_ending_with_a = None
    for word in words:
        if word.endswith('a'):
            if shortest_word_ending_with_a is None or len(word) < len(shortest_word_ending_with_a):
                shortest_word_ending_with_a = word

    sorted_words = sorted(words, key=len, reverse=True)

    print(f"Число слов, длина которых меньше 7 символов: {count_short_words}")
    print(f"Самое короткое слово, заканчивающееся на 'a': {shortest_word_ending_with_a}")
    print("Слова в порядке убывания их длины:")
    for word in sorted_words:
        print(word)

def input_for_task5(list_of_vars):
    """
    Function to input floating point numbers into a list.
    Repeats until the user stops.
    Args:
        list_of_vars (list): List where the numbers will be added.
    """
    while True:
        need_more_vars = input("Вы хотите ввести еще числа?(Y-Да): ")

        if need_more_vars != "Y":
            break

        user_input = input("Введите вещественное число: ")

        try:
            number = float(user_input)
            print(f"Вы ввели число: {number}")
            list_of_vars.append(number)
        except ValueError:
            print("Ошибка: введите правильное вещественное число!")

def main_task5(list_of_vars):
    """
    Function to find the first and second negative numbers in the list and sum the positive ones between them.
    Args:
        list_of_vars (list): List of numbers to analyze.
    Returns:
        tuple: (found_first_negative, found_second_negative, sum_between_negatives)
    """
    if not list_of_vars:
        print("There are no elements, please add some")
        return None, None, None

    is_we_find_first_passive = False
    is_we_find_second_passive = False
    sum_of_positive_elements = 0

    for var in list_of_vars:
        if not is_we_find_first_passive:
            if var < 0:
                is_we_find_first_passive = True
        else:
            if var < 0:
                is_we_find_second_passive = True
                break
            else:
                sum_of_positive_elements += var

    return is_we_find_first_passive, is_we_find_second_passive, sum_of_positive_elements

def output_result(is_we_find_first_passive, is_we_find_second_passive, sum_of_positive_elements):
    """
    Function to output the results of Task 5.
    Args:
        is_we_find_first_passive (bool): Whether the first negative was found.
        is_we_find_second_passive (bool): Whether the second negative was found.
        sum_of_positive_elements (float): The sum of positive elements between the negatives.
    """
    if is_we_find_first_passive is None or is_we_find_second_passive is None or sum_of_positive_elements is None:
        print("Вы должны хотя бы один раз вызвать вторую функцию")
        return

    if not is_we_find_first_passive:
        print("В списке нет отрицательных элементов")
    elif not is_we_find_second_passive:
        print(f"В списке лишь один отрицательный элемент, сумма от него до конца списка: {sum_of_positive_elements}")
    else:
        print(f"Сумма чисел от первого до второго отрицательных элементов равна: {sum_of_positive_elements}")

def task5():
    """
    Main function to control the flow of Task 5, providing options to input data, process data, and output results.
    """
    is_we_find_first_passive = None
    is_we_find_second_passive = None
    sum_of_positive_elements = None
    list_of_vars = []

    while True:
        while True:
            try:
                comand = int(input("what do you want: \n1: input variables\n2: find first passive variable and sum between first and second passive elements\n3: output result\nanother: exit\n"))
                break
            except ValueError:
                print("Ошибка: неправильный ввод")

        if comand == 1:
            input_for_task5(list_of_vars)
        elif comand == 2:
            is_we_find_first_passive, is_we_find_second_passive, sum_of_positive_elements = main_task5(list_of_vars)
        elif comand == 3:
            output_result(is_we_find_first_passive, is_we_find_second_passive, sum_of_positive_elements)
        else:
            break

def even_numbers():
    for num in range(100):
        if num % 2 == 0:
            yield num

def main():
    """
    Main program loop to choose tasks and execute them. Keeps the program running until the user exits.
    """
    func = even_numbers()
    for _ in range(10):
        print(next(func))

    print(list(even_numbers()))
    """
    #original_func = task3.__wrapped__
    #original_func()

    while True:
        while True:
            try:
                comand = int(input("Какое задание вы хотите выполнить: "))
                break
            except ValueError:
                print("Ошибка: неправильный ввод")

        if comand == 1:
            x = 0
            eps = 0
            while True:
                try:
                    x = float(input("Введите x: "))
                    if abs(x) >= 1:
                        raise ValueError("x should be less than 1.")
                    break
                except ValueError as ve:
                    print(f"Ошибка: {ve}")

            while True:
                try:
                    eps = float(input("Введите eps: "))
                    break
                except ValueError:
                    print("Ошибка: неправильный ввод")

            task1(x, eps)
        elif comand == 2:
            task2()
        elif comand == 3:
            task3()
        elif comand == 4:
            task4()
        elif comand == 5:
            task5()
        else:
            break
   """
if __name__ == "__main__":
    main()
