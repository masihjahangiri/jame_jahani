#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define TEDADE_TEAM_HA 32

/*define fuctions-----------------------------------------------------------------------------------------*/
char** str_split(char* a_str, const char a_delim); // resource :  https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
int read_teams_and_put_to_struct();
int read_bazikonane_team_and_put_to_struct();
void chidane_barnameye_baziha_dar_marhaleye_gorohi();
int gereftane_id_team_by_goroh_and_index_goroh(char goroh,short int index_goroh);
void gozashtan_id_teamha_dar_goroh_ha();
void sort_kardane_goroh_ha();
void chidane_tarkibe_defualt_teamha();
short int gereftane_index_bazikoni_ke_max_skill_poste_asli(short int id_team , char poste);
/*define fuctions------------------------------------------------------------------------------------[end]*/


struct bazikon_info{
	short int shomare_lebas;
	char name[30];
	short int age;
	
	char poste_asli;
	char poste_feli;
	
	short int skill;
	short int fitness;
	short int form;
	
	short int aya_bazikon_dar_tarkibe_aslist; // if yes value = 1 , else value = 0
};

struct team_info{
	char name[30];
	char group;
	short int group_index;
	char confederation[30];
	short int sabade_ghoree_keshi;
	char file_name[30];
	struct bazikon_info bazikon[100];
	short int bazikon_len;
} Team_info[TEDADE_TEAM_HA] ={0};










struct natije_bazi_gorohi{
	short int id_teame_aval;
	char tedade_gole_zade__teame_aval;
	
	short int id_teame_dovom;
	char tedade_gole_zade__teame_dovom;
};

struct natije_bazi_hazfi{
	short int id_teame_aval;
	char tedade_gole_zade__teame_aval_dar_vaghte_ghanoni;
	char tedade_gole_zade__teame_aval_dar_vaghte_ezafe;
	char tedade_gole_zade__teame_aval_dar_vaghte_penalti;
	
	short int id_teame_dovom;
	char tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni;
	char tedade_gole_zade__teame_dovom_dar_vaghte_ezafe;
	char tedade_gole_zade__teame_dovom_dar_vaghte_penalti;
};


struct jadvale_natayej{
	short int ta_marhaleye_chand_pish_rafte;
	struct natije_bazi_gorohi dore_avale_gorohi[16]; 
	struct natije_bazi_gorohi dore_dovom_gorohi[16]; 
	struct natije_bazi_gorohi dore_sevom_gorohi[16];
	
	struct natije_bazi_hazfi dore_yek_hashtome_nahaee[8];  
	struct natije_bazi_hazfi dore_yek_chaharome_nahaee[4];  
	struct natije_bazi_hazfi dore_nime_nahaee[2]; 
	struct natije_bazi_hazfi dore_radebandi_va_final[2]; 
	
} Jadvale_natayej={0};











struct goroh{
	short int id_teams;
	short int tedad_bazi;
	
	short int tedad_bord;
	short int tedad_mosavi;
	short int tedad_bakht;
	
	short int tedad_gole_zade;
	short int tedad_gole_khorde;
	
	short int emtiyaz;
	short int tafazole_gol;
	
} Goroh_ha[8][4] ={0};







int main(){
	
    int i =0 , j=0 ;
    
    read_teams_and_put_to_struct();
    read_bazikonane_team_and_put_to_struct();
    chidane_barnameye_baziha_dar_marhaleye_gorohi();
    gozashtan_id_teamha_dar_goroh_ha();
    sort_kardane_goroh_ha();
    chidane_tarkibe_defualt_teamha();
//    for(i=0;i<8;i++){
//    	printf("\n\n\n\n%c\n",i+65);
//    	for(j=0;j<4;j++)
//    	printf("\n%s ====>  || emtiyaz = %d  || tafazol = %d  || tedad gole zade = %d ",Team_info[Goroh_ha[i][j].id_teams],Goroh_ha[i][j].emtiyaz,Goroh_ha[i][j].tafazole_gol,Goroh_ha[i][j].tedad_gole_zade);
//    	
//	}
	
	
	for(i=0;i<36;i++){

    
    	printf("\n%s ====>     post = %c       || skill = %d   || to tarkibe asli hast? %d",Team_info[11].bazikon[i].name,Team_info[11].bazikon[i].poste_asli,Team_info[11].bazikon[i].skill,Team_info[11].bazikon[i].aya_bazikon_dar_tarkibe_aslist);
    	
	}
	                         
	return 0 ;
}



