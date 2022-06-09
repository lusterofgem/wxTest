cc = g++

cflags = `wx-config --cflags` -std=c++17
libs = `wx-config --libs gl`

project = wxTest
include_dir = include
src_dir = src
obj_dir = obj
obj = $(subst src/,,$(subst .cpp,.o,$(wildcard src/*)))

.PHONY: all clean

all: $(project)

clean:
	rm obj/*
	echo $(obj)

$(project): $(obj_dir)/$(obj)
	g++ -o $@ $^ $(libs)

$(obj_dir)/%.o: $(src_dir)/%.cpp
	g++ -o $@ -c $^ $(cflags)
