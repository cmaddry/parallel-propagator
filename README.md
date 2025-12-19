# Parallel Computing Numerical Propagator
In this project, I will be implementing a numerical propagator capable of parallel computations. The initial version will leverage [OpenMP](https://www.openmp.org/) with a GPU version planned for the future.The details of this project can be found in this README.

## Background



## Mathematical Formulation
### Two-body Physics
Description can be found [here](https://gssc.esa.int/navipedia/index.php/Two-body_Problem)

```math
\begin{align}
    a = \ddot{r} = \dot{v} - \mu \frac{\vec{r}}{|\vec{r}|^3} \\ \dot{r} = v
\end{align}
```



### Numerical Integration 
#### Runge-Kutta Methods


## Code implementation