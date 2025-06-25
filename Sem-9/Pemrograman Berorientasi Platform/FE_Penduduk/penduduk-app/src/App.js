import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import SelectPage from './components/SelectPage';
import InsertPage from './components/InsertPage';
import UpdatePage from './components/UpdatePage';

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<SelectPage />} />
        <Route path="/insert" element={<InsertPage />} />
        <Route path="/update/:id" element={<UpdatePage />} />
      </Routes>
    </Router>
  );
}

export default App;
