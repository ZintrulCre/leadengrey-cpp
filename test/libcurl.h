#include "include/std.h"
#include <curl/curl.h>

const char* url_arr[] = { "https://www.instagram.com/", "https://www.bilibili.com/" };
int url_len = GetArraySize(url_arr);

size_t write_data(void* buffer, size_t size, size_t count, void* stream) {
    (void)buffer;
    (void)stream;
    return size * count;
}

void MultiTest()
{
    CURLM* curl_multi_handle = curl_multi_init();

    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < url_len; ++i) {
        CURL* easy_handle = curl_easy_init();
        curl_easy_setopt(easy_handle, CURLOPT_NOSIGNAL, 1);
        curl_easy_setopt(easy_handle, CURLOPT_URL, url_arr[i]);
        curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(easy_handle, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(easy_handle, CURLOPT_POSTREDIR, CURL_REDIR_POST_ALL);

        curl_multi_add_handle(curl_multi_handle, easy_handle);
    }
    
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    printf("anchor1: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count());

    int handle_num = 0;
    do
    {
        curl_multi_wait(curl_multi_handle, nullptr, 0, 1000, nullptr);
        curl_multi_perform(curl_multi_handle, &handle_num);
    } while (handle_num > 0);

    std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();
    printf("anchor2: %ld ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(t3 - t2).count());

    int curl_msg_left_num = 0;
    CURLMsg* curl_msg = nullptr;
    while ((curl_msg = curl_multi_info_read(curl_multi_handle, &curl_msg_left_num)) != nullptr)
    {
        if (curl_msg->msg != CURLMSG_DONE)
        {
            continue;
        }

        int response_code = 0;
        curl_easy_getinfo(curl_msg->easy_handle, CURLINFO_RESPONSE_CODE, &response_code);
        printf("response_code: %d\n", response_code);
        printf("return code: %d, %s\n", curl_msg->data.result, curl_easy_strerror(curl_msg->data.result));

        char* effective_url = nullptr;
        curl_easy_getinfo(curl_msg->easy_handle, CURLINFO_EFFECTIVE_URL, &effective_url);
        if (effective_url)
        {
            printf("effective_url: %s\n",  effective_url);
        }

        curl_multi_remove_handle(curl_multi_handle, curl_msg->easy_handle);
        curl_easy_cleanup(curl_msg->easy_handle);
    }

    curl_multi_cleanup(curl_multi_handle);
}

void EasyTest()
{
    const char* ip = "...";
    const char* port = "...";
    const char* index = "...";
    char url[128] = "";
    strcat(url, ip);
    strcat(url, ":");
    strcat(url, port);
    strcat(url, "/");
    strcat(url, index);
    strcat(url, "/_doc/");
    printf("%s\n", url);

    const char* auth = "...";
    char auth_header[64] = "Authorization: Basic ";
    strcat(auth_header, auth);
    printf("%s\n", auth_header);
    
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		struct curl_slist *headers = nullptr;
		headers = curl_slist_append(headers, auth_header);
		headers = curl_slist_append(headers, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		const char *data = "{\r\n    \"name\": \"test\",\r\n    \"curl_msg\": \"test\"\r\n}";
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		res = curl_easy_perform(curl);
	    curl_easy_cleanup(curl);

        cout << res << endl;
	}
}