<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rodapé</title>

    <style>
        #rodape{
            margin-top:40px;
            padding:25px 20px;
            background:rgba(2,6,23,.95);
            border-top:2px solid #38bdf8;
        }

        .rodape-container{
            max-width:1300px;
            margin:auto;
            display:flex;
            justify-content:space-between;
            align-items:center;
            flex-wrap:wrap;
            gap:20px;
        }

        #rodape p,
        #rodape span{
            font-size:14px;
            color:#9ca3af;
        }

        .rodape-left{
            opacity:.85;
        }

        .rodape-right{
            display:flex;
            gap:30px;
            flex-wrap:wrap;
        }

        .pessoa{
            display:flex;
            flex-direction:column;
            gap:2px;
        }

        .nome{
            font-weight:500;
        }

        .email{
            font-size:13px;
            opacity:.75;
        }

        @media (max-width:700px){
            .rodape-container{
                flex-direction:column;
                text-align:center;
            }

            .rodape-right{
                justify-content:center;
            }
        }
    </style>
</head>

<body>

<footer id="rodape">
    <div class="rodape-container">

        <div class="rodape-left">
            <p>© 2026 Semana Acadêmica</p>
            <p>Copyright 2026</p>
        </div>

        <div class="rodape-right">
            <div class="pessoa">
                <span class="nome">Yury de Oliveira</span>
                <span class="email">yury2116@gmail.com</span>
            </div>

            <div class="pessoa">
                <span class="nome">João Carlos Pilão Filisbino</span>
                <span class="email">jfilisbino@gmail.com</span>
            </div>
        </div>

    </div>
</footer>

</body>
</html>
