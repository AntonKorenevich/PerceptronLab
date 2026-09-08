#include "PerceptronLab.h"
#include <iostream>

PerceptronLab::PerceptronLab()
	: m_pOR(0.f, 0.f, 0.f)
	, m_pAND(0.f, 0.f, 0.f)
	, m_pXOR(0.f, 0.f, 0.f)
{
	m_trainingData.push_back({ 0, 0, 0, 0, 0 });
	m_trainingData.push_back({ 0, 1, 1, 0, 1 });
	m_trainingData.push_back({ 1, 0, 1, 0, 1 });
	m_trainingData.push_back({ 1, 1, 1, 1, 0 });
}

void PerceptronLab::RunLab()
{
	TrainPerceptron(&m_pAND, LogicType::AND);
	TrainPerceptron(&m_pOR, LogicType::OR);
	TrainPerceptron(&m_pXOR, LogicType::XOR);
	PrintFunction(&m_pXOR);
}

void PerceptronLab::TrainPerceptron(Perceptron* p, LogicType lType)
{
	if (!p)
	{
		return;
	}

	bool retry = false;
	int eCounter = 1;
	int iCounter = 1;
	do
	{
		retry = false;
		std::cout << "----- Epoch " << eCounter << " ----- " << std::endl;
		for (auto data : m_trainingData)
		{
			if (lType == LogicType::AND)
			{
				retry |= !p->Train(data.v1, data.v2, data.targetAND);
			}
			else if (lType == LogicType::OR)
			{
				retry |= !p->Train(data.v1, data.v2, data.targetAND);
			}
			else
			{
				retry |= !p->Train(m_pAND.Predict(data.v1, data.v2), m_pOR.Predict(data.v1, data.v2), data.targetXOR);
			}
			m_pOR.LogInfo(data.v1, data.v2);
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
}

void PerceptronLab::PrintFunction(const Perceptron* p) const
{
	if (!p)
	{
		return;
	}

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
			if (p->GetResult(x, y) > 0)
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
