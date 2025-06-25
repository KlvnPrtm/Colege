import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { Link, useNavigate } from 'react-router-dom';

const Select = () => {
  const [data, setData] = useState([]);
  const navigate = useNavigate();

  // Decode JWT token untuk cek role
  const getUserRole = () => {
    try {
      const token = localStorage.getItem('token');
      if (!token) return null;
      const payload = JSON.parse(atob(token.split('.')[1]));
      return payload.role;
    } catch (error) {
      return null;
    }
  };

  const role = getUserRole();

   const logout = () => {
    localStorage.removeItem('token');
    navigate('/login');
  };



  useEffect(() => {
    axios
      .get('http://localhost:5000/penduduk', {
        headers: { Authorization: `Bearer ${localStorage.getItem('token')}` }
      })
      .then((res) => setData(res.data))
      .catch((err) => {
        if (err.response?.status === 401) {
          navigate('/login');
        }
      });
  }, [navigate]);

  const handleDelete = (id) => {
    if (!window.confirm('Yakin ingin menghapus data ini?')) return;

    axios
      .delete(`http://localhost:5000/penduduk/${id}`, {
        headers: { Authorization: `Bearer ${localStorage.getItem('token')}` }
      })
      .then(() => {
        setData(data.filter((item) => item.id !== id));
      })
      .catch((err) => {
        alert('Gagal menghapus data. Mungkin Anda bukan admin.');
        console.error(err);
      });
  };

  return (
    <div style={{ padding: '20px' }}>
      
      <h2>Data Penduduk</h2>
      <Link to="/insert">Tambah Data</Link> | <button onClick={logout}>Logout</button>
      <br /><br />
      <table border="1" cellPadding="8" cellSpacing="0">
        <thead>
          <tr>
            <th>ID</th>
            <th>NIK</th>
            <th>Nama</th>
            <th>Alamat</th>
            <th>Aksi</th>
          </tr>
        </thead>
        <tbody>
          {data.map((p) => (
            <tr key={p.id}>
              <td>{p.id}</td>
              <td>{p.nik}</td>
              <td>{p.nama}</td>
              <td>{p.alamat}</td>
              <td>
                <Link to={`/update/${p.id}`}>
                  <button>Update</button>
                </Link>
                &nbsp;
                {role === 'admin' && (
                  <button onClick={() => handleDelete(p.id)}>Delete</button>
                )}
              </td>
            </tr>
          ))}
          {data.length === 0 && (
            <tr>
              <td colSpan="5" align="center">Tidak ada data.</td>
            </tr>
          )}
        </tbody>
      </table>
    </div>
  );
};

export default Select;
