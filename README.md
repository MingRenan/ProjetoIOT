# 🌿 Projeto Umidade - Node.js + Express + PostgreSQL + Prisma

Este projeto é uma API que recebe dados de **umidade** e salva no banco de dados **PostgreSQL** usando **Prisma ORM**.

---

## 🚀 Tecnologias usadas

- [Node.js](https://nodejs.org/)
- [Express](https://expressjs.com/)
- [PostgreSQL](https://www.postgresql.org/)
- [Prisma ORM](https://www.prisma.io/)

---

## 📦 Instalação

### 1. Clone o repositório

```bash
git clone https://github.com/seu-usuario/seu-projeto.git
cd seu-projeto
```

### 2. Instale as dependências

```bash
npm install
```

---

## ⚙️ Configuração do Banco de Dados

Certifique-se de que seu servidor PostgreSQL esteja **ativo**.

- Banco de dados: `postgres`
- Porta: `5433` (ou ajuste conforme sua instalação)
- Usuário: `postgres`
- Senha: `sua_senha`

### 3. Configure o arquivo `.env`

Crie um arquivo `.env` na raiz do projeto com o seguinte conteúdo:

```env
DATABASE_URL="postgresql://postgres:SENHA@localhost:5433/postgres"
```

- Substitua **SENHA** pela sua senha do banco.

---

## 🔥 Configurar o Prisma

### 4. Gerar o Prisma Client

```bash
npx prisma generate
```

### 5. Criar as migrações

```bash
npx prisma migrate dev --name criar_tabela_umidade
```

Se ocorrer erro de "drift" (diferença entre o banco e as migrações), execute:

```bash
npx prisma migrate reset
```

Isso irá limpar o banco e aplicar as migrações novamente.

---

## 🚀 Rodando o Projeto

### 6. Inicie o servidor

```bash
node server.js
```

O servidor será iniciado em:

```
http://localhost:3000
```

---

## 📡 Endpoints

### POST `/umidade`

Recebe dados de umidade e salva no banco.

- Método: `POST`
- URL: `http://localhost:3000/umidade`
- Headers: `Content-Type: application/json`
- Body (JSON):

```json
{
  "umidade": 65
}
```

Resposta esperada:

```json
{
  "mensagem": "Dado recebido com sucesso"
}
```

Se enviar um dado inválido (por exemplo, texto), a API responde:

```json
{
  "erro": "Dado inválido"
}
```

---

## 🛠️ Prisma Studio

Visualize e edite seus dados no banco com uma interface web:

```bash
npx prisma studio
```

Isso abrirá automaticamente no navegador.

---

## 📋 Scripts úteis

| Comando | Descrição |
|:--------|:----------|
| `npm run dev` | Inicia o servidor com **nodemon** |
| `npx prisma generate` | Gera o Prisma Client |
| `npx prisma migrate dev` | Aplica migrações no banco |
| `npx prisma studio` | Abre o Prisma Studio para gerenciar o banco |

---

## ✅ Checklist para rodar o projeto

- [x] PostgreSQL instalado e rodando
- [x] `.env` configurado corretamente
- [x] Banco de dados acessível (`localhost:5433`)
- [x] Prisma Client gerado (`npx prisma generate`)
- [x] Migração criada (`npx prisma migrate dev --name criar_tabela_umidade`)
- [x] Servidor Node rodando (`npm run dev` ou `node server.js`)

---

## 📚 Aprendizados

- Conexão entre **Node.js** e **PostgreSQL**.
- Criação de **API REST** usando **Express**.
- Utilização do **Prisma ORM** para modelagem e manipulação de banco de dados.
- Utilização do **Prisma Studio** para gerenciamento visual de dados.

---

## ✨ Melhorias Futuras

- Adicionar autenticação de usuários.
- Criar dashboard para visualizar a evolução da umidade.
- Enviar alertas por e-mail/SMS baseado em limites críticos.

---

## 🧑‍💻 Desenvolvido por

Renan Ming 🚀

---
