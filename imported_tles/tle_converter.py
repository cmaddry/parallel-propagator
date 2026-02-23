## This will convert a TLE to the RCI reference frame so that my propogator can 
## calculate.
from sgp4.api import Satrec
import csv

# Opens file and stores each line
with open("605_tle.txt", mode="r") as file:
    reader = csv.reader(file)
    lines = file.readlines()


# Ues the sgp4 package to calculate the rci reference frame from the TLE
satellite = Satrec.twoline2rv(lines[0], lines[1])
jd, fr = 2458826.5, 0.8625
e, r, v = satellite.sgp4(jd, fr)

# Saves the rci data to a .txt file
seperator = ","
with open("605_esi.txt", mode="w") as file:
    file.write(seperator.join(map(str, r)))
    file.write(',')
    file.write(seperator.join(map(str, v)))