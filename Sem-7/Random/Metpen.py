import pandas as pd

# Generate dummy data for 100 respondents
data = {
    'No': list(range(1, 101)),
    'Frekuensi Penggunaan Gadget': ['Kurang dari 1 jam', '1-3 jam', '3-5 jam', 'Lebih dari 5 jam'] * 25,
    'Waktu Penggunaan': ['Pagi hari', 'Siang hari', 'Sore hari', 'Malam hari'] * 25,
    'Pengaruh Terhadap Interaksi Sosial': ['Sangat jarang', 'Jarang', 'Kadang-kadang', 'Tidak'] * 25,
    'Pengaruh Pada Hubungan': ['Sangat memengaruhi', 'Memengaruhi', 'Sedikit memengaruhi', 'Tidak memengaruhi'] * 25,
    'Rasa Cemas Ketika Tidak Ada Gadget': ['Sangat sering', 'Sering', 'Jarang', 'Tidak pernah'] * 25,
    'Perasaan Setelah Lama Menggunakan': ['Sangat lelah', 'Lelah', 'Sedikit lelah', 'Tidak lelah'] * 25,
    'Durasi Penggunaan Sebelum Tidur': ['Kurang dari 30 menit', '30 menit - 1 jam', '1-2 jam', 'Lebih dari 2 jam'] * 25,
    'Sulit Tidur Setelah Gunakan Gadget': ['Sangat sering', 'Sering', 'Kadang-kadang', 'Tidak pernah'] * 25
}

# Create DataFrame
df_dummy = pd.DataFrame(data)

# Save the data to a CSV file
file_path = "dummy_gadget_use_data.csv"
df_dummy.to_csv(file_path, index=False)

file_path
