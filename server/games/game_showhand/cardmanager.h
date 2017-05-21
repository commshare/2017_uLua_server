#pragma once
#include <memory>
#include <vector>
#include <array>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/*
����
�����Ƶĵ�����ɫ�Ĺ�ʽΪ��
8,9,10,11,12,13,14,�ֱ����8,9,10,11,12,13,A
��Ψһ�㣺��ԭʼ��*100+��ɫ������4:�ڣ�3���죬2��÷��1������
�Ҵ��Ƶ���Խ������Ψһ��ҲԽ��
*/
class cardmanager
{
private:
	std::vector<int> p_left_cards;//����
	std::vector<int> p_right_cards;//����

	std::vector<int> m_cards;//���е��� 
	std::vector<bool> firstbet_list;
	bool orleftwin;

	std::vector<bool> left_win_rate;
	std::vector<bool> right_win_rate;
public:
	cardmanager();
	void sendcard();
	void send_cheat_card(bool left_win);//�Ƿ������Ӯ
	void gm_exchange_card();
	std::vector<bool>& get_who_first_bet_list();
	std::vector<bool>& get_left_win_rate();//�õ�������Ӯ�ø���
	std::vector<bool>& get_right_win_rate();//�õ��ұ����Ӯ�ø���
	std::vector<int>& get_left_cards();
	std::vector<int>& get_right_cards();
	bool get_left_result();
	int get_cards_type(const std::vector<int>& cards);
private:
	void init_cards();
	int compare_cards();
	void set_result();
	void set_whofirstbetlist();
	void set_whowinratelist();

	int get_whofirstbet_point(int currentCardIndex, const std::vector<int>& cards);
	int get_win_rate_point(int currentCardIndex, const std::vector<int>& cards);
	int get_cards_point(const std::vector<int>& cards);

	bool Is_TONGHUASHUN(const std::vector<int>& sort_cards);//ͬ��˳
	bool Is_TIEZHI(const std::vector<int>& sort_cards);//��֧
	bool Is_HULU(const std::vector<int>& sort_cards);//��«
	bool Is_TONGHUA(const std::vector<int>& sort_cards);//ͬ��
	bool Is_SHUNZI(const std::vector<int>& sort_cards);//˳��
	bool Is_SANTIAO(const std::vector<int>& sort_cards);//����
	bool Is_LIANGDUI(const std::vector<int>& sort_cards);//����
	bool Is_DUIZI(const std::vector<int>& sort_cards);//����

	int get_point_TONGHUASHUN(const std::vector<int>& sort_cards);//ͬ��˳
	int get_point_TIEZHI(const std::vector<int>& sort_cards);//��֦
	int get_point_HULU(const std::vector<int>& sort_cards);//��«
	int get_point_TONGHUA(const std::vector<int>& sort_cards);//ͬ��
	int get_point_SHUNZI(const std::vector<int>& sort_cards);//˳��
	int get_point_SANTIAO(const std::vector<int>& sort_cards);//����
	int get_point_LIANGDUI(const std::vector<int>& sort_cards);//����
	int get_point_DUIZI(const std::vector<int>& sort_cards);//����

	int get_point_SANPAI(const std::vector<int>& sort_cards);//ɢ��

	void send_GM_Cards();

	friend std::ostream& operator<<(std::ostream& stream, const cardmanager& cm);
};