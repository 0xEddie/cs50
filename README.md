# Compilation of work for cs50

In weeks 1-5, C programs are compiled using a makefile, which automatically uses clang to compile and some flags to specify output.

So instead of
```bash
make hello
```

we have to specify the output, and any libraries
```bash
clang hello.c -o hello -lcs50
```

## TODO
- finish figuring out the devenv for local C dev
