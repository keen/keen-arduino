
#ifndef KEENCLIENT_H_
#define KEENCLIENT_H_

#include <Arduino.h>
#include <Bridge.h>
#include <HttpClient.h>

class KeenClient : public HttpClient {
public:
	KeenClient();

	void setProjectId(String &project_id);
	void setWriteKey(String &write_key);
	void setReadKey(String &read_key);
	void setMasterKey(String &master_key);

private:
	String project_id;
	String write_key;
	String read_key;
	String master_key;
};

#endif /* KEENCLIENT_H_ */
