Meeting participants: Chengyang Huang, Ziheng Zhang, Zhanbo Cui

In this meeting, We discussed exercises in assignment1, since we are from 2 groups, we also exchanged our solution on these exercises.

Points where we found interesting:
1. Performance drop due to aligned memory that evicts data at same cache line
2. How to avoid unexpected optimization by the compiler
3. The optimizations done by the compiler when we apply -O2 or even -O3 flags.

Points where we found challenging:
1. How to read assembly code, since we don't have much experience on this.
2. Reasoning why measured result is different from expected, for example, the measured result for spmv.c in exercise 1, since the possible reason like instruction pipelining is hard to be verified from the aspect of software.





2 Group discussion records for each question


We have found an interesting part in that we all present the ratio of theoretical calculation to experiment and we found that the value of this ratio varies. Since we know that the reason for this ratio has to do with the data being read and written. We are curious why different CPUs have different data read
rates and made a discussion.

We compared Core i5’s memory mountain with Core i7’s memory mountain. The read throughput of Core I7 drops only on the leftmost edge of the cache area, and the read throughput decreases with the increase of data size when the step size remains constant. We found that there are many
gullies in the Core i5’s memory mountain. When the step size is 1, the read throughput of 64K, 256K, and 1024K shows obvious depression, leading to the appearance of many peaks.


We learned together about the GNU compiler which provides the -O option for program optimization. We found that -the O2 option is a more advanced option than O1, with more optimization. GCC will perform almost all optimizations that do not involve time or space trade-offs. When the O2 option is set, the compiler does not do loop unrolling and inline functions. Compared to O1, O2 optimization increases compilation time based on improved execution efficiency of generated code.


For vectorization we are using the same gcc version 8.3.1, and we found that the related flags include -ftree-vectorize, -ftree-loop-vectorize, -ftree-slp-vectorize, -fvect-cost-model=model, -ftree-loop-if-convert.

3 Conclusions

In this task, We learned many ways to increase computing performance with
a special example (Matrix Multiply). Through memory mountain, we have learned how the catch works in the reading and writing option. We also learned different options of GNU program optimi