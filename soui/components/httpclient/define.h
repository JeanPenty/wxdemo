#pragma once


//����ÿ�ζ�ȡ���ݵĻ�������С 4KB
#define READ_BUFFER_SIZE		4096

//�ڴ������õĻ�������С 8M
#define DOWNLOAD_BUFFER_SIZE	(8*1024*1024)


//���峣��httpͷ����
#define HEADER_USER_AGENT			"User-Agent"
#define HEADER_CONNECTION			"Connection"
#define HEADER_ACCEPT				"Accept"
#define HEADER_ACCEPT_ENCODING		"Accept-Encoding"
#define HEADER_ACCEPT_LANGUAGE		"Accept-Language"
#define HEADER_CONTENT_TYPE			"Content-Type"
#define HEADER_HOST					"Host"
#define HEADER_RANGE				"Range"
#define HEADER_LOCATION				"Location"
#define HEADER_CONTENT_LENGTH		"Content-Length"


//Ĭ��HTTP�汾
static const char default_http_version[] = "HTTP/1.1";

//����Ĭ�ϵ�userAgent
static const char default_user_agent[] = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.4044.92 Safari/537.36";

//Ĭ�Ͻ�������
static const char default_accept[] = "*/*";

//Ĭ�ϱ�������
static const char default_connection[] = "Keep-Alive";

//Ĭ������
static const char default_language[] = "zh-CN,zh;q=0.9";
 
//HTTPЭ�黻�з�
static const char http_newline[] = "\r\n";
