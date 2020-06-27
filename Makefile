CC = gcc
CFLAGS = -fpic -Wall -g
OBJS = _run_notify_.o _net_curl_.o
LDLIBS = -lcurl

all: notify

notify: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o notify

_run_notify_.o: _run_notify_.c _net_curl_.h
_net_curl_.o: _net_curl_.c _net_curl_.h

clean:
	rm -f *~ *.o notify

install: all
	cp notify ../bin/notify

remove:
	rm ../bin/notify
