
#ifndef APICLIENT_H_
#define APICLIENT_H_

#include <Arduino.h>
#include <Bridge.h>
#include <HttpClient.h>

class ApiClient : public HttpClient {
public:
	ApiClient();
	ApiClient(String &auth_header);
	ApiClient(const char *auth_header);
	ApiClient(String &auth_header, String &contenttype_header);
	ApiClient(const char *auth_header, const char *contenttype_header);

	unsigned int post(String &url, String &data);
	unsigned int post(const char *url, const char *data);

	void postAsynchronously(String &url, String &data);
	void postAsynchronously(const char *url, const char *data);

	void setAuthorizationHeader(String &auth_header);
	void setAuthorizationHeader(const char *auth_header);

	void setContentTypeHeader(String &contenttype_header);
	void setContentTypeHeader(const char *contenttype_header);

private:
	void addAuthorizationHeader();
	void addContentTypeHeader();
	void addHeader(String &header);
	void addHeader(const char *header);
	String auth_header;
	String contenttype_header;
};

#endif /* APICLIENT_H_ */
