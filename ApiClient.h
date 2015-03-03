
#ifndef APICLIENT_H_
#define APICLIENT_H_

#include <Arduino.h>
#include <Bridge.h>
#include <HttpClient.h>

class ApiClient : public HttpClient {
public:
	ApiClient();

	unsigned int post(const char *url, const char *data);
	void postAsynchronously(const char *url, const char *data);
	void setAuthorizationHeader(const char *auth_header);
	void setContentTypeHeader(const char *contenttype_header);

private:
	void addAuthorizationHeader();
	void addContentTypeHeader();
	void addHeader(const char *header);
	char auth_header[257];
	char contenttype_header[257];
};

#endif /* APICLIENT_H_ */
