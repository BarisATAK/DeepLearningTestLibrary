#pragma once
#pragma once
#include <fstream>
#include "Convolution.h"
#define BIAS 1

class Model{};
void Model::setImage(double** img) {}
void Model::ModelSummary(std::string process) {	}
void Model::ReadImageFile(std::string img_file_path) {}
void Model::Conv2D(std::string krnl_file_path, std::string activation, std::string padding, std::string bias, int stride) {}
void Model::CNNBias(double* bias_weigths) {}
void Model::CNNRelu(int img_width, int img_height, int krnl_count) {}
void Model::MaxPooling2D(int pool_size) {}
void Model::Flatten() {}
double* Model::FCNRelu(double* new_inputs, double* neuron_weights, int nodes) {}
double* Model::FCNSoftmax(double* new_inputs, double* neuron_weights, int nodes) {}
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
void Model::Dense(std::string weight_file_path, std::string activation) {}
void Model::setNewDepth(int img_depth) {
	this->img_depth = img_depth;
}




