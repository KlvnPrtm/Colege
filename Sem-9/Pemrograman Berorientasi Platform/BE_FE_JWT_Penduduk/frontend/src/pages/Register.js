import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate, Link } from 'react-router-dom';

const Register = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [errorMsg, setErrorMsg] = useState('');
  const [successMsg, setSuccessMsg] = useState('');
  const navigate = useNavigate();

  const handleRegister = (e) => {
    e.preventDefault();
    setErrorMsg('');
    setSuccessMsg('');

    axios.post('http://localhost:5000/register', {
      username,
      password,
    })
    .then(() => {
      setSuccessMsg('Registrasi berhasil! Silakan login.');
      setTimeout(() => navigate('/login'), 1500); // otomatis redirect
    })
    .catch(err => {
      const msg = err.response?.data?.message || 'Gagal registrasi';
      setErrorMsg(msg);
    });
  };

  return (
    <div style={{ padding: '20px' }}>
      <h2>Register</h2>
      {errorMsg && <p style={{ color: 'red' }}>{errorMsg}</p>}
      {successMsg && <p style={{ color: 'green' }}>{successMsg}</p>}
      <form onSubmit={handleRegister}>
        <div>
          <label>Username: </label>
          <input value={username} onChange={e => setUsername(e.target.value)} required />
        </div>
        <div>
          <label>Password: </label>
          <input type="password" value={password} onChange={e => setPassword(e.target.value)} required />
        </div>
        <button type="submit">Register</button>
      </form>
      <p>Sudah punya akun? <Link to="/login">Login di sini</Link></p>
    </div>
  );
};

export default Register;
