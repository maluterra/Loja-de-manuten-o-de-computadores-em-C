#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct cliente{

	int codigo; 
	char tipo_servico[4];
	char nome[50];
	int qtd_dias;
	float total_cobrado;
	char status_ordem;
	char status_pagamento;

};

//fun�oes
/*cont tipo de servi�o por cliente e cont2 =  � quantidade de clientes */
void leitura(cliente *clientes, int *cont, int *cont2, int *i); 
void Mostra_servico(cliente *clientes, int *cont, int *cont2);
void Mostra_pagas(cliente *clientes, int *cont, int *cont2);
void Servicos_fina_naopago(cliente *clientes, int *cont, int *cont2);
void Buscar_OS(cliente *clientes,int *cont, int *cont2);
void Mostra_em_execucao(cliente *clientes, int *cont, int *cont2);
void Mostra_finalizados(cliente *clientes, int *cont, int *cont2);
void Visualizar_pagamento(cliente *clientes, int *cont, int *cont2);
void Visualizar_nao_inicializados(cliente *clientes, int *cont, int *cont2);
void Calucular_valor_pagos(cliente *clientes,int *cont, int *cont2);
void Calucular_valor_todos(cliente *clientes,int *cont, int *cont2);


int main (){
	
	//chamamos esta função para conseguir utilizar caracteres especiais
	setlocale(LC_ALL, "portuguese");
	
	struct cliente *clientes;

    clientes = (struct cliente*) malloc(10 * sizeof(struct cliente));
	
	//declara��o das variaveis que s�o utilizadas como op��es 
	char op3='A',op4='A';
	
	//variaveis que s�o utilizadas como passagem de parametro 
	int cont,cont2,i=0;
	
	//vai rodar at� o usuario digitar 6 pra sair 
	while (op3 != 'F'){
		
		
		//vai imprimir o menu em tela
		printf ("\t******************************************************");
		printf ("\n\t*\t\t\t\t                     *\n\t*\t\t         MENU \t\t\t     *\n\t*\t\t\t\t\t\t     *\n");
		printf ("\t******************************************************");
	
		printf ("\n\n\t******************************************************");
		printf ("\n\n\t\t(A) - Cadastrar ordens de servicos");
		printf ("\n\t\t(B) - Vizualizar todas as ordens de servi�os");
		printf ("\n\t\t(C) - Buscar uma unica ordem de servi�o");
		printf ("\n\t\t(D) - Mostrar outros tipos de ordem de servi�os");
		printf ("\n\t\t(E) - Mostrar o valor total no caixa");
		printf ("\n\t\t(F) - Sair");
		printf ("\n\n\t******************************************************");
	
		//vai ler a op��o que usuario digitou 
		printf ("\n\n\t - ");
		scanf (" %c",&op3);

    	//vai deixar o carcter com letra maiuscula
   	    op3 = toupper(op3);
	
	
	
  		//para verificar a op��o que o usuario escolheu e vai chamar a fun��o correta 
		switch (op3){
		
			case 'A':
				
				printf ("\n\n\n\t");
				system ("pause");
				system ("cls");
				
				fflush (stdin);
				leitura(clientes,&cont,&cont2,&i);
				break;
			
			case 'B':
				
				printf ("\n\n\n\t");
				system ("pause");
				system ("cls");
				
				fflush (stdin);
				Mostra_servico(clientes,&cont,&cont2);
				break;
			
			case 'C':
				
				printf ("\n\n\t");
	 		    system ("pause");
	 		    system ("cls");
				
				fflush (stdin);
       			Buscar_OS(clientes, &cont, &cont2);
				break;
			
			case 'D':
			
				printf ("\n\n\n\t");
	 		    system ("pause");
	 		    system ("cls");
				
        		//vai imprimir o sub menu 
				printf ("\t******************************************************");
				printf ("\n\t*\t\t\t\t                     *\n\t*\t        Escolha uma das op�oes \t\t     *\n\t*\t\t\t\t\t\t     *\n");
				printf ("\t******************************************************");
					
				printf ("\n\n");
			
				printf ("\t******************************************************\n");
				printf ("\n\t\t(A) - Vizualizar servi�os pagos");
				printf ("\n\t\t(B) - Servi�os aguardando pagamento");
				printf ("\n\t\t(C) - Servi�os que n�o foram inciados");
				printf ("\n\t\t(D) - Mostrar os que est�o em execu��o");
				printf ("\n\t\t(E) - Mostrar os que foram finzalizados");
				printf ("\n\t\t(F) - Finalizados, mas n�o pagos");
				printf ("\n\t\t(G) - Valor total para os servi�os pagos");
				printf ("\n\n\t******************************************************");
			
				printf ("\n\n\t - ");

        		//vai ler a op��o que o usuario que escolheu 
				scanf (" %c",&op4);
        		op4 = toupper(op4);
			
        		//para verificar a op��o que o usuario escolheu e vai chamar a fun��o correta 
				switch (op4){
				
					case 'A':
					
						
						fflush (stdin);
						Mostra_pagas(clientes,&cont,&cont2);
						break;
					
					case 'B':
				
            			fflush (stdin);
						Visualizar_pagamento(clientes, &cont, &cont2);
						break;
					
					case 'C':
					
            			fflush (stdin);
						Visualizar_nao_inicializados(clientes, &cont, &cont2);
						break;
					
					case 'D':
					
            			fflush (stdin);
						Mostra_em_execucao(clientes, &cont, &cont2);
						break;
					
					case 'E':
					
            			fflush (stdin);
						Mostra_finalizados(clientes, &cont, &cont2);	
						break;
					
					case 'F':
					
						fflush (stdin);
						Servicos_fina_naopago(clientes,&cont,&cont2);
						break;
					
					case 'G':
					
            			fflush (stdin);
            			Calucular_valor_pagos(clientes, &cont, &cont2);
						break;
					
					default: 
							
						printf ("N�o entendi o que voc� digitou");		 
						system ("pause");
						system ("cls");
				}
				
			break;
				
      		case 'E':

        	fflush (stdin);
        	Calucular_valor_todos(clientes,&cont, &cont2);
			break;
			
			case 'F':
			
				printf ("Sair");
				break;
			
			default:
			
				printf ("\n\n\tN�o entendi o que voc� digitou");
				printf ("\n\n\n\t");
				system ("pause");
				system ("cls");
				
		}			
	}	
}
	
