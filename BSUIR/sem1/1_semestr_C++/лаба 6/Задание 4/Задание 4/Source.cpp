#include <iostream>
#include <cstring>
#include <string>

void bigbukovki(std::string& str) {
	size_t lenght = str.length();
	std::string BIG = "CQWX";

	for (unsigned i{}; i < lenght; )
	{
		// �������� ������
		size_t position = str.find_first_of(BIG, i);
		// ���� �� ������� �� ������ ��������� � ������� i, ������� �� �����
		if (position == std::string::npos) break;

		str.erase(position, 1);
		--lenght;
		// ��������� � ���������� ������� ����� position
		i = position;
	}
}

void bukovki(std::string& str) {
	size_t lenght = str.length();
	std::string tests = "eiy";

	for (int i = 0; i < lenght; ++i) {
		if (str[i] == 'c') {
			if ((i != lenght) && (tests.find(str[i + 1]) != std::string::npos)) str[i] = 's';
			else str[i] = 'k';
		}
		if (str[i] == 'q') {
			if ((i != lenght) && (str[i + 1] == 'u')) str[i + 1] = 'v';
			str[i] = 'k';
		}
		if (str[i] == 'x') {
			str.replace(i, 1, "ks");
			++lenght;
		}
		if (str[i] == 'w') str[i] = 'v';
	}
}

void remaining(std::string& str, std::string findstr, std::string newstr) {
	size_t lenght = str.length();
	size_t lenghtfind = findstr.length();
	size_t lenghtnew = newstr.length();

	for (unsigned i{}; i <= lenght - lenghtfind; )
	{
		// �������� ������
		size_t position = str.find(findstr, i);
		// ���� �� ������� �� ������ ��������� � ������� i, ������� �� �����
		if (position == std::string::npos) break;

		str.replace(position, lenghtfind, newstr);
		lenght -= lenghtfind - lenghtnew;
		// ��������� � ���������� ������� ����� position
		i = position + 1;
	}
}

void doblesogl(std::string& str) {
	size_t lenght = str.length();
    std::string soglasnie = "bcdfghjklmnpqrstvwxz";
	size_t lenght1 = lenght - 1;

	for (unsigned i{}; i < lenght1; )
	{
		// �������� ������
		size_t position = str.find_first_of(soglasnie, i);
		// ���� �� ������� �� ������ ��������� � ������� i, ������� �� �����
		if (position == std::string::npos) break;

		if (str[position + 1] == str[position]) {
			str.erase(position, 1);
            --lenght1;
			i = position;
		}
		else {
            i = position + 1;
		}
		// ��������� � ���������� ������� ����� position	
	}
}


int main() {
	std::string str;
	std::getline(std::cin, str);
	
	bigbukovki(str);
	bukovki(str);

	remaining(str, "you", "u");
	remaining(str, "You", "U");
	remaining(str, "oo", "u");
	remaining(str, "Oo", "U");
	remaining(str, "ee", "i");
	remaining(str, "Ee", "I");
	remaining(str, "Th", "Z");
	remaining(str, "th", "z");
	remaining(str, "ph", "f");
	remaining(str, "Ph", "F");

	doblesogl(str);
	std::cout << str;
}