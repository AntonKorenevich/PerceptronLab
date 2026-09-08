#pragma once

class Perceptron
{
public:
	Perceptron(float w1, float w2, float bias);

	void SetLearningRate(float value) { m_learningRate = value; };
	
	int		Predict(float v1, float v2) const;
	bool	Train(float v1, float v2, float target);
	float	GetResult(float v1, float v2) const;
	void	LogInfo(float v1, float v2);

private:
	float m_w1;
	float m_w2;
	float m_bias;
	float m_learningRate;
};

