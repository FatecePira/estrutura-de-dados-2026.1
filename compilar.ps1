# =====================================================================
# SCRIPT DE COMPILAÇÃO AUTOMÁTICA - SIMULADOR DE ESTRUTURAS DE DADOS
# =====================================================================
# Este script substitui o utilitário 'make' no ambiente Windows.
# Para rodar, digite no terminal: .\compilar.ps1

Write-Host "Iniciando a compilacao do projeto..." -ForegroundColor Cyan

# Abaixo está o comando principal do GCC. Ele foi escrito em uma única linha,
# mas aqui está o significado de cada "flag" (parâmetro) para o seu estudo:
#
# gcc            -> Chama o compilador C (GNU Compiler Collection).
# -Wall -Wextra  -> Ativa os alertas (Warnings). O compilador vai avisar se houver código suspeito ou variáveis sem uso.
# -std=c11       -> Força o uso do padrão moderno da linguagem C (versão 2011).
# -I include     -> Ensina o compilador que os arquivos de "contrato" (.h) estão dentro da pasta 'include'.
# main.c src/... -> É a lista de todos os arquivos de "motor" (.c) que precisam ser unidos.
# -o             -> Define o nome do arquivo de saída (Output).
# simulador.exe  -> O nome do executável final gerado para rodar nativamente no Windows.

gcc -Wall -Wextra -std=c11 -I include main.c src/comum.c src/lista_seq.c src/lista_enc.c src/pilha.c src/fila.c src/fila_circ.c src/fila_dupla.c src/fila_prio.c -o simulador.exe

# O PowerShell guarda o resultado do último comando na variável especial $LASTEXITCODE.
# Se for igual a 0, significa que o GCC rodou perfeitamente e não encontrou erros.
if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilacao concluida com sucesso! Nenhum erro encontrado." -ForegroundColor Green
    Write-Host "-> Para abrir o menu do sistema, digite: .\simulador.exe" -ForegroundColor Yellow
} 
# Se for diferente de 0, significa que faltou alguma chave, ponto e vírgula ou arquivo.
else {
    Write-Host "ATENCAO: A compilacao falhou. Verifique os erros apontados pelo GCC acima." -ForegroundColor Red
}