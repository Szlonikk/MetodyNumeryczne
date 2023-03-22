import numpy as np

A1=np.array(([2.34332898, -0.11253278, -0.01485349, 0.33316649, 0.71319625],[
-0.11253278, 1.67773628, -0.32678856, -0.31118836, -0.43342631],
[-0.01485349, -0.32678856, 2.66011353, 0.85462464, 0.16698798],
[0.33316649, -0.31118836, 0.85462464, 1.54788582, 0.32269197],
[0.71319625,-0.43342631,0.16698798,0.32269197,3.27093538]))

A2=np.array(([2.34065520, -0.05353743, 0.00237792, 0.32944082, 0.72776588],
[-0.05353743, 0.37604149, -0.70698859, -0.22898376, -0.75489595],
[0.00237792, -0.70698859, 2.54906441, 0.87863502, 0.07309288],
[0.32944082, -0.22898376, 0.87863502, 1.54269444, 0.34299341],
[0.72776588, -0.75489595, 0.07309288, 0.34299341, 3.19154447]))

b=np.array([3.55652063354463, -1.86337418741501, 5.84125684808554, -1.74587299057388, 0.84299677124244])
b2=np.array([3.55652063354463+(10**-5), -1.86337418741501, 5.84125684808554, -1.74587299057388, 0.84299677124244])

resultA1b=np.linalg.solve(A1,b)
resultA1b2=np.linalg.solve(A1,b2)
resultA2b=np.linalg.solve(A2,b)
resultA2b2=np.linalg.solve(A2,b2)

print("Współczynnik uwarunkowania macierzy A1: ",np.linalg.cond(A1))
print("Współczynnik uwarunkowania macierzy A2: ",np.linalg.cond(A2))

print("WEKTOR ROZWIAZAN A1*y=b: ")
print(resultA1b)
print("WEKTOR ROZWIAZAN A1*y=b': ")
print(resultA1b2)
print("WEKTOR ROZWIAZAN A2*y=b: ")
print(resultA2b)
print("WEKTOR ROZWIAZAN A2*y=b': ")
print(resultA2b2)
print("\nMACIERZ A1")
print("Norma wektorowa dla y1-y':")
print(np.linalg.norm((resultA1b-resultA1b2)))
print("\nMACIERZ A2")
print("Norma wektorowa dla y1-y':")
print(np.linalg.norm((resultA2b-resultA2b2)))

