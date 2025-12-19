# parallel-propagator



## Setup steps
### Setup OpenMP following [this](https://www.geeksforgeeks.org/installation-guide/openmp-introduction-with-installation-guide/) guide.

1. Sent the following command
```bash
echo |cpp -fopenmp -dM |grep -i open
```

2. Then
```bash
export OMP_NUM_THREADS=8
```



## Running
I created the [test_code](/test_code/) to see if OpenMP was working properly.

1. Chat wrote the test script [test.cpp](/test_code/test.cpp).

2. The code can be ran with the following command:
```bash
g++ -O3 -fopenmp test.cpp -o test_output
```
The following output is generated in the test_output file:
    Sum = 450000000
    Time = 0.103597 seconds
    Threads used = 8
