// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
//#define _USE_32BIT_TIME_T
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ



// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
//#include <vld.h>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp> 
#include <boost/lexical_cast.hpp>
#include <boost/noncopyable.hpp>
#include <enable_smart_ptr.h>
#include <boost/cstdint.hpp>
#include <boost/pool/pool.hpp>
#include <boost/property_tree/json_parser.hpp> 
#include <boost/unordered_map.hpp>
#include <boost/function.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/log/common.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/filesystem.hpp>
#include <boost/timer.hpp>



#include <limits>
#include <string>
#include <xstring>
#include <queue>
#include <list>
#include <exception>
#include <map>
#include <vector>

#include <tchar.h>
#include <com_log.h>
#include <mongo/db/jsobj.h>
