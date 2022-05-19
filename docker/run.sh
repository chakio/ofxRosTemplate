#!/bin/bash

cd `dirname $0`

xhost +local:user
nvidia-docker &> /dev/null
if [ $? -ne 0 ]; then
    TAG=`../commonfiles/build.sh -u 1604 -r -p 2 -l action_graph -t`
    echo $TAG
    echo "=============================" 
    echo "=nvidia docker not installed="
    echo "============================="
else
    TAG="chakio/ofros"
    echo $TAG
    echo "=========================" 
    echo "=nvidia docker installed="
    echo "========================="
    docker run -it \
    --privileged \
    --runtime=nvidia \
    --env=DISPLAY=$DISPLAY \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --env="QT_X11_NO_MITSHM=1" \
    --rm \
    -v "/$(pwd)/global_ros_setting.sh:/ros_setting.sh" \
    -v "/$(pwd)/ros_workspace:/catkin_ws/" \
    -v "/$(pwd)/../ofxRosTemplete:/catkin_ws/src/ofxRosTemplete" \
    -v /etc/group:/etc/group:ro \
    -v /etc/passwd:/etc/passwd:ro \
    -v /etc/localtime:/etc/localtime:ro \
    -v /media:/media \
    -v /dev:/dev \
    --net host \
    $TAG
fi