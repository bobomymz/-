#include<bits/stdc++.h>
#include<sstream>
#include<windows.h>
#include<conio.h>
using namespace std;
/*δ��wqxͬ���ֹת�� 
һ����λ�ƶ�
	��������  ��Ϸ����       ʵ�ʴ�С
	ʱ��      ����           1ms 
	����      ��             1��=2���ַ�
	�¶�      degree         1 degree=1���϶� 
����BUG��¼ 
	1����ͼ���Եǽ���ɴ���
	    1�����졢����ʱ�䣺2022.1
	    2����������
	    	(1)��ͼ�ܳ�16~17�����䣬���䳤5��
	    3���������
	        (1)ǽ����ʾΪ�����ַ���ȫ��/��/����/������ģ����ڣ�
		    (2)�������ݼ�¼���� 
		4������ʱ�䣺2022.7.14ǰ 
	2�����ڱ����������
		1�����졢����ʱ�䣺2022.6.27
		2������������������ڱ���ʱ��char(24~27) 
		3���������
			(1)������ 
		4������ʱ�䣺2022.7.10
		   ��������Ϊ�����ַ� 
	3��Կ���ſ���״̬����
		1������ʱ�䣺2022.8
		2������ʱ�䣺2022.9
		3�����������������Ϸ
		4������ԭ�򣺳�ʼ��ʱΧ�Ʒ��������ţ�doors_around_rooms���ĺ���û��������Ϊδ�������˴���Ϸ�д򿪵����ٴ�
			��Ϸʱ����״̬�����ǿ�������ͬһ��λ�õ��ű��ֿ��������Զ���ۼ� 
		5������ʱ�䣺2022.9.30 
������Ϸ��ͼ
	1������綨
		1����һ��λ�û��䳤��/��� 
		2����㣺һ��λ��/�������Σ��Ķ��㣬ÿ�����ĸ�������ڣ�һ������½Ǹ�㣨��ӡ��ʾΪ���ϣ�������Ϊ�˸�
			����(x,y)�����Ͻ�(x,y+1)�����½�(x+1,y)�����Ͻ�(x+1,y+1)
		3����Եǽ������x==1||x==length||y==1||y==width��λ�õļ���
		4�����Σ��ųɳ����ε�һЩλ�õļ��� 
		5�����䣺������һ��������ǽ�ĳ�����2�ľ��ε�һЩλ�õļ��� 
	2����С
		��length�񣬿�width�񣬸�height*2�㣨x��y��z����1��ʼ��ţ�
		1~height��Ϊһ����Ϸ����height+1~height*2��Ϊ��չ�泲������������ӳ�Ѩ���� 
�ġ�����Կ��
	1����
		1��������4��
		2������
			(1)�������ͨ��ԽԶԽ�ࣩ
			(2)Χ�Ʒ������� 
	2��Կ��
		1��������4�֣���Ӧ�ţ� 
		2������
			(1)�������ͨ��ԽԶԽ�٣�
			(2)����������
			(3)����������
				[1]ģʽ��ȷ����ÿ���ŵ�Կ�׶����ڲ��������ŵ������ȡ��
				[2]ʵ�ַ���
					��׼��
						BFS�����ף�Q��vst
						vector<position_3D> vspace�ѷ��ʡ�û����Ʒ�Ŀյ�	
						vector<position_3D> vdoor[4]�ѷ��ʡ�δ�Ŷ�ӦԿ�׵��ţ����ֱַ��¼�� 
						vector<position_3D> vkind����ѡ����ŵ����� 
					�ڳ�ʼ����
						a.ȫ�����
						b.�����������Ϊ��� 
					���ظ�ִ�У� 
						a.BFS���������ѷ��ʡ��ѷŶ�ӦԿ�׵��ţ��ܵ��ĵط���
						����vspace������������δ���ʵ��Ŷ�����vdoor
						b.Ϊ�´�ѭ��׼�� 
							��4������������Ϊ0�����ȿյض���������vkind 
							������һ���ſ���ѡ�� 
								��vkind�����ȡ��һ���ţ���������ȫ������Q��ȥ����
								��vspace�����ȡ�������������Ŀյط��ö�Ӧ��һ��Կ��
						 	�����˳�ѭ�� 
					ע�⣺����BFS���������ظ������ѷ��ʹ��ĵط���֮ǰѭ����Ҳ���ᣩ��  
�塢���
	1���ƶ�
		1������ٿ�
			����� ��Ӧ���� ����仯
			��     0        (x,y-1,z) 
			��     1        (x+1,y,z)
			��     2        (x,y+1,z)
			��     3        (x-1,y,z)
			���ƶ���ģʽ�¸ı�λ�ã����ı䳯��ģʽ�½��ı䷽�� 
		2����ײ���
		   ��ʽ�������������������������/�򡭡����͡�������Ȼ�󡭡��������򡭡�����Ȼ�󡭡������� 
			(1)����ǽ��ͣ��
			(2)����������ж�ӦԿ�׾ͽ��ŷ���ͣ�� 
		3�������ƶ�
			(1)�ֶ�����¥�����¿ո������/��¥ �Զ�����¥������¥�ݾ���/��¥
			(2)�������ݾ�����ѡ¥����棬Ȼ���ƶ�����Ӧ¥��
	2�������Ʒ
		��Ʒ��    ��ʰ    ʹ�ã���1��ʹ��1����2��ʹ��2��������    ����Ч������1��Ч��1����2��Ч��2��������
		Կ��      �Զ�    �Զ�                                    ����Ӧ��
		���ڱ���  ��      ��                                      ָ�򵽴���ڵ����·�ߵķ���
		����      ��      ��                                      ������ߣ�ʹ����ܿ�����Զ�ĵط� 
	3����Ұ����
		1����������¥����/��¥���������ӹ��䣨����Ҫ�޶���Զ���룿��
			ǽ��������һ�㣬�������ⶼ�ܿ�����Ҳ����Ʒ���赲���ߣ���
		2��׼��
			int game_map[][][].in_player_sight������һ�ο������λ�õ�ʱ�䣬��Ϊ��Ϸ��ͼ 
			queue<position_3D> pos_in_sight����Ҫ����Ļ������ʾ��λ�ã���Ϊ��1 
			queue<position_2D> pos_lst_sight�ϴ�����Ļ����ʾ��λ�ã�scr������Ϊ��2
			queue<position_2D> pos_backupλ�ã�scr�����ݣ�Ϊ�»غϵĶ�2��׼������Ϊ��3 
			string screen_display_coding(position_3D pos)��Ļ������� 
			map<position_2D,string> screen_pos��Ļ�ϵ�λ����ʾ���ݵı��루����screen_display_coding�� 
			map<position_2D,int> screen_z��Ļ��������Ҫ��ʾ��λ��������¥�㣨z���꣩ 
			position_3Dtoscr��position_scrto3D�ȸ��������ת������ 
			(1)��ʼ����all_assigned����ÿ����Ϸ��ʼʱ���һ��������Щ������screen_zÿ�غ϶�Ҫ�� 
			(2)����ѿ�����
			 	[1]�Ѿ���ǹ���Ϸ��ͼ��[3]
				[2]�����Ϸ��ͼ�����1�����screen_z������ 
				[3]��λ�������λ�ã����screen_z������ 
		3������
			(1)ʮ����
				[1]��飺ʮ�����ӽǣ�ǰ�����ң�+������ӷ�Χ�Ż� 
				[2]�ŵ㣺ʵ�ּ� ȱ�㣺��������ȫ���ã������ﲻ�ܿ���ȫ����Χ 
			    [3]ʵ�ַ���
					���Ȱ�������ڵ�λ�����1�����һ����Ϸ��ͼ
					����4�����������Ұ�����1�����һ����Ϸ��ͼ
						������λ�����߿��Դ������Ͱ��������λ�����1������ѿ���
						��������λ����������������߷����෴�ķ����ϵ�ǰһ��λ�ã�
						���ǰһ��λ�����߿��Դ������Ͱ�����Ӧ���λ�����1������ѿ��� 
			(1)������
				[1]��飺�����λ��Ϊ������BFS����������ǽ�ͼ�¼���ڵ������߷�Χ������ϵ����ǣ������λ�õ��ĸ��
					Ϊԭ�㣩�������ʱ���ȫ�ڵ���λ�ã�ֱ���������߷�Χ�����ڵ�
				[2]�ŵ㣺��Ϊ��ʵ�ļ�������Ұ��ʵ��������� 
				   ȱ�㣺ʱ�临�Ӷ��Ըߣ��о���������13����Ż�������������޴����ӵ����� 
				[3]׼��
					bool occlusion[4][360]��¼���λ��4������ϱ��ڵ������߷�λ�ǣ�0��δ�ڵ���1�����ڵ�
					int cnt_occlusion[4]��¼���λ��4�������δ���ڵ������߷�λ�ǻ�ʣ��������occlusion[0~3]��0���� 
					int calc_angle(position_3D p)����p������λ�õķ�λ�ǣ�0~360�㣩 
					bool invisible(position_3D p)����p�Ƿ񿴲��� 
					void mark_occlusion(position_3D p)���p�ڵ��ĽǶȷ�Χ
					queue<position_3D> visible_stair�����ܿ�����¥�ݵ�λ�� 
					BFS�����ף�Q��vst
					�ֲ�λ�ñ�����u��v��v2 
					��ʼ����assigned����ÿ�μ���ǰocclusion���㣬cnt_occlusion[0~3]����Ϊ360 
					��λ��ö�ٷ�������ʱ�룬���359�㣩��for(int i=��С�Ƕ�;i!=(���Ƕ�+1)%360;i=(i+1)%360)
				[4]ʵ�ַ�����player_calculate_vision2(position_3D pos=player1.pos)��
					�����������Ӳ����vst
					�ڶ���Ϊ�ջ�cnt_occlusion[0~3]��Ϊ0���ᣬ����ȡ������u  
					�۲�����չ���ڣ�������չ��v
					��v������ͼ��Χ���� 
					�ݿ�����v��invisible(v)���ͱ��vst������
					��v��ǽ�����occlusion��mark_occlusion(v)��
					��v��Ӳ����vst������Ϸ��ͼ�б�ǣ����� 
					��v��¥�ݣ�����ͨ����λ��v2���visible_stair������ 
					������뿴��¥��/�£�ö��visible_stair��ÿ��λ��u��
					occlusion���㣬cnt_occlusion[0~3]����Ϊ360�� 
					������ͨ����¥�ݿ����ķ�λ�Ƿ�ΧΪ�ɼ���mark_occlusion()���ı�cnt_occlusion��ͬʱȡ��occlusion���� 
					����player_calculate_vision2(u) 
		4����Ļ���£�screen_update��ʱ
			(1)�����2
				[1]ȡ������spos 
				[2]����spos��screen_z�����Ļ�������λ��Ҫ��ӡ��Ϸ��ͼ���ĸ�λ�ã�now_pos�� 
					screen_zû����Ļ���λ�õ���Ϣ�������λ��Ϳ�ڣ�����screen_pos��886 
				[3]�ж� 
					����now_pos����ʾ���ݱ����������Ļ�ϣ�δ���£�����ʾ���ݱ��벻ͬ��
						�������now_pos��print_game_map_pos(now_pos)��������screen_pos
					d.now_pos�����3
			(2)�����1
				[1]ȡ������now_pos
				[2]�����print_game_map_pos(now_pos)��
				[3]position_3Dtoscr(now_pos)�����3 
			(3)��3������ȫ���Ƶ���2 
	4����������
		1������ֵ
			(1)��ʼ��100%
			(2)����0�����������Ϸʧ��
		2������ֵ
			(1)��ʼ��100%
			(2)����ƶ�ʱ����1�㣬����<100%��ÿ0.5��ظ�1��
	5��ʳ�� 
		�ȼ�\Ч��  �����ָ�ADDL  �����ظ�ADDS ���ָ������ޣ� 
		1          +40%          +20%
		2          +20%          +10%
		3		   +10%          +5%
	6������
		1����������/�;ö� 
			(1)���ɷ�����������ɡ������ԽԶԽ��/�ࡢ�����ԽԶԽ��/�� 
		2������
			(1)����ǹ
				[1]ʹ�ã������ܡ�/�����ߡ�ģʽ�£���s��������1����������������ҳ��򷢳���ɫ������������0.5�룬
					�´�ʹ����ȴ����ʹ����ɣ�����ȴ0.1�� 
				[2]�ص㣺����˲������Ŀ�꣬����ǽ�����ϵ��ž��жϣ��������Ӿͷ��䣬���߶��������ɫ���⣬��������к�ɫ��KO��Ч��
				[3]����Ч������ȼTNT������� 
			(2)���� 
				[1]ʹ�ã������ܡ�/�����ߡ�ģʽ�£���s������������1������ҳ����ӳ����ڣ��ٶ�7m/s��
					�´�ʹ����ȴ�0.2�� 
				[2]�ص㣺�ٶȽϸߣ��ɻ��գ�����ǽ�����ϵ��ž�ֹͣ���У���ɿɼ�ʰ����Ʒ����������к�ɫ��KO��Ч��
				[3]����Ч�������� 
			(3)ì
				[1]ʹ�ã������ܡ�/�����ߡ�ģʽ�£�ÿ���ƶ�/�ı䷽������ҳ���̳�����Ϊ2��ì�����ֲ���ֱ���´Σ�
					���������;öȼ��٣�������ٶ��йأ� 
				[2]�ص㣺˲������Ŀ�꣬���������޷��ƶ��͹���������ǽ�����ϵ��ž�ͣ�£���������к�ɫ��KO��Ч��
				[3]����Ч�������� 
��������
	1��ֱ�߾��루�����ľ��빫ʽ��
	2�������پ��루MHT_DIST��
	3������/�������루�����һ���ߵ���һ��Ĳ�����
�ߡ���Ļ
	1�������������ң��������£� 
		1�������Ϣ��[0,0]->[46,48] 47*49 
		2����Ϸ��ͼ��[46,0]->[142,48] 97*49
		3�������Ʒ��[142,0]->[188,48] 47*49 
			(1)��ʽ
				[1]���
					���Ͻǣ�"��Ʒ��"
					�б�ǩ���������;á����桢ʹ��ָ�ϵ�
					�б�ǩ����Ʒ��+��ʾͼ�� 
				[2]MC��� 
					��1~2�У�"������Ʒ��     ������   �;ã�   " 
					��2�У�"ʹ�÷�����"
					��3�У�������Ʒ��ͼ�񣨰�����˳������ 
			(2)ʹ��
				[1]��f��������Ʒ/ѡ����Ʒ���˳�
				[2]������Ʒʱʹ�÷����ѡ��
�ˡ���ʱ������־ 
	1��׼��
		map<string,int> game_timer��¼δ��ĳ���¼�����ʱ����Ϸʱ��
		map<string,bool> game_flag��¼ĳ���¼��Ƿ��� 
	2��ʹ��
	e.g.game_timer["����ƶ�"]=game_time+1000;�������ֵplayer1.vts.stg.strength_value����һ�루1000ms���ظ�+1
		game_flag["���ʬ��"]=true;��ʬ�屻����������Ļ 
		��Ļ��ȥ��KO������ 
		1��󡭡� 
		if(game_timer["pvsr"]<=game_time&&����) player1.vts.stg.strength_value++;�������ֵ�ظ�+1
�š�����
	1��������£���С��������
		1����ʼ�������ж��У�Qbug/Qghost��Ϊ��
		2��ÿ�������Ұ���㽫�ܿ����Ҳ��ڶ��еĵ��˼�����У������õ���Ϊ����״̬��.update=true�� 
		3��ÿ�θ��µ���ʱ������Ҿ���>50����Ҳ��ܿ�����������˾ͳ��ӣ�ֹͣ���£�.update=false��
			�������ƶ�ʱ���������µĵ��ˣ�����������У��������������Ϊ����״̬��.update=true�� 
	2������
		1������
			(1)λ�ã���Ѩ��һ��ʼ�����λ�� 
			(2)��Ϸ�����Ƶ�������� 
		2���ƶ�
			(1)���򣺳�ʼ���������ǽ�����������ת�䣨������ʱ�䣩������¥�����¥��/��û���������������¥��������Ѩ�ͽ��� 
			(2)�ٶȣ�1~10��/1000���루����ʱȷ����
		3������
			(1)��ʽ����ײ
			(2)�˺���1~20��Ѫ�����ٶ��йأ�  
		4��Ѫ����1��
			(1)���������˺�+1  (2)������/����/ì����-1
			(3)Ѫ��=0ʱ��������������Ѩ�ڲ����λ�ã�û�п�λ�͵��ţ� 
	3�����ӳ�Ѩ
		1�����ɣ���Ѩ��λ�ھ������һ��������Ŀյأ������Խ��Խ�࣬ͬʱ�ڳ�Ѩ�ڲ���ͼ����ͬһλ�õĳ�Ѩ�ڲ���Ӧ 
		2����Ѩ��Ѫ����3��
		���������-1��Ѫ��=0ʱ���ݻٲ���ʧ����������Ϊ��Ѩ��
		3������/��ҽ���ɴ�������Ѩ�ڲ���ͼ 
		4���洢��game_map[1~length][1~width][height+1~height+height].items.nst 
		5�����裺ֻ�пյغ�ǽ��û���κ���Ʒ 
	4����
		1������
			(1)λ�ã�һ��ʼ�����λ�� 
			(2)��Ϸ�����Ƶ�������� 
		2���ƶ�
			(1)�ٶȣ�1~10��/1000���루����ʱȷ����
			(2)�������
				[1]�ܿ�����ң���·�ߴ洢��Ϊ�գ���������·�������Ĵ洢���� 
					����Ϊ�գ�����·���ƶ��� 
				[2]���������������������Դ�ƶ� 
				[3]��������㼣�������㼣�����ƶ� 
				[4]���ģʽ���������ת�䣨������ʱ�䣩������¥�����¥��/��û����������������������¥��������Ѩ��������ʽ��� 
		3������
			(1)��ʽ����ײ
			(2)�˺���1~20��Ѫ�����ٶ��йأ�  
		4��Ѫ����5��
			(1)���������˺�+1  (2)������/���ڻ���-1
			(3)Ѫ��=0ʱ��������������Ѩ�ڲ����λ�ã�û�п�λ�͵��ţ�
*/
#define PRESS_KEY_UP 72
#define PRESS_KEY_DOWN 80
#define PRESS_KEY_LEFT 75
#define PRESS_KEY_RIGHT 77
#define PRESS_KEY_ENTER 13
#define PRESS_KEY_SPACE 32
#define PRESS_KEY_E 101
#define PRESS_KEY_F 102
#define PRESS_KEY_G 103
#define PRESS_KEY_S 115 
#define PRESS_KEY_V 118
typedef long long ll;
HANDLE hout;//�����������ɫר�ã� 
const int SMALLEST_TIME=10;//��Ϸʱ����С��λ��10����
const int MAX_SCREEN_LENGTH=189,MAX_SCREEN_WIDTH=49;//ConsolePauser����󳤿��
const int MAX_LENGTH=500,MAX_WIDTH=500,MAX_HEIGHT=10;//��Ϸ��ͼ����󳤿�� 
const int KINDS_OF_DOORS=4,KINDS_OF_KEYS=4;//�š�Կ�׵�����������4
const int KINDS_OF_FOOD=2,EFFECT_OF_FOOD=3;//ʳ�����������2��Ч���ȼ�����3 
const int MAX_PLAYER_SPEED=2000;//��ҵ�����ٶ� 
const int MAX_SIZE_OF_ITEM_LAB=20;//�����Ʒ�����������
const int MAX_BUG_NUM=100000,MAX_GHOST_NUM=10000;//���ӡ����������� 
const int INF=2e9;//��Ϸ������֡� 
const double PI=acos(-1);//�� 
bool game_pause=false,game_end=false,game_success=false,start_again=false;//�Ƿ���ͣ/������Ϸ���ɹ����ѡ����¿�ʼ
int game_time,start_time;//��Ϸ�����С���ʼ��ʱ��
int lst_see_time;//�ϴ����¼��������Ұ��ʱ�� 
void gotoxy(int x=0,int y=0); 
enum MAZE{//�Թ���ǽ�ڡ��š�ͨ���� 
	WALL,SPACE,EXIT,DOOR1,DOOR2,DOOR3,DOOR4,UPSTAIR,DOWNSTAIR,NEST,DOORS,STAIRS//ǰ����λ�ò�׼�� 
};
enum FLOOR{//�ذ�״�� 
	NORMAL,HOLE
}; 
enum PLAYER_ENEMY{//��Һ͵��� 
	NOBODY,PLAYER,BUG,GHOST
};
enum ALL_ITEM{//������Ʒ
	K1=1,K2,K3,K4,AS1,AS2,AS3,AL1,AL2,AL3,BX,BL,TT,CE//ȡ���ַ���β�ַ� 
};
enum KEY{//Կ�� 
	KEY1=1,KEY2,KEY3,KEY4
};
enum FOOD_KIND{//ʳ��
	ADDS=1,ADDL//�����ָ��������ָ� 
};
enum CHANGING_SOLID{//�仯�Ĺ��� 
	BOX=1,BARREL,TNT,CANDLE
};
enum LIQUID{//Һ�� 
	WATER=1,MAGMA
};
enum WEAPON{//������������˼ǵ�ȥ wcnt ����һ�£��� 
	LSG,DART,SPR
};
enum DIRECTION_KEY{//�����
	STOP=0,
	UP,DOWN,LEFT,RIGHT
};
enum CHANGE_DIRECTION{//�ı䷽��
	TURN_RIGHT,TURN_BACK,TURN_LEFT 
};
enum ACTION_KIND{//��ҵĲ������� 
	RUN,WALK,CHOOSE_ITEM,CHANGE_WPN 
};
int length,width,height;//��Ϸ��ͼ����� 
int cnt_notWALL,cnt_SPACE,cnt_STAIRS;//���� 
struct position_2D{//����ṹ�壨xOy�� 
	int x,y;//x�����y���� 
	bool operator<(position_2D a)const{//����< 
		return x<a.x||(x==a.x&&y<a.y);
	}
	bool operator==(position_2D a)const{//����== 
		return x==a.x&&y==a.y;	
	}
	void output1(bool enter=0){//��ӡ���� 
		cout<<"("<<x<<","<<y<<")";
		if(enter) cout<<endl;
	}
};
struct position_3D{//����ṹ�壨xOyOz�� 
	int x,y,z;//x���ꡢy�����z���� 
	void init(){
		x=y=z=0;
	}
	bool operator==(position_3D a)const{//����== 
		return x==a.x&&y==a.y&&z==a.z;	
	}
	bool operator!=(position_3D a)const{//����!=
		return x!=a.x||y!=a.y||z!=a.z;	
	}
	bool operator<(position_3D a)const{//����<
		if(x!=a.x) return x<a.x;
		if(y!=a.y) return y<a.y;
		return z<a.z;	
	}
	void output1(bool enter=0){//��ӡ���� 
		cout<<"("<<x<<","<<y<<","<<z<<")";
		if(enter) cout<<endl;
	}
};
		struct pheromone{//���ӵ���Ϣ�� 
			int disapp,id,d;//��Ϣ����ʧ��ʱ�䡢˭���µġ�ָ�� 
			void init(){
				disapp=d=0;id=-1;
			}
		};
	struct enemy{//����
		int id;//���˵ı�� 
		bool dead;//���������ǻ� 
		int body_disapp;//ʬ����ʧ��ʱ�� 
		pheromone phm;//��Ϣ��
		void init(){
			id=-1;dead=false;body_disapp=0;
			phm.init();
		}
	};
		struct exit_sign{//���ڱ��ƽṹ��
			bool exist;//��û�г��ڱ��� 
			int dir;//���ڱ���ָʾ�ĳ��ڷ���
			void init(){
				exist=dir=0;
			}
		};
		struct mirror{//���ӽṹ��
			bool exist;//��û�о��� 
			int dir,side;//���ӵķ��������
			/*      0	1	2	3
			1side  ��  ��  ��  ��
			2side 	�u	�v  
			*/
			void init(){
				exist=dir=side=0;
			}
		};
		struct food{//ʳ��ṹ��
			bool exist;//��û��ʳ�� 
			int kind,effect;//kind:0,ADDS,ADDL effect:1,2,3
			void init(){
				exist=kind=effect=0;
			}
		};
		struct laser{//�������ṹ��
			bool exist;//��û�м����� 
			int laser_beam;//����������ʽ��0~3���������򡪣���4������Ŀ����� 
			void init(){
				exist=laser_beam=0;
			}
		};
		struct weapon_energy_edc{//��������/�;öȻظ�
			bool exist;
			int num,kind;//��������������/�;öȻظ���0������ǹ 1��ì��
			void init(){
				exist=num=kind=0;
			}
		};
		struct dart{//���ڽṹ��
			bool exist(){//��û�з���
				return num[0]>0||num[1]>0;
			}
			bool exist0(){//��û�е��ϵķ���
				return num[0]>0;
			}
			bool exist1(){//��û�з��еķ���
				return num[1]>0;
			}
			int d[2],num[2];//0������ʾʱ�ã����� /1�����������ã�������  �ķ��ڵķ������� 
			void init(){
				d[0]=d[1]=num[0]=num[1]=0;
			} 
			int prd(){//��ʾʱ�ķ��򣨵���ʱ�豣֤exist()==true�� 
				if(num[1]) return d[1];
				return d[0];
			}
		}; 
		struct spear{//ì�ṹ��
			bool exist;//��û��ì
			int d;//ì�ķ���
			bool head;//ìͷ 
			void init(){
				exist=d=head=0;
			} 
		};
		struct nest{//���ӵĳ�Ѩ��
			bool exist;//��û�г�Ѩ�� 
			int id;//���
			position_3D to;//��Ӧ�ĳ�Ѩ��λ�ã�ע�⣺�����ǽ�ȥҲ�����ǳ����� 
			void init(){
				exist=0;id=-1;to.init();
			} 
		};
		struct footprint{//�㼣�ṹ��
			bool exist(){//��û���㼣
				return d!=-1;
			}
			int d;//����㼣����4����/��¥�� 
			void init(){
				d=-1;
			}
		};
	struct thing{
		int key;//0,KEY1,KEY2,KEY3,KEY4
		exit_sign exit_signs;
		mirror mirrors; 
		food foods;
		weapon_energy_edc wee;
		nest nst;  
		laser lsr;
		dart drt;
		spear spr;
		footprint fpt;//�����������Ʒ�ж� 
		int medicine;//ҩƷ�����ࣨ0��û�У� 
		bool treasure,lamp;//��û�б�����
		int changing_solid;//0,BOX,BARREL,TNT,CANDLE
		int liquid;//0,WATER,MAGMA
		void init(){
			key=medicine=treasure=lamp=changing_solid=liquid=0;
			exit_signs.init();mirrors.init();foods.init();wee.init();nst.init();lsr.init();drt.init();spr.init();fpt.init();
		}
		bool nothing(){//��ʾ�����Ƿ�û�ж��� 
			return !(key||exit_signs.exist||mirrors.exist||foods.exist||wee.exist||nst.exist||lsr.exist||drt.exist()||spr.exist||medicine||treasure||lamp||changing_solid||liquid); 
		}
	};
