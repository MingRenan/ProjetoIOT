const express = require('express');
const { PrismaClient } = require('@prisma/client');
const app = express();
const port = 3000;

const prisma = new PrismaClient();

app.use(express.json());

app.post('/umidade', async (req, res) => {
  const { umidade } = req.body;

  if (typeof umidade !== 'number') {
    return res.status(400).json({ erro: 'Dado inválido' });
  }

  try {
    const novoRegistro = await prisma.umidade.create({
      data: {
        umidade: umidade
      }
    });
    console.log(`🌿 Umidade registrada:`, novoRegistro);
    res.status(201).json({ mensagem: 'Dado salvo com sucesso', dado: novoRegistro });
  } catch (error) {
    console.error('Erro ao salvar no banco:', error);
    res.status(500).json({ erro: 'Erro interno ao salvar' });
  }
});

app.listen(port, () => {
  console.log(`🚀 API rodando em http://localhost:${port}`);
});
