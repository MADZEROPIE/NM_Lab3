import pandas as pd
import matplotlib.pyplot as plt

#data=pd.read_csv("./res.csv", sep=',')
#data.columns=["x","y","T"]

#print(data)


#plt.plot(data["x"],data["y"])
#plt.show()

#plt.plot(data[0],data[2])
#plt.show()


x = []
y = []
z = []

for line in open('res.csv', 'r'):
    values = [float(s) for s in line.split(sep=',')]
    x.append(values[0])
    y.append(values[1])
    z.append(values[2])

print(x)
print(y)
print(z)

plt.plot(x,y)
plt.show()


plt.plot(x,z)
plt.show()
