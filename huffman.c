#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//--------------------- structure pour la source d'information
struct codage{
  char symbole[100];
  int freq;
};

typedef struct codage codage;


//------------------- structure pour l'arbre de Huffman
struct noeud{
  char symbole[100];
  struct noeud *fils_g;
  struct noeud *fils_d;
  struct noeud *pere;
};

typedef struct noeud noeud;

// cette fonction prend une chaine caractere
// remplit un tableau freq de taille 256
// avec les frequences de chaque caracteres ASCII
void frequence(int *freq,char *chaine)
{
  char car;
  int i;
  int length;

  // on recupere la longueur de la chaine
  length=strlen(chaine);

  //on initialise le tableau de frequence à 0
  for(i=0;i<256;i++)
    {
      freq[i]=0;
    }
  
  // on calcule les frequences
  // de chaque caracteres dans la chaine 
  for(i=0;i<length;i++)
    {
      car=chaine[i];
      freq[car]++;
    }

  return;
}


void  tri_bulle(codage *tab_codage, int length)
{
  int u;
  char s[100];
  int i,j;

  for(i=0;i<length;i++)
    {
      for(j=0;j<length-1;j++)
	{
	  if( tab_codage[j].freq < tab_codage[j+1].freq )
	    {
	      // on permute tab_codage[j] et tab_codage[j+1]
	      // symbole
	      strcpy(s,tab_codage[j].symbole);
	      strcpy(tab_codage[j].symbole,tab_codage[j+1].symbole);
	      strcpy(tab_codage[j+1].symbole,s);
	      
	      //freq
	      u=tab_codage[j].freq;
	      tab_codage[j].freq=tab_codage[j+1].freq;
	      tab_codage[j+1].freq=u;
	    }
	}
    }
  return;
}

// init_tab_codage
// remplit tab_codage avec les caractères de freq > 0
// et les ordonne par ordre decroissant
// renvoie la taille du tableau
int init_tab_codage(codage *tab_codage,int *freq)
{
  int nb=0,i,j,length;

  // on insere dans tab_codage
  // chaque caractere de freq > 0
  j=0;
  for(i=0;i<256;i++)
    {
      if(freq[i] > 0)
	{
	  tab_codage[j].freq=freq[i];
	  tab_codage[j].symbole[0]=(char)i;
	  tab_codage[j].symbole[1]='\0';
	  j++;
	}
    }

  length=j;
  // on affiche le contenu de tab_codage
  for(i=0;i<length;i++)
    {
      printf("caractère \"%s\", freq=%d\n",tab_codage[i].symbole,tab_codage[i].freq); 
    }

  // on trie le tableau
  tri_bulle(tab_codage, length);

  // on re-affiche le contenu de tab_codage (trié)
  for(i=0;i<length;i++)
    {
      printf("caractère \"%s\", freq=%d\n",tab_codage[i].symbole,tab_codage[i].freq); 
    }

  return(length);
}


//--------- fonction qui recherche dans l'arbre racine la feuille contenant  symbole
noeud *trouve_noeud(noeud *racine,char *symbole)
{
  noeud *t;
  t=racine;
  int compteur=0;
  //printf("trouve noeud\n");
  while( (t != NULL) )
    {
      //printf("trouve noeud %d\n",compteur);
      //compteur++;
      if( strcmp(t->symbole,symbole) == 0)
	{
	  return(t);
	}
      else if( (t->fils_g != NULL ) && ( strstr((t->fils_g)->symbole,symbole) != NULL) )
	{	 
	  //printf("g:%s\n",(t->fils_g)->symbole);
	t=t->fils_g;	
	}
      else if( (t->fils_d != NULL ) && ( strstr((t->fils_d)->symbole,symbole) != NULL) )
	{
	  //printf("d:%s\n",(t->fils_d)->symbole);
	      t=t->fils_d;
	}
      else
	return(NULL);
    }


}



noeud *huffman_code(codage *source,  int N)
{
	if(N>1){
		strcat(source[N-2].symbole,source[N-1].symbole);
		source[N-2].freq+=source[N-1].freq;
		printf("Caractère: %s, fréquence: %d \n",source[N-2].symbole,source[N-2].freq);
		tri_bulle(source, N-1);
		huffman_code(source,N-1);
	
		
	}

}


int main()
{

  // char *chaine="aaababaaabababcddddbcaaaabaa";
  char *chaine="aaababaaababbbbbbbbbbbbabcddddbcaaabbbbbbbbbbbabbaa";
 
  int freq[256];
  codage source[256];
  int length;
  noeud *racine;

  frequence(freq,chaine);
  length=init_tab_codage(source,freq);
	

  racine=huffman_code(source,length);
 /* Essais pour les noeud
	int i;
	for(i=0;i<length;i++){
		racine.symbole=source[N-1].symbole;
		racine.fils_d;

*/
  return(EXIT_SUCCESS);
}




