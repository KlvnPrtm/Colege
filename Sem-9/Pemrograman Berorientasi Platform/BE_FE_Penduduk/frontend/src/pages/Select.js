import React, { useEffect, useState } from 'react';
import axios from 'axios';
import { Link } from 'react-router-dom';

const Select = () => {
  const [data, setData] = useState([]);

  const fetchData = () => {
    axios.get('http://localhost:5000/penduduk')
      .then(res => setData(res.data));
  };

  useEffect(() => {
    fetchData();
  }, []);

  const handleDelete = (id) => {
    axios.delete(`http://localhost:5000/penduduk/${id}`).then(() => fetchData());
  };

  return (
    <div>
      <h2>Data Penduduk</h2>
      <Link to="/insert">Tambah Penduduk</Link>
      <table border="1" cellPadding="10">
        <thead>
          <tr>
            <th>ID</th><th>NIK</th><th>Nama</th><th>Alamat</th><th>Aksi</th>
          </tr>
        </thead>
        <tbody>
          {data.map(p => (
            <tr key={p.id}>
              <td>{p.id}</td>
              <td>{p.nik}</td>
              <td>{p.nama}</td>
              <td>{p.alamat}</td>
              <td>
                <Link to={`/update/${p.id}`}>Update</Link> | 
                <button onClick={() => handleDelete(p.id)}>Delete</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default Select;
