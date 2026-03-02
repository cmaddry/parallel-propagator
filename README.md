# Parallel Computing Numerical Propagator
In this project, I will be implementing a numerical propagator capable of parallel computations. The initial version will leverage [OpenMP](https://www.openmp.org/) with a GPU version planned for the future. The details of this project can be found in this README.

## Background



## Mathematical Formulation
### Two-body Physics
Description can be found [here](https://gssc.esa.int/navipedia/index.php/Two-body_Problem).

We rewrite the two body mathematical equation into the two equations:

```math
\begin{align}
    a = \ddot{r} = \dot{v} = - \mu \frac{\vec{r}}{|\vec{r}|^3} \\ \dot{r} = v
\end{align}
```
With this, the equations becomes two first order ODEs, and we can now solve this with numerical integration methods.

Given $$\vec{r}$$, we can compute $$\dot{v}$$


### Perturbations
In the context of satellite motion, perturbations are additional forces that act on the satellite in orbit around the Earth. Simple two-body motion does not account for these additional forces, so we must add them to our model.

Because these perturbations are forces, they will effectively change the acceleration of our two-body motion. In practice, these perurbations will take the following form:

```math
\begin{align}
    a_{total} = a_{two \ body} + a_{J2} + a_{drag} + a_{3^{rd} \ body} + ...
\end{align}
```

where they change the effective acceleration of the satellite.


#### J2 Perturbation
The J2 perturbation (or gravitational perturbation) is a result of the Earth's shape. Instead of being a perfect sphere, Earth has a slight bulge near the equator. 

To account for this irregular shape, the J2 perturbation is added to our model.

```math
\begin{align}
    a_{x} &= \ kx\Big(5 \frac{z^2}{r^2} - 1\Big) \\ a_{y} &= \ ky\Big(5 \frac{z^2}{r^2} - 1\Big) \\ a_{z} &= \ kz\Big(5 \frac{z^2}{r^2} - 3\Big)
\end{align}
```

where 
```math
\begin{align}
    k = \frac{3}{2} \times J2 \times \mu \times R_e^2 / r^5
\end{align}
```

and 

```math
\begin{align}
    \mu &= 3.986004418\times 10^{14} \ m^3/s^2 \\ R_e^2 &= 6378137.0 \ m\\ r^5 &= 1.08262668 \times 10^{-3}
\end{align}
```



The derivation of which can be found in Bate, R., Mueller, D., White, J., *Fundamentals of Astrodynamics*, Dover, 1971.




### Numerical Integration 
#### Runge-Kutta Methods


## Code implementation