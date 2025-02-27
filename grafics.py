import numpy as np
import matplotlib.pyplot as plt

t1 = []
t2 = []
t3 = []
n = range(100, 500100, 100)

with open("lin_search.txt", "r") as file:
	for i in range(5000):
		t = file.readline()
		t2.append(int(t))
'''			
with open("honest_lin.txt", "r") as file:
        for i in range(2000):
                t = int(file.readline())
                t2.append(t)'''
with open("str_c.txt", "r") as file:
        for i in range(5000):
                t = int(file.readline())
                t1.append(t)

with open("str_c_2.txt", "r") as file:
        for i in range(5000):
                t = int(file.readline())
                t3.append(t)

def grafic(t1, t2, n):
        plt.figure(figsize=(8, 6), dpi=100)
        plt.title("Время работы программы")
        plt.grid(True, linestyle="--")
        plt.xticks(range(0, 500100, 50000))
        plt.ylabel("$время$ $работы$, $ms$")  
        plt.xlabel("$размер$ $массива$, $n$")
        #plt.scatter(n, t1, c="green", s=1, label="Линейный поиск суммы")
        #plt.scatter(n, t2, c="red", s=1, label="Линейный поиск")
        plt.scatter(n, t1, c="green", s=1, label="Стратегия C (равномерное распределение)")
        plt.scatter(n, t3, c="orange", s=1, label="Стратегия C (неравномерное распределение)")
        #plt.scatter(n, t2, c="red", s=1, label="Линейный поиск суммы (+сортировка)")
        #plt.scatter(n, t2, c="green", s=1, label="Бинарный поиск")
        #plt.scatter(n, t2, c="green", s=1, label="Квадратичный поиск суммы")
        plt.legend(fontsize='large')
        plt.savefig("c1.png")


