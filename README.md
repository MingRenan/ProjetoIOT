# 🌿 Projeto Umidade - Node.js + Express + PostgreSQL + Prisma + Arduino

**Uma API REST para registrar e visualizar dados de umidade, integrada com Arduino via Python.**

---

## 🚀 Tecnologias

- **Back-end:** Node.js, Express
- **ORM:** Prisma
- **Banco de Dados:** PostgreSQL
- **Script Serial:** Python (pyserial, requests)
- **Serial Device:** Arduino

---

## 📂 Estrutura do Projeto

```
umidade-api/
├── prisma/                # Configurações e migrações do Prisma
│   ├── migrations/
│   └── schema.prisma
├── src/                   # Código-fonte da API
│   ├── controllers/       # Lógica de negócio
│   ├── routes/            # Definição de endpoints
│   ├── services/          # Comunicação com o banco e utilitários
│   └── app.js             # Configuração do Express
├── leitura/               # Script Python para leitura serial
│   └── leitura.py
├── .env                   # Variáveis de ambiente
├── .gitignore
├── package.json
├── server.js              # Ponto de entrada da aplicação
└── README.md              # Documentação
```

---

## 💻 Instalação e Configuração

### 1. Clone o repositório

```bash
git clone https://github.com/seu-usuario/umidade-api.git
cd umidade-api
```

### 2. Instale dependências

- **Node.js:**
  ```bash
  npm install
  ```  
- **Python (opcional, para Arduino):**
  ```bash
  pip install pyserial requests
  ```

### 3. Variáveis de ambiente

Crie um arquivo `.env` na raiz:

```env
DATABASE_URL="postgresql://postgres:senha@127.0.0.1:5433/postgres"
PORT=3000
```

- **DATABASE_URL:** string de conexão PostgreSQL
- **PORT:** porta onde a API irá rodar (padrão 3000)

---

## ⚙️ Banco de Dados e Prisma

1. **Gerar cliente Prisma**
   ```bash
   npx prisma generate
   ```
2. **Criar/atualizar migrações**
   ```bash
   npx prisma migrate dev --name init_umidade
   ```
3. **(Opcional) Resetar o banco em caso de drift**
   ```bash
   npx prisma migrate reset
   ```
4. **Abrir Prisma Studio**
   ```bash
   npx prisma studio
   ```

---

## 🚀 Executando a API

- **Modo padrão:**
  ```bash
  node server.js
  ```

- **Modo desenvolvimento (com nodemon):**
  ```bash
  npm run dev
  ```

Acesse em `http://localhost:3000`.

---

## 📡 Endpoints Disponíveis

### POST `/umidade`

Registrar um novo dado de umidade.

- **URL:** `/umidade`
- **Método:** `POST`
- **Headers:** `Content-Type: application/json`
- **Body:**
  ```json
  {
    "umidade": 65
  }
  ```
- **Resposta 201:**
  ```json
  {
    "mensagem": "Dado salvo com sucesso",
    "dado": { "id": 1, "umidade": 65, "dataHora": "2025-04-30T12:34:56.789Z" }
  }
  ```
- **Resposta 400 (dado inválido):**
  ```json
  { "erro": "Dado inválido" }
  ```


---

## 🧪 Integração com Arduino

Para enviar dados de umidade do Arduino para a API, utilize o script Python em `leitura/leitura.py`.

- **Dependências Python:** `pyserial`, `requests`
- **Fluxo:** conecta na porta serial, lê valores, envia via `POST /umidade`
- **Execução:**
  ```bash
  python leitura/leitura.py
  ```
- **Atenção:** ajuste a porta (ex: `COM4` ou `/dev/ttyUSB0`) e certifique-se de que a API está em execução.

---

## 📋 Scripts úteis

| Comando          | Descrição                                     |
|:-----------------|:----------------------------------------------|
| `npm run dev`    | Inicia API com nodemon                        |
| `npm start`      | Inicia API padrão (`node server.js`)          |
| `npm run py`     | Executa leitura serial Python (`leitura.py`)  |
| `npx prisma studio` | Abre o Prisma Studio                       |

---

## ✅ Checklist

- [x] PostgreSQL instalado e rodando na porta configurada
- [x] `.env` configurado corretamente
- [x] Prisma Client gerado e migrações aplicadas
- [x] API rodando sem erros em `http://localhost:3000`
- [x] Script Python de leitura pronto e conectando ao Arduino

---

## 📚 Aprendizados e Melhori‍as Futuras

- **Aprendizados:**
  - Conexão Node.js ↔ PostgreSQL via Prisma
  - Boas práticas REST com Express
  - Automação de leitura serial via Python
- **Melhorias Futura:**
  - Autenticação JWT nas rotas
  - Dashboard web para visualização de histórico de umidade
  - Alertas/Notificações quando a umidade ultrapassar limites críticos

---

## 🧑‍💻 Desenvolvido por

**Renan Ming** 🚀

[Meu GitHub](https://github.com/seu-usuario)

---

*Feel free to contribute!*

