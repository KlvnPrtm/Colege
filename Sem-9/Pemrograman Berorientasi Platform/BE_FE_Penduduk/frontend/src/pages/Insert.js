import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate } from 'react-router-dom';

const Insert = () => {
  const [form, setForm] = useState({ nik: '', nama: '', alamat: '' });
  const navigate = useNavigate();

  const handleSubmit = e => {
    e.preventDefault();
    axios.post('http://localhost:5000/penduduk', form)
      .then(() => navigate('/'));
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Tambah Data Penduduk</h2>
      <input placeholder="NIK" value={form.nik} onChange={e => setForm({...form, nik: e.target.value})} /><br />
      <input placeholder="Nama" value={form.nama} onChange={e => setForm({...form, nama: e.target.value})} /><br />
      <input placeholder="Alamat" value={form.alamat} onChange={e => setForm({...form, alamat: e.target.value})} /><br />
      <button type="submit">Simpan</button>
    </form>
  );
};

export default Insert;