struct MAP{
	int maze;//WALL,SPACE,EXIT,DOOR1,DOOR2,DOOR3,DOOR4,UPSTAIR,DOWNSTAIR,LIFT
	bool door_state;//true������false���أ�ֻ�Ǹ�Կ���ż�¼�� 
	int floor;//NORMAL,HOLE 
	int player_enemy;//NOBODY,PLAYER,BUG,GHOST
	enemy emy;//������Ϣ 
	thing things;//��Ʒ 
	int in_player_sight;//������һ�ο������λ�õ�ʱ�䣨=game_time��������ڿ��õ�����game_time��������ڿ�������
}game_map[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1];
struct direction{//����ṹ�� 
	int d1,d2;//d1��ǰ��ƫd2�����ң����� 
};
	struct velocity{//�ٶȹ����壨v��
		double speed;//��λ����/1000���루����Ϊ0����
		int wait_time;//��1��ͣ���ٺ��루����Ϊ0����
		void tv(){//wait_time->speed
			speed=double(1000)/wait_time;
		}
		void vt(){//speed->wait_time
			if(speed>0.1) wait_time=1000/speed+0.5;//�������� 
			else wait_time=10000;//speedС��һ���̶Ⱦ�Ĭ��Ϊ0.1 
			if(wait_time<=0) wait_time=1;//��ֹ���� 
		}
	};
		struct life_injury{//���������˽ṹ��
			int change;//�����������û�У�1������ 2�����٣� 
			/*    0    1    2        3        4
			���� ���� ���� �������� �������� ... 
			*/
			int life;//����ֵ��0%~100%��%ʡ�ԣ�
			int hurt,recovery;//����ֵ���ظ�ֵ 
			void init(int lf){//��ʼ�� 
				life=lf;hurt=recovery=change=0;
			}
		};
		struct strength{//�����ṹ��
			bool change;//�����������û�� 
			double physical_strength;//����ֵ��0%~100%��%ʡ�ԣ�
			int recovery_time;//�ָ�ʱ�� 
			void init(){//��ʼ�� 
				physical_strength=100;change=1;recovery_time=400;
			}
		};
	struct vital_signs{//���������ṹ�� 
		life_injury lfin;//����������
		strength stg;//���� 
		void init(){//��ʼ�� 
			lfin.init(100);stg.init(); 
		}
	};
	struct score{//��������ָ��Ϸ����ʱ����Ҫ�õ�ָ�꣩ 
		int time_spent;//�ӳ����ѵ�ʱ�� 
		bool kc_change;//��ɱ���Ƿ�仯 
		int kill_count,shoot_times,shoot_hit_times;//��ɱ����ʹ��������������������е��˴��� 
		double hit_rate;//������ 
		int hurt_times;//���ܹ������� 
		void init(){//��ʼ�� 
			time_spent=kill_count=shoot_times=shoot_hit_times=hit_rate=hurt_times=0;
			kc_change=false;
		}
	};
		struct key{//Կ�׽ṹ��
			int door_keys[KINDS_OF_KEYS];//�洢��ͬ�����Կ��
			int treasure_keys;//�����������Կ��
			void init(){//��ʼ�� 
				memset(door_keys,0,sizeof(door_keys));
				treasure_keys=0;
			} 
		};
		struct stored_food{//��Ҵ洢��ʳ��ṹ��
			int food_cnt[KINDS_OF_FOOD][EFFECT_OF_FOOD];//�洢��ͬЧ����ʳ�� 
			void init(){//��ʼ�� 
				memset(food_cnt,0,sizeof(food_cnt));
			} 
		};
			struct laser_gun{
				int energy,last_time,cool_time;//����ǹ����������ʱ�䡢��ȴʱ�� 
				bool en_change;//�����������û��
				int kind,kd_cnt;//ģʽ��ģʽ���� 
				bool kd_change;//�����������û��
				int kd_energy[5];//ģʽ��Ӧ���������� 
				string kname[5];//ģʽ��
				void init(){
				 	energy=en_change=kind=0;last_time=500;cool_time=200;
				 	kd_cnt=5;
				 	kd_energy[0]=1;kd_energy[1]=3;kd_energy[2]=3;kd_energy[3]=4;kd_energy[4]=8;
				 	kname[0]="����";kname[1]="����";kname[2]="����";kname[3]="�Ĵ�ɨ��";kname[4]="���濪��";
				}
			};
			struct holding_spear{//�ֳ�ì
				int endurance;//�;ö� 
				void init(){
					endurance=100;
				}
			};
			struct throwing_dart{//����
				int num;//���� 
				void init(){
					num=0;
				}
			};
		struct weapon{//����
			int select_wpn,wcnt;//ѡ����������������� 
			//LSG,DART,SPR 
			bool sw_change;//�����������û��
			laser_gun lsg;
			throwing_dart drt;
			holding_spear hsr; 
			bool data_change,mode_change;//���������Ĳ�����Ϣ/ģʽ����û�� 
			void init(){
				select_wpn=LSG;wcnt=3;sw_change=data_change=mode_change=0; 
				lsg.init();drt.init();hsr.init();
			}
			void print1();//��ӡѡ����������Ͳ�����Ϣ���������;õȣ� 
			void print2();//��ӡ����ģʽ
			void print3();//��ӡʹ��˵�� 
		};
	struct item{//��Ʒ�ṹ�� 
		key keys;//Կ�� 
		stored_food foods;//ʳ�� 
		bool num_change;//��Ʒ�����Ƿ�仯 
		int select_number;//ѡ�е���Ʒ����Ʒ����ı��
		bool sn_change;//�����������û��  
		vector<int> item_lab;//��Ʒ������Ʒ���룩 
		bool il_change;//�����������û�� 
		weapon wpn;//���� 
		void init(){//��ʼ�� 
			keys.init();
			foods.init();
			wpn.init();
			num_change=0; 
			select_number=0;sn_change=il_change=0;
			item_lab.clear();
		}
		string item_name();//��Ʒ���� 
		int item_num();//��Ʒ���� 
		int item_endurance();//��Ʒ�;� 
		string item_method();//��Ʒʹ�÷��� 
		void print_item(int k);//������Ʒ�ı����ӡ��Ʒ 
		void print1();//��ӡ��Ʒ��ѡ�е���Ʒ��Ϣ 
		void print2();//��ӡ��Ʒ�����������Ʒ
		void print3();//��ѡ��������λ��
	};
