#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct key{
	int pos[3]; // 3 entiers dans 0..25 qui donnent les positions initiale des rotors RI,RII,RIII
	int connecteur[6][2]; // les 6  connecteurs : 
                        // la lettre connecteur[i][0] est échangée avec  
                        //la lettre connecteur[i][1]
};

typedef struct key key;


void chiffrement_enigma(char *clair, char *chiffre, key k)
{	
	int a,b;

			
	int RI[26]={9,6,3,16,14,23,20,18,2,0,12,8,5,17,21,19,15,13,4,22,10,1,11,25,24,7};
	int inv_RI[26]={9,21,8,2,18,12,1,25,11,0,20,22,10,17,4,16,3,13,7,15,6,14,19,5,24,23};

	int RII[26]={13,19,25,15,18,5,1,14,10,12,22,17,2,9,3,8,21,11,0,4,24,20,23,7,6,16};
	int inv_RII[26]={18,6,12,14,19,5,24,23,15,13,8,17,9,0,7,3,25,11,4,1,21,16,10,22,20,2};

	int RIII[26]={9,21,8,20,1,7,19,2,3,24,0,10,4,16,25,15,14,18,6,23,13,17,12,22,5,11};
	int inv_RIII[26]={10,4,7,8,12,24,18,5,2,0,11,25,22,20,16,15,13,21,17,6,3,1,23,19,9,14};

	int reflecteur[26]={24,17,20,7,16,18,11,3,15,23,13,6,14,10,12,8,4,1,5,25,2,22,21,9,0,19};
	for(a=0;a<k.pos[0];a++){
		for(b=0;b<26;b++)
			RI[b]=RI[(b+1)%26];
	}

	for(a=0;a<k.pos[1];a++){
		for(b=0;b<26;b++)
			RII[b]=RII[(b+1)%26];
	}

	for(a=0;a<k.pos[2];a++){
		for(b=0;b<26;b++)
			RIII[b]=RIII[(b+1)%26];
	}
	int i,j,res=0;
	for(i=0;i<strlen(clair);i++){

		//Lettre à ASCII
		char c = clair[i]-'A';

		//Connecteurs
		for(j=0;j<6;j++){
			if(k.connecteur[j][0]==c)
				c=k.connecteur[j][1];
			else if(k.connecteur[j][1]==c)
				c=k.connecteur[j][0];
		}

		//Rotors
		c=RI[c];
		c=RII[c];
		c=RIII[c];

		//Reflecteur
		c=reflecteur[c];

		//Rotors inverses
		c=inv_RI[c];
		c=inv_RII[c];
		c=inv_RIII[c];

		//Connecteurs
		for(j=0;j<6;j++){
			if(k.connecteur[j][0]==c)
				c=k.connecteur[j][1];
			else if(k.connecteur[j][1]==c)
				c=k.connecteur[j][0];
		}
		
		//Entier à ASCII
		c+='A';
		chiffre[i]=c;
		res++;
		int l;
		k.pos[0]=(k.pos[0]+1)%26;
		for(l=0;l<26;l++)
			RI[l]=RI[(l+1)%26];
			

		if(res%26==0){
			k.pos[1]=(k.pos[0]+1)%26;
			for(l=0;l<26;l++)
				RII[l]=RII[(l+1)%26];
		}
		
		if(res%(26*26)==0){
			k.pos[2]=(k.pos[0]+1)%26;
			for(l=0;l<26;l++)
				RIII[l]=RIII[(l+1)%26];
		}
					
	}
	chiffre[strlen(clair)]='\0';
	printf("%s\n",chiffre);
	return;
}

