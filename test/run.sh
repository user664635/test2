clang  -Wall -Ofast -march=native -S test.c -o a.asm &&\
clang -lm -fuse-ld=mold a.asm &&\
./a.out
