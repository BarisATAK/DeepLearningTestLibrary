#pragma once
#pragma once
#include <fstream>
#include "Convolution.h"
#define BIAS 1

class Model{
private:
	int img_width;
	int img_height;
	int img_depth;
	int krnl_size;
	int krnl_count;
	int input_size;
	double predict;
	double probability;
	double** image;
	double* inputs;
public:
	Model() {
		this->img_width = 28;
		this->img_height = 28;
		this->img_depth = 1;
	}
	void ReadImageFile(std::string img_file_path);
	void Conv2D(std::string krnl_file_path, std::string activation, std::string padding, std::string bias, int stride);
	void MaxPooling2D(int pool_size);
	void CNNRelu(int img_width, int img_height, int krnl_count);
	void CNNBias(double* bias_weigths);
	double* FCNRelu(double* new_inputs, double* neuron_weights, int nodes);
	double* FCNSoftmax(double* new_inputs, double* neuron_weights, int nodes);
	void ModelSummary(std::string process);
	void Flatten();
	void Dense(std::string weight_file_path, std::string activation);
	void setNewDepth(int img_depth);
	void setImage(double** img);
	void setPredict(double predict);
	void setProbability(double probability);
	double getPredict();
	double getProbability();
};
void Model::setImage(double** img) {
	this->image = img;
}
void Model::ModelSummary(std::string process) {
	//std::cout << " ==> " << "(" << img_width << ", " << img_height << ", " << img_depth << ")" << "\n\n";
}
void Model::ReadImageFile(std::string img_file_path) {
	std::ifstream img_file;
	img_file.open(img_file_path);
	img_file >> img_width;
	img_file >> img_height;
	img_file >> img_depth;

	image = new double* [img_depth];
	for (int d = 0; d < img_depth; d++) {
		image[d] = new double[img_width * img_height];
	}

	for (int y = 0; y < img_height; y++) {
		for (int x = 0; x < img_width; x++) {
			for (int d = 0; d < img_depth; d++) {
				img_file >> image[d][y * img_width + x];
				//std::cout << image[d][y*img_width + x] << "\n"; // Debug!!!
			}
		}
	}
	img_file.close();
}
void Model::Conv2D(std::string krnl_file_path, std::string activation, std::string padding, std::string bias, int stride) {
	ModelSummary("Conv2D");
	std::ifstream krnl_file;
	krnl_file.open(krnl_file_path);
	krnl_file >> krnl_size;
	krnl_file >> krnl_count;

	double** kernel = new double* [krnl_size * krnl_size];
	for (int k_s = 0; k_s < krnl_size * krnl_size; k_s++) {
		kernel[k_s] = new double[krnl_count * img_depth];
	}

	for (int k_s = 0; k_s < krnl_size * krnl_size; k_s++) {
		for (int d = 0; d < img_depth; d++) {
			for (int k_c = 0; k_c < krnl_count; k_c++) {
				krnl_file >> kernel[k_s][k_c * img_depth + d];
				//std::cout << kernel[k_s][k_c*img_depth + d] << " "; // Debug!!!
			}
			//std::cout << "\n\n"; // Debug!!!
		}
	}

	double* bias_weigths = new double[krnl_count];
	if (bias == "true") {
		for (int k_c = 0; k_c < krnl_count; k_c++) {
			krnl_file >> bias_weigths[k_c];
			//std::cout << bias[i] << "\n ";  // Debug for Bias values!!!
		}
	}
	else {
		delete[] bias_weigths;
	}

	krnl_file.close();

	Convolution c;

	if (padding == "" || padding == "valid") { //azalt
		int padding = 0;
		image = c.Conv(image, kernel, img_width, img_height, img_depth, padding, krnl_count, krnl_size, stride);
		img_width = c.getNewWidth();
		img_height = c.getNewWidth();
		if (bias == "true")
			CNNBias(bias_weigths);
		if (activation == "relu") {
			CNNRelu(img_width, img_height, krnl_count);
		}
	}
	else if (padding == "same") { //zero-padding
		int padding = (krnl_size - 1) / 2;
		image = c.ZeroPadding(image, img_width, img_height, img_depth, padding, krnl_size, stride);
		img_width = c.getNewWidth();
		img_height = c.getNewWidth();
		image = c.Conv(image, kernel, img_width, img_height, img_depth, 0, krnl_count, krnl_size, stride);
		img_width = c.getNewWidth();
		img_height = c.getNewWidth();
		if (bias == "true")
			CNNBias(bias_weigths);
		if (activation == "relu") {
			CNNRelu(img_width, img_height, krnl_count);
		}
	}
	else {
		//std::cout << "Invalid value! You must enter 'same' or 'valid' ...";
	}
	setNewDepth(krnl_count);
}
void Model::CNNBias(double* bias_weigths) {
	for (int y = 0; y < img_width; y++) {
		for (int x = 0; x < img_height; x++) {
			for (int k_c = 0; k_c < krnl_count; k_c++) {
				image[k_c][y * img_width + x] += bias_weigths[k_c];
			}
		}
	}
}

