<!DOCTYPE html>
<html lang="pt-br">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<link rel="icon" href="IMG/Logo-Metropolitana-P.ico" type="image/x-icon">
<title>SEMCOMP</title>

<style>
html{
    scroll-behavior:smooth;
}

body{
    margin:0;
    background:linear-gradient(120deg,#53A6FA,#002942);
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
    margin:30px 0;
    padding:25px;
    background:rgba(30,41,59,.5);
    border-radius:16px;
}

h1,h2{
    text-align:center;
    font-weight:500;
}

h1{
    font-size:36px; 
}

h2{
    margin-bottom:15px;
    color:#38bdf8;
}


.fatece{
    position:relative;
    min-height:400px;
    /*background-image:url("./IMG/Fatece.jpg");*/
    background-size:cover;
    background-position:center;
    display:flex;
    align-items:center;
    justify-content:center;
    padding:60px 25px; 
}

.fatece-overlay{
    background:rgba(30,41,59,.9);
    padding:50px 40px;
    border-radius:20px;
    max-width:950px;
    text-align:center;
}

.fatece-overlay p{
    margin-top:22px;
    font-size:19px;
    line-height:1.6;
    opacity:.95;
}

.info-grid{
    display:flex;
    gap:20px;
    flex-wrap:wrap;
}

.info-card{
    flex:1;
    min-width:250px;
    background:rgba(30,41,59,.7);
    padding:20px;
    border-radius:14px;
    transition:.3s;
}

.info-card:hover{
    transform:translateY(-6px);
    background:rgba(30,41,59,.9);
}

.info-card h3{
    color:#38bdf8;
    margin-bottom:10px;
}

.destaques{
    display:flex;
    gap:20px;
    flex-wrap:wrap;
}

.destaque{
    flex:1;
    min-width:250px;
    background:#1e293b;
    padding:20px;
    border-radius:14px;
    transition:.3s;
}

.destaque:hover{
    transform:translateY(-6px);
    box-shadow:0 15px 40px rgba(0,0,0,.4);
}

.destaque h3{
    color:#38bdf8;
    margin-bottom:8px;
}

.cta{
    text-align:center;
}

.cta a{
    display:inline-block;
    margin-top:15px;
    padding:12px 25px;
    border-radius:30px;
    background:#38bdf8;
    color:#002942;
    text-decoration:none;
    font-weight:500;
    transition:.3s;
}

.cta a:hover{
    background:#F79F39;
    color:white;
}
</style>
</head>

<body>

<?php include "menu.php"; ?>

<div class="container">

    <section class="fatece">
        <div class="fatece-overlay">
            <h1>Semana da Computação 2026</h1>
            <p>
                Um evento acadêmico voltado para estudantes e entusiastas da área de tecnologia,
                reunindo palestras, minicursos, workshops e experiências práticas
                sobre o presente e o futuro da computação.
            </p>
        </div>
    </section>

    <section>
        <h2>Sobre o Evento</h2>

        <div class="info-grid">
            <div class="info-card">
                <h3>📍 Onde</h3>
                <p> Faculdade Fatece – Pirassununga</p>
            </div>

            <div class="info-card">
                <h3>📅 Quando</h3>
                <p>17 à 22 de Agosto – 2026</p>
            </div>

            <div class="info-card">
                <h3>👥 Público</h3>
                <p>Estudantes, professores e profissionais da área</p>
            </div>
        </div>
    </section>

    <section>
        <h2>O que vai rolar?</h2>

        <div class="destaques">
            <div class="destaque">
                <h3>Palestras</h3>
                <p>
                    Profissionais do mercado abordando temas como
                    Inteligência Artificial, Segurança Web e Cloud Computing.
                </p>
            </div>

            <div class="destaque">
                <h3>Minicursos</h3>
                <p>
                    Atividades práticas focadas em desenvolvimento web,
                    mobile, bancos de dados e versionamento com Git.
                </p>
            </div>

            <div class="destaque">
                <h3>Feira Tecnológica</h3>
                <p>
                    Exposição de projetos, networking e troca de experiências
                    entre alunos e profissionais.
                </p>
            </div>
        </div>
    </section>

    <section class="cta">
        <h2>Participe</h2>
        <p>Garanta sua inscrição e fique por dentro da programação completa.</p>
        <a href="incricoes.php">Inscreva-se agora</a>
    </section>

</div>
<?php include "rodape.php"; ?>
</body>
</html>

