/*
 * ApiClient.cpp
 */

#include "ApiClient.h"

ApiClient::ApiClient() {
	request_buffer.reserve(BUFF_SIZE);
}

unsigned int ApiClient::request() {
	return 0;
	//return runShellCommand(request_buffer);
}

unsigned int ApiClient::get(const __FlashStringHelper *url) {
	return request();
}

unsigned int ApiClient::get(const String &url) {
	return request();
}

unsigned int ApiClient::get(const char *url) {
	return request();
}

unsigned int ApiClient::post(const __FlashStringHelper *url, const __FlashStringHelper *data) {
	request_buffer = F("curl -X POST ");
	request_buffer += F("-H \"Authorization: ");
	addAuthorizationHeader();
	request_buffer += F("\" ");
	request_buffer += F("-H \"Content-Type: ");
	addContentTypeHeader();
	request_buffer += F("\" ");
	request_buffer += F("-d '");
	request_buffer += data;
	request_buffer += F("' ");
	request_buffer += url;
	return request();
}

unsigned int ApiClient::post(const String &url, const String &data) {
	request_buffer = F("curl -X POST ");
	request_buffer += F("-H \"Authorization: ");
	addAuthorizationHeader();
	request_buffer += F("\" ");
	request_buffer += F("-H \"Content-Type: ");
	addContentTypeHeader();
	request_buffer += F("\" ");
	request_buffer += F("-d '");
	request_buffer += data;
	request_buffer += F("' ");
	request_buffer += url;
	return request();
}

unsigned int ApiClient::post(const char *url, const char *data) {
	request_buffer = F("curl -X POST ");
	request_buffer += F("-H \"Authorization: ");
	addAuthorizationHeader();
	request_buffer += F("\" ");
	request_buffer += F("-H \"Content-Type: ");
	addContentTypeHeader();
	request_buffer += F("\" ");
	request_buffer += F("-d '");
	request_buffer += data;
	request_buffer += F("' ");
	request_buffer += url;
	return request();
}
 
void ApiClient::setAuthorizationHeader(const __FlashStringHelper *auth_header) {
	this->auth_header.u.flashstring_ptr = auth_header;
	this->auth_header.type = POINTER_UNION_TYPE_FLASHSTRING;
	return *this;
}

void ApiClient::setAuthorizationHeader(const String *auth_header) {
	this->auth_header.u.string_ptr = auth_header;
	this->auth_header.type = POINTER_UNION_TYPE_STRING;
	return *this;
}

void ApiClient::setAuthorizationHeader(const char *auth_header) {
	this->auth_header.u.char_ptr = auth_header;
	this->auth_header.type = POINTER_UNION_TYPE_CHAR;
	return *this;
}

void ApiClient::getAuthorizationHeader() {
	switch(auth_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(auth_header.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*auth_header.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(auth_header.u.char_ptr);
			break;
		default:
			break;
	}
}

void ApiClient::addAuthorizationHeader() {
	switch(auth_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			request_buffer += auth_header.u.flashstring_ptr;
			break;
		case POINTER_UNION_TYPE_STRING:
			request_buffer += *auth_header.u.string_ptr;
			break;
		case POINTER_UNION_TYPE_CHAR:
			request_buffer += auth_header.u.char_ptr;
			break;
		default:
			break;
	}
}

void ApiClient::setContentTypeHeader(const __FlashStringHelper *contenttype_header) {
	this->contenttype_header.u.flashstring_ptr = contenttype_header;
	this->contenttype_header.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void ApiClient::setContentTypeHeader(const String *contenttype_header) {
	this->contenttype_header.u.string_ptr = contenttype_header;
	this->contenttype_header.type = POINTER_UNION_TYPE_STRING;
}

void ApiClient::setContentTypeHeader(const char *contenttype_header) {
	this->contenttype_header.u.char_ptr = contenttype_header;
	this->contenttype_header.type = POINTER_UNION_TYPE_CHAR;
}

void ApiClient::getContentTypeHeader() {
	switch(contenttype_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(contenttype_header.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*contenttype_header.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(contenttype_header.u.char_ptr);
			break;
		default:
			break;
	}
}

void ApiClient::addContentTypeHeader() {
	switch(contenttype_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			request_buffer += contenttype_header.u.flashstring_ptr;
			break;
		case POINTER_UNION_TYPE_STRING:
			request_buffer += *contenttype_header.u.string_ptr;
			break;
		case POINTER_UNION_TYPE_CHAR:
			request_buffer += contenttype_header.u.char_ptr;
			break;
		default:
			break;
	}
}

void ApiClient::setUserAgentHeader(const __FlashStringHelper *useragent_header) {
	this->useragent_header.u.flashstring_ptr = useragent_header;
	this->useragent_header.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void ApiClient::setUserAgentHeader(const String *useragent_header) {
	this->useragent_header.u.string_ptr = useragent_header;
	this->useragent_header.type = POINTER_UNION_TYPE_STRING;
}

void ApiClient::setUserAgentHeader(const char *useragent_header) {
	this->useragent_header.u.char_ptr = useragent_header;
	this->useragent_header.type = POINTER_UNION_TYPE_CHAR;
}

void ApiClient::getUserAgentHeader() {
	switch(useragent_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(useragent_header.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*useragent_header.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(useragent_header.u.char_ptr);
			break;
		default:
			break;
	}
}

void ApiClient::addUserAgentHeader() {
	switch(useragent_header.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			request_buffer += useragent_header.u.flashstring_ptr;
			break;
		case POINTER_UNION_TYPE_STRING:
			request_buffer += *useragent_header.u.string_ptr;
			break;
		case POINTER_UNION_TYPE_CHAR:
			request_buffer += useragent_header.u.char_ptr;
			break;
		default:
			break;
	}
}

void ApiClient::printRequest() {
	Serial.println(request_buffer);
}

