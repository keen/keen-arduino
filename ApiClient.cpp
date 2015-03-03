/*
 * ApiClient.cpp
 */

#include "ApiClient.h"

ApiClient::ApiClient() {
	strcpy(this->auth_header, "");
	setContentTypeHeader("application/json");
}

unsigned int ApiClient::post(const char *url, const char *data) {
	begin("curl");
	addParameter("--request");
	addParameter("POST");
	addParameter("--data");
	addParameter(data);
	addAuthorizationHeader();
	addContentTypeHeader();
	addParameter(url);
	return run();
}

void ApiClient::postAsynchronously(const char *url, const char *data) {
	begin("curl");
	addParameter("--request");
	addParameter("POST");
	addParameter("--data");
	addParameter(data);
	addAuthorizationHeader();
	addContentTypeHeader();
	addParameter(url);
	runAsynchronously();
}

void ApiClient::setAuthorizationHeader(const char *auth_header) {
	strcpy(this->auth_header, "Authorization: ");
	strcat(this->auth_header, auth_header);
}

void ApiClient::setContentTypeHeader(const char *contenttype_header) {
	strcpy(this->contenttype_header, "Content-Type: ");
	strcat(this->contenttype_header, contenttype_header);
}

void ApiClient::addAuthorizationHeader() {
	if (sizeof(auth_header) > 0) {
		addHeader(auth_header);
	}
}

void ApiClient::addContentTypeHeader() {
	if (sizeof(contenttype_header) > 0) {
		addHeader(contenttype_header);
	}
}

void ApiClient::addHeader(const char *header) {
	if (sizeof(header) > 0) {
		addParameter("--header");
		addParameter(header);
	}
}

