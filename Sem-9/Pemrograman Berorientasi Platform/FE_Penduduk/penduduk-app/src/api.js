import axios from 'axios';

const API_BASE = 'http://localhost:67/api';

export const getData = () => axios.get(`${API_BASE}/getData`);
export const addData = (data) => axios.post(`${API_BASE}/add`, data);
export const updateData = (data) => axios.put(`${API_BASE}/update`, data);
export const deleteData = (id) => axios.delete(`${API_BASE}/delete/${id}`);
