#Jhennifer Rodrigues, 14A

import os
import sys
import math

files = os.listdir()
files.pop(0)

def main(FILE_NAME):
    def calc(Xlist: list, Ylist: list):
        Xmean = sum(Xlist) / len(Xlist)
        Ymean = sum(Ylist) / len(Ylist)
        xy = []
        xx = []
        yy = []

        for i in range(len(Xlist)):
            xy.append((Xlist[i] - Xmean) * Ylist[i])

        Sxy = sum(xy)

        for x in Xlist:
            xx.append((x - Xmean) * x)

        Sxx = sum(xx)

        for y in Ylist:
            yy.append((y - Ymean) * y)

        Syy = sum(yy)

        return Sxy / math.sqrt((Sxx * Syy))

    try:
        if os.stat(FILE_NAME).st_size > 0:
            file = open(FILE_NAME)

        else:
            print("Arquivo vazio!")

    except FileNotFoundError:
        print("Arquivo não encontrado!")

    lines = file.readlines()
    values = []
    Xlist = []
    Ylist = []

    for line in lines:
        values.append(line.split(','))

    for i in range(len(values)):
        try:
            x = float(values[i][0])
            y = float(values[i][1])

        except ValueError:
            print("Os valores não são numéricos!")

        Xlist.append(x)
        Ylist.append(y)

    print(calc(Xlist, Ylist))
    file.close()

for file in files:
    print(f'\n{file} ->')
    main(file)

