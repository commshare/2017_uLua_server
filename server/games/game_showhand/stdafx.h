// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/thread/null_mutex.hpp>
#include <boost/bind.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp> 
#include <boost/lexical_cast.hpp>
#include <boost/noncopyable.hpp>
#include <boost/smart_ptr.hpp>
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
#include <boost/date_time.hpp>


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

#include <enable_singleton.h>
#include <net/msg_queue.h>
#include <enable_object_manager.h>
#include <enable_singleton.h>
#include <server_manager_handler.h>
#include <net/peer_tcp.h>


#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib, "sshare-gd.lib")

#else
#pragma comment(lib, "sshare.lib")
#endif
#endif