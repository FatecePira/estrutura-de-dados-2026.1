<!DOCTYPE html>
<html lang="pt-br">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<link rel="icon" href="IMG/Logo-Metropolitana-P.ico" type="image/x-icon">
<title>Palestras</title>

<style>
html{
    scroll-behavior: smooth;
}

body{
    margin:0;
    background:linear-gradient(120deg,#53A6FA,#FABB52);
    min-height:100vh;
    font-family:'Poppins',sans-serif;
    color:white;
    padding-top:90px;
}

.container{
    max-width:1300px;
    margin:auto;
    padding:20px;
}

section{
    margin:20px 0;
    padding:20px;
    background:rgba(30,41,59,.5);
    border-radius:12px;
}

h2{
    text-align:center;
    margin-bottom:20px;
    font-weight:500;
}

.dias{
    display:flex;
    gap:15px;
    flex-wrap:wrap;
}

.dia{
    flex:1;
    min-width:250px;
    background:rgba(30,41,59,.7);
    padding:15px;
    border-radius:12px;
    transition:.3s;
}

.dia:hover{
    transform:translateY(-5px);
    background:rgba(30,41,59,.9);
}

.dia h3{
    color:#38bdf8;
    margin-bottom:10px;
}

ul{
    padding-left:20px;
}

li{
    margin-bottom:6px;
}

.palestrantes{
    display:flex;
    gap:20px;
    flex-wrap:wrap;
}

.palestrantes article{
    flex:1;
    min-width:250px;
    background:#1e293b;
    padding:15px;
    border-radius:12px;
    text-align:center;
    transition:.3s;
}

.palestrantes article:hover{
    transform:translateY(-5px);
    box-shadow:0 15px 40px rgba(0,0,0,.4);
}

.palestrantes img{
    width:100%;
    height:220px;
    object-fit:cover;
    border-radius:10px;
    margin-bottom:12px;
}

.palestrantes h3{
    color:#38bdf8;
    margin-bottom:6px;
}

.palestrantes p{
    font-size:14px;
    opacity:.9;
}
</style>
</head>

<body>

<?php include "menu.php"; ?>

<div class="container">

    <section id="programacao">
        <h2>Programação</h2>

        <div class="dias">

            <div class="dia">
                <h3>Dia 1 – Segunda-feira</h3>
                <ul>
                    <li>Abertura do evento</li>
                    <li>Palestra sobre Inteligência Artificial</li>
                </ul>
            </div>

            <div class="dia">
                <h3>Dia 2 – Terça-feira</h3>
                <ul>
                    <li>Minicurso de Desenvolvimento Web</li>
                    <li>Workshop de Git e GitHub</li>
                </ul>
            </div>

            <div class="dia">
                <h3>Dia 3 – Quarta-feira</h3>
                <ul>
                    <li>Palestra de Segurança Web</li>
                    <li>Minicurso Mobile</li>
                </ul>
            </div>

            <div class="dia">
                <h3>Dia 4 – Quinta-feira</h3>
                <ul>
                    <li>Cloud Computing</li>
                    <li>Bancos de Dados</li>
                </ul>
            </div>

            <div class="dia">
                <h3>Dia 5 – Sexta-feira</h3>
                <ul>
                    <li>Feira Tecnológica</li>
                    <li>Encerramento</li>
                </ul>
            </div>

        </div>
    </section>

    <section id="palestrantes">
        <h2>Palestrantes</h2>

        <div class="palestrantes">

            <article>
                <img src="IMG/joao.png" alt="João Carlos">
                <h3>João Carlos</h3>
                <p>Especialista em Inteligência Artificial.</p>
            </article>

            <article>
                <img src="IMG/yury.png" alt="Agiota">
                <h3>Yury</h3>
                <p>Desenvolvedor Full Stack.</p>
            </article>

            <article>
                <img src="IMG/well.jpg" alt="Xera Graxa">
                <h3>Manivela</h3>
                <p>Engenheiro de Software.</p>
            </article>

            <article>
                <img src="IMG/yuri.png" alt="Elmago">
                <h3>Yuri</h3>
                <p>Administrador de Banco de Dados.</p>
            </article>

        </div>
    </section>

</div>
<?php include "rodape.php"; ?>
</body>
</html>
