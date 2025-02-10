# 

After finishing the below tasks, run the following commands to see if your code
is correct.

```shell
mkdir build && cd build
cmake ..
make -j4
make test
```

As an alternative to `make test` (or `ctest`) you can run the individual
`test_*` executables.
