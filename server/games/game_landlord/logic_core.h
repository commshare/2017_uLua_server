#pragma once
#include "proc_game_landlord_protocol.h"
#include "logic_player.h"

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
	int compare_card(std::vector<int>& cards_1, std::vector<int>& cards_2);
	void playhand(int deskid,std::vector<int>& cards);
	game_landlord_protocol::card_Info logic_core::get_rob_playhand(logic_player* player);
private:
	int rand(int min, int max);
	int take_one_card();
	int getPoint(int type, std::vector<int>& cards);
	int GetPaiType(std::vector<int>& cards);

	bool IS_SHUANGFEI(std::vector<int>& cards);	//˫��
	bool IS_SIZHANGPAI(std::vector<int>& cards);	//������
	bool IS_SANPAI(std::vector<int>& cards);	//������
	bool IS_ERPAI(std::vector<int>& cards);	//������
	bool IS_SIPAISHUN(std::vector<int>& cards);	//���� ˳��
	bool IS_SANPAISHUN(std::vector<int>& cards);	//���� ˳��
	bool IS_ERPAISHUN(std::vector<int>& cards);	//����˳
	bool IS_DANPAISHUN(std::vector<int>& cards);	//����˳
	bool IS_DANPAI(std::vector<int>& cards);//������

	int FEN_SHUANGFEI(std::vector<int>& cards);	//˫��
	int FEN_ZHADAN(std::vector<int>& cards);	//������
	int FEN_SANPAI(std::vector<int>& cards);	//������
	int FEN_ERPAI(std::vector<int>& cards);	//������
	int FEN_SIPAISHUN(std::vector<int>& cards);	//���� ˳��
    int FEN_SANPAISHUN(std::vector<int>& cards);	//���� ˳��
	int FEN_ERPAISHUN(std::vector<int>& cards);	//����˳
	int FEN_DANPAISHUN(std::vector<int>& cards);	//����˳
	int FEN_DANPAI(std::vector<int>& cards);//������

	int IS_Contain_SHUANGFEI(std::vector<int>& cards);	//˫��
	int IS_Contain_SIZHANGPAI(std::vector<int>& cards, int pai);	//������
	int IS_Contain_SANPAI(std::vector<int>& cards, int pai);	//������
	int IS_Contain_ERPAI(std::vector<int>& cards, int pai);	//������
	int IS_Contain_SIPAISHUN(std::vector<int>& cards, int maxpai);	//���� ˳��
	int IS_Contain_SANPAISHUN(std::vector<int>& cards, int maxpai);	//���� ˳��
	int IS_Contain_ERPAISHUN(std::vector<int>& cards, int maxpai);	//����˳
	int IS_Contain_DANPAISHUN(std::vector<int>& cards, int maxpai);	//����˳
	int IS_Contain_DANPAI(std::vector<int>& cards, int pai);//������

	std::vector<int> Get_SHUANGFEI(std::vector<int>& cards);	//˫��
	std::vector<int> Get_SIPAI(std::vector<int>& cards, int pai);	//������
	std::vector<int> Get_SANPAI(std::vector<int>& cards, int pai);	//������
	std::vector<int> Get_ERPAI(std::vector<int>& cards, int pai);	//������
	std::vector<int> Get_DANPAI(std::vector<int>& cards, int pai);//������
	std::vector<int> Get_SIPAISHUN(std::vector<int>& cards, int maxpai);	//���� ˳��
	std::vector<int> Get_SANPAISHUN(std::vector<int>& cards, int maxpai);	//���� ˳��
	std::vector<int> Get_ERPAISHUN(std::vector<int>& cards, int maxpai);	//����˳
	std::vector<int> Get_DANPAISHUN(std::vector<int>& cards, int maxpai);	//����˳

	void INIT_PAI_TYPE_MAP(int deskId);

	std::vector<int>& get_ZUIXIAO_PAI(std::vector<int> cards_1);//�õ��Լ�����  ��С�ƣ�
	std::vector<int>& get_ZUIXIAO_PAI(std::vector<int>& cards_1, std::vector<int>& cards_2);//�õ��Լ�����  ��С�ƣ�
private:
	std::vector<int> m_cards;
	int deskCount;//��������м������ڴ�
	int mOpenCard;//ȡ��ǰ������ȷ��˭��ȡ��
	std::map<int, std::vector<int>> m_cardMap;
	std::map<int, std::map<int, std::vector<int>>> m_desk_type_map;
	std::vector<int> m_RemainlandlordCards;//ʣ�µ�3����
	int landlord_id;
};