void Model::CNNRelu(int img_width, int img_height, int krnl_count) {
	for (int y = 0; y < img_height; y++) {
		for (int x = 0; x < img_width; x++) {
			for (int k_c = 0; k_c < krnl_count; k_c++) {
				(image[k_c][y * img_width + x] <= 0.0) ? image[k_c][y * img_width + x] = 0.0 :
					image[k_c][y * img_width + x] = image[k_c][y * img_width + x];
			}
		}
	}

	//for (int k_c = 0; k_c < krnl_count; k_c++) { // Debug!!! 
	//	for (int y = 0; y < img_height; y++) {
	//		for (int x = 0; x < img_width; x++) {
	//			std::cout << image[k_c][y*img_width + x] << " ";
	//		}
	//		std::cout << "\n";
	//	}
	//	std::cout << std::endl << std::endl << std::endl << std::endl;
	//}
}
void Model::MaxPooling2D(int pool_size) {
	ModelSummary("MaxPooling2D");

	double** new_images = new double* [img_depth];

	int new_width = img_width / pool_size;
	int new_height = img_height / pool_size;

	for (int d = 0; d < img_depth; d++)
		new_images[d] = new double[new_width * new_height];

	double max;
	for (int d = 0; d < img_depth; d++) {
		for (int y = 0; y < new_height * pool_size; y += pool_size) {
			for (int x = 0; x < new_width * pool_size; x += pool_size) {
				max = image[d][y * img_width + x];
				for (int p_row = 0; p_row < pool_size * 2; p_row++) {
					for (int p_col = 0; p_col < pool_size * 2; p_col++) {
						if (image[d][(y + p_row) * img_width + (x + p_col)] > max) {
							max = image[d][(y + p_row) * img_width + (x + p_col)];
						}
					}
				}
				new_images[d][y / pool_size * new_width + x / pool_size] = max;
			}
		}
	}

	for (int d = 0; d < img_depth; d++)
		delete[] image[d];
	delete[] image;

	image = new double* [img_depth];
	for (int d = 0; d < img_depth; d++)
		image[d] = new double[new_width * new_height];

	for (int d = 0; d < img_depth; d++) {
		for (int y = 0; y < new_height; y++) {
			for (int x = 0; x < new_width; x++) {
				image[d][y * new_width + x] = new_images[d][y * new_width + x];
				//std::cout << image[d][y*new_width + x] << " ";
			}
			//std::cout << "\n";
		}
		//std::cout << std::endl << std::endl;
	}

	for (int d = 0; d < img_depth; d++)
		delete[] new_images[d];
	delete[]new_images;

	img_width = new_width;
	img_height = new_height;
}