//Fun��o leitura vai ler e cadastrar todos os clientes
void leitura(cliente *clientes,int *cont, int *cont2, int *i){
  
	//i , j, k e l variaveis para as repeti��es
	int  qt = 1,k=0,n=0,m=0; // qt = quantidade de seevi�os.
	/* BOTAR NOME SIGNIFICATIVO */
  
	//op��es 
	char op = 'S', op2 = 'S';

	//vai inicializar o total de cada cliente com 0 
	clientes[*i].total_cobrado = 0;
	
	//vai inicializar a variavel contador
	*cont = 0;
		
	//vai rodar ate o usuario digitar que deseja sair 
	while(op != 'N'){
		
		//vai inicializar os tipos de servico de cada cliente com 0
		for (m=0 ; m < 4 ; m++){
			
			clientes[*i].tipo_servico[m] = 0;
		}

    	//vai ler as informa��es de cada cliente
    	printf ("\t******************************************************");
		printf ("\n\t*\t\t\t\t                     *\n\t*\t\t   Ordem de Servi�o\t\t     *\n\t*\t\t\t\t\t\t     *\n");
		printf ("\t******************************************************");
	
    	printf("\n\n\n\tDigite o c�digo da ordem de servi�o:\n\n\t - ");
    	scanf("%d", &clientes[*i].codigo); /* Ordem: Ponteiro */  

    	printf("\n\tVoc� deseja algum tipo de servi�o? Sim = S N�o = qualquer outra tecla\n\n\t - ");
    	scanf(" %c",&op2);
    	
    	op2 = toupper (op2);

    	//vai rodar enquanto o cliente n�o deseja sair e at� ele atingir o limite de pedidos de tipo de servicos 
		while(op2 == 'S' && k <= 3){
    	
    		printf ("\n\n\t");
    		system ("pause");
    		system ("cls");

          	//vai mostrar o menu em tela para o usuario 		
      		printf ("\t******************************************************");
			printf ("\n\t*\t\t\t\t                     *\n\t*\t\t\tOP��ES\t\t\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************\n\n");

     		printf ("\n\t(A) � formata��o com backup         Pre�o: R$ 150,00");
      		printf ("\n\t(B) � formata��o sem backup         Pre�o: R$ 110,00");
      		printf ("\n\t(C) � Troca de pe�as                Pre�o: R$ 200,00");
      		printf ("\n\t(D) � Limpeza e manuten��o b�sica   Pre�o: R$ 100,00\n\n");
      		
      		//vai receber o tipo de servico que o suario deseja 
      		printf("\n\tDigite o tipo de servi�o que voc� deseja:\n\n\t - ");

      		scanf (" %c", &clientes[*i].tipo_servico[k]);
      		
      		//vai deixar a op��o com a letra maiuscula 
      		clientes[*i].tipo_servico[k] = toupper (clientes[*i].tipo_servico[k]);
      		
      		while (clientes[*i].tipo_servico[k] != 'A' && clientes[*i].tipo_servico[k] != 'B' && clientes[*i].tipo_servico[k] != 'C' && clientes[*i].tipo_servico[k] != 'D'){
      			
      			printf ("\n\n\tN�o entendi o que voc� digitou");
      			
      			printf ("\n\n\n\t");
    			system ("pause");
    			system ("cls");
      			
      			//vai mostrar o menu em tela para o usuario 		
	      		printf ("\t******************************************************");
				printf ("\n\t*\t\t\t\t                     *\n\t*\t\t\tOP��ES\t\t\t     *\n\t*\t\t\t\t\t\t     *\n");
				printf ("\t******************************************************\n\n");
	
	     		printf ("\n\t(A) � formata��o com backup         Pre�o: R$ 150,00");
	      		printf ("\n\t(B) � formata��o sem backup         Pre�o: R$ 110,00");
	      		printf ("\n\t(C) � Troca de pe�as                Pre�o: R$ 200,00");
	      		printf ("\n\t(D) � Limpeza e manuten��o b�sica   Pre�o: R$ 100,00\n\n");
	      		
	      		//vai receber o tipo de servico que o suario deseja 
	      		printf("\n\tDigite o tipo de servi�o que voc� deseja:\n\n\t - ");
	
	      		scanf (" %c", &clientes[*i].tipo_servico[k]);
	      		
	      		//vai deixar a op��o com a letra maiuscula 
	      		clientes[*i].tipo_servico[k] = toupper (clientes[*i].tipo_servico[k]);
			  	
			  }

          	//vai receber a quantidade de determiando produto que o cliente desej a
      		printf ("\n\tDigite a quantidade que voc� deseja:\n\n\t - ");
      		scanf  ("%d", &qt);
      
        	//vai verificar qual op��o de servico o usuario escolheu e vai calcular o valor total  
     		switch (clientes[*i].tipo_servico[k]){

        		case 'A':

          			clientes[*i].total_cobrado = clientes[*i].total_cobrado + (qt * 150);
                	//vai contabilizar quantas vezes ele escolheu um tipo de servico
				 	k++;
          			break;

        		case 'B': 

          			clientes[*i].total_cobrado = clientes[*i].total_cobrado + (qt * 110);
          			k++;
          			break;

        		case 'C':

          			clientes[*i].total_cobrado = clientes[*i].total_cobrado + (qt * 200);
          			k++;
          			break;

        		case 'D':

          			clientes[*i].total_cobrado = clientes[*i].total_cobrado + (qt * 100);
				  	k++;
          			break;

        	/*	default:
          		printf ("\n\n\tN�o entendi o que voc� digitou\n");*/
	
      		}

        	//vai verificar se o usuario escolheu 3 pedidos se sim ele s� pode pedir mais um
    		if(k <= 3){
 					
      			printf("\n\tVoc� deseja outro tipo de servi�o? Sim = S N�o = para qualquer outra tecla\n\n\t -");
      			scanf(" %c", &op2);
      			
      			//vai deixar a op��o com letra maiuscula
      			op2 = toupper (op2);
      		}
    	}
    
    	printf ("\n\n\t");
    	system ("pause");
    	system ("cls");

    	//vai receber quantos dias o servico vai levar 
    	printf("\n\tQuantos dias ser�o necess�rios para a execu��o de todo o trabalho:\n\t - ");
    	scanf("%d", &clientes[*i].qtd_dias);

    	//vai receber o nome do cliente
    	printf ("\n\tDigite o nome do cliente:\n\t - ");
    	fflush(stdin);
		gets(clientes[*i].nome);
  
    	//vai mostrar as op��es de servi�o para o cliente
    	printf("\n\tDigite o status da ordem de servi�o\n");
    	printf("\n\t(A) - n�o iniciado");
    	printf("\n\t(B) - servi�o em execu��o");
    	printf("\n\t(C) - Servi�o finalizado\n\n\t - ");
    
    	scanf(" %c",&clientes[*i].status_ordem);
    
    	//vai deixar a variavel com a letra maisucula
    	clientes[*i].status_ordem = toupper(clientes[*i].status_ordem);

    	while (clientes[*i].status_ordem != 'A' && clientes[*i].status_ordem !='B' && clientes[*i].status_ordem != 'C'){

	        printf ("\n\n\tN�o entendi o que voc� digitou");
	
			printf ("\n\n\n\t");
	        system ("pause");
	        system ("cls");
	        //vai mostrar as op��es de servi�o para o cliente
	        printf("\n\tDigite o status da ordem de servi�o\n");
	        printf("\n\t(A) - n�o iniciado");
	        printf("\n\t(B) - servi�o em execu��o");
	        printf("\n\t(C) - Servi�o finalizado\n\n\t - ");
	        scanf(" %c",&clientes[*i].status_ordem);
	        
	        clientes[*i].status_ordem = toupper (clientes[*i].status_ordem);

   		}

	    printf("\n\tDigite o status de pagamento\n");
	    printf("\n\t(A) - aguardando pagamento");
	    printf("\n\t(B) - servi�o pago\n\n\t - "); // um minutin
	    scanf(" %c",&clientes[*i].status_pagamento);
	    
	    clientes[*i].status_pagamento = toupper (clientes[*i].status_pagamento);
	 
	    while (clientes[*i].status_pagamento != 'A' && clientes[*i].status_pagamento != 'B'){
	
	    	printf ("\n\n\tN�o entendi o que voc� digitou");
	
			printf ("\n\n\n\t");
	    	system ("pause");
	    	system ("cls");
	
	    	printf("\n\tDigite o status de pagamento\n");
	    	printf("\n\t(A) - aguardando pagamento");
	    	printf("\n\t(B) - servi�o pago\n\n\t - "); // um minutin
	    	scanf(" %c",&clientes[*i].status_pagamento);
	      
	    	clientes[*i].status_pagamento = toupper (clientes[*i].status_pagamento);
	    }
	    
	    printf("\n\tVoc� deseja cadastrar mais algum cliente? Sim = S N�o = N\n\n\t - ");
	    scanf(" %c",&op);
	    op = toupper(op);
	    	
		while (op != 'S' && op != 'N'){
			
			printf ("\n\n\tN�o entendi o que voc� digitou");
			
			printf ("\n\n\n\t");
			system ("pause");
			system ("cls");
			
			printf("\n\tVoc� deseja cadastrar mais algum cliente? Sim = S N�o = N\n\n\t - ");
	  		scanf(" %c",&op);
	   		op = toupper(op);
		}
		
	    printf ("\n\n\t");
	    system ("pause");
	    system ("cls");
        
	    //vai fazer com que o valor da variavel k seja igual a do cont para que assim possa fazer a repeti��o nas outras fun��es  
	    if (*cont < k){
	    	
	    	//vai passar o numero o numero de tipo de servicos para o ponteiro
	    	*cont = k;
		}
	
	    //vai reinicializar a variavel k para que o proximo pedido seja igual a 0
	    k=0;

	    //vai contabilizar a quantidade de clientes
	    *i = *i + 1;
   }
   
   //vai passar o numero de cliente para o ponteiro 
   *cont2 = *i;
}