struct player{//��� 
	position_3D pos;//����
	int d,color;//���������ʾ��0�������� 1����Ѫ�� 2�����˺� 3���䷽����������� 
	vital_signs vts;//�������� 
	score scr;//���� 
	velocity vlc;//�ٶ� 
	item items;//��Ʒ
	string name;//���� 
	void init();//��ʼ�� 
	/*����Ϊ��־����*/
	bool d_change,move;//�����Ƿ�ı䣬�Ƿ�ı���λ��
	bool up_down,ud_change,lst_ud,lst_enter,enter_nest;
	//�Ƿ��Զ���/��¥�ݻ��߽�/����Ѩ�ڣ�ǰ���������û�У��ϴ��Ƿ��Զ���/��¥�ݣ��ϴ��Ƿ��Զ���/����Ѩ��
	bool flash,use_weapon,enemy_move;//�Ƿ���˸���Ƿ�ʹ������������/������Ұ��Ƿ�ı���λ�� 
	int action_kind;//��Ҷ�����0������ 1������ 2��ѡ����Ʒ 3:�ı䷽��
	//RUN,WALK,CHOOSE_ITEM,CHANGE_WPN
	bool ak_change;//�����������û�� 
}player1; 
struct pos_player_see{//��ҿ��ü��ĸ��� 
	position_3D pos;//����
};
queue<position_3D> pos_in_sight,pos_change;
//������ڿ��ü����£���Ļ�϶�Ӧλ��û����ʾ��λ�á�����Ұ���Լ����µ�λ�� 
queue<position_2D> pos_lst_sight,pos_backup;
//�ϴ���Ļ����ʾ��λ�úͱ��� 
map<position_2D,string> screen_pos;//��Ļ�ϵ�λ����ʾ���ݵı��� 
map<position_2D,int> screen_z;//��Ļ��������Ҫ��ʾ��λ��������¥�㣨z���꣩ 
struct rectangle{//���νṹ�壨������Ļ����ȣ� 
	position_2D upper_left,lower_right;//���ϽǺ����½�
	void init(position_2D ul,position_2D lr){//��ʼ�� 
		upper_left=ul,lower_right=lr;
	} 
	void init(int x_1,int y_1,int x_2,int y_2){//��ʼ�� 
		upper_left=(position_2D){x_1,y_1},lower_right=(position_2D){x_2,y_2};
	}
	void output_frame(string c="*",int color=0x07,int kind=1){//������α߿� 
		for(int x=upper_left.x;x+c.size()-1<=lower_right.x;x+=c.size()){
			int y_1=upper_left.y,y_2=lower_right.y;
			gotoxy(x,y_1);
			SetConsoleTextAttribute(hout,color);
			cout<<c;
			gotoxy(x,y_2);
			SetConsoleTextAttribute(hout,color);
			cout<<c;
		}
		if(kind)
			for(int y=upper_left.y;y<=lower_right.y;y++){
				int x_1=upper_left.x,x_2=lower_right.x;
				gotoxy(x_1,y);
				SetConsoleTextAttribute(hout,color);
				cout<<c;
				gotoxy(x_2,y);
				SetConsoleTextAttribute(hout,color); 
				cout<<c;
			}
	}
}whole_screen,game_map_area,vital_signs_area,item_area;
//������Ļ����Ϸ��ͼ���������Ϣ���������Ʒ�� 
queue<position_3D> laser_beams;//���������� 
struct flying_dart{//���еķ���
	position_3D pos;//���� 
	int d,time;//���ڵķ���ÿ�ηɶ���ʱ�� 
	velocity vlc;//�ٶ�   
	void init(position_3D u,int dir){
		pos=u; 
		d=dir;time=game_time; 
		vlc.speed=7;vlc.vt();
	} 
}; 
queue<flying_dart> darts;//�����еķ��ڶ���
queue<position_3D> spears;//�ϴ���ʾ����Ļ��ì�Ķ��� 
struct bug{//���ӽṹ��
	position_3D pos;//���� 
	int d;//���� 
	velocity vlc;//�ٶ�  
	life_injury lfin;//����
	int lst_ud;//�ϴ�����¥ʱ�䣨��ֹ����һ��¥��� 
	bool change_pos;//�������ˣ��ı�λ�ø��� 
	bool update;//�Ƿ�Ҫ���£���С�������� 
	int enter_nest;//�ϴν�����Ѩ��ʱ�� 
	void init(position_3D u);
};
vector<bug> bugs;//��ţ�0~MAX_BUG_NUM-1
queue<int> Qbug;//���Ӷ��У���ţ� 
struct bug_nest{//���ӳ�Ѩ�ڽṹ��
	position_3D pos;//����
	life_injury lfin;//����
	bool destroy;//�Ƿ񱻴ݻ� 
	void init(position_3D u);
};
vector<bug_nest> bug_nests;//���ӵĳ�Ѩ��
queue<int> Qbug_nest;//���ӳ�Ѩ�ڶ��У���ţ� 
struct ghost{//��ṹ�� 
	position_3D pos;//���� 
	int d;//����4������¥��������Ѩ�ڣ� 
	velocity vlc;//�ٶ�  
	life_injury lfin;//����
	bool change_pos;//�������ˣ��ı�λ�ø��� 
	bool update;//�Ƿ�Ҫ���£���С�������� 
	void init(position_3D u);
};
vector<ghost> ghosts;//��ţ�0~MAX_GHOST_NUM-1
queue<int> Qghost;//����У���ţ� 
queue<position_3D> pos_dead;//ʬ����� 
struct barrel{//Ͱ�ṹ��
	position_3D pos;//���� 
	velocity vlc;//�ٶ� 
	bool stage;//״̬����/���� 
}; 
struct tnt{//ը���ṹ�� 
	position_3D pos;//����
	bool stage;//״̬����ֹ/��ȼ�� 
};
queue<barrel> barrels;//Ͱ����
queue<tnt> TNTs;//ը������
map<string,int> game_timer;//��Ϸ��ʱ�� 
map<string,bool> game_flag;//��Ϸ��־ 
int dx4[4]={0,1,0,-1};
int dy4[4]={-1,0,1,0};
//ǰ���ҡ����� 
int dx8[8]={0,1,1,1,0,-1,-1,-1};
int dy8[8]={-1,-1,0,1,1,1,0,-1};
//ǰ����ǰ���ҡ��Һ󡢺��������ǰ 
queue<position_3D> Q;
bool vst[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1];
int dis[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1];
int dis_to_exit[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1],dis_to_player[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1];
int mx_dis_to_player;
bool pos_in_room[MAX_LENGTH+1][MAX_WIDTH+1][MAX_HEIGHT*2+1];
vector<position_3D> pos_dis_to_player[(MAX_LENGTH-1)*(MAX_WIDTH-1)*(MAX_HEIGHT*2)];
vector<position_3D> pos_in_nest;
//BFSר��
int sum1[MAX_LENGTH+1][MAX_WIDTH+1],sum2[MAX_LENGTH+1][MAX_WIDTH+1];
//ǰ׺�� 
bool stair_exist[MAX_HEIGHT+1][2];//��¼ĳ��¥��û����0/��1¥��
//�Թ����� 
bool occlusion[4][360];
int cnt_visible[4]={360,360,360,360};
//��Ұ���� 
//���� 
void hideCursor(){//���ع�� 
	CONSOLE_CURSOR_INFO cursor_info1={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info1);
} 
void gotoxy(int x,int y){//�ƶ����
	if(x<0||x>MAX_SCREEN_LENGTH-1||y<0||y>MAX_SCREEN_WIDTH-1) return;
	COORD pos={short(x),short(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
position_2D GetConsoleCursor(){
	position_2D coordScreen={0,0}; //���λ��
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi)){
		coordScreen.x=csbi.dwCursorPosition.X;
		coordScreen.y=csbi.dwCursorPosition.Y;
	}
	return coordScreen; //���λ��
}
void SLEEP(int x){//��ʱ����λ�����룩 
	int time_now=clock();
	while(clock()-time_now<x); 
}
void CLEAR(){
	SetConsoleTextAttribute(hout,0x07);
	system("cls");
	SetConsoleTextAttribute(hout,0x07);
}
void wait_until(int key){
	while(1){
		if(_kbhit()){
			int c=_getch();
			if(c==key) return;
		}
	}
}
bool pos_in_area(int posx,int posy,int areax,int areay,int areal,int areaw){//�ж������Ƿ���ָ����Χ��
	//areal ��Χ�� areaw ��Χ�� 
	return posx>=areax&&posx<=areax+areal-1&&posy>=areay&&posy<=areay+areaw-1;
}
bool pos_in_area2(int posx,int posy,int areax1,int areay1,int areax2,int areay2,int kind=1){//�ж������Ƿ���ָ����Χ��
	//areal ��Χ�� areaw ��Χ�� 
	if(kind==1) return posx>=areax1&&posx<=areax2&&posy>=areay1&&posy<=areay2;
	if(kind==2) return posx>areax1&&posx<areax2&&posy>areay1&&posy<areay2;
	return false;
}
position_2D position_3Dto2D(position_3D pos){
	return (position_2D){pos.x,pos.y};
} 
position_3D position_2Dto3D(position_2D pos,int z){
	return (position_3D){pos.x,pos.y,z};
}
position_2D position_2Dtoscr(position_2D pos){
	return (position_2D){(pos.x-player1.pos.x)*2+MAX_SCREEN_LENGTH/2,(pos.y-player1.pos.y)+MAX_SCREEN_WIDTH/2};
} 
position_2D position_3Dtoscr(position_3D pos){
	return (position_2D){(pos.x-player1.pos.x)*2+MAX_SCREEN_LENGTH/2,(pos.y-player1.pos.y)+MAX_SCREEN_WIDTH/2};
} 
position_2D position_scrto2D(position_2D pos){
	return (position_2D){(pos.x-MAX_SCREEN_LENGTH/2)/2+player1.pos.x,pos.y-MAX_SCREEN_WIDTH/2+player1.pos.y};
}
position_3D position_scrto3D(position_2D pos,int z){
	return (position_3D){(pos.x-MAX_SCREEN_LENGTH/2)/2+player1.pos.x,pos.y-MAX_SCREEN_WIDTH/2+player1.pos.y,z};
}
//��ά����ά����Ļ��ͼ��ʾ���껥��ת�� 
direction ptp(position_3D a,position_3D b){//a��b��ʲô���� 
	direction ret;
	if(a.x>b.x) ret.d2=1;//��
	else ret.d2=3;//��
	if(a.y<b.y) ret.d1=0;//��
	else ret.d1=2;//��
	return ret; 
}
position_2D dtp2(position_2D pos,int dir,int d){
	switch(d){
		case 4:return (position_2D){pos.x+dx4[dir],pos.y+dy4[dir]};
		case 8:return (position_2D){pos.x+dx8[dir],pos.y+dy8[dir]};
		default:return (position_2D){-1,-1};
	}
}
position_3D dtp3(position_3D pos,int dir,int d){//��posλ�õ�d������ʲôλ�� 
	switch(d){
		case 4:return (position_3D){pos.x+dx4[dir],pos.y+dy4[dir],pos.z};
		case 8:return (position_3D){pos.x+dx8[dir],pos.y+dy8[dir],pos.z};
		default:return (position_3D){-1,-1,-1};
	}
}
int turn(int d,int op){//������ǰ����d����һ��������op����TURN_RIGHT,TURN_BACK,TURN_LEFT��
	switch(op){
		case TURN_RIGHT:return (d+1)%4;
		case TURN_BACK:return (d+2)%4;
		case TURN_LEFT:return (d+3)%4;
	}
	return d;
}
bool wall_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].maze==WALL;
}
bool space_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].maze==SPACE;
}
bool door_here(position_3D pos,int state=-1){
	return DOOR1<=game_map[pos.x][pos.y][pos.z].maze&&game_map[pos.x][pos.y][pos.z].maze<=DOOR4
	&&(state==-1||game_map[pos.x][pos.y][pos.z].door_state==state);
}
bool no_door_here(position_3D pos){
	return !((DOOR1<=game_map[pos.x][pos.y][pos.z].maze&&game_map[pos.x][pos.y][pos.z].maze<=DOOR4)
	||game_map[pos.x][pos.y][pos.z].maze==SPACE);//������Կ���źͳ����� 
}
bool stair_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].maze==UPSTAIR||game_map[pos.x][pos.y][pos.z].maze==DOWNSTAIR;
}
bool nobody_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].player_enemy==NOBODY;
}
bool player_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].player_enemy==PLAYER;
}
bool enemy_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].player_enemy==BUG||game_map[pos.x][pos.y][pos.z].player_enemy==GHOST;
}
bool nothing_here(position_3D pos){
	return game_map[pos.x][pos.y][pos.z].things.nothing();
}
bool no_mirror_around(position_3D pos){//���һ��λ�û᲻���뾵�����ڻ��غ�
	if(game_map[pos.x][pos.y][pos.z].things.mirrors.exist) return false; 
	for(int i=0;i<4;i++){
		position_3D v=dtp3(pos,i,4);
		if(pos_in_area2(v.x,v.y,1,1,length,width,2)
		&&game_map[v.x][v.y][v.z].things.mirrors.exist) return false;
	}
	return true;
}
int count_around_pos(position_3D pos,int d,int maze,int n=length,int m=width){
	int cnt=0;
	if(maze==STAIRS){
		cnt=count_around_pos(pos,d,UPSTAIR)+count_around_pos(pos,d,DOWNSTAIR);
		return cnt;
	}
	else if(maze==DOORS){
		for(int i=0;i<4;i++) cnt+=count_around_pos(pos,d,DOOR1+i);
		return cnt;
	}
	switch(d){
		case 4:
			if(maze==NEST){
				for(int i=0;i<4;i++){
					position_3D v=dtp3(pos,i,4);
					if(game_map[v.x][v.y][v.z].things.nst.exist&&game_map[v.x][v.y][v.z].maze==SPACE) cnt++;
				}
				return cnt;
			}
			for(int i=0;i<4;i++){
				position_3D v=dtp3(pos,i,4);
				if(pos_in_area2(v.x,v.y,1,1,n,m)&&game_map[v.x][v.y][v.z].maze==maze) cnt++;
			}
			break;
		case 8:
			if(maze==NEST){
				for(int i=0;i<4;i++){
					position_3D v=dtp3(pos,i,4);
					if(game_map[v.x][v.y][v.z].things.nst.exist&&game_map[v.x][v.y][v.z].maze==SPACE) cnt++;
				}
				return cnt;
			}
			for(int i=0;i<8;i++){
				position_3D v=dtp3(pos,i,8);
				if(pos_in_area2(v.x,v.y,1,1,n,m)&&game_map[v.x][v.y][v.z].maze==maze) cnt++;
			}
			break;
	}
	return cnt;
}
bool worth_relecting(position_3D pos){//�������λ�ö���������õ� 
	return space_here(pos)||stair_here(pos)||door_here(pos);
} 
bool in_room(position_3D pos){//λ����ĳ�������� 
	if(wall_here(pos)) return false;
	for(int i=0;i<4;i++){
		int j=turn(i,TURN_RIGHT);
		position_3D a=dtp3(pos,i,4),b=dtp3(pos,j,4);
		if(wall_here(a)) continue;
		if(wall_here(b)){
			i++;
			continue;
		}
		position_3D c=dtp3(a,j,4);//pos��i����j����iƫj�����λ��
		if(!wall_here(c)) return true; 
	}
	return false;
}
bool see_through(position_3D pos,int kind=1){//���߿��Դ������λ��
//kind=1�����ӣ�ֻҪ�ǿյأ�û���ӣ���¥�ݻ��ŵ������߾Ϳ��Դ���
//kind=2��б�ӣ�ֻҪ�ǿյػ�¥�ݻ��ŵ������߾Ϳ��Դ���
	if(kind==1) return space_here(pos)||stair_here(pos)||door_here(pos,1);
	else return space_here(pos)||stair_here(pos)||door_here(pos,1);
}
bool light_through(position_3D pos){//���߿��Դ��� 
	return space_here(pos)||stair_here(pos)||door_here(pos,1);
}
bool ghost_through(position_3D u){//����Դ���
	return (stair_here(u)||door_here(u,1)||space_here(u))&&nobody_here(u); 
} 
int gcd(int m,int n){//���Լ��
	if(m%n==0) return n;
	else return gcd(n,m%n);//շת����� 
}
int lcm(int m,int n){//��С������ 
	return m*n/gcd(m,n);//ԭ���Ļ�=���Լ��*��С������ 
} 
void nearest_RATIO(int a,int b,int l){//��ӽ��ķ�Χ���Ʊ�ֵ 
	if(a==0||b==0){
		cout<<a<<":"<<b;
		return;
	}
	int k1=1000,k2=1,min=k1*b-k2*a;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++){
			if(abs(i*b-j*a)<min&&i*b>=j*a){
				k1=i;k2=j;
				min=k1*b-k2*a;
			}
		}
	}
	cout<<k1<<":"<<k2;
}
int MHT_DIST(int x1,int y1,int x2,int y2){//�����پ��� 
	return abs(x1-x2)+abs(y1-y2);
}
int MHT_DIST2(int x1,int y1,int z1,int x2,int y2,int z2){//��ά�����پ���
	return  abs(x1-x2)+abs(y1-y2)+abs(z1-z2);
}
void CUT_LINE(int length,char x){//�ָ��� 
	for(;length>0;length--){
		cout<<x;		
	}
	cout<<endl;
}
void PRINT(rectangle area,int x,int y,string a,int times=1,int time=0,bool enter=false){
//�Զ���������ظ�����ʱ���Զ����У� 
	position_2D pos;
	pos.x=x,pos.y=y;
	for(int i=1;i<=times;i++){
		for(int j=0;j<int(a.size());j++,pos.x++){
			if(pos.x>=0&&pos.y>=0&&(int(a[j])>=0||int(a[j-1]>=0))) gotoxy(pos.x,pos.y);
			if(pos_in_area2(pos.x,pos.y
			,area.upper_left.x,area.upper_left.y,area.lower_right.x,area.lower_right.y,2)){
				cout<<a[j];
				SLEEP(time);
			}
		}
		if(enter) cout<<endl,pos.y++,pos.x=x;
	}
}
string connect_str(string a,string b,string c="",string d="",string e="",string f="",string g="",string h=""){
	//�����ַ��������8���� 
	string ret;
	ret+=a;ret+=b;ret+=c;ret+=d;ret+=e;ret+=f;ret+=g;ret+=h;
	return ret;
}
string int_to_str(int x,int y=0){//int����ת����string�ַ�����yλ����λ��ǰ��0���䣬y==0ʱ����ʹ��ǰ��0�� 
	string s="";string f=(x<0?"-":"");
	if(x==0){
		if(y==0) return "0"; 
		while(y--) s+='0';
		return s;
	}
	x=abs(x);
	while(x){
		s+=char(x%10+'0');
		x/=10;
	}
	reverse(s.begin(),s.end());
	while(y!=0&&int(s.size())<y) s='0'+s;
	s=f+s;
	return s;
}
string ll_to_str(ll x,ll y=0){//ll����ת����string�ַ�����yλ����λ��ǰ��0���䣬y==0ʱ����ʹ��ǰ��0�� 
	string s=(x<0?"-":"");
	if(x==0){
		if(y==0) return "0"; 
		while(y--) s+='0';
		return s;
	}
	x=abs(x);
	while(x){
		s+=char(x%10+'0');
		x/=10;
	}
	reverse(s.begin(),s.end());
	while(y!=0&&ll(s.size())<y) s='0'+s;
	return s;
}
string double_to_str(double x,int y=0){//double������ת����string�ַ���������yλС���� 
	if(y>15) y=15;
	bool negative=x<0;
	if(x<0) x=-x;
	ll a=x*pow(10,y)+0.5,b=a/pow(10,y),c=(b>0?log10(b):0)+1;
	string s=ll_to_str(a,c+y);
	if(c<ll(s.size())) s.insert(c,".");
	if(negative) s='-'+s;
	return s;
}
string to_time(int hour,int min,int sec,string k="HHСʱMM����SS��",bool leading0=false){
	min+=sec/60;sec%=60;hour+=min/60;min%=60;
	string ret=k,h=int_to_str(hour),m=int_to_str(min),s=int_to_str(sec);
	if(leading0){
		if(h.size()<2) h='0'+h;
		if(m.size()<2) m='0'+m;
		if(s.size()<2) s='0'+s;
	}
	int p1,p2,p3;
	p1=ret.find("HH");
	if(hour!=0) ret.replace(p1,2,h);
	else ret.erase(0,ret.find("MM")-p1);
	p2=ret.find("MM");
	if(min!=0) ret.replace(p2,2,m);
	else ret.erase(p2,ret.find("SS")-p2);
	p3=ret.find("SS");
	if(sec!=0||(hour==0&&min==0)) ret.replace(p3,2,s);
	else ret.erase(p3,ret.size()-p3);
	return ret;
}
string repeat_char(char c,int times){
	string s="";
	if(times<=0) return "";
	while(times--) s+=c;
	return s;
}
string repeat_str(string s,int times){
	string ret="";
	if(times<=0) return "";
	while(times--) ret+=s;
	return ret;
}
void formatted_output(int kind,rectangle area,int x,int y,int color,string s,int times=1,int time=0,bool enter=false){
//kind=1��������ӡ 2��PRINT��color=-1�����ϴ�һ����x=INF�������ϴκ��� 
	position_2D pos;
	if(x==INF) pos=GetConsoleCursor();
	else pos.x=x,pos.y=y;
	if(color!=-1) SetConsoleTextAttribute(hout,color);
	if(kind==1){
		for(int i=0;i<int(s.size());i++,pos.x++){
			if(pos.x>=0&&pos.y>=0&&(int(s[i])>=0||int(s[i-1])>=0)) gotoxy(pos.x,pos.y);
			if(pos_in_area2(pos.x,pos.y
			,area.upper_left.x,area.upper_left.y,area.lower_right.x,area.lower_right.y,2)){
				cout<<s[i];
			}
		}
	}
	else PRINT(area,pos.x,pos.y,s,times,time,enter);
}
void print_out_of_sight(){
	SetConsoleTextAttribute(hout,0x00);
	cout<<"  "; 
}
void print_body(){
	SetConsoleTextAttribute(hout,0xcf);
	cout<<"KO";
}
void print_player_enemy(int k,int id){
	player1.name+=" ";
	int c=player1.vts.lfin.change,c2=player1.d_change&&!player1.move,c3=0;
	if(id!=-1){
		if(k==BUG) c3=bugs[id].lfin.change;
		else c3=ghosts[id].lfin.change;
	}
	switch(k){
		case PLAYER:
			if(c2){
				SetConsoleTextAttribute(hout,0x9f);
				if(game_timer["���ͼ����˸"]<=game_time) game_timer["���ͼ����˸"]=game_time+100;
				player1.color=3;
				switch(player1.d){
					case 0:
						cout<<"��";
						break;
					case 1:
						cout<<"��";
						break;
					case 2:
						cout<<"��";
						break;
					case 3:
						cout<<"��";
						break;
				}
			}
			else if(c==1){
				SetConsoleTextAttribute(hout,0xaf);
				if(game_timer["���ͼ����˸"]<=game_time) game_timer["���ͼ����˸"]=game_time+1000;
				player1.color=1;
				cout<<player1.name.substr(0,2);
			}
			else if(c==2){
				SetConsoleTextAttribute(hout,0xcf);
				if(game_timer["���ͼ����˸"]<=game_time) game_timer["���ͼ����˸"]=game_time+100;
				player1.color=2;
				cout<<player1.name.substr(0,2);
			}
			else if(c==0&&game_timer["���ͼ����˸"]<=game_time){
				SetConsoleTextAttribute(hout,0xf9);
				player1.color=0;
				cout<<player1.name.substr(0,2);
			}
			break;
		case GHOST:
			if(c3==2) SetConsoleTextAttribute(hout,0xcf);
			else SetConsoleTextAttribute(hout,0x0f);
			cout<<"��";
			break;
		case BUG:
			if(c3==2) SetConsoleTextAttribute(hout,0xcf);
			else if(c3==1) SetConsoleTextAttribute(hout,0xaf);
			else SetConsoleTextAttribute(hout,0xfc);
			cout<<"��";
			break;
	}
	player1.name.erase(player1.name.size()-1,1);
}
void print_laser_beam(int d,int ipt){
	if(ipt) SetConsoleTextAttribute(hout,0xbf);
	else SetConsoleTextAttribute(hout,0xfb);
	if(ipt) cout<<"��";
	else if(d%2==0) cout<<"��";
	else cout<<"��";
}
void print_exit(int x,int y){
	SetConsoleTextAttribute(hout,0xaf);
	if(x==1||y==1) cout<<"E]";
	else cout<<"[E";
}
void print_wall(){
	SetConsoleTextAttribute(hout,0x77);
	cout<<"  ";
}
void print_space(){
	SetConsoleTextAttribute(hout,0xff);
	cout<<"  ";
}
void print_spear(int d,bool h){
	SetConsoleTextAttribute(hout,0xf6);
	if(h){
		switch(d){
			case 0:
				cout<<"��";
				break;
			case 1:
				cout<<"��";
				break;
			case 2:
				cout<<"��";
				break;
			case 3:
				cout<<"��";
				break;
		}
	}
	else if(d%2==0) cout<<"��";
	else cout<<"��";
}
void print_dart(int d,bool nest){
	if(nest) SetConsoleTextAttribute(hout,0xfc);
	else SetConsoleTextAttribute(hout,0xf9);
	switch(d){
		case 0:
			cout<<"��";
			break;
		case 1:
			cout<<"��";
			break;
		case 2:
			cout<<"��";
			break;
		case 3:
			cout<<"��";
			break;
	}
}
void print_key(int k,int light=0xf0){//light:�ƹ����ȣ�����ɫ����/ǳ��/���/�ڣ� 
	switch(k){
		case KEY1:
			SetConsoleTextAttribute(hout,light+0x0c);
			cout<<char(3);
			break;
		case KEY2:
			SetConsoleTextAttribute(hout,light+0x0c);
			cout<<char(4);
			break;
		case KEY3:
			SetConsoleTextAttribute(hout,light+0x00);
			cout<<char(5);
			break;
		case KEY4:
			SetConsoleTextAttribute(hout,light+0x00);
			cout<<char(6);
			break;
	}
	cout<<"="; 
}
void print_nest(int change,int life,int z){
	switch(change){
		case 0:
			SetConsoleTextAttribute(hout,0xfc);
			cout<<"��";
			break;
		case 2:
			SetConsoleTextAttribute(hout,0xcf);
			cout<<life<<" ";
			break;
	}
	/*
	SetConsoleTextAttribute(hout,0xfc);
	cout<<z<<" ";*/
}
void print_exit_signs(int k){
	SetConsoleTextAttribute(hout,0xfa);
	switch(k){
		case 0:
			cout<<"��";
			break;
		case 1:
			cout<<"��";
			break;
		case 2:
			cout<<"��";
			break;
		case 3:
			cout<<"��";
			break;
	}
}
void print_mirror(int side,int d){
	SetConsoleTextAttribute(hout,0xf0);
	if(side==1)
		switch(d){
			case 0:cout<<"��";break;
			case 1:cout<<"��";break;
			case 2:cout<<"��";break;
			case 3:cout<<"��";break;
		}
	else{
		if(d==0) cout<<"�u";
		else cout<<"�v";
		cout<<" ";
	}
} 
void print_food(int kind,int effect){
	switch(effect){
		case 1:SetConsoleTextAttribute(hout,0xf6);break;
		case 2:SetConsoleTextAttribute(hout,0xf5);break;
		case 3:SetConsoleTextAttribute(hout,0xf9);break;
	}
	if(kind==ADDL) cout<<"v"; 
	else cout<<char(3);
	cout<<char(24);
}
void print_weapon_energy_endurance(int num,int kind){
	switch(kind){
		case 0:SetConsoleTextAttribute(hout,0xfb);break;
		case 1:SetConsoleTextAttribute(hout,0xf6);break;
	}
	cout<<"+"<<num; 
}
void print_door(int state,int k){
	if(!state){//��û�� 
		switch(k){
			case DOOR1:
				SetConsoleTextAttribute(hout,0x6f);
				cout<<char(3);
				break;
			case DOOR2:
				SetConsoleTextAttribute(hout,0x6f);
				cout<<char(4);
				break;
			case DOOR3:
				SetConsoleTextAttribute(hout,0x6f);
				cout<<char(5);
				break;
			case DOOR4:
				SetConsoleTextAttribute(hout,0x6f);
				cout<<char(6);
				break;
		}
		cout<<"]";
	}
	else{//�ſ��� 
		switch(k){
			case DOOR1:
				SetConsoleTextAttribute(hout,0x2f);
				cout<<char(3);
				break;
			case DOOR2:
				SetConsoleTextAttribute(hout,0x2f);
				cout<<char(4);
				break;
			case DOOR3:
				SetConsoleTextAttribute(hout,0x2f);
				cout<<char(5);
				break;
			case DOOR4:
				SetConsoleTextAttribute(hout,0x2f);
				cout<<char(6);
				break;
		}
		cout<<" ";
	}
}
void print_stair(int k){
	SetConsoleTextAttribute(hout,0xf0);
	switch(k){
		case UPSTAIR:
			cout<<char(24)<<char(24);
			break;
		case DOWNSTAIR:
			cout<<char(25)<<char(25);
			break;
	}
}
void print_error_pos(int k){
	SetConsoleTextAttribute(hout,0x6f);
	cout<<"#"<<k;
}
string item::item_name(){
	int sn=player1.items.select_number;
	vector<int> &v=player1.items.item_lab;
	if(sn<0||sn>=v.size()) return "��"; 
	int k=v[sn];
	switch(k){
		case K1:case K2:case K3:case K4:return connect_str("Կ��",int_to_str(k-K1+1)); 
		case AS1:case AS2:case AS3:return connect_str("�����ظ� ",int_to_str(k-AS1+1),"��");
		case AL1:case AL2:case AL3:return connect_str("�����ָ� ",int_to_str(k-AL1+1),"��");
		case BX:return "����";
		case BL:return "ľͰ";
		case TT:return "TNTըҩ";
		case CE:return "����";
	}
}
int item::item_num(){
	int sn=player1.items.select_number;
	item &ITEM=player1.items;
	vector<int> &v=player1.items.item_lab;
	if(sn<0||sn>=v.size()) return 0; 
	int k=v[sn];
	switch(k){
		case K1:case K2:case K3:case K4:return ITEM.keys.door_keys[k-K1+KEY1-1]; 
		case AS1:case AS2:case AS3:case AL1:case AL2:case AL3:
			return ITEM.foods.food_cnt[(k-AS1)/EFFECT_OF_FOOD][(k-AS1)%EFFECT_OF_FOOD];
		case BX:return 0;
		case BL:return 0;
		case TT:return 0;
		case CE:return 0;
	}
	return 0;
}
int item::item_endurance(){
	int sn=player1.items.select_number;
	vector<int> &v=player1.items.item_lab;
	if(sn<0||sn>=v.size()) return 0; 
	int k=v[sn];
	switch(k){
		case K1:case K2:case K3:case K4:return 0; 
		case AS1:case AS2:case AS3:return 0;
		case AL1:case AL2:case AL3:return 0;
		case BX:return 0;
		case BL:return 0;
		case TT:return 0;
		case CE:return 0;
	}
	return 0;
}
string item::item_method(){
	int sn=player1.items.select_number;
	vector<int> &v=player1.items.item_lab;
	if(sn<0||sn>=v.size()) return "��"; 
	int k=v[sn];
	switch(k){
		case K1:case K2:case K3:case K4:return "�Զ�"; 
		case AS1:case AS2:case AS3:
		case AL1:case AL2:case AL3:
		case BX:case BL:case TT:case CE:return "����e��";
	}
	return "��"; 
}
void item::print_item(int k){
	switch(k){
		case K1:case K2:case K3:case K4:
			print_key(k-K1+KEY1);
			break;
		case AS1:case AS2:case AS3:case AL1:case AL2:case AL3:
			print_food((k-AS1)/EFFECT_OF_FOOD+ADDS,(k-AS1)%EFFECT_OF_FOOD+1);
			break;
		case BX:break;
		case BL:break;
		case TT:break;
		case CE:break;
		default:cout<<"ERROR";
	}
}
void item::print1(){
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+1;
	if(player1.action_kind==CHOOSE_ITEM)
		formatted_output(1,item_area,opos.x,opos.y,0xf0,"��Ʒ��");
	else
		formatted_output(1,item_area,opos.x,opos.y,0x0f,"��Ʒ��");
	opos.y++;
	formatted_output(1,item_area,opos.x,opos.y,0x0f,connect_str("������Ʒ��",item_name(),"          "));
	opos.x+=24;
	formatted_output(1,item_area,opos.x,opos.y,0x0f,connect_str("������",int_to_str(item_num()),"      "));
	opos.x+=9;
	formatted_output(1,item_area,opos.x,opos.y,0x0f,connect_str("�;ã�",int_to_str(item_endurance()),"      "));
	opos.x=item_area.upper_left.x+1;
	opos.y++;
	formatted_output(1,item_area,opos.x,opos.y,0x0f,connect_str("ʹ�÷�����",item_method(),"          "));
}
void item::print2(){
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+4;
	gotoxy(opos.x,opos.y); 
	vector<int> &v=player1.items.item_lab;
	for(int i=0;i<v.size();i++) print_item(v[i]);
	formatted_output(2,item_area,INF,0,0x00,"  ",MAX_SIZE_OF_ITEM_LAB-v.size());
}
void item::print3(){
	if(item::select_number<0) return;//ûѡ����Ʒ
	int sn=item::select_number;
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+5;
	formatted_output(2,item_area,opos.x,opos.y,0x00," ",MAX_SIZE_OF_ITEM_LAB*2);
	opos.x=item_area.upper_left.x+sn*2+1;opos.y=item_area.upper_left.y+5;//��Ƿ�������Ʒ���·� 
	formatted_output(1,item_area,opos.x,opos.y,0x0b,"��");
} 
string weapon_name(int sw){
	switch(sw){
		case LSG:return "����ǹ";
		case DART:return "����";
		case SPR:return "ì"; 
		default:return "ERROR";
	}
}
string weapon_mode(){
	weapon &wpn=player1.items.wpn;
	switch(wpn.select_wpn){
		case LSG:return wpn.lsg.kname[wpn.lsg.kind];
		case DART:return "����";
		case SPR:return "����"; 
		default:return "ERROR";
	}
}
string weapon_method(){
	weapon &wpn=player1.items.wpn;
	switch(wpn.select_wpn){
		case LSG:return "����S������";
		case DART:return "����S��Ͷ��";
		case SPR:return "�Զ�"; 
		default:return "ERROR";
	}
}
void weapon::print1(){
	int sw=weapon::select_wpn,col=0x0f;
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+6;
	switch(sw){
		case LSG:col=0x0b;break; 
		case DART:col=0x09;break; 
		case SPR:col=0x06;break;
	}
	if(player1.action_kind==CHANGE_WPN)
		formatted_output(1,item_area,opos.x,opos.y,0xf0,"������");
	else
		formatted_output(1,item_area,opos.x,opos.y,0x0f,"������");
	opos.y++;
	formatted_output(1,item_area,opos.x,opos.y,0x0f,"��ǰ������<");
	formatted_output(1,item_area,INF,INF,col,weapon_name(sw));
	formatted_output(1,item_area,INF,INF,0x0f,">    ");
	opos.x+=20;
	switch(sw){
		case LSG:
			formatted_output(1,item_area,opos.x,opos.y,0x0b
			,connect_str("����������",int_to_str(lsg.energy),"    "));
			break; 
		case DART:
			formatted_output(1,item_area,opos.x,opos.y,0x09
			,connect_str("������",int_to_str(drt.num),"        "));
			break; 
		case SPR:
			formatted_output(1,item_area,opos.x,opos.y,0x06
			,connect_str("�;öȣ�",int_to_str(hsr.endurance),"      "));
			break;
	}
} 
void weapon::print2(){
	int sw=weapon::select_wpn,col=0x0f;
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+8;
	switch(sw){
		case LSG:col=0x0b;break; 
		case DART:col=0x09;break; 
		case SPR:col=0x06;break;
	}
	formatted_output(1,item_area,opos.x,opos.y,col,connect_str("ģʽ��",weapon_mode(),"���ո���л���        "));
} 
void weapon::print3(){
	int sw=weapon::select_wpn,col=0x0f;
	position_2D opos;
	opos.x=item_area.upper_left.x+1;opos.y=item_area.upper_left.y+9;
	switch(sw){
		case LSG:col=0x0b;break; 
		case DART:col=0x09;break; 
		case SPR:col=0x06;break;
	}
	formatted_output(1,item_area,opos.x,opos.y,col,connect_str("ʹ�÷�����",weapon_method(),"        "));
} 
int interconnection_distance(position_3D s,position_3D e,int max_dis,position_3D no_reach){
	//��s��e�Ĳ��о��루BFS�� 
	memset(vst,0,sizeof(vst));
	memset(dis,0,sizeof(dis));
	while(!Q.empty()) Q.pop();
	vst[s.x][s.y][s.z]=1;
	dis[s.x][s.y][s.z]=0;
	Q.push(s);
	while(!Q.empty()){
		position_3D u=Q.front();Q.pop();
		if(u==e) return dis[u.x][u.y][u.z];
		if(dis[u.x][u.y][u.z]>max_dis) return -1;
		for(int i=0;i<4;i++){
			position_3D v=dtp3(u,i,4);
			if(v.x>=1&&v.x<=length&&v.y>=1&&v.y<=width&&v.z>=1&&v.z<=height
				&&!(vst[v.x][v.y][v.z]&&v!=no_reach)
				&&game_map[v.x][v.y][v.z].maze!=WALL
				&&!(DOOR1<=game_map[v.x][v.y][v.z].maze&&game_map[v.x][v.y][v.z].maze<=DOOR4)
				){
				if(game_map[v.x][v.y][v.z].maze==UPSTAIR) v.z++;
				else if(game_map[v.x][v.y][v.z].maze==DOWNSTAIR) v.z--;
				vst[v.x][v.y][v.z]=1;
				dis[v.x][v.y][v.z]=dis[u.x][u.y][u.z]+1;
				Q.push(v);
			}
		}
	}
	return -1; 
}
bool useful_door(position_2D u,int z,int dis){//�ж����Ƿ�����
	position_2D a,b;//��ǰ���ź��λ��
	a.x=0;b.x=0;
	for(int i=0;i<4;i++){
		position_2D v=dtp2(u,i,4);
		if(pos_in_area2(v.x,v.y,1,1,length,width,2)&&space_here(position_2Dto3D(v,z))){
			if(a.x==0) a=v;
			else{
				b=v;
				break;
			}
		}
	}
	if(a.x==0||b.x==0) return false;//���λ�ò������������յ�
	position_3D no_reach={-1,-1,-1};
	int dmaze=game_map[u.x][u.y][z].maze;
	if(game_map[u.x][u.y][z].maze!=WALL) game_map[u.x][u.y][z].maze=WALL;//no_reach=position_2Dto3D(u,z);
	int connect=interconnection_distance((position_3D){a.x,a.y,z},(position_3D){b.x,b.y,z},dis,no_reach);
	game_map[u.x][u.y][z].maze=dmaze;
	if(connect==-1||connect>=dis) return true;
	return false;
}
bool cmpa(int a,int b){//�Ƕ�С�� 
	return (a-b+360)%360>180;
} 
int calc_angle(position_3D a,position_3D b){//a->b���㷽��� 
	position_3D c=b;c.x-=a.x;c.y-=a.y;
	int angle=(c.x==0?90:atan(1.0*abs(c.y)/abs(c.x))/PI*180);
	//cout<<abs(c.y)<<"/"<<abs(c.x)<<"->"<<angle<<endl;
	if(c.x<0){
		if(c.y>0) angle=180-angle;
		else angle+=180;
	}
	else if(c.y<0) angle=360-angle;
	return angle;
}
bool invisible(position_3D p,position_3D pos){//pos������pλ�� 
	//if(abs(p.x-pos.x)<=1||abs(p.y-pos.y)<=1) return false;
	//cout<<"?"<<p.x<<","<<p.y<<endl;
	for(int i=0;i<4;i++){
		//cout<<i<<":"<<cnt_visible[i]<<endl;
		if(!cnt_visible[i]) continue;
		position_3D u=pos;u.x+=bool(i&1);u.y+=bool(i&2);//վ 
		//cout<<"u "<<u.x<<","<<u.y<<endl;
		int mn=-1,mx=-1; 
		for(int j=0;j<4;j++){
			position_3D v=p;v.x+=bool(j&1);v.y+=bool(j&2);//�� 
			if(u==v) continue;
			int a=calc_angle(u,v);
			//cout<<"v "<<v.x<<","<<v.y<<":"<<a<<endl;
			if(mn==-1||cmpa(a,mn)) mn=a;//cout<<mn<<"<"<<a<<endl,
			if(mx==-1||cmpa(mx,a)) mx=a;//cout<<a<<"<"<<mx<<endl,
		}
		//cout<<mn<<"->"<<mx<<endl;
		for(int j=mn;j!=(mx+1)%360;j=(j+1)%360)
			if(!occlusion[i][j]) return false;
	}
	return true; 
}
void mark_occlusion(position_3D p,position_3D pos){//pλ���ڵ���pos���� 
	//cout<<"��"<<p.x<<","<<p.y<<endl;
	for(int i=0;i<4;i++){
		//cout<<i<<":"<<cnt_visible[i]<<endl;
		if(!cnt_visible[i]) continue;
		position_3D u=pos;u.x+=bool(i&1);u.y+=bool(i&2);//վ 
		//cout<<"u "<<u.x<<","<<u.y<<endl;
		int mn=-1,mx=-1; 
		for(int j=0;j<4;j++){
			position_3D v=p;v.x+=bool(j&1);v.y+=bool(j&2);//�� 
			if(u==v) continue;
			int a=calc_angle(u,v);
			//cout<<"v "<<v.x<<","<<v.y<<":"<<a<<endl;
			if(mn==-1||cmpa(a,mn)) mn=a;//cout<<mn<<"<"<<a<<endl,
			if(mx==-1||cmpa(mx,a)) mx=a;//cout<<a<<"<"<<mx<<endl,
		}
		//cout<<mn<<"->"<<mx<<endl;
		for(int j=mn;j!=(mx+1)%360;j=(j+1)%360)
			if(!occlusion[i][j]) occlusion[i][j]=1,cnt_visible[i]--;//,cout<<j<<","
		//cout<<endl;
	}
}
void prd(){
	gotoxy(0,40);
	for(int j=0;j<360;j++) printf("%4d",j);
	//cout<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<360;j++) printf("%4d",occlusion[i][j]);
		//cout<<endl;
	}
}
bool rand_error(int max,int min){
	if(max<min){
		formatted_output(1,whole_screen,30,30,0x0c,"�����������д���ˣ���");
		return true;
	}
	return false;
}
int RAND(int max,int min){//����� 
	if(rand_error(max,min)) swap(max,min);
	int num=rand()%(max-min+1)+min;
	return num;
}
bool RAND_BOOL(int a){//�����������ֵ 
	int num=rand()%100+1;
	if(num<=a) return 1;
	else return 0;
}
int RAND_ALTO(int max,int min,int a){//Ⱥ������� 
	if(rand_error(max,min)) swap(max,min);
	int k=min;
	for(int i=1;i<=max-min+1;i++){
		if(RAND_BOOL(a)) k++;
	}
	return k;
}
void RAND_EXIT_AROUND_GAME_MAP(int cnt,int l=length,int w=width,int h=height){//��ͼ����� 
	vector<position_3D> v;//�洢���ܻᱻѡ����λ��
	/* l=5,w=5
	0��ʾ�����ܻᱻѡ����1��ʾ�п��ܻᱻѡ�� 
		(1,1)==>01110<==(l,1)
				10001
				10001
				10001
    	(1,w)==>01110<==(l,w)
 	��Ȼ��ÿ��¥��Ҫ���ȥ
 	���⣬ѡ����λ�ã�����Ҫ��һ����ǽ�������ڣ�������һ��ͨ��������ô�ӳ�ȥ����*/ 
	for(int z=1;z<=height+h;z++){//�ҳ����п������ó��ڵ�λ�� 
		for(int x=2;x<l;x++){
			if(game_map[x][2][z].maze!=WALL)
				v.push_back((position_3D){x,1,z});
			if(game_map[x][w-1][z].maze!=WALL)
				v.push_back((position_3D){x,w,z});
		}
		for(int y=2;y<w;y++){
			if(game_map[2][y][z].maze!=WALL)
				v.push_back((position_3D){1,y,z});
			if(game_map[l-1][y][z].maze!=WALL)
				v.push_back((position_3D){l,y,z});
		}
	}
	for(int i=1;i<=cnt&&v.size()>0;i++){
		int j=RAND(v.size()-1,0);
		position_3D u=v[j];
		swap(v[j],v[v.size()-1]);v.pop_back();
		game_map[u.x][u.y][u.z].maze=EXIT;
		Q.push(u);vst[u.x][u.y][u.z]=1;//Ϊ���ڱ��Ƶ�������׼�� 
	} 
}
int RAND_MIRROR_DIRECTION(position_3D pos){//���ѡ���ӷ��� 
	vector<int> v;//�洢���ܻᱻѡ���ľ��ӳ��� 
	/*  				0��	   1��	  2��	 3�� 
	�����ĸ������λ��  1��2�� 2��3�� 3��0�� 0��1�� 
	*/
	for(int i=0;i<4;i++){
		int j=turn(i,TURN_RIGHT),k=turn(i,TURN_LEFT);
		position_3D a=dtp3(pos,i,4),b=dtp3(pos,j,4);
		if(worth_relecting(a)&&worth_relecting(b)) v.push_back(k);
	}
	if(v.size()>0) return v[RAND(v.size()-1,0)];
	return -1;
}
position_3D RAND_PLAYER_IN_GAME_MAP(int l=length,int w=width,int h=height){
//����Ϸ��ͼ�����ѡ����ҵ�λ�ã��յ����ˣ�Զ����ڣ�������·�� 
	vector<position_3D> v;//�洢���ܻᱻѡ����λ��
	int mx_dis=0;
	for(int z=1;z<=h;z++)
		for(int y=2;y<w;y++)
			for(int x=2;x<l;x++){
				position_3D u;
				u.x=x;u.y=y;u.z=z;
				if(space_here(u)&&nobody_here(u)&&nothing_here(u)
					&&count_around_pos(u,4,WALL)<=3)
						mx_dis=max(mx_dis,dis_to_exit[x][y][z]);
			}
	for(int z=1;z<=h;z++){
		for(int y=2;y<w;y++){
			for(int x=2;x<l;x++){
				position_3D u;
				u.x=x;u.y=y;u.z=z;
				if(space_here(u)&&nobody_here(u)&&nothing_here(u)
					&&count_around_pos(u,4,WALL)<=3
					&&mx_dis-dis_to_exit[x][y][z]<=pos_in_room[x][y][z]*5) v.push_back(u); 
			}
		}
	}
	if(v.size()>0) return v[RAND(v.size()-1,0)];
	return (position_3D){2,2,1};
}
//���ú��� 
void screen_partition();
void welcome_player();
void ask_player();
void initial();
void game();
void win();
void lose();
void detail();
void end();
void ask_try_again();
void player_calculate_vision1();
void player_calculate_vision2(position_3D pos=player1.pos);
//�������� 
int main(){//������Ʒ��������Ʒ 
	srand(time(0));
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	//��Ļ����������������������ɫ�� 
	hideCursor();//���������� 
	screen_partition();
	welcome_player();CLEAR();
	while(1){
		ask_player();CLEAR();
		initial();//�����ʼ����ͽ�����Ϸ������ģ��������� 
		game();CLEAR();
		if(game_success) win();
		else lose();
		detail();
		ask_try_again();
		CLEAR();
		if(!start_again){
			end();
			break;
		}
	}
	return 0;
}
//������
void screen_partition(){//��Ļ���� 
	whole_screen.init(0,0,MAX_SCREEN_LENGTH-1,MAX_SCREEN_WIDTH-1);
	int midx=MAX_SCREEN_LENGTH/2,midy=MAX_SCREEN_WIDTH/2;//��Ļ����ʾ����Ϸ��ͼ���ĵ㣨��ҵ�λ�ã� 
	game_map_area.init(max(0,midx-midy*2),0,min(MAX_SCREEN_LENGTH-1,midx+midy*2),MAX_SCREEN_WIDTH-1);
	//����ҵ�λ��Ϊ���ĵ�һ��������������������Ϊ��Ϸ��ͼ��Χ��97*48�������¿���Ļ�߽�
	vital_signs_area.init(0,0,game_map_area.upper_left.x,MAX_SCREEN_WIDTH-1);
	//�����Ϣ�������
	item_area.init(game_map_area.lower_right.x,0,MAX_SCREEN_LENGTH-1,MAX_SCREEN_WIDTH-1);
	//�����Ʒ�����ұ�
}
void welcome_player(){
	//��ǰҪ���� 
	formatted_output(2,whole_screen,40,20,0x07,"��ӭ������Ұ���٣�",1,150);
	formatted_output(2,whole_screen,40,21,-1,"���ߣ�wqx",1,150);
	formatted_output(2,whole_screen,40,22,0x0e,"���»س��Կ�ʼ",1,150);
	wait_until(PRESS_KEY_ENTER);
	formatted_output(2,whole_screen,40,22,0x0b,"��Ϸ������......",1,100);
}
void ask_player(){
	//��ǰҪ����
	formatted_output(2,whole_screen,40,20,0x07,"��������ʲô���֣���",1,100);
	formatted_output(2,whole_screen,INF,0,0x0e,"���ð����ո�ͱ�����",1,100);
	formatted_output(2,whole_screen,INF,0,0x07,"��",1,100);
	cin>>player1.name; 
	formatted_output(2,whole_screen,40,21,0x07,"�������ͼ����ߣ�",1,100);
	formatted_output(2,whole_screen,INF,0,0x0e,
	connect_str("4<=��<=",int_to_str(MAX_LENGTH),"��4<=��<=",int_to_str(MAX_WIDTH)
	,"��1<=��<=",int_to_str(MAX_HEIGHT)),
	1,100);
	formatted_output(2,whole_screen,INF,0,0x07,"������",1,100);
	formatted_output(2,whole_screen,INF,0,0x0e,"�ո�",1,100);
	formatted_output(2,whole_screen,INF,0,0x07,"�ָ�����",1,100);
	cin>>length>>width>>height;
	formatted_output(2,whole_screen,40,22,0x0b,"��Ϸ��ʼ��......",1,100);
}
	void all_assigned(){
		game_end=game_success=false;
		hideCursor();
		for(int z=1;z<=height*2;z++){
			for(int y=1;y<=width;y++){
				for(int x=1;x<=length;x++){
					MAP &POS=game_map[x][y][z];
					POS.floor=NORMAL;
					POS.maze=WALL;
					POS.door_state=false;
					POS.player_enemy=NOBODY;
					POS.emy.init(); 
					POS.things.init();
					POS.in_player_sight=-1;
				}
			}
		}
		mx_dis_to_player=0;
		memset(pos_in_room,0,sizeof(pos_in_room));
		
		cnt_notWALL=cnt_SPACE=cnt_STAIRS=0;
		
		mx_dis_to_player=0;
		for(int i=0;i<(MAX_LENGTH-1)*(MAX_WIDTH-1)*(MAX_HEIGHT*2);i++) pos_dis_to_player[i].clear();
		
		player1.up_down=0;
		while(!pos_in_sight.empty()) pos_in_sight.pop();
		while(!pos_lst_sight.empty()) pos_lst_sight.pop();
		while(!pos_backup.empty()) pos_backup.pop();
		screen_pos.clear();screen_z.clear();
		
		for(int i=0;i<4;i++) cnt_visible[i]=360;
		memset(occlusion,0,sizeof(occlusion));
		
		game_timer.clear(); 
		game_flag.clear();
		
		bugs.clear();ghosts.clear();
		while(!Qbug.empty()) Qbug.pop();
		while(!Qbug_nest.empty()) Qbug_nest.pop();
		while(!Qghost.empty()) Qghost.pop();
		
		while(!laser_beams.empty()) laser_beams.pop();
		while(!darts.empty()) darts.pop();
		while(!spears.empty()) spears.pop();
	}
			void print_game_map_pos(position_3D pos,int kind=1){//kind=1�����������ù�� 2�����������ù�� 
				int x=pos.x,y=pos.y,z=pos.z
				,px=(x-player1.pos.x)*2+MAX_SCREEN_LENGTH/2,py=(y-player1.pos.y)+MAX_SCREEN_WIDTH/2;
				if(kind==1&&(px<=game_map_area.upper_left.x||px+1>=game_map_area.lower_right.x
				||py<=game_map_area.upper_left.y||py>=game_map_area.lower_right.y)) return;
				if(kind==1) gotoxy(px,py);
				MAP &POS=game_map[x][y][z];
				thing &THING=POS.things;
				if(POS.emy.dead&&POS.emy.body_disapp>game_time)//��ʬ��
					print_body(); 
				else if(!nobody_here(pos))//��������� 
					print_player_enemy(POS.player_enemy,POS.emy.id);
				else if(THING.drt.exist())//�з���
					print_dart(THING.drt.prd(),THING.nst.exist); 
				else if(THING.nst.exist&&THING.nst.id!=-1){//�г�Ѩ��
					nest &NST=THING.nst;
					bug_nest bns=bug_nests[NST.id];
					int c=bns.lfin.change,lf=bns.lfin.life,z=bns.pos.z;
					print_nest(c,lf,z); 
				}
				else if(THING.lsr.exist){//�м�����
					int d=THING.lsr.laser_beam;
					position_3D u=pos;u.x+=dx4[d];u.y+=dy4[d];
					MAP &NPOS=game_map[u.x][u.y][u.z];
					print_laser_beam(d,!light_through(u)||POS.things.mirrors.exist); 
				}
				else if(POS.maze==EXIT)//�����ǳ��� 
					print_exit(x,y);
				else if(POS.maze==WALL)//�����Ƕ�ǽ 
					print_wall();
				else if(space_here(pos)){//�����ǿյ� 
					if(POS.things.nothing())//ɶ������û�� 
						print_space();
					else{//�������Щ���� 
						if(THING.spr.exist)//��ì 
							print_spear(THING.spr.d,THING.spr.head);
						else if(THING.key)//��Կ�� 
							print_key(THING.key);
						else if(THING.exit_signs.exist)//��ָ����ڵı���
							print_exit_signs(THING.exit_signs.dir);
						else if(THING.mirrors.exist){//�о��� 
							mirror &MIRROR=THING.mirrors;
							print_mirror(MIRROR.side,MIRROR.dir);
						}
						else if(THING.foods.exist){//��ʳ��
						    food &FOOD=THING.foods;
							print_food(FOOD.kind,FOOD.effect);
						}
						else if(THING.wee.exist)//����������/�;öȻظ� 
							print_weapon_energy_endurance(THING.wee.num,THING.wee.kind);
					}
				}
				else if(DOOR1<=POS.maze&&POS.maze<=DOOR4)//ò�������� 
					print_door(POS.door_state,POS.maze);
				else if(POS.maze==UPSTAIR||POS.maze==DOWNSTAIR)//������¥�� 
					print_stair(POS.maze);
				else print_error_pos(POS.maze);
				cout<<endl;
			}
		string screen_display_coding(position_3D pos){//��Ļ������� 
			string col,out,ret;//�����ɫ���ַ�������ֵ 
			int x=pos.x,y=pos.y,z=pos.z;
			MAP &POS=game_map[x][y][z];
			thing &THING=POS.things;
			if(POS.emy.dead&&POS.emy.body_disapp>game_time){//��ʬ��
				col="cf";//SetConsoleTextAttribute(hout,0xcf);
				out="KO";//cout<<"KO;
			}
			else if(!nobody_here(pos)){//��������� 
				bool lsr=THING.lsr.exist;int id=POS.emy.id;
				int c=player1.vts.lfin.change,c2=player1.d_change&&!player1.move,c3=0;
				if(id!=-1){
					if(POS.player_enemy==BUG) c3=bugs[id].lfin.change;
					else c3=ghosts[id].lfin.change;
				}
				switch(POS.player_enemy){
					case PLAYER:
						player1.name+=" ";
						if(c2){
							col="9f";//SetConsoleTextAttribute(hout,0x9f);
							switch(player1.d){
								case 0:out="��";//cout<<"��";
									break;
								case 1:out="��";//cout<<"��";
									break;
								case 2:out="��";//cout<<"��";
									break;
								case 3:out="��";//cout<<"��";
									break;
							}
						}
						else if(c==1) col="af",out=player1.name.substr(0,2);//SetConsoleTextAttribute(hout,0xaf);
						else if(c==2) col="cf",out=player1.name.substr(0,2);//SetConsoleTextAttribute(hout,0xcf);
						else if(c==0&&game_timer["���ͼ����˸"]<=game_time) col="f9",out=player1.name.substr(0,2);
						//SetConsoleTextAttribute(hout,0xf9);
						//cout<<player1.name.substr(0,2);
						player1.name.erase(player1.name.size()-1,1);
						break;
					case GHOST:
						if(c3==2) col="cf";//SetConsoleTextAttribute(hout,0xcf);
						else col="0f";//SetConsoleTextAttribute(hout,0x0f);
						out="��";//cout<<"��";
						break;
					case BUG:
						if(c3==2) col="cf";//SetConsoleTextAttribute(hout,0xcf);
						else if(c3==1) col="af";//SetConsoleTextAttribute(hout,0xaf);
						else col="fc";//SetConsoleTextAttribute(hout,0xfc);
						out="��";//cout<<"��";
						break;
				}
			}
			else if(THING.drt.exist()){//�з���
				if(THING.nst.exist) col="fc";//SetConsoleTextAttribute(hout,0xfc);
				else col="f9";//SetConsoleTextAttribute(hout,0xf9);
				SetConsoleTextAttribute(hout,0xf9);
				switch(THING.drt.prd()){
					case 0:
						out="��";//cout<<"��";
						break;
					case 1:
						out="��";//cout<<"��";
						break;
					case 2:
						out="��";//cout<<"��";
						break;
					case 3:
						out="��";//cout<<"��";
						break;
				} 
			} 
			else if(THING.nst.exist&&THING.nst.id!=-1){//�г�Ѩ��
				nest &NST=THING.nst;
				bug_nest bns=bug_nests[NST.id];
				int c=bns.lfin.change,lf=bns.lfin.life;
				switch(c){
					case 0:
						col="fc";//SetConsoleTextAttribute(hout,0xfc);
						out="��";//cout<<"��";
						break;
					case 2:
						col="fc";//SetConsoleTextAttribute(hout,0xcf);
						out=int_to_str(lf,0);//cout<<fixed<<setprecision(0)<<lf<<" ";
						break;
				}
			}
			else if(THING.lsr.exist){//�м�����
				int d=THING.lsr.laser_beam;
				position_3D u=pos;u.x+=dx4[d];u.y+=dy4[d];
				MAP &NPOS=game_map[u.x][u.y][u.z];
				bool ipt=!light_through(u)||POS.things.mirrors.exist;
				if(ipt) col="bf";//SetConsoleTextAttribute(hout,0xbf);
				else col="fb";//SetConsoleTextAttribute(hout,0xfb);
				if(ipt) out="��";//cout<<"��";
				else if(d%2==0) out="��";//cout<<"��";
				else out="��";//cout<<"��";
			}
			else if(POS.maze==EXIT){
				col="af";//SetConsoleTextAttribute(hout,0xaf);
				if(x==1||y==1) out="E]";//cout<<"E]";
				else out="[E";//cout<<"[E";
			}
			else if(POS.maze==WALL){//�����Ƕ�ǽ 
				col="77";//SetConsoleTextAttribute(hout,0x77);
				out="  ";//cout<<"  ";
			}
			else if(space_here(pos)){//�����ǿյ� 
				if(POS.things.nothing()){//ɶ������û�� 
					col="ff";//SetConsoleTextAttribute(hout,0xff);
					out="  ";//cout<<"  ";
				}
				else{//�������Щ���� 
					if(THING.spr.exist){//��ì 
						int d=THING.spr.d,h=THING.spr.head;
						col="f6";//SetConsoleTextAttribute(hout,0xf6);
						if(h)
							switch(d){
								case 0:
									out="��";//cout<<"��";
									break;
								case 1:
									out="��";//cout<<"��";
									break;
								case 2:
									out="��";//cout<<"��";
									break;
								case 3:
									out="��";//cout<<"��";
									break;
							}
						else if(d%2==0) out="��";//cout<<"��";
						else out="��";//cout<<"��";
					}
					else if(THING.key){//��Կ�� 
						switch(THING.key){
							case KEY1:
								col="fc";//SetConsoleTextAttribute(hout,0xfc);
								out=char(3);//cout<<char(3);
								break;
							case KEY2:
								col="fc";//SetConsoleTextAttribute(hout,0xfc);
								out=char(4);//cout<<char(4);
								break;
							case KEY3:
								col="f0";//SetConsoleTextAttribute(hout,0xf0);
								out=char(5);//cout<<char(5);
								break;
							case KEY4:
								col="f0";//SetConsoleTextAttribute(hout,0xf0);
								out=char(6);//cout<<char(6);
								break;
						}
						out+="=";//cout<<"="; 
					}
					else if(THING.exit_signs.exist){//��ָ����ڵı���
						col="fa";//SetConsoleTextAttribute(hout,0xfa); 
						switch(THING.exit_signs.dir){
							case 0:
								out=char(24);//"24";//cout<<char(24);
								break;
							case 1:
								out=char(26);//"26";//cout<<char(26);
								break;
							case 2:
								out=char(25);//"25";//cout<<char(25);
								break;
							case 3:
								out=char(27);//"27";//cout<<char(27);
								break;
						}
						out+="]";//cout<<"]"; 
					}
					else if(THING.mirrors.exist){//�о��� 
						col="f0";//SetConsoleTextAttribute(hout,0xf0);
						mirror &MIRROR=THING.mirrors;
						if(MIRROR.side==1)
							switch(MIRROR.dir){
								case 0:
									out="��";//cout<<"��";
									break;
								case 1:
									out="��";//cout<<"��";
									break;
								case 2:
									out="��";//cout<<"��";
									break;
								case 3:
									out="��";//cout<<"��";
									break;
							}
						else{
							if(MIRROR.dir==0){
								//if(d1==2&&d2==1) cout<<"��";
								//else cout<<"��";
								out="�u";//cout<<"�u";
							}
							else{
								//if(d1==2&&d2==3) cout<<"��";
								//else cout<<"��";
								out="�v";//cout<<"�v";
							}
							out+=" ";//cout<<" ";
						}
					}
					else if(THING.foods.exist){//��ʳ��
						food &FOOD=THING.foods;
						switch(FOOD.effect){
							case 1:col="f6";//SetConsoleTextAttribute(hout,0xf6);
								break;
							case 2:col="f5";//SetConsoleTextAttribute(hout,0xf5);
								break;
							case 3:col="f9";//SetConsoleTextAttribute(hout,0xf9);
								break;
						}
						if(FOOD.kind==ADDL) out="v";//cout<<"v"; 
						else out=char(3);//cout<<char(3);
						out+="��";//cout<<"��";
					}
					else if(THING.wee.exist){//����������/�;öȻظ�
						int num=THING.wee.num,kind=THING.wee.kind;
						switch(kind){
							case 0:col="fb";//SetConsoleTextAttribute(hout,0xfb);
								break;
							case 1:col="f6";//SetConsoleTextAttribute(hout,0xf6);
								break;
						}
						out=connect_str("+",int_to_str(num));//cout<<"+"<<num; 
					}
				}
			}
			else if(DOOR1<=POS.maze&&POS.maze<=DOOR4&&!POS.door_state){//ò�������� 
				switch(POS.maze){
					case DOOR1:
						col="6f";//SetConsoleTextAttribute(hout,0x6f);
						out=char(3);//cout<<char(3);
						break;
					case DOOR2:
						col="6f";//SetConsoleTextAttribute(hout,0x6f);
						out=char(4);//cout<<char(4);
						break;
					case DOOR3:
						col="6f";//SetConsoleTextAttribute(hout,0x6f);
						out=char(5);//cout<<char(5);
						break;
					case DOOR4:
						col="6f";//SetConsoleTextAttribute(hout,0x6f);
						out=char(6);//cout<<char(6);
						break;
				}
				out+="]";//cout<<"]";
			}
			else if(DOOR1<=POS.maze&&POS.maze<=DOOR4&&POS.door_state){//ò���ſ��� 
					switch(POS.maze){
						case DOOR1:
							col="2f";//SetConsoleTextAttribute(hout,0x2f);
							out=char(3);//cout<<char(3);
							break;
						case DOOR2:
							col="2f";//SetConsoleTextAttribute(hout,0x2f);
							out=char(4);//cout<<char(4);
							break;
						case DOOR3:
							col="2f";//SetConsoleTextAttribute(hout,0x2f);
							out=char(5);//cout<<char(5);
							break;
						case DOOR4:
							col="2f";//SetConsoleTextAttribute(hout,0x2f);
							out=char(6);//cout<<char(6);
							break;
					}
					out+=" ";//cout<<" ";
			}
			else if(POS.maze==UPSTAIR||POS.maze==DOWNSTAIR){//������¥�� 
				col="f0";//SetConsoleTextAttribute(hout,0xf0);
				switch(POS.maze){
					case UPSTAIR:
						out=char(24)+char(24);//cout<<char(24)<<char(24);
						break;
					case DOWNSTAIR:
						out=char(25)+char(25);//cout<<char(25)<<char(25);
						break;
				}
			}
			else{
				col="6f";//SetConsoleTextAttribute(hout,0x6f);
				out="# ";//cout<<"#"<<POS.maze;
			}
			ret=col+out;
			return ret;
		}
		void print_game_map_z(int z){
			for(int y=1;y<=width;y++){
				for(int x=1;x<=length;x++){
					gotoxy((x-1)*2,y-1+(height*2-z)*width);
					print_game_map_pos((position_3D){x,y,z},2);
					//SLEEP(5);
				}
			}
		}
	void print_game_map(){
		for(int z=1;z<=height*2;z++) print_game_map_z(z);
	}
