//#include <iostream>
//#include <Windows.h>
//#define HIGH 20
//#define LENGTH 70
//
//
//using namespace std;
//
//class Creature{
//public:
//	Creature* neighbors[9];
//	int age;	
//	virtual int look() = 0;
//	virtual void move(int x,int y) = 0;
//};
//
//Creature* afield[HIGH][LENGTH];
//
//Creature* lookAround(int x, int y)
//{
//	Creature* neighbors[9];
//	int i = 0;
//
//	for (int j = x - 1; j < x + 1; j++){
//		for (int t = y - 1; t < x + 1; t++){
//			if (j == x && t == x) continue;
//			neighbors[i++] = afield[x][y];
//		}
//	}
//
//	return *neighbors;
//}
//
//class Fox : public Creature{
//public:
//	int rabbitsEaten;
//
//	virtual int look(){ return 70; }
//	virtual void move(int x, int y){};
//};
//
//class Rabbit : public Creature{
//public:
//	Creature* neighbors[9];
//	virtual int look(){ return 82; }
//	virtual void move(int x, int y)
//	{
//		*neighbors = lookAround(x,y);
//				
//	};
//};
//
//class Grass : public Creature{
//public:
//	Creature* neighbors[9];
//	virtual int look(){ return 71; }
//	virtual void move(int x, int y){};
//};
//
//class Empty : public Creature{
//public:
//	Creature* neighbors[9];
//	virtual int look(){ return 45; }
//	virtual void move(int x, int y){};
//};
//
//class Field{
//public:
//	
//	Field(){
//		for (int i = 0; i < HIGH; i++){
//			for (int j = 0; j < LENGTH; j++){
//			int _rand = rand() % 4;
//			switch (_rand)
//			{
//			case 0:
//				afield[i][j] = new Fox;
//				break;
//			case 1:
//				afield[i][j] = new Rabbit;
//				break;
//			case 2:
//				afield[i][j] = new Empty;
//				break;
//			case 3:
//				afield[i][j] = new Grass;
//				break;
//			default:
//				break;
//			}
//			}
//		}
//	}
//	void show(){
//		system("cls");
//		for (int i = 0; i < HIGH; i++){
//			for (int j = 0; j < LENGTH; j++){
//			
//					cout << (char)afield[i][j]->look();
//			
//			}
//			cout << endl;
//		}
//	}
//
//	void move(){
//		for (int i = 1; i < HIGH-1; i++){
//			for (int j = 1; j < LENGTH-1; j++){
//
//				afield[i][j]->move(i,j);
//
//			}
//			
//		}
//	}
//};