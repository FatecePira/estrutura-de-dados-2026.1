<!DOCTYPE html>
<html lang="pt-BR">

<head>
	<meta charset="UTF-8" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />

	<link rel="icon" href="IMG/Logo-Metropolitana-P.ico" type="image/x-icon">
	<title>Contato</title>

	<link rel="preconnect" href="https://fonts.googleapis.com" />
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin />
	<link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;500;800&display=swap" rel="stylesheet" />

	<style>
		* {
			box-sizing: border-box;
			margin: 0;
			padding: 0;
		}

		html,
		body {
			height: 100%;
		}

		body {
			font-family: 'Poppins', sans-serif;
			background: linear-gradient(180deg, #0b3a5a, #4b91d1);
			padding-top: 90px;
			display: flex;
			flex-direction: column;
		}

		main {
			flex: 1;
		}

		.container {
			max-width: 1400px;
			margin: 0 auto;
			padding: 40px 30px;
		}

		.listagem-contatos {
			display: flex;
			flex-wrap: wrap;
			gap: 40px;
			justify-content: center;
			list-style: none;
		}

		.cartao {
			background-color: #a4cff3;
			width: 340px;
			padding: 28px;
			display: flex;
			flex-direction: column;
			align-items: center;
			gap: 20px;
			border-radius: 20px;
			transition: 0.3s ease;
		}

		.cartao:hover {
			background-color: #65b9f1;
			transform: translateY(-8px);
		}

		.informacoes {
			width: 100%;
			display: flex;
			justify-content: space-between;
			border: 1px solid #1e293b;
			border-radius: 12px;
			padding: 10px 14px;
			font-size: 14px;
			text-transform: uppercase;
			font-weight: 500;
			color: #1e293b;
		}

		.slideshow {
			position: relative;
			width: 160px;
			/* ⬅️ IMAGEM MAIOR */
			height: 160px;
			border-radius: 16px;
			overflow: hidden;
			background: #1e293b;
		}

		.slideshow img {
			position: absolute;
			inset: 0;
			width: 100%;
			height: 100%;
			object-fit: cover;
			opacity: 0;
			transition: opacity 0.6s ease;
		}

		.slideshow img.active {
			opacity: 1;
		}

		.descricao {
			max-height: 140px;
			overflow-y: auto;
			font-size: 15px;
			text-align: center;
			line-height: 1.5;
			color: #1e293b;
		}

		.descricao::-webkit-scrollbar {
			width: 4px;
		}

		.descricao::-webkit-scrollbar-thumb {
			background: rgba(0, 0, 0, .3);
			border-radius: 10px;
		}

		@media (max-width: 600px) {
			.cartao {
				width: 100%;
				max-width: 380px;
			}
		}

		body.dark {
			background: linear-gradient(180deg, #020617, #0f172a);
		}

		body.dark .cartao {
			background: #1e293b;
			color: #e5e7eb;
		}

		body.dark .cartao:hover {
			background: #273549;
		}

		body.dark .informacoes {
			border: 1px solid rgba(255, 255, 255, .15);
			color: #e5e7eb;
		}

		body.dark .descricao {
			color: #d1d5db;
		}

		body.dark .descricao::-webkit-scrollbar-thumb {
			background: rgba(255, 255, 255, .25);
		}

		body.dark .slideshow {
			background: #020617;
			box-shadow: 0 10px 30px rgba(0, 0, 0, .6);
		}
	</style>
</head>

<body>

	<?php include "menu.php"; ?>

	<main>
		<div class="container">
			<ul class="listagem-contatos">

				<li class="cartao">
					<div class="informacoes">
						<span>Stefane Menezes</span>
						<span>#001</span>
					</div>

					<div class="slideshow">
						<img src="./IMG/Stefane3.jpg" class="active">
						<img src="./IMG/Stefane1.png">
						<img src="./IMG/Stefane2.png">
					</div>

					<p class="descricao">
						Doutora em Ciência da Computação pela UFSCar, mestra em Engenharia de Computação,
						especialista em Tecnologias Web e professora na FATECE e Faculdade Metropolitana.
					</p>
				</li>

				<li class="cartao">
					<div class="informacoes">
						<span>Julyette Redling</span>
						<span>#002</span>
					</div>

					<div class="slideshow">
						<img src="./IMG/Ju3.gif" class="active">
						<img src="./IMG/Ju1.png">
						<img src="./IMG/Ju2.png">
					</div>

					<p class="descricao">
						Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatibus,
						molestiae accusamus dolore eaque repudiandae.
					</p>
				</li>

				<li class="cartao">
					<div class="informacoes">
						<span>Andre Machi</span>
						<span>#003</span>
					</div>

					<div class="slideshow">
						<img src="./IMG/Andre2.png" class="active">
						<img src="./IMG/Andre1.png">
						<img src="./IMG/Andre3.png">
					</div>

					<p class="descricao">
						Lorem ipsum dolor sit amet consectetur adipisicing elit. Libero,
						praesentium quisquam deleniti maiores.
					</p>
				</li>

			</ul>
		</div>
	</main>

	<?php include "rodape.php"; ?>

	<script>
		document.querySelectorAll('.slideshow').forEach(slideshow => {
			const slides = slideshow.querySelectorAll('img');
			let index = 0;

			setInterval(() => {
				slides[index].classList.remove('active');
				index = (index + 1) % slides.length;
				slides[index].classList.add('active');
			}, 6000);
		});
	</script>

</body>

</html>
