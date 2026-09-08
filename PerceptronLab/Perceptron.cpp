#include "Perceptron.h"
#include <iostream>

Perceptron::Perceptron(float w1, float w2, float bias)
	: m_w1(w1)
	, m_w2(w2)
	, m_bias(bias)
	, m_learningRate(0.1)
{
}

int Perceptron::Predict(float v1, float v2) const
{
	float result = m_w1 * v1 + m_w2 * v2 + m_bias;
	if (result > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Perceptron::Train(float v1, float v2, float target)
{
	float error = target - Predict(v1, v2);
	if (error == 0)
	{
		return true;
	}
	else
	{
		m_w1 += m_learningRate * error * v1;
		m_w2 += m_learningRate * error * v2;
		m_bias += m_learningRate * error;
		return false;
	}
}

float Perceptron::GetResult(float v1, float v2) const
{
	return m_w1 * v1 + m_w2 * v2 + m_bias;
}

void Perceptron::LogInfo(float v1, float v2)
{
	std::cout << "W1: " << m_w1 << std::endl;
	std::cout << "W2: " << m_w2 << std::endl;
	std::cout << "Bias: " << m_bias << std::endl;
}
