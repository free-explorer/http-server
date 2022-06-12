#include <iostream>
#include <uwebsockets/App.h>

using namespace std;

int main() {
	cout << "starting the server\n";

	// server code usign uwebsocket
	uWS::App()
		.get("/hello", [](auto* res, auto* req) {
		res->cork([res = std::move(res)]() {
			res->end("Hello World!");
		});
		})
		.get("/*", [](auto* res, auto* req) {
			res->cork([res = std::move(res)]() {
				res->end("Any Page");
			});
			})
		.listen(9001, [](auto* listenSocket) {
			if (listenSocket) {
				std::cout << "Listening for connections on port : 9001." << std::endl;
			}
			}).run();

			cout << "Shoot! We failed to listen and the App fell through, exiting now!" << std::endl;
}