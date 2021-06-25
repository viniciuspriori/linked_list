#include <iostream>
using namespace std;

struct tTriangulo{
  int lado1;
  int lado2;
  int lado3;
};

struct tNo{
  tTriangulo info;
   //aqui vai a struct
  tNo* proximo;
};

tNo* criaNo(tTriangulo t){
  tNo* no = new tNo;
  no -> info = t;

  cout << "criando nó t.lado2 (2): " << no -> info.lado2 << endl; 
   //struct
  no -> proximo = NULL;
  return no;
}

struct tLista{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void inicializaLista(tLista* pLista){
    pLista -> primeiro = NULL;
    pLista -> ultimo = NULL;
    pLista -> marcador = NULL;
    pLista -> tamanho = 0;
    cout << "Lista inicializada. \n";
}

int obterTamanho(tLista* pLista){
    return (pLista -> tamanho);
}

bool listaVazia(tLista* pLista){
  return (pLista -> tamanho==0);
}

bool finalLista(tLista* pLista){
  return (pLista -> marcador == NULL);
}

void incluirNoFim(tLista* pLista, tTriangulo t){
  tNo* no;
  no = criaNo(t);//

  if(listaVazia(pLista)){
    pLista -> primeiro = no; 
  } else {
      pLista -> ultimo -> proximo = no;
  } 
    pLista -> ultimo = no;
    pLista -> marcador = no;
    pLista -> tamanho ++;

    cout << "\nObjeto incluido na lista." << endl; 
}

void imprimirLista(tLista* pLista){
  cout << "\nImprimindo lista: " << endl;
  pLista -> marcador = pLista -> primeiro;

  while(!finalLista(pLista)){
    tTriangulo t = pLista -> marcador -> info; //

    cout << t.lado1 << " " << t.lado2 << " " << t.lado3 << " " << endl;

    pLista -> marcador = pLista -> marcador -> proximo; 
  }
}

int main(){
  tLista* triangulos = new tLista;
  tTriangulo t;

  cin >> t.lado1;
  cin >> t.lado2;
  cin >> t.lado3; 

  //cout << "[erro] t.lado2 main " << t.lado2 << endl; 

  inicializaLista(triangulos);

  cout << "tam: " << obterTamanho(triangulos) << endl;


  incluirNoFim(triangulos, t);
  incluirNoFim(triangulos, t);

  cout << "tam: " << obterTamanho(triangulos) << endl;

  imprimirLista(triangulos);

  //incluirNoFim(triangulos, t);
  cout << "tam: " << obterTamanho(triangulos) << endl;

  //imprimirLista(triangulos);

  //  cout << "ultimo : " << triangulos -> ultimo -> info << endl;
}