double indice_confiance(char * message){
  	int i, IndConf,g[26], frequence[26],res=0,res1=0,res2=0;
	char c;
	double pourcentages_francais[26]={9.42, 1.02,	2.64, 3.39, 15.87, 0.95, 1.04, 0.77, 8.41, 0.89, 0.00, 5.34, 3.24, 7.15, 5.14, 2.86, 1.06, 6.46, 7.90, 7.26, 6.24,  2.15, 0.00, 0.30, 0.24, 0.32};

	for(i=0;i<strlen(message);i++){
		c=message[i]-'A';
		frequence[c]++;
		res++;
	}

	for(i=0;i<26;i++){
		g[i]=((12/26)*(1/26)+(14/26)*pourcentages_francais[i]);
		frequence[i]=frequence[i]/res;
	}
	for(i=0;i<26;i++){
		res1+=(frequence[i]*100)*(frequence[i]*100);
		res2+=(g[i]*100)*(g[i]*100);
	}
	IndConf=abs(res1-res2);
		
		
	return IndConf;

}


void analyse(char *chiffre) {
	/*int i,j,k;
	key k;
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			for(l=0;l<26;l++){
				k.pos[0]=l;
				k.pos[1]=j;
				k.pos[2]=i;

				indice_confiance(*/
				
}


int main() {
	char *clair="COSETTEETAITLAIDEHEUREUSEELLEEUTPEUTETREETEJOLIENOUSAVONSDEJAESQUISSECETTEPETITEFIGURESOMBRECOSETTEETAITMAIGREETBLEMEELLEAVAITPRESDEHUITANSONLUIENEUTDONNEAPEINESIXSESGRANDSYEUXENFONCESDANSUNESORTEDOMBREPROFONDEETAIENTPRESQUEETEINTSAFORCEDAVOIRPLEURELESCOINSDESABOUCHEAVAIENTCETTECOURBEDELANGOISSEHABITUELLEQUONOBSERVECHEZLESCONDAMNESETCHEZLESMALADESDESESPERESSESMAINSETAIENTCOMMESAMERELAVAITDEVINEPERDUESDENGELURESLEFEUQUILECLAIRAITENCEMOMENTFAISAITSAILLIRLESANGLESDESESOSETRENDAITSAMAIGREURAFFREUSEMENTVISIBLECOMMEELLEGRELOTAITTOUJOURSELLEAVAITPRISLHABITUDEDESERRERSESDEUXGENOUXLUNCONTRELAUTRETOUTSONVETEMENTNETAITQUUNHAILLONQUIEUTFAITPITIELETEETQUIFAISAITHORREURLHIVERELLENAVAITSURELLEQUEDELATOILETROUEEPASUNCHIFFONDELAINEONVOYAITSAPEAUcAETLAETLONYDISTINGUAITPARTOUTDESTACHESBLEUESOUNOIRESQUIINDIQUAIENTLESENDROITSOULATHENARDIERLAVAITTOUCHEESESJAMBESNUESETAIENTROUGESETGRELESLECREUXDESESCLAVICULESETAITAFAIREPLEURERTOUTELAPERSONNEDECETTEENFANTSONALLURESONATTITUDELESONDESAVOIXSESINTERVALLESENTREUNMOTETLAUTRESONREGARDSONSILENCESONMOINDREGESTEEXPRIMAIENTETTRADUISAIENTUNESEULEIDEELACRAINTELACRAINTEETAITREPANDUESURELLEELLEENETAITPOURAINSIDIRECOUVERTELACRAINTERAMENAITSESCOUDESCONTRESESHANCHESRETIRAITSESTALONSSOUSSESJUPESLUIFAISAITTENIRLEMOINSDEPLACEPOSSIBLENELUILAISSAITDESOUFFLEQUELENECESSAIREETETAITDEVENUECEQUONPOURRAITAPPELERSONHABITUDEDECORPSSANSVARIATIONPOSSIBLEQUEDAUGMENTERILYAVAITAUFONDDESAPRUNELLEUNCOINETONNEOUETAITLATERREUR";
	//char *chiffre= malloc(sizeof(strlen(clair)+1)*(char));
	char chiffre[strlen(clair)+1];	
	key k= {{1,2,3},{{4,5}, {6,1},{18,21},{3,22},{12,25},{11,19}}};
	chiffrement_enigma(clair,chiffre,k);


	return(0);
}



