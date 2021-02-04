FROM openjdk:11 as javaapp_build

COPY --from=ocv_build /usr/local/opencv /usr/local/opencv
COPY ./src/Test.java /app/build/
WORKDIR /app/build

#javac -classpath /usr/local/opencv/share/java/opencv4/opencv-
RUN javac Test.java -classpath /usr/local/opencv/share/java/opencv4/opencv-451.jar

###########
FROM app_base as javaapp
RUN  apt update && apt install -y openjdk-11-jre
COPY --from=ocv_build /usr/local/opencv /usr/local/opencv
COPY --from=javaapp_build /app/build/Test.class /app/
WORKDIR /app
CMD [ "java", "-Djava.library.path=/usr/local/opencv/share/java/opencv4/" "-classpath /usr/local/opencv/share/java/opencv4/opencv-451.jar:" "Test" ]
