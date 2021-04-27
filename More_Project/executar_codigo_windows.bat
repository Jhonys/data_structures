:: move para o diretorio atual executando o .bat
pushd %~dp0

more.exe "teste.txt"

:: sai do diretorio atual executando o .bat
popd

pause