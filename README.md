<h1 align="center">Tree B+</h1>

---
<p align="center">
      Arvore B+ implementada como trabalho pratico na UFLA - Lavras MG.
</p>

<h2 align="center">Sobre</h2>
   
<p align="center">
    Esta arvore B+ foi implementada como objetivo principal o desenvolvimento de um sistema para uso eficiente de arquivos binários. 
    Utilizando um sequenceSet para armazenamento dos dados e a arvore B+ como indice para inserção, edição e remocao de forma eficiente.
    Para tal foi utilizado uma base de dados de captura de redes disponibilizada em <a href = "https://drive.google.com/file/d/1g9gFX9xffJWl0f7SXVM1d6v4l7ojY3Ew/view">Google Drive</a>
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/tree.png" /></p>
</p>

   - As paginas fazem parte do sequenceSet(onde realmente contem dados)
   - Noh's são indices e contem apenas chaves
   - Noh's folhas apontam para uma pagina que esta em arquivo
   
<p align="center">
    Estrutura de um Noh
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/noh.png" /></p>
    Dessa forma é possivel saber se um noh é folha ou não, com isso saber se estamos apontando para outro noh ou uma pagina do sequenceSet.
    
</p>

<p align="center">
    Estrutura de um Noh
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/percorreEmOrdem.png" /></p>
    Com uma funcao de percorrimento é possivel numerar os noh's da arvore e assim arquivar estes.
    Se chamarmos nosso sequenceSet de 'set.txt' a arvore sera armazenada num arquivo chamado 'setINDEX.txt'
    No vetor de keys é armazenado 'indice' e 'destino' do pacote de redes. Sendo 'destino' chave primaria e 'indice' chave secundaria.
    
</p>

---

<h2 align="center">Previews</h2>

<p align="center">
    Menu
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/menu.png" /></p>    
</p>
<p align="center">
    Print da arvore num arquivo chamado 'printINDEXset.txt'
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/treefile.png" /></p>    
</p>
<p align="center">
    Print dos dados no sequenceSet em um arquivo chamado 'printset.txt'
    <p align="center"><img  src="https://github.com/felipecarvalhogodoi98/Bplus/blob/master/img/depurar.png" /></p>    
</p>

---

<h2 align="center">Funcionalidades</h2>

   - ✅ Inserção 
   - ✅ Inserção por indice do arquivo CSV
   - ✅ Inserção por intervalo de indice do arquivo CSV
   - ✅ Remoção
   - ✅ Edição
   - ✅ Depuração dos dados
   - ✅ Depuração dos dados em arquivo
   - ✅ Depuração da arvore
   
 ---


<h2 align="center">Como usar?</h2>
      
      - Clone o repositorio
      - Pelo terminal digite o comando make (deve estar devidamente configurado para compilar)
      - Se nao compilar pelo make tente o comando "g++ -o executavel main.cpp Bmais.cpp Dado.cpp Pagina.cpp sequenceSet.cpp Noh.cpp Key.cpp"
      - Um arquivo chamado 'executavel.exe' sera gerado
   

