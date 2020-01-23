FROM ubuntu:18.04

MAINTAINER "Madhu Sriramu(madhusirmv@gmail.com)"

RUN apt-get update && apt-get install -y \
	g++ \
	gdb \
	libgtest-dev \
	cmake

RUN cd /usr/src/gtest && cmake CMakeLists.txt && make && cp *.a /usr/lib

WORKDIR /source 

ADD runTests.sh .
RUN chmod +x runTests.sh

LOCAL_GROUP_ID=$(id -g)
LOCAL_USER_ID=$(id -u)

RUN groupadd -g $LOCAL_GROUP_ID -o user
RUN useradd -s /bin/bash -u $LOCAL_USER_ID -g $LOCAL_GROUP_ID -N -o -m user

CMD ["./runTests.sh"]
