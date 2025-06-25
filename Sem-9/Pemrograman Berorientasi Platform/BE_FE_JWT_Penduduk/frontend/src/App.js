import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Select from './pages/Select';
import Insert from './pages/Insert';
import Update from './pages/Update';
import Login from './pages/Login';
import Register from './pages/Register';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Select />} />
        <Route path="/insert" element={<Insert />} />
        <Route path="/update/:id" element={<Update />} />
        <Route path="/login" element={<Login />} />
        <Route path="/register" element={<Register />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