int read_teams_and_put_to_struct(){
	FILE *fp = fopen("files\\Teams\\Teams.csv", "r");
	if (!fp) {
		perror("fail to open <file\\Teams\\Teams.csv>: ");
		return 0;
	}
	
	char buffer[100];
	char **buffer_joda_shode;
	int i = 0;
	
	while (fgets(buffer, 100, fp) != NULL) {
		
		buffer_joda_shode = str_split(buffer, ',');
		
		
		
	        strcpy(Team_info[i].name,buffer_joda_shode[0]);
	        free(buffer_joda_shode[0]);
	        
	        Team_info[i].group=buffer_joda_shode[1][0];
	        free(buffer_joda_shode[1]);
	        
	        Team_info[i].group_index = buffer_joda_shode[2][0]-48;
	        free(buffer_joda_shode[2]);
	        
	        strcpy(Team_info[i].confederation,buffer_joda_shode[3]);
	        free(buffer_joda_shode[3]);
	        
	        Team_info[i].sabade_ghoree_keshi = buffer_joda_shode[4][0]-48;
	        free(buffer_joda_shode[4]);
	         
	        strcpy(Team_info[i].file_name,buffer_joda_shode[5]);
	        Team_info[i].file_name[strlen(Team_info[i].file_name) - 1 ] = 0;  // baraye hazfe \n az akhar "buffer_joda_shode" string
	        free(buffer_joda_shode[5]);
	       
	       
	       
	        free(buffer_joda_shode);
	    
	   
		i++;
	}
	
	fclose(fp);
	fp = NULL;
	
	return 0 ;
}


