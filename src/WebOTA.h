#include <Arduino.h>

#ifdef ESP8266
#include <ESP8266WebServer.h>
#endif
#ifdef ESP32
#include <WebServer.h>
#endif

class WebOTA {
	public:
		unsigned int port;
		String path = "";
		String mdns = "";

		int init(const unsigned int port, const char *path);
		int init(const unsigned int port);
		int init();
		void delay(unsigned int ms);

#ifdef ESP8266
		int add_http_routes(ESP8266WebServer *server, const char *path);
#endif
#ifdef ESP32
		int add_http_routes(WebServer *server, const char *path);
#endif

		int handle();

		void set_custom_html(char const * const html);

		int init_wifi(const char *mdns_hostname);


	private:
		bool init_has_run;
		char const * custom_html = NULL;
		String get_ota_html();
		long max_sketch_size();
		int init_mdns(const char *host);
		String ip2string(IPAddress ip);
};

extern WebOTA webota;
