#pragma once
#include "proc_game_landlord_protocol.h"


class logic_core
{
public:
	logic_core(int);
	void init();
	void send_card();
private:
	int rand(int min, int max);
	int take_one_card();
	int compare_card(std::vector<int> cards_1, std::vector<int> cards_2);
	int getPoint(std::vector<int> cards);

	bool logic_core::IS_SHUANGFEI(std::vector<int> cards);	//˫��
	bool logic_core::IS_ZHADAN(std::vector<int> cards);	//������
	bool logic_core::IS_SIDAIYI(std::vector<int> cards);	//�Ĵ�1
	bool logic_core::IS_SIDAIER(std::vector<int> cards);	//�Ĵ���
	bool logic_core::IS_SANPAI(std::vector<int> cards);	//������
	bool logic_core::IS_SANDAIYI(std::vector<int> cards);	//����1
	bool logic_core::IS_DUIPAI(std::vector<int> cards);	//������
	bool logic_core::IS_SIPAISHUN(std::vector<int> cards);	//���� ˳��
	bool logic_core::IS_SANPAISHUN(std::vector<int> cards);	//���� ˳��
	bool logic_core::IS_ERPAISHUN(std::vector<int> cards);	//����˳
	bool logic_core::IS_DANPAISHUN(std::vector<int> cards);	//����˳
	bool logic_core::IS_DANPAI(std::vector<int> cards);//������
private:
	std::vector<int> m_cards;
	int deskCount;//��������м������ڴ�
	int mOpenCard;//ȡ��ǰ������ȷ��˭��ȡ��
	std::map<int, std::vector<int>> m_cardMap;
};
