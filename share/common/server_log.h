#pragma once
#include <string>

#include <boost/log/common.hpp>
#include <boost/log/sources/logger.hpp>

enum severity_levels
{
	slog_emergency = 0,                //slog_emerg
	slog_alert = 1,                    //slog_alert
	slog_critical = 2,                 //slog_crit
	slog_error = 3,                    //slog_error ����slog_error��log������console��ʾ ���Ҳ�������д���ļ�
	slog_warning = 4,                  //slog_warning
	slog_notice = 5,                   //slog_notice
	slog_info = 6,                     //slog_info
	slog_debug = 7                     //slog_debug
};

class com_log 
{
public:
	com_log(void);
	~com_log(void);

	//filename Ĭ��Ϊ������
	static void InitLog(const std::string& filename = "");

	static void SetLevel(severity_levels sl);
	static void SetConsole();
	static void flush();
	static void clear();
};

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(server_lg, boost::log::sources::severity_logger_mt<severity_levels>);

#define BOOST_SLOG(slog_lvl) BOOST_LOG_SEV(server_lg::get(), slog_lvl)

//��������Ļ��ʾ��������������ļ�
//BOOST_LOG_FUNCTION(); ��������ļ���������
#define SLOG_EMERGENCY BOOST_LOG_FUNCTION();BOOST_SLOG(slog_emergency)
#define SLOG_ALERT BOOST_SLOG(slog_alert)
#define SLOG_CRITICAL BOOST_SLOG(slog_critical)
#define SLOG_ERROR BOOST_LOG_FUNCTION();BOOST_SLOG(slog_error)

//���²�����ʾ���������־������������ļ�
#define SLOG_WARNING BOOST_SLOG(slog_warning)
#define SLOG_NOTICE BOOST_SLOG(slog_notice)
#define SLOG_INFO BOOST_SLOG(slog_info)
#define SLOG_DEBUG BOOST_SLOG(slog_debug)

//////////////////////////////////////////////////////////////////////////
#include <exception>
#define __ENTER_FUNCTION try{
#define __LEAVE_FUNCTION }catch(std::exception* ex){BOOST_LOG_FUNCTION();SLOG_ERROR<<ex->what();}

#define __ENTER_FUNCTION_CHECK bool EX_CHECK = false;try{
#define __LEAVE_FUNCTION_CHECK }catch(std::exception* ex){BOOST_LOG_FUNCTION();SLOG_ERROR<<ex->what();EX_CHECK = true;}

#define __ASSERT(exp, msg) if(!(exp)){BOOST_LOG_FUNCTION();SLOG_ALERT<<msg;throw new std::exception(msg);}