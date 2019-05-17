Objectives given:
	1. Ler e guardar a informação da agência, dos clientes e dos pacotes turísticos armazenada em
	ficheiros. -> DONE
	2. Gerir os clientes e pacotes turísticos: criar, alterar e remover um cliente; criar, alterar ou colocar
	como indisponível um pacote turístico (nota: os pacotes turísticos nunca são efetivamente
	removidos; ver exemplo acima). -> DONE
	3. Gerar e visualizar de modo formatado a informação de um cliente especificado. -> DONE
	4. Gerar e visualizar de modo formatado a informação de todos os clientes da agência. -> DONE
	5. Gerar e visualizar de modo formatado os pacotes turísticos disponíveis (todos, todos relativos a um
	destino específico, todos entre duas datas, todos os relativos a um destino específico e entre duas
	datas). -> DONE
	6. Gerar e visualizar de modo formatado os pacotes turísticos vendidos (a um cliente específico, a
	todos os clientes). -> DONE
	7. Efetuar a compra de uma pacote turístico por um cliente. -> DONE
	8. Calcular e visualizar o número e o valor total de pacotes vendidos. -> DONE
	9. Obter o nome dos N locais mais visitados (um pacote pode incluir visitas a vários locais), ordenados
	por ordem decrescente do número de visitas ( = número de pacotes vendidos que passam por esse
	local). -> DONE
	10. Gerar uma listagem de todos os clientes na qual se indica, para cada cliente, um dos pacotes em
	que seja visitado um dos N locais mais visitados (ver ponto 9) que ele ainda não visitou. -> DONE

EXTRA FEATURES:
    
    1. Client's with invalid packs (agency doesn't have them) are cleared out

    2. Data saving options

    3. Before and after view of changes you made, and changes are only saved on user confirmation

    4. Writing of files only occurs if any updated wasn't saved yet

NOTES:
    1. Interface beauty and terminal clearing isn't implemented, as it was not an important feature

    2. Unit Test isn't available during program, was only used in early development to test general functions of string manipulation
	
	3. Class "Hierarchy"
				Date 		Address
				  |			|	|
			TravelPack		|	|
			|		 |		|	|
			|		Client--|	|
			|		 |			|
			Agency---|----------|
	
	4. Upon editing client information, there's no option to change the value of the purchases as we decided it shouldn't be changed directly during the program
	
	5. We assumed a "no refund" policy for the agency, so after deleting a pack from the client, agency sold packs and money gained will not be changed, as well as the client money spent
			
	6. Client NIF's are not limited to 9 numbers, as we assumed there could be international clients and the size of number can change for the "VAT" of the client
	
	7. When searching for available packs to a certain destiny
	
	8. Due to some problems with clearing the input buffer, and deadline was already too close, might have to press Enter 2 times for the program to continue after input
