#include <stdio.h>
#include <math.h>
#include <windows.h>

int check(double *val, const char *name) {
	char buffer[256];
	printf("Введите %s: ", name);
	if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
		return 0;
	}
	int read_chars = 0;
	if(sscanf(buffer, "%lf%n", val, &read_chars) != 1) {
		printf("Ошибка! Неверные входные данные.\n");
		return 0;
	}
	int i = read_chars;
	while(buffer[i] != '\0') {
		if(buffer[i] != ' '
			 && buffer[i] != '\n'
			 && buffer[i] != '\t' 
			 && buffer[i] != '\r') {
			printf("Ошибка! Присутствуют лишние данные.\n");
			return 0;
		}
		i++;
	}
	return 1;
}

double maximum(double a, double b) {
    if(a > b) return a; else return b;
}

double minimum(double a, double b) {
    if(a > b) return b; else return a;
}

int main() {
	SetConsoleCP(65001);
    SetConsoleOutputCP(65001);  
	double x, ax, y, ay, f;
	if(!check(&x, "x") || !check(&y, "y")) {
		return 0;
	}
    ax = fabs(x);
    ay = fabs(y);
    if(ax + ay <= 1.0 || x >= 0.0) {
        if(x < 0) {
            printf("Ошибка! Нельзя высчитать квадратный корень из отрицательного числа.\n");
            return 0;
        }
        f = maximum(x, y) + sqrt(x);
    } else
    if(ax + ay > 0.0 || (x < 0.0 && y < 0.0)) {
        f = minimum(x, y) + pow(sin(x), 2) - cos(pow(y, 2));
    } else {
        f = exp(pow(x, 2) + ay);
        //этот случай математически невозможен
    }
    printf("F = %lf\n", f);
    return 0;
}