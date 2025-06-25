import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { useParams, useNavigate } from 'react-router-dom';

const Update = () => {
  const [form, setForm] = useState(null); // null untuk pengecekan awal
  const { id } = useParams();
  const navigate = useNavigate();
  const token = localStorage.getItem('token');
  const headers = { Authorization: `Bearer ${token}` };

  useEffect(() => {
    axios.get(`http://localhost:5000/penduduk/${id}`, { headers })
      .then(res => {
        if (res.data.length > 0) {
          setForm(res.data[0]);
        } else {
          alert('Data tidak ditemukan');
          navigate('/');
        }
      })
      .catch(err => {
        console.error(err);
        alert('Gagal mengambil data');
        navigate('/');
      });
  }, [id]);

  const handleSubmit = e => {
    e.preventDefault();
    axios.put(`http://localhost:5000/penduduk/${id}`, form, { headers })
      .then(() => navigate('/'))
      .catch(() => alert('Gagal update'));
  };

  // Tampilkan loading jika data belum siap
  if (!form) return <p>Loading...</p>;

  return (
    <form onSubmit={handleSubmit}>
      <h2>Update Penduduk</h2>
      <input placeholder="NIK" value={form.nik} onChange={e => setForm({...form, nik: e.target.value})} required  /><br />
      <input placeholder="Nama" value={form.nama} onChange={e => setForm({...form, nama: e.target.value})} required /><br />
      <input placeholder="Alamat" value={form.alamat} onChange={e => setForm({...form, alamat: e.target.value})} required /><br />
      <button type="submit">Update</button>
    </form>
  );
};

export default Update;
