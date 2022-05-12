#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
#include <cstring>

using namespace std;



string replaceSpasi(string a){
    for(int i=0; a[i];i++){
		if(a[i]==' '){
			a[i]='_';
		}
	}

	return a;
}

main(){
    char temp2[128];
    string a = "anto wahyudi";

    strcpy(temp2, replaceSpasi(a).c_str());
    
	cout << temp2;
}