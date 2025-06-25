const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');

const app = express();
app.use(cors());
app.use(express.json());

const SECRET_KEY = 'your_secret_key'; // Ganti dengan env var untuk produksi

// Koneksi ke database MySQL
const db = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: '', // Ganti dengan password MySQL kamu
  database: 'latihan_database',
});

db.connect((err) => {
  if (err) {
    console.error('Database connection error:', err);
    return;
  }
  console.log('Connected to MySQL');
});

// ========== Middleware JWT ========== //
function authenticateToken(req, res, next) {
  const authHeader = req.headers['authorization'];
  const token = authHeader?.split(' ')[1];
  if (!token) return res.sendStatus(401);

  jwt.verify(token, SECRET_KEY, (err, user) => {
    if (err) return res.sendStatus(403);
    req.user = user;
    next();
  });
}

function authorizeRole(role) {
  return (req, res, next) => {
    if (req.user.role !== role) return res.sendStatus(403);
    next();
  };
}

// ========== AUTH ROUTES ========== //
  //register
app.post('/register', async (req, res) => {
    const { username, password, role = 'user' } = req.body;

  // Validasi
  if (!username || !password) return res.status(400).json({ message: 'Username dan password wajib diisi' });

  // Cek username sudah ada
  db.query('SELECT * FROM users2 WHERE username = ?', [username], async (err, result) => {
    if (err) return res.sendStatus(500);
    if (result.length > 0) return res.status(409).json({ message: 'Username sudah digunakan' });

    const hashedPassword = await bcrypt.hash(password, 10);
    db.query('INSERT INTO users2 (username, password, role) VALUES (?, ?, ?)', [username, hashedPassword, role], (err, result) => {
      if (err) return res.sendStatus(500);
      res.status(201).json({ message: 'Pendaftaran berhasil' });
    });
  });
});

// Login
app.post('/login', (req, res) => {
  const { username, password } = req.body;
  const query = 'SELECT * FROM users2 WHERE username = ?';
  db.query(query, [username], async (err, results) => {
    if (err) return res.sendStatus(500);
    if (results.length === 0) return res.status(401).json({ message: 'User tidak ditemukan' });

    const user = results[0];
    const valid = await bcrypt.compare(password, user.password);
    if (!valid) return res.status(401).json({ message: 'Password salah' });

    const token = jwt.sign({ id: user.id, role: user.role }, SECRET_KEY, { expiresIn: '1h' });
    res.json({ token });
  });
});

// ========== CRUD PENDUDUK ========== //

// Get all penduduk
app.get('/penduduk', authenticateToken, (req, res) => {
  db.query('SELECT * FROM tbpenduduk', (err, results) => {
    if (err) throw err;
    res.json(results);
  });
});

// Get by ID
app.get('/penduduk/:id', (req, res) => {
  const id = req.params.id;
  db.query('SELECT * FROM tbpenduduk WHERE id = ?', [id], (err, result) => {
    if (err) return res.status(500).json({ message: 'Query error' });
    res.json(result);
  });
});

// Insert data
app.post('/penduduk', authenticateToken, (req, res) => {
  const { nik, nama, alamat } = req.body;
  db.query('INSERT INTO tbpenduduk (nik, nama, alamat) VALUES (?, ?, ?)', [nik, nama, alamat], (err, result) => {
    if (err) throw err;
    res.json({ message: 'Data berhasil ditambahkan' });
  });
});

// Update data
app.put('/penduduk/:id', authenticateToken, (req, res) => {
  const { nik, nama, alamat } = req.body;
  db.query('UPDATE tbpenduduk SET nik=?, nama=?, alamat=? WHERE id=?', [nik, nama, alamat, req.params.id], (err, result) => {
    if (err) throw err;
    res.json({ message: 'Data berhasil diupdate' });
  });
});

// Delete data (admin only)
app.delete('/penduduk/:id', authenticateToken, authorizeRole('admin'), (req, res) => {
  db.query('DELETE FROM tbpenduduk WHERE id=?', [req.params.id], (err, result) => {
    if (err) throw err;
    res.json({ message: 'Data berhasil dihapus' });
  });
});

// ========== START SERVER ========== //
app.listen(5000, () => {
  console.log('Server berjalan di http://localhost:5000');
});