//Fun��o mostra servico vai mostrar todos os servicos 
void Mostra_servico(cliente *clientes, int *cont, int *cont2){
	
	//variaveis de controle
	int j,l;
	
	//vai pecorrer todo o vetor cliente 
	for (j=0 ; j < *cont2 ; j++){
		
		printf ("\t******************************************************");
		printf ("\n\t*\t\t\t\t                     *\n\t*\t\t   Ordem de servi�o \t\t     *\n\t*\t\t\t\t\t\t     *\n");
		printf ("\t******************************************************");

		printf ("\n\n\t******************************************************");
    	//vai imprimir os dados de todos os clientes
    	printf ("\n\n\t\tC�digo: %d", clientes[j].codigo);

    	printf ("\n\n\t\tTipo(s) de servico(s): ");
    	printf ("\n");
    
    	//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
    	for (l=0 ; l < *cont ; l++){

         	printf ("\n\t\t - %c",clientes[j].tipo_servico[l]);
    	}

    	printf ("\n\n\t\tQuantidade de dias: %d",clientes[j].qtd_dias);
    	printf ("\n\n\t\tValor total a ser cobrado: %.2f",clientes[j].total_cobrado);
    	fflush(stdin);
    	printf ("\n\n\t\tNome: %s",clientes[j].nome);  
    	printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[j].status_ordem);
    	printf ("\n\n\t\tStatus de pagamento: %c",clientes[j].status_pagamento);
    	printf ("\n\n\t******************************************************");
    	
    	printf ("\n\n\t");
    	system ("pause");
    	system ("cls");
  	}
}

