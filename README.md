# Parallel Computing Numerical Propagator
In this project, I will be implementing a numerical propagator capable of parallel computations. The initial version will leverage [OpenMP](https://www.openmp.org/) with a GPU version planned for the future.The details of this project can be found in this README.

## Background



## Mathematical Formulation
### Two-body Physics
Description can be found [here](https://gssc.esa.int/navipedia/index.php/Two-body_Problem).

We rewrite the two body mathematical equation into the two equations:

```math
\begin{align}
    a = \ddot{r} = \dot{v} - \mu \frac{\vec{r}}{|\vec{r}|^3} \\ \dot{r} = v
\end{align}
```
With this, the equations becomes two first order ODEs, and we can now solve this with numerical integration methods.

Given $$\vec{r}$$ , we can compute $$\dot{v}$$


### Numerical Integration 
#### Runge-Kutta Methods


## Code implementation