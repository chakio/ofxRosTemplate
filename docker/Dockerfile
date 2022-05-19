# This is an auto generated Dockerfile for ros:ros-core
# generated from docker_images/create_ros_core_image.Dockerfile.em
FROM ubuntu:20.04
ARG USER=initial
ARG GROUP=initial
ARG UID=1000
ARG GID=${UID}
ARG SHELL=/bin/bash
#FROM $base_image
RUN echo base image: ${base_image}

#######################################################################
##                            Speeding up                            ##
#######################################################################
RUN sed -i 's@archive.ubuntu.com@ftp.jaist.ac.jp/pub/Linux@g' /etc/apt/sources.list

#######################################################################
##                      install common packages                      ##
#######################################################################
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
   pkg-config \
   apt-utils \
   wget \
   git \
   build-essential \ 
   net-tools \
   gedit \
   terminator \
   nautilus \
   software-properties-common \
   apt-transport-https \
   libopencv-dev \
   ffmpeg \
   x264 \
   libx264-dev \
   zip \
   unzip \
   usbutils \
   sudo \
   python3-pip \
   libusb-1.0-0-dev

#######################################################################
##                           install font                            ##
#######################################################################
RUN echo ttf-mscorefonts-installer msttcorefonts/accepted-mscorefonts-eula select true | debconf-set-selections 
RUN apt-get update && apt-get install -y ttf-mscorefonts-installer \
   msttcorefonts -qq 

RUN python3 -m pip install --upgrade pip
RUN apt-get install  -y python3-ruamel.yaml

#######################################################################
##                       install nvidia docker                       ##
#######################################################################
RUN apt-get install -y --no-install-recommends \
    libxau-dev \
    libxdmcp-dev \
    libxcb1-dev \
    libxext-dev \
    libx11-dev \
    mesa-utils \
    x11-apps

# nvidia-container-runtime
ENV NVIDIA_VISIBLE_DEVICES ${NVIDIA_VISIBLE_DEVICES:-all}
ENV NVIDIA_DRIVER_CAPABILITIES ${NVIDIA_DRIVER_CAPABILITIES:+$NVIDIA_DRIVER_CAPABILITIES,}graphics

RUN echo "/usr/local/nvidia/lib" >> /etc/ld.so.conf.d/nvidia.conf && \
    echo "/usr/local/nvidia/lib64" >> /etc/ld.so.conf.d/nvidia.conf

# Required for non-glvnd setups.
ENV LD_LIBRARY_PATH /usr/lib/x86_64-linux-gnu:/usr/lib/i386-linux-gnu${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}:/usr/local/nvidia/lib:/usr/local/nvidia/lib64


#######################################################################
##                            ros install                            ##
#######################################################################

# install packages
RUN apt-get update
RUN apt-get install -q -y \
    dirmngr \
    gnupg2 \
    lsb-release \
    curl

# setup sources.list
RUN echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list
# setup keys
RUN curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
RUN apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
RUN curl -sSL 'http://keyserver.ubuntu.com/pks/lookup?op=get&search=0xC1CF6E31E6BADE8868B172B4F42ED6FBAB17C654' | apt-key add -
RUN apt-get update 
RUN apt-get install -y \
    ros-noetic-desktop-full
 # install ros packages
ENV ROS_DISTRO noetic
COPY ./ros_entrypoint.sh /

RUN apt-get install -y \
    python3-rosdep \
    python3-rosinstall \ 
    python3-rosinstall-generator \ 
    python3-wstool \
    build-essential 
#######################################################################
##                   install additional packages                     ##
#######################################################################
WORKDIR  /
# setup environment
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

RUN apt-get update 
RUN apt-get install -y libopencv-dev \
    ros-noetic-map-server \
    ros-noetic-amcl \
    ros-noetic-teleop-twist-joy \
    ros-noetic-camera-calibration \
    ros-noetic-gmapping \
    ros-noetic-ros-numpy \
    ros-noetic-robot-state-publisher

ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["bash"]