//Fun��o mostra apenas os seri�oes pagos
void Mostra_pagas(cliente *clientes, int *cont, int *cont2){
	
	//variaveis de controle 
	int j,l,p=0;
	
	printf ("\n\n\n\t");
	system ("pause");
	system ("cls");
	
	//vai pecorrer todo o vetor cliente 
	for (j=0 ; j < *cont2 ; j++){

		//vai verificar o status de pagamento de cada cliente e s� vai imprimir os dados daqueles que ja pagaram
		if (clientes[j].status_pagamento == 'B'){
			
			printf ("\t******************************************************");
			printf ("\n\t*\t\t\t\t                     *\n\t*\t\t Ordem de servi�o pagas\t\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");
			
			printf ("\n\n\t******************************************************");	
			printf ("\n\n\t\tC�digo: %d", clientes[j].codigo);

    		printf ("\n\n\t\tTipo(s) de servico(s):");
    		printf ("\n");
    
        	//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
    		for (l=0 ; l < *cont ; l++){

         		printf ("\n\t\t - %c",clientes[j].tipo_servico[l]);
    		}
    		
	        printf ("\n\n\t\tQuantidade de dias: %d",clientes[j].qtd_dias);
	        printf ("\n\n\t\tValor total a ser cobrado: %.2f",clientes[j].total_cobrado);
	        fflush(stdin);
	        printf ("\n\n\t\tNome: %s", clientes[j].nome); 	
	        printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[j].status_ordem);
	        printf ("\n\n\t\tStatus de pagamento: %c",clientes[j].status_pagamento);
	    	printf ("\n\n\t******************************************************");
	    	
	    	printf ("\n\n\t");
    		system ("pause");
    		system ("cls");
        	//vai contabilizar quantos clientes efeturam o pagamento
    		p++;
		}
  	}	
	//caso nenhum cliente tenha pagado vai imprimir a seguinte mensagem 
	if (p == 0){
  		
		printf ("\n\n\tNenhum servi�o foi pago at� o momento");
	}
}

