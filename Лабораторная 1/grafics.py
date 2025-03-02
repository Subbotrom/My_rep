import numpy as np
import matplotlib.pyplot as plt

t1 = []
t2 = []
t3 = []
n = []

with open("file_10.txt", "r") as file:
        for i in range(710):
                a = file.readline()
                if i%2 == 0:
                        n.append(int(a))
                else:
                        t2.append(int(a))

with open("file_1.txt", "r") as file:
        for i in range(710):
                t = int(file.readline())
                if i%2 == 0:
                        t3.append(t)

with open("file_9.txt", "r") as file:
        for i in range(710):
                a = file.readline()
                if i%2 == 0:
                        pass
                else:
                        t1.append(int(a))
'''
with open("str_c_2.txt", "r") as file:
        for i in range(5000):
                t = int(file.readline())
                t3.append(t)'''

def grafic(t1, t2, n):
        plt.figure(figsize=(8, 6), dpi=100)
        plt.title("Время работы программы")
        plt.grid(True, linestyle="--")
        plt.xticks(range(0, 500100, 50000))
        plt.ylabel("$время$ $работы$, $ms$")  
        plt.xlabel("$размер$ $массива$, $n$")
        #plt.scatter(n, t1, c="red", s=1, label="Линейный поиск суммы")
        #plt.scatter(n, t3, c="red", s=1, label="Линейный поиск")
        plt.scatter(n, t1, c="green", s=1, label="Стратегия C (равномерное распределение)")
        plt.scatter(n, t2, c="orange", s=1, label="Стратегия C (неравномерное распределение)")
        #plt.scatter(n, t2, c="red", s=1, label="Линейный поиск суммы (+сортировка)")
        #plt.scatter(n, t2, c="green", s=1, label="Бинарный поиск")
        #plt.scatter(n, t2, c="green", s=1, label="Квадратичный поиск суммы")
        plt.legend(fontsize='large')
        plt.savefig("task_3_c.png")
grafic(t1, t2, n)
