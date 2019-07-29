import sys
import os

path = r"C:\Users\tobys\Documents\GitHub\Geant4Box\build"#sys.argv[1] #Ordner
dirs = os.listdir( path )
#
# for dateien in dirs:
#     if dateien[:7]=="Edep_ZN":
#         #if dateien[0:1]
#       getrennt = dateien.split("_")
#       if getrennt[5] == "200":
#           temp = getrennt[0]
#           i = 0
#           while i < len(getrennt):
#               if i == 5:
#                 temp = temp +"_20_GeV"
#                 i=i+1
#               else:
#                 temp = temp +"_"+ getrennt[i]
#               i=i+1
#           os.rename(path+"/"+dateien, path+"/"+temp)

for dateien in dirs:
     if dateien[:7]=="Edep_Ed":
         #print(dateien[5:])
         os.rename(path+"/"+dateien, path+"/"+dateien[5:])
