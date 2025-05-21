<!DOCTYPE html>
<html>
<head>
    <title>Latihan Array Asosiatif Multidimensi</title>
    <style>
        table {
            border-collapse: collapse;
            width: 60%;
        }
        th, td {
            padding: 8px 12px;
            border: 1px solid black;
        }
        th {
            background-color: #1f4e78;
            color: white;
        }
    </style>
</head>
<body>
    <h2>Latihan – Gunakan Array Asosiatif Multidimensi</h2>

    <form method="GET" action="{{ route('matkul') }}">
        Filter Kode: <input type="text" name="kode" value="{{ request('kode') }}" />
        <button type="submit">Tampilkan</button>
    </form>

    <br>

    <table>
        <thead>
            <tr>
                <th>No</th>
                <th>Kode</th>
                <th>Nama</th>
                <th>SKS</th>
            </tr>
        </thead>
        <tbody>
            @forelse ($data as $index => $d)
                <tr>
                    <td>{{ $index + 1 }}</td>
                    <td>{{ $d['kode'] }}</td>
                    <td><strong>{{ $d['nama'] }}</strong></td>
                    <td>{{ $d['sks'] }}</td>
                </tr>
            @empty
                <tr>
                    <td colspan="4">Data tidak ditemukan.</td>
                </tr>
            @endforelse
        </tbody>
    </table>
</body>
</html>
