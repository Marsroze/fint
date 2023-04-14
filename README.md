# fint

fint is a [`brainf**k`](https://en.wikipedia.org/wiki/Brainfuck#:~:text=The%20language's%20name%20is%20a,the%20boundaries%20of%20computer%20programming.) language interpreter.
It can interprete any valid brainf**ck code safely through:

- expression
- file

```sh
usage : fint.exe [-e expression] [filename]
```

## How to build

using Makefile :

```sh
make
```

Manually :

```sh
gcc -c src/intepreter.c
gcc -c src/main.c
gcc intepreter.o main.o -o fint.exe
```
