#!/bin/sh

git clone https://github.com/igor961/raylib.git ../raylib

cd ../raylib/src

make PLATFORM=PLATFORM_WEB -B

cd ~/project

mkdir -p builds/web
emcc -o builds/web/game.html src/*.c src/utils/*.c -I ../raylib/src -L ../raylib/src -static -lraylib -lglfw -s USE_GLFW=3 -s FORCE_FILESYSTEM=1 -s ASYNCIFY -s TOTAL_MEMORY=67108864 --shell-file ../raylib/src/shell.html --preload-file assets