/*
void print(int l,int w,int h){
	for(int z=h;z>=1;z--){
		for(int y=1;y<=w;y++){
			for(int x=1;x<=l;x++){
				gotoxy(x*2-2,y+(height*2-z)*width-1);
				MAP &POS=game_map[x][y][z];
				if(POS.maze==SPACE) SetConsoleTextAttribute(hout,0xff);
				else if(UPSTAIR<=POS.maze&&POS.maze<=DOWNSTAIR){
					switch(POS.maze){
						case UPSTAIR:
							SetConsoleTextAttribute(hout,0x8f);
							cout<<char(24)<<char(24);
							break;
						case DOWNSTAIR:
							SetConsoleTextAttribute(hout,0x0f);
							cout<<char(25)<<char(25);
							break;
					}
				}
				else if(POS.maze==EXIT){
					SetConsoleTextAttribute(hout,0xaf);
					if(x==1||y==1) cout<<"E]";
					else cout<<"[E";
				}
				else SetConsoleTextAttribute(hout,0x77);
				cout<<"  ";
			}
		}
	}
}*/
			void rand_basic(int sx,int sy,int sz,int a,int b,int c,const int l=length,const int w=width,int h=height){
			//���ɻ����Թ����յ�+ǽ+¥�ݣ�һ��ͨ·��������ߴ���ָһ����Ϸ���ģ���������Ѩ�� 
				memset(stair_exist,0,sizeof(stair_exist));
				vector<position_3D> vec;//�洢ֻ����һ����ǽλ�õ�ǽ
				map<position_3D,bool> f;//���ǽ�Ƿ����б��� 
				memset(stair_exist,0,sizeof(stair_exist)); 
				position_3D st;st.x=sx,st.y=sy;st.z=sz;
				int smaze=2;//0��UPSTAIR 1��DOWNSTAIR 2��SPACE 
				if(sz<h&&sz>1) smaze=RAND(1,0);
				else if(sz<h) smaze=0;
				else if(sz>1) smaze=1;
				//��װ¥�ݾ�װ¥�� 
				if(smaze==2){
					game_map[sx][sy][sz].maze=SPACE;cnt_SPACE++;
					/*
					gotoxy(sx*2-2,sy+(height*2-sz)*width-1);
					SetConsoleTextAttribute(hout,0xff);
					cout<<"  ";*/
				}
				else{
					position_3D pos=st;
					if(smaze==0){
						pos.z=sz+1;
						/*
						gotoxy(pos.x*2-2,pos.y+(height*2-pos.z)*width-1);
						SetConsoleTextAttribute(hout,0x0f);
						cout<<char(25)<<char(25);
						gotoxy(sx*2-2,sy+(height*2-sz)*width-1);
						SetConsoleTextAttribute(hout,0x8f);
						cout<<char(24)<<char(24);*/
					}
					else{
						pos.z=sz-1;
						/*
						gotoxy(pos.x*2-2,pos.y+(height*2-pos.z)*width-1);
						SetConsoleTextAttribute(hout,0x8f);
						cout<<char(24)<<char(24);
						gotoxy(sx*2-2,sy+(height*2-sz)*width-1);
						SetConsoleTextAttribute(hout,0x0f);
						cout<<char(25)<<char(25);*/
					}
					game_map[sx][sy][pos.z].maze=UPSTAIR+(smaze^1),stair_exist[pos.z][smaze^1]=true;
					for(int i=0;i<4;i++){
						position_3D v=dtp3(pos,i,4);
						if(pos_in_area2(v.x,v.y,1,1,l,w,2))
							vec.push_back(v),f[v]=true;
					}
					game_map[sx][sy][sz].maze=UPSTAIR+smaze;stair_exist[sz][smaze]=true;cnt_STAIRS++;
				}
				cnt_notWALL++;
				/*
				SLEEP(10);*/
				for(int i=0;i<4;i++){
					position_3D u=dtp3(st,i,4);
					if(pos_in_area2(u.x,u.y,1,1,l,w,2)){
						vec.push_back(u);f[u]=true; 
					}
				}
				while(vec.size()){
					int k=RAND(vec.size()-1,0);
					position_3D u=vec[k];//���ѡһ��ǽ
					swap(vec[k],vec[vec.size()-1]);vec.pop_back();f[u]=0;//��ǽuɾ�� 
					if(count_around_pos(u,4,WALL,l,w)==3&&pos_in_area2(u.x,u.y,1,1,l,w,2)){
					//���Ǳ�Եǽ�Һ����涼��ǽ����������ͨ·��������չ
						for(int i=0;i<4;i++){//�������u���ǽ������ʧ����ǰ������Χ��ǽ����� 
							position_3D v=dtp3(u,i,4);
							if(!f.count(v)&&game_map[v.x][v.y][v.z].maze==WALL&&pos_in_area2(v.x,v.y,1,1,l,w,2))
								vec.push_back(v),f[v]=true;
						}
						bool add_stair=RAND_BOOL(a),add_up=0,add_down=0;
						//�Ƿ��¥�ݣ�����/��¥�ݷֱ��в��У����ӵĳ�Ѩ�ڲ��ݲ��������¥�ݣ� 
						int stair_kind;//¥�ݵ����ࣨ0��UPSTAIR 1��DOWNSTAIR�� 
						position_3D u2=u;u2.z++;//������/��¥��ͨ����λ�� 
						if(u.z<=h&&u.z>=1&&u2.z<=h&&game_map[u2.x][u2.y][u2.z].maze==WALL&&count_around_pos(u2,4,WALL,l,w)==4)
							add_up=true; 
						//��һ����Ϸ����������¥��ͨ�������λ�ò��ǿյ�����Χ����ǽ�� 
						u2=u;u2.z--;//������¥��ͨ����λ�� 
						if(u.z<=h&&u2.z>=1&&u2.z<=h&&game_map[u2.x][u2.y][u2.z].maze==WALL&&count_around_pos(u2,4,WALL,l,w)==4)
							add_down=true; 
						//��һ����Ϸ����������¥��ͨ�������λ�ò��ǿյ�����Χ����ǽ�� 
						bool add_nest=RAND_BOOL((u.z<=h?b:c)); 
						position_3D u3=u;u3.z+=(u.z>h?-height:height);//�����/����Ѩ��ͨ����λ��
						//��>height:�ڳ�Ѩ�-=height <=height:�ڳ�Ѩ�⣬+=height�� 
						if(!(game_map[u3.x][u3.y][u3.z].maze==WALL&&count_around_pos(u3,4,WALL,l,w)==4))
							add_nest=false;
						//��/����Ѩ��ͨ�������λ�ò��ǿյ�����Χ����ǽ�� ��������������Ͳ��� 
						if((add_up||add_down)//����¥��������һ����
						&&((add_up&&!stair_exist[u.z][0])//��㻹û������¥��
						||(add_down&&!stair_exist[u.z][1])//����㻹û������¥�� 
						||add_stair)//�����¥��
						){
							u2=u;
							if(add_up&&add_down) stair_kind=RAND(1,0);
							else if(add_up) stair_kind=0;
							else stair_kind=1;
							if(stair_kind==0) u2.z++;
							else u2.z--;
							for(int i=0;i<4;i++){//¥��/����Χ��ǽ 
								position_3D v=dtp3(u2,i,4);
								if(!f.count(v)&&pos_in_area2(v.x,v.y,1,1,l,w,2))
								//���汣֤¥����Χ����ǽ�����Բ����ж�
									vec.push_back(v),f[v]=true;
							}
							game_map[u.x][u.y][u.z].maze=UPSTAIR+stair_kind;
							game_map[u2.x][u2.y][u2.z].maze=UPSTAIR+(stair_kind^1);
							stair_exist[u.z][stair_kind]=true;stair_exist[u2.z][stair_kind^1]=true;
							cnt_STAIRS+=2;cnt_notWALL+=2;
							/*
							if(stair_kind==0){
								gotoxy(u.x*2-2,u.y+(height*2-u.z)*width-1);
								SetConsoleTextAttribute(hout,0x8f);
								cout<<char(24)<<char(24);
								gotoxy(u2.x*2-2,u2.y+(height*2-u2.z)*width-1);
								SetConsoleTextAttribute(hout,0x0f);
								cout<<char(25)<<char(25);
							}
							else{
								gotoxy(u.x*2-2,u.y+(height*2-u.z)*width-1);
								SetConsoleTextAttribute(hout,0x0f);
								cout<<char(25)<<char(25);
								gotoxy(u2.x*2-2,u2.y+(height*2-u2.z)*width-1);
								SetConsoleTextAttribute(hout,0x8f);
								cout<<char(24)<<char(24);
							}*/
						}
						else if(add_nest){//�Ӹ���Ѩ��û����
							for(int i=0;i<4;i++){//��/����Ѩ�ں���Χ��ǽ 
								position_3D v=dtp3(u3,i,4);
								if(!f.count(v)&&pos_in_area2(v.x,v.y,1,1,l,w,2))
								//���汣֤��/����Ѩ�ں���Χ����ǽ�����Բ����ж�
									vec.push_back(v),f[v]=true;
							}
							bug_nest bns;//���ɳ�Ѩ��
							if(u.z<=height) bns.init(u);
							else bns.init(u3);
							//�洢��һ����Ϸ���������
							bug_nests.push_back(bns);
							int id=int(bug_nests.size())-1;
							Qbug_nest.push(id);//��Ŵ�ŵ������� 
							game_map[u.x][u.y][u.z].maze=game_map[u3.x][u3.y][u3.z].maze=SPACE;
							nest &NST=game_map[u.x][u.y][u.z].things.nst,&NST2=game_map[u3.x][u3.y][u3.z].things.nst;
							//�ֱ��Ӧu��u3�����������ã������� 
							NST.exist=NST2.exist=true;NST.id=NST2.id=id;//������Ӧ�ĳ�Ѩ�ڹ���һ����� 
							NST.to=u3;NST2.to=u;//��Ѩ�ڵ������Ӧ���� 
							cnt_SPACE++;cnt_notWALL++;
							/* 
							gotoxy(u.x*2-2,u.y+(height*2-u.z)*width-1);
							SetConsoleTextAttribute(hout,0xfc);
							cout<<"��";
							gotoxy(u3.x*2-2,u3.y+(height*2-u3.z)*width-1);
							SetConsoleTextAttribute(hout,0xfc);
							cout<<"��";*/
						}
						else{//¥�ݷ��˻�����һ��ͨ·���߲����¥�ݣ���ֻ�ǿյ� 
							game_map[u.x][u.y][u.z].maze=SPACE;
							cnt_SPACE++;cnt_notWALL++;
							/*
							gotoxy(u.x*2-2,u.y+(height*2-u.z)*width-1);
							SetConsoleTextAttribute(hout,0xff);
							cout<<"  ";*/
						}
						/*
						SLEEP(10);*/
					}
				}
			}
			void fill_dead_ends(int kind,int a,int l=length,int w=width,int h1=1,int h2=height){//�������ͬ 
				vector<position_3D> vec;//�洢ֻ����һ���յصĿյأ�����ͬ��
				int cnt2=0;//�������ĵط������ڲ�һ��������ͬ�� 
				for(int z=h1;z<=h2;z++)
					for(int y=2;y<w;y++)
						for(int x=2;x<l;x++){
							position_3D u;
							u.x=x;u.y=y;u.z=z;
							if(space_here(u)&&nothing_here(u)){
								cnt2++;
								if(count_around_pos(u,4,WALL,l,w)==3&&count_around_pos(u,4,NEST,l,w)==0) vec.push_back(u);
							}
						}
				int cnt=0;
				if(kind==1) cnt=a;
				else cnt=cnt2*a/100;
				/*
				gotoxy(0,40+kind);
				SetConsoleTextAttribute(hout,0x0f);
				cout<<vec.size();
				gotoxy(10,40+kind);
				SetConsoleTextAttribute(hout,0x0f);
				cout<<"#"<<cnt;*/
				while(vec.size()&&cnt){
					int k=RAND(vec.size()-1,0);
					position_3D u=vec[k];//���ѡһ������ǽ��λ��
					game_map[u.x][u.y][u.z].maze=WALL;cnt--;
					swap(vec[k],vec[vec.size()-1]);
					vec.erase(vec.begin()+vec.size()-1);
					//�����λ�øĳ�ǽ��ɾ��
					/*
					gotoxy(u.x*2-2,u.y+(height*2-u.z)*width-1);
					SetConsoleTextAttribute(hout,0x77);
					cout<<"  ";*/
					for(int i=0;i<4;i++){//һ��������ǽֻ��ʹ��Χ�Ŀյؿ��ܱ������ͬ 
						position_3D v=dtp3(u,i,4);
						if(space_here(v)&&nothing_here(v)&&count_around_pos(v,4,WALL,l,w)==3&&count_around_pos(v,4,NEST,l,w)==0
						&&pos_in_area2(v.x,v.y,1,1,l,w,2))//�Ӹ��ж��Ƿ���� 
							vec.push_back(v);
					}
					/*
					gotoxy(0,40+kind);
					SetConsoleTextAttribute(hout,0x0f);
					cout<<vec.size()<<"  ";
					gotoxy(10,40+kind);
					SetConsoleTextAttribute(hout,0x0f);
					cout<<"#"<<cnt<<"  ";
					SLEEP(10);*/
				}
			}
			void make_room(int a,const int l=length,const int w=width,int h=height){
			//�Ѿ���һ���ǽ�ڹ⣬�γ�һ������ 
				memset(sum1,0,sizeof(sum1));
				memset(sum2,0,sizeof(sum2));
				for(int z=1;z<=h;z++){
					for(int y=1;y<=w;y++)
						for(int x=1;x<=l;x++){
							sum1[x][y]=int(game_map[x][y][z].maze!=WALL)+sum1[x][y-1];
							sum2[x][y]=int(game_map[x][y][z].maze!=WALL)+sum2[x-1][y];
						}
					for(int y=2;y<w;y++)
						for(int x=2;x<l;x++)//ö�پ��ε����Ͻǣ����ٺ��Ϊ2�� 
							if(RAND_BOOL(a)&&game_map[x][y][z].maze==WALL
								&&game_map[x+1][y][z].maze==WALL&&game_map[x][y+1][z].maze==WALL){
								int x2=x+1,y2=y+1;//�����ľ������Ͻ�(x,y)�����½�(x2,y2)
								if(RAND_BOOL(50)){
									while(x2<l&&sum1[x2][y2]-sum1[x2][y-1]==0) x2++;
									x2--;
									if(x2==x) continue;
									while(y2<w&&sum2[x2][y2]-sum2[x-1][y2]==0) y2++;
									y2--;
									if(y2==y) continue;
								}
								else{
									while(y2<w&&sum2[x2][y2]-sum2[x-1][y2]==0) y2++;
									y2--;
									if(y2==y) continue;
									while(x2<l&&sum1[x2][y2]-sum1[x2][y-1]==0) x2++;
									x2--;
									if(x2==x) continue;
								}
								for(int j=max(y,2);j<=min(y2,w-1);j++)
									for(int i=max(x,2);i<=min(x2,l-1);i++){//���ڱ�Եǽ�ϵĲ��ڵ� 
										game_map[i][j][z].maze=SPACE;
										/*
										gotoxy(i*2-2,j+(height*2-z)*width-1);
										SetConsoleTextAttribute(hout,0xff);
										cout<<"  ";
										SLEEP(10);*/
									}
								for(int i=x;i<=x2;i++)
									for(int j=y;j<=w;j++)
										sum1[x][y]=int(game_map[x][y][z].maze!=WALL)+sum1[x][y-1];
								for(int i=x;i<=l;i++)
									for(int j=y;j<=y2;j++)
										sum2[x][y]=int(game_map[x][y][z].maze!=WALL)+sum2[x-1][y];
							}
				}
				for(int z=1;z<=h;z++)
					for(int y=1;y<=w;y++)
						for(int x=1;x<=l;x++){
							position_3D u;
							u.x=x;u.y=y;u.z=z;
							pos_in_room[x][y][z]=in_room(u);
						}
				for(int z=height+1;z<=height+h;z++)
					for(int y=1;y<=w;y++)
						for(int x=1;x<=l;x++){
							position_3D u;
							u.x=x;u.y=y;u.z=z;
							MAP &POS=game_map[u.x][u.y][u.z];
							if(!wall_here(u)) pos_in_nest.push_back(u);
						}
			}
		void rand_maze(int l=length,int w=width,int h=height){
			//print_game_map();
			rand_basic(RAND(l-1,2),RAND(w-1,2),RAND(h,1),5,5,10);
			//����������Щ�����Ĳ��������ɲ�ͬ���Թ�
			fill_dead_ends(1,RAND_ALTO(cnt_SPACE,0,RAND(10,5)),length,width,1,height);
			fill_dead_ends(2,85,length,width,height+1,height*2);
			make_room(100);
			//print(l,w,h);
			//SLEEP(10000);
			//CLEAR();
		}
		void make_nest(int a,int l=length,int w=width,int h=height){
			for(int z=1;z<=h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						MAP &POS=game_map[u.x][u.y][u.z];
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)
						&&RAND_BOOL(a)){ 
							bug_nest bns;//���ɳ�Ѩ��
							bns.init(u);
							bug_nests.push_back(bns);
							int id=int(bug_nests.size())-1;
							POS.things.nst.exist=true;POS.things.nst.id=id;
							Qbug_nest.push(id);
						}
					}
		}
			void make_exits(int l=length,int w=width,int h=height){//�������еĳ���
				memset(vst,0,sizeof(vst));memset(dis_to_exit,0,sizeof(dis_to_exit));
				while(!Q.empty()) Q.pop();
				int exit_nums=RAND_ALTO(max((l+w)*height/10,1),1,5);//��Ϸ��ͼ�г��ڵ�����
				RAND_EXIT_AROUND_GAME_MAP(exit_nums,l,w,h);
			}
			void make_exit_sign(int a,int b,int l=length,int w=width,int h=height){//���ɳ��ڵı���->]����ͷ��char(24~27)��
				while(!Q.empty()){//BFS 
					position_3D u=Q.front();Q.pop();
					for(int i=0;i<4;i++){
						position_3D v=dtp3(u,i,4);
						if(pos_in_area2(v.x,v.y,1,1,l,w,2)){
							if(!vst[v.x][v.y][v.z]&&game_map[v.x][v.y][v.z].maze!=WALL){
								vst[v.x][v.y][v.z]=1;
								dis_to_exit[v.x][v.y][v.z]=dis_to_exit[u.x][u.y][u.z]+1;
								Q.push(v);
								if(v.z<=height&&space_here(v)&&nothing_here(v)
								&&count_around_pos(v,4,SPACE)>=3
								&&(pos_in_room[v.x][v.y][v.z]?RAND_BOOL(a):RAND_BOOL(b))
								){
									exit_sign &EXIT_SIGN=game_map[v.x][v.y][v.z].things.exit_signs;
									EXIT_SIGN.exist=1;
									EXIT_SIGN.dir=turn(i,TURN_BACK);
								}
								if(game_map[v.x][v.y][v.z].maze==UPSTAIR) v.z++;
								else if(game_map[v.x][v.y][v.z].maze==DOWNSTAIR) v.z--;
								else if(game_map[v.x][v.y][v.z].things.nst.exist) v=game_map[v.x][v.y][v.z].things.nst.to;
								if(!vst[v.x][v.y][v.z]&&u.z!=v.z){//�����¥�ݻ��߳�Ѩ�� 
									vst[v.x][v.y][v.z]=1;
									dis_to_exit[v.x][v.y][v.z]=dis_to_exit[u.x][u.y][u.z]+1;
									Q.push(v);
								}
							}
						}
					}
				}
			}
		void make_exit(){
			//��������Թ�������ʩ������Ϻ󣡣��� 
			make_exits(); 
			make_exit_sign(1,5);
			/*
			for(int z=height*2;z>=1;z--)
				for(int y=1;y<=width;y++)
					for(int x=1;x<=length;x++){
						gotoxy(x*3-2+length*2,y+(height*2-z)*width-1);
						SetConsoleTextAttribute(hout,0x07);
						cout<<dis_to_exit[x][y][z];
					}
			SLEEP(10000);*/
		}
	void make_map(){
		rand_maze();
		//make_nest(2); 
		make_exit();
		//print(length,width,height);SLEEP(5000);
	}
		void player::init(){
			player1.pos=RAND_PLAYER_IN_GAME_MAP();
			game_map[player1.pos.x][player1.pos.y][player1.pos.z].player_enemy=PLAYER;
			player1.d=0;player1.color=0;
			player1.vts.init();
			//player1.vlc.wait_time=1;player1.vlc.ts();//wait_time����speed 
			player1.vlc.speed=100;player1.vlc.vt();//speed����wait_time 
			player1.scr.init();
			player1.items.init();
			player1.move=true;
			player1.action_kind=RUN; 
			player1.lst_ud=player1.lst_enter=false;
		}
		void calculate_dis_to_player(int l=length,int w=width,int h=height){
			while(!Q.empty()) Q.pop();
			memset(vst,0,sizeof(vst));memset(dis_to_player,0,sizeof(dis_to_player));
			Q.push(player1.pos);
			vst[player1.pos.x][player1.pos.y][player1.pos.z]=1;
			while(!Q.empty()){//BFS 
				position_3D u=Q.front();Q.pop();
				for(int i=0;i<4;i++){
					position_3D v=dtp3(u,i,4);
					if(pos_in_area2(v.x,v.y,1,1,l,w,2)){
						if(!vst[v.x][v.y][v.z]&&game_map[v.x][v.y][v.z].maze!=WALL){
							vst[v.x][v.y][v.z]=1;
							dis_to_player[v.x][v.y][v.z]=dis_to_player[u.x][u.y][u.z]+1;
							Q.push(v);
							if(game_map[v.x][v.y][v.z].maze==UPSTAIR) v.z++;
							else if(game_map[v.x][v.y][v.z].maze==DOWNSTAIR) v.z--;
							else if(game_map[v.x][v.y][v.z].things.nst.exist) v=game_map[v.x][v.y][v.z].things.nst.to;
							if(!vst[v.x][v.y][v.z]&&u.z!=v.z){//�����¥�ݿ������� 
								vst[v.x][v.y][v.z]=1;
								dis_to_player[v.x][v.y][v.z]=dis_to_player[u.x][u.y][u.z]+1;
								Q.push(v);
							}
						}
					}
				}
			}
			for(int z=1;z<=height+h;z++)
				for(int y=2;y<w;y++)
					for(int x=2;x<l;x++){//ͳ�Ƶ���Ҳ�ͬ�����λ�ã�������Զ����
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						if(!wall_here(u)) pos_dis_to_player[dis_to_player[x][y][z]].push_back(u);
						mx_dis_to_player=max(mx_dis_to_player,dis_to_player[x][y][z]); 
					}
		}
	void make_player(){
		player1.init();
		calculate_dis_to_player();
		/*
		for(int z=height*2;z>=1;z--)
			for(int y=1;y<=width;y++)
				for(int x=1;x<=length;x++){
					gotoxy(x*3-2+length*3,y+(height-z)*width-1);
					SetConsoleTextAttribute(hout,0x07);
					cout<<dis_to_player[x][y][z];
				}
		SLEEP(30000);*/
	}
		void farther_more_doors(int a,int b,int c){//ԽԶԽ��
			for(int i=10;i<=mx_dis_to_player;i++)
				if(RAND_BOOL(a)){
					int sz=pos_dis_to_player[i].size(),door_num=RAND_ALTO(sz>0?sz:1,1,b+i*(c-b)/mx_dis_to_player);
					//��ǰ��������Ͽ��Է��ŵ�λ���������������ȡλ�ã�����Ҫ�������� 
					while(sz&&door_num){
						int k=RAND(sz-1,0);
						position_3D u=pos_dis_to_player[i][k];
						swap(pos_dis_to_player[i][k],pos_dis_to_player[i][sz-1]);
						sz--;
						//����ҷ��ŵ�λ��
						MAP &DPOS=game_map[u.x][u.y][u.z]; 
						if(u.z<=height
						&&space_here(u)&&nothing_here(u)&&!count_around_pos(u,4,DOORS)
						&&useful_door(position_3Dto2D(u),u.z,10)){
						//�յء�������ã����ŵ�һ�ߵ���һ�ߵ�·�̲���̫���� 
							int door_kind=RAND(4,1);//���ѡ������
							DPOS.maze=door_kind-1+DOOR1;
							DPOS.door_state=false;
							door_num--;
						}
					}
				}
		}
		void doors_around_rooms(int a,int l=length,int w=width,int h=height){//�������ڷ�����Χ 
			for(int z=1;z<=h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						if(pos_in_room[x][y][z])
							for(int i=0;i<4;i++){
								position_3D v=dtp3(u,i,4);
								MAP &DPOS=game_map[v.x][v.y][v.z]; 
								if(RAND_BOOL(a)
								&&space_here(v)&&nobody_here(v)&&nothing_here(v)
								&&count_around_pos(v,4,WALL)<=2&&!count_around_pos(v,4,DOORS)
								&&!pos_in_room[v.x][v.y][v.z]){
								//�յأ���Χû���š�������2��ǽ�����ڷ����� 
									int door_kind=RAND(4,1);//���ѡ������
									DPOS.maze=door_kind-1+DOOR1;
									DPOS.door_state=false;
								}
							}
					}
		}
	void make_door(){
		farther_more_doors(20,10,80);
		doors_around_rooms(100);
	}
			void bug::init(position_3D u){
				pos=u;d=0;vlc.speed=RAND(10,1);vlc.vt();
				lfin.init(1);
				lst_ud=enter_nest=-INF;change_pos=update=false;
			}
			void bug_nest::init(position_3D u){
				pos=u;
				lfin.init(3);
			}
		void make_bug(int a,int b,int c,int l=length,int w=width,int h=height){//���ɳ��� 
			for(int z=1;z<=height+h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						MAP &POS=game_map[u.x][u.y][u.z];
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)&&dis_to_player[x][y][z]>=10//���������10������ 
						&&RAND_BOOL(a+b/dis_to_exit[x][y][z]*(100-c-a)/b+(z>height?c:0))){ 
							bug bg;//���ɳ���
							bg.init(u);
							bugs.push_back(bg);
							int id=int(bugs.size())-1;
							POS.player_enemy=BUG;POS.emy.id=id;
							Qbug.push(id);
						}
					}
		}
			void ghost::init(position_3D u){
				pos=u;d=0;vlc.speed=RAND(3,1);vlc.vt();
				lfin.init(2);
				change_pos=update=false;
			}
		void make_ghost(int a,int l=length,int w=width,int h=height){//���ɹ� 
			for(int z=1;z<=height+h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						MAP &POS=game_map[u.x][u.y][u.z];
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)&&dis_to_player[x][y][z]>=20//���������20������ 
						&&RAND_BOOL(a)){ 
							ghost gt;//���ɹ�
							gt.init(u);
							ghosts.push_back(gt);
							int id=int(ghosts.size())-1;
							POS.player_enemy=GHOST;POS.emy.id=id;
							Qghost.push(id);
						}
					}
		}
	void make_enemy(){
		make_bug(2,15,20);
		make_ghost(1);
	}
			void farther_less_keys(int a,int b,int c){//ԽԶԽ�� 
				for(int i=1;i<=mx_dis_to_player;i++)
					if(RAND_BOOL(a)){
						int sz=pos_dis_to_player[i].size(),key_num=RAND_ALTO(sz>0?sz:1,1,b-i*(b-c)/mx_dis_to_player);
						//��ǰ��������Ͽ��Է�Կ�׵�λ���������������ȡλ�ã�����Ҫ��Կ�����������������ɲ��ϼ�С�� 
						while(sz&&key_num){
							int k=RAND(sz-1,0);
							position_3D u=pos_dis_to_player[i][k];
							swap(pos_dis_to_player[i][k],pos_dis_to_player[i][sz-1]);
							sz--;
							//����ҷ�Կ�׵�λ��
							MAP &KPOS=game_map[u.x][u.y][u.z]; 
							if(u.z<=height&&space_here(u)&&KPOS.things.nothing()){
								int key_kind=RAND(3,0);//���ѡԿ������
								KPOS.things.key=key_kind+KEY1;
								key_num--;
							} 
						}
					}
			}
			void keys_in_rooms(int a,int l=length,int w=width,int h=height){//Կ�������ڷ�������
				vector<position_3D> v;
				for(int z=1;z<=h;z++)
					for(int y=1;y<=w;y++)
						for(int x=1;x<=l;x++){
							position_3D u;
							u.x=x;u.y=y;u.z=z;
							MAP &KPOS=game_map[u.x][u.y][u.z]; 
							if(pos_in_room[x][y][z]&&space_here(u)&&KPOS.things.nothing())
								v.push_back(u);
						}
				for(int i=0;i<int(v.size());i++){
					position_3D u=v[i];
					MAP &KPOS=game_map[u.x][u.y][u.z]; 
					if(RAND_BOOL(a)){
						int key_kind=RAND(3,0);//���ѡԿ������
						KPOS.things.key=key_kind+KEY1;
					} 
				}
			}
			void keys_to_doors(int a,int b,int l=length,int w=width){//ÿ��Կ�׶���Ӧһ���� 
				vector<position_3D> vspace;//�ѷ��ʡ�δ��Կ�׵Ŀյ�	
				vector<position_3D> vdoor[4];//�ѷ��ʡ�δ�Ŷ�ӦԿ�׵��ţ����ֱַ��¼��
				while(!Q.empty()) Q.pop();
				memset(vst,0,sizeof(vst));
				Q.push(player1.pos);
				vst[player1.pos.x][player1.pos.y][player1.pos.z]=1;
				while(1){
					while(!Q.empty()){//BFS 
						position_3D u=Q.front();Q.pop();
						for(int i=0;i<4;i++){
							position_3D v=dtp3(u,i,4);
							if(pos_in_area2(v.x,v.y,1,1,l,w,2)){
								if(!vst[v.x][v.y][v.z]
								&&!wall_here(v)&&!door_here(v)){//����ǽ�������ţ���Ȼ��������㣩 
									vst[v.x][v.y][v.z]=1;
									Q.push(v);
									if(space_here(v)&&nothing_here(v)) vspace.push_back(v);//�ѷ��ʡ�û����Ʒ�Ŀյ�
									else if(game_map[v.x][v.y][v.z].maze==UPSTAIR) v.z++;
									else if(game_map[v.x][v.y][v.z].maze==DOWNSTAIR) v.z--;
									else if(game_map[v.x][v.y][v.z].things.nst.exist) v=game_map[v.x][v.y][v.z].things.nst.to;
									if(u.z!=v.z&&!vst[v.x][v.y][v.z]){//�����¥�ݿ�������/��Ѩ���Խ������Ҳ����ߵ�ȥ���ĵط� 
										vst[v.x][v.y][v.z]=1;
										Q.push(v);
									}
								}
								else if(!vst[v.x][v.y][v.z]&&door_here(v)){
									vst[v.x][v.y][v.z]=1;
									vdoor[game_map[v.x][v.y][v.z].maze-DOOR1].push_back(v);
									//�ѷ��ʡ�δ�Ŷ�ӦԿ�׵���
								}
							}
						}
					}
					vector<int> vkind;//����ѡ����ŵ����� 
					for(int i=0;i<4;i++)
						if(vdoor[i].size()&&vspace.size()>=vdoor[i].size()) vkind.push_back(i);
					if(vkind.size()){//�п���ѡ����ŵ�����  
						int door_kind=vkind[RAND(vkind.size()-1,0)];//���ѡ�ŵ�����
						for(int i=0;i<int(vdoor[door_kind].size());i++){
							position_3D dr=vdoor[door_kind][i];//��ǰ�ŵ�Կ�׶�Ӧ���� 
							Q.push(dr);
							//�ѷ��˶�ӦԿ�׵��š��򿪡�����Ϊ�´�ѭ������� 
							int k=RAND(vspace.size()-1,0);
							position_3D u=vspace[k];
							//ȡ��Ҫ��Կ�׵Ŀյ�
							MAP &KPOS=game_map[u.x][u.y][u.z];
							if(RAND_BOOL(a*max(1,b/dis_to_player[dr.x][dr.y][dr.z]))){//Ŀǰ�����Ŷ���֤��Կ�� 
								int key_kind=door_kind;
								KPOS.things.key=key_kind+KEY1;
								swap(vspace[k],vspace[vspace.size()-1]);vspace.pop_back();//����Կ�ײŰ�����յ�ɾ�� 
							}
							//����Կ�� 
						}
						vdoor[door_kind].clear();//��������� 
					}
					else break;//ѭ����û��δ�Ŷ�ӦԿ�׵��ţ�����һ�Σ���Ϊ�ʼû�ţ� 
				}
			}
		void make_key(){
			//farther_less_keys(20,15,5); 
			//keys_in_rooms(10);
			keys_to_doors(100,0); 
		}
		void make_mirror(int a,int l=length,int w=width,int h=height){
			for(int z=1;z<=h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						if(space_here(u)&&no_mirror_around(u)&&nobody_here(u)&&nothing_here(u)
						&&RAND_BOOL(a)){
							int mirror_dir=RAND_MIRROR_DIRECTION(u);
							if(mirror_dir==-1) continue;
							int cw=count_around_pos(u,4,WALL),mirror_side;
							if(cw==2) mirror_side=1;
							else if(!cw) mirror_side=2;
							else mirror_side=RAND(2,1);
							mirror &MIRROR=game_map[u.x][u.y][u.z].things.mirrors;
							MIRROR.exist=1;MIRROR.side=mirror_side;
							if(mirror_side==1) MIRROR.dir=mirror_dir;
							else MIRROR.dir=mirror_dir%2;
						}
					}
		}	
		void make_food(int a,int b,int l=length,int w=width,int h=height){
			for(int z=1;z<=h*2;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)&&RAND_BOOL(z<=h?a:b)){
							int kind=RAND(ADDL,ADDS),effect=log2(RAND(1<<3,1<<1));//8,7,6,5->3;4,3->2;2->1
							food &FOOD=game_map[u.x][u.y][u.z].things.foods;
							FOOD.exist=1;
							FOOD.kind=kind;FOOD.effect=effect;
						}
					}
		}
		void make_weapon_energy_edc(int a,int b,int c,int l=length,int w=width,int h=height){//��������������/�;öȻظ�
			for(int z=1;z<=h*2;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						weapon_energy_edc &WEE=game_map[u.x][u.y][u.z].things.wee;
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)&&RAND_BOOL(z<=h?a:b)){
							WEE.exist=true;
							WEE.num=RAND(9,1);
							if(RAND_BOOL(c)) WEE.kind=0;
							else WEE.kind=1;
						}
					}
		}
		void make_dart(int a,int l=length,int w=width,int h=height){//���ɵ��ϵķ���
			 for(int z=1;z<=h;z++)
				for(int y=1;y<=w;y++)
					for(int x=1;x<=l;x++){
						position_3D u;
						u.x=x;u.y=y;u.z=z;
						dart &DRT=game_map[u.x][u.y][u.z].things.drt;
						if(space_here(u)&&nobody_here(u)&&nothing_here(u)&&RAND_BOOL(a)){
							DRT.num[0]++;
							DRT.d[0]=RAND(3,0);
						}
					}
		}
		void make_box(){
		}
		void make_barrel(){
		}
		void make_TNT(){
		}
		void make_treasure(){
		}
		void make_candle(){
		}
		void make_lamp(){
		} 
		void make_water(){
		}
		void make_magma(){
		}
	void make_item(){
		make_key();
		make_mirror(20); 
		make_food(1,5);
		make_weapon_energy_edc(3,5,30);
		make_dart(2); 
		make_box();
		make_barrel();
		make_TNT();
		make_treasure();
		make_candle();
		make_lamp();
		make_water();
		make_magma();
	}
	void print_initial_picture(){
	    //��ǰҪ���� 
		//whole_screen.output_frame();
		//game_map_area.output_frame();
		vital_signs_area.output_frame();
		item_area.output_frame();
		game_time=lst_see_time=0;
		player_calculate_vision2();
		player_calculate_vision1();
		while(!pos_in_sight.empty()){
			position_3D u=pos_in_sight.front();pos_in_sight.pop();
			print_game_map_pos(u);
			position_2D spos=position_3Dtoscr(u);
			pos_lst_sight.push(spos);
			//screen_pos[spos]=screen_display_coding(u);
		}
		
		formatted_output(1,vital_signs_area,1,1,0x0c
		,connect_str("����ֵ��",repeat_char(char(3),(player1.vts.lfin.life+5)/10.0),"           "));
		formatted_output(1,vital_signs_area,1,2,0x0a
		,connect_str("����ֵ��",int_to_str(player1.vts.stg.physical_strength,0),"% "));
		formatted_output(1,vital_signs_area,1,3,0x0e
		,connect_str("��ɱ����",int_to_str(player1.scr.kill_count)));
		formatted_output(1,vital_signs_area,1,4,0x07,"�ֶ������ո��������¥");
		formatted_output(1,vital_signs_area,1,5,0x0b,"�ƶ�    ��F���л���");
		
		player1.items.print1();player1.items.print2();player1.items.print3();
		player1.items.wpn.print1();player1.items.wpn.print2();player1.items.wpn.print3();
	}
