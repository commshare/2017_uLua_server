#pragma once
#include "game_object_def.h"
#include "game_object_field.h"
#include <list>

class game_object_handler;
class game_object
{
public:
	game_object();
	virtual ~game_object();

public:	
	//to_all �Ƿ�ȫ��ת��
	//use_ex �Ƿ������չ
	mongo::BSONObj to_bson(bool to_all = false, bool use_ex = false);
	bool from_bson(mongo::BSONObj& s);
	virtual void init_game_object() = 0;//ע������
	virtual bool store_game_object(bool to_all = false);//������������ʵ�ִ˽ӿ�
	virtual void to_bson_ex(mongo::BSONObjBuilder& ba) {};	//��չ������� �����ȡ

	virtual uint32_t get_id() {return 0;};//array ʹ��,  mapʹ�� ����Ψһ ��Ӧgame_object_map::get_id_name
	void set_hanlder(game_object_handler* hanlder);
	void set_update(bool is_update = true);

	//e_game_object_type
	GFieldPtr regedit_tfield(e_game_object_type etype, const std::string& fieldname);
	//string
	GStringFieldPtr regedit_strfield(const std::string& fieldname);
	//mongodb array
	GArrayFieldPtr regedit_arrfield(const std::string& fieldname, GArrayObjPtr arrptr);
	//game_object
	GObjFieldPtr regedit_objfield(const std::string& fieldname, GObjPtr objptr);
	//mongodb map
	GMapFieldPtr regedit_mapfield(const std::string& fieldname, GMapObjPtr mapptr);
	//OID
	GOIDFieldPtr regedit_oidfield(std::string fieldname = "_id");
	//intlist
	GIntListFieldPtr regedit_intlistfield(const std::string& fieldname);

	bool has_update();		
	
	const std::string& get_errorfields();
private:
	game_object_handler* Handler;
	std::list<GFieldPtr> m_fields;
	bool m_has_update;	
	std::string m_errorfields;
};