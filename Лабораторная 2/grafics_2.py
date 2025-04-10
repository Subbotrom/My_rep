import numpy as np
import matplotlib.pyplot as plt

l = 1000
lenth = []
perm_1 = []
perm_2 = []
perm_3 =[]
teor = []
time_1 = []
time_2 = []
time_3 = []
time_p = []

with open("shel_2_2.txt", "r") as file:
        for i in range(960):
                a = file.readline()
                if i%5 == 0:
                        lenth.append(l)
                        perm_1.append(int(a))
                elif i%5 == 1:
                        time_1.append(int(a))
                elif i%5 == 2:
                        perm_2.append(int(a))
                elif i%5 == 3:
                        time_2.append(int(a))
                else:
                        time_p.append(int(a))
                        l += l//50

with open("shel_05.txt", "r") as file:
        for i in range(384):
                a = file.readline()
                if i%2 == 0:
                        perm_3.append(int(a))
                elif i%2 == 1:
                        time_3.append(int(a))
                        

def grafic_perm():
        plt.figure(figsize=(8, 6), dpi=100)
        plt.title("Количество перестановок (логарифмический масштаб)")
        plt.grid(True, linestyle="--")
        plt.ylabel("$число$ $перестановок$, $ед.$")  
        plt.xlabel("$размер$ $массива$, $ед.$")
        plt.yscale("log")
        plt.xscale("log")
        k1 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(perm_1)), 1)[0]
        k2 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(perm_2)), 1)[0]
        k3 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(perm_3)), 1)[0]
        kp = 2
        plt.scatter(lenth, perm_2, c="red", s=5, label="Сортировка Шелла (шаг х 0.8) k = %.3f" %k2)
        plt.scatter(lenth, perm_3, c="green", s=5, label="Сортировка Шелла (шаг х 0.5) k = %.3f" %k3)
        plt.scatter(lenth, perm_1, c="blue", s=5, label="Сортировка Шелла Хиббард k = %.3f" %k1)   
        plt.scatter(lenth, (np.array(lenth)*(np.array(lenth)-1))/2, c="orange", s=5, label="Пузырек k = %.3f" %kp)
        plt.legend(fontsize='large')
        plt.show()

def grafic_time():
        plt.figure(figsize=(8, 6), dpi=100)
        plt.title("Время работы программы (логарифмический масштаб)")
        plt.grid(True, linestyle="--")
        plt.ylabel("$время$ $работы$, $с$")  
        plt.xlabel("$размер$ $массива$, $ед.$")
        plt.yscale("log")
        plt.xscale("log")
        k1 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(time_1)), 1)[0]
        k2 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(time_2)), 1)[0]
        k3 = np.polyfit(np.log(np.array(lenth)), np.log(np.array(time_3)), 1)[0]
        kp = np.polyfit(np.log(np.array(lenth)), np.log(np.array(time_p)), 1)[0]
        plt.scatter(lenth, time_2, c="red", s=5, label="Сортировка Шелла (шаг х 0.8) k = %.3f" %k2)
        plt.scatter(lenth, time_3, c="green", s=5, label="Сортировка Шелла (шаг х 0.5) k = %.3f" %k3)
        plt.scatter(lenth, time_1, c="blue", s=5, label="Сортировка Шелла Хиббард k = %.3f" %k1)   
        plt.scatter(lenth, time_p, c="orange", s=5, label="Пузырек k = %.3f" %kp)
        plt.legend(fontsize='large')
        plt.show()

grafic_perm()