void initial(){//��Ϸ��ʼ��
	//��ǰҪ���� 
	all_assigned();
	make_map();
	make_player();
	make_door();
	make_enemy();
	make_item();
	int cnt=0;
	//print_game_map();
	//SLEEP(10000);
	//CLEAR();
	print_initial_picture();
}			
	void pause(){
		if(game_pause&&_kbhit()){
			switch(_getch()){//��ⰴ�� 
				case PRESS_KEY_ENTER:
					game_pause=false;
					game_flag["��Ϸ��ͣ/����"]=true; 
					return;
			}
		}
	}
	void assigned(){
		player1.scr.time_spent=game_time;
		//������ʱ 
		while(!pos_backup.empty()) pos_backup.pop();
		while(!pos_change.empty()) pos_change.pop();
		screen_z.clear();
		for(int i=0;i<4;i++) cnt_visible[i]=360;
		memset(occlusion,0,sizeof(occlusion));
		player1.d_change=player1.move=player1.vts.lfin.change=player1.vts.stg.change
		=player1.ud_change=player1.ak_change=player1.flash=player1.use_weapon
		=player1.enemy_move
		=player1.items.num_change=player1.items.sn_change=player1.items.il_change
		=player1.items.wpn.sw_change=player1.items.wpn.data_change=player1.items.wpn.mode_change
		=player1.scr.kc_change=false;
		game_flag["��Ϸ��ͣ/����"]=game_flag["���ӱ���ҹ���"]=game_flag["���ʬ��"]=game_flag["���ì�ı�λ��"]=game_flag["���ڱ仯"]=false;
	}
			void player_reduce_blood(double sub=1){
				player1.vts.lfin.hurt+=player1.vts.lfin.life;
				player1.vts.lfin.life-=sub;player1.scr.hurt_times++;
				player1.vts.lfin.hurt-=player1.vts.lfin.life;//��ֹ��� 
				player1.vts.lfin.change=2;//��Ѫ 
				pos_change.push(player1.pos);player1.flash=true;
				if(player1.vts.lfin.life<=0){
					player1.vts.lfin.life=0;
					game_end=true;game_success=false;
				}
			}
			void bug_move_away(int id){//�ı�λ������ 
				bug &bg=bugs[id];
				if(pos_in_nest.size()==0){//û�г�Ѩ�� 
					bg.update=false;
					return;
				}
				int k=RAND(pos_in_nest.size()-1,0);
				position_3D npos=pos_in_nest[k];
				bg.pos.x=npos.x;bg.pos.y=npos.y;bg.pos.z=npos.z;
				MAP &NPOS=game_map[bg.pos.x][bg.pos.y][bg.pos.z];
				if(space_here(bg.pos)&&nobody_here(bg.pos)){
					bg.change_pos=false;bg.enter_nest=true;
					NPOS.player_enemy=BUG;NPOS.emy.id=id;
					bg.lfin.life=1;bg.lfin.change=false;
				}
				else bg.change_pos=true;
			}
		void deal_bug(){
			int bug_num=Qbug.size();
			while(bug_num>0){
				bug_num--;
				int id=Qbug.front();Qbug.pop();
				bug &bg=bugs[id];
				MAP &POS=game_map[bg.pos.x][bg.pos.y][bg.pos.z];
				string s=connect_str("����",int_to_str(id));
				if(MHT_DIST2(bg.pos.x,bg.pos.y,bg.pos.z,player1.pos.x,player1.pos.y,player1.pos.z)>50
				&&POS.in_player_sight<lst_see_time)//����Ҿ��볬��50������ҿ����� 
					bg.update=false;//ֹͣ���� 
				if(!bg.update) continue;
				Qbug.push(id);
				if(bg.change_pos){
					bug_move_away(id);
					continue;
				}
				thing &THING=POS.things;
				if((THING.lsr.exist&&bg.lfin.change!=2)//�����ѱ�����״̬ 
				||(THING.drt.exist1()&&bg.lfin.change!=2)//�����ѱ�����״̬ 
				||(THING.spr.exist&&game_timer[connect_str(s,"��ì����")]<=game_time)//1000������ʱ�ѵ� 
				){
				    if(THING.spr.exist){
						game_timer[connect_str(s,"��ì����")]=game_time+1000;//ÿ�����һ���˺� 
						player1.items.wpn.hsr.endurance-=bg.vlc.speed;
						if(player1.items.wpn.hsr.endurance<0) player1.items.wpn.hsr.endurance=0;
						player1.items.wpn.data_change=true;
					}
					else player1.scr.shoot_hit_times++;
					life_injury &lfin=bg.lfin;
					lfin.life--;lfin.change=2;
					if(POS.in_player_sight==lst_see_time){
						pos_change.push(bg.pos);
						game_flag["���ӱ���ҹ���"]=true; 
					}
					if(lfin.life<=0){
						player1.scr.kill_count++;player1.scr.kc_change=true;
						POS.emy.dead=true;POS.emy.body_disapp=game_time+200;
						pos_dead.push(bg.pos);
						MAP &POS=game_map[bg.pos.x][bg.pos.y][bg.pos.z];
						POS.player_enemy=NOBODY;POS.emy.id=-1;
						bug_move_away(id);
						continue;
					}
				}
				else if(!(THING.lsr.exist||THING.drt.exist1()||THING.spr.exist)){//Ҫ������һһ��Ӧ 
					if(bg.lfin.change!=0&&POS.in_player_sight==lst_see_time){
						pos_change.push(bg.pos);
						game_flag["���ӱ���ҹ���"]=true; 
					}
					bg.lfin.change=0;
				}
				if(game_timer[s]>game_time)//ʱ��û�������� 
					continue;
				game_timer[s]=game_time+bg.vlc.wait_time; 
				if(THING.spr.exist) continue;//��ì�����޷��ƶ��͹��� 
				position_3D npos=bg.pos;
				int d=bg.d;
				if(POS.emy.phm.disapp>game_time&&POS.emy.phm.id!=id) d=POS.emy.phm.d;//����Ϣ�� 
				bool special_move=false;
				if(stair_here(npos)&&bg.lst_ud+5000<=game_time){//����¥ 
					if(game_map[npos.x][npos.y][npos.z].maze==UPSTAIR) npos.z++;
					else npos.z--;
					bg.lst_ud=game_time;special_move=true;
				}
				else if(POS.things.nst.exist&&bg.enter_nest+5000<=game_time){//����Ѩ��
					position_3D npos2=POS.things.nst.to;
					MAP &POS2=game_map[npos2.x][npos2.y][npos2.z];
					npos.x=npos2.x;npos.y=npos2.y;npos.z=npos2.z;//�ƶ�����Ӧ�ĳ�Ѩ��
					bg.enter_nest=game_time;special_move=true;
				}
				if(!special_move){//��ͨ�ƶ� 
					npos.x+=dx4[d];
					npos.y+=dy4[d];
				}
				MAP &NPOS=game_map[npos.x][npos.y][npos.z];
				thing &THING2=NPOS.things;
				if(!THING2.spr.exist&&(stair_here(npos)||door_here(npos,1)||space_here(npos))&&nobody_here(npos)){
					POS.player_enemy=NOBODY;POS.emy.id=-1;
					POS.emy.phm.disapp=game_time+2000;POS.emy.phm.id=id;POS.emy.phm.d=d;//������Ϣ�� 
					NPOS.player_enemy=BUG;NPOS.emy.id=id;
					if(POS.in_player_sight==lst_see_time&&bg.pos.z==player1.pos.z){
						player1.enemy_move=true;
						pos_change.push(bg.pos);
					}
					if(NPOS.in_player_sight==lst_see_time&&npos.z==player1.pos.z){
						player1.enemy_move=true;
						pos_change.push(npos);
					}
					bg.pos=npos;
					if(!stair_here(npos)) bg.lst_ud=game_time-5000;
					if(!NPOS.things.nst.exist) bg.enter_nest=game_time-5000;
				}
				else{
					if(NPOS.player_enemy==PLAYER){
						player_reduce_blood(20.0/bg.vlc.speed);
						bg.lfin.life++;
						if(!game_flag["���ӱ���ҹ���"]) bg.lfin.change=1;
					}
					else if(NPOS.player_enemy==BUG&&NPOS.emy.id!=-1&&!bugs[NPOS.emy.id].update){//���´���
						int add=NPOS.emy.id;
						Qbug.push(add);bugs[add].update=true;
					}
					else if(NPOS.player_enemy==GHOST&&NPOS.emy.id!=-1&&!ghosts[NPOS.emy.id].update){//���´��� 
						int add=NPOS.emy.id;
						Qghost.push(add);ghosts[add].update=true;
					}
					int tmp=count_around_pos(npos,4,SPACE);
					if(npos.z>height&&pos_in_area2(npos.x,npos.y,1,1,length,width,2)
					&&wall_here(npos)&&tmp<3
					&&(tmp<=1?RAND_BOOL(5):RAND_BOOL(1))){
						NPOS.maze=SPACE;
						position_3D npos2=npos;npos2.z-=height;
						MAP &NPOS2=game_map[npos2.x][npos2.y][npos2.z];
						if(NPOS.in_player_sight==lst_see_time){
							game_flag["�����ڵص�"]=true;
						}
						if((wall_here(npos2)||space_here(npos2))&&count_around_pos(npos2,4,SPACE)<=1&&RAND_BOOL(50)){//���ɳ�Ѩ��
							NPOS2.maze=SPACE;
							bug_nest bns;
							bns.init(npos2);
							bug_nests.push_back(bns);
							int id=int(bug_nests.size())-1;
							Qbug_nest.push(id);
							nest &NST=NPOS.things.nst,&NST2=NPOS2.things.nst;
							NST.exist=NST2.exist=true;NST.id=NST2.id=id;
							NST.to=npos2;NST2.to=npos;
							if(NPOS2.in_player_sight==lst_see_time){
								game_flag["�����ڵص�"]=true;
							}
						}
					}
					if(RAND_BOOL(50)) d=turn(d,TURN_RIGHT);
					else d=turn(d,TURN_LEFT);
					bg.d=d;
				}
			}
		}
			void ghost_move_away(int id){//�ı�λ������ 
				ghost &gt=ghosts[id];
				gt.pos.x=RAND(length-1,1);gt.pos.y=RAND(width-1,1);gt.pos.z=RAND(height,1);
				MAP &NPOS=game_map[gt.pos.x][gt.pos.y][gt.pos.z];
				if(space_here(gt.pos)&&nobody_here(gt.pos)){
					NPOS.player_enemy=GHOST;NPOS.emy.id=id;
					gt.lfin.life=2;gt.lfin.change=false;
					gt.change_pos=false;
				}
				else gt.change_pos=true;
			}
			void ghost_turn(int &d,position_3D u){//����ı䷽��/��������㼣/����������� 
				//�Ա������>����>�㼣>�Ա����㼣>��� 
				vector<int> vd;vd.clear();
				MAP &POS=game_map[u.x][u.y][u.z];
				thing &THING=POS.things;
				position_3D v;
				int snd=-1,fpt=-1,fnear=-1;
				for(int i=0;i<4;i++){
					v=dtp3(u,i,4);
					MAP &NPOS=game_map[v.x][v.y][v.z];
					thing &THING2=NPOS.things;
					if(player_here(v)){//�Ա�����Ҿ��߹�ȥ 
						d=i;
						return;//��߼���ֱ���˳� 
					}
					if(ghost_through(v)){
						if(d==i) vd.push_back(d);
						if(THING.fpt.d!=-1&&THING.fpt.d<4)//�㼣��ǰ������ 
							fpt=THING.fpt.d;
						else if(THING2.fpt.d!=-1)//�Ա����㼣 
							fnear=i;
						vd.push_back(i);
					}
				}
				if(stair_here(u)||POS.things.nst.exist){//����¥��������Ѩ��
					v=u;
					position_3D v2=v;
					if(POS.things.nst.exist) v2=POS.things.nst.to;
					MAP &POS2=game_map[v2.x][v2.y][v2.z];
					if(POS.maze==UPSTAIR) v.z++;
					else if(POS.maze==DOWNSTAIR) v.z--;
					else{//�ƶ�����Ӧ�ĳ�Ѩ��
						v.x=v2.x;
						v.y=v2.y;
						v.z=v2.z;
					}
					MAP &NPOS=game_map[v.x][v.y][v.z];
					thing &THING2=NPOS.things;
					if(player_here(v)){//�Ա�����Ҿ��߹�ȥ 
						d=4;
						return;//��߼���ֱ���˳� 
					}
					if(ghost_through(v)){
						if(d==4) vd.push_back(4);
						if(THING.fpt.d==4)//�㼣����¥ 
							fpt=THING.fpt.d;
						else if(THING2.fpt.d!=-1)//�Ա����㼣 
							fnear=4;
						vd.push_back(4);
					}
				}
				int sz=vd.size();
				if(snd!=-1) d=snd;
				else if(fpt!=-1) d=fpt;
				else if(fnear!=-1) d=fnear;
				else if(sz) d=vd[RAND(sz-1,0)]; 
			}
		void deal_ghost(){
			int ghost_num=Qghost.size();
			while(ghost_num>0){
				ghost_num--;
				int id=Qghost.front();Qghost.pop();
				ghost &gt=ghosts[id];
				MAP &POS=game_map[gt.pos.x][gt.pos.y][gt.pos.z];
				string s=connect_str("��",int_to_str(id));
				if(MHT_DIST2(gt.pos.x,gt.pos.y,gt.pos.z,player1.pos.x,player1.pos.y,player1.pos.z)>200
				&&POS.in_player_sight<lst_see_time)//����Ҿ��볬��200������ҿ����� 
					gt.update=false;//ֹͣ���� 
				if(!gt.update) continue;
				Qghost.push(id);
				if(gt.change_pos){
					ghost_move_away(id);
					continue;
				}
				thing &THING=POS.things;
				if((THING.lsr.exist&&gt.lfin.change!=2)//�����ѱ�����״̬ 
				||(THING.drt.exist1()&&gt.lfin.change!=2)//�����ѱ�����״̬ 
				){
					player1.scr.shoot_hit_times++;
					life_injury &lfin=gt.lfin;
					lfin.life--;lfin.change=2;
					if(POS.in_player_sight==lst_see_time){
						pos_change.push(gt.pos);
						game_flag["����ҹ���"]=true; 
					}
					if(lfin.life<=0){
						player1.scr.kill_count++;player1.scr.kc_change=true;
						POS.emy.dead=true;POS.emy.body_disapp=game_time+200;
						pos_dead.push(gt.pos);
						MAP &POS=game_map[gt.pos.x][gt.pos.y][gt.pos.z];
						POS.player_enemy=NOBODY;POS.emy.id=-1;
						ghost_move_away(id);
						continue;
					}
				}
				else if(!(THING.lsr.exist||THING.drt.exist1())){//Ҫ������һһ��Ӧ 
					if(gt.lfin.change!=0&&POS.in_player_sight==lst_see_time){
						pos_change.push(gt.pos);
						game_flag["����ҹ���"]=true; 
					}
					gt.lfin.change=0;
				}
				if(game_timer[s]>game_time)//ʱ��û�������� 
					continue;
				game_timer[s]=game_time+gt.vlc.wait_time; 
				if(THING.lsr.exist) continue;//�����������޷��ƶ��͹��� 
				position_3D npos=gt.pos;
				int d=gt.d;
				ghost_turn(d,gt.pos); 
				if(stair_here(npos)&&d==4){//����¥ 
					if(game_map[npos.x][npos.y][npos.z].maze==UPSTAIR) npos.z++;
					else npos.z--;
				}
				else if(POS.things.nst.exist&&d==4){//����Ѩ��
					position_3D npos2=POS.things.nst.to;
					MAP &POS2=game_map[npos2.x][npos2.y][npos2.z];
					npos.x=npos2.x;npos.y=npos2.y;npos.z=npos2.z;//�ƶ�����Ӧ�ĳ�Ѩ��
				}
				else{//��ͨ�ƶ� 
					npos.x+=dx4[d];
					npos.y+=dy4[d];
				}
				MAP &NPOS=game_map[npos.x][npos.y][npos.z];
				thing &THING2=NPOS.things;
				if((stair_here(npos)||door_here(npos,1)||space_here(npos))&&nobody_here(npos)){
					POS.player_enemy=NOBODY;POS.emy.id=-1;
					NPOS.player_enemy=GHOST;NPOS.emy.id=id;
					if(POS.in_player_sight==lst_see_time&&gt.pos.z==player1.pos.z){
						player1.enemy_move=true;
						pos_change.push(gt.pos);
					}
					if(NPOS.in_player_sight==lst_see_time&&npos.z==player1.pos.z){
						player1.enemy_move=true;
						pos_change.push(npos);
					}
					gt.pos=npos;
				}
				else{
					if(NPOS.player_enemy==PLAYER){
						player_reduce_blood(10.0/gt.vlc.speed);
					}
					else if(NPOS.player_enemy==BUG&&NPOS.emy.id!=-1&&!bugs[NPOS.emy.id].update){//���´���
						int add=NPOS.emy.id;
						Qbug.push(add);bugs[add].update=true;
					}
					else if(NPOS.player_enemy==GHOST&&NPOS.emy.id!=-1&&!ghosts[NPOS.emy.id].update){//���´��� 
						int add=NPOS.emy.id;
						Qghost.push(add);ghosts[add].update=true;
					}
					gt.d=d;
				}
			}
		}
	void deal_enemy(){
		deal_bug();
		deal_ghost();
	}
				void calculate_vision(position_3D pos,int dir){//������posλ����d���򿴵���Ұ
 					position_3D npos=pos;
 					do{
 						npos=dtp3(npos,dir,4);
 						if(!pos_in_area2(npos.x,npos.y,1,1,length,width)) return;
						//������ͼ��Χ�Ϳ���ֱ��������
						MAP &POS=game_map[npos.x][npos.y][npos.z];
						if(POS.in_player_sight<game_time
						//&&!screen_pos.count(position_3Dtoscr(npos))//��Ļ�����λ��û����ʾ����
						){
 							pos_in_sight.push(npos);
							//��ҿ��ü��ĸ������
							screen_z[position_3Dtoscr(npos)]=npos.z;//�޸���Ļ�����λ��������¥�㣨����֮ǰ�� 
 							POS.in_player_sight=game_time;//�����Ϸ��ͼ
							if(POS.player_enemy==BUG&&POS.emy.id!=-1){//�ܿ����������
								int id=POS.emy.id;
								bug &bg=bugs[id];
								if(!bg.update){
									Qbug.push(id);
									bg.update=true;
								}
							}
							else if(POS.player_enemy==GHOST&&POS.emy.id!=-1){//�ܿ��������
								int id=POS.emy.id;
								ghost &gt=ghosts[id];
								if(!gt.update){
									Qghost.push(id);
									gt.update=true;
								}
							}
						}
 						if(see_through(npos,2)){
							int d1=turn(dir,TURN_LEFT),d2=turn(dir,TURN_RIGHT);
							position_3D pos1=dtp3(npos,d1,4),pos2=dtp3(npos,d2,4);
							if(game_map[pos1.x][pos1.y][pos1.z].in_player_sight<game_time){
 								pos_in_sight.push(pos1);
								screen_z[position_3Dtoscr(pos1)]=pos1.z;
 								game_map[pos1.x][pos1.y][pos1.z].in_player_sight=game_time;
							}
							if(game_map[pos2.x][pos2.y][pos2.z].in_player_sight<game_time){
 								pos_in_sight.push(pos2);
								screen_z[position_3Dtoscr(pos2)]=pos2.z;
 								game_map[pos2.x][pos2.y][pos2.z].in_player_sight=game_time;
							}
						}
						else{
							int d1=turn(dir,TURN_LEFT),d2=turn(dir,TURN_RIGHT),d3=turn(dir,TURN_BACK);
							position_3D pos1=dtp3(npos,d1,4),pos2=dtp3(npos,d2,4),pos3=dtp3(pos1,d3,4);
							if(game_map[pos1.x][pos1.y][pos1.z].in_player_sight<game_time
							&&see_through(pos3,2)){
 								pos_in_sight.push(pos1);
								screen_z[position_3Dtoscr(pos1)]=pos1.z;
 								game_map[pos1.x][pos1.y][pos1.z].in_player_sight=game_time;
							}
							pos3=dtp3(pos2,d3,4);
							if(game_map[pos2.x][pos2.y][pos2.z].in_player_sight<game_time
							&&see_through(pos3,2)){
 								pos_in_sight.push(pos2);
								screen_z[position_3Dtoscr(pos2)]=pos2.z;
 								game_map[pos2.x][pos2.y][pos2.z].in_player_sight=game_time;
							}
						}
						/*
						if(game_map[npos.x][npos.y][npos.z].things.mirrors.exist){
							mirror &MIRROR=game_map[npos.x][npos.y][npos.z].things.mirrors;
							int d1=turn(dir,TURN_LEFT),d2=turn(dir,TURN_RIGHT),d3=MIRROR.dir;
							if(MIRROR.side==1){
								if(dir==d3) calculate_vision(npos,d2);
								else if(d2==d3) calculate_vision(npos,d1);
							}
							else{
								if(dir%2==d3) calculate_vision(npos,d2);
								else calculate_vision(npos,d1);
							}
						}
						else if(player1.up_down){//�����ͨ��¥�ݿ�¥��/�� 
 							if(game_map[npos.x][npos.y][npos.z].maze==UPSTAIR) npos.z++;
 							else if(game_map[npos.x][npos.y][npos.z].maze==DOWNSTAIR) npos.z--;
 							//����¥��Ҫ�ı�����
						}*/
					}
					while(see_through(npos,2));//���߿��Դ����ͼ������㣨���ٻῴ��һ�����ӣ�
				}
			void player_calculate_vision1(){//������ҵ���Ұ
				//if(!screen_pos.count(position_3Dtoscr(player1.pos))//��Ļ�����λ��û����ʾ����
				//){
				//û�п�������ط�
					pos_in_sight.push(player1.pos);
					//���������ڵ�λ�á����
				//}
				screen_z[position_3Dtoscr(player1.pos)]=player1.pos.z;//�޸���Ļ�����λ��������¥��
				game_map[player1.pos.x][player1.pos.y][player1.pos.z].in_player_sight=game_time;
				for(int i=0;i<4;i++){//�ĸ����򶼼�����Ұ 
					calculate_vision(player1.pos,i);
				}
			}
			void player_calculate_vision2(position_3D pos){
				int x=pos.x,y=pos.y,z=pos.z;
				queue<position_3D> visible_stair;//��Ұ��Χ�ڵ�¥��λ�� 
				memset(vst,0,sizeof(vst));
				while(!Q.empty()) Q.pop();
				vst[x][y][z]=1;
				pos_in_sight.push(pos);
				screen_z[position_3Dtoscr(pos)]=z;
				game_map[x][y][z].in_player_sight=game_time;
				Q.push(pos);
				while(!Q.empty()&&(cnt_visible[0]||cnt_visible[1]||cnt_visible[2]||cnt_visible[3])){
					position_3D u=Q.front();Q.pop();
					for(int i=0;i<4;i++){
						position_3D v=u;v.x+=dx4[i];v.y+=dy4[i];
						if(!pos_in_area2(v.x,v.y,1,1,length,width)||vst[v.x][v.y][z]) continue;
						vst[v.x][v.y][z]=1;
						if(invisible(v,pos)) continue;
						MAP &POS=game_map[v.x][v.y][z];
						if(POS.in_player_sight<game_time){
							pos_in_sight.push(v);
							screen_z[position_3Dtoscr(v)]=z;
							POS.in_player_sight=game_time;
							if(POS.player_enemy==BUG&&POS.emy.id!=-1){//�ܿ����������
								int id=POS.emy.id;
								bug &bg=bugs[id];
								if(!bg.update){
									Qbug.push(id);
									bg.update=true;
								}
							}
							else if(POS.player_enemy==GHOST&&POS.emy.id!=-1){//�ܿ��������
								int id=POS.emy.id;
								ghost &gt=ghosts[id];
								if(!gt.update){
									Qghost.push(id);
									gt.update=true;
								}
							}
						}
						if(wall_here(v)||door_here(v,0)) mark_occlusion(v,pos);
						else Q.push(v); 
						if(stair_here(v)) visible_stair.push(v); 
					}
				}
				/*
				while(!visible_stair.empty()&&player1.up_down){//�����ͨ��¥�ݿ�¥��/�� some bugs here
					for(int i=0;i<4;i++) cnt_visible[i]=360;
					memset(occlusion,0,sizeof(occlusion));
					position_3D u=visible_stair.front();visible_stair.pop();
					mark_occlusion(u,pos);
					for(int i=0;i<4;i++){//ȫ�������� 
						cnt_visible[i]=360-cnt_visible[i]; 
						for(int j=0;j<360;j++) occlusion[i][j]=!occlusion[i][j];
					}
					position_3D v=u;
					if(game_map[u.x][u.y][u.z].maze==UPSTAIR) v.z++;
					else v.z--;
					player_calculate_vision2(v);
				}*/
			}
			void player_use_item(){
				item &ITEM=player1.items;
				vector<int> &v=ITEM.item_lab;
				int x=player1.items.select_number;
				if(x<0||x>=v.size()) return;
				int k=v[x];
				life_injury &lfin=player1.vts.lfin;
				strength &stg=player1.vts.stg;
				bool flag=false;
				int add=(1<<(EFFECT_OF_FOOD+AS1-k-1))*5;
				switch(k){
					case AS1:case AS2:case AS3:
						lfin.life+=add;lfin.recovery+=add;
						lfin.change=true;
						ITEM.foods.food_cnt[0][k-AS1]--;
						if(!ITEM.foods.food_cnt[0][k-AS1]) flag=true;
						break;
					case AL1:case AL2:case AL3:
						stg.physical_strength+=(1<<(EFFECT_OF_FOOD+AL1-k-1))*10;
						stg.change=true;
						ITEM.foods.food_cnt[1][k-AL1]--;
						if(!ITEM.foods.food_cnt[1][k-AL1]) flag=true;
						break;
				}
				if(flag) player1.items.item_lab.erase(v.begin()+x);
				player1.items.il_change=true;
			} 
						void player_shoot_laser_beam(position_3D pos,int dir,int d=4){
		 					position_3D npos=pos;
			 				npos=dtp3(npos,dir,d);
			 				bool hit=false;//�Ƿ����е���
							player1.scr.shoot_times++;
			 				while(1){
			 					if(!pos_in_area2(npos.x,npos.y,1,1,length,width,2)) return;
			 					if(!light_through(npos))//������Դ����ͼ�������
									return;
			 					MAP &NPOS=game_map[npos.x][npos.y][npos.z];
								if(NPOS.player_enemy==PLAYER) return;
			 					thing &THING=NPOS.things;
			 					THING.lsr.exist=true;THING.lsr.laser_beam=dir;
								laser_beams.push(npos);
			 					if(NPOS.in_player_sight==lst_see_time) pos_change.push(npos);
			 					if(nobody_here(npos)&&THING.nst.exist&&THING.nst.id!=-1){//���г��ӵĳ�Ѩ��
			 						position_3D npos2=THING.nst.to;
			 						MAP &NPOS2=game_map[npos2.x][npos2.y][npos2.z];
			 						thing &THING2=NPOS2.things;
								 	nest &NST=THING.nst,&NST2=THING2.nst;
								 	int id=NST.id;
								 	bug_nest &bns=bug_nests[id];
								 	bns.lfin.life--;bns.lfin.change=2;
								 	if(bns.lfin.life<=0){
								 		NST.exist=false;
										NST.id=-1;
										NST2.exist=false;
										NST2.id=-1;
									}
								}
								if(THING.mirrors.exist){//�������Ӿͷ��� 
									mirror &MIRROR=THING.mirrors;
									int d1=turn(dir,TURN_LEFT),d2=turn(dir,TURN_RIGHT),d3=MIRROR.dir;
									if(MIRROR.side==1){
										if(dir==d3) player_shoot_laser_beam(npos,d2);
										else if(d2==d3) player_shoot_laser_beam(npos,d1);
									}
									else{
										if(dir%2==d3) player_shoot_laser_beam(npos,d2);
										else player_shoot_laser_beam(npos,d1);
									}
									return;
								}
			 					npos=dtp3(npos,dir,d);
							}
						}
					void player_use_laser_gun012(){
						weapon &wpn=player1.items.wpn;
						laser_gun &lsg=wpn.lsg;
						position_3D npos=dtp3(player1.pos,player1.d,4);
						if(light_through(npos)){//������1���������� 
							game_timer["���������"]=game_time+lsg.last_time;game_timer["����ǹ��ȴ"]=game_timer["���������"]+lsg.cool_time;
							lsg.energy--;
							wpn.data_change=true; 
							player1.use_weapon=true;
							player_shoot_laser_beam(player1.pos,player1.d);
						}
						if(lsg.kind==1){
							int d2=turn(player1.d,TURN_LEFT),d3=turn(player1.d,TURN_RIGHT);
						 	position_3D npos2=dtp3(player1.pos,d2,4),npos3=dtp3(player1.pos,d3,4);
							if(light_through(npos2)){//������1���������� 
								game_timer["���������"]=game_time+lsg.last_time;game_timer["����ǹ��ȴ"]=game_timer["���������"]+lsg.cool_time;
								lsg.energy--;
								wpn.data_change=true; 
						 		player1.use_weapon=true;
								player_shoot_laser_beam(npos2,player1.d);
							}
							if(light_through(npos3)){//������1���������� 
						 		game_timer["���������"]=game_time+lsg.last_time;game_timer["����ǹ��ȴ"]=game_timer["���������"]+lsg.cool_time;
						 		lsg.energy--;
								wpn.data_change=true; 
								player1.use_weapon=true;
								player_shoot_laser_beam(npos3,player1.d);
							}
						}
					  	else if(lsg.kind==2){
					 	}
					}
				void player_use_laser_gun(){
					weapon &wpn=player1.items.wpn;
					laser_gun &lsg=wpn.lsg;
					switch(lsg.kind){
						case 0:case 1:case 2:
							player_use_laser_gun012();
							break;
						case 3:
							for(int i=0;i<4;i++){
								position_3D npos=dtp3(player1.pos,i,4);
								if(light_through(npos)){//������1���������� 
									game_timer["���������"]=game_time+lsg.last_time;game_timer["����ǹ��ȴ"]=game_timer["���������"]+lsg.cool_time;
									lsg.energy--;
									wpn.data_change=true; 
									player1.use_weapon=true;
									player_shoot_laser_beam(player1.pos,i);
								}
							}
							break;
						case 4:
							break;
					}
				}
			    void player_use_dart(int dir){//�����ӳ��ķ��ڲ�������ڶ��� 
					flying_dart fdt;
					dart &DRT=game_map[player1.pos.x][player1.pos.y][player1.pos.z].things.drt; 
					weapon &wpn=player1.items.wpn;
					throwing_dart &drt=wpn.drt;
					fdt.init(player1.pos,dir);
					darts.push(fdt);
					DRT.num[1]++;DRT.d[1]=fdt.d;
					player1.scr.shoot_times++;
					drt.num--;wpn.data_change=true;
					game_timer["�ӷ�����ȴ"]=game_time+200;
				}
			void player_use_weapon(){
				weapon &wpn=player1.items.wpn;
				laser_gun &lsg=wpn.lsg;
				throwing_dart &drt=wpn.drt;
				switch(wpn.select_wpn){
					case LSG:
						//lsg.energy+=8;
						if(lsg.energy>=lsg.kd_energy[lsg.kind]&&game_timer["����ǹ��ȴ"]<=game_time) player_use_laser_gun();
						break;
					case DART:
						if(drt.num>0&&game_timer["�ӷ�����ȴ"]<=game_time
						&&!game_map[player1.pos.x][player1.pos.y][player1.pos.z].things.drt.exist1()) player_use_dart(player1.d);
						break;
				}
 			}
				    void player_erase_spear(){//�����ϴ���ʾ��ì 
			    		while(!spears.empty()){
			    			position_3D u=spears.front();spears.pop();
			    			if(game_map[u.x][u.y][u.z].in_player_sight==lst_see_time)
								pos_change.push(u),game_flag["���ì�ı�λ��"]=true;
				    		MAP &POS=game_map[u.x][u.y][u.z];
				    		POS.things.spr.exist=false;
				    	}
				    }
				    void player_use_spear(position_3D pos,int dir,int length){ 
						weapon &wpn=player1.items.wpn;
			    		position_3D npos=dtp3(pos,dir,4),lpos=pos;
			    		int i=1;
			    		if(!(wall_here(npos)||door_here(npos,0)||i>length)){
							game_flag["���ì�ı�λ��"]=true;
							//wpn.hsr.endurance--;
							//wpn.data_change=true; 
						}
			    		while(1){
			    			MAP &POS=game_map[npos.x][npos.y][npos.z];
			        		if(wall_here(npos)||door_here(npos,0)||i>length){//ì����ǽ��ì�ĳ��Ȳ��� 
			    				MAP &LPOS=game_map[lpos.x][lpos.y][lpos.z];
			    				if(i!=1) LPOS.things.spr.head=true;
			        			break;
						    }
				    		thing &THING=POS.things;
				    		spear &spr=THING.spr;
				    		spr.exist=true;spr.d=dir;spr.head=false;
				    		pos_change.push(npos);spears.push(npos);
				    		lpos=npos;npos=dtp3(npos,dir,4);i++;
				    	}
			    	}
			void player_update_spear(){//ì�Զ�����
				player_erase_spear();
				if(player1.items.wpn.hsr.endurance>0) player_use_spear(player1.pos,player1.d,2); 
			}
		void player_detect_move(){
			int maze;
			vector<int> &v=player1.items.item_lab;
			position_3D npos;
			npos=player1.pos;
			thing &THING=game_map[player1.pos.x][player1.pos.y][player1.pos.z].things;
			int d=-1;
			if(_kbhit()){
				switch(_getch()){//��ⰴ�� 
					case PRESS_KEY_UP:
						d=0;
						break;
					case PRESS_KEY_RIGHT:
						d=1;
						break;
					case PRESS_KEY_DOWN:
						d=2;
						break;
					case PRESS_KEY_LEFT:
						d=3;
						break;
					case PRESS_KEY_SPACE:
						maze=game_map[player1.pos.x][player1.pos.y][player1.pos.z].maze;
						if(!player1.up_down&&(UPSTAIR<=maze&&maze<=DOWNSTAIR||THING.nst.exist)){//���������¥�������Ѩ�� 
							THING.fpt.d=4;//��¼�㼣
							if(maze==UPSTAIR) npos.z++;
							else if(maze==DOWNSTAIR) npos.z--;
							else npos=THING.nst.to;
						}
						else{
							player1.up_down^=1;
							player1.ud_change=true;
						}
						break;
					case PRESS_KEY_F:
						player1.action_kind=CHOOSE_ITEM;player1.ak_change=true;
						return;
					case PRESS_KEY_E:
						player_use_item();
						return;
					case PRESS_KEY_V:
						if(player1.action_kind==RUN) player1.action_kind=WALK;
						else player1.action_kind=RUN;
						player1.ak_change=true;
						break;
					case PRESS_KEY_S:
						player_use_weapon();
						return;
					case PRESS_KEY_ENTER:
						game_pause=!game_pause;
						game_flag["��Ϸ��ͣ/����"]=true; 
						return;
				}
			}
			if(d!=-1){
				if(d==player1.d&&player1.action_kind==WALK||player1.action_kind==RUN){//״̬�ǡ����ߡ�ת��ʱҪ������ 
					THING.fpt.d=d;//��¼�㼣
					npos.x+=dx4[d];
					npos.y+=dy4[d];
				}
			}
			else if(!player1.lst_ud&&stair_here(npos)&&player1.up_down){
				player1.lst_ud=true;//��ֹ��ס
				THING.fpt.d=4;//��¼�㼣
				if(game_map[npos.x][npos.y][npos.z].maze==UPSTAIR) npos.z++;
				else npos.z--;
			}
			else if(!player1.lst_enter&&THING.nst.exist&&player1.up_down){
				player1.lst_enter=true;//��ֹ��ס
				THING.fpt.d=4;//��¼�㼣
				npos=THING.nst.to;
			}
			if(player1.pos!=npos){//�����Ǹı���λ�� 
				int nmaze=game_map[npos.x][npos.y][npos.z].maze;
				if(!nobody_here(npos)){//�����б������
					player_reduce_blood(10.0/player1.vlc.speed);
					if(game_map[npos.x][npos.y][npos.z].player_enemy==BUG&&game_map[npos.x][npos.y][npos.z].emy.id!=-1){
						int id=game_map[npos.x][npos.y][npos.z].emy.id;
						bug &bg=bugs[id];
						bg.lfin.life++;bg.lfin.change=1;//������Ѫ 
					}
				}
				else if(nmaze==SPACE||nmaze==EXIT//�����ǿյء�����
				||(DOOR1<=nmaze&&nmaze<=DOOR4&&game_map[npos.x][npos.y][npos.z].door_state)//���ŵ���  
				||(UPSTAIR<=nmaze&&nmaze<=DOWNSTAIR)//����¥��
				){
					game_map[player1.pos.x][player1.pos.y][player1.pos.z].player_enemy=NOBODY;
					game_map[npos.x][npos.y][npos.z].player_enemy=PLAYER;
					player1.move=1;
					if(nmaze==EXIT){
						game_end=game_success=true;
						return;
					}
				}
				else if(DOOR1<=nmaze&&nmaze<=DOOR4//���Ź���
				&&player1.items.keys.door_keys[nmaze-DOOR1]>=1){//������Կ�� 
					game_map[player1.pos.x][player1.pos.y][player1.pos.z].player_enemy=NOBODY;
					game_map[npos.x][npos.y][npos.z].player_enemy=PLAYER;
					game_map[npos.x][npos.y][npos.z].door_state=true;
					int &dk=player1.items.keys.door_keys[nmaze-DOOR1+KEY1-1];
					dk--;player1.items.num_change=true;
					if(dk==0){
						v.erase(find(v.begin(),v.end(),nmaze-DOOR1+K1));
						player1.items.il_change=true;
					} 
					player1.move=1;
				}
			}
			if(player1.move) player1.pos=npos;
			if(d!=-1&&player1.d!=d){
				if(!player1.move) player1.flash=true,pos_change.push(player1.pos);
				player1.d_change=true;player1.d=d;
			}
			if((player1.d_change||player1.move)&&player1.items.wpn.select_wpn==SPR) player_update_spear();
			if(!stair_here(player1.pos)) player1.lst_ud=false;
			if(!THING.nst.exist) player1.lst_enter=false;
		}
			void player_check_key(thing &THING,item &items,vector<int> &v){//��Կ�� 
				int &nkey=THING.key;
				int &dk=items.keys.door_keys[nkey-KEY1];
				if(nkey){
					if(!dk){
						v.push_back(nkey-KEY1+K1);
						items.il_change=true;
					} 
					dk++;items.num_change=true;
					nkey=0; 
				}
			}
			void player_check_food(thing &THING,item &items,vector<int> &v){//��ʳ�� 
				food &nfood=THING.foods;
				bool &nexist=nfood.exist;
				if(nexist){
					int& nkind=nfood.kind,neffect=nfood.effect;
					int &fc=items.foods.food_cnt[nkind-ADDS][neffect-1];
					if(!fc){
						v.push_back(AS1+(nkind-1)*EFFECT_OF_FOOD+(neffect-1));
						items.il_change=true;
					} 
					fc++;items.num_change=true;
					nexist=nkind=neffect=0; 
				}
			}
			void player_check_wpn_energy_edc(thing &THING,item &items){//��������;öȻظ� 
				weapon_energy_edc &wee=THING.wee;
				int &ly=items.wpn.lsg.energy,&hec=items.wpn.hsr.endurance,&num=wee.num,&kind=wee.kind;
				bool &dc=items.wpn.data_change,&ex=wee.exist;
				if(ex){
					switch(kind){
						case 0:ly+=num;num=ex=0;dc=1;break;
						case 1:hec+=num;num=ex=0;dc=1;break;
					}
				}
			}
			void player_check_wpn(thing &THING,item &items){//������
				dart &DRT=THING.drt;
				weapon &wpn=items.wpn;
				int &dnum=wpn.drt.num;
				if(DRT.exist0()){//���ϵķ��� 
					dnum+=DRT.num[0];
					DRT.num[0]=0;
					wpn.data_change=true;
				}
			}
		void player_check_thing(){//��Ҽ�ʰ��Ʒ 
			thing &THING=game_map[player1.pos.x][player1.pos.y][player1.pos.z].things;
			if(THING.nothing()) return;//����û����ֱ���˳� 
			item &items=player1.items;
			vector<int> &v=items.item_lab;
			player_check_key(THING,items,v);
			player_check_food(THING,items,v);
			player_check_wpn_energy_edc(THING,items);
			player_check_wpn(THING,items);
		}
		void player_choose_item(){
			if(_kbhit()){
				switch(_getch()){//��ⰴ�� 
					case PRESS_KEY_DOWN:
						player1.action_kind=CHANGE_WPN;
						player1.ak_change=true;
						break;
					case PRESS_KEY_RIGHT:
						player1.items.select_number=min(player1.items.select_number+1,9);
						player1.items.sn_change=true;
						break;
					case PRESS_KEY_LEFT:
						player1.items.select_number=max(player1.items.select_number-1,0);
						player1.items.sn_change=true;
						break;
					case PRESS_KEY_F:
						player1.action_kind=RUN;player1.ak_change=true;
						break;
					case PRESS_KEY_E:
						player_use_item();
						break;
					case PRESS_KEY_V:
						player1.action_kind=WALK;
						player1.ak_change=true;
						break;
					case PRESS_KEY_ENTER:
						game_pause=!game_pause;
						game_flag["��Ϸ��ͣ/����"]=true; 
						return;
				}
			}
		}
			void player_weapon_mode(){//��������ģʽ 
				item &items=player1.items;
				weapon &wpn=items.wpn;
				laser_gun &lsg=wpn.lsg;
				switch(wpn.select_wpn){
					case LSG:
						lsg.kind=(lsg.kind+1)%lsg.kd_cnt;
						wpn.mode_change=true;
						break;
				}
			}
		void player_update_weapon(){//�������� 
			item &items=player1.items;
			weapon &wpn=items.wpn;
			if(_kbhit()){
				switch(_getch()){//��ⰴ�� 
					case PRESS_KEY_UP:
						player1.action_kind=CHOOSE_ITEM;
						player1.ak_change=true;
						break;
					case PRESS_KEY_RIGHT:
						wpn.select_wpn=(wpn.select_wpn+1)%wpn.wcnt;
						wpn.sw_change=true;
						break;
					case PRESS_KEY_LEFT:
						wpn.select_wpn=(wpn.select_wpn-1+wpn.wcnt)%wpn.wcnt;
						wpn.sw_change=true;
						break;
					case PRESS_KEY_SPACE:
						player_weapon_mode();
						break;
					case PRESS_KEY_F:
						player1.action_kind=RUN;player1.ak_change=true;
						break;
					case PRESS_KEY_E:
						player_use_item();
						break;
					case PRESS_KEY_V:
						player1.action_kind=WALK;
						player1.ak_change=true;
						break;
					case PRESS_KEY_ENTER:
						game_pause=!game_pause;
						game_flag["��Ϸ��ͣ/����"]=true; 
						return;
				}
				if(wpn.sw_change){//�Զ����� 
					player_erase_spear();
					if(wpn.select_wpn==SPR) player_use_spear(player1.pos,player1.d,2);
				}
			}
		}
		void player_lfin_update(){
			if(player1.color!=0){
				player1.flash=true;
				pos_change.push(player1.pos);
			}
			if(player1.move){
				player1.vts.stg.change=1;
				player1.vts.stg.physical_strength--;
				if(player1.vts.stg.physical_strength<0) player1.vts.stg.physical_strength=0;
				game_timer["��������ָ�"]=max(game_timer["��������ָ�"],game_time+player1.vts.stg.recovery_time);
			}
			else if(game_timer["��������ָ�"]<=game_time&&player1.vts.stg.physical_strength<100){
			//�����ָ�ʱ���ѵ� 
				player1.vts.stg.change=1;
				player1.vts.stg.physical_strength++;
				game_timer["��������ָ�"]+=player1.vts.stg.recovery_time;
			}
			player1.vlc.speed=pow(player1.vts.stg.physical_strength,2)/double(100);player1.vlc.vt();
		}
		void player_sight_update(){
			if(player1.move||player1.ud_change||game_flag["�����ڵص�"]){
				player_calculate_vision2(player1.pos);
				player_calculate_vision1();
				lst_see_time=game_time;//������Ұ 
			}
		}
		void player_others(){//�������� 
			if(player1.items.wpn.hsr.endurance==0) player_erase_spear();//ì���;ö��ù��Զ�ɾ�� 
		}
	void deal_player(){
		switch(player1.action_kind){
			case RUN:case WALK:
				if(game_timer["����ƶ�"]<=game_time){//����ƶ�ʱ���ѵ� 
					player_detect_move();
					player_check_thing();
					game_timer["����ƶ�"]+=player1.vlc.wait_time;
				}
				break;
			case CHOOSE_ITEM:
				player_choose_item();
				break;
			case CHANGE_WPN:
				player_update_weapon();
				break;
		}
		player_lfin_update();
		player_sight_update();
		player_others();
	}
		void shoot_laser_beam(){//��������� 
			if(laser_beams.size()&&game_timer["���������"]<=game_time){
				player1.use_weapon=true;
				while(!laser_beams.empty()){
					position_3D u=laser_beams.front();laser_beams.pop();
					MAP &POS=game_map[u.x][u.y][u.z];
					POS.things.lsr.exist=false;
					if(POS.in_player_sight==lst_see_time) pos_change.push(u);
					if(!POS.things.nst.exist||POS.things.nst.id==-1) continue;
					bug_nest &bgn=bug_nests[POS.things.nst.id];
					if(bgn.lfin.change!=0) bgn.lfin.change=0;//��Ѩ�����е���˸ֹͣ 
				}
			}
		}
		void clean_dead(){//���ʬ�� 
			while(!pos_dead.empty()){
				position_3D u=pos_dead.front();
				MAP &POS=game_map[u.x][u.y][u.z];
				if(POS.emy.body_disapp>game_time) return;//�����ʬ�廹û������ʱ�䣬�������Ĳ��ÿ���
				if(POS.in_player_sight=lst_see_time){
					pos_change.push(u);
					game_flag["���ʬ��"]=true;
				}
				pos_dead.pop(); 
			}
		}
			void dart_fall(position_3D pos){//�������� 
				MAP &POS=game_map[pos.x][pos.y][pos.z];
				dart &DRT=POS.things.drt;
				DRT.num[1]--;
				DRT.num[0]++;DRT.d[0]=RAND(3,0);
				if(POS.in_player_sight==lst_see_time){//������Ļ 
					game_flag["���ڱ仯"]=true;
					pos_change.push(pos); 
				}
			}
		void throw_dart(){//���ڷ��� 
			int num=darts.size();
			if(num==0) return;
			while(num--){
				flying_dart fdt=darts.front();darts.pop();
				MAP &POS=game_map[fdt.pos.x][fdt.pos.y][fdt.pos.z];
				dart &DRT=POS.things.drt;
				if(fdt.time<=game_time) fdt.time=game_time+fdt.vlc.wait_time;
				else{//û���ƶ�ʱ�� 
					darts.push(fdt);
					continue;
				}
				/* 
				if(enemy_here(fdt.pos)){
					dart_fall(fdt.pos);
					continue;//�������˾�ֹͣ���� 
				}*/
				position_3D npos=dtp3(fdt.pos,fdt.d,4);//��һ���ط� 
				MAP &NPOS=game_map[npos.x][npos.y][npos.z];
				dart &NDRT=NPOS.things.drt;
				if(pos_in_area2(npos.x,npos.y,1,1,length,width,2)&&!(wall_here(npos)||door_here(npos,0))){
					if(game_map[fdt.pos.x][fdt.pos.y][fdt.pos.z].in_player_sight==lst_see_time){//������Ļ 
						game_flag["���ڱ仯"]=true;
						pos_change.push(fdt.pos); 
					}
					if(game_map[npos.x][npos.y][npos.z].in_player_sight==lst_see_time){//������Ļ 
						game_flag["���ڱ仯"]=true;
						pos_change.push(npos); 
					}
					DRT.num[1]--;
					fdt.pos=npos;
					NDRT.num[1]++;NDRT.d[1]=fdt.d;
					darts.push(fdt);//���·Żض��� 
				}
				else dart_fall(fdt.pos);//����ǽ����ϵ��ž�ֹͣ����
			}
		}
		void open_close_treasure(){
		}
		void on_off_candle(){
		}
		void move_barrel(){
		}
		void on_off_lamp(){
		}
		void delay_boom_TNT(){
		}
		void pour_water(){
		}
		void pour_magma(){
		}
	void deal_item(){
		shoot_laser_beam();
		clean_dead(); 
		throw_dart();
		open_close_treasure();
		on_off_candle();
		move_barrel();
		on_off_lamp();
		delay_boom_TNT();
		pour_water();
		pour_magma();
	}
		void game_map_update(){//������ʾ����Ļ�ϵ���Ϸ��ͼ 
			if(player1.move||player1.ud_change||game_flag["�����ڵص�"]){
			//����ƶ����Ƿ�ͨ��¥�ݿ��ı��˻���������߷�Χ�����˵ص� 
				game_flag["�����ڵص�"]=false; 
				while(!pos_lst_sight.empty()){//�ȴ����ϴ���ʾ����Ļ�� 
					position_2D spos=pos_lst_sight.front();pos_lst_sight.pop();
					if(!screen_z.count(spos)){
						formatted_output(1,game_map_area,spos.x,spos.y,0x00,"  ");//�����Ļ�����λ�� 
						if(screen_pos.count(spos)) screen_pos.erase(spos);//��Ļ�����λ�õ���ʾ���ݱ����ò����ˣ�ɾ�� 
						continue;
					}
					position_3D npos=position_scrto3D(spos,screen_z[spos]);
					//��Ļ����ת��Ϊ��Ϸ��ͼ���꣬z���껻��������Ļ�϶�Ӧλ��Ҫ��ʾ��¥��
					string ncode=screen_display_coding(npos);
					if(ncode!=screen_pos[spos]){//����Ҫ��ʾ�����ݱ�����ϴβ�ͬ
						print_game_map_pos(npos);//����µ����� 
						screen_pos[spos]=ncode;//��Ļ�����λ�õ���ʾ���ݱ������ 
					}
					pos_backup.push(spos);//����Ļ�����λ�÷ŵ����ݶ�����
				}
				while(!pos_in_sight.empty()){//�ٴ�����������ʾ����Ļ�� 
					position_3D npos=pos_in_sight.front();pos_in_sight.pop();
					position_2D spos=position_3Dtoscr(npos);//npos����Ļ�ϵĶ�Ӧλ�� 
					print_game_map_pos(npos);//��� 
					screen_pos[spos]=screen_display_coding(npos);//�������λ�õ���Ļ��Ϣ
					pos_backup.push(spos);//�����λ�÷ŵ����ݶ����� 
				}
				while(!pos_backup.empty()){//���ݶ��е�����ȫ��copy���ϴ���ʾ����Ļ�ģ����»غ��ã� 
					pos_lst_sight.push(pos_backup.front()); 
					pos_backup.pop();
				}
				formatted_output(1,vital_signs_area,1,6,0x0f,"1");
			}
			else if(player1.enemy_move||player1.flash||player1.use_weapon
			||game_flag["���ӱ���ҹ���"]||game_flag["���ʬ��"]||game_flag["���ì�ı�λ��"]||game_flag["���ڱ仯"]){
			//���û�ƶ�����ʾ����Ϸ��ͼ�����б�ı仯������ͻȻð��һ���������⴦��
				while(!pos_change.empty()){
					position_3D npos=pos_change.front();pos_change.pop();
					position_2D spos=position_3Dtoscr(npos);//npos����Ļ�ϵĶ�Ӧλ�� 
					print_game_map_pos(npos);//��� 
					screen_pos[spos]=screen_display_coding(npos);//�������λ�õ���Ļ��Ϣ
					pos_lst_sight.push(spos);//��ӵ��ϴ���ʾ����Ļ�ģ����»غ��ã�
				}
				formatted_output(1,vital_signs_area,1,6,0x0f,"2");
			}
			else formatted_output(1,vital_signs_area,1,6,0x0f,"0");
			if(player1.d_change){//��ҷ���ı� 
				string s;
				switch(player1.d){
					case 0:s="��";break;
					case 1:s="��";break;
					case 2:s="��";break;
					case 3:s="��";break;
				}
				game_map_area.output_frame(s,0x0f,0);
			}
		}
			void lives_update(){//��������������� 
				if(player1.vts.lfin.change||player1.d_change||player1.items.sn_change){
					if(player1.vts.lfin.life<10) formatted_output(1,vital_signs_area,1,1,0x0c,"������Σ��");
					else formatted_output(1,vital_signs_area,1,1,0x0c
						,connect_str("����ֵ��",repeat_char(char(3),(player1.vts.lfin.life+5)/10.0),"          "));
				}
				if(player1.vts.stg.change||player1.d_change||player1.items.sn_change){
					formatted_output(1,vital_signs_area,1,2,0x0a
					,connect_str("����ֵ��",int_to_str(player1.vts.stg.physical_strength),"%  "));
					if(player1.vts.stg.physical_strength<25)
						formatted_output(1,vital_signs_area,14,2,0x0a,"�����漱��");
					else formatted_output(1,vital_signs_area,14,2,0x0a,"          ");
				}
			}
			void weapon_update(){//����״̬���� 
				if(player1.ak_change||player1.items.wpn.data_change||player1.items.wpn.sw_change) player1.items.wpn.print1();
				if(player1.items.wpn.mode_change||player1.items.wpn.sw_change) player1.items.wpn.print2();
				if(player1.items.wpn.sw_change) player1.items.wpn.print3();
			}
			void score_update(){//�������� 
				if(player1.scr.kc_change)
					formatted_output(1,vital_signs_area,1,3,0x0e
					,connect_str("��ɱ����",int_to_str(player1.scr.kill_count)));
			}
			void state_update(){//���״̬���� 
				if(player1.ud_change||player1.d_change||player1.items.sn_change){
					if(player1.up_down)
						formatted_output(1,vital_signs_area,1,4,0x0f,"�Զ�����¥���ɲ鿴¥��/�µĳ�����");
					else formatted_output(1,vital_signs_area,1,4,0x0f,"�ֶ������ո��������¥           ");
				}
				if(player1.ak_change||player1.d_change||player1.items.sn_change)
					switch(player1.action_kind){
						case RUN:formatted_output(1,vital_signs_area,1,5,0x0b,"����    ");break;
						case WALK:formatted_output(1,vital_signs_area,1,5,0x0b,"����    ");break;
						case CHOOSE_ITEM:formatted_output(1,vital_signs_area,1,5,0x0b,"ѡ����Ʒ");break;
						case CHANGE_WPN:formatted_output(1,vital_signs_area,1,5,0x0b,"�л�����");break;
					}
				if(game_flag["��Ϸ��ͣ/����"]) formatted_output(1,vital_signs_area,1,24,0x0f,(game_pause?"��Ϸ��ͣ":"        "));
			}
		void vital_signs_update(){
			lives_update();
			weapon_update();
			score_update();
			state_update();
		}
		void item_update(){
			if(player1.ak_change||player1.items.num_change||player1.items.il_change||player1.items.sn_change)
				player1.items.print1();
			if(player1.items.il_change) player1.items.print2();
			if(player1.items.sn_change) player1.items.print3();
		}
	void screen_update(){//��Ļ���� 
		game_map_update();
		vital_signs_update();
		item_update();
	}
		void judge_win_lose(){
		}
		void delay_time(){//��ʱ1���� 
			SLEEP(1);
			game_time=clock()-start_time;
		}
	void others(){
		judge_win_lose();
		delay_time();
	}
