#pragma once
#include "proc_game_landlord_protocol.h"

class logic_core
{
public:
	logic_core(int);
	void init();
	void send_card();
	std::map<int, std::vector<int>>& get_cards_info() { return m_cardMap; }
	std::vector<int>& get_cards_info(int desk) { return m_cardMap[desk]; }

	int get_openCard() { return mOpenCard; }
	int get_Landlord() { return landlord_id; }
	const std::vector<int>& get_RemainLandlordCards() { return m_RemainlandlordCards; }
	int compare_card(std::vector<int> cards_1, std::vector<int> cards_2);
	void playhand(int deskid,std::vector<int>& cards);
private:
	int rand(int min, int max);
	int take_one_card();
	int getPoint(int type, std::vector<int> cards);
	int GetPaiType(std::vector<int> cards);

	bool logic_core::IS_SHUANGFEI(std::vector<int> cards);	//˫��
	bool logic_core::IS_ZHADAN(std::vector<int> cards);	//������
	bool logic_core::IS_SANPAI(std::vector<int> cards);	//������
	bool logic_core::IS_ERPAI(std::vector<int> cards);	//������
	bool logic_core::IS_SIPAISHUN(std::vector<int> cards);	//���� ˳��
	bool logic_core::IS_SANPAISHUN(std::vector<int> cards);	//���� ˳��
	bool logic_core::IS_ERPAISHUN(std::vector<int> cards);	//����˳
	bool logic_core::IS_DANPAISHUN(std::vector<int> cards);	//����˳
	bool logic_core::IS_DANPAI(std::vector<int> cards);//������

	int logic_core::FEN_SHUANGFEI(std::vector<int> cards);	//˫��
	int logic_core::FEN_ZHADAN(std::vector<int> cards);	//������
	int logic_core::FEN_SANPAI(std::vector<int> cards);	//������
	int logic_core::FEN_ERPAI(std::vector<int> cards);	//������
	int logic_core::FEN_SIPAISHUN(std::vector<int> cards);	//���� ˳��
    int logic_core::FEN_SANPAISHUN(std::vector<int> cards);	//���� ˳��
	int logic_core::FEN_ERPAISHUN(std::vector<int> cards);	//����˳
	int logic_core::FEN_DANPAISHUN(std::vector<int> cards);	//����˳
	int logic_core::FEN_DANPAI(std::vector<int> cards);//������
private:
	std::vector<int> m_cards;
	int deskCount;//��������м������ڴ�
	int mOpenCard;//ȡ��ǰ������ȷ��˭��ȡ��
	std::map<int, std::vector<int>> m_cardMap;
	std::vector<int> m_RemainlandlordCards;//ʣ�µ�3����
	int landlord_id;
};
