//
// Copyright (c) 2020, Rowan Lindsay
//

#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

#include "_net_curl_.h"

size_t _store_dat_(char* ptr, size_t size, size_t nmemb, _res_data_* data)
{
    size_t _new_len_ = data -> _nb_ + nmemb;
    if (_new_len_ > _MAXRESLN_) return fprintf(stderr, "data buffer size exceeded!"), -1;
    memcpy(data -> _dat_ + data -> _nb_, ptr, nmemb);
    data -> _nb_ = _new_len_;
    return nmemb;
}

int _post_(_post_struct_ pst)
{
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* _session_ = curl_easy_init();
    if (!_session_) return 1;
    char _err_msg_[CURL_ERROR_SIZE];
    _res_data_ dat;
    memset(&dat, 0, sizeof(_res_data_));
    curl_easy_setopt(_session_, CURLOPT_URL, pst._req_url_);
    curl_easy_setopt(_session_, CURLOPT_POSTFIELDS, pst._reg_params_);
    curl_easy_setopt(_session_, CURLOPT_ERRORBUFFER, _err_msg_);
    curl_easy_setopt(_session_, CURLOPT_WRITEFUNCTION, &_store_dat_);
    curl_easy_setopt(_session_, CURLOPT_WRITEDATA, &dat);
    CURLcode _res_cd_ = curl_easy_perform(_session_);
    if (_res_cd_ != CURLE_OK) 
        fprintf(stderr, "request failed: %s\n", curl_easy_strerror(_res_cd_)),
        fprintf(stderr, "error: %s\n", _err_msg_),
        pst._error_ = 1;
    fprintf(stdout, "%s", dat._dat_);
    curl_easy_cleanup(_session_);
    curl_global_cleanup();
    return 0;
}
