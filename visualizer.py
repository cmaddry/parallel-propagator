import pandas as pd
import numpy as np
import plotly.express as px
import plotly.graph_objects as go

# Function that will allow me to create a sphere to act as the globe
def spherical_shell_mesh(radius=6.371e6, resolution=100):
    theta = np.linspace(0, 2*np.pi, resolution)
    phi = np.linspace(0, np.pi, resolution)
    
    theta, phi = np.meshgrid(theta, phi)
    
    x = radius * np.sin(phi) * np.cos(theta)
    y = radius * np.sin(phi) * np.sin(theta)
    z = radius * np.cos(phi)
    
    return x.flatten(), y.flatten(), z.flatten()

x, y, z = spherical_shell_mesh()


# Loads in the data from the output file
test_data = pd.read_csv('output/output.txt', names=["x","y","z"])


# Plotting of the globe and model output
fig = px.scatter_3d(test_data, x = "x", y = "y", z = "z", color="z")
fig.update_traces(marker=dict(size = 1, color = "#990066"))

fig.add_trace(go.Scatter3d(
    x=x,
    y=y,
    z=z,
    name="Earth Outline",
    mode="markers",
    marker=dict(size=0.4, color="#80b3ff"),
))

fig.show()