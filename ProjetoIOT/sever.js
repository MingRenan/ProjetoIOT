// ============================
// 📁 server.js (Express + Prisma)
// ============================
const express = require('express');
const { PrismaClient } = require('@prisma/client');
const path = require('path');

const app = express();
const port = 3000;

const prisma = new PrismaClient();

let ultimoComando = null;

app.use(express.json());
app.use(express.static(path.join(__dirname, 'public')));

// Rota de leitura de umidade
app.post('/umidade', async (req, res) => {
  const { umidade } = req.body;
  if (typeof umidade !== 'number') {
    return res.status(400).json({ erro: 'Dado inválido' });
  }
  try {
    const novoRegistro = await prisma.umidade.create({
      data: { umidade }
    });
    console.log(`🌿 Umidade registrada:`, novoRegistro);
    res.status(201).json({ mensagem: 'Dado salvo com sucesso', dado: novoRegistro });
  } catch (error) {
    console.error('Erro ao salvar no banco:', error);
    res.status(500).json({ erro: 'Erro interno ao salvar' });
  }
});

// Rota de envio de comando manual
app.post('/comando', (req, res) => {
  const { comando } = req.body;
  if (!comando) return res.status(400).json({ erro: 'Comando ausente' });

  ultimoComando = comando;
  console.log(`⚙️ Novo comando recebido: ${comando}`);
  res.status(200).json({ mensagem: 'Comando recebido' });
});

// Rota de leitura do próximo comando
app.get('/comando', (req, res) => {
  if (ultimoComando) {
    const comandoParaEnviar = ultimoComando;
    ultimoComando = null;
    res.json({ comando: comandoParaEnviar });
  } else {
    res.json({ comando: null });
  }
});

// Rota para retornar os últimos registros de umidade
app.get('/ultimos-dados', async (req, res) => {
  try {
    const registros = await prisma.umidade.findMany({
      orderBy: { id: 'desc' },
      take: 5
    });
    res.json(registros);
  } catch (error) {
    console.error('Erro ao buscar dados:', error);
    res.status(500).json({ erro: 'Erro ao buscar dados' });
  }
});







app.listen(port, () => {
  console.log(`🚀 API rodando em http://localhost:${port}`);
});
