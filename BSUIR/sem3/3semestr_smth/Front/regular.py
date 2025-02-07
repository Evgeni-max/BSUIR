import re

def replace_data_A(text, personal_data_list):
    result = '|'.join(personal_data_list)
    pattern = rf'(({result})\s*(?:\:|\=|\s{{2}})\s*).*?\n'
    def repl(match):
        return match.group(1) + '*' * (len(match.group(0)) - len(match.group(1)) - 1) + '\n'

    result = re.sub(pattern, repl, text)
    return result

def replace_data_B(text, personal_data_list):
    result = '|'.join(personal_data_list)
    pattern = rf'(({result})\s*(?:\:|\=|\s{{2}})\s*).*?\n'

    match = re.search(pattern, text)
    return match is not None

def replace_data_C(text, personal_data_list):
    result = '|'.join(personal_data_list)
    pattern = rf'(({result})\s*(?:\:|\=|\s{{2}})\s*).*?\n'
    def repl(match):
        return match.group(1) + '\n'

    result = re.sub(pattern, repl, text)
    return result
# def replace_FIO(text):
#     pattern = r'((Фамилия|Имя|Отчество|Пол|Дата рождения)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)
#
# def replace_Adress(text):
#     pattern = r'((Адрес прописки|Страна|Регион|Город|Улица|Номер дома)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)
#
# def replace_Pasport(text):
#     pattern = r'((Серия и номер паспорта|Код подразделения|Кем выдан)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)
#
# def replace_LoginPassword(text):
#     pattern = r'((Логин|Пароль)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)
#
# def replace_Card(text):
#     pattern = r'((номер счета|Имя владельца карты|Номер кредитной карты|Срок действия карты)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)
#
# def replace_University(text):
#     pattern = r'((Специальность|Направление|Учебное заведение|Серия/Номер диплома|Регистрационный номер)\s*(?:\:|\=|\s{2})\s*).*?\n'
#     return replace_data(text, pattern)


# Пример использования
text = """Принимайте\nФамилия   Никонова\nПол   Женщина\nДата рождения   05.06.1993
Специальность : Офтальмолог\nУчебное заведение : Пензенский государственный университет\nСерия/Номер диплома : 200315 7717085\nРегистрационный номер : 10-847-306
Адрес прописки : Россия, г. Улан-Удэ, Школьный пер., д. 11 кв.85\nСтрана : Россия\nГород : г. Якутск\nУлица : Мирная ул.\nНомер дома : 14
номер счета : 50250752100000006687\nИмя владельца карты : Ivan Fomenkov\nНомер кредитной карты : 4870 9793 2613 1249\n   Срок действия карты : 06/24"""


print(replace_data_B(text, ["Пароль", "Логин"]))
#print(replace_Card(text))
#print(replace_University(text))
#print(replace_Adress(text))
#print(replace_LoginPassword(text))