void game(){//��Ϸ���� 
	//��ǰ��Ҫ���� 
	game_time=1;start_time=clock();
	while(!game_end){
		assigned();
		pause();
		if(game_pause) continue;
		deal_enemy();
		deal_player();
		deal_item();
		screen_update();
		others();
	}
} 
void win(){
	score &scr=player1.scr;
	formatted_output(2,whole_screen,40,19,0x0a,
	connect_str("��Ӯ�ˣ�",player1.name,"����������ʱ",to_time(0,0,scr.time_spent/1000),"��"),1,150);
} 
void lose(){
	score &scr=player1.scr;
	formatted_output(2,whole_screen,40,19,0x0c,
	connect_str("�����ˣ�",player1.name,"���������",to_time(0,0,scr.time_spent/1000),"��"),1,150);
}
void detail(){//��ϸ��Ϸ��Ϣ����չʾ 
	int col=0;
	if(game_success) col=0x0a;
	else col=0x09;
	score &scr=player1.scr;
	formatted_output(2,whole_screen,40,20,col,"��ϸ��Ϣ��",1,150);
	if(scr.shoot_times!=0) scr.hit_rate=scr.shoot_hit_times*1.0/scr.shoot_times;//
	else scr.hit_rate=0;
	formatted_output(2,whole_screen,40,21,col,
	connect_str("��ɱ����",int_to_str(scr.kill_count)," ��������ʣ�",double_to_str(scr.hit_rate*100,1),"%")
	,1,150);//
	formatted_output(2,whole_screen,40,22,col,
	connect_str("���ܹ���������",int_to_str(scr.hurt_times)
	," ʧȥ����ֵ��",int_to_str(player1.vts.lfin.hurt),"% �ظ�����ֵ��",int_to_str(player1.vts.lfin.recovery),"%")
	,1,150);
}
void ask_try_again(){
	formatted_output(2,whole_screen,40,23,0x07,"���»س����¿�ʼ",1,150);
	wait_until(PRESS_KEY_ENTER);
	formatted_output(2,whole_screen,40,23,0x0b,"��Ϸ������......",1,100);
	start_again=true; 
}
void end(){//��ʱ���� 
	//��ǰҪ���� 
	formatted_output(2,whole_screen,40,20,0x0e,connect_str(player1.name,"����ӭ�´�������"),1,150);
}
//�������� 
