#pragma once
#pragma once
class Convolution {...};
double** Convolution::Conv(double** image, double** kernel, int img_width, int img_height, int img_depth, int padding, int krnl_count, int krnl_size, int stride) {}
double** Convolution::ZeroPadding(double** image, int img_width, int img_height, int img_depth, int padding, int krnl_size, int stride) {}
int Convolution::getNewWidth() {
	return new_width;
}
int Convolution::getNewHeight() {
	return new_height;
}
