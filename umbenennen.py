import sys
import os

path = sys.argv[1] #Ordner
dirs = os.listdir( path )

for dateien in dirs:
    if dateien[-5:]==".root":
        print(dateien)
