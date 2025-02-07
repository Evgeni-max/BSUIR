#include <iostream>
#include <vector>

#define Pi 3.14159265359

int main() {
	const int horizontal_resolution = 1920, vertical_resolution = 1080;
	const int horizontal_degree_of_camera = 60, vertical_degree_of_camera = 40;
	const int horizontal_displacement_of_camera = -10, vertical_displacement_of_camera = 37;
	const int height = 3;
	//����� �� ��������� � ������ �������� ����� ���� � �� �� ����������, ������� ���������� ���������� �� ���� 
	//�������������� � ������������ ����- ��� ��������� ���� �������� ������(10 �� ��� � 37 �� ���) � ����� ����� ������� �������� � ������� ������(������� ���� ������)
	double horizontal_degree = 0, vertical_degree = 0;
	//����������� ���������� ������ ������
	double x_coordinate = 0, y_coordinate = 0;
	std::vector<std::pair<int, int>> list_of_pixels{ {1117, 1080} ,{1161, 523},{1015, 303},{991, 174},{1161, 523},{1161, 523},{1054, 98},{1167, 70},{1189, 32},{1280, 270} };

	for (auto pixel : list_of_pixels) {
		//���� ���������� �� ������� ��� ������ ��������� �� ���������� ������� � ����� �� ���������� �� ��������� ������
		horizontal_degree = (double)pixel.first / horizontal_resolution * horizontal_degree_of_camera - horizontal_degree_of_camera / 2 + horizontal_displacement_of_camera;
		//���� ����� ������ � ��� ������������� ����, ����� ���������� 90 �������� ��� �������� ����������
		vertical_degree = (double)pixel.second / vertical_resolution * vertical_degree_of_camera - vertical_degree_of_camera / 2 + vertical_displacement_of_camera;
		vertical_degree = 90 - vertical_degree;
		//����������� ���������� �������, ����� ������� ������������������ ���������, ��� ���� ������������� ����������� � ��������: ������ ������ � y ����������
		y_coordinate = height * tan(vertical_degree / 180 * Pi);
		//� ������ x ���������� ����� ������������� ����������� � ��������: y ���������� � x ����������
		x_coordinate = y_coordinate * tan(horizontal_degree / 180 * Pi);
		//����� �������� ��� ������
		std::cout << "Pixel coordinat:[" << pixel.first << ',' << pixel.second << ']' << '\t' << "Metric coordinat:[" << x_coordinate << " , " << y_coordinate << ']' << std::endl;
	}
}