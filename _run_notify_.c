//
// Copyright (c) 2020, Rowan Lindsay
//

#include <stdio.h>
#include <string.h>

#include "_net_curl_.h"
#include "_secrets_.h"

int main ()
{
    char* _MSG_ = "Hello there!";
    _post_struct_ p;
    memset(&p, 0, sizeof(_post_struct_));
    p._req_url_ = _SECRETS_NIURL_;
    sprintf(
        p._reg_params_, "user=%s&token=%s&message=%s",
        _SECRETS_USERN_,
        _SECRETS_TOKEN_,
        _MSG_);
    _post_(p);
    if (p._error_) return 1;
    return 0;
}