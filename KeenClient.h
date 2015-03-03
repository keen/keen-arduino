
#ifndef KEENCLIENT_H_
#define KEENCLIENT_H_

#include "ApiClient.h"

class KeenClient : public ApiClient {
public:
	KeenClient();

	void setProjectId(const char *project_id);
	void setWriteKey(const char *write_key);
	void setReadKey(const char *read_key);
	void setMasterKey(const char *master_key);
	void addEvent(const char *event_collection, const char *json_event);
	void addEvents(const char *json_events);

private:
	char project_id[257];
	char write_key[257];
	char read_key[257];
	char master_key[257];
};

#endif /* KEENCLIENT_H_ */
