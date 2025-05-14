import numpy as np

# Data tinggi badan
data = [170, 158, 159, 147, 171, 162, 155, 161, 170, 171,
        156, 149, 155, 160, 159, 147, 152, 163, 165, 149,
        150, 170, 164, 156, 166, 154, 172, 163, 156, 150,
        161, 157, 163, 164, 158, 148, 161, 160, 173, 175,
        169, 173, 165, 157, 149, 170, 168, 174, 168, 174]

# Menghitung nilai statistik
mean = np.mean(data)
median = np.median(data)
mode = max(set(data), key=data.count)
q1 = np.percentile(data, 25)
q2 = np.percentile(data, 50)
q3 = np.percentile(data, 75)
d6 = np.percentile(data, 60)
p10 = np.percentile(data, 10)
p50 = np.percentile(data, 50)
p90 = np.percentile(data, 90)
variance = np.var(data, ddof=1)
std_dev = np.std(data, ddof=1)

# Menampilkan hasil
print(f"Mean: {mean}")
print(f"Median: {median}")
print(f"Modus: {mode}")
print(f"Q1: {q1}")
print(f"Q2: {q2}")
print(f"Q3: {q3}")
print(f"D6: {d6}")
print(f"P10: {p10}")
print(f"P50: {p50}")
print(f"P90: {p90}")
print(f"Variansi: {variance}")
print(f"Standar Deviasi: {std_dev}")