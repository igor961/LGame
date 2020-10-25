#!/bin/sh

git clone https://github.com/raysan5/raylib.git ../raylib

cd ../raylib/src

make PLATFORM=PLATFORM_WEB -B

cd ~/project

make PLATFORM=PLATFORM_WEB -B
