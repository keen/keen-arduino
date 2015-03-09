
#ifndef KEENCLIENT_H_
#define KEENCLIENT_H_

#include "ApiClient.h"

class KeenClient : public ApiClient {
public:
	KeenClient();
	
	void addEvent(const __FlashStringHelper *event_collection,
		      const __FlashStringHelper *event_body);
	void addEvent(const String *event_collection,
		      const String *event_body);
	void addEvent(const char *event_collection,
		      const char *event_body);

	void addEvents(const __FlashStringHelper *events);
	void addEvents(const String *events);
	void addEvents(const char *events);

	void setApiVersion(const __FlashStringHelper *api_version);
	void setApiVersion(const String *api_version);
	void setApiVersion(const char *api_version);
	void getApiVersion();

	void setProjectId(const __FlashStringHelper *project_id);
	void setProjectId(const String *project_id);
	void setProjectId(const char *project_id);
	void getProjectId();

	void setWriteKey(const __FlashStringHelper *write_key);
	void setWriteKey(const String *write_key);
	void setWriteKey(const char *write_key);
	void getWriteKey();

	void setReadKey(const __FlashStringHelper *read_key);
	void setReadKey(const String *read_key);
	void setReadKey(const char *read_key);
	void getReadKey();

	void setMasterKey(const __FlashStringHelper *master_key);
	void setMasterKey(const String *master_key);
	void setMasterKey(const char *master_key);
	void getMasterKey();

private:
	StringPointer api_version;
	StringPointer project_id;
	StringPointer write_key;
	StringPointer read_key;
	StringPointer master_key;
};

#endif /* KEENCLIENT_H_ */
