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
void chidane_tarkibe_team(short int id_team , short int tedad_modafe , short int tedad_hafbak , short int mohajem );
short int gereftane_index_bazikoni_ke_max_skill_poste_feli(short int id_team , char poste);
void play_bazi_gorohi();
int miyangine_ghodrate_bazikonan(short int index_team);
void taghyir_form_bazikonan(short int index_team, short int meghdare_taghyir , short int aya_bazikonani_ka_dar_tarkibe_asli_hastand);
void taghyir_fitness_bazikonan(short int index_team, short int meghdare_taghyir , short int aya_bazikonani_ka_dar_tarkibe_asli_hastand);
void chidane_barnameye_baziha_dar_marhaleye_hazfi();
int gereftane_id_teame_barande_dar_marhale_hazfi(short int kodam_marhale ,short int baziye_chandome_marhale);
int gereftane_id_teame_bazande_dar_marhale_hazfi(short int kodam_marhale ,short int baziye_chandome_marhale);
void taghyir_poste_bazikon(short int id_team , short int id_bazikon , char post);
void taghyir_jaye_bazikon(short int id_team , short int id_bazikon_aval , short int id_bazikon_dovom);
int teame_user_bazi_chandome_list_gorohi_ast(short int kodam_marhale);
void neshan_dadane_vazeeyat();
/*define fuctions------------------------------------------------------------------------------------[end]*/

short int id_team_user = 0 ;


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
	short int golhaye_teame_aval_dar_che_daghayegi_bodand[30];
	
	short int id_teame_dovom;
	char tedade_gole_zade__teame_dovom;
	short int golhaye_teame_dovom_dar_che_daghayegi_bodand[30];
};

struct natije_bazi_hazfi{
	short int id_teame_aval;
	char tedade_gole_zade__teame_aval_dar_vaghte_ghanoni;
	char tedade_gole_zade__teame_aval_dar_vaghte_ezafe;
	char tedade_gole_zade__teame_aval_dar_vaghte_penalti;
	short int golhaye_teame_aval_dar_che_daghayegi_bodand[30];
	
	short int id_teame_dovom;
	char tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni;
	char tedade_gole_zade__teame_dovom_dar_vaghte_ezafe;
	char tedade_gole_zade__teame_dovom_dar_vaghte_penalti;
	short int golhaye_teame_dovom_dar_che_daghayegi_bodand[30];
};


struct jadvale_natayej{
	short int ta_marhaleye_chand_pish_rafte;
	
	short int tedade_bazihaye_dore_hazfi[4];
	
	struct natije_bazi_gorohi dore_gorohi[3][16]; 
	
	
	struct natije_bazi_hazfi dore_hazfi[4][8];  
	
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
	
    int i =0 , j=0 , counter =0  , adad , array[10] ,ta_marhaleye_chand_pish_rafte ;
    char buffer[100] , string[50] , charr;
    char **string_split;
    
    read_teams_and_put_to_struct();
    read_bazikonane_team_and_put_to_struct();
    chidane_barnameye_baziha_dar_marhaleye_gorohi();
    gozashtan_id_teamha_dar_goroh_ha();
    chidane_tarkibe_defualt_teamha();
    
    
    
    
    
    for(i=1;i<=TEDADE_TEAM_HA;i++){
    	printf("\n\n%d- %s        miyangine ghodrate bazikonan : %d",i,Team_info[i-1].name,miyangine_ghodrate_bazikonan(i-1));
	}
	printf("\n\n\n\nTeame khod ra entekhab konid (id team ra vared konid) :  ");
	fgets(buffer,100, stdin);
	sscanf(buffer,"%d",&id_team_user);
	id_team_user--;
	
	
	
	
	  
	
	    
