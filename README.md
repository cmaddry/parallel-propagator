# parallel-propagator



## Setup steps
### Setup OpenMP following [this](https://www.geeksforgeeks.org/installation-guide/openmp-introduction-with-installation-guide/) guide.

1. Sent the following command
```bash
echo |cpp -fopenmp -dM |grep -i open
```


2. Got 
```bash 
#define _OPENMP 201511
```

3. Then
```bash
export OMP_NUM_THREADS=8
```