//Fun��o finalizados n�o pagos vai mostrar apenas os dados dos cliente que est�o com o serv�os finzalizados mas que ainda n�o pagaram
void Servicos_fina_naopago(cliente *clientes,int *cont, int *cont2){

	//Variaveis de repi��o 
  	int O,M;

	printf ("\n\n\n\t");
	system ("pause");
	system ("cls");
	
	//vai percorrer o vetor cliente
	for (O = 0 ; O < *cont2 ; O++){
    
	    //vai verificar se o cliente na posi��o O pagou e se o servi�o que ele pediu esta pronto 
	    if(clientes[O].status_pagamento == 'A' && clientes[O].status_ordem == 'C'){
	      
	    	//vai imprimir os dos dos clientes que satisfazem a condi��o 
	    	printf ("\t******************************************************");
			printf ("\n\t*\t\t\t\t                     *\n\t*\tServi�os feitos que ainda n�o foram pagos    *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");
	    	
	    	printf ("\n\n\t******************************************************");
	    	printf ("\n\n\t\tC�digo: %d", clientes[O].codigo); 
	    	printf ("\n\n\t\tTipo(s) de servi�o(s):\n");

      		//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
      		for (M=0 ; M < *cont ; M++){

          		printf("\n\t\t - %c", clientes[O].tipo_servico[M]);
      	}
      	
      	printf ("\n\n\t\tQuantidades de dias: %d", clientes[O].qtd_dias); 
      	printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[O].total_cobrado); 
      	fflush(stdin);
    	printf ("\n\n\t\tNome: %s", clientes[O].nome); 	
    	printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[O].status_ordem);
	    printf ("\n\n\t\tStatus de pagamento: %c",clientes[O].status_pagamento);
	    printf ("\n\n\t******************************************************");
	    
	    printf ("\n\n\t");
    	system ("pause");
    	system ("cls");
    }
  }
}

