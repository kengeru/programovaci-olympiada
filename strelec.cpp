#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    int r, s;
    cin>>r>>s;
    string w;
    cin>>w;

    vector<vector<char>>sachovnice;
    for (int i = 0; i < r+1; i++){
        string row;
        getline(cin, row);
        
        vector<char> row_;
        for (int i = 0; i < row.size(); i++){
            row_.push_back (row [i]);
        }
        
        sachovnice.push_back (row_);
    }
    sachovnice.erase(sachovnice.begin());
    
    //kontrola
	for (int i = 0; i<w.size(); i++){
	    int kontrola = 0;
	    for (int x = 0; x < r; x++){
        	for (int y = 0; y < s; y++){
        		if (w[i] == sachovnice [x][y]){
                    kontrola = 1;
                }
            }
        }
        if (kontrola == 0){
            cout<<0<<endl;
            return 0;
        }
	}

	//souradnice prvniho pismene
    vector<vector<int>> pismena;
    for (int x = 0; x < r; x++){
    	for (int y = 0; y < s; y++){
    		if (w[0] == sachovnice [x][y]){
                vector <int> souradnice;
                souradnice.clear();
                souradnice.push_back (y);
                souradnice.push_back(x);
    			pismena.push_back (souradnice);
            }
        }   
    }

    //souradnice dalsich pismen
    vector<vector<int>> pomoc;
    vector<int> souradnice;
    for (int x = 1; x < w.size(); x++){
        //cout<<"dalsi pismeno"<<endl;
        for (int y = 0; y < pismena.size(); y++){
            //1. diagonála
            int i = 1;
            while (true){
                if (pismena[y][1] - i < 0 || pismena[y][0] + i >= s){
                    break;
                }
                if (sachovnice [pismena[y][1] - i][pismena[y][0] + i] == w.at(x)){
                    //cout<<sachovnice [pismena[y][1] - i][pismena[y][0] + i]<<endl;
                    souradnice.clear();
                    souradnice.push_back(pismena[y][0] + i);
                    souradnice.push_back(pismena[y][1] - i);
                    pomoc.push_back (souradnice);
                }
                i++;
            }
            
                        
            //2. diagonála
            i = 1;
            while (true){
                if (pismena[y][1] - i < 0 || pismena[y][0] - i < 0){
                    break;
                }
                if (sachovnice [pismena[y][1] - i][pismena[y][0] - i] == w.at(x)){
                    //cout<<sachovnice [pismena[y][1] - i][pismena[y][0] - i]<<endl;
                    souradnice.clear();
                    souradnice.push_back(pismena[y][0] - i);
                    souradnice.push_back(pismena[y][1] - i);
                    pomoc.push_back (souradnice);
                }
                i++;
            }
            
            //3. diagonála
            i = 1;
            while (true){
                if (pismena[y][1] + i >= r || pismena[y][0] - i < 0){
                    break;
                }
                if (sachovnice [pismena[y][1] + i][pismena[y][0] - i] == w.at(x)){
                    //cout<<sachovnice [pismena[y][1] + i][pismena[y][0] - i]<<endl;
                    souradnice.clear();
                    souradnice.push_back(pismena[y][0] - i);
                    souradnice.push_back(pismena[y][1] + i);
                    pomoc.push_back (souradnice);
                }
                i++;
            }
            //4. diagonála
            i = 1;
            while (true){
                if (pismena[y][1] + i >= r || pismena[y][0] + i >= s){
                    break;
                }
                if (sachovnice [pismena[y][1] + i][pismena[y][0] + i] == w.at(x)){
                    //cout<<sachovnice [pismena[y][1] + i][pismena[y][0] + i]<<endl;
                    souradnice.clear();
                    souradnice.push_back(pismena[y][0] + i);
                    souradnice.push_back(pismena[y][1] + i);
                    pomoc.push_back (souradnice);
                }
                i++;
            }
            
            

        }
        
        pismena.clear();
        for (int i=0; i<pomoc.size(); i++){
            pismena.push_back(pomoc[i]);
        }
        pomoc.clear();
        //for (int i = 0; i < pismena.size(); i++){
        //    cout<<pismena[i][0]<<' '<<pismena[i][1]<<endl;
        //}
        
        
    }
    
    //pocet moznych reseni
    int pocetreseni = pismena.size()%1000000007;
    cout<<pocetreseni<<endl;


	return 0;
}
