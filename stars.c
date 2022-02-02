#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct coord {
	float x;
	float y;
};

void createStar(struct coord *star) {
	star[0].x = -1.0;
	star[0].y = +0.0;
	star[1].x = -0.1;
	star[1].y = +0.1;
	star[2].x = +0.0;
	star[2].y = +1.0;
	star[3].x = +0.1;
	star[3].y = +0.1;
	star[4].x = +1.0;
	star[4].y = +0.0;
	star[5].x = +0.1;
	star[5].y = -0.1;
	star[6].x = +0.0;
	star[6].y = -1.0;
	star[7].x = -0.1;
	star[7].y = -0.1;
}

void stars(int nstars);

int main(int argc, char *argv[]) {
	int nstars;
	
	if (argc == 2) {
		nstars = atoi(argv[1]);
		if (nstars > 0) stars(nstars);
	}
	return 0;
}

void stars(int nstars) {
	unsigned int width = 500;
	unsigned int height = 100;
	unsigned int red = 188;
	unsigned int green = 192;
	unsigned int blue = 204;
	float size;
	float maxSize = 1.5;
	float minSize = 0.5;
	float x, y;
	int i;
	struct coord star[8];
	
	createStar(star);
	srand(time(NULL));
	puts("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
	puts("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">");
	printf("<svg width=\"100%%\" height=\"100%%\" viewBox=\"0 0 %d %d\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" xml:space=\"preserve\" xmlns:serif=\"http://www.serif.com/\" style=\"fill-rule:evenodd;clip-rule:evenodd;stroke-linejoin:round;stroke-miterlimit:2;\">\n", width, height);
	while (nstars--) {
		printf("\t<path ");
		printf("d=\"");

		size = ((float)rand() / (float)(RAND_MAX / (maxSize - minSize))) + minSize;

		x = (float)rand() / (float)(RAND_MAX / ((float)width - (size * 2))) + size;
		y = (float)rand() / (float)(RAND_MAX / ((float)height - (size * 2))) + size;

		printf("M%f,%f", x + (star[0].x * size), y + (star[0].y * size));
		i = 0;
		while (++i < 8) {
			printf("L%f,%f", x + (star[i].x * size), y + (star[i].y * size));
		}
		printf("L%f,%fZ", x + (star[0].x * size), y + (star[0].y * size));
		
		printf("\" ");
		printf("style=\"");
		printf("fill:rgb(%d,%d,%d);", red, green, blue);
		printf("\"");
		puts("/>");
	}
	puts("</svg>");
}
