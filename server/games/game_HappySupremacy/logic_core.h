#pragma once

#include "proc_game_happysupremacy_protocol.h"

struct Card
{
public:
	BYTE point;
	e_card_flower flower;
	Card()
	{

	}

	Card(const e_card_flower type,const BYTE point)
	{
		this->point=point;
		this->flower=type;
	}

	BYTE ToPoint() const
	{
		if(flower==e_flower_spade && point==1)
		{
			return 6;
		}else
		{
			return point;
		}
	}
};
struct CardInfo
{
	e_card_owner owner;
	Card card;
};

struct CombineCardInfo
{
	e_card_owner owner;
	std::array<Card,2> cards;
};

struct CombinePointInfo
{
	e_card_owner owner;
	BYTE combineCards_Id;
	BYTE combineCard_point;
	BYTE maxsingleCard_point;

	CombinePointInfo()
	{
		combineCards_Id=0;
		combineCard_point=0;
		maxsingleCard_point=0;
	}
};

class logic_core
{
public:
	logic_core();
	void send_card();
	void send_cheat_card(bool or_SHOUFEN);//���ׯ���ǻ����˵Ļ�
	void send_cheat_card(std::vector<e_bet_type> win_type_list);//��ƭ��
	std::vector<CardInfo>& get_sort_player_card() {return m_sortcart_list;}
	std::map<e_bet_type,e_bet_result>& get_result_list(){return m_result_list;}
	std::map<e_card_owner,CombinePointInfo>& get_result_point_list(){return m_result_point_list;}
	BYTE get_remain_card_count(){return static_cast<BYTE>(m_cards.size());}
private:
	friend std::ostream& operator<<(std::ostream& stream, const logic_core& cardEngine);
	void init_card();
	void random_card();
	void take_open_card();  //����
	void take_one_card(e_card_owner owner,uint16_t index);  //ȡ��
	void take_card();//ȡ������

	int card_campare_single(const CombineCardInfo& cd1,const CombineCardInfo& cd2);
	int card_campare(const CombineCardInfo& cd1,const CombineCardInfo& cd2);
	const Card& get_single_maxcard(const std::array<Card,2>& cd);
	BYTE get_single_card_point(const Card& cd);
	BYTE get_card_Point(const std::array<Card,2>& cd) const;//ͳһת��Ϊ�Ƚϵ��������

	void set_result();
	void insert_to_sortcardlist(e_card_owner owner,Card card);
	void set_result_point();
	BYTE get_combineCard_Id(const std::array<Card,2>& cd) const;
	
	void send_GM_Cards();
private:
	std::vector<Card> m_cards;//ȫ������
	std::map<e_card_owner,CombineCardInfo> m_doorMap_card;
	std::vector<CardInfo> m_sortcart_list;	//9����(�������Ƶ�����)
	Card mOpenCard;//ȡ��ǰ������ȷ��˭��ȡ��
	//���ţ�˳�ţ�����
	std::map<e_bet_type,e_bet_result> m_result_list;//��ע���
	std::map<e_card_owner,CombinePointInfo> m_result_point_list;//����ơ��������б�
};
