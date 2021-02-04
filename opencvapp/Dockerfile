# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:8.4.0 as OpenCV_Build

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY ./src/OpenCV/ /usr/src/OpenCV/
WORKDIR /usr/src/OpenCV/build

# This command compiles your app using GCC, adjust for your source code
#RUN g++ -o myapp main.cpp
RUN apt update && apt install -y cmake
RUN apt install -y openjdk-11-jdk
RUN apt install -y ant
RUN apt install libeigen3-dev
ENV JAVA_HOME /usr/lib/jvm/java-11-openjdk-arm64
RUN cmake \
        -DCMAKE_INSTALL_PREFIX=/usr/local/opencv \
        -DBUILD_SHARED_LIBS=OFF\
        -DCMAKE_BUILD_TYPE=Release\
        -DWITH_1394=OFF -DWITH_EIGEN=OFF -DWITH_GSTREAMER=OFF\
        -DWITH_GTK=OFF -DWITH_GTK_2_X=OFF\
        -DWITH_IPP=OFF -DWITH_PROTOBUF=OFF\
        -DWITH_QUIRC=OFF \
        -DBUILD_opencv_js=OFF -DBUILD_opencv_app=OFF\
        -DBUILD_DOCS=OFF -DBUILD_EXAMPLES=OFF\
        -DBUILD_PACKAGE=OFF -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF\
        -DBUILD_JAVA=ON -DBUILD_OBJC=OFF \
        ..\
        && make && make install

LABEL Name=opencv4docker Version=0.0.1

#############################################
FROM gcc:8.4.0 as app_build
COPY --from=OpenCV_Build /usr/local/opencv /usr/local/opencv
COPY ./src/app /app
WORKDIR /app/build
ARG OCV_MAJOR_VER=4
RUN apt update && apt install -y cmake
RUN cmake .. -DOpenCVD_DIR=/usr/local/opencv/lib/cmake/opencv${OCV_MAJOR_VER}/
RUN make
# This command runs your application, comment out this line to compile only
#CMD ["./myapp"]
#############################################

FROM debian:buster as app_base
RUN apt update && apt install -y libtiff5 libpng16-16 libopenjp2-7 libopenexr23


#############################################
FROM app_base
#COPY --from=OpenCV_Build /usr/local/opencv /usr/local/opencv
COPY --from=app_build /app/build/Main /app/
WORKDIR /app
CMD ["./Main"]