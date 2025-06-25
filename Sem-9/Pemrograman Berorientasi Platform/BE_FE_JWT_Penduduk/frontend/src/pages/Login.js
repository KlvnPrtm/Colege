import React, { useState } from 'react';
import axios from 'axios';
import { useNavigate, Link } from 'react-router-dom';

const Login = () => {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [errorMsg, setErrorMsg] = useState('');
  const navigate = useNavigate();

  const handleLogin = (e) => {
    e.preventDefault();
    axios.post('http://localhost:5000/login', { username, password })
      .then(res => {
        localStorage.setItem('token', res.data.token);
        navigate('/');
      })
      .catch(err => {
        const msg = err.response?.data?.message || 'Gagal login';
        setErrorMsg(msg);
      });
  };

  return (
    <div style={{ padding: '20px' }}>
      <h2>Login</h2>
      {errorMsg && <p style={{ color: 'red' }}>{errorMsg}</p>}
      <form onSubmit={handleLogin}>
        <div>
          <label>Username: </label>
          <input value={username} onChange={e => setUsername(e.target.value)} required />
        </div>
        <div>
          <label>Password: </label>
          <input type="password" value={password} onChange={e => setPassword(e.target.value)} required />
        </div>
        <button type="submit">Login</button>
      </form>
      <p>Belum punya akun? <Link to="/register">Daftar di sini</Link></p>
    </div>
  );
};

export default Login;
