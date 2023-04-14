# fint

fint is a `brainf**k` language interpreter.
It can interprete any valid brainf**ck code safely through:

- expression
- file

```sh
usage : fint.exe [-e expression] [filename]
```

## How to compile

> using Makefile

```sh
make
```

> manually

```sh
gcc -c src/intepreter.c
gcc -c src/main.c
gcc intepreter.o main.o -o fint.exe
```
