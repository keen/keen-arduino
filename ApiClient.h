
#ifndef APICLIENT_H_
#define APICLIENT_H_

#include <Arduino.h>
#include <Bridge.h>

#define  POINTER_UNION_TYPE_CHAR   1
#define  POINTER_UNION_TYPE_STRING    2
#define  POINTER_UNION_TYPE_FLASHSTRING  3

#define MAX_BUFF_SIZE 512
#define BUFF_SIZE MAX_BUFF_SIZE + 1

typedef struct {
	int type;
	union {
		const char *char_ptr;
		const String *string_ptr;
		const __FlashStringHelper *flashstring_ptr;
	} u;
} StringPointer;

class ApiClient : public Process {
public:
	ApiClient();
	
	unsigned int get(const __FlashStringHelper *url);
	unsigned int get(const String &url);
	unsigned int get(const char *url);
	
	unsigned int post(const __FlashStringHelper *url, const __FlashStringHelper *data);
	unsigned int post(const String &url, const String &data);
	unsigned int post(const char *url, const char *data);


	void setAuthorizationHeader(StringPointer auth_header);
	void setAuthorizationHeader(const __FlashStringHelper *auth_header);
	void setAuthorizationHeader(const String *auth_header);
	void setAuthorizationHeader(const char *auth_header);
	void getAuthorizationHeader();
	
	void setContentTypeHeader(const __FlashStringHelper *contenttype_header);
	void setContentTypeHeader(const String *contenttype_header);
	void setContentTypeHeader(const char *contenttype_header);
	void getContentTypeHeader();
	
	void setUserAgentHeader(const __FlashStringHelper *useragent_header);
	void setUserAgentHeader(const String *useragent_header);
	void setUserAgentHeader(const char *useragent_header);
	void getUserAgentHeader();
	
	void printRequest();
	
private:
	unsigned int request();
	void addAuthorizationHeader();
	void addContentTypeHeader();
	void addUserAgentHeader();
	String request_buffer;
	StringPointer auth_header;
	StringPointer contenttype_header;
	StringPointer useragent_header;
};

#endif /* APICLIENT_H_ */

