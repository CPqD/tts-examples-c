# CPqD Texto Fala &ndash; Exemplos em C  [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

O [CPQD Texto Fala](https://www.cpqd.com.br/cpqd-texto-fala/) é um *framework* que permite converter texto genérico, como notícias ou diálogos, em fala natural. É possível integrar o CPQD Texto Fala nas mais variadas aplicações, desde aplicativos móveis até sistemas de diálogo para telefonia.

Este repositório possui dois programas de exemplo implementados em C++. O programa ``example_tts`` demonstra o uso do básico do CPQD Texto Fala, utilizando síntese síncrona (bloqueia a *thread* até a síntese ser concluída). Já o programa ``example_tts_streaming`` demonstra o uso de síntese via streaming, que possibilita a entrega do áudio na medida em que a fala é sintetizada.


## Compilação e execução no Windows

Baixe o conteúdo do repositório em seu computador e crie um *branch* local apontando para a *tag* **v4.5-V1**:

	# git clone https://github.com/CPqD/tts-examples-c.git
	# git checkout -B v4.5-V1 tags/v4.5-V1

Para facilitar a criação dos projetos, o programa [CMake](https://cmake.org/) pode ser utilizado via interface gráfica.

Os projetos serão criados de acordo com o tipo de compilador instalado na máquina. Os comandos aqui propostos estão sendo guiados pelo compilador Visual Studio.

Para criar os projetos:
1. Acesse o diretório source do repositório baixado;
2. Abra o programa CMake;
3. Insira as opções:
    - **Source code**: caminho da pasta ``source`` que possui o arquivo CMakeLists.txt
    - **Build the binaries**: caminho onde serão gerados os arquivos de build. Normalmente acrescentamos o diretório build no caminho do source code. Exemplo:/source/build
4. Clique em **Configure** e escolha o compilador Visual Studio versão 64 bits;
5. Clique em **Generate** para que as configurações sejam setadas no compilador;
6. A solution ``examples.sln`` e os projetos ``example_tts`` e ``example_tts_streaming`` estarão disponíveis na pasta build.


Para compilar o projeto criado:
1. Abra solution ``examples.sln``;
2. Altere a configuração para Release;
3. Clique com o botão direito no projeto ``example_tts`` na opção **Build**;
4. Clique com o botão direito no projeto ``example_tts_streaming`` na opção **Build**;
5. Os executáveis (**example_tts.exe** e **example_tts_streaming.exe**) foram gerados na pasta Release.


Com os exectutáveis ``example_tts.exe`` e ``example_tts_streaming.exe`` gerados, você pode testar o funcionamento da biblioteca do **CPQD Texto Fala** da seguinte maneira:
1. Rode o programa exemplo informando o caminho da instalação da biblioteca do CPQD Texto Fala:

       # example_tts.exe <caminho da instalação do CPQD Texto Fala>
       # example_tts_streaming.exe <caminho da instalação do CPQD Texto Fala>
2. Ambos os exemplos irão gerar um arquivo example.wav contendo o texto sintetizado;
3. Opcionalmente o texto a ser sintetizado pode ser informado via arquivo (example.txt). Caso o arquivo não seja encontrado, um texto padrão será sintetizado.

Maiores dúvidas, veja a documentação de [instalação.](https://speechweb.cpqd.com.br/tts/docs/latest/InstallationGuide/Install.html)



## Compilação e execução no Linux

Baixe o conteúdo do repositório em seu computador e crie um *branch* local apontando para a *tag* **v4.5-V1**:

	# git clone https://github.com/CPqD/tts-examples-c.git
	# git checkout -B v4.5-V1 tags/v4.5-V1

Para facilitar a criação dos projetos, o programa [CMake](https://cmake.org/) pode ser utilizado via linha de comando.

Os projetos serão criados de acordo com o tipo de compilador instalado na máquina.

Para criar os projetos:
1. Acesse o diretório source do repositório baixado;
2. Crie a pasta build;
3. Use o comando abaixo para criar e configurar os projetos:

       # cmake -Bbuild -H./source/

4. Os projetos gerados estarão disponíveis na pasta build.



Para compilar o projeto criado:
1. Acesse a pasta build;
2. Rode os comandos:

       # make example_tts
       # make example_tts_streaming

3. Os executáveis (**example_tts** e **example_tts_streaming**) foram gerados na pasta build.


Com os exectutáveis ``example_tts`` e ``example_tts_streaming`` gerados, você pode testar o funcionamento da biblioteca do **CPqD Texto Fala** da seguinte maneira:
1. Rode o programa exemplo informando o caminho da instalação da biblioteca do CPqD Texto Fala:

       # ./example_tts <caminho da instalação do CPqD Texto Fala>
       # ./example_tts_streaming <caminho da instalação do CPqD Texto Fala>
2. Ambos os exemplos irão gerar um arquivo example.wav contendo o texto sintetizado;
3. Opcionalmente o texto a ser sintetizado pode ser informado via arquivo (example.txt). Caso o arquivo não seja encontrado, um texto padrão será sintetizado.

Maiores dúvidas, veja a documentação de [instalação.](https://speechweb.cpqd.com.br/tts/docs/latest/InstallationGuide/Install.html)



## Documentação

Veja a documentação de como utilizar o **CPqD Texto Fala** em uma [aplicação C.](https://speechweb.cpqd.com.br/tts/docs/latest/ProgrammingGuide/Native/Index.html)
