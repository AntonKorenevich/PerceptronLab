#pragma once
#include "Perceptron.h"
#include <vector>

enum LogicType
{
	OR,
	AND,
	XOR
};

struct TrainingData
{
	float v1;
	float v2;
	float targetOR;
	float targetAND;
	float targetXOR;
};

class PerceptronLab
{
public:
	PerceptronLab();
	void RunLab();

	void TrainPerceptron(Perceptron* p, LogicType lType);
	void PrintFunction(const Perceptron* p) const;

private:
	Perceptron m_pOR;
	Perceptron m_pAND;
	Perceptron m_pXOR;

	std::vector<TrainingData> m_trainingData;
};

