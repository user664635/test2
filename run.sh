clang  -Wall -Ofast -S test/test.c -o a.asm &&\
clang -lm -fuse-ld=mold a.asm &&\
./a.out
