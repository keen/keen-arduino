/*
 * KeenClient.cpp
 */

#include "KeenClient.h"

KeenClient::KeenClient() {
	setApiVersion(F("3.0"));
	setContentTypeHeader(F("application/json"));
	setUserAgentHeader(F("Arduino/0.1a"));
	resource.reserve(URI_SIZE);
}

void KeenClient::buildResource()
{
	resource = F("https://api.keen.io/");
	addApiVersion();
	resource += F("/projects/");
	addProjectId();
	resource += F("/events");
}

void KeenClient::buildResource(const __FlashStringHelper *event_collection)
{
	buildResource();
	resource += F("/");
	resource += event_collection;

}

void KeenClient::buildResource(const String &event_collection)
{
	buildResource();
	resource += F("/");
	resource += event_collection;

}

void KeenClient::buildResource(const char *event_collection)
{
	buildResource();
	resource += F("/");
	resource += event_collection;
}

void KeenClient::getResource()
{
	Serial.println(resource);
}

unsigned int KeenClient::addEvent(const __FlashStringHelper *event_collection,
		     const __FlashStringHelper *event_body)
{
	buildResource(event_collection);
	setAuthorizationHeader(write_key);
	return post(resource, event_body);
}

unsigned int KeenClient::addEvent(const String &event_collection,
		     const String &event_body)
{
	buildResource(event_collection);
	setAuthorizationHeader(write_key);
	return post(resource, event_body);
}

unsigned int KeenClient::addEvent(const char *event_collection,
		     const char *event_body)
{
	buildResource(event_collection);
	setAuthorizationHeader(write_key);
	return post(resource, event_body);
}

unsigned int KeenClient::addEvents(const __FlashStringHelper *events)
{
	buildResource();
	setAuthorizationHeader(write_key);
	return post(resource, events);
}

unsigned int KeenClient::addEvents(const String &events)
{
	buildResource();
	setAuthorizationHeader(write_key);
	return post(resource, events);
}

unsigned int KeenClient::addEvents(const char *events)
{
	buildResource();
	setAuthorizationHeader(write_key);
	return post(resource, events);
}

void KeenClient::setApiVersion(const __FlashStringHelper *api_version)
{
	this->api_version.u.flashstring_ptr = api_version;
	this->api_version.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void KeenClient::setApiVersion(const String *api_version)
{
	this->api_version.u.string_ptr = api_version;
	this->api_version.type = POINTER_UNION_TYPE_STRING;
}

void KeenClient::setApiVersion(const char *api_version)
{
	this->api_version.u.char_ptr = api_version;
	this->api_version.type = POINTER_UNION_TYPE_CHAR;
}

void KeenClient::getApiVersion()
{
	switch(api_version.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(api_version.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*api_version.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(api_version.u.char_ptr);
			break;
		default:
			break;
	}
}

void KeenClient::addApiVersion()
{
	switch(api_version.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			resource += api_version.u.flashstring_ptr;
			break;
		case POINTER_UNION_TYPE_STRING:
			resource += *api_version.u.string_ptr;
			break;
		case POINTER_UNION_TYPE_CHAR:
			resource += api_version.u.char_ptr;
			break;
		default:
			break;
	}
}

void KeenClient::setProjectId(const __FlashStringHelper *project_id)
{
	this->project_id.u.flashstring_ptr = project_id;
	this->project_id.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void KeenClient::setProjectId(const String *project_id)
{
	this->project_id.u.string_ptr = project_id;
	this->project_id.type = POINTER_UNION_TYPE_STRING;
}

void KeenClient::setProjectId(const char *project_id)
{
	this->project_id.u.char_ptr = project_id;
	this->project_id.type = POINTER_UNION_TYPE_CHAR;
}

void KeenClient::getProjectId()
{
	switch(project_id.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(project_id.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*project_id.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(project_id.u.char_ptr);
			break;
		default:
			break;
	}
}

void KeenClient::addProjectId()
{
	switch(project_id.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			resource += project_id.u.flashstring_ptr;
			break;
		case POINTER_UNION_TYPE_STRING:
			resource += *project_id.u.string_ptr;
			break;
		case POINTER_UNION_TYPE_CHAR:
			resource += project_id.u.char_ptr;
			break;
		default:
			break;
	}
}

void KeenClient::setWriteKey(const __FlashStringHelper *write_key)
{
	this->write_key.u.flashstring_ptr = write_key;
	this->write_key.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void KeenClient::setWriteKey(const String *write_key)
{
	this->write_key.u.string_ptr = write_key;
	this->write_key.type = POINTER_UNION_TYPE_STRING;
}

void KeenClient::setWriteKey(const char *write_key)
{
	this->write_key.u.char_ptr = write_key;
	this->write_key.type = POINTER_UNION_TYPE_CHAR;
}

void KeenClient::getWriteKey()
{
	switch(write_key.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(write_key.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*write_key.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(write_key.u.char_ptr);
			break;
		default:
			break;
	}
}

void KeenClient::setReadKey(const __FlashStringHelper *read_key)
{
	this->read_key.u.flashstring_ptr = read_key;
	this->read_key.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void KeenClient::setReadKey(const String *read_key)
{
	this->read_key.u.string_ptr = read_key;
	this->read_key.type = POINTER_UNION_TYPE_STRING;
}

void KeenClient::setReadKey(const char *read_key)
{
	this->read_key.u.char_ptr = read_key;
	this->read_key.type = POINTER_UNION_TYPE_CHAR;
}

void KeenClient::getReadKey()
{
	switch(read_key.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(read_key.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*read_key.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(read_key.u.char_ptr);
			break;
		default:
			break;
	}
}

void KeenClient::setMasterKey(const __FlashStringHelper *master_key)
{
	this->master_key.u.flashstring_ptr = master_key;
	this->master_key.type = POINTER_UNION_TYPE_FLASHSTRING;
}

void KeenClient::setMasterKey(const String *master_key)
{
	this->master_key.u.string_ptr = master_key;
	this->master_key.type = POINTER_UNION_TYPE_STRING;
}

void KeenClient::setMasterKey(const char *master_key)
{
	this->master_key.u.char_ptr = master_key;
	this->master_key.type = POINTER_UNION_TYPE_CHAR;
}

void KeenClient::getMasterKey()
{
	switch(master_key.type) {
		case POINTER_UNION_TYPE_FLASHSTRING:
			Serial.println(master_key.u.flashstring_ptr);
			break;
		case POINTER_UNION_TYPE_STRING:
			Serial.println(*master_key.u.string_ptr);
			break;
		case POINTER_UNION_TYPE_CHAR:
			Serial.println(master_key.u.char_ptr);
			break;
		default:
			break;
	}
}


