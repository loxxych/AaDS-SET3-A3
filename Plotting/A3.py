import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("tests.csv")

sizes = df["size"]

def plot_compare(x, y1, y2, title, ylabel="Время (мс)"):
    plt.figure(figsize=(12, 6))
    plt.plot(x, y1, label="Quick Sort", linewidth=2)
    plt.plot(x, y2, label="Intro (quick+heap+insertion) Sort", linewidth=2)
    plt.title(title)
    plt.xlabel("N")
    plt.ylabel(ylabel)
    plt.grid(True)
    plt.legend()
    plt.show()

# Type 1
plot_compare(
    sizes,
    df["quick_random"],
    df["intro_random"],
    "Сравнение времени работы на случайных массивах"
)

# Type 2
plot_compare(
    sizes,
    df["quick_reverse"],
    df["intro_reverse"],
    "Сравнение времени работы на массивах, отсортированных в обратном порядке"
)

# Type 3
plot_compare(
    sizes,
    df["quick_almost"],
    df["intro_almost"],
    "Сравнение времени работы на почти отсортированных массивах"
)
