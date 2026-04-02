<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="icon" href="IMG/Logo-Metropolitana-P.ico" type="image/x-icon">
    <title>Inscrições</title>

    <style>
        html {
            scroll-behavior: smooth;
        }

        body {
            margin: 0;
            background: linear-gradient(120deg, #53A6FA, #FABB52);
            min-height: 100vh;
            font-family: 'Poppins', sans-serif;
            color: white;
            padding-top: 50px;
        }

        h1, h2 {
            text-align: center;
            font-weight: 500;
        }

        section {
            padding: 20px;
        }

        footer {
            background: black;
            text-align: center;
            padding: 10px;
        }

        .container {
            max-width: 900px;
            margin: auto;
            padding: 20px;
        }

        article {
            background: #1e293b;
            padding: 15px;
            border-radius: 12px;
            transition: 0.3s;
        }

        article:hover {
            transform: translateY(-5px);
            box-shadow: 0 15px 40px rgba(0, 0, 0, 0.4);
        }

        #inscricao {
            background: rgba(30, 41, 59, 0.5);
            border-radius: 12px;
        }

        form {
            display: flex;
            flex-direction: column;
        }

        label {
            margin-top: 10px;
            font-size: 14px;
        }

        input,
        select,
        textarea {
            width: 100%;
            padding: 10px;
            margin-top: 5px;
            border-radius: 8px;
            border: none;
            outline: none;
            font-family: inherit;
        }

        textarea {
            resize: vertical;
            min-height: 100px;
        }

        input:focus,
        select:focus,
        textarea:focus {
            box-shadow: 0 0 8px #38bdf8;
        }


        .interesses {
            display: flex;
            gap: 15px;
            flex-wrap: wrap;
            margin-top: 10px;
        }

        .checkbox {
            display: flex;
            gap: 10px;
            align-items: center;
            background: rgba(30, 41, 59, 0.6);
            padding: 8px 14px;
            border-radius: 8px;
            cursor: pointer;
            transition: 0.3s;
        }

        .checkbox:hover {
            background: rgba(30, 41, 59, 0.9);
        }

        .checkbox input {
            accent-color: #38bdf8;
        }


        .botoes {
            display: flex;
            gap: 10px;
            margin-top: 15px;
        }

        button {
            padding: 10px 20px;
            border: none;
            border-radius: 8px;
            background: #38bdf8;
            color: white;
            cursor: pointer;
            font-weight: 500;
        }

        button:hover {
            background: #F79F39;
        }
    </style>
</head>

<body>

<?php include "menu.php"; ?>

<section>
    <div class="container">
        <article id="inscricao">
            <h2>Inscrição</h2>

            <form>
                <label>Nome</label>
                <input type="text" name="nome" required>

                <label>Email</label>
                <input type="email" name="email" required>

                <label>Telefone</label>
                <input type="tel" name="telefone" required>

                <label>Curso</label>
                <select name="curso">
                    <option>Ciência da Computação</option>
                    <option>Sistemas de Informação</option>
                </select>

                <label>Turno</label>
                <select name="turno" required>
                    <option value="manha">Manhã</option>
                    <option value="noite">Noite</option>
                </select>

                <label>Atividades de interesse</label>
                <div class="interesses">
                    <label class="checkbox">
                        <input type="checkbox" name="interesse[]" value="palestras">
                        Palestras
                    </label>

                    <label class="checkbox">
                        <input type="checkbox" name="interesse[]" value="workshops">
                        Workshops
                    </label>

                    <label class="checkbox">
                        <input type="checkbox" name="interesse[]" value="minicursos">
                        Minicursos
                    </label>
                </div>

                <label>Comentários</label>
                <textarea></textarea>

                <div class="botoes">
                    <button type="submit">Enviar</button>
                    <button type="reset">Limpar</button>
                </div>
            </form>
        </article>
    </div>
</section>
<?php include "rodape.php"; ?>
</body>
</html>
