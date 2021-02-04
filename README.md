# learning-docker-opencv
A template for building an opencv-based app on Docker

## To build OpenCV
- Download OpenCV source into opencvapp/src/OpenCV
- Run:
```
$cd opencvapp/
$docker image build -t ocv_build --target ocv_build . # for later java app build
$docker image build -t app_base --target app_base . # for later java app build
$docker image build -t app .
```
## To build a Java app using OpenCV
- Run:
```
 $cd javaapp 
 $docker image build -t javaapp .
``` 