void Model::Flatten() {
	ModelSummary("Flatten");

	input_size = img_depth * img_width * img_height;
	inputs = new double[input_size];

	int counter = 0;
	for (int y = 0; y < img_height; y++) {
		for (int x = 0; x < img_width; x++) {
			for (int d = 0; d < img_depth; d++) {
				inputs[counter++] = image[d][y * img_width + x];
			}
		}
	}

	for (int d = 0; d < img_depth; d++)
		delete[] image[d];
	delete[] image;

	for (int i = 0; i < input_size; i++) { // Debug!!! --> For Flatten Values.
		//std::cout << inputs[i] << "\n";
	}

	//std::cout << "Flatten Size: " << counter << "\n";
}
double* Model::FCNRelu(double* new_inputs, double* neuron_weights, int nodes) {
	double total;

	for (int n = 0; n < nodes; n++) {
		total = 0.0;
		for (int i = 0; i < input_size; i++) {
			total += inputs[i] * neuron_weights[n * (input_size + 1) + i];
		}
		total += BIAS * neuron_weights[n * (input_size + 1) + (input_size)];
		(total <= 0.0) ? new_inputs[n] = 0.0 : new_inputs[n] = total;
		//std::cout << new_inputs[n] << " "; // Debug!!!
	}
	//std::cout <<"\n\n\n"; // Debug!!!
	delete[] inputs;
	return new_inputs;
}
double* Model::FCNSoftmax(double* new_inputs, double* neuron_weights, int nodes) {
	double total;

	double* softmax = new double[nodes];
	for (int n = 0; n < nodes; n++) {
		total = 0.0;
		for (int i = 0; i < input_size; i++) {
			total += inputs[i] * neuron_weights[n * (input_size + 1) + i];
		}
		total += BIAS * neuron_weights[n * (input_size + 1) + (input_size)];
		new_inputs[n] = total;
		//std::cout << new_inputs[n] << " "; // Debug!!!
	}
	//std::cout <<"\n\n"; // Debug!!!

	double exp_total = 0.0;

	for (int n = 0; n < nodes; n++) {
		exp_total += std::exp(new_inputs[n]);
	}

	for (int n = 0; n < nodes; n++) {
		softmax[n] = std::exp(new_inputs[n]) / exp_total;
		//std::cout << softmax[n] << " "; // Debug!!!
	}
	//std::cout << "\n\n";
	double max = softmax[0];
	for (int n = 0; n < nodes; n++) {
		if (softmax[n] > max) {
			max = softmax[n];
		}
	}

	for (int n = 0; n < nodes; n++) {
		if (softmax[n] == max) {
			setProbability(softmax[n]);
			setPredict(n);
			//std::cout << "Accuracy => " << softmax[n] << "\n";
			//std::cout << "Result   => " << "[" << n << "]";
		}
	}

	return softmax;
}
void Model::setPredict(double predict) {
	this->predict = predict;
}
void Model::setProbability(double probability) {
	this->probability = probability;
}
double Model::getPredict(){
	return this->predict;
}
double Model::getProbability() {
	return this->probability;
}
void Model::Dense(std::string weight_file_path, std::string activation) {
	ModelSummary("Dense");

	int nodes;

	std::ifstream weights_file;
	weights_file.open(weight_file_path);
	weights_file >> nodes;
	double* neuron_weights = new double[(input_size + 1) * nodes];

	for (int n = 0; n < nodes; n++) {
		for (int i = 0; i < input_size + 1; i++) {
			weights_file >> neuron_weights[n * (input_size + 1) + i];
			//std::cout << neuron_weights[n*(input_size+1) + i] << " "; // For weights Debug
		}
		//std::cout << "\n" << "\n"; // For weights Debug
	}
	weights_file.close();

	double* new_inputs = new double[nodes];
	if (activation == "relu") {
		new_inputs = FCNRelu(new_inputs, neuron_weights, nodes);
	}
	else if (activation == "softmax") {
		new_inputs = FCNSoftmax(new_inputs, neuron_weights, nodes);
	}

	input_size = nodes;
	inputs = new double[input_size];
	for (int i = 0; i < input_size; i++)
		inputs[i] = new_inputs[i];
}

void Model::setNewDepth(int img_depth) {
	this->img_depth = img_depth;
}




