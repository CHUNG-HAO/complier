#include <iostream>
#include <curl/curl.h>
#include <thread>

using namespace std;

int main() {
    CURL *curl;
    CURLcode res;
    string url;
    int times;

    cout << "Enter the URL: ";
    cin >> url;
    cout << "Enter the number of times to send: ";
    cin >> times;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        while(true) {
            for(int i = 0; i < times; i++){
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                res = curl_easy_perform(curl);
                if(res == CURLE_OK) {
                    cout << "Successfully connected to the website." << endl;
                } else {
                    cout << "Failed to connect to the website: " << curl_easy_strerror(res) << endl;
                }
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