/*
 * ApiClient.cpp
 */

#include "ApiClient.h"

ApiClient::ApiClient() {
	this->auth_header = "";
	this->contenttype_header = "application/json";
}

ApiClient::ApiClient(String &auth_header) {
	this->auth_header = auth_header;
	this->contenttype_header = "application/json";
}

ApiClient::ApiClient(const char *auth_header) {
	this->auth_header = String(auth_header);
	this->contenttype_header = "application/json";
}

ApiClient::ApiClient(String &auth_header, String &contenttype_header) {
	this->auth_header = auth_header;
	this->contenttype_header = contenttype_header;
}

ApiClient::ApiClient(const char *auth_header, const char *contenttype_header) {
	this->auth_header = String(auth_header);
	this->contenttype_header = String(contenttype_header);
}

unsigned int ApiClient::post(String &url, String &data) {
	return post(url.c_str(), data.c_str());
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

void ApiClient::postAsynchronously(String &url, String &data) {
	return postAsynchronously(url.c_str(), data.c_str());
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

void ApiClient::setAuthorizationHeader(String &auth_header) {
	this->auth_header = auth_header;
}

void ApiClient::setAuthorizationHeader(const char *auth_header) {
	this->auth_header = String(auth_header);
}

void ApiClient::setContentTypeHeader(String &contenttype_header) {
	this->contenttype_header = contenttype_header;
}

void ApiClient::setContentTypeHeader(const char *contenttype_header) {
	this->contenttype_header = String(contenttype_header);
}

void ApiClient::addAuthorizationHeader() {
	if (auth_header.length() > 0) {
		addHeader("Authorization: " + auth_header);
	}
}

void ApiClient::addContentTypeHeader() {
	if (contenttype_header.length() > 0) {
		addHeader("Content-Type: " + contenttype_header);
	}
}

void ApiClient::addHeader(String &header) {
	if (header.length() > 0) {
		addParameter("--header");
		addParameter(header);
	}
}

void ApiClient::addHeader(const char *header) {
	String _header = String(header);
	addHeader(header);
}

