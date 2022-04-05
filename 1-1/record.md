
## conatiner memory limit 4G

```
Time for Sparse Ax, nrows=100, nnz=460, T = 0.000001
Time for Sparse Ax, nrows=100, nnz=460, T = 0.000001
Time for Sparse Ax, nrows=10000, nnz=49600, T = 0.000141
Time for Sparse Ax, nrows=10000, nnz=49600, T = 0.000039
Time for Sparse Ax, nrows=1000000, nnz=4996000, T = 0.013048
Time for Sparse Ax, nrows=1000000, nnz=4996000, T = 0.003869
Time for Sparse Ax, nrows=9000000, nnz=44988000, T = 0.117536
Time for Sparse Ax, nrows=9000000, nnz=44988000, T = 0.055164
Time for Sparse Ax, nrows=100000000, nnz=499960000, T = 45.226684
Time for Sparse Ax, nrows=100000000, nnz=499960000, T = 48.251460
```

check container memory limit
https://blog.csdn.net/hknaruto/article/details/107511106

## container memory unlimited

```
Time for Sparse Ax, nrows=100, nnz=460, T = 0.000002
Time for Sparse Ax, nrows=100, nnz=460, T = 0.000000
Time for Sparse Ax, nrows=10000, nnz=49600, T = 0.000135
Time for Sparse Ax, nrows=10000, nnz=49600, T = 0.000038
Time for Sparse Ax, nrows=1000000, nnz=4996000, T = 0.012939
Time for Sparse Ax, nrows=1000000, nnz=4996000, T = 0.003883
Time for Sparse Ax, nrows=100000000, nnz=499960000, T = 1.298301
Time for Sparse Ax, nrows=100000000, nnz=499960000, T = 0.327222
```

c = time / nnz / 2