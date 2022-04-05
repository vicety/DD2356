[toc]

## 1

### What is the performance in total execution time  - do not consider data movement - according to your performance model on Dardel or your local computer for different sparse matrices  = 102, 104, 106, and 108? 

Measured
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

### What is the measured performance in total execution time and floating-point operations per second running spmv.c for different sizes  = 102, 104, 106, and 108? Compare the results from the performance model and experimental results. Discuss the comparison in the report.

```
1e2 1/c = NaN
1e4 1/c = 1.3053e9
1e6 1/c = 1.2866e9
1e8 1/c = 499960000 / 0.327222 = 1.5279e9
```

Theoretical
AMD Ryzen 5800x: base clock 3.8GHz, Max. Boost Clock Up to 4.7GHz 
(Using base clock) Assume 1 instruction per clock, then `1/c=3.8e9`, for boost clock `1/c=4.7e9`

(base clock) Measured / Theoretical = 0.402
(boost clock) Measured / Theoretical = 0.325

### What is the main reason for the observed difference between the modeled value and the measured value?

1. Other concurrent program
2. Executed on WSL2 (based on virtual machine)
3. maybe throughput from memory to cache



### What are the read bandwidth values you measure running spmv.c for different sizes  = 102, 104, 106, and 108?

#### for 1e8

Assuming perfect cache, memory load data needed = `nnz (sizeof(double) + sizeof(int)) + nrows (sizeof(double) + sizeof(int)) = nnz * 12 + nrows * 12`
memory save data need = `nrows sizeof(double)`
For 1e8, data needed = 599960000 * 12 = 7199520000 = 7.2e9 = 763MB, larger than cache

Tested with AIDA64
Memory Read 38232MB/s
Memory Write 21284MB/s
Assuming Perfect Cache, then we need 12Byte per MA instruction, which is about (38232MB/12B=3.34e9 MA/s), which gives a bound of 1/c to be under 3.34e9

Measured data throughput = data needed / time used = 7.2e9/0.327222 = 2.2e10 Byte/s = 20984 MB/s
Compared to 38232MB/s = 4e10 Byte/s

#### for others

1e6 5996000 * 12 / 0.003883 = 1.853e10
1e4 59600 * 12 / 0.000038 = 1.882e10
1e2 NaN

### What is the bandwidth you obtain by running the STREAM benchmark  Download STREAM benchmarkon your system? How does it compare to the bandwidth you measured in SpMV? Discuss the comparison. Compile the STREAM benchmark with:

```
This system uses 8 bytes per array element.
-------------------------------------------------------------
Array size = 10000000 (elements), Offset = 0 (elements)
Memory per array = 76.3 MiB (= 0.1 GiB).
Total memory required = 228.9 MiB (= 0.2 GiB).
Each kernel will be executed 10 times.
 The *best* time for each kernel (excluding the first iteration)
 will be used to compute the reported bandwidth.

Function    Best Rate MB/s  Avg time     Min time     Max time
Copy:           28581.3     0.005980     0.005598     0.007112
Scale:          28001.7     0.006087     0.005714     0.006667
Add:            31712.0     0.007955     0.007568     0.008878
Triad:          31213.4     0.007978     0.007689     0.009456
-------------------------------------------------------------
Solution Validates: avg error less than 1.000000e-13 on all three arrays
```

## 2

1. Report the name of the processor and the size of the L1, L2, and L3 of the processor you are benchmarking. You can check the specs of your processor online.
512KB 4MB 32MB
2. Create the memory mountain following the steps above.
Save the image of the displayed "memory mountain", and place the resulting image in your pdf file.
3. What region (array size, stride) gets the most consistently high performance (ignoring spikes in the graph that are noisy results...)? What is the read bandwidth reported? 
4. What region (array size, stride) gets the most consistently low performance (Ignoring spikes in the graph that are noisy results...)? What is the read bandwidth reported? 
5. When you look at the graph for stride=1, you (should) see relatively high performance compared to stride=32. This is true even for large array sizes that are much larger than the L3 cache size. How is this possible, when the array cannot possibly all fit into the cache? Your explanation should include a brief overview of hardware prefetching as it applies to caches.
TODO
6. What is temporal locality? What is spatial locality?
7. Adjusting the total array size impacts temporal locality, why? Will an increased array size increase or decrease temporal locality?

## 3

float二进制表示
http://www.binaryconvert.com/convert_double.html
hex转decimal
https://www.rapidtables.com/convert/number/hex-to-decimal.html

## reference

1. [AMD Ryzen™ 7 5800X Desktop Processors](https://www.amd.com/en/products/cpu/amd-ryzen-7-5800x)