# CPqD Texto Fala &ndash; Exemplos em C  [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

**VERS�O DE DESENVOLVIMENTO**

O **CPqD Texto Fala** � um *framework* que permite converter texto gen�rico, como not�cias ou di�logos, em fala. � poss�vel integrar o CPqD Texto Fala nas mais variadas aplica��es, desde aplicativos m�veis at� sistemas de di�logo para telefonia. 

Este reposit�rio possui um arquivo CMake contendo dois projetos, na linguagem C, que demonstram como utilizar a biblioteca din�mica (Windows ou GNU/Linux) do **CPqD Texto Fala**: ``example_tts`` e ``example_tts_streaming``. 
O projeto ``example_tts`` cont�m o c�digo fonte de um programa exemplo, utilizando uma s�ntese s�ncrona, cujo o �udio � disponibilizado apenas no final do processamento. J� o projeto ``example_tts_streaming`` cont�m o c�digo fonte de um programa exemplo utilizando uma s�ntese via streaming.


## Releases

Como boa pr�tica, deve-se fazer o uso de vers�es est�veis, presentes em: https://github.com/CPqD/tts-examples-c/releases


## Cria��o dos projetos

Baixe o conte�do do reposit�rio em seu computador e crie um *branch* local apontando para a *tag* **v4.3-V1**:

	# git clone https://github.com/CPqD/tts-examples-c.git
	# git checkout -B v4.3-V1 tags/v4.3-V1

Para facilitar a cria��o dos projetos, o programa CMake (https://cmake.org/) pode ser utilizado (via interface gr�fica ou via linha de comando).
Os projetos ser�o criados de acordo com o tipo de compilador instalado na m�quina.

Para criar os projetos via linha de comando:
1. Acesse o diret�rio source do reposit�rio baixado;
2. Crie a pasta build;
3. Use o comando abaixo para criar e configurar os projetos:
	# cmake -Bbuild -H. 
4. Os projetos gerados estar�o dispon�veis na pasta build.


Para criar os projetos via interface gr�fica:
1. Acesse o diret�rio source do reposit�rio baixado;
2. Abra o programa CMake;
3. Insira as op��es:
	# Source code: caminho da pasta source que possui o arquivo CMakeLists.txt
	# Build the binaries: caminho onde ser�o gerados os arquivos de build. Normalmente acrescentamos o diret�rio build no caminho do source code. Exemplo:/source/build
4. Clique em Configure para escolher o tipo de compilador desejado;
5. Clique em Generate para que as configura��es sejam setadas no compilador;
6. Os projetos gerados estar�o dispon�veis na pasta build.


Caso n�o deseje criar e compilar os projetos, utilize os execut�veis gerados para Windows e Linux 64 bits contidos na pasta bin.


## Execu��o

Com os exectut�veis ``example_tts`` e ``example_tts_streaming`` gerados (ou copiados), voc� pode testar o funcionamento da biblioteca do CPqD Texto Fala da seguinte maneira:
1. Copie o arquivo example.txt contido no reposit�rio para a mesma pasta dos execut�veis;
2. Rode o exemplo utilizando a seguinte linha de comando:
	# <execut�vel example_tts> <caminho da instala��o da biblioteca do CPqD Texto Fala>
	# <execut�vel example_tts_streaming> <caminho da instala��o da biblioteca do CPqD Texto Fala>

Ambos os exemplos ir�o gerar um arquivo example.wav contendo o texto do arquivo example.txt sintetizado.

Maiores d�vidas, veja a documenta��o de instala��o e teste em: https://speechweb.cpqd.com.br/tts/docs/latest/InstallationGuide/Installation/Install.html


## Documenta��o

A documenta��o de como utilizar o **CPqD Texto Fala** em uma aplica��o C est� dispon�vel em: https://speechweb.cpqd.com.br/tts/docs/latest






