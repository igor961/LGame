#!/bin/sh

git clone https://github.com/igor961/raylib.git ../raylib

cd ../raylib/src

make PLATFORM=PLATFORM_WEB -B

cd ~/project

make PLATFORM=PLATFORM_WEB -B
