import React, { useEffect, useState } from 'react';
import { getData, deleteData } from '../api';
import { useNavigate } from 'react-router-dom';

const SelectPage = () => {
  const [data, setData] = useState([]);
  const navigate = useNavigate();

  const loadData = async () => {
    const res = await getData();
    setData(res.data);
  };

  useEffect(() => {
    loadData();
  }, []);

  const handleDelete = async (id) => {
    if (window.confirm("Yakin ingin menghapus?")) {
      await deleteData(id);
      loadData();
    }
  };

  return (
    <div>
      <h2>Data List</h2>
      <button onClick={() => navigate('/insert')}>+ Tambah Data</button>
      <table border="1" cellPadding="10">
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
          {data.map((d) => (
            <tr key={d.id}>
              <td>{d.id}</td>
              <td>{d.nik}</td>
              <td>{d.nama}</td>
              <td>{d.alamat}</td>
              <td>
                <button onClick={() => navigate(`/update/${d.id}`)}>Edit</button>
                <button onClick={() => handleDelete(d.id)}>Hapus</button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default SelectPage;
