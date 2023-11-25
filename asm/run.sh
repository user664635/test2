clang  -Wall -Ofast -march=x86-64-v4 -S main.c -o a.asm &&\
clang -lm -fuse-ld=mold a.asm &&\
./a.out
