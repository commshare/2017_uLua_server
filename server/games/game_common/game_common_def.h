#pragma once
#include <string>

// �ټ�����Ϸ�ܾ�����һֱ����
static const std::string TOTAL_COUNT_BACCARAT = "totalCountBaccarat";
// �ټ�����Ϸ����������������
static const std::string DAY_COUNT_BACCARAT = "dayCountBaccarat";

// ��������Ϸ�ܾ�����һֱ����
static const std::string TOTAL_COUNT_CROCODILE = "totalCountCrocodile";

// ������Ϸ�ܾ�����һֱ����
static const std::string TOTAL_COUNT_DICE = "totalCountDice";

// ţţ��Ϸ�ܾ�����һֱ����
static const std::string TOTAL_COUNT_COWS = "totalCountCows";

// �ں�÷����Ϸ�ܾ�����һֱ����
static const std::string TOTAL_COUNT_SHCD = "totalCountShcd";
// �ں�÷����Ϸ����������������
static const std::string DAY_COUNT_SHCD = "dayCountShcd";

enum GameId
{
	game_baccracat = 5,             // �ټ���

	game_shcd = 10,                 // �ں�÷��
};

