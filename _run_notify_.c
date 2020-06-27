//
// Copyright (c) 2020, Rowan Lindsay
//

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "_net_curl_.h"
#include "_secrets_.h"
#include "_pkg_info_.h"

int main (int argc, char**argv)
{
    _post_struct_ p;
    for (int opt; (opt = getopt(argc, argv, "vm:h")) != EOF;)
        switch (opt) {
            case 'v': 
                return fprintf(stdout, "Notify %s\n", _INFO_VERSION_);
                break;
            case 'm':
                memset(&p, 0, sizeof(_post_struct_));
                p._req_url_ = _SECRETS_NIURL_;
                sprintf(
                    p._reg_params_, "user=%s&token=%s&message=%s",
                    _SECRETS_USERN_,
                    _SECRETS_TOKEN_,
                    optarg);
                _post_(p);
                if (p._error_) return 1;
                break;
            case 'h':
                fprintf(stderr, "Usage: notify [-v|-m <message>]\n");
                break;
            case '?':
                return 1;
        }
    return 0;
}