//Fun��o busca vai receber um c�digo e vai procurar a ordem de servi�o referente a esse codigo 
void Buscar_OS(cliente *clientes,int *cont, int *cont2){

	//Variaveis de repi��o 
  	int S,T;
  	int valor_comparar;
  	
  	printf ("\t******************************************************"); 
	printf ("\n\t*\t\t\t\t                     *\n\t*\t\tBusca uma ordem de servi�o\t     *\n\t*\t\t\t\t\t\t     *\n");
	printf ("\t******************************************************");
  
  	//vai receber o codigo que o cliente deseja
  	printf("\n\n\tDigite o c�digo do Cliente que voc� quer buscar: ");
  	scanf("%d",&valor_comparar);

    //vai pecorrer todo o vetor cliente 
    for (S = 0 ; S < *cont2 ; S++){
      
    	//vai procurar a ordem de servico referente a esse servico 
    	if(valor_comparar == clientes[S].codigo){
        
	        //vai imprimir todos os dados do cliente refente a esse c�digo     
	        printf ("\n\n\t******************************************************");
	        printf ("\n\n\t\tC�digo: %d", clientes[S].codigo); 
	        printf ("\n\n\t\tTipo(s) de servi�o(s):\n");
	
	        //como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
	        for (T=0 ; T < *cont ; T++){
	
	        	printf("\n\t\t - %c", clientes[S].tipo_servico[T]);
	
	        }
			printf ("\n\n\t\tQuantidades de dias: %d", clientes[S].qtd_dias); 
        	printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[S].total_cobrado); 
        	fflush(stdin);
        	printf ("\n\n\t\tNome: %s", clientes[S].nome); 
        	printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[S].status_ordem);
	 	    printf ("\n\n\t\tStatus de pagamento: %c",clientes[S].status_pagamento);
        	printf ("\n\n\t******************************************************");
      }
    }  
    printf ("\n\n\n\t");
	system ("pause");
	system ("cls");
}

