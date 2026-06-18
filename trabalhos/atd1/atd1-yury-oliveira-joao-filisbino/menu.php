<!DOCTYPE html>
<html lang="pt-br">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">

<link href="https://unpkg.com/boxicons@2.1.1/css/boxicons.min.css" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Courgette&family=Poppins:wght@300;400;500;600&display=swap" rel="stylesheet">

<style>
*{
    margin:0;
    padding:0;
    box-sizing:border-box;
    font-family:'Poppins',sans-serif;
}

:root{
    --nav-color:#002942;
    --side-nav:#010718;
    --text-color:#ffffff;
}

body{
    background:linear-gradient(10deg,#53A6FA,#002942);
    min-height:100vh;
    padding-top:90px;
    transition:background .4s,color .4s;
}
body.dark{
    background:linear-gradient(10deg,#0f172a,#020617);
    color:#e5e7eb;
}

nav{
    position:fixed;
    top:10px;
    left:50%;
    transform:translateX(-50%);
    width:95%;
    height:60px;
    background:var(--nav-color);
    border-radius:30px;
    z-index:1000;
    transition:background .4s;
}

body.dark nav{
    background:#0f172a;
}

.nav-bar{
    max-width:1400px;
    height:100%;
    margin:auto;
    padding:0 25px;
    display:flex;
    align-items:center;
}

.nav-left{
    flex:2;
    display:flex;
    align-items:center;
    gap:15px;
}

.sidebarOpen{
    font-size:26px;
    color:white;
    cursor:pointer;
    display:none;
}

.navLogo a{
    font-family:'Courgette',cursive;
    font-size:22px;
    font-weight:400;
    color:white;
    text-decoration:none;
}
.nav-center{
    flex:1;
    display:flex;
    justify-content:flex-end;
    margin-right:40px;
}

.nav-links{
    display:flex;
    gap:30px;
    list-style:none;
}

.nav-links a{
    color:white;
    text-decoration:none;
    font-size:16px;
}

.nav-links a:hover{
    opacity:.7;
}

.nav-right{
    display:flex;
    align-items:center;
    gap:15px;
}

.nav-right i{
    color:white;
    font-size:22px;
    cursor:pointer;
}

.searchBox{
    position:relative;
}

.search-field{
    position:absolute;
    right:0;
    top:45px;
    width:260px;
    background:#002942;
    padding:6px;
    border-radius:8px;
    display:none;
}

body.dark .search-field{
    background:#020617;
}

.searchBox.active .search-field{
    display:flex;
}

.search-field input{
    width:100%;
    padding:8px;
    border:none;
    border-radius:6px;
    outline:none;
}

@media (max-width:900px){
    .sidebarOpen{
        display:block;
    }

    .nav-center{
        display:none;
    }

    .menu{
        position:fixed;
        top:0;
        left:-100%;
        width:300px;
        height:100%;
        background:var(--side-nav);
        padding:20px;
        transition:.4s;
        z-index:999;
    }

    nav.active .menu{
        left:0;
    }

    .menu .nav-links{
        flex-direction:column;
        gap:20px;
        margin-top:40px;
    }
}
</style>
</head>

<body>

<nav>
    <div class="nav-bar">

        <div class="nav-left">
            <i class='bx bx-menu sidebarOpen'></i>
            <span class="navLogo">
                <a href="index.php">Semana da Computação 2026</a>
            </span>
        </div>

        <div class="nav-center">
            <ul class="nav-links">
                <li><a href="Palestras.php">Palestras</a></li>
                <li><a href="incricoes.php">Inscrições</a></li>
                <li><a href="contatos.php">Contato</a></li>
            </ul>
        </div>

        <div class="nav-right">
            <i class='bx bx-moon' id="darkToggle"></i>

            <div class="searchBox" id="searchBox">
                <i class='bx bx-search'></i>
                <div class="search-field">
                    <input type="text" placeholder="Buscar...">
                </div>
            </div>
        </div>

    </div>
</nav>

<script>
const searchBox = document.getElementById('searchBox');
const darkToggle = document.getElementById('darkToggle');
const body = document.body;

searchBox.addEventListener('click', () => {
    searchBox.classList.toggle('active');
});

if(localStorage.getItem('darkMode') === 'on'){
    body.classList.add('dark');
    darkToggle.classList.replace('bx-moon','bx-sun');
}

darkToggle.addEventListener('click', () => {
    body.classList.toggle('dark');

    if(body.classList.contains('dark')){
        darkToggle.classList.replace('bx-moon','bx-sun');
        localStorage.setItem('darkMode','on');
    }else{
        darkToggle.classList.replace('bx-sun','bx-moon');
        localStorage.setItem('darkMode','off');
    }
});
</script>

</body>
</html>
