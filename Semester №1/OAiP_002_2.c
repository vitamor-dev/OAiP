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

int main() {
	SetConsoleCP(65001);
    SetConsoleOutputCP(65001);  
	double n, k, m, z, x, y1, y2, y3, f1, f2, f3, a;
	if(!check(&n, "n") || !check(&k, "k") || !check(&m, "m") || !check(&z, "z")) {
		return 0;
	}
    if(z > 1) {
        x = z;
        printf("Так как z > 1, x = z.\n");
     } else {
        x = pow(z, 2) + 1;
        printf("Так как z <= 1, x = z^2 + 1.\n");
     }
    if(m * x <= 0) {
        printf("Ошибка! Аргумент логарифма должен быть > 0.\n");
        return 0;
    }
    f1 = 2.0 * x;
    f2 = pow(x, 2);
    f3 = x / 3.0;
    a = cos(k * x) + log (m * x);
    y1 = sin(n * f1) + a;
    y2 = sin(n * f2) + a;
    y3 = sin(n * f3) + a;
    printf("При phi(x) = 2 * x, y = %lf\n", y1);
    printf("При phi(x) = x ^ 2, y = %lf\n", y2);
    printf("При phi(x) = x / 3, y = %lf\n", y3);
    return 0;
}
