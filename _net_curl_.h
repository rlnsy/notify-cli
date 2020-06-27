//
// Copyright (c) 2020, Rowan Lindsay
//

#ifndef _NET_CURL_H_
#define _NET_CURL_H_

#define _MAXPARAMLN_ 512

typedef struct
{
	char* _req_url_;
	char _reg_params_[_MAXPARAMLN_];
	int _error_;
} _post_struct_;

int  _post_(_post_struct_ pst);

#define _MAXRESLN_ 2048

typedef struct
{
    size_t _nb_;
    char _dat_[_MAXRESLN_ + 1];
} _res_data_;

size_t _store_dat_(char* ptr, size_t size, size_t nmemb, _res_data_* data);

#endif