	while(1){
	
	
	
						printf("\n\n\nAmade baraye dastor dadn : ");
						fgets(buffer,100, stdin);
						sscanf(buffer,"%s %d",string, &adad); 
						
						
						
						
						
						
						if(strcmp(string,"state")==0){
							neshan_dadane_vazeeyat();
						}
						
						
						
						if(strcmp(string,"table")==0){
							if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte>=1 && Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6){
								
								sort_kardane_goroh_ha();
								
								for(i=0;i<8;i++){
									printf("\n\n\n\n\ngoroh %c: ",i+65);
							    	for(j=0;j<4;j++)
							    	printf("\n\n%s =>emtiyaz=%d  || tafazol=%d  || gole zade=%d || gole khorde=%d || bazi=%d || bord=%d || bakht=%d || mosavi=%d" , Team_info[Goroh_ha[i][j].id_teams].name , Goroh_ha[i][j].emtiyaz , Goroh_ha[i][j].tafazole_gol  ,  Goroh_ha[i][j].tedad_gole_zade , Goroh_ha[i][j].tedad_gole_khorde, Goroh_ha[i][j].tedad_bazi,Goroh_ha[i][j].tedad_bord,Goroh_ha[i][j].tedad_bakht,Goroh_ha[i][j].tedad_mosavi);
								}
									
					     	}
					     	
					     	
					     	
					     	
					     	if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6 && Jadvale_natayej.ta_marhaleye_chand_pish_rafte>=3){
								chidane_barnameye_baziha_dar_marhaleye_hazfi();
								ta_marhaleye_chand_pish_rafte = Jadvale_natayej.ta_marhaleye_chand_pish_rafte - 3 ;
								
								for(i=0;i<ta_marhaleye_chand_pish_rafte;i++){
						       	switch(i) {
									      case 0 :
									         printf("\n\n\n\nnatayeje yek-hashtome nahaei : \n");
									         break;
									      case 1 :
									         printf("\n\n\n\nnatayeje yek-chaharome nahaei : \n");
									         break;
									      case 2 :
									         printf("\n\n\n\nnatayeje nime nahaei : \n");
									         break;
									      case 3 :
									         printf("\n\n\n\nnatayeje nahaei : \n");
									         break;
									   }
						       	    for(j=0;j<Jadvale_natayej.tedade_bazihaye_dore_hazfi[i];j++){
									   
								       	  if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
								          printf("\n%s ghanoni=> %d  --------------  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni , Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
								          
								          else if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
									   	  printf("\n%s ghanoni=> %d     ezafe=> %d  -------------- %d <=ezafe  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
									      
									      else
									   	  printf("\n%s ghanoni=> %d     ezafe=> %d     penalti=> %d  -------------- %d <=penalti      %d <=ezafe     %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_penalti,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_penalti ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
								   }
							   }
								
								
							}
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
					     	
						}
						
						
						
						
						
						
						
						
						if(strcmp(string,"proceed")==0 && Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6){
							if(adad>=1 && adad<=7){
								
								for(i=0;i<adad;i++){
									printf("\n\n\n\nnatije baziha :\n");
									if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=2){
										play_bazi_gorohi();
										for(j=0;j<18;j++){
											printf("\n\n\n%s => %d  --------------  %d <= %s",Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].id_teame_aval].name,Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_aval,Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_dovom, Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].id_teame_dovom].name);
										    
											for(counter=0;counter<Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_aval||counter<Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_dovom;counter++){
												if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
													printf("\n%d => min                   min <= %d",Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter],Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
										    	
										    	if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]==0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
													printf("\n                            min <= %d",Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
													
												if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]==0)
													printf("\n%d => min                            ",Jadvale_natayej.dore_gorohi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]);
											}
										}
									}
									else if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6){
										   ta_marhaleye_chand_pish_rafte= Jadvale_natayej.ta_marhaleye_chand_pish_rafte -3 ;
										   play_bazi_hazfi();
										   for(j=0;j<Jadvale_natayej.tedade_bazihaye_dore_hazfi[ta_marhaleye_chand_pish_rafte];j++){
											   
										       	  if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni!=Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
										          printf("\n\n\n%s ghanoni=> %d  --------------  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni , Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
										          
										          else if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe!=Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
											   	  printf("\n\n\n%s ghanoni=> %d     ezafe=> %d  -------------- %d <=ezafe  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe ,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
											      
											      else
											   	  printf("\n\n\n%s ghanoni=> %d     ezafe=> %d     penalti=> %d  -------------- %d <=penalti      %d <=ezafe     %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_penalti,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_penalti ,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
										   
										   		
										   		
										   		
										   		for(counter=0;counter<Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe||counter<Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe;counter++){
													if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
														printf("\n%d => min                   min <= %d",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter],Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
											    	
											    	if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]==0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
														printf("\n                            min <= %d",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
														
													if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]==0)
														printf("\n%d => min                            ",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]);
												}
										   }
									}
								}
							}
							else if(adad==0){
								    if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=2){
										play_bazi_gorohi();
										for(j=0;j<18;j++){
											printf("\n\n\n%s => %d  --------------  %d <= %s",Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].id_teame_aval].name,Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_aval,Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_dovom, Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].id_teame_dovom].name);
										    
											for(counter=0;counter<Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_aval||counter<Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].tedade_gole_zade__teame_dovom;counter++){
												if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
													printf("\n%d => min                   min <= %d",Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter],Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
										    	
										    	if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]==0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
													printf("\n                            min <= %d",Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
													
												if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]==0)
													printf("\n%d => min                            ",Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte-1][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]);
											}
										}
									}
									else if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6){
										ta_marhaleye_chand_pish_rafte= Jadvale_natayej.ta_marhaleye_chand_pish_rafte -3 ;
										   play_bazi_hazfi();
										   for(j=0;j<Jadvale_natayej.tedade_bazihaye_dore_hazfi[ta_marhaleye_chand_pish_rafte];j++){
											   
										       	  if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni!=Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
										          printf("\n\n\n%s ghanoni=> %d  --------------  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni , Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
										          
										          else if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe!=Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
											   	  printf("\n\n\n%s ghanoni=> %d     ezafe=> %d  -------------- %d <=ezafe  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe ,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
											      
											      else
											   	  printf("\n\n\n%s ghanoni=> %d     ezafe=> %d     penalti=> %d  -------------- %d <=penalti      %d <=ezafe     %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_penalti,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_penalti ,Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].id_teame_dovom].name);	    	
										   
										   		
										   		
										   		
										   		for(counter=0;counter<Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe||counter<Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe;counter++){
													if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
														printf("\n%d => min                   min <= %d",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter],Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
											    	
											    	if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]==0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]!=0)
														printf("\n                            min <= %d",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]);
														
													if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]!=0 && Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_dovom_dar_che_daghayegi_bodand[counter]==0)
														printf("\n%d => min                            ",Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][j].golhaye_teame_aval_dar_che_daghayegi_bodand[counter]);
												}
										   }
									}
							}
							
						}
						else
						  printf("\n\n\nvorodi eshtebah ast !");
						if(strcmp(string,"lineup")==0){
							printf("\n\n\n\nListe bazikonan :\n");
							for(i=0;i<Team_info[id_team_user].bazikon_len;i++){
					    	printf("\n\n%d- %s => poste feli=%c || poste asli = %c || skill = %d || to tarkibe asli hast? %d || form = %d || fitness = %d",i+1,Team_info[id_team_user].bazikon[i].name,Team_info[id_team_user].bazikon[i].poste_feli,Team_info[id_team_user].bazikon[i].poste_asli,Team_info[id_team_user].bazikon[i].skill,Team_info[id_team_user].bazikon[i].aya_bazikon_dar_tarkibe_aslist,Team_info[id_team_user].bazikon[i].form,Team_info[id_team_user].bazikon[i].fitness);
						    } 
						    printf("\n\n\nAya mikhahid tarkibe team ra taghyir dahid ? 1-bale   2-kheir : ");
						    fgets(buffer,100, stdin);
						    sscanf(buffer,"%d",&adad);
							if(adad==1){
							    printf("\n\n\n1- taeene tarkibe team be sorate se adad \n2- ja be ja kardane bazikonan\n3- taghyire poste bazikonan\n\n");
								fgets(buffer,100, stdin);
						        sscanf(buffer,"%d",&adad);
								if(adad==1){
									printf("\n\n\ntarkib team ra be sorat 3 adad vared konid :");
									fgets(buffer,100, stdin);
						            sscanf(buffer,"%d%d%d",&array[0],&array[1],&array[2]);
						            if(array[0]>=0&&array[0]<=10&&array[1]>=0&&array[1]<=10&&array[2]>=0&&array[2]<=10&&(array[0]+array[1]+array[2])==10){
						            	chidane_tarkibe_team(id_team_user ,array[0],array[1],array[2]);
						            	printf("\n\n\ntarkib team ba movaffaghiyat anjam shod.");
						            	for(i=0;i<Team_info[id_team_user].bazikon_len;i++){
								    	printf("\n\n%d- %s => poste feli=%c || poste asli = %c || skill = %d || to tarkibe asli hast? %d || form = %d || fitness = %d",i+1,Team_info[id_team_user].bazikon[i].name,Team_info[id_team_user].bazikon[i].poste_feli,Team_info[id_team_user].bazikon[i].poste_asli,Team_info[id_team_user].bazikon[i].skill,Team_info[id_team_user].bazikon[i].aya_bazikon_dar_tarkibe_aslist,Team_info[id_team_user].bazikon[i].form,Team_info[id_team_user].bazikon[i].fitness);
									    } 
									}
									else
						                printf("\n\n\nvorodi eshtebah ast !");
						            
								}
								else if(adad==2){
									printf("\n\n\id do bazikoni ke mikhahid jabe ja konid ra vared konid :");
									fgets(buffer,100, stdin);
						            sscanf(buffer,"%d%d",&array[0],&array[1]);
						            array[0]--;
						            array[1]--;
						            if(array[0]>=0 && array[0]<=Team_info[id_team_user].bazikon_len-1&&array[1]>=0 && array[1]<=Team_info[id_team_user].bazikon_len-1){
										taghyir_jaye_bazikon(id_team_user,array[0],array[1]);
										printf("\n\n\nja be jayie ba movaffaghiyat anjam shod.");
						            	for(i=0;i<Team_info[id_team_user].bazikon_len;i++){
								    	printf("\n\n%d- %s => poste feli=%c || poste asli = %c || skill = %d || to tarkibe asli hast? %d || form = %d || fitness = %d",i+1,Team_info[id_team_user].bazikon[i].name,Team_info[id_team_user].bazikon[i].poste_feli,Team_info[id_team_user].bazikon[i].poste_asli,Team_info[id_team_user].bazikon[i].skill,Team_info[id_team_user].bazikon[i].aya_bazikon_dar_tarkibe_aslist,Team_info[id_team_user].bazikon[i].form,Team_info[id_team_user].bazikon[i].fitness);
									    }
									}
										
									else
										printf("\n\n\nvorodi eshtebah ast !");	
								}
								else if(adad==3){
									printf("\n\n\id va poste  bazikon ra vared konid :");
									fgets(buffer,100, stdin);
						            sscanf(buffer,"%d %c",&array[0],&charr);
						            array[0]--;
						            if(array[0]>=0 && array[0]<=Team_info[id_team_user].bazikon_len-1&&(charr=='A'||charr=='M'||charr=='D'||charr=='G')){
										taghyir_poste_bazikon(id_team_user,array[0],charr);
										printf("\n\n\ntaghyir poste bazikon ba movaffaghiyat anjam shod.");
						            	for(i=0;i<Team_info[id_team_user].bazikon_len;i++){
								    	printf("\n\n%d- %s => poste feli=%c || poste asli = %c || skill = %d || to tarkibe asli hast? %d || form = %d || fitness = %d",i+1,Team_info[id_team_user].bazikon[i].name,Team_info[id_team_user].bazikon[i].poste_feli,Team_info[id_team_user].bazikon[i].poste_asli,Team_info[id_team_user].bazikon[i].skill,Team_info[id_team_user].bazikon[i].aya_bazikon_dar_tarkibe_aslist,Team_info[id_team_user].bazikon[i].form,Team_info[id_team_user].bazikon[i].fitness);
									    }
									}	
									else
										printf("\n\n\nvorodi eshtebah ast !");
						            	
								}	
							} 
					    } 
    
	
	
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
			    Team_info[counter].bazikon[i].form = 70 ;
			    
			    
			    
			    
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
	
	Jadvale_natayej.tedade_bazihaye_dore_hazfi[0]= 8;
	Jadvale_natayej.tedade_bazihaye_dore_hazfi[1]= 4;
	Jadvale_natayej.tedade_bazihaye_dore_hazfi[2]= 2;
	Jadvale_natayej.tedade_bazihaye_dore_hazfi[3]= 2;
	
	Jadvale_natayej.dore_gorohi[0][0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	Jadvale_natayej.dore_gorohi[0][0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	
	Jadvale_natayej.dore_gorohi[0][1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	Jadvale_natayej.dore_gorohi[0][1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	
	Jadvale_natayej.dore_gorohi[0][2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	Jadvale_natayej.dore_gorohi[0][2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	
	Jadvale_natayej.dore_gorohi[0][3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	Jadvale_natayej.dore_gorohi[0][3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	
	Jadvale_natayej.dore_gorohi[0][4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	Jadvale_natayej.dore_gorohi[0][4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	
	Jadvale_natayej.dore_gorohi[0][5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	Jadvale_natayej.dore_gorohi[0][5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	
	Jadvale_natayej.dore_gorohi[0][6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	Jadvale_natayej.dore_gorohi[0][6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	
	Jadvale_natayej.dore_gorohi[0][7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	Jadvale_natayej.dore_gorohi[0][7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	
	Jadvale_natayej.dore_gorohi[0][8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	Jadvale_natayej.dore_gorohi[0][8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	
	Jadvale_natayej.dore_gorohi[0][9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	Jadvale_natayej.dore_gorohi[0][9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	
	Jadvale_natayej.dore_gorohi[0][10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	Jadvale_natayej.dore_gorohi[0][10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	
	Jadvale_natayej.dore_gorohi[0][11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	Jadvale_natayej.dore_gorohi[0][11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	
	Jadvale_natayej.dore_gorohi[0][12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	Jadvale_natayej.dore_gorohi[0][12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	
	Jadvale_natayej.dore_gorohi[0][13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	Jadvale_natayej.dore_gorohi[0][13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	
	Jadvale_natayej.dore_gorohi[0][14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	Jadvale_natayej.dore_gorohi[0][14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	
	Jadvale_natayej.dore_gorohi[0][15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	Jadvale_natayej.dore_gorohi[0][15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_gorohi[1][0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	Jadvale_natayej.dore_gorohi[1][0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	
	Jadvale_natayej.dore_gorohi[1][1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	Jadvale_natayej.dore_gorohi[1][1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	
	Jadvale_natayej.dore_gorohi[1][2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	Jadvale_natayej.dore_gorohi[1][2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	
	Jadvale_natayej.dore_gorohi[1][3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	Jadvale_natayej.dore_gorohi[1][3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	
	Jadvale_natayej.dore_gorohi[1][4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	Jadvale_natayej.dore_gorohi[1][4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	
	Jadvale_natayej.dore_gorohi[1][5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	Jadvale_natayej.dore_gorohi[1][5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	
	Jadvale_natayej.dore_gorohi[1][6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	Jadvale_natayej.dore_gorohi[1][6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	
	Jadvale_natayej.dore_gorohi[1][7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	Jadvale_natayej.dore_gorohi[1][7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	
	Jadvale_natayej.dore_gorohi[1][8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	Jadvale_natayej.dore_gorohi[1][8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	
	Jadvale_natayej.dore_gorohi[1][9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	Jadvale_natayej.dore_gorohi[1][9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	
	Jadvale_natayej.dore_gorohi[1][10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	Jadvale_natayej.dore_gorohi[1][10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	
	Jadvale_natayej.dore_gorohi[1][11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	Jadvale_natayej.dore_gorohi[1][11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	
	Jadvale_natayej.dore_gorohi[1][12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	Jadvale_natayej.dore_gorohi[1][12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	
	Jadvale_natayej.dore_gorohi[1][13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	Jadvale_natayej.dore_gorohi[1][13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	
	Jadvale_natayej.dore_gorohi[1][14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	Jadvale_natayej.dore_gorohi[1][14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	
	Jadvale_natayej.dore_gorohi[1][15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	Jadvale_natayej.dore_gorohi[1][15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_gorohi[2][0].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',4);
	Jadvale_natayej.dore_gorohi[2][0].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',1);
	
	Jadvale_natayej.dore_gorohi[2][1].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('A',2);
	Jadvale_natayej.dore_gorohi[2][1].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('A',3);
	
	Jadvale_natayej.dore_gorohi[2][2].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',4);
	Jadvale_natayej.dore_gorohi[2][2].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',1);
	
	Jadvale_natayej.dore_gorohi[2][3].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('B',2);
	Jadvale_natayej.dore_gorohi[2][3].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('B',3);
	
	Jadvale_natayej.dore_gorohi[2][4].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',4);
	Jadvale_natayej.dore_gorohi[2][4].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',1);
	
	Jadvale_natayej.dore_gorohi[2][5].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('C',2);
	Jadvale_natayej.dore_gorohi[2][5].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('C',3);
	
	Jadvale_natayej.dore_gorohi[2][6].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',4);
	Jadvale_natayej.dore_gorohi[2][6].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',1);
	
	Jadvale_natayej.dore_gorohi[2][7].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('D',2);
	Jadvale_natayej.dore_gorohi[2][7].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('D',3);
	
	Jadvale_natayej.dore_gorohi[2][8].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',2);
	Jadvale_natayej.dore_gorohi[2][8].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',3);
	
	Jadvale_natayej.dore_gorohi[2][9].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('F',4);
	Jadvale_natayej.dore_gorohi[2][9].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('F',1);
	
	Jadvale_natayej.dore_gorohi[2][10].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',4);
	Jadvale_natayej.dore_gorohi[2][10].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',1);
	
	Jadvale_natayej.dore_gorohi[2][11].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('E',2);
	Jadvale_natayej.dore_gorohi[2][11].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('E',3);
	
	Jadvale_natayej.dore_gorohi[2][12].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',4);
	Jadvale_natayej.dore_gorohi[2][12].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',1);
	
	Jadvale_natayej.dore_gorohi[2][13].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('H',2);
	Jadvale_natayej.dore_gorohi[2][13].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('H',3);
	
	Jadvale_natayej.dore_gorohi[2][14].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',2);
	Jadvale_natayej.dore_gorohi[2][14].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',3);
	
	Jadvale_natayej.dore_gorohi[2][15].id_teame_aval = gereftane_id_team_by_goroh_and_index_goroh('G',4);
	Jadvale_natayej.dore_gorohi[2][15].id_teame_dovom = gereftane_id_team_by_goroh_and_index_goroh('G',1);
	
	
	

}

int gereftane_id_team_by_goroh_and_index_goroh(char goroh,short int index_goroh){
	int i =0 ;
	for(i=0;i<TEDADE_TEAM_HA;i++){
		if (Team_info[i].group==goroh&&Team_info[i].group_index==index_goroh)
		  break;
	}
	return i ;
}



void chidane_barnameye_baziha_dar_marhaleye_hazfi(){
	sort_kardane_goroh_ha();
	
	Jadvale_natayej.dore_hazfi[0][0].id_teame_aval = Goroh_ha['A'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][0].id_teame_dovom = Goroh_ha['B'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][1].id_teame_aval = Goroh_ha['C'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][1].id_teame_dovom = Goroh_ha['D'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][2].id_teame_aval = Goroh_ha['B'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][2].id_teame_dovom = Goroh_ha['A'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][3].id_teame_aval = Goroh_ha['D'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][3].id_teame_dovom = Goroh_ha['C'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][4].id_teame_aval = Goroh_ha['E'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][4].id_teame_dovom = Goroh_ha['F'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][5].id_teame_aval = Goroh_ha['G'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][5].id_teame_dovom = Goroh_ha['H'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][6].id_teame_aval = Goroh_ha['F'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][6].id_teame_dovom = Goroh_ha['E'-65][(2)-1].id_teams;
	
	Jadvale_natayej.dore_hazfi[0][7].id_teame_aval = Goroh_ha['H'-65][(1)-1].id_teams;
	Jadvale_natayej.dore_hazfi[0][7].id_teame_dovom = Goroh_ha['G'-65][(2)-1].id_teams;
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_hazfi[1][0].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(0 ,0);
	Jadvale_natayej.dore_hazfi[1][0].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(0,1);
	
	Jadvale_natayej.dore_hazfi[1][1].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(0 ,4);
	Jadvale_natayej.dore_hazfi[1][1].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(0,5);
	
	Jadvale_natayej.dore_hazfi[1][2].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(0 ,2);
	Jadvale_natayej.dore_hazfi[1][2].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(0,3);
	
	Jadvale_natayej.dore_hazfi[1][3].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(0 ,6);
	Jadvale_natayej.dore_hazfi[1][3].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(0,7);
	
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_hazfi[2][0].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(1 ,0);
	Jadvale_natayej.dore_hazfi[2][0].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(1,1);
	
	Jadvale_natayej.dore_hazfi[2][1].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(1 ,2);
	Jadvale_natayej.dore_hazfi[2][1].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(1,3);
	
	
	
	
	
	
	
	
	
	Jadvale_natayej.dore_hazfi[3][0].id_teame_aval = gereftane_id_teame_bazande_dar_marhale_hazfi(2 ,0);
	Jadvale_natayej.dore_hazfi[3][0].id_teame_dovom = gereftane_id_teame_bazande_dar_marhale_hazfi(2,1);
	
	Jadvale_natayej.dore_hazfi[3][1].id_teame_aval = gereftane_id_teame_barande_dar_marhale_hazfi(2 ,0);
	Jadvale_natayej.dore_hazfi[3][1].id_teame_dovom = gereftane_id_teame_barande_dar_marhale_hazfi(2,1);

}




int gereftane_id_teame_barande_dar_marhale_hazfi(short int kodam_marhale ,short int baziye_chandome_marhale){
	if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
		return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
	else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
	    return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
	else{
		        if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ezafe>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
					return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
				else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ezafe<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
				    return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
				else{
					if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_penalti>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_penalti)
						return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
				    else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_penalti<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_penalti)
				    	return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
				}	
	}
	return  0;
}

int gereftane_id_teame_bazande_dar_marhale_hazfi(short int kodam_marhale ,short int baziye_chandome_marhale){
	if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
		return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
	else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
	    return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
	else{
		        if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ezafe<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
					return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
				else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_ezafe>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
				    return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
				else{
					if(Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_penalti<Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_penalti)
						return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_aval;
				    else if (Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_aval_dar_vaghte_penalti>Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].tedade_gole_zade__teame_dovom_dar_vaghte_penalti)
				    	return Jadvale_natayej.dore_hazfi[kodam_marhale][baziye_chandome_marhale].id_teame_dovom;
				}	
	}
	return  0;
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
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'G')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
		Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        Team_info[i].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(i,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
	}
}

short int gereftane_index_bazikoni_ke_max_skill_poste_feli(short int id_team , char poste){ //bazikonani ke dar tarkib asli team nistand
	 int i,max_skill=0 , index_max_skill;
	 for(i=0;i<Team_info[id_team].bazikon_len;i++){
	 	if(Team_info[id_team].bazikon[i].skill>max_skill&&Team_info[id_team].bazikon[i].poste_feli == poste && Team_info[id_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist == 0){
	 		max_skill = Team_info[id_team].bazikon[i].skill ;
	 		index_max_skill = i ;
		 }
	 	    
	 }
	 return index_max_skill;
}



void chidane_tarkibe_team(short int id_team , short int tedad_modafe , short int tedad_hafbak , short int mohajem ){
    int i;
    
    for(i=0;i<Team_info[id_team].bazikon_len;i++){
	 	Team_info[id_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist = 0 ;    // clear tarkib
	}
	 
	 
	    Team_info[id_team].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(id_team,'G')].aya_bazikon_dar_tarkibe_aslist = 1 ;
	
	for(i=0;i<tedad_modafe;i++)    
        Team_info[id_team].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(id_team,'D')].aya_bazikon_dar_tarkibe_aslist = 1 ;
           
    for(i=0;i<tedad_hafbak;i++)     
        Team_info[id_team].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(id_team,'M')].aya_bazikon_dar_tarkibe_aslist = 1 ;
        
	for(i=0;i<mohajem;i++)     
        Team_info[id_team].bazikon[gereftane_index_bazikoni_ke_max_skill_poste_feli(id_team,'A')].aya_bazikon_dar_tarkibe_aslist = 1 ;	
        
        
        
	
}




void taghyir_poste_bazikon(short int id_team , short int id_bazikon , char post){
	
	if(Team_info[id_team].bazikon[id_bazikon].poste_asli == post && Team_info[id_team].bazikon[id_bazikon].poste_feli != Team_info[id_team].bazikon[id_bazikon].poste_asli )
		Team_info[id_team].bazikon[id_bazikon].skill *= 2; 
	if (Team_info[id_team].bazikon[id_bazikon].poste_asli != post  && Team_info[id_team].bazikon[id_bazikon].poste_feli == Team_info[id_team].bazikon[id_bazikon].poste_asli)
		Team_info[id_team].bazikon[id_bazikon].skill /= 2; 
	
	Team_info[id_team].bazikon[id_bazikon].poste_feli = post; 
	
}

void taghyir_jaye_bazikon(short int id_team , short int id_bazikon_aval , short int id_bazikon_dovom){
    int komaki;
    komaki = Team_info[id_team].bazikon[id_bazikon_aval].poste_feli;
    
    taghyir_poste_bazikon(id_team ,id_bazikon_aval,Team_info[id_team].bazikon[id_bazikon_dovom].poste_feli);
    taghyir_poste_bazikon(id_team ,id_bazikon_dovom,komaki);
    
    komaki = Team_info[id_team].bazikon[id_bazikon_aval].aya_bazikon_dar_tarkibe_aslist;
    Team_info[id_team].bazikon[id_bazikon_aval].aya_bazikon_dar_tarkibe_aslist = Team_info[id_team].bazikon[id_bazikon_dovom].aya_bazikon_dar_tarkibe_aslist;
    Team_info[id_team].bazikon[id_bazikon_dovom].aya_bazikon_dar_tarkibe_aslist = komaki ;
}












void play_bazi_gorohi(){
	int daghighe_bazi , counter , m=50 ; //m ye adadi beine 0 ta 100 ke harche be 100 nazdik bashe ehtemale inke team dovom bebare bishtare
	srand(time(NULL));   // should only be called once
   
    if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=2){
    	
    	      for(counter=0;counter<16;counter++){
		
				        for(daghighe_bazi=1;daghighe_bazi<=90;daghighe_bazi++){
							m= 50 ;
							m += ((miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval)-50)/2) + ((50-miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom))/2);
							
						
									if(daghighe_bazi<75 && (rand()%101)<=1){
									        if((rand()%101)<=m){
									        	Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_khorde++;
											}
											else{
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_khorde++;
											}
												
									}
									else if(daghighe_bazi>=75 && daghighe_bazi<80 && (rand()%101)<=2){
									    	if((rand()%101)<=m){
									        	Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_khorde++;
											}
											else{
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_khorde++;
											}
									}
									else if(daghighe_bazi>=80 &&daghighe_bazi<85 && (rand()%101)<=4){
									    	if((rand()%101)<=m){
									        	Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_khorde++;
											}
											else{
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_khorde++;
											}
									}
									else if(daghighe_bazi>=85 &&daghighe_bazi<=90 && (rand()%101)<=6){
									    	if((rand()%101)<=m){
									        	Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_khorde++;
											}
											else{
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom++;
												Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tafazole_gol++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tafazole_gol--;
												
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_gole_zade++;
												Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_gole_khorde++;
											}
									}
						
					      }
					      
					      
					      
					 taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_aval, 1, 1);
					 taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_dovom, 1 , 1); 
					 taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_aval, -1, 0);
					 taghyir_form_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_dovom, -1 , 0);
					 
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_aval, 1, 0);
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_dovom, 1 , 0); 
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_aval, -1, 1);
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_gorohi[0][counter].id_teame_dovom,-1 , 1);
					 
					 
					 if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval>Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom){
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].emtiyaz+=3;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_bord++;
					 	
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_bakht++;
					 }
					 else if(Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval<Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom){
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].emtiyaz+=3;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_bord++;
					 	
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_bakht++;
					 }
					 else{
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].emtiyaz++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_aval].group_index].tedad_mosavi++;
					 	
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].emtiyaz++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_bazi++;
					 	Goroh_ha[Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group-65][Team_info[Jadvale_natayej.dore_gorohi[Jadvale_natayej.ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom].group_index].tedad_mosavi++;
					 }
					 
					 
					  
					      
			}   
			
			Jadvale_natayej.ta_marhaleye_chand_pish_rafte++;       
	}	
	
	
	
	
}




int miyangine_ghodrate_bazikonan(short int index_team){
	int i , sum_skill=0 , sum_form=0 , sum_fitness=0 , skill_average =0 , skill_average_bar_hasbe_darsad =0 , form_average=0 , fitness_average=0   ;
	
	for(i = 0 ; i<Team_info[index_team].bazikon_len;i++){
		if(Team_info[index_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist==1){
					sum_skill+=Team_info[index_team].bazikon[i].skill;
		            sum_form+=Team_info[index_team].bazikon[i].form;
		            sum_fitness+=Team_info[index_team].bazikon[i].fitness;
		}
	}
	skill_average = sum_skill / 11;
	form_average = sum_form / 11;
	fitness_average = sum_fitness / 11;
	
	skill_average_bar_hasbe_darsad = (skill_average*100)/1602;
	
	return ((skill_average_bar_hasbe_darsad*6)+(form_average*2)+(fitness_average))/9 ;
	
}

void taghyir_form_bazikonan(short int index_team, short int meghdare_taghyir , short int aya_bazikonani_ka_dar_tarkibe_asli_hastand){
	int i;
	for(i=0;i<Team_info[index_team].bazikon_len;i++){
		if(Team_info[index_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist==aya_bazikonani_ka_dar_tarkibe_asli_hastand){
			if(Team_info[index_team].bazikon[i].form+meghdare_taghyir<=100 && Team_info[index_team].bazikon[i].form+meghdare_taghyir>=0)
			   Team_info[index_team].bazikon[i].form += meghdare_taghyir;
			else if(Team_info[index_team].bazikon[i].form+meghdare_taghyir>100)
	        	Team_info[index_team].bazikon[i].form = 100;
	        else if(Team_info[index_team].bazikon[i].form+meghdare_taghyir<0)
	        	Team_info[index_team].bazikon[i].form = 0;
		}
		
	}	
}

void taghyir_fitness_bazikonan(short int index_team, short int meghdare_taghyir , short int aya_bazikonani_ka_dar_tarkibe_asli_hastand){
	int i;
	for(i=0;i<Team_info[index_team].bazikon_len;i++){
		if(Team_info[index_team].bazikon[i].aya_bazikon_dar_tarkibe_aslist==aya_bazikonani_ka_dar_tarkibe_asli_hastand){
			if(Team_info[index_team].bazikon[i].fitness+meghdare_taghyir<=100 && Team_info[index_team].bazikon[i].fitness+meghdare_taghyir>=0)
			    Team_info[index_team].bazikon[i].fitness += meghdare_taghyir;
	        else if(Team_info[index_team].bazikon[i].fitness+meghdare_taghyir>100)
	        	Team_info[index_team].bazikon[i].fitness = 100;
	        else if(Team_info[index_team].bazikon[i].fitness+meghdare_taghyir<0)
	        	Team_info[index_team].bazikon[i].fitness = 0;
		}   
		
	}	
}





























void play_bazi_hazfi(){
	int daghighe_bazi , counter , m=50 , i=0 ; //m ye adadi beine 0 ta 100 ke harche be 100 nazdik bashe ehtemale inke team dovom bebare bishtare
	srand(time(NULL));   // should only be called once
    chidane_barnameye_baziha_dar_marhaleye_hazfi();
    if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6&&Jadvale_natayej.ta_marhaleye_chand_pish_rafte>=3){
    	
    	      int ta_marhaleye_chand_pish_rafte = Jadvale_natayej.ta_marhaleye_chand_pish_rafte-3 ;
    	      for(counter=0;counter<Jadvale_natayej.tedade_bazihaye_dore_hazfi[ta_marhaleye_chand_pish_rafte];counter++){
		
				         for(daghighe_bazi=1;daghighe_bazi<=90;daghighe_bazi++){
							  m= 50 ;
							  m += ((miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval)-50)/2) + ((50-miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom))/2);
							
						
									if((rand()%101)<=1){
									        if((rand()%101)<=m){
									        	Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni++;
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);	
											}
											else{
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni++;
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);	
											}
												
									}
					      }
					      
					      
					      if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni==Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni){
										
								for(daghighe_bazi=90;daghighe_bazi<=120;daghighe_bazi++){
											  
											  m= 50 ;
											  m += ((miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval)-50)/2) + ((50-miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom))/2);
											
						
										
										if((rand()%101)<=1){
									    	if((rand()%101)<=m){
									        	Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ezafe++;
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_aval_dar_che_daghayegi_bodand[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ezafe-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
											}
											else{
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe++;
												Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].golhaye_teame_dovom_dar_che_daghayegi_bodand[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe + Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni-1]=daghighe_bazi;
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
												
											}
									   
									    }
								 }
								 
								 taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_aval, -3, 1);
					             taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_dovom,-3 , 1);
					             
					             
					             
					             if(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe==Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_ezafe){
					                   for(i=0;i<5;i++){
					                   	   if((rand()%101)<=miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval)){
					                   	   		Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_penalti++;
					                   	   		taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
										   }
										   if((rand()%101)<=miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom)){
					                   	   		Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_penalti++;
					                   	   		taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
												taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
										   }
					                   	   
									   }
									   
									   
							
									   while(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_penalti==Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_penalti){
									   			       if((rand()%101)<=miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval)){
								                   	   		Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_aval_dar_vaghte_penalti++;
								                   	   		taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, 1, 1);
															taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, -1 , 1);
													   }
													   if((rand()%101)<=miyangine_ghodrate_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom)){
								                   	   		Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].tedade_gole_zade__teame_dovom_dar_vaghte_penalti++;
								                   	   		taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_dovom, 1, 1);
															taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][counter].id_teame_aval, -1 , 1);
													   }
													   
									   }
									   
								 }
						  }
					      
					      
					 taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_aval, 1, 1);
					 taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_dovom, 1 , 1); 
					 taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_aval, -1, 0);
					 taghyir_form_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_dovom, -1 , 0);
					 
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_aval, 1, 0);
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_dovom, 1 , 0); 
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_aval, -1, 1);
					 taghyir_fitness_bazikonan(Jadvale_natayej.dore_hazfi[0][counter].id_teame_dovom,-1 , 1);	      
			}   
			
			Jadvale_natayej.ta_marhaleye_chand_pish_rafte++;       
	}	
	
	
	
	
}































int teame_user_bazi_chandome_list_gorohi_ast(short int kodam_marhale){
	int i ;
	if(kodam_marhale<=2){
		for(i=0;i<16;i++){
			if(Jadvale_natayej.dore_gorohi[kodam_marhale][i].id_teame_aval == id_team_user || Jadvale_natayej.dore_gorohi[kodam_marhale][i].id_teame_dovom == id_team_user )
			   return i ;
			
		}
	}
	   
}
















void neshan_dadane_vazeeyat(){
	int i =0 , j=0 , ta_marhaleye_chand_pish_rafte= 0 ;
	if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=2){
		printf("\n\n\n\nbazi haye gorohi dore bad : ");
		for(i=Jadvale_natayej.ta_marhaleye_chand_pish_rafte;i<=2;i++){
			printf("\n\n%s ------------- %s",Team_info[Jadvale_natayej.dore_gorohi[i][teame_user_bazi_chandome_list_gorohi_ast(i)].id_teame_aval].name , Team_info[Jadvale_natayej.dore_gorohi[i][teame_user_bazi_chandome_list_gorohi_ast(i)].id_teame_dovom].name);
		}
		sort_kardane_goroh_ha();
		printf("\n\n\n\nvazeeyat team dar goroh %c: ",Team_info[id_team_user].group);
    	for(j=0;j<4;j++)
    	printf("\n\n%s =>emtiyaz=%d  || tafazol=%d  || gole zade=%d || gole khorde=%d || bazi=%d || bord=%d || bakht=%d || mosavi=%d" , Team_info[Goroh_ha[Team_info[id_team_user].group-65][j].id_teams].name , Goroh_ha[Team_info[id_team_user].group-65][j].emtiyaz , Goroh_ha[Team_info[id_team_user].group-65][j].tafazole_gol  ,  Goroh_ha[Team_info[id_team_user].group-65][j].tedad_gole_zade , Goroh_ha[Team_info[id_team_user].group-65][j].tedad_gole_khorde, Goroh_ha[Team_info[id_team_user].group-65][j].tedad_bazi,Goroh_ha[Team_info[id_team_user].group-65][j].tedad_bord,Goroh_ha[Team_info[id_team_user].group-65][j].tedad_bakht,Goroh_ha[Team_info[id_team_user].group-65][j].tedad_mosavi);	
	}
	else if(Jadvale_natayej.ta_marhaleye_chand_pish_rafte<=6){
		chidane_barnameye_baziha_dar_marhaleye_hazfi();
		ta_marhaleye_chand_pish_rafte = Jadvale_natayej.ta_marhaleye_chand_pish_rafte - 3 ;
		
		for(i=0;i<ta_marhaleye_chand_pish_rafte;i++){
       	switch(i) {
			      case 0 :
			         printf("\n\n\n\nnatayeje yek-hashtome nahaei : \n");
			         break;
			      case 1 :
			         printf("\n\n\n\nnatayeje yek-chaharome nahaei : \n");
			         break;
			      case 2 :
			         printf("\n\n\n\nnatayeje nime nahaei : \n");
			         break;
			      case 3 :
			         printf("\n\n\n\nnatayeje nahaei : \n");
			         break;
			   }
       	    for(j=0;j<Jadvale_natayej.tedade_bazihaye_dore_hazfi[i];j++){
			   
		       	  if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
		          printf("\n%s ghanoni=> %d  --------------  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni , Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
		          
		          else if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
			   	  printf("\n%s ghanoni=> %d     ezafe=> %d  -------------- %d <=ezafe  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
			      
			      else
			   	  printf("\n%s ghanoni=> %d     ezafe=> %d     penalti=> %d  -------------- %d <=penalti      %d <=ezafe     %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_penalti,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_penalti ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
		   }
	   }
		
		printf("\n\n\n\nbazi haye hazfi dore bad : ");
		for(i=0;i<Jadvale_natayej.tedade_bazihaye_dore_hazfi[ta_marhaleye_chand_pish_rafte];i++){
			printf("\n\n%s ------------- %s",Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][i].id_teame_aval].name ,Team_info[Jadvale_natayej.dore_hazfi[ta_marhaleye_chand_pish_rafte][i].id_teame_dovom].name );
		}
		
	}
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






































//    for(i=0;i<8;i++){
//    	printf("\n\n\n\n%c\n",i+65);
//    	for(j=0;j<4;j++)
//    	printf("\n%s ====>  || emtiyaz = %d  || tafazol = %d  || tedad gole zade = %d ",Team_info[Goroh_ha[i][j].id_teams],Goroh_ha[i][j].emtiyaz,Goroh_ha[i][j].tafazole_gol,Goroh_ha[i][j].tedad_gole_zade);
//    	
//	}
//
//	for(i=0;i<36;i++){
//
//    
//    	printf("\n%s ====>     post = %c       || skill = %d   || to tarkibe asli hast? %d || form = %d || fitness = %d",Team_info[11].bazikon[i].name,Team_info[11].bazikon[i].poste_asli,Team_info[11].bazikon[i].skill,Team_info[11].bazikon[i].aya_bazikon_dar_tarkibe_aslist,Team_info[11].bazikon[i].form,Team_info[11].bazikon[i].fitness);
//    	
//	}
//	
//	play_bazi_gorohi();
//    play_bazi_gorohi();
//    play_bazi_gorohi();
//    printf("\n\n\n\n");
//
//    for(i=0;i<16;i++){
//        
//    	         	printf("\n%s ====>     %d ----- %d    <==== %s",Team_info[Jadvale_natayej.dore_gorohi[0][i].id_teame_aval].name , Jadvale_natayej.dore_gorohi[0][i].tedade_gole_zade__teame_aval,Jadvale_natayej.dore_gorohi[0][i].tedade_gole_zade__teame_dovom,Team_info[Jadvale_natayej.dore_gorohi[0][i].id_teame_dovom].name);
//		
//	}
//	
//	
//	printf("\n\n\n\n");
//
//    for(i=0;i<16;i++){
//        
//    	         	printf("\n%s ====>     %d ----- %d    <==== %s",Team_info[Jadvale_natayej.dore_gorohi[1][i].id_teame_aval].name , Jadvale_natayej.dore_gorohi[1][i].tedade_gole_zade__teame_aval,Jadvale_natayej.dore_gorohi[1][i].tedade_gole_zade__teame_dovom,Team_info[Jadvale_natayej.dore_gorohi[1][i].id_teame_dovom].name);
//		
//	}
//	
//	
//	printf("\n\n\n\n");
//
//    for(i=0;i<16;i++){
//        
//    	         	printf("\n%s ====>     %d ----- %d    <==== %s",Team_info[Jadvale_natayej.dore_gorohi[2][i].id_teame_aval].name , Jadvale_natayej.dore_gorohi[2][i].tedade_gole_zade__teame_aval,Jadvale_natayej.dore_gorohi[2][i].tedade_gole_zade__teame_dovom,Team_info[Jadvale_natayej.dore_gorohi[2][i].id_teame_dovom].name);
//		
//	}
//	
//	sort_kardane_goroh_ha();
//        for(i=0;i<8;i++){
//	    	printf("\n\n\n\n\n\n\n%c\n\n",i+65);
//	    	for(j=0;j<4;j++)
//	    	printf("\n\n%s ====>  || emtiyaz = %d  || tafazol = %d  || tedad gole zade = %d || tedad gole khorde = %d || tedad bazi = %d || tedad bazi borde = %d || tedad bazi bakhte = %d || tedad bazi mosavi shode = %d",Team_info[Goroh_ha[i][j].id_teams],Goroh_ha[i][j].emtiyaz,Goroh_ha[i][j].tafazole_gol,Goroh_ha[i][j].tedad_gole_zade,Goroh_ha[i][j].tedad_gole_khorde,Goroh_ha[i][j].tedad_bazi,Goroh_ha[i][j].tedad_bord,Goroh_ha[i][j].tedad_bakht,Goroh_ha[i][j].tedad_mosavi);
//	    	
//        }
//       
//       
//       play_bazi_hazfi();
//       play_bazi_hazfi();
//       play_bazi_hazfi();
//       play_bazi_hazfi();
//       for(i=0;i<4;i++){
//       	printf("\n\n\n\n\n\n\n\n\n");
//       	    for(j=0;j<Jadvale_natayej.tedade_bazihaye_dore_hazfi[i];j++)
//		       	  if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni)
//		          printf("\n%s ghanoni=> %d  --------------  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni , Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
//		          
//		          else if(Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe!=Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe)
//			   	  printf("\n%s ghanoni=> %d     ezafe=> %d  -------------- %d <=ezafe  %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
//			      
//			      else
//			   	  printf("\n%s ghanoni=> %d     ezafe=> %d     penalti=> %d  -------------- %d <=penalti      %d <=ezafe     %d <=ghanoni %s",Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_aval].name,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ghanoni,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_ezafe,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_aval_dar_vaghte_penalti,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_penalti ,Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ezafe, Jadvale_natayej.dore_hazfi[i][j].tedade_gole_zade__teame_dovom_dar_vaghte_ghanoni,Team_info[Jadvale_natayej.dore_hazfi[i][j].id_teame_dovom].name);	    	
//			   
//	   }
