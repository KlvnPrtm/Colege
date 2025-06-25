import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Insert from './pages/Insert';
import Select from './pages/Select';
import Update from './pages/Update';

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Select />} />
        <Route path="/insert" element={<Insert />} />
        <Route path="/update/:id" element={<Update />} />
      </Routes>
    </Router>
  );
}

export default App;
