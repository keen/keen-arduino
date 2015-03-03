/*
 * KeenClient.cpp
 */

#include "KeenClient.h"

KeenClient::KeenClient() {
	this->project_id = String("");
	this->write_key = String("");
	this->read_key = String("");
	this->master_key = String("");
}

void KeenClient::setProjectId(String &project_id) {
	this->project_id = project_id;
}

void KeenClient::setProjectId(const char *project_id) {
	this->project_id = String(project_id);
}

void KeenClient::setWriteKey(String &write_key) {
	this->write_key = write_key;
}

void KeenClient::setWriteKey(const char *write_key) {
	this->write_key = String(write_key);
}

void KeenClient::setReadKey(String &read_key) {
	this->read_key = read_key;
}

void KeenClient::setReadKey(const char *read_key) {
	this->read_key = String(read_key);
}

void KeenClient::setMasterKey(String &master_key) {
	this-> master_key = master_key;
}

void KeenClient::setMasterKey(const char *master_key) {
	this-> master_key = String(master_key);
}

void KeenClient::addEvent(String &event_collection, String &json_event) {
	if( write_key.length() > 0 ) {
		setAuthorizationHeader(write_key);
		String url = "https://api.keen.io/3.0/projects/";
		url += project_id;
		url += "/events/";
		url += event_collection;
		post(url, json_event);
	}	
}

void KeenClient::addEvent(const char *event_collection, const char *json_event) {
	String _event_collection = String(event_collection);
	String _json_event = String(json_event);
	addEvent(_event_collection, _json_event);
}

void KeenClient::addEvents(String &json_events) {
	if( write_key.length() > 0 ) {
		setAuthorizationHeader(write_key);
		String url = "https://api.keen.io/3.0/projects/";
		url += project_id;
		url += "/events";
		post(url, json_events);
	}
}

void KeenClient::addEvents(const char *json_events) {
	String _json_events = String(json_events);
	addEvents(_json_events);
}

