
all: test

test: install
	cd bin; \
	LD_LIBRARY_PATH=. ./main

install:
	cd dlopen_dlsym && ${MAKE} install

clean:
	cd dlopen_dlsym && ${MAKE} clean
