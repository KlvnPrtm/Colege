import React, { useEffect, useState } from 'react';
import { getData, updateData } from '../api';
import { useNavigate, useParams } from 'react-router-dom';

const UpdatePage = () => {
  const { id } = useParams();
  const [form, setForm] = useState({ id: '', nik: '', nama: '', alamat: '' });
  const navigate = useNavigate();

  useEffect(() => {
    const fetchData = async () => {
      const res = await getData();
      const selected = res.data.find((d) => d.id === parseInt(id));
      if (selected) setForm(selected);
    };
    fetchData();
  }, [id]);

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    await updateData(form);
    navigate('/');
  };

  return (
    <div>
      <h2>Update Data</h2>
      <form onSubmit={handleSubmit}>
        <input name="nik" value={form.nik} onChange={handleChange} required />
        <input name="nama" value={form.nama} onChange={handleChange} required />
        <input name="alamat" value={form.alamat} onChange={handleChange} required />
        <button type="submit">Update</button>
      </form>
    </div>
  );
};

export default UpdatePage;