//Fun��o mostra em execu��o vai imprimir todas as ordem de servico que esta� em execu��o 
void Mostra_em_execucao(cliente *clientes, int *cont, int *cont2){

	printf ("\n\n\n\t");
	system("pause");
	system("cls");

	//variavel a de controle 
	int x,z;

	//vai pecorrer todo o vetor cliente 
	for(z=0 ; z < *cont2 ; z++){

    	//vai verificar se o servi�o esta em excu��o para cada cliente 
		if(clientes[z].status_ordem == 'B'){

			printf ("\t******************************************************"); 
			printf ("\n\t*\t\t\t\t                     *\n\t*\t\tServi�os em execu��o\t\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");
			
			printf ("\n\n\t******************************************************");
      		printf ("\n\n\t\tC�digo: %d", clientes[z].codigo); 	
      		printf ("\n\n\t\tTipo(s) de servi�o(s):\n");

      		//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
			for(x=0 ; x < *cont ; x++){

				printf("\n\t\t - %c", clientes[z].tipo_servico[x]);
			}
			
			printf ("\n\n\t\tQuantidades de dias: %d", clientes[z].qtd_dias); 
      		printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[z].total_cobrado); 
      		fflush(stdin);
			printf ("\n\n\t\tNome: %s", clientes[z].nome); 
			printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[z].status_ordem);
	 	    printf ("\n\n\t\tStatus de pagamento: %c",clientes[z].status_pagamento);
      		printf ("\n\n\t******************************************************");
      		
      		printf ("\n\n\n\t");
			system("pause");
			system("cls");
		}
	}
}

//Fun��o mostra finalizados vai imprimir todas as ordens de servi�os que foram finzalizados 
void Mostra_finalizados(cliente *clientes, int *cont, int *cont2){

	printf ("\n\n\n\t");
	system("pause");
	system("cls");

	//variavel de controle
	int z,x;

	//vai pecorrer todo o vetor cliente 
	for(z=0 ; z < *cont2 ; z++){

		if(clientes[z].status_ordem == 'C'){
			
			printf ("\t******************************************************"); 
			printf ("\n\t*\t\t\t\t                     *\n\t*\t\tServi�os finalizados\t\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");

			printf ("\n\n\t******************************************************");
			printf ("\n\n\t\tC�digo: %d", clientes[z].codigo); 

      		printf ("\n\n\t\tTipo(s) de servi�o(s):\n");

      		//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
			for(x=0 ; x < *cont ; x++){

				printf("\n\t\t - %c", clientes[z].tipo_servico[x]);
			}
			
			printf ("\n\n\t\tQuantidades de dias: %d", clientes[z].qtd_dias); 
      		printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[z].total_cobrado); 
			fflush(stdin);
			printf ("\n\n\t\tNome: %s", clientes[z].nome); 
			printf ("\n\n\t\tStatus da ordem de servi�o: %c",clientes[z].status_ordem);
	 	    printf ("\n\n\t\tStatus de pagamento: %c",clientes[z].status_pagamento);
	 	    printf ("\n\n\t******************************************************");
	 	    
	 	    printf ("\n\n\n\t");
			system("pause");
			system("cls");
		}
	}
}

//Fun��o agurda pagamento vai imprimir apenas apenas as ordem de servi�o que n�o recebram pagamento ainda
void Visualizar_pagamento(cliente *clientes, int *cont, int *cont2){

	//variaveis de controle 
	int i, j;
	
	printf ("\n\n\n\t");
	system("pause");
	system("cls");
	
	//vai pecorrer todo o vetor cliente 
	for(i = 0; i < *cont2; i ++){

    	//va verificar quais clientes ainda n�o efeturam pagamento 
		if(clientes[i].status_pagamento == 'A'){
			
			printf ("\t******************************************************"); 
			printf ("\n\t*\t\t\t\t                     *\n\t*\t   Servi�os que agurdam pagamentos\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");

			printf ("\n\n\t******************************************************");
			printf ("\n\n\t\tC�digo: %d", clientes[i].codigo); 
			printf ("\n\n\t\tTipos de servi�o:\n");

      		//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
			for(j = 0; j < *cont; j ++){
		
				printf("\n\t\t - %c", clientes[i].tipo_servico[j]);
			
			}
			
			printf ("\n\n\t\tQuantidades de dias: %d", clientes[i].qtd_dias); 
			printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[i].total_cobrado);
			fflush(stdin);
      		printf ("\n\n\t\tNome: %s", clientes[i].nome);
			printf("\n\n\t\tStatus da ordem de servi�o: %c", clientes[i].status_ordem);
			printf("\n\n\t\tStatus de pagamento: %c", clientes[i].status_pagamento);
			printf ("\n\n\t******************************************************");
			
			printf ("\n\n\n\t");
			system("pause");
			system("cls");
		}
	}
}

