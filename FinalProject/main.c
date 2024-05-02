#pragma comment(lib, "libcurl.lib")
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <curl/curl.h>
#include "minmax.h"

int main(void) {
    CURL* curl;
    CURLcode res;
    char poststring[200] /*, nam[100], prj[100]*/;// to generate dynamic data
    printf("Welcome to the library curl application\n ");
    struct min_max data = maxmin();
    sprintf(poststring, "max=%d&min=%d", data.max, data.min);
    printf("max =%d,min =%d\n", data.max, data.min);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e2302181/new.php");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststring);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_operation() failed : %s\n",
                curl_easy_strerror(res));
            curl_easy_cleanup(curl);
        }
        return 0;
    }
}
   
   
