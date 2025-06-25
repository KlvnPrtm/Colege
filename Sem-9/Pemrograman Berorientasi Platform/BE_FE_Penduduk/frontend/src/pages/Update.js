import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { useParams, useNavigate } from 'react-router-dom';

const Update = () => {
  const { id } = useParams();
  const [form, setForm] = useState({ nik: '', nama: '', alamat: '' });
  const navigate = useNavigate();

  useEffect(() => {
    axios.get(`http://localhost:5000/penduduk/${id}`)
      .then(res => setForm(res.data));
  }, [id]);

  const handleSubmit = e => {
    e.preventDefault();
    axios.put(`http://localhost:5000/penduduk/${id}`, form)
      .then(() => navigate('/'));
  };

  return (
    <form onSubmit={handleSubmit}>
      <h2>Update Data Penduduk</h2>
      <input value={form.nik} onChange={e => setForm({...form, nik: e.target.value})} /><br />
      <input value={form.nama} onChange={e => setForm({...form, nama: e.target.value})} /><br />
      <input value={form.alamat} onChange={e => setForm({...form, alamat: e.target.value})} /><br />
      <button type="submit">Update</button>
    </form>
  );
};

export default Update;
