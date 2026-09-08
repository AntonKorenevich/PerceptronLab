#include <iostream>
#include <vector>


struct TrainingData
{
	float v1;
	float v2;
	float target;
};

class Perceptron
{
public:
	Perceptron(float w1, float w2, float bias)
		: m_w1(w1)
		, m_w2(w2)
		, m_bias(bias)
		, m_learningRate(0.1)
	{

	}

	void SetLearningRate(float value)
	{
		m_learningRate = value;
	}

	int Predict(float v1, float v2) const
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

	bool Train(float v1, float v2, float target)
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

	float GetResult(float v1, float v2)
	{
		return m_w1 * v1 + m_w2 * v2 + m_bias;
	}

	void LogInfo(float v1, float v2)
	{
		std::cout << "W1: " << m_w1 << std::endl;
		std::cout << "W2: " << m_w2 << std::endl;
		std::cout << "Bias: " << m_bias << std::endl;
		// std::cout << "Result: " << Predict(v1, v2) << std::endl;
	}

private:
	float m_w1;
	float m_w2;
	float m_bias;
	float m_learningRate;
};

void main()
{
	std::vector<TrainingData> trainingData;
	trainingData.push_back({ 0, 0, 0 });
	trainingData.push_back({ 0, 1, 0 });
	trainingData.push_back({ 1, 0, 0 });
	trainingData.push_back({ 1, 1, 1 });


	Perceptron p(0.0, 0.0, 0.0);

	bool retry = false;
	int eCounter = 1;
	int iCounter = 1;
	do
	{
		retry = false;
		std::cout << "----- Epoch " << eCounter << " ----- " << std::endl;
		for (auto data : trainingData)
		{
			retry |= !p.Train(data.v1, data.v2, data.target);
			p.LogInfo(data.v1, data.v2);
			iCounter++;
			std::cout << "Training completed for block" << std::endl;
		}
		eCounter++;
		std::cout << "------------ " << std::endl;
		if (eCounter >= 100)
		{
			std::cout << "Training is failed" << std::endl;
			break;
		}
	} while (retry);
	std::cout << "Total amount of trainings: " << iCounter << std::endl;

	std::cout << p.GetResult(1, 1) << std::endl;
	std::cout << p.GetResult(5, 5) << std::endl;
	std::cout << p.GetResult(7, 7) << std::endl;
	std::cout << p.GetResult(9, 9) << std::endl;
	std::cout << p.GetResult(10, 10) << std::endl;

	std::cout << "    ";

	for (int x = 0; x <= 10; ++x)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;

	for (int y = 10; y >= 0; --y)
	{
		std::cout << y << " | ";

		for (int x = 0; x <= 10; ++x)
		{
			if (p.GetResult(x, y) > 0)
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << "_ ";
			}
		}

		std::cout << std::endl;
	}
}