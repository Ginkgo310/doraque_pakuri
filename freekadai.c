#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int selecter = 0;
int check = 1;
int damege = 0;
int real_def = 0;
int slyme_move = 0;
int slyme_damege = 0;
int sleep_time = 2;
int freeza = 0;

void slyme(){
	system("clear");
	printf("                     ^               \n");
	printf("                    / \\             \n");
	printf("                  -     -            \n");
	printf("                --       --          \n");
	printf("              /   ::   ::   \\       \n");
	printf("              |             |        \n");
	printf("              \\    _____    /       \n");
	printf("               --  \\___/  --        \n");
	printf("                 ---------           \n");
	printf("\n");
	printf(" __________________________________________ \n");
	printf("|                                          |\n");
}

void endline(){
	printf("|__________________________________________|\n");
}

void mp_shortage(int mp){
	slyme();
	printf("|     Beacause ofshort of your mp,         |\n");
	printf("|     you can't use magic.Your mp:%3d      |\n",mp);
	printf("|__________________________________________|\n");
}

void blink_slyme(){
	for(int i = 0; i < 3; ++i){
		slyme();
		printf("|                                          |\n");
		endline();
		usleep(50000);
		system("clear");
		usleep(50000);
	}

}

struct chara{
	char name[1000];
	int  hp;
	int  mp;
	int  atk;
	int  def;
};

int main(void){
	struct chara you;
	struct chara enemy;

	enemy.hp = 200;
	enemy.mp = 0;
	enemy.atk = 20;
	enemy.def = 7;

	while(check){
		system("clear");
		printf("selecter your job\n");
		printf("press 1 to selecter magician(HP = 70,MP = 10,ATK = 40,DEF = 5)\npress 2 to select fighter(HP = 100,MP = 0,ATK = 60,DEF = 10)\n");
		scanf("%d",&selecter);
		switch(selecter){
			case 1:
				snprintf(you.name, sizeof(you.name), "magician");
				you.hp = 70;
				you.mp = 10;
				you.atk = 40;
				you.def = 5;
				break;
			default:
				snprintf(you.name, sizeof(you.name), "fighter");
				you.hp = 100;
				you.mp = 0;
				you.atk = 60;
				you.def = 10;
				break;
		}
		printf("your job is %s.press 1 to start game,or press 2 to change your job\n",you.name);
		scanf("%d",&selecter);
		if(selecter == 1){
			check = 0;
		}else{
			check = 1;	
		}
	}

	system("clear");
	slyme();
	printf("Wow! A wild slyme  appeard! It will attack you.\n");
	endline();
	sleep(sleep_time);
	while(enemy.hp > 0 && you.hp > 0){
		real_def = you.def;
		slyme();
		printf("|   1.attack     　2.defend yourself 　　  |\n");
		printf("|   3.use magic    4.get data              |\n");
		endline();
		scanf("%d",&selecter);
		system("clear");
		slyme_move = 1;
		switch(selecter){
			case 1:
				blink_slyme();
				slyme();
				damege = (rand() % 10) + you.atk;
				printf("|    you attacked slyme! %d damage!        |\n",damege);
				endline();
				enemy.hp = enemy.hp - damege;
				sleep(sleep_time);
				break;
			case 2:
				slyme();
				real_def = you.def + (rand() % 10);
				printf("|         you defended yourself!           |\n");
				endline();
				sleep(sleep_time);
				break;
			case 3:
				slyme();
				printf("|        Which magic will you use?         |\n");
				printf("|  1.heal yourself             (need 2 mp) |\n");
				printf("|  2.upgrade your atk          (need 1 mp) |\n");
				printf("|  3.upgrade your def          (need 1 mp) |\n");
				printf("|  4.freeze enemy              (need 4 mp) |\n");
				endline();
				scanf("%d",&selecter);
				system("clear");
				switch(selecter){
					case 1:
						if(you.mp < 2){
							mp_shortage(you.mp);
						}else{
							blink_slyme();
							you.mp = you.mp - 2;
							you.hp = you.hp + 10 + (rand() % 10 + 1);
							slyme();
							printf("| you healed! your hp = %d|\n",you.hp);
							endline();
						}
						break;
					case 2:
						if(you.mp < 1){
							mp_shortage(you.mp);
						}else{
							--you.mp;
							blink_slyme();
							you.atk = you.atk + 5 + (rand() % 20);
							slyme();
							printf("|  Your atk has upgraded. atk = %d         |\n",you.atk);
							endline();
						}	
						break;
					case 3:
						if(you.mp < 1){
							mp_shortage(you.mp);
						}else{
							blink_slyme();
							--you.mp;
							you.def = you.def + 3 + (rand() & 5 + 1);
							printf("|      Your def has upgraded. def = %2d     |\n",you.def);
							endline();
						}
						break;
					default:
						if(you.mp < 4){
							mp_shortage(you.mp);
						}else{
							slyme();
							you.mp = you.mp - 4;
							printf("|       Slyme has stopped...               |\n");
							endline();
							freeza = 2;
						}
						break;
				}
				sleep(sleep_time);
				break;
			default:
				slyme();
				printf("|Your Data.                                |\n");
				printf("|  HP %3d   MP %3d   ATK %3d   DEF %3d     |\n",you.hp,you.mp,you.atk,you.def);
				printf("|Enemy's Data.                             |\n");
				printf("|  HP %3d   MP %3d   ATK %3d   DEF %3d     |\n",enemy.hp,enemy.mp,enemy.atk,enemy.def);
				printf("| press 1 to close data                    |\n");
				endline();
				slyme_move = 0;
				scanf("%d",&selecter);
				break;

		}
		if(enemy.hp <= 0 || freeza > 0){
			slyme_move = 0;
		}

		if(slyme_move != 0){
			slyme_move = rand() % 10 + 1;
			switch(slyme_move){
				case 1:
					slyme();
					printf("|    Suddenly,                             |\n");
					printf("|  Slyme began to be covered with light..  |\n");
					endline();
					sleep(3);
					blink_slyme();
					blink_slyme();
					blink_slyme();
					slyme();
					printf("|            Bomb! You dead!               |\n");
					endline();
					you.hp = 0;
					break;
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
					slyme_damege = enemy.atk + (rand() % 5 + 1) - real_def;
					you.hp = you.hp - slyme_damege;
					blink_slyme();
					slyme();
					printf("|      Slyme attacked you! damege is %3d   |\n",slyme_damege);
					endline();
					break;
				default:
					enemy.hp = enemy.hp + (rand() % 10 + 30);
					blink_slyme();
					slyme();
					printf("|         Slyme healed himself!            |\n");
					endline();
					break;
			}
			sleep(sleep_time);
		}
		--freeza;
	}
	system("clear");
	if(enemy.hp > 0){
		slyme();
	}else{
		for(int i = 0; i < 10; ++i){
			printf("\n");
		}
		printf(" __________________________________________ \n");
		printf("|                                          |\n");

	}
	printf(you.hp <= 0?"|         You dead..                       |\n":"|              You win!                    |\n");
	endline();
	return 0;
}
