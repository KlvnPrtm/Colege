import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';

const Insert = () => {
  const [form, setForm] = useState({ nik: '', nama: '', alamat: '' });
  const navigate = useNavigate();
  const token = localStorage.getItem('token');
  const headers = { Authorization: `Bearer ${token}` };

  const handleSubmit = e => {
    e.preventDefault();
    axios.post('http://localhost:5000/penduduk', form, { headers })
      .then(() => navigate('/'))
      .catch(err => alert('Gagal insert'));
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Tambah Penduduk</h2>
      <input placeholder="NIK" value={form.nik} onChange={e => setForm({...form, nik: e.target.value})} required  /><br />
      <input placeholder="Nama" value={form.nama} onChange={e => setForm({...form, nama: e.target.value})} required  /><br />
      <input placeholder="Alamat" value={form.alamat} onChange={e => setForm({...form, alamat: e.target.value})} required  /><br />
      <button type="submit">Simpan</button>
    </form>
  );
};

export default Insert;
