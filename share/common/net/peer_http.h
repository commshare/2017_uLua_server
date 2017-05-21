#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

struct header
{
	std::string name;
	std::string value;
};

struct msg_request
{
public:
	explicit msg_request(){ clear();}
	
	std::string method;			// "GET", "POST".	
	std::string uri;			// ������http://��·��
	int http_version_major;		// 
	int http_version_minor;		// 
	std::vector<header> headers;// HTTP��ͷ
	std::string content;		// �ϴ�������
	std::string spath;			// �����ַ

	void clear()
	{
		method = "GET";
		uri.clear();
		http_version_major = 1;
		http_version_minor = 0;
		headers.clear();
		content.clear();
		spath.clear();

	}
};

struct msg_response
{
public:
	explicit msg_response(){ clear();}	
	std::string http_version;		// �汾
	int32_t status_code;			// ״̬��
	std::string status_message;		// ״̬
	std::vector<header> headers;	// HTTP��ͷ
	std::stringstream content;		// HTTP���ص�����	

	void clear()
	{
		http_version.clear();
		status_code = -1;
		status_message.clear();
		headers.clear();
		content.str("");
	}
};

class peer_http: public boost::enable_shared_from_this<peer_http>
{
public:
	peer_http(boost::asio::io_service& io_service);
	virtual ~peer_http();

	void post_request(const msg_request& req);	
	//ͬ�������ʹ��
	virtual void on_complete(){};	
private:
	void handle_resolve(const boost::system::error_code& err, boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
	void handle_connect(const boost::system::error_code& err);
	void handle_write_request(const boost::system::error_code& err);
	void handle_read_status_line(const boost::system::error_code& err);
	void handle_read_headers(const boost::system::error_code& err);
	void handle_read_content(const boost::system::error_code& err);

private:
	boost::asio::ip::tcp::resolver resolver_;
	boost::asio::ip::tcp::socket socket_;
	boost::asio::streambuf request_;
	boost::asio::streambuf response_;

protected:
	//http����ص��ӿ� (�첽���̰߳�ȫ)
	virtual void http_response(bool result, const std::string& response) = 0;

	//ͬ������ ʹ��peer_http_mgr��on_complete����
	void use_synchronization();
	msg_response m_response;
};