//Fun��o servi�os n�o inicializados vai imprimir todos os tipos de servi�os que n�o foram inicializados 
void Visualizar_nao_inicializados(cliente *clientes, int *cont, int *cont2){
  
	//variaveis de controle
	int i, j;
	
	printf ("\n\n\n\t");
	system("pause");
	system("cls");
	
	//vai percorrer todo o vetor cliente
	for(i = 0 ; i < *cont2 ; i ++){
     
    	//vai verificar se o cliente na posi��o i teve seu servico n�o inicizalidos 
		if(clientes[i].status_ordem == 'A'){
			
			printf ("\t******************************************************"); 
			printf ("\n\t*\t\t\t\t                     *\n\t*\t\tServi�os n�o iniciados\t\t     *\n\t*\t\t\t\t\t\t     *\n");
			printf ("\t******************************************************");

      		printf ("\n\n\n\t******************************************************");
			printf ("\n\n\t\tC�digo: %d", clientes[i].codigo); 		
      		printf ("\n\n\t\tTipo(s) de servi�o(s):\n");

      		//como o tipo de servico � um vetor � necessario criar um segundo for para percorrer ele
			for(j = 0; j < *cont; j ++){
				
			  printf("\n\t\t - %c", clientes[i].tipo_servico[j]);
			
			}
			
			printf ("\n\n\t\tQuantidades de dias: %d", clientes[i].qtd_dias); 
			printf ("\n\n\t\tValor total a ser cobrado: %.2f", clientes[i].total_cobrado);
			fflush(stdin);
      		printf ("\n\n\t\tNome: %s", clientes[i].nome);
			printf("\n\n\t\tStatus de pagamento: %c", clientes[i].status_pagamento);
			printf("\n\n\t\tStatus da ordem de servi�o: %c", clientes[i].status_ordem);
			
			printf ("\n\n\n\t\t");
			system("pause");
			system("cls");
		}
	}	
}

// Calcular o valor total em caixa baseado nos servi�os que j� foram pagos.
void Calucular_valor_pagos(cliente *clientes,int *cont, int *cont2){

	//variavel para a repeti��o
	int S;
	
	//valor que vai sendo somado 
	float valor_caixa = 0;
  
	printf ("\n\n\n\t");
	system("pause");
	system("cls");
	
	//vai pecorrer todo o vetor cliente
	for (S = 0 ; S < *cont2 ; S++){
      
    	//Verificar se o servi�o foi pago
    	if( clientes[S].status_pagamento == 'B'){
        
    	valor_caixa = valor_caixa + clientes[S].total_cobrado;  
    	}
 	}
  
 	printf ("\n\n\n\t******************************************************");
	printf ("\n\t*\t\t\t\t                     *\n\t*\tValor total para os servi�os pagos: %.2f   *\n\t*\t\t\t\t\t\t     *\n",valor_caixa);
	printf ("\t******************************************************");
	
	printf ("\n\n\n\t");
	system("pause");
	system("cls");
}

//Calcular o valor total de servi�os (pagos e n�o pagos).
void Calucular_valor_todos(cliente *clientes,int *cont, int *cont2){

	//variavel para a repeti��o
	int S;
	//valor que vai sendo somado 
	float valor_caixa = 0;
	
	printf ("\n\n\n\t");
	system("pause");
	system("cls");

	//vai pecorrer todo o vetor cliente 
	for (S = 0 ; S < *cont2 ; S++){
      
    	valor_caixa = valor_caixa + clientes[S].total_cobrado; 
    }

  	printf ("\n\n\n\t******************************************************");
	printf ("\n\t*\t\t\t\t                     *\n\t*\t     Valor total no caixa: %.2f \t     *\n\t*\t\t\t\t\t\t     *\n",valor_caixa);
	printf ("\t******************************************************");
  
   printf ("\n\n\n\t");
   system("pause");
   system("cls");
}
