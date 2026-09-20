#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
int check(double *val, const char *name) {
	char buffer[256];
	printf("Введите %s: ", name);
	if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
		return 0;
	}
	int read_chars = 0;
	if(sscanf(buffer, "%lf%n", val, &read_chars) != 1) {
		printf("Error! Incorrect input data.");
		return 0;
	}
	int i = read_chars;
	while(buffer[i] != '\0') {
		if(buffer[i] != ' '
			 && buffer[i] != '\n'
			 && buffer[i] != '\t' 
			 && buffer[i] != '\r') {
			printf("Error! Extra data provided.");
			return 0;
		}
		i++;
	}
	return 1;
}

int main() {
	setlocale(LC_CTYPE, "");
	setlocale(LC_NUMERIC, "C");
	double x, y, z, a, b, c, d, res;
	const double PI = 4.0 * atan(1.0);
	if(!check(&x, "x") || !check(&y, "y") || !check(&z, "z")) {
		return 0;
	}
	if(y < 0.0) {
		if(floor(x) != x) {
			printf("Error! You can't raise a negative number to a non-integer power.");
			return 0;
		}
	}
	a = pow(2, pow(y, x));
	b = pow(3, x * y);
	c = y * (atan(z) - PI/6.0);
	d = fabs(x) + 1.0 / (pow(y, 2) + 1.0);
	res = a + b - c / d;
	printf("Result = %lf", res);
	return 0;
}