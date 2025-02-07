#include <iostream>
#include <vector>

#define Pi 3.14159265359

int main() {
	const int horizontal_resolution = 1920, vertical_resolution = 1080;
	const int horizontal_degree_of_camera = 60, vertical_degree_of_camera = 40;
	const int horizontal_displacement_of_camera = -10, vertical_displacement_of_camera = 37;
	const int height = 3;
	//чтобы не создавать в каждой итерации цикла одни и те же переменные, вынесем обьявление переменных за цикл 
	//горизонтальный и вертикальный углы- это сложенные угол поворота камеры(10 по гор и 37 по вер) с углом между искомым пикселем и центром камеры(главной осью камеры)
	double horizontal_degree = 0, vertical_degree = 0;
	//метрические координаты кромки дороги
	double x_coordinate = 0, y_coordinate = 0;
	std::vector<std::pair<int, int>> list_of_pixels{ {1117, 1080} ,{1161, 523},{1015, 303},{991, 174},{1161, 523},{1161, 523},{1054, 98},{1167, 70},{1189, 32},{1280, 270} };

	for (auto pixel : list_of_pixels) {
		//угол отклонения от главной оси камеры вычисляем по выведенной формуле и сразу же складываем со смещением камеры
		horizontal_degree = (double)pixel.first / horizontal_resolution * horizontal_degree_of_camera - horizontal_degree_of_camera / 2 + horizontal_displacement_of_camera;
		//тоже самое делаем и для вертикального угла, также прибавляем 90 градусов для легкости вычислений
		vertical_degree = (double)pixel.second / vertical_resolution * vertical_degree_of_camera - vertical_degree_of_camera / 2 + vertical_displacement_of_camera;
		vertical_degree = 90 - vertical_degree;
		//метрические координаты находим, решая простое тригонометрическое выражение, где есть прямоугольный треугольник с катетами: высота камеры и y координата
		y_coordinate = height * tan(vertical_degree / 180 * Pi);
		//в случае x координаты имеем прямоугольный треугольник с катетами: y координата и x координата
		x_coordinate = y_coordinate * tan(horizontal_degree / 180 * Pi);
		//вывод значений для каждой
		std::cout << "Pixel coordinat:[" << pixel.first << ',' << pixel.second << ']' << '\t' << "Metric coordinat:[" << x_coordinate << " , " << y_coordinate << ']' << std::endl;
	}
}