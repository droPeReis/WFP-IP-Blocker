# WFP-IP-Blocker
## EN
This is a simple Windows Firewall IP Blocker that uses the Windows Filtering Platform (WFP) to block incoming and outgoing connections from a specific IP address. 

### Prerequisites
* Windows 10 or later

* Windows SDK installed (Download Windows SDK)

* MinGW-w64 or MSVC (Visual C++) installed

### Installation and Compilation

1. Clone the repository:
```
git clone https://github.com/yourusername/firewall-ip-blocker.git
cd firewall-ip-blocker
```

2. Ensure you have the necessary include paths for Windows SDK:

* Headers: C:\Program Files (x86)\Windows Kits\10\Include\<version>\um\fwpmu.h
* Libraries: C:\Program Files (x86)\Windows Kits\10\Lib\<version>\um\x64\Fwpuclnt.lib

3. Compile the code:

* Using MinGW-w64:
```
gcc -o firewall.exe firewall.c -I"C:\Program Files (x86)\Windows Kits\10\Include\<version>\um" -L"C:\Program Files (x86)\Windows Kits\10\Lib\<version>\um\x64" -lFwpuclnt
```
And then just run the executable to block a specific IP.



WFP-IP-Blocker

--------------------------------------------------------------------------
## PT

Este é um simples Bloqueador de IP do Firewall do Windows que utiliza a Windows Filtering Platform (WFP) para bloquear conexões de entrada e saída de um endereço IP específico.

### Pré-requisitos

* Windows 10 ou superior

* Windows SDK instalado (Baixar Windows SDK)

* MinGW-w64 ou MSVC (Visual C++) instalado

### Instalação e Compilação

1. Clone o repositório:
```
git clone https://github.com/seuusuario/firewall-ip-blocker.git
cd firewall-ip-blocker
```
2. Verifique se você possui os caminhos necessários para os arquivos do Windows SDK:

* Cabeçalhos: C:\Program Files (x86)\Windows Kits\10\Include\<versao>\um\fwpmu.h
* Bibliotecas: C:\Program Files (x86)\Windows Kits\10\Lib\<versao>\um\x64\Fwpuclnt.lib

3. Compile o código:

Usando MinGW-w64:
```
gcc -o firewall.exe firewall.c -I"C:\Program Files (x86)\Windows Kits\10\Include\<versao>\um" -L"C:\Program Files (x86)\Windows Kits\10\Lib\<versao>\um\x64" -lFwpuclnt
```
Após a compilação, basta executar o executável para bloquear um IP específico.