RUN wget https://github.com/mongodb/mongo-c-driver/releases/download/1.4.2/mongo-c-driver-1.4.2.tar.gz -O /mongo-c-driver-1.4.2.tar.gz
RUN tar zxvf /mongo-c-driver-1.4.2.tar.gz -C /
RUN cd /mongo-c-driver-1.4.2 && ./configure && make
RUN cd /mongo-c-driver-1.4.2 && make install

RUN wget https://github.com/mongodb/mongo-cxx-driver/archive/r3.0.3.tar.gz
RUN tar zxvf r3.0.3.tar.gz
RUN cd /mongo-cxx-driver-r3.0.3/build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DLIBMONGOC_DIR=/usr/local -DLIBBSON_DIR=/usr/local ..
RUN cd /mongo-cxx-driver-r3.0.3/build && make EP_mnmlstc_core
RUN cd /mongo-cxx-driver-r3.0.3/build && make
RUN cd /mongo-cxx-driver-r3.0.3/build && make install


RUN apt-get install -y \
    gstreamer1.0-plugins-base \
    libsndfile1-dev \
    libopenal-dev \
    libpulse-dev \
    libglew-dev \
    liburiparser-dev \
    libglfw3-dev \
    librtaudio-dev \
    libpugixml-dev

RUN wget https://github.com/mongodb/mongo-c-driver/releases/download/1.4.2/mongo-c-driver-1.4.2.tar.gz -O /mongo-c-driver-1.4.2.tar.gz
RUN tar zxvf /mongo-c-driver-1.4.2.tar.gz -C /
RUN cd /mongo-c-driver-1.4.2 && ./configure && make
RUN cd /mongo-c-driver-1.4.2 && make install

RUN wget https://github.com/mongodb/mongo-cxx-driver/archive/r3.0.3.tar.gz
RUN tar zxvf r3.0.3.tar.gz
RUN cd /mongo-cxx-driver-r3.0.3/build && cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local -DLIBMONGOC_DIR=/usr/local -DLIBBSON_DIR=/usr/local ..
RUN cd /mongo-cxx-driver-r3.0.3/build && make EP_mnmlstc_core
RUN cd /mongo-cxx-driver-r3.0.3/build && make
RUN cd /mongo-cxx-driver-r3.0.3/build && make install

RUN sudo wget https://openframeworks.cc/versions/v0.11.2/of_v0.11.2_linux64gcc6_release.tar.gz  -O /of_v0.11.2_linux64gcc6_release.tar.gz 
RUN sudo tar -zxvf /of_v0.11.2_linux64gcc6_release.tar.gz  -C /
RUN cd /of_v0.11.2_linux64gcc6_release/scripts/linux/ubuntu && ./install_dependencies.sh -y
RUN cd /of_v0.11.2_linux64gcc6_release/scripts/linux && ./compileOF.sh -j3
RUN cd /of_v0.11.2_linux64gcc6_release/scripts/linux && ./compilePG.sh
RUN cd /of_v0.11.2_linux64gcc6_release/addons &&  git clone https://github.com/kylemcdonald/ofxCv
RUN rosdep init
RUN rosdep update
#######################################################################
##                         make sudoer user                          ##
#######################################################################

# ARG USER
# ARG USER_ID
# RUN groupadd -g 1000 developer && \
#     useradd  -g      developer -G sudo -m -u $USER_ID -s /bin/bash ${USER} && \
#     echo "${USER}:${USER}" | chpasswd

# RUN echo "Defaults visiblepw" >> /etc/sudoers
# RUN echo "${USER} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# USER ${USER}
RUN echo "export PS1='\[\e[1;31;40m\]OF_ROS\[\e[0m\] \u:\w\$ '">> ~/.bashrc
RUN echo "source /ros_setting.sh">> ~/.bashrc