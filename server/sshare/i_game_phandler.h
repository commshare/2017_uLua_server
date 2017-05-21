#pragma once
#include <i_game_def.h>



//������֪ͨ����߼��ӿ�
class i_game_phandler
{
public:
	i_game_phandler();
	virtual ~i_game_phandler();

	//���Ըı�(�������Ͷ��Ǳ仯��)
	virtual void on_attribute_change(int atype, int v = 0) = 0;
	virtual void on_attribute64_change(int atype, GOLD_TYPE v = 0) = 0;

	//���״̬�ı�
	virtual void on_change_state() = 0;

	void set_player(iGPlayerPtr player);

	/*
			֪ͨ����յ�����
			senderId	���������id
			receiverId	������id
			giftId		����ID
	*/
	virtual void onAcceptGift(int receiverId, int giftId){}

	i_game_player* getIGamePlayer(){ return m_player.get(); }
protected:
	iGPlayerPtr m_player;
};

