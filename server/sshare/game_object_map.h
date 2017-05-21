#pragma once
#include <enable_smart_ptr.h>
#include <enable_hashmap.h>
#include "game_object.h"
#include "game_object_handler.h"

class game_object_map
	:public game_object_handler
{
protected:
	typedef ENABLE_MAP<uint32_t, GObjPtr> cell_map;
	cell_map m_cells;
public:
	typedef cell_map::iterator cell_it;
	
public:
	game_object_map();
	virtual ~game_object_map();

	virtual const std::string& get_cells_name()=0;		//map��
	virtual const std::string& get_id_name()=0;		//map key ��
	virtual GObjPtr create_game_object(uint32_t object_id) = 0;	//ͨ��id�����������

	virtual bool update_all(){return false;}//����ǵ�2�����ϵĹ�ϵ ��������Ϊtrue

	uint32_t get_obj_count(){return m_cells.size();}
	bool put_obj(GObjPtr object);
	bool have_obj(uint32_t object_id);
	bool del_obj(uint32_t object_id);
	GObjPtr find_obj(uint32_t object_id);

	template<class T>
	boost::shared_ptr<T> find_Tobj(uint32_t object_id)
	{
		return CONVERT_POINT(T, find_obj(object_id));
	}

	void clear_obj();

	cell_it begin(){return m_cells.begin();}
	cell_it end(){return m_cells.end();}

	mongo::BSONObj to_bsonarr(bool to_all = false);
	bool from_bson(mongo::BSONObj& mb);
};
