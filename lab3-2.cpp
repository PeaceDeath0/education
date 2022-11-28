#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "ru");
	float routeLength = 10, distanceInOneDay;
	int days = 1;
	float percent;
	FILE* f_output, * f_input;
pair <float, float> pairOfDistance = input(routeLength, &distanceInOneDay);
pair <float, float>  input(float* routeLength, float* distanceInOneDay) {
	pair <float, float> pairOfDistance;
	pairOfDistance.first = routeLength;
	pairOfDistance.second = distanceInOneDay;
	return pairOfDistance;
}
	f_input = fopen("hike.txt", "r");
cout >> routeLength; \\ 11
	if (f_input == 0)
	{
		printf("Ошибка при окрытии файла\n");
		return 1;
	}
	fscanf(f_input, "%f%f", &routeLength, &distanceInOneDay);

	fclose(f_input);
	printf("\n\tДлинна пути = %0.0f\n\tПройденное расстояние за 1 день = %0.0f\n", routeLength, distanceInOneDay);



	f_output = fopen("result.txt", "w");

	for (distanceInOneDay; distanceInOneDay < routeLength; distanceInOneDay += percent)
	{
		percent = (distanceInOneDay / 100) * 15;
		days++;
	}

	fprintf(f_output, "Путешественник потратит на маршрут\n\t %d дней", days);

	printf("Результат записан в файл result.txt");

	return 0;
}
