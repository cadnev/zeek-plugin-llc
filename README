# LLC packet analyzer
A plugin for [Zeek](https://github.com/zeek/zeek) that analyzes LLC packets

## Installation
## Manual:
```sh
$ cd /tmp/zeek/auxil
$ git clone https://github.com/cadnev/zeek-plugin-llc.git
$ cd zeek-plugin-llc
$ ./configure && make install
```

### From Dockerfile:
```dockerfile
FROM alpine:3.13
RUN apk add --no-cache zlib openssl libstdc++ libpcap libgcc
RUN apk add --no-cache -t .build-deps \
  bsd-compat-headers \
  libmaxminddb-dev \
  linux-headers \
  openssl-dev \
  libpcap-dev \
  python3-dev \
  zlib-dev \
  binutils \
  fts-dev \
  cmake \
  clang \
  bison \
  bash \
  swig \
  perl \
  make \
  flex \
  git \
  g++ \
  fts \
  openssh

RUN echo "===> Cloning zeek..." \
  && cd /tmp \
  && git clone --recursive --branch=v4.1.1 "https://github.com/zeek/zeek.git"

RUN echo "===> Compiling zeek..." \
  && cd /tmp/zeek \
  && CC=clang ./configure \
      --prefix=/usr/local/zeek \
      --build-type=Debug \
      --disable-broker-tests \
      --disable-zeekctl \
      --disable-auxtools \
      --disable-python \
      --disable-archiver \
      --disable-btest \
      --disable-btest-pcaps \
      --disable-zkg \
  && make -j $(nproc) \
  && make install

RUN echo "===> Installing zeek-llc package..." \
    && cd /tmp/zeek/auxil/ \
    && git clone https://github.com/cadnev/zeek-plugin-llc.git \
    && cd zeek-plugin-llc \
    && CC=clang ./configure --zeek-dist=/tmp/zeek \
    && make -j $(nproc) \
    && make install \
    && export ZEEK_PLUGIN_PATH=/tmp/zeek/auxil/zeek-plugin-llc/build \
    && /usr/local/zeek/bin/zeek -N Zeek::LLC
```

## Usage
```sh
$ /usr/local/zeek/bin/zeek -Cr sample.pcap
$ cat llc.log
DSAP: fe
SSAP: fe
Control: 3
```