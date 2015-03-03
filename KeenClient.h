
#ifndef KEENCLIENT_H_
#define KEENCLIENT_H_

#include "ApiClient.h"

class KeenClient : public ApiClient {
public:
	KeenClient();

	void setProjectId(String &project_id);
	void setProjectId(const char *project_id);

	void setWriteKey(String &write_key);
	void setWriteKey(const char *write_key);

	void setReadKey(String &read_key);
	void setReadKey(const char *read_key);

	void setMasterKey(String &master_key);
	void setMasterKey(const char *master_key);

	void addEvent(String &event_collection, String &json_event);
	void addEvent(const char *event_collection, const char *json_event);

	void addEvents(String &json_events);
	void addEvents(const char *json_events);

private:
	String project_id;
	String write_key;
	String read_key;
	String master_key;
};

#endif /* KEENCLIENT_H_ */
