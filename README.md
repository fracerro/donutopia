# Donutopia

# Compilation

Compile *only the library*:
```
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
```

Compile with testcases:

```
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build

```

# Demo

To compile demo programs (**after** compiling the library):
```
cd demo
make
```
Executables can be found in the folder demo/builds.
