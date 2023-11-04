FROM ubuntu:22.04

RUN apt-get update

# Copy necessary installation files
COPY SimplicityStudio_v4/setup.sh /tmp/
COPY SimplicityStudio_v4/StudioLinux /tmp/StudioLinux/
COPY an1121_headless_builds /opt/an1121_headless_builds
RUN apt-get install -y python2
COPY compile.sh /tmp/compile.sh

COPY SimplicityCommander-Linux /opt/SimplicityCommander-Linux

COPY slc_cli /opt/slc_cli
RUN apt-get install -y openjdk-17-jdk openjdk-17-jre

# Install Simplicity Studio
ENV DEBIAN_FRONTEND noninteractive
RUN dpkg --add-architecture i386 \
	&& apt-get update \
	&& apt-get install -y gnome-themes-standard \
	&& mkdir -p /etc/udev/rules.d \
	&& sed -i "s/sudo apt-get install/apt-get install -y/" "/tmp/setup.sh" \
	&& /tmp/setup.sh \
	&& apt-get autoremove --purge -y \
	&& apt-get clean
RUN rm -rf /tmp/setup.sh /tmp/StudioLinux

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
