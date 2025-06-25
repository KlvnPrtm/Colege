const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const bodyParser = require('body-parser');

const app = express();
app.use(cors());
app.use(bodyParser.json());

const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '', // Ganti dengan password MySQL
  database: 'latihan_database'
});

db.connect(err => {
  if (err) throw err;
  console.log('MySQL Connected');
});


// Get all data
app.get('/penduduk', (req, res) => {
  db.query('SELECT * FROM tbpenduduk', (err, results) => {
    if (err) throw err;
    res.json(results);
  });
});

// Get single data
app.get('/penduduk/:id', (req, res) => {
  db.query('SELECT * FROM tbpenduduk WHERE id = ?', [req.params.id], (err, results) => {
    if (err) throw err;
    res.json(results[0]);
  });
});

// Insert data
app.post('/penduduk', (req, res) => {
  const { nik, nama, alamat } = req.body;
  db.query('INSERT INTO tbpenduduk (nik, nama, alamat) VALUES (?, ?, ?)', [nik, nama, alamat], (err, result) => {
    if (err) throw err;
    res.send('Data inserted');
  });
});

// Update data
app.put('/penduduk/:id', (req, res) => {
  const { nik, nama, alamat } = req.body;
  db.query('UPDATE tbpenduduk SET nik=?, nama=?, alamat=? WHERE id=?', [nik, nama, alamat, req.params.id], (err, result) => {
    if (err) throw err;
    res.send('Data updated');
  });
});

// Delete data
app.delete('/penduduk/:id', (req, res) => {
  db.query('DELETE FROM tbpenduduk WHERE id=?', [req.params.id], (err, result) => {
    if (err) throw err;
    res.send('Data deleted');
  });
});

app.listen(5000, () => {
  console.log('Server running on port 5000');
});
