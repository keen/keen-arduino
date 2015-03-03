/*
 * KeenClient.cpp
 */

#include "KeenClient.h"

KeenClient::KeenClient() {
	strcpy(this->project_id, "");
	strcpy(this->write_key, "");
	strcpy(this->read_key, "");
	strcpy(this->master_key, "");
}

void KeenClient::setProjectId(const char *project_id) {
	strcpy(this->project_id, project_id);
}

void KeenClient::setWriteKey(const char *write_key) {
	strcpy(this->project_id, write_key);
}

void KeenClient::setReadKey(const char *read_key) {
	strcpy(this->project_id, read_key);
}

void KeenClient::setMasterKey(const char *master_key) {
	strcpy(this->project_id, master_key);
}

void KeenClient::addEvent(const char *event_collection, const char *json_event) {
	if( sizeof(write_key) > 0 ) {
		setAuthorizationHeader(write_key);
		char url[257];
		strcpy(url, "https://api.keen.io/3.0/projects/");
		strcat(url, project_id);
		strcat(url, "/events/");
		strcat(url, event_collection);
		post(url, json_event);
	}	
}

void KeenClient::addEvents(const char *json_events) {
	if( sizeof(write_key) > 0 ) {
		setAuthorizationHeader(write_key);
		char url[257];
		strcpy(url, "https://api.keen.io/3.0/projects/");
		strcat(url, project_id);
		strcat(url, "/events");
		post(url, json_events);
	}
}

