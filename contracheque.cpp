#include <iostream>
#include <locale.h>

using namespace std;

main(){
	setlocale(LC_ALL, "Portuguese");
	
	string nome;
	int i, valorFilho;
	double salarioBase, inss, impostoRenda, fgts, valeTransporte , salarioFamilia, valorLiquido, vencimentos, descontos;
	bool confirmaFilho, erro = true;

	// Inserção de Dados
	cout << "\nInsira seu nome: ";
	cin >> nome;
	
	cout << "\nInsira o quanto você ganha: R$";;
	cin >> salarioBase;
	
	while (erro == true) {
		cout << "\nVocê por acaso tem filho(a) menor de 14 anos? Diga 1 para sim ou 0 não: ";
		cin >> valorFilho;
		
		//Verificação se a pessoa tem filho ou não
		if (valorFilho == 1) {
			confirmaFilho = true;
			erro = false;
			break;
		} else if (valorFilho == 0){
			confirmaFilho = false;
			erro = false;
			break;
		} else {
			cout << "Insira um valor válido. (0 ou é 1) \n"; 
		}
	}
		
	// Cálculo do INSS
	if (salarioBase <= 1751.81) {
		inss = salarioBase * 0.08;
	} else if (salarioBase > 1751.82 && salarioBase <= 2919.72) {
		inss = salarioBase * 0.09;
	} else if (salarioBase > 2919.72 && salarioBase <= 5839.45) {
		inss = salarioBase * 0.11;
	} else {
		inss = 570.88;
	}
	
	// Cálculo do Imposto de Renda
	if (salarioBase <= 1903.98) {
		impostoRenda = 0;
	} else if (salarioBase > 1903.98 && salarioBase <= 2826.65) {
		impostoRenda = salarioBase * 0.075;
	} else if (salarioBase > 2826.65 && salarioBase <= 3751.05) {
		impostoRenda = salarioBase * 0.15;
	} else if (salarioBase > 3751.05 && salarioBase <= 4664.68){
		impostoRenda = salarioBase * 0.0225;
	} else if (salarioBase > 4664.68){
		impostoRenda = salarioBase * 0.0275;
	} else {
		cout << "Insira um valor válido. (0 ou é 1) \n";
	}
	
	// Cálculo do Salário Família
	if (confirmaFilho == true){
		if (salarioBase <= 907.77) {
			salarioFamilia = 46.54;
		} else if (salarioBase > 907.77 && salarioBase <= 1364.43) {
			salarioFamilia = 32.80;
		} else {
			salarioFamilia = 0;
		}
	}
	
	// Cálculo FGTS
	fgts = salarioBase * 0.08;
	
	// Vale Transporte
	valeTransporte = salarioBase * 0.06;
	
	// Soma dos vencimentos e descontos
	vencimentos = salarioFamilia + valeTransporte;
	descontos = inss + impostoRenda;
	
	// Cálculo do valor líquido
	valorLiquido = salarioBase + vencimentos - descontos;
		
	// Retornos
	cout << "\n\n" << nome << ", você paga: \n\nR$" << inss << " de INSS; \n\n";
	
	if (salarioBase <= 1903.98) {
		cout << "Não paga imposto; \n\n";	
	} else {
		cout << "R$" << impostoRenda << " de Imposto de Renda; \n\n";
	}
	
	if (confirmaFilho == true) {
		if (salarioBase <= 1364.43) {
		cout << "Recebe R$" << salarioFamilia << " de Salário Família; \n\n";
		} else if (salarioFamilia == 0) {
			cout << "Não tem direito a Salário Família; \n\n";
		}
	} else if (confirmaFilho == false) {
		cout << "Não tem direito a Salário Família, já que você não tem filho(a) menor de 14 anos; \n\n";
	}
	
	cout << "Recebe R$" << valeTransporte << " de Vale Transporte; \n\n";
	cout << "E você acumula R$" << fgts << " de FGTS.\n\n\n\n";
	cout << "O total dos seus vencimentos é de R$" << vencimentos << " e de seus descontos é de R$" << descontos << ". \n\n";
	cout << "Valor Líquido: R$" << valorLiquido << ".\n\n\n\n\n\n\n";
	
	return 0;
}


/*

Links de Refêrencia dos Valores Utilizados (Maio de 2019):

INSS: https://calendariobolsafamilia2019.com.br/tabela-inss-2019/
Imposto de Renda: https://impostoderenda2019.blog.br/calculo-imposto-de-renda-2019/
Salário Família: http://audtecgestao.com.br/capa.asp?infoid=3964
FGTS: https://www.socontabilidade.com.br/conteudo/duvida4.php

*/