int read_bazikonane_team_and_put_to_struct(){
	int counter=0;
	char dir[100] = "files\\Teams\\";
	FILE *fp;
	
	srand(time(NULL));   // should only be called once
    int random_number =0;
	
	for (counter=0;counter<TEDADE_TEAM_HA;counter++){
				
		strcat(dir,Team_info[counter].file_name);
		
		fp = fopen(dir, "r");
		
		if (!fp) {
			perror("fail to open team file");
			return 0;
		}
		
		char buffer[100];
		char **buffer_joda_shode;
		int i = 0;


		while (fgets(buffer, 100, fp) != NULL) {
			
			buffer_joda_shode = str_split(buffer, ',');
			
			
			    Team_info[counter].bazikon[i].shomare_lebas = i+1 ;
			    
			    
			    
		        strcpy(Team_info[counter].bazikon[i].name,buffer_joda_shode[1]);
		        free(buffer_joda_shode[1]);
		        
		        Team_info[counter].bazikon[i].age = (buffer_joda_shode[2][0]-48)*10 + (buffer_joda_shode[2][1]-48);
		        free(buffer_joda_shode[2]);
		        
		        Team_info[counter].bazikon[i].poste_asli =buffer_joda_shode[3][0] ;
		        Team_info[counter].bazikon[i].poste_feli =buffer_joda_shode[3][0] ;
		        free(buffer_joda_shode[3]);
		       
		       
		        free(buffer_joda_shode);
		        
		        
		        
		        
		        
		        
		        Team_info[counter].bazikon[i].fitness = 86 ;
			    Team_info[counter].bazikon[i].form = 86 ;
			    
			    
			    
			    
				        if(strcmp(Team_info[counter].name, "Germany")==0)
				        	random_number = rand() % 1602;
				        
				        else if(strcmp(Team_info[counter].name, "Brazil")==0)
				        	random_number = rand() % 1483;
				        	
				        else if(strcmp(Team_info[counter].name, "Portugal")==0)
				        	random_number = rand() % 1358;
						
						else if(strcmp(Team_info[counter].name, "Argentina")==0)
				        	random_number = rand() % 1348;
				        
				        else if(strcmp(Team_info[counter].name, "Belgium")==0)
				        	random_number = rand() % 1325;
				        	
				        else if(strcmp(Team_info[counter].name, "Spain")==0)
				        	random_number = rand() % 1231;
				        	
				        else if(strcmp(Team_info[counter].name, "Poland")==0)
				        	random_number = rand() % 1209;
				        	
				        else if(strcmp(Team_info[counter].name, "Switzerland")==0)
				        	random_number = rand() % 1190;
				        	
				        else if(strcmp(Team_info[counter].name, "France")==0)
				        	random_number = rand() % 1183;
				        	
				        else if(strcmp(Team_info[counter].name, "Peru")==0)
				        	random_number = rand() % 1128;
				        	
				        else if(strcmp(Team_info[counter].name, "Denmark")==0)
				        	random_number = rand() % 1099;
				        	
				        else if(strcmp(Team_info[counter].name, "Colombia")==0)
				        	random_number = rand() % 1078;
				        	
				        else if(strcmp(Team_info[counter].name, "England")==0)
				        	random_number = rand() % 1047;
				        	
				        else if(strcmp(Team_info[counter].name, "Mexico")==0)
				        	random_number = rand() % 1032;
				        
				        else if(strcmp(Team_info[counter].name, "Croatia")==0)
				        	random_number = rand() % 1018;
				        	
				        else if(strcmp(Team_info[counter].name, "Sweden")==0)
				        	random_number = rand() % 998;
				        	
				        else if(strcmp(Team_info[counter].name, "Uruguay")==0)
				        	random_number = rand() % 924;
				        	
				        else if(strcmp(Team_info[counter].name, "Iceland")==0)
				        	random_number = rand() % 910;
				        	
				        else if(strcmp(Team_info[counter].name, "Senegal")==0)
				        	random_number = rand() % 884;
				        	
				        else if(strcmp(Team_info[counter].name, "Costa Rica")==0)
				        	random_number = rand() % 850;
				        	
				        else if(strcmp(Team_info[counter].name, "Tunisia")==0)
				        	random_number = rand() % 838;
				        	
				        else if(strcmp(Team_info[counter].name, "Egypt")==0)
				        	random_number = rand() % 805;
				        	
				        else if(strcmp(Team_info[counter].name, "Iran")==0)
				        	random_number = rand() % 798;
				        	
				        else if(strcmp(Team_info[counter].name, "Serbia")==0)
				        	random_number = rand() % 756;
				        	
				        else if(strcmp(Team_info[counter].name, "Australia")==0)
				        	random_number = rand() % 747;
				        	
				        else if(strcmp(Team_info[counter].name, "Morocco")==0)
				        	random_number = rand() % 738;
				        	
				        else if(strcmp(Team_info[counter].name, "Nigeria")==0)
				        	random_number = rand() % 640;
				        	
				        else if(strcmp(Team_info[counter].name, "Panama")==0)
				        	random_number = rand() % 621;
				        	
				        else if(strcmp(Team_info[counter].name, "Japan")==0)
				        	random_number = rand() % 600;
				        	
				        else if(strcmp(Team_info[counter].name, "Korea Republic")==0)
				        	random_number = rand() % 570;
				        	
				        else if(strcmp(Team_info[counter].name, "Saudi Arabia")==0)
				        	random_number = rand() % 543;
				        	
				        else if(strcmp(Team_info[counter].name, "Russia")==0)
				        	random_number = rand() % 534;
		        	
		        
		    
		        Team_info[counter].bazikon[i].skill = random_number ;
		        
			i++;
		}
		
		Team_info[counter].bazikon_len = i;
		
		fclose(fp);
		fp = NULL;
		
		strcpy(dir,"files\\Teams\\");
	}
	
	return 0 ;
}



