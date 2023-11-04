FROM ubuntu:22.04

RUN apt update && \
    apt install -y gnupg build-essential git git-lfs ca-certificates libltdl-dev \
    ninja-build gcc-multilib pkg-config libffi-dev gcc-mingw-w64 cmake \
    autoconf autotools-dev automake autogen libtool m4 gettext wget qemu-system

ARG GCC_ARM_VERSION=10.3-2021.10
ARG GCC_ARM_RELEASE=gcc-arm-none-eabi-${GCC_ARM_VERSION}
ARG GCC_ARM_RELEASE_FILE=${GCC_ARM_RELEASE}-x86_64-linux.tar.bz2

WORKDIR /opt
RUN wget --progress=dot:giga https://developer.arm.com/-/media/Files/downloads/gnu-rm/${GCC_ARM_VERSION}/${GCC_ARM_RELEASE_FILE}
RUN tar -xjvf ${GCC_ARM_RELEASE_FILE}
RUN rm ${GCC_ARM_RELEASE_FILE}
WORKDIR /
ENV PATH="/opt/${GCC_ARM_RELEASE}/bin/:${PATH}"

# Print out installed version
RUN VERSION=$(arm-none-eabi-gcc -dumpversion); \
   echo "VERSION=$VERSION"

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8

# Clean up cache
RUN rm -rf /var/cache/apk/*
