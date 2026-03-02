import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# Loads in the data from the output file
test_data = pd.read_csv('output/output.txt', names=["x","y","z"])


# Plotting of the globe and model output

plt.scatter(test_data["x"], test_data["y"], s=0.0001)

plt.show()