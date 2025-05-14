import matplotlib.pyplot as plt
import numpy as np

# Membuat nilai x
x = np.linspace(-10, 10, 400)
# Fungsi y = 1/2 x + 5
y = 0.5 * x + 5

# Membuat plot
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='y = 1/2x + 5', color='blue')
plt.axhline(0, color='black', linewidth=1)  # sumbu x
plt.axvline(0, color='black', linewidth=1)  # sumbu y
plt.grid(True, which='both')
plt.title('Grafik y = 1/2x + 5')
plt.xlabel('x')
plt.ylabel('y')

# Titik-titik penting
x_vals = [-6, 0, 2, 4]
y_vals = [0.5 * x + 5 for x in x_vals]
plt.scatter(x_vals, y_vals, color='red')
for xv, yv in zip(x_vals, y_vals):
    plt.text(xv, yv + 0.3, f'({xv}, {yv})', fontsize=9, ha='center')

plt.legend()
plt.show()