void chidane_barnameye_baziha_dar_marhaleye_gorohi(){
	
	Jadvale_natayej.dore_avale_gorohi[0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	Jadvale_natayej.dore_avale_gorohi[0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	
	Jadvale_natayej.dore_avale_gorohi[1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	Jadvale_natayej.dore_avale_gorohi[1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	
	Jadvale_natayej.dore_avale_gorohi[2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	Jadvale_natayej.dore_avale_gorohi[2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	
	Jadvale_natayej.dore_avale_gorohi[3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	Jadvale_natayej.dore_avale_gorohi[3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	
	Jadvale_natayej.dore_avale_gorohi[4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	Jadvale_natayej.dore_avale_gorohi[4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	
	Jadvale_natayej.dore_avale_gorohi[5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	Jadvale_natayej.dore_avale_gorohi[5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	
	Jadvale_natayej.dore_avale_gorohi[6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	Jadvale_natayej.dore_avale_gorohi[6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	
	Jadvale_natayej.dore_avale_gorohi[7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	Jadvale_natayej.dore_avale_gorohi[7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	
	Jadvale_natayej.dore_avale_gorohi[8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	Jadvale_natayej.dore_avale_gorohi[8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	
	Jadvale_natayej.dore_avale_gorohi[9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	Jadvale_natayej.dore_avale_gorohi[9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	
	Jadvale_natayej.dore_avale_gorohi[10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	Jadvale_natayej.dore_avale_gorohi[10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	
	Jadvale_natayej.dore_avale_gorohi[11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	Jadvale_natayej.dore_avale_gorohi[11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	
	Jadvale_natayej.dore_avale_gorohi[12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	Jadvale_natayej.dore_avale_gorohi[12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	
	Jadvale_natayej.dore_avale_gorohi[13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	Jadvale_natayej.dore_avale_gorohi[13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	
	Jadvale_natayej.dore_avale_gorohi[14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	Jadvale_natayej.dore_avale_gorohi[14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	
	Jadvale_natayej.dore_avale_gorohi[15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	Jadvale_natayej.dore_avale_gorohi[15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_dovom_gorohi[0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	Jadvale_natayej.dore_dovom_gorohi[0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	
	Jadvale_natayej.dore_dovom_gorohi[1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	Jadvale_natayej.dore_dovom_gorohi[1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	
	Jadvale_natayej.dore_dovom_gorohi[2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	Jadvale_natayej.dore_dovom_gorohi[2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	
	Jadvale_natayej.dore_dovom_gorohi[3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	Jadvale_natayej.dore_dovom_gorohi[3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	
	Jadvale_natayej.dore_dovom_gorohi[4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	Jadvale_natayej.dore_dovom_gorohi[4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	
	Jadvale_natayej.dore_dovom_gorohi[5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	Jadvale_natayej.dore_dovom_gorohi[5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	
	Jadvale_natayej.dore_dovom_gorohi[6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	Jadvale_natayej.dore_dovom_gorohi[6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	
	Jadvale_natayej.dore_dovom_gorohi[7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	Jadvale_natayej.dore_dovom_gorohi[7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	
	Jadvale_natayej.dore_dovom_gorohi[8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	Jadvale_natayej.dore_dovom_gorohi[8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	
	Jadvale_natayej.dore_dovom_gorohi[9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	Jadvale_natayej.dore_dovom_gorohi[9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	
	Jadvale_natayej.dore_dovom_gorohi[10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	Jadvale_natayej.dore_dovom_gorohi[10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	
	Jadvale_natayej.dore_dovom_gorohi[11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	Jadvale_natayej.dore_dovom_gorohi[11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	
	Jadvale_natayej.dore_dovom_gorohi[12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	Jadvale_natayej.dore_dovom_gorohi[12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	
	Jadvale_natayej.dore_dovom_gorohi[13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	Jadvale_natayej.dore_dovom_gorohi[13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	
	Jadvale_natayej.dore_dovom_gorohi[14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	Jadvale_natayej.dore_dovom_gorohi[14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	
	Jadvale_natayej.dore_dovom_gorohi[15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	Jadvale_natayej.dore_dovom_gorohi[15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_sevom_gorohi[0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	Jadvale_natayej.dore_sevom_gorohi[0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	
	Jadvale_natayej.dore_sevom_gorohi[1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	Jadvale_natayej.dore_sevom_gorohi[1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	
	Jadvale_natayej.dore_sevom_gorohi[2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	Jadvale_natayej.dore_sevom_gorohi[2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	
	Jadvale_natayej.dore_sevom_gorohi[3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	Jadvale_natayej.dore_sevom_gorohi[3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	
	Jadvale_natayej.dore_sevom_gorohi[4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	Jadvale_natayej.dore_sevom_gorohi[4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	
	Jadvale_natayej.dore_sevom_gorohi[5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	Jadvale_natayej.dore_sevom_gorohi[5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	
	Jadvale_natayej.dore_sevom_gorohi[6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	Jadvale_natayej.dore_sevom_gorohi[6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	
	Jadvale_natayej.dore_sevom_gorohi[7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	Jadvale_natayej.dore_sevom_gorohi[7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	
	Jadvale_natayej.dore_sevom_gorohi[8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	Jadvale_natayej.dore_sevom_gorohi[8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	
	Jadvale_natayej.dore_sevom_gorohi[9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	Jadvale_natayej.dore_sevom_gorohi[9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	
	Jadvale_natayej.dore_sevom_gorohi[10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	Jadvale_natayej.dore_sevom_gorohi[10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	
	Jadvale_natayej.dore_sevom_gorohi[11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	Jadvale_natayej.dore_sevom_gorohi[11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	
	Jadvale_natayej.dore_sevom_gorohi[12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	Jadvale_natayej.dore_sevom_gorohi[12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	
	Jadvale_natayej.dore_sevom_gorohi[13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	Jadvale_natayej.dore_sevom_gorohi[13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	
	Jadvale_natayej.dore_sevom_gorohi[14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	Jadvale_natayej.dore_sevom_gorohi[14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	
	Jadvale_natayej.dore_sevom_gorohi[15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	Jadvale_natayej.dore_sevom_gorohi[15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	
	
	

}

int gereftane_id_team_by_goroh_and_index_goroh(char goroh,short int index_goroh){
	int i =0 ;
	for(i=0;i<TEDADE_TEAM_HA;i++){
		if (Team_info[i].group==goroh&&Team_info[i].group_index==index_goroh)
		  break;
	}
	return i ;
}


















void gozashtan_id_teamha_dar_goroh_ha(){
	int i =0;
	for(i=0;i<32;i++){
		Goroh_ha[Team_info[i].group-65][Team_info[i].group_index - 1].id_teams= i ;
	}
}


void sort_kardane_goroh_ha(){
	int i =0 , j=0 , k=0;
	struct goroh  komaki;
	for(i=0;i<8;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4-1;k++){
				
				if(Goroh_ha[i][k+1].emtiyaz>Goroh_ha[i][k].emtiyaz){
					komaki = Goroh_ha[i][k];
					Goroh_ha[i][k] = Goroh_ha[i][k+1];
					Goroh_ha[i][k+1]=komaki;	
				}
				
				else if (Goroh_ha[i][k+1].emtiyaz==Goroh_ha[i][k].emtiyaz && Goroh_ha[i][k+1].tafazole_gol>Goroh_ha[i][k].tafazole_gol){
					komaki = Goroh_ha[i][k];
					Goroh_ha[i][k] = Goroh_ha[i][k+1];
					Goroh_ha[i][k+1]=komaki;
				}
				else if (Goroh_ha[i][k+1].emtiyaz==Goroh_ha[i][k].emtiyaz && Goroh_ha[i][k+1].tafazole_gol==Goroh_ha[i][k].tafazole_gol&& Goroh_ha[i][k+1].tedad_gole_zade>Goroh_ha[i][k].tedad_gole_zade){
					komaki = Goroh_ha[i][k];
					Goroh_ha[i][k] = Goroh_ha[i][k+1];
					Goroh_ha[i][k+1]=komaki;
				}
			}
		}
		
	}
}


















void chidane_tarkibe_defualt_teamha(){ // be sorate pishfarz hameye team ha az system 4 3 3 estefade mikonand
	int i;
	for(i=0;i<TEDADE_TEAM_HA;i++){ 
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'G')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
		Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_asli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
	}
}

short int gereftane_index_bazikoni_ke_max_skill_poste_asli(short int id_team , char poste){ //bazikonani ke dar tarkib asli team nistand
	 int i,max_skill=0 , index_max_skill;
	 for(i=0;i<Team_info[id_team].bazikon_len;i++){
	 	if(Team_info[id_team].bazikon[i].skill>max_skill&&Team_info[id_team].bazikon[i].poste_asli == poste && Team_info[id_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist == 0){
	 		max_skill = Team_info[id_team].bazikon[i].skill ;
	 		index_max_skill = i ;
		 }
	 	    
	 }
	 return index_max_skill;
}







































/*external functions---------------------------------------------------------------------------------------*/

char** str_split(char* a_str, const char a_delim){
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


/*external functions------------------------------------------------------------------------------------[end]*/








