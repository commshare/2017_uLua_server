#pragma once

// ���ʼ���
class Probability
{
	typedef std::pair<int, int> RANGE;
public:
	/*
			��ʼ�������б�
	*/
	bool initByProbabilityList(std::vector<int>& pList);

	/*
			�����������
	*/
	int getRandRange(int randNum);

	int getRandRange();
private:
	std::vector<RANGE> m_rangeList;
	
	int m_total;
};

