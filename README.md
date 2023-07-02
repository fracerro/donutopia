# Donutopia
Progetto per il corso "Programmazione per la Fisica", anno accademico 2022/2023.

# Compilazione

Con i test:
```
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build
```

Solo la libreria:
```
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build

```

# Demo

Per compilare i programmi di demo (dopo aver compilato la libreria):
```
cd demo
make
```
Nella cartella *builds* verranno generati gli eseguibili.
