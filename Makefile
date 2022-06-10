cc = g++

opencv_include_dir = C:/opencv-4.5.5/build/install/include
opencv_lib_dir = C:/opencv-4.5.5/build/install/x64/mingw/bin
opencv_lib = -lopencv_calib3d455 -lopencv_core455 -lopencv_dnn455 -lopencv_features2d455 -lopencv_flann455 -lopencv_gapi455 -lopencv_highgui455 -lopencv_imgcodecs455 -lopencv_imgproc455 -lopencv_ml455 -lopencv_objdetect455 -lopencv_photo455 -lopencv_stitching455 -lopencv_video455 -lopencv_videoio455 -lopencv_videoio_ffmpeg455_64

wx_include_dir = C:/wxWidgets-3.1.6/lib/gcc_lib/mswu C:/wxWidgets-3.1.6/include
wx_lib_dir = C:/wxWidgets-3.1.6/lib/gcc_lib
wx_lib = -lwxmsw31u_gl -lopengl32 -lglu32 -lwxmsw31u_core  -lwxbase31u    -lwxtiff -lwxjpeg -lwxpng   -lwxzlib -lwxregexu -lwxexpat   -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lshlwapi -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lversion -lws2_32 -lwininet -loleacc -luxtheme

cflags += -std=c++17 -I$(opencv_include_dir) $(patsubst %,-I%,$(wx_include_dir))
libs += -L${opencv_lib_dir} $(opencv_lib) -L$(wx_lib_dir) $(wx_lib)

project = wxTest
include_dir = include
src_dir = src
obj_dir = obj
obj = $(subst src/,,$(subst .cpp,.o,$(wildcard src/*)))

.PHONY: all clean copy-dll

all: $(project) copy-dll

clean:
	rm -f obj/*
	rm -f *.dll
	rm -f $(project)

copy-dll:
	cp ${opencv_lib_dir}/* .

$(project): $(obj_dir)/$(obj)
	g++ -o $@ $^ $(libs)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	g++ -o $@ -c $^ $(cflags)
