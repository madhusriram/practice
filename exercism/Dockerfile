# Downloads exercism files to work on it and places it inside an appropriate git location
FROM ubuntu:18.04

MAINTAINER "Madhu Sriramu(madhusirmv@gmail.com)"

RUN apt-get update && apt-get install -y \
	wget \
	vim

WORKDIR /source

# Build exercism from sources
RUN wget https://github.com/exercism/cli/releases/download/v3.0.5/exercism-linux-64bit.tgz && \
    tar xzf exercism-linux-64bit.tgz && \
    mv exercism /usr/local/bin/

ADD configure_exercism.sh /source/
RUN chmod +x configure_exercism.sh

CMD ["./configure_exercism.sh"]
