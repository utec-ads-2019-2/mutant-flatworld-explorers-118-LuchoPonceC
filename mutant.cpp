#include <bits/stdc++.h>

using namespace std;

char posicion(int actual){
	switch(actual){
		case 0:
			return 'N';

		case 1:
			return 'E';

		case 2:
			return 'S';

		case 3:
			return 'W';
	}
}

bool validar_insertar(int posx, int posy, vector<int *> &repetidos){
	bool encontrado = false;
	for(vector<int *>::iterator iterar = repetidos.begin(); iterar!=repetidos.end(); iterar++){
		//std::cout<<"LA POSICION ECINTRADA ES: "<<(*iterar)[0]<<" "<<(*iterar)[1]<<std::endl;
		if(posx == (*iterar)[0] and posy == (*iterar)[1]){
			
			encontrado=true;
			break;
		}
	}
	if(encontrado == false){
		
		repetidos.push_back(new int[2]{posx,posy});
		return true;
	}
	return false;
}
	
void execute(int recx, int recy, int posx, int posy, char view, string lista, vector<int *> &repetidos){
	
	bool out = false;
	int actual = 0;
	switch(view){
		case 'N':
			actual = 0;
			break;
		case 'E':
			actual = 1;
			break;
		case 'S':
			actual = 2;
			break;
		case 'W':
			actual = 3;
			break;
	}
	//std::cout<<"LA POSICION INICIAL ES: "<<posx<<" y "<<posy<<std::endl;
	for(int i=0; i<lista.size();i++){
		
		switch(lista[i]){
			case 'R':
				actual = (actual+1)%4;
				break;
			case 'L':			
				if(actual -1 < 0 ){
					actual = actual + 3;
				}
				else{
					actual--;
				}
				break;

			case 'F':
				switch(actual){
					case 0:
						posy++;
						break;
					case 1:
						posx++;
						break;
					case 2:
						posy--;
						break;
					case 3:
						posx--;
						break;
				}
				
		}
		//std::cout<<"la posicion actual es "<<posx<<" "<<posy<<" "<<" y la letra es "<<lista[i]<<" y la vista es "<<posicion(actual)<<std::endl;
				

		if(posx>recx){
			posx--;
			out = validar_insertar(posx,posy,repetidos);
			

		}
		else if(posx<0) {
			posx++; 
			out = validar_insertar(posx,posy,repetidos);
			
		}
		else if(posy<0)	{
			posy++; 
			out = validar_insertar(posx,posy,repetidos);
			
		}
		else if(posy>recy) {
			posy--;
			out = validar_insertar(posx,posy,repetidos);
			
		}
		if(out) {break;}
	}
	if(out){
		std::cout<<posx<<" "<<posy<<" "<<posicion(actual)<<" LOST"<<std::endl;
	}
	else{
		std::cout<<posx<<" "<<posy<<" "<<posicion(actual)<<std::endl;
	}
	


}

int main(){

	int recx,recy,posx,posy;
	char view;
	string lista;
	cin>>recx>>recy;
	vector<int *> repetidos;
	while(cin>>posx>>posy){
		cin>>view;
		cin>>lista;
		//std::cout<<repetidos.size()<<std::endl;
		execute(recx,recy,posx,posy,view,lista, repetidos);

	}

	return 0;
}