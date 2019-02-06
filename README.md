# CPqD Texto Fala &ndash; Exemplos em C  [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

**VERSÃO DE DESENVOLVIMENTO**

O **CPqD Texto Fala** é um *framework* que permite converter texto genérico, como notícias ou diálogos, em fala. É possível integrar o CPqD Texto Fala nas mais variadas aplicações, desde aplicativos móveis até sistemas de diálogo para telefonia. 

Este repositório possui um arquivo CMake contendo dois projetos, na linguagem C, que demonstram como utilizar a biblioteca dinâmica (Windows ou GNU/Linux) do **CPqD Texto Fala**: ``example_tts`` e ``example_tts_streaming``. 
O projeto ``example_tts`` contém o código fonte de um programa exemplo, utilizando uma síntese síncrona, cujo o áudio é disponibilizado apenas no final do processamento. Já o projeto ``example_tts_streaming`` contém o código fonte de um programa exemplo utilizando uma síntese via streaming.


## Releases

Como boa prática, deve-se fazer o uso de versões estáveis, presentes em: https://github.com/CPqD/tts-examples-c/releases


## Criação dos projetos

Baixe o conteúdo do repositório em seu computador e crie um *branch* local apontando para a *tag* **v4.3-V1**:

	# git clone https://github.com/CPqD/tts-examples-c.git
	# git checkout -B v4.3-V1 tags/v4.3-V1

Para facilitar a criação dos projetos, o programa CMake (https://cmake.org/) pode ser utilizado (via interface gráfica ou via linha de comando).
Os projetos serão criados de acordo com o tipo de compilador instalado na máquina.

Para criar os projetos via linha de comando:
1. Acesse o diretório source do repositório baixado;
2. Crie a pasta build;
3. Use o comando abaixo para criar e configurar os projetos:
       
       # cmake -Bbuild -H.

4. Os projetos gerados estarão disponíveis na pasta build.


Para criar os projetos via interface gráfica:
1. Acesse o diretório source do repositório baixado;
2. Abra o programa CMake;
3. Insira as opções:
 
       # Source code: caminho da pasta source que possui o arquivo CMakeLists.txt
       # Build the binaries: caminho onde serão gerados os arquivos de build. Normalmente acrescentamos o diretório build no caminho do source code. Exemplo:/source/build
	
4. Clique em Configure para escolher o tipo de compilador desejado;
5. Clique em Generate para que as configurações sejam setadas no compilador;
6. Os projetos gerados estarão disponíveis na pasta build.


Caso não deseje criar e compilar os projetos, utilize os executáveis gerados para Windows e Linux 64 bits contidos na pasta bin.


## Execução

Com os exectutáveis ``example_tts`` e ``example_tts_streaming`` gerados (ou copiados), você pode testar o funcionamento da biblioteca do CPqD Texto Fala da seguinte maneira:
1. Copie o arquivo example.txt contido no repositório para a mesma pasta dos executáveis;
2. Rode o exemplo utilizando a seguinte linha de comando:

       # <executável example_tts> <caminho da instalação da biblioteca do CPqD Texto Fala>
       # <executável example_tts_streaming> <caminho da instalação da biblioteca do CPqD Texto Fala>

Ambos os exemplos irão gerar um arquivo example.wav contendo o texto do arquivo example.txt sintetizado.

Maiores dúvidas, veja a documentação de instalação e teste em: https://speechweb.cpqd.com.br/tts/docs/latest/InstallationGuide/Installation/Install.html


## Documentação

A documentação de como utilizar o **CPqD Texto Fala** em uma aplicação C está disponível em: https://speechweb.cpqd.com.br/tts/docs/latest






