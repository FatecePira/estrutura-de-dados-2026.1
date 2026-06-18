# 📚 Estrutura de Dados - 2026.[Semestre]

Repositório oficial da disciplina para o curso de Ciência da Computação da **Fatece Pirassununga**.

---

## 👨‍🏫 Professor Responsável

- **Nome:** [Inserir Nome do Professor]
- **E-mail/Contato:** [Inserir Contato]

## 🎯 Ementa / Objetivo da Disciplina

[Professor: Escreva aqui um breve resumo do que será ensinado neste semestre]

## 📂 Estrutura deste Repositório

- 📁 `aulas/` - Slides, materiais de apoio e códigos vistos em sala.
- 📁 `trabalhos/` - Enunciados e entregas de atividades práticas.
- 📁 `atd1/` - Resolução da ATD 1.
- 📁 `atd2/` - Resolução da ATD 2.
- 📁 `atd3/` - Resolução da ATD 3.
- *(e assim por diante para cada ATD)*

## 📝 Critérios de Avaliação

- **N1:** [Regra da N1]
- **N2:** [Regra da N2]

---

## 📘 TUTORIAL PARA ALUNOS: Como Publicar Seus Projetos no Git

Se você é aluno e nunca usou Git antes,este tutorial é para você. Vamos aprender passo a passo como publicar suas ATDs e trabalhos — **sem medo de quebrar nada**.

### 🎯 O Que É Git e GitHub? (Explicação Simples)

| Nome | O Que É | Analogia |
|------|---------|----------|
| **Git** (no seu PC) | Um "superpoder" que salva versões dos seus arquivos | Como o *Controlar Alterações* do Word, mas para todo o projeto |
| **GitHub** (na nuvem) | O "Armazém Central" onde todos guardam a versão oficial | Como uma biblioteca onde a turma deixa os trabalhos |

---

### 📋 Fluxo de Trabalho em 5 Passos Simples

#### Passo 1️⃣: Trazer o Projeto para Seu PC (`clone`)

**Primeira vez only:** Baixe uma cópia exata do repositório.

```bash
git clone <link-do-repositorio>
cd nome-do-repositorio
```

---

#### Passo 2️⃣: Criar um "Espaço Seguro" (`branch`)

🚫 **Nunca trabalhe direto na `main`!** Crie um ramo paralelo para cada ATD.

Para a **ATD1**:
```bash
git checkout -b resolucao-atd1
```

Para a **ATD2**:
```bash
git checkout -b resolucao-atd2
```

---

#### Passo 3️⃣: Tirar uma "Foto" do Trabalho (`commit`)

**1. Preparar** (escolher arquivos):
```bash
git add .
```

**2. Salvar** (com mensagem clara):
```bash
git commit -m "Adiciona exercícios de Python na pasta atd1"
```

✅ **Mensagens boas:** `"Adiciona exercícios 1 a 5 da ATD1"`  
❌ **Mensagens ruins:** `"ajuste"`, `"update"`, `"fix"`

---

#### Passo 4️⃣: Enviar para o Armazém (`push`)

```bash
git push -u origin resolucao-atd1
```

---

#### Passo 5️⃣: Pedir Permissão para Juntar (`Pull Request`)

1. Abra o **GitHub** da faculdade
2. Clique em **"Create Pull Request"**
3. Escreva o que você mudou: *"Adicionei os exercícios 1 a 5 da ATD1 na pasta atd1/"*

---

### 🔄 Seu Fluxo Diário (Quando Já Tiver o Repositório)
1. git pull origin main ← Baixe atualizações dos colegas
2. git checkout -b resolucao-atdX ← Crie sua branch
3. git add . ← Preparar arquivos
4. git commit -m "..." ← Salvar com mensagem
5. git push origin resolucao-atdX ← Enviar para o GitHub
6. Criar Pull Request no site ← Pedido de revisão

---

### 🆘 Emergência: "Fez Besteira, Quer Voltar?"

| Problema | Comando |
|----------|---------|
| Errou um arquivo | `git checkout -- arquivo.txt` |
| Esqueceu um arquivo no commit | `git add arquivo.txt` → `git commit --amend` |
| Quer ver o que mudou | `git status` (use sempre!) |

---

### 💡 Dicas de Ouro

1. **Puxe antes de começar:** `git pull` garante versão atualizada
2. **Mensagens claras:** Seja específico na mensagem do commit
3. **Não apague `.keep`:** Ele mantém pastas vazias no Git
4. **Use ferramentas visuais:** GitHub Desktop ou VS Code Git ajudam iniciantes

---

### 🏷️ DICAS DE TAGS PARA COMITS (Mensagens Profissionais)

Usar **tags** no início da mensagem do commit deixa o histórico organizado e fácil de entender. Aqui estão as tags mais usadas:

| Tag | Quando Usar | Exemplo de mensagem |
|-----|-----------|---------------------|
| **`feat:`** | Quando você **adiciona algo novo** (funcionalidade, exercício, arquivo) | `feat: adiciona exercícios 1 a 5 da ATD1` |
| **`fix:`** | Quando você **corrige um erro** | `fix: corrige erro no cálculo da ATD2` |
| **`docs:`** | Quando você **muda documentação** (README,并确保, comentários) | `docs: atualiza README com tutorial de Git` |
| **`style:`** | Quando você **muda estilo** (formatação, indentação, cores) sem mudar lógica | `style: formata código Python com 4 espaços` |
| **`refactor:`** | Quando você **reorganiza código** sem mudar funcionalidade | `refactor: reorganiza estrutura da pasta atd1` |
| **`test:`** | Quando você **adiciona ou muda testes** | `test: adiciona teste para função calcular()` |
| **`chore:`** | Quando você **muda coisas de manutenção** (config, dependências) | `chore: atualiza versão do Node.js` |
| **`remove:`** | Quando você **remove algo** (arquivo, código) | `remove: deleta arquivo temporário eski` |

---

### ✅ Exemplos Práticos de Commits com Tags

**Para ATD1:**
```bash
git commit -m "feat: adiciona exercícios de Python na pasta atd1"
git commit -m "feat: adiciona relatório PDF da ATD1"
```

**Para corrigir erro:**
```bash
git commit -m "fix: corrige erro de sintaxe no exercício 3"
```

**Para atualizar documentação:**
```bash
git commit -m "docs: atualiza instruções de entrega no README"
```

**Para formatar código:**
```bash
git commit -m "style: formata todos os arquivos .py com indentação correta"
```

---

### 🚫 Mensagens que EVITAR

❌ `"ajuste"` — não diz o que foi ajustado  
❌ `"update"` — não diz o que foi atualizado  
❌ `"fix"` — não diz o que foi corrigido  
❌ `"coisa"` — muito genérico

✅ **Use sempre:** tag + o que fez + onde  
Exemplo: `"feat: adiciona exercícios 1 a 5 da ATD1"`

---

### ✅ Checklist Antes de Enviar

- [ ] Criou branch nova (`resolucao-atdX`)
- [ ] Fez `git pull origin main`
- [ ] Arquivos na pasta correta (`atd1/`, `atd2/`, etc.)
- [ ] Fez `git add .`
- [ ] Commit com mensagem clara
- [ ] Fez `git push`
- [ ] Criou **Pull Request** no GitHub

---

_**Atenção Alunos:** Dúvidas sobre o código devem ser abertas na aba "Issues" deste repositório!_

_Boa sorte com suas ATDs! 🎓_
