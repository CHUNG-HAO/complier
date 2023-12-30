#include <iostream>
#include <curl/curl.h>
#include <thread>

using namespace std;

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        while(true) {
            for(int i = 0; i < 10; i++){
                curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/CHUNG-HAO");
                res = curl_easy_perform(curl);
                cout << "nice try to connect to website" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}