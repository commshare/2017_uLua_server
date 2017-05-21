#pragma once
#include "game_sys_def.h"

class game_player;
class FriendMap;
struct stFriendInfo;

// ����С���ȹ���
class SpeakerMgr : public enable_obj_pool<SpeakerMgr>, public game_sys_base
{
public:
	MAKE_SYS_TYPE(e_gst_speaker);

	MAKE_GET_OWNER(game_player);

	virtual bool sys_load();
};

