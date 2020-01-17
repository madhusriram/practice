FROM ubuntu:18.04

MAINTAINER "Madhu Sriramu(madhusirmv@gmail.com)"

RUN apt-get update && apt-get install -y \
	g++ \
	libgtest-dev \
	cmake

RUN cd /usr/src/gtest && cmake CMakeLists.txt && make && cp *.a /usr/lib

WORKDIR /source 

ADD runTests.sh .
RUN chmod +x runTests.sh

CMD ["./runTests.sh"]
