#pragma once
#pragma once
class Convolution {
private:
	int new_width;
	int new_height;
public:
	double** Conv(double** image, double** kernel, int img_width, int img_height, int img_depth, int padding, int krnl_count, int krnl_size, int stride);
	double** ZeroPadding(double** image, int img_width, int img_height, int img_depth, int padding, int krnl_size, int stride);
	int getNewWidth();
	int getNewHeight();

};
double** Convolution::Conv(double** image, double** kernel, int img_width, int img_height, int img_depth, int padding, int krnl_count, int krnl_size, int stride) {

	new_width = (img_width + (2 * padding) - krnl_size) / stride + 1;
	new_height = (img_height + (2 * padding) - krnl_size) / stride + 1;

	double** new_images = new double* [krnl_count]; // Yeni derinlik.

	for (int k_c = 0; k_c < krnl_count; k_c++)
		new_images[k_c] = new double[new_width * new_height];

	double total;
	double depth_total;

	for (int y = 0; y < new_height * stride; y += stride) {
		for (int x = 0; x < new_width * stride; x += stride) {
			for (int k_c = 0; k_c < krnl_count; k_c++) {
				depth_total = 0.0;
				for (int d = 0; d < img_depth; d++) {
					total = 0.0;
					for (int k_row = 0; k_row < krnl_size; k_row++) {
						for (int k_col = 0; k_col < krnl_size; k_col++) {
							total += image[d][(y + k_row) * img_width + (x + k_col)] * kernel[k_row * krnl_size + k_col][k_c * img_depth + d];
						}
					}
					depth_total += total;
					total = 0;
				}
				new_images[k_c][y / stride * new_width + x / stride] = depth_total; //Relu
			}
		}
	}
	return new_images;
}
double** Convolution::ZeroPadding(double** image, int img_width, int img_height, int img_depth, int padding, int krnl_size, int stride) {

	new_width = img_width + (krnl_size - 1);
	new_height = img_height + (krnl_size - 1);

	double** temp_images = new double* [img_depth];

	for (int i = 0; i < img_depth; i++)
		temp_images[i] = new double[new_width * new_height];

	for (int d = 0; d < img_depth; d++) {
		for (int y = 0; y < new_height; y++) {
			for (int x = 0; x < new_width; x++) {
				if (y < krnl_size / 2 || y >= new_height - (krnl_size / 2)) {
					temp_images[d][y * new_width + x] = 0;
				}
				else {
					if (x < krnl_size / 2 || x >= new_width - (krnl_size / 2)) {
						temp_images[d][y * new_width + x] = 0;
					}
					else {
						temp_images[d][y * new_width + x] = image[d][(y - (krnl_size / 2)) * img_width + (x - (krnl_size / 2))];
					}
				}
				//std::cout << temp_images[d][y*new_width + x] << " ";
			}
			//std::cout << "\n";
		}
		//std::cout << "\n";
	}
	return temp_images;
}
int Convolution::getNewWidth() {
	return new_width;
}
int Convolution::getNewHeight() {
	return new_height;
}
