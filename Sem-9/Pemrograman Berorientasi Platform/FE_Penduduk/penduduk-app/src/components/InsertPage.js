import React, { useState } from 'react';
import { addData } from '../api';
import { useNavigate } from 'react-router-dom';

const InsertPage = () => {
  const [form, setForm] = useState({ nik: '', nama: '', alamat: '' });
  const navigate = useNavigate();

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    await addData(form);
    navigate('/');
  };

  return (
    <div>
      <h2>Tambah Data</h2>
      <form onSubmit={handleSubmit}>
        <input name="nik" placeholder="NIK" onChange={handleChange} required />
        <input name="nama" placeholder="Nama" onChange={handleChange} required />
        <input name="alamat" placeholder="Alamat" onChange={handleChange} required />
        <button type="submit">Simpan</button>
      </form>
    </div>
  );
};

export default InsertPage;
