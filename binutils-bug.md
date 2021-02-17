https://bugs.archlinux.org/task/69567

```
/usr/bin/avr-ld: error while loading shared libraries: libctf.so.0: cannot open shared object file: No such file or directory
collect2: error: ld returned 127 exit status
exit status 1
```

```
$ asp checkout avr-binutils
$ cd avr-binutils
$ git checkout 41cab1afc826c22d5e1049f1bb60ab9e9b714f7e
$ cd trunk
$ makepkg -sci
```

* needs gpg --recv-keys 13FCEF89DD9E3C4F
